#include <ap_parser.hpp>

#include <container/list.hpp>
#include <base/pair.hpp>

#include <servo.hpp>
#include <adc_pin.hpp>

#define BUGGYBOT_SERVOS_INTERN
#include <buggybot_servos.hpp>

#include <device/stream/uart_stream.hpp>
#include <device/stream/eeprom_stream.hpp>

#include <device/pin/input_digital_pin.hpp>
#include <board/adm2560.hpp>

UartStream<0> io("test");  

template<class Stream>
void write(Stream& stream, u8* buff, u32 size) {
  while(size != 0) {
    stream.setValue(*(buff++));
    size--;
  }
}

template<class Stream>
void read(Stream& stream, u8* buff, u32 size) {
  while(size != 0) {
    *(buff++) = stream.getValue();
    size--;
  }
}

using namespace AP;

typedef Pair<AP::Config::Servo*, _ServoBase*> pair_t;
List<12, pair_t> servos;

InputDigitalPin<ADM2560::Pinmap::A12> sensor1("s1");
InputDigitalPin<ADM2560::Pinmap::A13> sensor2("s2");
InputDigitalPin<ADM2560::Pinmap::A14> sensor3("s3");
InputDigitalPin<ADM2560::Pinmap::A15> sensor4("s4");

InputDigitalPin<ADM2560::Pinmap::A8> tirette("tir");

ADCPin<ADM2560::Pinmap::A9> gp2l;
ADCPin<ADM2560::Pinmap::A10> gp2r;

List<5, Input<bool>*> bumpers;
List<3, Input<u16>*> gp2s;

struct Conf {
  u16 magic_number;

  AP::Config::Servo lf0;
  AP::Config::Servo lf1;
  AP::Config::Servo lf2;

  AP::Config::Servo rf0;
  AP::Config::Servo rf1;
  AP::Config::Servo rf2;

  AP::Config::Servo rb0;
  AP::Config::Servo rb1;
  AP::Config::Servo rb2;

  AP::Config::Servo lb0;
  AP::Config::Servo lb1;
  AP::Config::Servo lb2;
};

Conf main_conf;

void init_main_conf(void) {
  main_conf.magic_number = AP::SYNC;
  
  using namespace AP::Buggybot::Servo;
  
  // Id
  main_conf.lf0.servo.id = LF0;
  main_conf.lf1.servo.id = LF1;
  main_conf.lf2.servo.id = LF2;
  
  main_conf.rf0.servo.id = RF0;
  main_conf.rf1.servo.id = RF1;
  main_conf.rf2.servo.id = RF2;
  
  main_conf.rb0.servo.id = RB0;
  main_conf.rb1.servo.id = RB1;
  main_conf.rb2.servo.id = RB2;
  
  main_conf.lb0.servo.id = LB0;
  main_conf.lb1.servo.id = LB1;
  main_conf.lb2.servo.id = LB2;
    
  // Default pwm
  main_conf.lf0.default_pwm = 44;
  main_conf.lf1.default_pwm = 73;
  main_conf.lf2.default_pwm = 30;
    
  main_conf.rf0.default_pwm = 112;
  main_conf.rf1.default_pwm = 81;
  main_conf.rf2.default_pwm = 38;
    
  main_conf.rb0.default_pwm = 50;
  main_conf.rb1.default_pwm = 100;
  main_conf.rb2.default_pwm = 130;
    
  main_conf.lb0.default_pwm = 105;
  main_conf.lb1.default_pwm = 74;
  main_conf.lb2.default_pwm = 32;

  // 
  servos.doForeach([](pair_t& item) {
      item.left()->angle1 = 0;
      item.left()->angle1_pwm = 0;
      item.left()->angle2 = 0;
      item.left()->angle2_pwm = 0;
    });
}

void servo_list_init(void) {
  using namespace AP::Buggybot::Servo;
  
  servos.append(pair_t(&main_conf.lf0, &lf0));
  servos.append(pair_t(&main_conf.lf1, &lf1));
  servos.append(pair_t(&main_conf.lf2, &lf2));
  
  servos.append(pair_t(&main_conf.rf0, &rf0));
  servos.append(pair_t(&main_conf.rf1, &rf1));
  servos.append(pair_t(&main_conf.rf2, &rf2));
  
  servos.append(pair_t(&main_conf.rb0, &rb0));
  servos.append(pair_t(&main_conf.rb1, &rb1));
  servos.append(pair_t(&main_conf.rb2, &rb2));
  
  servos.append(pair_t(&main_conf.lb0, &lb0));
  servos.append(pair_t(&main_conf.lb1, &lb1));
  servos.append(pair_t(&main_conf.lb2, &lb2));
}

void bumper_list_init(void) {
  bumpers.append(&sensor1);
  bumpers.append(&sensor2);
  bumpers.append(&sensor3);
  bumpers.append(&sensor4);
  bumpers.append(&tirette);
}

void gp2_list_init(void) {
  gp2s.append(&gp2l);
  gp2s.append(&gp2r);
}

void send_ack(const void* msg) {
  typedef Pack<Message, Dummy> pack_t;
  auto pak = (pack_t*)msg;

  Pack<Message, Protocol::Ack> ack;
  ack.message.payload.cls = pak->message.header.cls;
  ack.message.payload.id = pak->message.header.id;

  u8* response = pack(ack);
  write(io, response, sizeof(ack));
}

void send_nak(const void* msg) {
  typedef Pack<Message, Dummy> pack_t;
  auto pak = (pack_t*)msg;

  Pack<Message, Protocol::Nak> nak;

  u8* response = pack(nak);
  write(io, response, sizeof(nak));
}

void servo_pwm_handle(const void* msg) {
  typedef Pack<Message, Actuator::ServoPWM> pack_t;
  auto pak = (pack_t*)msg;
  
  servos.doForeach([pak](pair_t& item) {
      if(item.left()->servo.id == pak->message.payload.servo.id) {
	item.right()->setValue(pak->message.payload.pwm);
      }
    });

  send_ack(msg);
}

void servo_angle_handle(const void* msg) {
  typedef Pack<Message, Actuator::ServoAngle> pack_t;
  auto pak = (pack_t*)msg;
  
  servos.doForeach([pak](pair_t& item) {
      if(item.left()->servo.id == pak->message.payload.servo.id) {
	const s32 min_angle = item.left()->angle1;
	const s32 min_pwm = item.left()->angle1_pwm;
	const s32 max_angle = item.left()->angle2;
	const s32 max_pwm = item.left()->angle2_pwm;
	const s32 cmd_angle = pak->message.payload.angle;

	if(max_angle != min_angle) {
	  const s32 angle = cmd_angle - min_angle;
	  const s32 delta_pwm = max_pwm - min_pwm;
	  const s32 delta_angle = max_angle - min_angle;
	  const s32 cmd = ((angle * delta_pwm) / delta_angle) + min_pwm;
	  item.right()->setValue(cmd);
	}
	else {
	  item.right()->setValue(item.left()->default_pwm);
	}
      }
    });

  send_ack(msg);
}

void set_servo_config_handle(const void* msg) {
  typedef Pack<Message, AP::Config::Servo> pack_t;
  auto pak = (pack_t*)msg;
  
  servos.doForeach([pak](pair_t& item) {
      if(item.left()->servo.id == pak->message.payload.servo.id) {
	AP::Config::Servo* const cfg = item.left();
	const AP::Config::Servo* const pay = &(pak->message.payload);

	cfg->default_pwm = pay->default_pwm;
	cfg->angle1 = pay->angle1;
	cfg->angle1_pwm = pay->angle1_pwm;
	cfg->angle2 = pay->angle2;
	cfg->angle2_pwm = pay->angle2_pwm;
      }
    });

  send_ack(msg);
}

void get_servo_config_handle(const void* msg) {
  typedef Pack<PollRequest, AP::Config::Servo> pack_t;
  auto pak = (pack_t*)msg;
  
  servos.doForeach([pak](pair_t& item) {
      if(item.left()->servo.id == pak->message.payload.id) {
	AP::Config::Servo* const cfg = item.left();
	Pack<Message, AP::Config::Servo> res;

	res.message.payload.servo.id = cfg->servo.id;
	res.message.payload.default_pwm = cfg->default_pwm;
	res.message.payload.angle1 = cfg->angle1;
	res.message.payload.angle1_pwm = cfg->angle1_pwm;
	res.message.payload.angle2 = cfg->angle2;
	res.message.payload.angle2_pwm = cfg->angle2_pwm;

	write(io, pack(res), sizeof(res));
      }
    });

  send_ack(msg);
}

void save_config_handle(const void* msg) {
  typedef Pack<Message, AP::Config::Save> pack_t;
  auto pak = (pack_t*)msg;
  
  send_nak(msg);
}

void bumper_handle(const void* msg) {
  Pack<Message, Sensor::Bumper> res;
  u16& mask = res.message.payload.mask;
  res.message.payload.bumper.id = bumpers.usedSpace();
  mask = 0;

  for(u16 i = 0 ; i < bumpers.usedSpace() ; i++) {
    mask = mask | (bumpers.get(i)->getValue() << i);
  }

  write(io, pack(res), sizeof(res));
}

void gp2_handle(const void* msg) {
  typedef Pack<PollRequest, Sensor::GP2> pack_t;
  auto pak = (pack_t*)msg;

  const u8 id = pak->message.payload.id;
  
  if(id < gp2s.usedSpace()) {
    Pack<Message, Sensor::GP2> res;
  
    res.message.payload.gp2.id = id;
    res.message.payload.value = gp2s.get(id)->getValue();
    
    write(io, pack(res), sizeof(res));
  }
  else {
    send_nak(msg);
  }
}

void default_handle(const void* msg) {
  send_nak(msg);
}

bool true_predicate(const void* msg) {
  return true;
}

int main(int argc, char* argv[]) {
  servo_list_init();
  bumper_list_init();
  gp2_list_init();
  init_main_conf();

  Parser<16, 128> parser;

  parser.addHandler(DefaultHandler<Message, Actuator::ServoPWM>(servo_pwm_handle));
  parser.addHandler(DefaultHandler<Message, Actuator::ServoAngle>(servo_angle_handle));
  parser.addHandler(DefaultHandler<Message, AP::Config::Servo>(set_servo_config_handle));
parser.addHandler(DefaultHandler<PollRequest, AP::Config::Servo>(get_servo_config_handle));
  parser.addHandler(DefaultHandler<PollRequest, Sensor::Bumper>(bumper_handle));
  parser.addHandler(DefaultHandler<PollRequest, Sensor::GP2>(gp2_handle));
  parser.addHandler(DefaultHandler<Message, AP::Config::Save>(save_config_handle));
  parser.addHandler(Handler(true_predicate, default_handle));


  servos.doForeach([](pair_t& item) {
      item.right()->setValue(item.left()->default_pwm);
    });

  while(1) {
    u8 c = io.getValue();
    parser.parse(&c, 1);
  }

  return 0;
}

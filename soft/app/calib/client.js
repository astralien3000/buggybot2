
var servo = ''
var default_pwm = 0
var angle1 = 0
var angle1_pwm = 0
var angle2 = 0
var angle2_pwm = 0


function set_cmd(servo, val) {
    req = new XMLHttpRequest();
    req.open("POST", "servo_cmd", true);
    req.send(servo + "=" + val)
}

function set_config() {
    req = new XMLHttpRequest();
    req.open("POST", "set_servo_cfg", true);
    msg = "servo="+servo+"&"
    msg += "default="+default_pwm+"&"
    msg += "pwm1="+angle1_pwm+"&"
    msg += "angle1="+angle1+"&"
    msg += "pwm2="+angle2_pwm+"&"
    msg += "angle2="+angle2
    req.send(msg)
}

function get_config() {
    req = new XMLHttpRequest();
    req.open("POST", "get_servo_cfg", false);
    req.send("servo="+servo);
    return JSON.parse(req.responseText);
}


function update_display() {
    a1 = document.getElementById('angle1')
    a1.innerHTML = angle1
    a2 = document.getElementById('angle2')
    a2.innerHTML = angle2
    p1 = document.getElementById('angle1_pwm')
    p1.value = angle1_pwm
    p2 = document.getElementById('angle2_pwm')
    p2.value = angle2_pwm
}

function servo_select(s) {
    if(servo != '') {
	set_cmd(servo, angle1_pwm);
	set_config();
    }

    servo = s;

    cfg = get_config();

    default_pwm = cfg.default_pwm;
    angle1 = cfg.angle1;
    angle1_pwm = cfg.angle1_pwm;
    angle2 = cfg.angle2;
    angle2_pwm = cfg.angle2_pwm;

    update_display()
}

function up_p1() {
    set_cmd(servo, angle1_pwm);
    set_config();
    update_display();
}

function up_p2() {
    set_cmd(servo, angle2_pwm);
    set_config();
    update_display();
}

function dec_p1() {
    angle1_pwm -= 1;
    up_p1();
}

function inc_p1() {
    angle1_pwm += 1;
    up_p1();
}

function dec_p2() {
    angle2_pwm -= 1;
    up_p2();
}

function inc_p2() {
    angle2_pwm += 1;
    up_p2();
}

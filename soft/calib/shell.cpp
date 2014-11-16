#include "shell.hpp"

#include "cmd.hpp"
#include "list_servo.hpp"
#include "cmd_servo.hpp"

#include <string.h>

#include <stdlib.h>
#include <base/alloc.hpp>

#include <stream/string_stream.hpp>

Command* cmds[] = {
  new ListServo(),
  new SetServo(),
  new CtrlServo(),
  new PrintServo(),
  new GetServo(),
  new SetDefaultServo(),
  new SetMaxServo(),
  new SetMinServo(),
  NULL
};

FormattedStream* Command::io = NULL;

Shell::Shell(void)
  : io("io") {
  io << "Hello !\n";
  Command::io = &io;
  io.setSeparatorMode(FormattedStream::SeparatorMode::LINE);
}

void
Shell::run(void) {
  char buffer[128];
  io << "cmd : ";
  io >> buffer;
  io << buffer << "\n";

  StringStream<128> sstream;
  sstream.setSeparatorMode(FormattedStream::SeparatorMode::LINE);
  sstream << buffer << "\n";
  sstream.setSeparatorMode(FormattedStream::SeparatorMode::WORD);

  char* args[8];
  u8 s = 0;
  while(sstream.inputUsedSpace() != 0) {
    char* arg = (char*)malloc(sizeof(char)*32);
    sstream >> arg;
    args[s++] = arg;
  }
  args[s] = NULL;

  for(u8 i = 0 ; cmds[i] != NULL ; i++) {
    if(strcmp(args[0], cmds[i]->name()) == 0) {
      cmds[i]->run(args);
      return;
    }
  }

  for(u8 i = 0 ; args[i] ; i++) {
    free(args[i]);
  }

  io << "error\n";
}

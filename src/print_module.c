#include "print_module.h"

#include <stdio.h>
#include <time.h>
char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
  char* log = Log_prefix;
  while (*log != '\0') {
    print(*log);
    log++;
  }
  time_t t = time(NULL);
  struct tm* aTm = localtime(&t);
  char timed[11];
  sprintf(timed, " %02d:%02d:%02d ", aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
  for (int i = 0; timed[i] != '\0'; i++) {
    print(timed[i]);
  }
  char* mes = message;
  while (*mes != '\0') {
    print(*mes);
    mes++;
  }
}

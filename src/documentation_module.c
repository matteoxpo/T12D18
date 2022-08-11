#include "documentation_module.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int validate(char* data) {
  int validation_result = !strcmp(data, Available_document);
  return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*),
                                          int document_count, ...) {
  int* res = malloc(document_count * sizeof(int));

  va_list ptr;
  va_start(ptr, document_count);

  for (int i = 0; i < document_count && ptr != NULL; i++) {
    char* t = va_arg(ptr, char*);
    res[i] = validate(t);
  }
  va_end(ptr);

  return res;
}

void doc_output(int document_count, int* res, ...) {
  va_list ptr;
  va_start(ptr, res);

  for (int i = 0; i < document_count && ptr != NULL; i++) {
    char* t = va_arg(ptr, char*);
    printf("[");
    printDoc(t, statDec(res[i]));
    printf("]\n");
  }
  va_end(ptr);
}

void printDoc(char* doc, char* status) {
  int size = strlen(doc);
  printf("%s", doc);
  for (int i = 0; i < 15 - size; i++) {
    printf(" ");
  }
  printf(": %s", status);
}
char* statDec(int i) { return i == 1 ? "available" : "unavailable"; }

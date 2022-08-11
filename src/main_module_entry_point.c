#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef QUEST1
  char *Module_load_successb = Module_load_success_message;
  print_log(print_char, Module_load_successb);
#elif QUEST2
  int *res = check_available_documentation_module(validate, Documents_count,
                                                  Documents);
  doc_output(Documents_count, res, Documents);
  free(res);
// malloc(15 * sizeof(int))
#endif
  // availability_mask = check_available_documentation_module(validate,
  // Documents_count, Documents);

  // Output availability for each document....

  return 0;
}

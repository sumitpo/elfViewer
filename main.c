#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "plot.h"

void *elfHdr = NULL;
void *elfSh = NULL;
void *elfPh = NULL;

int
test() {
  parseHdr(NULL, NULL);
}

int
clean() {
  // clean up
  if (NULL != elfHdr) free(elfHdr);
  if (NULL != elfSh) free(elfSh);
  if (NULL != elfPh) free(elfPh);
}
int
main(int argc, char *argv[]) {
  // log_set_level(LOG_WARN);
  log_set_level(LOG_INFO);

  if (argc < 2) {
    log_error("elf file required");
    return 1;
  }
  FILE *fp = fopen(argv[1], "rb");
  parseHdr(fp, &elfHdr);
  log_debug("the elf hdr @%p\n", elfHdr);
  plotHdr(elfHdr);

  parseSectionHdr(fp, &elfSh, elfHdr);
  parseProgramHdr(fp, &elfPh, elfHdr);

  clean();
  return 0;
}

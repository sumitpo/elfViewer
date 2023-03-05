/*
 * plot.c
 * Copyright (C) 2023 ghost <ghost@Tarn>
 *
 * Distributed under terms of the MIT license.
 */

#include "plot.h"

#include <stdint.h>

void
plotHdr(const void *elfHdr) {
  Elf64_Ehdr *hdr = (Elf64_Ehdr *)elfHdr;
  printf("\n==========program header table==========\n");
  printf("header size is ox%X\n", hdr->e_ehsize);

  printf("\n==========program header table==========\n");
  printf("offset is 0x%X\n", hdr->e_phoff);
  printf("number of program is 0x%x\n", hdr->e_phnum);
  printf("size of program entry is 0x%x\n", hdr->e_phentsize);

  printf("\n==========section header table==========\n");
  printf("offset is 0x%X\n", hdr->e_shoff);
  printf("number of section is 0x%x\n", hdr->e_shnum);
  printf("size of section entry is 0x%x\n", hdr->e_shentsize);
}

void
plotPhdr(const void *elfHdr, const void *elfPhdr){
  Elf64_Ehdr *hdr = (Elf64_Ehdr *)elfHdr;
  for(int i=0;i<hdr->e_shnum;i++){
  }
}

void
plotShdr(const void *elfHdr, const void *elfShdr){
  Elf64_Ehdr *hdr = (Elf64_Ehdr *)elfHdr;
  for(int i=0;i<hdr->e_phnum;i++){
  }
}

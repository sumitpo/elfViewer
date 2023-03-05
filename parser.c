#include "parser.h"

// pass the null elfHdr and file pointer
errCode
parseHdr(FILE *fp, void **elfHdr) {
  errCode ret = ELF_NOT_SET;

  // check arguments
  if (NULL == fp) {
    log_error("file pointer NULL");
    return ELF_INVALID_FILE_POINTER;
  }

  if (NULL != *elfHdr) {
    log_error("elf header is not NULL");
  }

  *elfHdr = (Elf64_Ehdr *)malloc(sizeof(Elf64_Ehdr));
  fread(*elfHdr, sizeof(Elf64_Ehdr), 1, fp);

  Elf64_Ehdr *hdr = (Elf64_Ehdr *)(*elfHdr);

  log_info("the file magic is %s", ((Elf64_Ehdr *)*elfHdr)->e_ident);
  if (hdr->e_ident[0] == ELFMAG0 && hdr->e_ident[1] == ELFMAG1 &&
      hdr->e_ident[2] == ELFMAG2 && hdr->e_ident[3] == ELFMAG3) {
    log_info("the file match");
  }
  return ret;
}
errCode
parseSectionHdr(FILE *fp, void **elfSh, const void *elfHdr) {
  errCode ret = ELF_NOT_SET;

  // check arguments
  if (NULL == fp) {
    log_error("file pointer NULL");
    return ELF_INVALID_FILE_POINTER;
  }

  if (NULL != *elfSh) {
    log_error("elf header is not NULL");
  }

  Elf64_Ehdr *hdr = (Elf64_Ehdr *)elfHdr;

  fseek(fp, hdr->e_shoff, SEEK_SET);
  *elfSh = (Elf64_Shdr *)malloc(hdr->e_shentsize * hdr->e_shnum);
  fread(*elfSh, hdr->e_shentsize, hdr->e_shnum, fp);

  return ret;
}
errCode
parseProgramHdr(FILE *fp, void **elfPh, const void *elfHdr) {
  errCode ret = ELF_NOT_SET;
  // check arguments
  if (NULL == fp) {
    log_error("file pointer NULL");
    return ELF_INVALID_FILE_POINTER;
  }

  if (NULL != *elfPh) {
    log_error("elf header is not NULL");
  }

  Elf64_Ehdr *hdr = (Elf64_Ehdr *)elfHdr;

  fseek(fp, hdr->e_phoff, SEEK_SET);
  *elfPh = (Elf64_Phdr *)malloc(hdr->e_phentsize * hdr->e_phnum);
  fread(*elfPh, hdr->e_phentsize, hdr->e_phnum, fp);

  return ret;
}

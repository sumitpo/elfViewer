/*
 * parser.h
 * Copyright (C) 2023 ghost <ghost@Tarn>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PARSER_H
#define PARSER_H

#include <elf.h>
#include <stdlib.h>

#include "errorCode.h"
#include "log.h"

errCode parseHdr(FILE *fp, void **elfHdr);
errCode parseSectionHdr(FILE *fp, void **elfSh, const void *);
errCode parseProgramHdr(FILE *fp, void **elfPh, const void *);

#endif /* !PARSER_H */

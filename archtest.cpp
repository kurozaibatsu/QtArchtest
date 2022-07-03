/*
 ============================================================================
 Name        : archtest.c
 Author      : R
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "archtest.h"
#include <stdio.h>
#include <string.h>

extern void archtest(char *pFilename, const uint8_t u8Len, uint8_t *pString) {
    FILE *f = fopen(pFilename, "rb");
    uint32_t offset = 0;
    fseek(f, 0x3c, SEEK_SET);
    fread(&offset, sizeof(offset), 1, f);
    fseek(f, offset + 4, SEEK_SET);
    uint16_t machine = 0;
    fread(&machine, sizeof(machine), 1, f);
    char *info;
    switch (machine) {
    case 0x8664:
        info = (char*) "AMD64";
        break;
    case 0x14c:
        info = (char*) "intel 386";
        break;
    case 0xaa64:
        info = (char*) "arm64";
        break;
    default:
        info = (char*) "unknown";
    }
    uint8_t stream[64];
    int len = sprintf((char*)stream, "Machine: 0x%.4x, %s", machine, info);
    if(len>0&&len<=u8Len){
        strncpy((char*)pString, (char*)stream, len+1);
    }
}

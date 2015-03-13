#include <stdio.h>
#include <stdlib.h>
#include "printBytes.h"

char * byteToString(unsigned char byte) {
  char * buffer = (char *) malloc(sizeof(char) * 9);
  int i = 7, control = 1;
  buffer[8] = 0;
  while (i > -1) {
    if (byte & control) {
      buffer[i] = '1';
    } else {
      buffer[i] = '0';
    }

    i -= 1;
    control = control << 1;
  }

  return buffer;
}

void printBitmap(char * bitmap, int length) {
  int i = 0;
  char * byte = NULL;
  printf("Map:\n");

  for (i = 0; i < length; i += 1) {
    byte = byteToString(bitmap[i]);
    printf("%i: %s %i\n", i, byte, bitmap[i]);
    free(byte);
  }
}



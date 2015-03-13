#include <stdio.h>
#include <stdlib.h>

#define KNOWN_MAX 1024
#define BITMAP_SIZE 8 // KNOWN_MAX / 8
#define BYTE_SIZE 8

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

int main(void) {
  int i = 0, j = 0, number = 0, address = 0, shifts = 0;
  char bitmap[BITMAP_SIZE], control = 0, *map = NULL;

  // initialize bitmap
  for (i = 0; i < BITMAP_SIZE; i += 1) {
    bitmap[0] = 0;
  }

  // populate bitmap
  while(scanf("%d", &number) != EOF) {
    address = number / BYTE_SIZE;
    shifts = (number % BYTE_SIZE) - 1;
    if (shifts == -1) {
      address -= 1;
      shifts = 7;
    }
    control = 1 << shifts;

    bitmap[address] = bitmap[address] | control;
  }

  // sort
  for (i = 0; i < BITMAP_SIZE; i += 1) {
    address = i;
    control = 1;
    for (j = 0; j < BYTE_SIZE; j += 1) {
      if (bitmap[address] & control) {
        printf("%i\n", address * BYTE_SIZE + j + 1);
      }
      control = control << 1;
    }
  }

  return 0;
}

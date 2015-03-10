#include <stdio.h>
#include <stdlib.h>

#define KNOWN_MAX 1024
#define BITMAP_SIZE 128 // KNOWN_MAX / 8
#define BYTE_SIZE 256
#define KNOWN_N 100

int main(void) {
  int list[KNOWN_N], n = 0, i = 0, number= 0, address = 0, shifts = 0;
  unsigned char bitmap[BITMAP_SIZE], control = 0;

  while(scanf("%d", &list[n]) != EOF) {
    n += 1;
  }

  // initialize bitmap
  for (i = 0; i < BITMAP_SIZE; i += 1) {
    bitmap[0] = 0;
  }

  // populate the bitmap
  for (i = 0; i < n; i += 1) {
    number = list[i];

    address = number / BYTE_SIZE;
    shifts = number % BYTE_SIZE;
    control = 1 << shifts;

    bitmap[address] = bitmap[address] & control;
  }

  // sort
  for (i = 0; i < KNOWN_MAX; i += 1) {
    address = i / BYTE_SIZE;
    shifts = i % BYTE_SIZE;
    control = 1 << shifts;
    if (bitmap[address] & control) {
      printf("%d\n", i);
    }
  }

  return 0;
}

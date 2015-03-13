#include "sorter.h"

int main(void) {
  int i = 0, j = 0, number = 0, address = 0, shifts = 0;
  char bitmap[BITMAP_SIZE], control = 0, *map = NULL;

  // initialize bitmap
  for (i = 0; i < BITMAP_SIZE; i += 1) {
    bitmap[i] = 0;
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

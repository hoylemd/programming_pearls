#include "rando.h"
int randint(int min, int max) {
  int r = 0, range = max - min;

  r = rand() % range;

  return r + min;
}

int main(void) {
  int numbers[MAX], i = 0, target = 0, temp = 0;

  // seeds
  srand(time(NULL));
  for (i = 0; i < MAX; i += 1) {
    numbers[i] = i;
  }

  // randomize
  for (i = 0; i < NUMBER; i += 1) {
    target = randint(i, MAX);
    temp = numbers[target];
    numbers[target] = numbers[i];
    numbers[i] = temp;
    printf("%d\n", temp);
  }

  return 0;
}

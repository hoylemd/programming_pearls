#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int a[100], n = 0, i = 0;

  while(scanf("%d", &a[n]) != EOF) {
    n += 1;
  }

  // do the sort here

  for (i = 0; i < n; i += 1) {
    printf("%d\n", a[i]);
  }

  return 0;
}

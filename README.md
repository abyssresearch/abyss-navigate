# WSP-Navigate
© 2024 William Stafford Parsons

## About
WSP-Navigate is a grid step navigation calculation algorithm as a substantial improvement to all similar algorithms for navigating rectangular grids in a 2D plane.

Read more [here](https://williamstaffordparsons.github.io/wsp-navigate/).

## Example
``` c
#include <stdio.h>
#include "wsp_navigate.h"

int main(void) {
  struct wsp_navigate_s s = {
    .grid_width = 10,
    .grid_height = 10,
    .source = 0,
    .destination = 95,
    .source_step = 0,
    .repetitions_count = 0,
    .has_source_coordinates = 0,
    .has_destination_coordinates = 0
  };
  unsigned char grid[100] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  unsigned char i = 0;

  grid[s.source] = 1;

  while (s.source != s.destination) {
    wsp_navigate(&s);
    grid[s.source] = 3;
  }

  grid[s.destination] = 2;
  i = 0;

  while (i != 100) {
    printf("%u ", grid[i]);

    if (((i + 1) % 10) == 0) {
      printf("\n");
    }

    i++;
  }

  return 0;
}
```

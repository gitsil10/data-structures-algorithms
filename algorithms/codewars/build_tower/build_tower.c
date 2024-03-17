#include <stdio.h>
#include <stdlib.h>

char **tower_builder(unsigned);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n_floors>\n", argv[0]);
        return 1;
    }
    unsigned n_floors = argc == 2 ? strtol(argv[1], NULL, 10) : 3;
    char **tower = tower_builder(n_floors);
    for (int i = 0; i < n_floors; i++) printf("%s\n", tower[i]);
    free(tower);
    return 0;
}

char **tower_builder(unsigned n_floors) {
  char **tower = (char **)malloc(n_floors * sizeof(char *));
  for (unsigned i = 0; i < n_floors; i++) {
    tower[i] = (char *)malloc((2 * n_floors - 1) * sizeof(char));
    for (int j = 0; j < 2 * n_floors - 1; j++) {
      if (j < n_floors - i - 1 || j >= n_floors + i) tower[i][j] = ' ';
      else tower[i][j] = '*';
    }
  }
  return tower;
}
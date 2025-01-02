#include <stdio.h> 
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> 

int cmp(const void *a, const void *b) {
  struct dirent *a1 = *(struct dirent**)a;
  struct dirent *b1 = *(struct dirent**)b;

  if (a1->d_type != b1->d_type) {
    return a1->d_type - b1->d_type;
  }

  return strcmp(a1->d_name, b1->d_name);
}

int main (int argc, const char *argv[]) {
  DIR* dir; 
  struct dirent *entry;

  struct dirent **entries = NULL; 
  int count = 0;

  if (argc == 1) {
    DIR *dir = opendir(".");

    // Case: Fail to open directory
    if (!dir) {
      perror("Unable to read directory");
      exit(EXIT_FAILURE);
    }

    // Case: Succeed in opening directory
    while((entry = readdir(dir)) != NULL) {
      entries = realloc(entries, (count + 1) * sizeof(struct dirent *));
      entries[count++] = entry;
    }
  }
  closedir(dir);

  qsort(entries, count, sizeof(struct dirent *), cmp);

  for (int i = 0; i < count; i++) {
    if (entries[i]->d_name[0] == '.') continue;
    if (entries[i]->d_type == DT_DIR) {
      printf("\033[1;34m%s\033[0m  ", entries[i]->d_name);
    } else if (entries[i]->d_type == DT_REG) {
      printf("%s  ", entries[i]->d_name);
    } else {
      printf("%s  ", entries[i]->d_name);
    }
    printf("\n");
  }

  free(entries);

  return 0;
}



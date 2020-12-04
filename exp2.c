#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>

struct {
  char directoryname[10], filename[10][10];
  int fcnt;
}
dir;
void main() {
    int i, choice;
    char f[30];
    dir.fcnt = 0;
    printf("\nENTER NAME OF DIRECTORY : ");
    scanf("%s", dir.directoryname);
    while (1) {
      printf("\n\n 1. CREATE FILE\t2. DELETE FILE\t3. SEARCH FILE \n 4. DISPLAY FILES\t5. EXIT\nENTER YOUR CHOICE: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
          printf("\n ENTER THE NAME OF THE FILE : ");
          scanf("%s", dir.filename[dir.fcnt]);
          dir.fcnt++;
          break;
        case 2:
          printf("\n ENTER THE NAME OF THE FILE : ");
          scanf("%s", f);
          for (i = 0; i < dir.fcnt; i++) {
            if (strcmp(f, dir.filename[i]) == 0) {
              printf("FILE %s IS DELETED ", f);
              strcpy(dir.filename[i], dir.filename[dir.fcnt - 1]);
              break;
            }
          }
          if (i == dir.fcnt)
            printf("FILE %s NOT FOUND", f);
          else
            dir.fcnt--;
          break;
        case 3:
          printf("\n ENTER THE NAME OF THE FILE : ");
          scanf("%s", f);
          for (i = 0; i < dir.fcnt; i++) {
            if (strcmp(f, dir.filename[i]) == 0) {
              printf("FILE %s IS FOUND ", f);
              break;
            }
          }
          if (i == dir.fcnt)
            printf("FILE %s NOT FOUND", f);
          break;
        case 4:
          if (dir.fcnt == 0)
            printf("\n DIRECTORY EMPTY");
          else {
            printf("\n THE FILES ARE : ");
            for (i = 0; i < dir.fcnt; i++)
              printf("\t%s", dir.filename[i]);
          }
          break;
        case 5:
          exit(0);
        }
      }
    }
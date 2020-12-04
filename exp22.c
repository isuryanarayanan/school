#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct {
  char directoryName[10], fileName[10][10];
  int fcnt;
}dir[10];
void main() {
    int i, chs, Dcount, k;
    char f[30], d[30];
    Dcount = 0;
    while (1) {
     	printf("\n\n 1. CREATE DIRECTORY\t 2. CREATE FILE\t 3. DELETE FILE");
printf("\n 4. SEARCH FILE \t \t 5. DISPLAY \t 6. EXIT \t ENTER YOUR CHOICE : ");
      scanf("%d", &chs);
      switch (chs) {
      case 1:
        printf("\n ENTER NAME OF DIRECTORY : ");
        scanf("%s", dir[Dcount].directoryName);
        dir[Dcount].fcnt = 0;
        Dcount++;
        break;
      case 2:
        printf("\n ENTER NAME OF THE DIRECTORY : ");
        scanf("%s", d);
        for (i = 0; i < Dcount; i++)
          if (strcmp(d, dir[i].directoryName) == 0) {
            printf("ENTER NAME OF THE FILE : ");
            scanf("%s", dir[i].fileName[dir[i].fcnt]);
            dir[i].fcnt++;
            break;
          }
        if (i == Dcount)
          printf("DIRECTORY %s NOT FOUND", d);
        break;
      case 3:
        printf("\nENTER NAME OF THE DIRECTORY : ");
        scanf("%s", d);
        for (i = 0; i < Dcount; i++) {
          if (strcmp(d, dir[i].directoryName) == 0) {
            printf("ENTER NAME OF THE FILE : ");
            scanf("%s", f);
            for (k = 0; k < dir[i].fcnt; k++) {
              if (strcmp(f, dir[i].fileName[k]) == 0) {
                printf("FILE %s IS DELETED ", f);
                dir[i].fcnt--;
                strcpy(dir[i].fileName[k], dir[i].fileName[dir[i].fcnt]);
                goto jmp;
              }
            }
            printf("FILE %s NOT FOUND", f);
            goto jmp;
          }
        }
        printf("DIRECTORY %s NOT FOUND", d);
        jmp: break;
      case 4:
        printf("\nENTER NAME OF THE DIRECTORY : ");
        scanf("%s", d);
        for (i = 0; i < Dcount; i++) {
          if (strcmp(d, dir[i].directoryName) == 0) {
            printf("ENTER THE NAME OF THE FILE : ");
            scanf("%s", f);
            for (k = 0; k < dir[i].fcnt; k++) {
              if (strcmp(f, dir[i].fileName[k]) == 0) {
                printf("FILE %s IS FOUND ", f);
                goto jmp1;
              }
            }
            printf("FILE %s NOT FOUND", f);
            goto jmp1;
          }
        }
        printf("DIRECTORY %s NOT FOUND", d);
        jmp1: break;
      case 5:
        if (Dcount == 0)
          printf("\nNO DIRECTORY ");
        else {
          printf("\nDIRECTORY\tFILES");
          for (i = 0; i < Dcount; i++) {
            printf("\n%s\t\t", dir[i].directoryName);
            for (k = 0; k < dir[i].fcnt; k++) {
              printf("\t%s", dir[i].fileName[k]);
            }
          }
        }
        break;
      case 6:
        exit(0);
      } 
    }
}

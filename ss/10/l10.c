#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *f1, *f2, *f3;
    int c = 0;
    char mne[20], opnd[20], la[20], fname[10];
    f1 = fopen("macin.dat", "r");
    f2 = fopen("macout.dat", "w+");
    f3 = fopen("deftab.dat", "w+");
    fscanf(f1, "%s%s%s", la, mne, opnd);
    while (strcmp(mne, "END") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            strcpy(fname, la);
            fscanf(f1, "%s%s%s", la, mne, opnd);
            while (strcmp(mne, "MEND") != 0)
            {
                fprintf(f3, "%s\t%s\t%s\n", la, mne, opnd);
                fscanf(f1, "%s%s%s", la, mne, opnd);
                c++;
            }
            fscanf(f1, "%s%s%s", la, mne, opnd);
        }
        if (strcmp(fname, mne) == 0)
        {
            fseek(f3, 0, SEEK_SET);
            while (c > 0)
            {
                fscanf(f3, "%s%s%s", la, mne, opnd);
                fprintf(f2, "%s\t%s\t%s\n", la, mne, opnd);
                c--;
            }
            fscanf(f1, "%s%s%s", la, mne, opnd);
        }
        fprintf(f2, "%s\t%s\t%s\n", la, mne, opnd);
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("PASS 1 is successful");
    return (0);
}
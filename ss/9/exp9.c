#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findSYMTAB(char findLabel[])
{
    FILE *SYMTAB;
    char label[30], addr[30];
    SYMTAB = fopen("symtab.txt", "r");
    fscanf(SYMTAB, "%s%s", label, addr);

    while (1)
    {
        if (feof(SYMTAB))
        {
            fclose(SYMTAB);
            break;
        }
        if (strcmp(findLabel, label) == 0)
        {
            fclose(SYMTAB);
            return atoi(addr);
        }
        fscanf(SYMTAB, "%s%s", label, addr);
    }
}

int getMnemonicCode(char mnemonic[])
{

    if (strcmp(mnemonic, "LDA") == 0)
        return 0x00;
    else if (strcmp(mnemonic, "STA") == 0)
        return 0x0C;
    else if (strcmp(mnemonic, "LDCH") == 0)
        return 0x01;
    else if (strcmp(mnemonic, "ADD") == 0)
        return 0x18;
    else
        return -1;
}

int main()
{
    FILE *INPUT, *OUTPUT, *SYMTAB, *INTERMEDIATE, *FINAL;
    char mnemonic[10][10] = {"START", "LDA", "STA", "ADD", "END"};
    int LOCCTR, start = 0, j = 0, i, length, Tlength, count = 0, finalAddress, startAddr;
    char label[20], opcode[20], operand[20], address[20];
    INPUT = fopen("input.txt", "r");
    OUTPUT = fopen("output.txt", "w");
    SYMTAB = fopen("symtab.txt", "w");
    fscanf(INPUT, "%s%s%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {

        start = atoi(operand);
        LOCCTR = start;
        fprintf(OUTPUT, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(INPUT, "%s%s%s", label, opcode, operand);
    }
    else
        LOCCTR = 0;
    while (strcmp(opcode, "END") != 0)
    {

        j = 0;
        fprintf(OUTPUT, "%d", LOCCTR);
        if (strcmp(label, "**") != 0)
            fprintf(SYMTAB, "\t%s\t%d\n", label, LOCCTR);
        while (strcmp(mnemonic[j], "END") != 0)

        {

            if (strcmp(mnemonic[j], opcode) == 0)

            {

                LOCCTR += 3;
            }
            j++;
        }
        if (strcmp(opcode, "WORD") == 0)
            LOCCTR += 3;
        else if (strcmp(opcode, "RESW") == 0)

        {

            LOCCTR = LOCCTR + (3 * atoi(operand));
            count += (3 * atoi(operand));
        }
        else if (strcmp(opcode, "RESB") == 0)

        {

            LOCCTR = LOCCTR + atoi(operand);
            count += atoi(operand);
        }
        else if (strcmp(opcode, "BYTE") == 0)

        {

            LOCCTR = LOCCTR + (strlen(operand));
        }
        else

            printf(" ");

        fprintf(OUTPUT, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(INPUT, "%s%s%s", label, opcode, operand);
    }

    fprintf(OUTPUT, "%d", LOCCTR);
    fprintf(OUTPUT, "\t%s\t%s\t%s\n", label, opcode, operand);
    printf("\n\n THE LENGTH OF THE PROGRAM IS %d", LOCCTR - start);
    length = LOCCTR - start;
    finalAddress = LOCCTR;
    Tlength = length - count;
    fclose(INPUT);
    fclose(OUTPUT);
    fclose(SYMTAB);

    INTERMEDIATE = fopen("output.txt", "r");
    FINAL = fopen("final.txt", "w");
    fscanf(INTERMEDIATE, "%s%s%s", label, opcode, operand);
    startAddr = atoi(operand);
    if (strcmp(opcode, "START") == 0)
    {

        fprintf(FINAL, "%s\t%s\t%s\t\n", label, opcode, operand);
        fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
    }
    while (strcmp(opcode, "END") != 0)
    {

        if (strcmp(label, "**") == 0)

        {

            fprintf(FINAL, "%s\t%s\t%s\t%s\t%x%d\n", address, label, opcode, operand, getMnemonicCode(opcode), findSYMTAB(operand));
            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
        }

        else if (strcmp(opcode, "BYTE") == 0)

        {

            fprintf(FINAL, "%s\t%s\t%s\t%s", address, label, opcode, operand);

            for (i = 2; i < (strlen(operand) - 1); i++)
            {

                fprintf(FINAL, "%d", operand[i]);
            }
            fprintf(FINAL, "\n");

            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
        }
        else if (strcmp(opcode, "WORD") == 0)

        {

            fprintf(FINAL, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);

            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
        }
        else if (strcmp(opcode, "RESW") == 0)

        {

            fprintf(FINAL, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);

            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
        }
        else if (strcmp(opcode, "RESB") == 0)

        {

            fprintf(FINAL, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);

            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
        }
        else

            fscanf(INTERMEDIATE, "%s%s%s%s", address, label, opcode, operand);
    }
    fprintf(FINAL, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);
    fclose(INTERMEDIATE);
    fclose(FINAL);
    return (0);
}
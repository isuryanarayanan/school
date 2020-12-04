#include <stdio.h>
#include <conio.h>
#include <string.h>
struct opc
{
    int len;
    char mnemonic[10], code[3];

} opcode;
struct opd
{
    int address;
    char code[10];
} op;
struct source_result
{
    int address;
    char label[10], instr[10], operand[10];
} res;
struct res
{
    int a;
    char c[10];
} s;

int main()
{
    FILE *r, *o, *result, *symb;
    int i, j, found = 0, l;
    char s1[10];
    r = fopen("intermediate.txt", "r");
    o = fopen("optab.txt", "r");
    result = fopen("output.txt", "w");
    symb = fopen("symtab.txt", "r");

    while (!feof(r))
    {
        fscanf(r, "%d\t%s\t%s\t%s", &res.address, res.label, res.instr, res.operand);
        fseek(o, 0, SEEK_SET);
        fseek(symb, 0, SEEK_SET);
        found = 0;

        while (!feof(o))
        {
            fscanf(o, "%s\t%s", opcode.mnemonic, opcode.code);
            if (strcmp(res.instr, opcode.mnemonic) == 0)
            {
                op.address = res.address;
                strcpy(op.code, opcode.code);
                fprintf(result, "%d\t%s", op.address, op.code);
                found = 1;
                break;
            }
        }
        if (found == 0)
            continue;
        while (!feof(symb))
        {
            fscanf(symb, "%s\t%d", s.c, &s.a);
            if (strcmp(res.operand, s.c) == 0)
            {

                fprintf(result, "%d\n", s.a);
                break;
            }
            else if (strcmp(res.operand, "**") == 0)
            {
                fprintf(result, "0000");
                break;
            }
            else if (res.operand[0] == '#')
            {
                strcpy(s1, res.operand);
                l = strlen(s1) - 1;
                for (i = 4; i > l; i--)
                    fprintf(result, "0");
                for (j = 1; j <= l; j++)
                    fprintf(result, "%c", s1[j]);
                fprintf(result, "\n");
                break;
            }
        }
    }

    printf("** PASS 2 COMPLETED**");
    fclose(r);
    fclose(o);
    fclose(result);

    fclose(symb);
    return 0;
}
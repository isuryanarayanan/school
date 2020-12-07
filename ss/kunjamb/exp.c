#include <stdio.h>

#include <string.h>

int main()
{

    char filename[50]; //for storing input file name

    char outputfilename[] = "result.txt"; //output file name

    int required_field; //for storing required field number

    FILE *fp, *ofp; //defining file pointers for input and output files

    //reading input file

    printf("Enter file name: ");

    scanf("%s", &filename);

    fp = fopen(filename, "r"); //reading input file in read mode

    //making sure input file exist and is readable

    if (!fp)
    {

        printf("File not found!\n");

        return 0;
    }

    //getting field number

    printf("Enter field number: ");

    scanf("%d", &required_field);

    //opening output file for writing

    ofp = fopen(outputfilename, "w");

    char line[250]; //buffer for storing each line of text

    char *word_token; //used for tokenizing each line

    int field_number = 0; //used for iterating through each word (field)

    //looping through each line

    while (fgets(line, sizeof(line), fp))
    {

        //tokenizing the line (splitting it by delimeters - white spaces

        // or next line character )

        word_token = strtok(line, " \n");

        field_number = 1;

        //looping through each tokens until target field

        //or until word token becomes null

        while (field_number != required_field && word_token != NULL)
        {

            word_token = strtok(NULL, " \n"); //getting next token

            field_number++;
        }

        if (word_token == NULL)
        {

            //null value, displaying and saving to file

            printf("(NULL)\n");

            fprintf(ofp, "(NULL)\n");
        }
        else
        {

            //field value at given position, displaying and saving to file

            printf("%s\n", word_token);

            fprintf(ofp, "%s\n", word_token);
        }
    }

    fclose(fp);

    fclose(ofp);
}
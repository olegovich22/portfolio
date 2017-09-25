//
// Created by Oleg on 16.09.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString()
{
    fflush(stdin);
    // growable buffer for chars
    char* buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            char *temp = (char *)realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }
    fflush(stdin);
    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;

    // minimize buffer
    char *minimal = (char *)malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;

}

int getInt()
{
    int chek=0;
    int answer=0;
    do
    {
        chek=scanf("%i", &answer);
        fflush(stdin);
        if (chek!=1)
        {
            printf("ERROR. Please enter int.\n");
        }
    }while(chek!=1);

    return answer;
}
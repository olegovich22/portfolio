//
// Created by Oleh on 28.03.2017.
//
#include <stdio.h>

int oleg228() {
    float dobutok;
    int q;
    do {
        q = scanf("%f", &dobutok);

        fflush(stdin);

        if ((dobutok < 3 || dobutok > 5) || q != 1) {
            printf("\ngive me the correct number pls!");
        }
    } while ((dobutok < 3 || dobutok > 5) || q != 1);
}
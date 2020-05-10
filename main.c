#include <stdio.h>
#include "booleanPar.h"

int main(){
    char symbol[] = {'T', 'T', 'F', 'T', '\0'};
    char operator[] = {'|', '&', '^', '\0'};

    int result = booleanParenthesization(symbol, operator);

    printf("There are %d cases of parenthesization where the expression equals True\n", result);

}
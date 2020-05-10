#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "booleanPar.h"

/*If a matrix is represented as a 1D array, in row major order, given the number of columns of the matrix and the coordinates
of an element, this function returns the index corresponding to the element in the 1D Array*/
int getMatrixIndex(int ncolumns, int row, int column){
    return ncolumns * row + column;
}

/*Initializes the i,i element of the matrix in 1 if value = expectedValue or 0 otherwise. That is, if the value of the i-th
of the boolean expression is equal to the value in expected*/
int initialValue(char expectedValue, char value){
    if (expectedValue == value){
        return 1;
    } else {
        return 0;
    }
}

/*Evaluates and updates the trueValues and falseValues tables with the number of true and false values obtained by operating
the parenthesiezed subexpressions with their corresponding operator*/
void evaluateExpression(char operator, int * trueValues, int * falseValues, int indexResult, int indexLOp, int indexROp){

    switch(operator){
        case '&': trueValues[indexResult] = trueValues[indexResult] + trueValues[indexLOp] * trueValues[indexROp];
                  falseValues[indexResult] = falseValues[indexResult] + trueValues[indexLOp] * falseValues[indexROp] + 
                                             falseValues[indexLOp] * trueValues[indexROp] + 
                                             falseValues[indexLOp] * falseValues[indexROp];
                  break;
        case '|': trueValues[indexResult] = trueValues[indexResult] + trueValues[indexLOp] * trueValues[indexROp] +
                                            trueValues[indexLOp] * falseValues[indexROp] +
                                            falseValues[indexLOp] * trueValues[indexROp];
                  falseValues[indexResult] = falseValues[indexResult] + falseValues[indexLOp] * falseValues[indexROp];
                  break;
        case '^': trueValues[indexResult] = trueValues[indexResult] + trueValues[indexLOp] * falseValues[indexROp] +
                                            falseValues[indexLOp] * trueValues[indexROp];
                  falseValues[indexResult] =  falseValues[indexResult] + trueValues[indexLOp] * trueValues[indexROp] +
                                              falseValues[indexLOp] * falseValues[indexROp];
                  break;
        default : printf("Error inesperado\n");
                  break;
    }
}


/*DP resolution to the boolean parenthesization problem*/
int booleanParenthesization(char * values, char * operators){
    int * evaluatesTrue;
    int * evaluatesFalse;
    int size, index, indexResult, indexLeftOperand, indexRightOperand, colRightOperand, result;

    size = strlen(values);

    evaluatesTrue = (int *)calloc(size * size, sizeof(int));
    evaluatesFalse = (int *)calloc(size * size, sizeof(int));

    for (int i = 0; i < size; i++){
        index = getMatrixIndex(size, i, i);
        evaluatesTrue[index] = initialValue('T', values[i]);
        evaluatesFalse[index] = initialValue('F', values[i]);
    }

    for (int l = 1; l < size; l++){
        for (int i = 0; i < size - l; i++){
            colRightOperand = i + l;
            indexResult = getMatrixIndex(size, i, colRightOperand);
            for (int j = i; j < i + l; j++){
                indexLeftOperand = getMatrixIndex(size, i, j);
                indexRightOperand = getMatrixIndex(size, j + 1, colRightOperand);
                evaluateExpression(operators[j], evaluatesTrue, evaluatesFalse, indexResult, indexLeftOperand, indexRightOperand);
            }
        }
    }

    result = evaluatesTrue[getMatrixIndex(size, 0, size - 1)];
    free(evaluatesTrue);
    free(evaluatesFalse);
    return result;
}
/*If a matrix is represented as a 1D array, in row major order, given the number of columns of the matrix and the coordinates
of an element, this function returns the index corresponding to the element in the 1D Array*/
int getMatrixIndex(int ncolumns, int row, int column);

/*Initializes the i,i element of the matrix in 1 if value = expectedValue or 0 otherwise. That is, if the value of the i-th
of the boolean expression is equal to the value in expected*/
int initialValue(char expectedValue, char value);

/*Evaluates and updates the trueValues and falseValues tables with the number of true and false values obtained by operating
the parenthesiezed subexpressions with their corresponding operator*/
void evaluateExpression(char operator, int * trueValues, int * falseValues, int indexResult, int indexLOp, int indexROp);

/*DP resolution to the boolean Parenthesization problem*/
int booleanParenthesization(char * values, char * operators);
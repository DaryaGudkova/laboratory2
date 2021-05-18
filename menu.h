#ifndef LABORATORY2_H_MENU_H
#define LABORATORY2_H_MENU_H

#include "ArraySequence.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>
#include "Complex.h"
#include <ctime>

int chooseTypeMatrix();
int chooseFunctionDiagonalMatrix();
template <typename T> DiagonalMatrix<T>* inputDiagonalMatrix();
DiagonalMatrix<complex>* InputComplexDiagonalMatrix();
void MenuDiagonalMatrix();
int СhooseFunctionSquareMatrix();

#endif //LABORATORY2_H_MENU_H

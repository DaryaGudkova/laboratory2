/*
#ifndef LABORATORY2_H_MENU_H
#define LABORATORY2_H_MENU_H

#include "ArraySequence.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>
#include <complex>
#include <ctime>
//#include "stdlib.h"
using namespace std;

int chooseTypeMatrix(){
    int type;
    cout << "Select type of numbers: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n\n"
         << "\t0: Return to select class\n"
         << "Enter a number: ";
    cin >> type;
    cout << sep << endl;
    return type;
}

///Diagonal Matrix
int chooseFunctionDiagonalMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Matrix Norm\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}

template <typename T>
DiagonalMatrix<T>* inputDiagonalMatrix(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim;
    cout << endl;
    DiagonalMatrix<T>* matrix = new DiagonalMatrix<T>();
    cout << "Enter Main Diagonal Coordinates:" << endl;
    T coord;
    for(int i = 0; i < dim; i++){
        cin >> coord;
        matrix->Set(coord, i, i);//не уверена
    }
    return matrix;
}

DiagonalMatrix<complex<float>>* InputComplexDiagonalMatrix() {
    int dim;
    cout << "Enter a dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new DiagonalMatrix<complex<float>>();
    cout << "Enter Main Diagonal Coordinates (one by one):" << endl;
    complex<float> coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex<float>(real, im);
        matrix->Set(coord,i,i);//не уверена
    }
    return matrix;
}

void MenuDiagonalMatrix(){
    while(true){
        int type = chooseTypeMatrix(); // 1 - int ; 2 - float ; 3 - complex ; 0 - return to select class
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 2){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix<float>();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number"); //выдавать ошибку
            }
        }
        else if (type == 3){
            while (true){
                int function = chooseFunctionDiagonalMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - matrix norm; 0 - return
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    sum->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter scalar: " << endl;
                    complex<double> scalar;
                    double real, im;
                    cout << "Enter Real and Imaginary number (separated by a space): " << endl;
                    cin >> real >> im;
                    scalar = complex<double>(real, im);
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    MatrixMult->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex<float>>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number");// было cout << "Enter the correct number!" << endl;
            }
        }
    }
}


///Square Matrix
int СhooseFunctionSquareMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Multiplication of two matrix\n"
         << "\t4: Matrix Norm\n"
         << "\t5: Multiplication of scalar and row\n"
         << "\t6: Addition of row and row\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}

template <typename T>
SquareMatrix<T>* InputSquareMatrix(){
    int dim;
    cout << "Enter a dimension of matrix:";
    cin >> dim;
    cout << endl;
    SquareMatrix<T>* matrix = new SquareMatrix<T>();
    cout << "Enter Coordinates:" << endl;
    T coord;
    for(int i = 0; i < dim*dim; i++){
        cin >> coord;
        matrix->Append(coord);//не уверена
    }
    return matrix;
}

SquareMatrix<complex<float>>* inputComplexSquareMatrix() {
    int dim;
    cout << "Enter a dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new SquareMatrix<complex<float>>();
    cout << "Enter Coordinates (one by one):" << endl;
    complex<float> coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex<float>(real, im);
        matrix->Append(coord);//не уверена
    }
    return matrix;
}

void MenuSquareMatrix(){
    while(true){
        int type = chooseTypeMatrix(); // 1 - int ; 2 - float ; 3 - complex ; 0 - return to select class
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = СhooseFunctionSquareMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - mult two matrix; 4 - norm; 5 -Multiplication of scalar and row;
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->ScalarMultiplyMatrix(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    MultiplyRow(*matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl << sep << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    AddRowToRow(*matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl << sep << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 2){
            while (true){
                int function = СhooseFunctionSquareMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->ScalarMultiplyMatrix(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl << matrix1 << endl;
                        cout << "Second matrix = " << endl << matrix2 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl << sum << endl << sep << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix1 << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    MultiplyRow(*matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl << sep << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl << matrix << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    AddRowToRow(*matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl << sep << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
        else if (type == 3){
            while (true){
                int function = СhooseFunctionSquareMatrix();  // 1 - sum; 2 - mult scalar and matrix; 3 - mult two matrix; 4 - norm; 5 -Multiplication of scalar and row;
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    sum->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->ScalarMultiplyMatrix(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    MatrixMult->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        matrix2->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication first matrix and second matrix = " << endl;
                    mult->ComplexMatrixPrint();
                    cout << endl << sep << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix1->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex<float>>();
                    cout << "Matrix Norm = " << matrixNorm << endl << sep << endl;
                }
                else if(function == 5) { //Multiplication of scalar and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    complex<float> scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    MultiplyRow(*matrix, numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl << sep << endl;
                }
                else if(function == 6){ //Addition of row and row
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        matrix->ComplexMatrixPrint();
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    AddRowToRow(*matrix, numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl << sep << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number"); // ошибку выдать
            }
        }
    }
}

///Menu
int menu(){
    while(true){
        int classType;
        cout << "Diagonal matrix - 1 \n Square matrix - 2 \n Exit - 0 ->" << endl;
        cin >> classType;
        cout << sep << endl;
        if (classType != 0 & classType != 1 & classType != 2){
            cout << "The number is incorrect. Please, enter the correct number" << endl;
        }
        if(classType == 1){
            MenuDiagonalMatrix();
        }
        else if (classType == 2){
            MenuSquareMatrix();
        }
        else if (classType == 0){
            break;
        }
    }
    return 0;
};


/
//генерация рандомных чисел
int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
}

complex<float> randomComplex() {
    return complex<float>(randomFloat(), randomFloat());
}


ostream& operator << (ostream& cout, complex<float> com){
    if (com.imag() == 0) return cout << com.real();

    if (com.real() != 0) {
        cout << com.real();
    }

    if (com.imag() > 0) {
        if (com.real() != 0)
            cout << '+';
        if (com.imag() != 1)
            cout << com.imag();
        return cout << 'i';
    }
    else {
        if (com.imag() == -1)
            return cout << "-i";
        return cout << com.imag() << 'i';
    }
}

complex<float> *c = new complex<float>[dimension];
for (int i = 0; i < dimension; ++i) {
c[i] = complex<float>(a[i],b[i]);
}


template<class T>
void createMatrix(ArraySequence<Matrix<T>*> *array, int size){
    cout<<endl;
    cout<<"Input 1,1 number:";
    T a = getNumber(a);
    T *r = new T[1];
    r[0] = a;
    ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
    int j = 1;
    for (int i = 0; i < size; i++) {
        for (j ; j < size; j++) {
            cout<<"Input "<<i+1<<", "<<j+1<<" number:";
            arraySequence->Append(getNumber(a));
    }
    j = 0;
    }
    auto *matrix = new Matrix<T>(*arraySequence, size);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomIntMatrix(ArraySequence<Matrix<int>*> *array, int size){
    cout<<endl;
    int a = randomInt();
    int *r = new int[1];
    r[0] = a;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(r, 1);
    int j = 1;
    for (int i = 0; i < size; ++i) {
        for (j ; j < size; ++j) {
            arraySequence->Append(randomInt());
        }
        j = 0;
    }
    auto *matrix = new Matrix<int>(*arraySequence, size, size);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomFloatMatrix(ArraySequence<Matrix<float>*> *array, int size){
    cout<<endl;
    float a = randomFloat();
    float *r = new float[1];
    r[0] = a;
    auto *arraySequence = new ArraySequence<float>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
        arraySequence->Append(randomFloat());
        }
    j = 0;
    }
    auto *matrix = new Matrix<float>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomComplexMatrix(ArraySequence<Matrix<complex<float>>*> *array, int size){
    cout<<endl;
    complex<float> a = randomComplex();
    auto *r = new complex<float>[1];
    r[0] = a;
    auto *arraySequence = new ArraySequence<complex<float>>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
        arraySequence->Append(randomComplex());
        }
        j = 0;
    }
    auto *matrix = new Matrix<complex<float>>(*arraySequence, size);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}
*/
/*
template<class T>
void printMatrixFromMemory(ArraySequence<Matrix<T>*> *arraySequence) {
    for (int k = 0; k < arraySequence->size; ++k) {
        cout<<k+1<<": ";
        if(arraySequence->Get(k)->size<4) {
            if (arraySequence->Get(k)->GetHeight()<4) {
                for (int i = 0; i < arraySequence->Get(k)->GetHeight(); ++i) {
                    for (int j = 0; j < arraySequence->Get(k)->GetLength(); ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<""<<endl;
                    cout<<"    ";
                }
                cout<<endl;
            }
            else {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < arraySequence->Get(k)->GetLength(); ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<""<<endl;
                    cout<<"    ";
                }
                for (int i = 0; i <  arraySequence->Get(k)->GetLength(); ++i) {
                    cout<<"... ";
                }
                cout<<endl;
            }
        }
        else{
        if (arraySequence->Get(k)->GetHeight()<4) {
        for (int i = 0; i < arraySequence->Get(k)->GetHeight(); ++i) {
        for (int j = 0; j < 3; ++j) {
        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
        }
        cout<<"... ";
        cout<<""<<endl;
        cout<<"    ";
        }
        }else {
        for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
        }
        cout<<"...";
        cout<<""<<endl;
        cout<<"    ";
        }
        for (int i = 0; i <  3; ++i) {
        cout<<"...";
        }
        cout<<endl;
        }
        }
    }
}

void showAvailableMatrix(ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
cout<<"---------"<<endl;
cout<<"What type do you want to look at?"<<endl;
cout<<"1. Int."<<endl;
cout<<"2. Float."<<endl;
cout<<"3. Complex."<<endl;
int a = GetInt(1, 3);
switch (a) {
case 1:
printMatrixFromMemory(matrixInt);
break;
case 2:
printMatrixFromMemory(matrixFloat);
break;
case 3:
printMatrixFromMemory(matrixComplex);
break;
default: break;
}
cout<<"---------"<<endl;
}


#endif //LABORATORY2_H_MENU_H
*/
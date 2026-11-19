#include<iostream>
#include "matrix.h"

void MatrixClass::createMatrix(int rowNum, int colNum){
    rows = rowNum;
    cols = colNum;

    if(grid == nullptr){
        //grid is given the pointer created by new int*, which returns the pointer to the int pointer array it created of size rows
        grid = new int*[rows];
        //assign each row pointer, grid[i], with the pointer of the int array that new int[cols] returns
        //() at the end fills them all with 0
        for(int i = 0; i < rows; i++){
            grid[i] = new int[cols]();
        }
    }
    else{

    }
}

void MatrixClass::printValue(int row, int col){
    //check bounds, then print data or error
    if(row <= rows && cols <= cols){
    std::cout << grid[row][col] << std::endl;
    }
    else{
        std::cout << "Invalid Input" << std::endl;
    }
}

void MatrixClass::multiply(int mult){
    //multiply every number in the matrix by an inputted value
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j] *= mult;
        }
    }
}

void MatrixClass::setData(){

    //read one character and assign it to decision
    char decision;
    std::cin >> decision;

    if(decision == 'r'){
        //random
    }
    else if(decision == 'm'){
        manualSet();
    }
    else{
        std::cout << "Invalid Input" << std::endl;
    }
}

void MatrixClass::manualSet(){
    int row = 0;
    int col = 0;
    int data = 0;

    //study how input output stream works to do this properly
    std::cout << "Enter row to insert at: ";
    std::cin >> row;
}
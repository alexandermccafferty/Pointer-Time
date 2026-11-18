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
    //add bounds checks to this tomorrow
    std::cout << grid[row][col];
}

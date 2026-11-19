#include<iostream>
#include "matrix.h"
#include<limits>

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
    if(row >+ 0 && row <= rows && col >= 0 && col <= cols){
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

//ask what data setting method to use, call that method
void MatrixClass::setData(){

    //read one character and assign it to decision
    char decision = charInput("Enter m to manually enter a data point, or r to fill the matrix randomly: ");

    if(decision == 'r'){
        //random
    }
    else if(decision == 'm'){
        manualSet();
    }
    else{
        std::cout << "Invalid input, please enter one of the options" << std::endl;
        setData();
    }
}

//manually set data at a certain row and column
void MatrixClass::manualSet(){
    int row = 0;
    int col = 0;
    int data = 0;

    //-1 to adjust user input to index. data remains as inputted.
    row = intInput("Enter row to insert at: ", rows) - 1;
    col = intInput("Enter column to insert at: ", cols) - 1;
    data = intInput("Enter number to insert at target: ", std::numeric_limits<int>::max());
    grid[row][col] = data;
}

//get input, making sure to check for input type and bounds
int MatrixClass::intInput(const char* message, int limit){
    int choice;
    //for bounds checking
    int max = limit;
    std::cout << message;
    while(true){
        if(!(std::cin >> choice)){
            //if the cin fails, it will enter a fail state, leading to this
            std::cout << "Invalid input, please enter a valid number: ";

            //clear cin fail state, allowing it to be used again
            std::cin.clear();
            
            //ignore dumps input stream, parameters are how many characters to dump, and what to stop at
            //we read basically as long as we can (numeric_limits max())
            //the <> after numeric limits provides the type, std::streamsize is the type for stream character counting
            //hit \n, dump that, and stop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //assume 1 based indexing for user input, check with 0-based, return 1-based and adjust in manualSet, so non-row/col input is preserved
        else if(choice - 1 >= max || choice < 1){
            std::cout << "Number out of bounds, please enter a valid number: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }   
}

//same as int input but for char, and without bounds checking
char MatrixClass::charInput(const char* message){
    char choice;
    std::cout << message;
    while(true){
        if(!(std::cin >> choice)){
            std::cout << "Invalid input, please enter one of the given options: ";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
        return choice;
        }
    }   
}
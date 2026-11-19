#include <iostream>
#include "matrix.h"

//references!
void changeNum(int& num){
    num++;
}

void changeWPointer(int* num){
    (*num)++;
}


int main(){
    std::cout << "CMake Working" << std::endl;
    int var = 10;
    void* pointer = &var;
    std::cout << pointer << std::endl;
    int* referenceable = &var;
    std::cout << *referenceable << std::endl;

    //the seperate reference variable is redundant in this case
    int& ref = var;
    changeNum(ref);
    std::cout << var << std::endl;
    //the function can do the pass by reference on its own, like so
    changeNum(var);
    std::cout << var << std::endl;

    //passing pointer to edit var:
    int* varPtr = &var;
    changeWPointer(varPtr);
    std::cout << var << std::endl;

    MatrixClass matrix;
    matrix.createMatrix(5, 5);
    matrix.printValue(3, 2);

    matrix.multiply(3);
}
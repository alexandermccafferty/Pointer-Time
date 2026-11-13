#include <iostream>

int main(){
    std::cout << "CMake Working" << std::endl;
    int var = 10;
    void* pointer = &var;
    std::cout << pointer << std::endl;
    int* referenceable = &var;
    std::cout << *referenceable;
}
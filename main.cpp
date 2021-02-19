#include <iostream>
//#include "vector.h"
//#include "vector.cpp"
#include <vector>

int main() {

    std::vector<int> a;
    auto array = a.data();
    std::cout << array;
//    int a1 = 10;
//    const int& b = a1;
//    int* c = &a1;
//    fefu::vector<int> a;
//    a.push_back(10);
//    a.push_back(20);
//    for(auto it = a.begin(); it != a.end(); it++) {
//        std::cout << (*it);
//    }
    return 0;
}

#include <iostream>
#include "vector.h"
#include "vector.cpp"
#include <vector>
#include <string>

int main() {
    fefu::vector<int> a;
    a.push_back(10);
    a.push_back(20);
    for(auto it = a.begin(); it != a.end(); it++) {
        a.insert(it, 30);
    }

    for(int i = 0; i < a.size(); i++) {
        std::cout << a[i] << std::endl;
    }

    //fefu::vector<int> a;
//    std::cout << a.capacity();
//    for (int i = 0; i < 10000; i++) {
//        a.push_back(i * 5);
//        std::cout << a.capacity() << std::endl;
//    }
//    std::cout << std::endl;
//
//    for(int i = 0; i < a.size(); i++) {
//        std::cout << a[i] << std::endl;
//    }



//    for(int i = 0; i < a.size(); i++) {
//        std::cout << a[i] << std::endl;
//    }

//    a.resize(10);
//
//    std::cout << a[6];
//    for(int i = 0; i < a.size(); i++) {
//        std::cout << a[i] << std::endl;
//    }
    return 0;
}

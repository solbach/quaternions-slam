#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <eigen3/Eigen/Dense>

class Util
{
public:
    Util();

    template<typename T>
    static void printEigen(T& value)
    {
        std::cout << value << "\n" << std::endl;
    }
};

#endif // UTIL_H

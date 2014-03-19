#include <iostream>
#include <eigen3/Eigen/Dense>



int main(int argc, const char* argv[])
{
    std::cout << "Hello Eigen" << std::endl;

    Eigen::Matrix2d a;
    a << 1, 2, 8, 9;

    std::cout << a << std::endl;

    std::cout << "Adiós Eigen" << std::endl;
    return 0; 
}

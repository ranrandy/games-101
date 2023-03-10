#include<cmath>
#include<eigen/Eigen/Core>
#include<eigen/Eigen/Dense>
#include<iostream>


int main(){

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a/b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0/180.0*acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;
    // vector dot product
    std::cout << "Example of dot product \n";
    std::cout << v.dot(w) << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    std::cout << "matrix add i + j \n";
    std::cout << i + j << std::endl;
    // matrix scalar multiply i * 2.0
    std::cout << "matrix scalar multiply i * 2.0 \n";
    std::cout << i*2.0 << std::endl;
    // matrix multiply i * j
    std::cout << "matrix multiply i * j \n";
    std::cout << i * j << std::endl;
    // matrix multiply vector i * v
    std::cout << "matrix multiply vector i * v \n";
    std::cout << i * v << std::endl;

    // hw0: 
    // Given P(2, 1), rotate 45 degrees counterclockwise, then translate (1, 2)
    Eigen::Vector3f p;
    p << 2, 1, 1; // Homogenous coordinate
    Eigen::Matrix3f rotate, translate;
    rotate << std::sqrt(2)/2.0, -std::sqrt(2)/2.0, 0,
              std::sqrt(2)/2.0,  std::sqrt(2)/2.0, 0,
                             0,                 0, 1;
    translate << 1, 0, 1,
                 0, 1, 2,
                 0, 0, 1;
    Eigen::Vector3f p_transformed;
    p_transformed << translate * rotate * p;
    std::cout << "transformed p:" << std::endl << p_transformed << std::endl;

    return 0;
}

/*
 * Source: https://eigen.tuxfamily.org/dox/GettingStarted.html
 *
 * There is no library to link to. The only thing that you need to keep in mind 
 * when compiling the above program is that the compiler must be able to find the 
 * Eigen header files. The directory in which you placed Eigen's source code must 
 * be in the include path. With GCC you use the -I option to achieve this, so you 
 * can compile the program with a command like this:
 * 
 * g++ -I /path/to/eigen/ my_program.cpp -o my_program 
 * 
 * On Linux or Mac OS X, another option is to symlink or copy the Eigen folder 
 * into /usr/local/include/. This way, you can compile the program with:
 * 
 * g++ my_program.cpp -o my_program 
 */

/*
 * Eigen library after 3.4.0 needs at least C++14 standard
 */
     
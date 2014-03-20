/**
 * @file
 * @author  Markus Solbach <mksolb@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Perform a Composition of two 3D States [x, y, theta]
 * Calculate the Jacobian (J1, J2) and Covariance (P) as well
 *
 * @section TODO
 * - Implementation
 */

#include <ctime>
#include <iostream>
#include <eigen3/Eigen/Dense>

#include "util.h"

/** Composition of two 2D States.
 *
 * State 1 goes from A --> B. State 2 goes from B --> C.
 * The composition of c(A,B) gives us the movement A --> C.
 * Usefull to calculate the absolute Pose of relative Poses, which
 * started at a given point of origin ( mostly [0,0,0] )
 * In this case we use the motion model derived from Pioneer 3-DX
 */
Eigen::Vector3d composition(const Eigen::Vector3d& x1,
                            const Eigen::Vector3d& x2,
                            Eigen::Matrix3d& J1,
                            Eigen::Matrix3d& J2)
{
    Eigen::Vector3d result;

    // Calculate the new position
    result[0] = ( x1(0) + x2(0)*cos((x1(2)*M_PI)/180)
                  - x2(1)*sin((x1(2)*M_PI)/180) );

    result[1] = ( x1(1) + x2(0)*sin((x1(2)*M_PI)/180)
                  + x2(1)*cos((x1(2)*M_PI)/180) );

    result[2] = ( x1(2) + x2(2) );

    // Calculate Jacobian 1
    J1(0,0) = 1;
    J1(0,1) = 0;
    J1(0,2) = -x2(0)*sin((x1(2)*M_PI)/180) - x2(1)*cos((x1(2)*M_PI)/180);

    J1(1,0) = 0;
    J1(1,1) = 1;
    J1(1,2) = x2(0)*cos((x1(2)*M_PI)/180) - x2(1)*sin((x1(2)*M_PI)/180);

    J1(2,0) = 0;
    J1(2,1) = 0;
    J1(2,2) = 1;

    // Calculate Jacobian 2
    J2(0,0) = cos((x1(2)*M_PI)/180);
    J2(0,1) = -sin((x1(2)*M_PI)/180);
    J2(0,2) = 0;

    J2(1,0) = sin((x1(2)*M_PI)/180);
    J2(1,1) = cos((x1(2)*M_PI)/180);
    J2(1,2) = 0;

    J2(2,0) = 0;
    J2(2,1) = 0;
    J2(2,2) = 1;

    return result;
}

int main(int argc, const char* argv[])
{
    time_t t = time(0);
    std::cout << "Hello Eigen at " << t << "\n" << std::endl;


    Eigen::Vector3d xAB, xBC, xAC;
    Eigen::Matrix3d J1, J2;

    // x, y, theta
    xAB << 4, 19, 20;
    xBC << 10, 10, 20;

    xAC = composition(xAB, xBC, J1, J2);

    Util::printEigen(xAC);
    Util::printEigen(J1);
    Util::printEigen(J2);

    std::cout << "\nAdiós Eigen" << std::endl;
    return 0; 
}

/**
* #######################################################################
* ########################### A p p e n d i x ###########################
* #######################################################################
*/

/** Calculate Covariance in Eigen-Style
* MatrixXd centered = mat.rowwise() - mat.colwise().mean();
* MatrixXd cov = (centered.adjoint() * centered) / double(mat.rows());

* Eigen::MatrixXi m(10, 10);
* m(0, 1) = 1;
* m(0, 2) = 2;
* m(0, 3) = 3;
*/

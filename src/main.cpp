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


/** Composition of two 2D States.
 *
 * State 1 goes from A --> B. State 2 goes from B --> C.
 * The composition of c(A,B) gives us the movement A --> C.
 * Usefull to calculate the absolute Pose of relative Poses, which
 * started at a given point of origin ( mostly [0,0,0] )
 */


int main(int argc, const char* argv[])
{
    time_t t = time(0);
    std::cout << "Hello Eigen at " << t << "\n" << std::endl;


    Eigen::Vector3d xAB, xBC;

    // x, y, theta
    xAB << 0, 0, 0;
    xBC << 10, 10, 20;

    std::cout << xAB + xBC << std::endl;

    std::cout << "\nAdiós Eigen" << std::endl;
    return 0; 
}

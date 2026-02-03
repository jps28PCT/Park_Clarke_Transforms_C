/*
MIT License

Copyright (c) 2026 Jacob Smithmyer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <math.h>

#include "park_clarke_trsfm.h"


/******************  CONSTANT DEFINTIONS  *******************/
#define CONST_1OVER3        0.33333333333333333333333333333333
#define CONST_2OVER3        0.66666666666666666666666666666666
#define CONST_SQRT3OVER3    0.57735026918962576450914878050196



/******************  FUNCTION DEFINTIONS  *******************/


/*****************************************************************************
 * This function normalizes an input vector to have a magnitude of 1.
 *
 * @param	Vector is the pointer to the first element of the vector
            (type double) to be normalized.  When the function is complete, 
            the same vector will contain the normalized values.
 * @param	n is the size of the vector.
 * 
 * @return	0
****************************************************************************/
int vector_normalize(double *Vector, int n){
    double squareSum = 0;
    double magnitude;
    int i;
    
    for (i=0; i<n; i++){
        squareSum = squareSum + pow(Vector[i], 2);
    }
    
    magnitude = sqrt(squareSum);

    for (i=0; i<n; i++){
        Vector[i] = Vector[i]/magnitude;
    }

    return 0;
}



/*****************************************************************************
 * This function performs the Clarke transform to transform a three-phase
 * vector to a two-phase quadrature vector.
 *
 * @param	InputVector is the pointer to the first element of the 3-element
 *          double vector to be transformed.
 * @param	OutputVector is the pointer to the first element of the 2-element
 *          double vector that contains the quadrature result of the vector.
 * 
 * @return	0
****************************************************************************/
int clarke_trsfm(double *InputVector, double *OutputVector){
    OutputVector[0] = (CONST_2OVER3 * InputVector[0]) - (CONST_1OVER3 * InputVector[1]) - (CONST_1OVER3 * InputVector[2]);
    OutputVector[1] = (CONST_SQRT3OVER3 * InputVector[1]) - (CONST_SQRT3OVER3 * InputVector[2]);

    return 0;
}



/*****************************************************************************
 * This function performs the inverse Clarke transform to transform a 
 * two-phase quadrature vector to a three-phase vector.
 *
 * @param	InputVector is the pointer to the first element of the 2-element
 *          double vector to be transformed.
 * @param	OutputVector is the pointer to the first element of the 3-element
 *          double vector that contains the three-phase result.
 * 
 * @return	0
****************************************************************************/
int inv_clarke_trsfm(double *InputVector, double *OutputVector){
    OutputVector[0] = CONST_2OVER3 * InputVector[0];
    OutputVector[1] = (CONST_SQRT3OVER3 * InputVector[1]) - (CONST_1OVER3 * InputVector[0]);
    OutputVector[2] = -1 * ((CONST_1OVER3 * InputVector[0]) + (CONST_SQRT3OVER3 * InputVector[1]));

    return 0;
}



/*****************************************************************************
 * This function performs the Park transform to rotate a quadrature 2-phase
 * vector.
 *
 * @param	InputVector is the pointer to the first element of the 2-element
 *          double vector to be transformed.
* @param	theta is the type-double angle to rotate the vector.
 * @param	OutputVector is the pointer to the first element of the 2-element
 *          double vector that contains the quadrature result of the vector.
 * 
 * @return	0
****************************************************************************/
int park_trsfm(double *InputVector, double theta, double *OutputVector){
    double sin_theta = sin(theta);
    double cos_theta = cos(theta);

    OutputVector[0] = (cos_theta * InputVector[0]) + (sin_theta * InputVector[1]);
    OutputVector[1] = (cos_theta * InputVector[1]) - (sin_theta * InputVector[0]);

    return 0;
}



/*****************************************************************************
 * This function performs the inverse Park transform to rotate a quadrature 
 * 2-phase vector.
 *
 * @param	InputVector is the pointer to the first element of the 2-element
 *          double vector to be transformed.
 * @param	theta is the type-double angle to rotate the vector.
 * @param	OutputVector is the pointer to the first element of the 2-element
 *          double vector that contains the quadrature result of the vector.
 * 
 * @return	0
****************************************************************************/
int inv_park_trsfm(double *InputVector, double theta, double *OutputVector){
    double sin_theta = sin(theta);
    double cos_theta = cos(theta);
    
    OutputVector[0] = (cos_theta * InputVector[0]) - (sin_theta * InputVector[1]);
    OutputVector[1] = (sin_theta * InputVector[0]) + (cos_theta * InputVector[1]);

    return 0;
}

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

#ifndef PARK_CLARKE_TRSFM_H
#define PARK_CLARKE_TRSFM_H

/******************  FUNCTION PROTOTYPES  *******************/


/*****************************************************************************
 * This function normalizes an input vector to have a magnitude of 1.
 *
 * @param	Vector is the pointer to the first element of the vector
 *           (type double) to be normalized.  When the function is complete, 
 *           the same vector will contain the normalized values.
 * @param	n is the size of the vector.
 * 
 * @return	0
****************************************************************************/
int vector_normalize(double *Vector, int n);



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
int clarke_trsfm(double *InputVector, double *OutputVector);



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
int inv_clarke_trsfm(double *InputVector, double *OutputVector);



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
int park_trsfm(double *InputVector, double theta, double *OutputVector);



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
int inv_park_trsfm(double *InputVector, double theta, double *OutputVector);

#endif //#ifndef PARK_CLARKE_TRSFM_H

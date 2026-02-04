# Park_Clarke_Transforms_C

C implementation of the Park and Clark transforms, as well as their inverses.</br>  
Requires `<math.h>` for `sin()` and `cos()`.</br> 
</br> 
The Park transform converts three-phase vectors in the time domain to a stationary two-phase vector.</br>
The Clarke transform rotates the two-phase vector into a consistent reference frame.</br>
</br>
I developed this as part of a field-oriented control BLDC motor project.  

<details>
  <summary>Functions</summary>

  ## vector_normalize(double *Vector, int n)
  This function normalizes an input vector to have a magnitude of 1.

  ### Inputs:
  - `Vector` is the pointer to the first element of the vector (type double) to be normalized.  When the function is complete, the same vector will contain the normalized values.
  
  ### Returns:
  - `0`


  ## int clarke_trsfm(double *InputVector, double *OutputVector)
  This function performs the Clarke transform to transform a three-phase vector to a two-phase quadrature vector.

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 3-element double vector to be transformed.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`


  ## int inv_clarke_trsfm(double *InputVector, double *OutputVector)
  This function performs the inverse Clarke transform to transform a two-phase quadrature vector to a three-phase vector.

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `OutputVector` is the pointer to the first element of the 3-element  double vector that contains the three-phase result.

  ### Returns:
  - `0`


  ## int park_trsfm(double *InputVector, double theta, double *OutputVector)
  This function performs the Park transform to rotate a quadrature 2-phase vector to the standard reference frame.

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `theta` is the type-double angle to rotate the vector in rad.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`


  ## int inv_park_trsfm(double *InputVector, double theta, double *OutputVector)
  This function performs the inverse Park transform to rotate a quadrature 2-phase vector from the standard reference frame.

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `theta` is the type-double angle to rotate the vector in rad.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`

  
</details>

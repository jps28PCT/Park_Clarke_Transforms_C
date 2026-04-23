# Park_Clarke_Transforms_C

C implementation of the Park and Clark transforms, as well as their inverses.</br>  
Requires `<math.h>` for `sin()` and `cos()`.</br> 
</br> 
The Clarke transform converts three-phase vectors in the time domain to a stationary two-phase vector.</br>
The Park transform rotates the two-phase stationary vector into a rotating reference frame.</br>
</br>
I developed this as part of a field-oriented control BLDC motor project.  

<details>
  <summary>Functions</summary>

  ## int vector_normalize(double *Vector, int n)
  This function normalizes an input vector to have a magnitude of 1.

  ### Inputs:
  - `Vector` is the pointer to the first element of the vector (type double) to be normalized.  When the function is complete, the same vector will contain the normalized values.
  - `n` is the size of the vector.
  
  ### Returns:
  - `0`


  ## int clarke_trsfm(double *InputVector, double *OutputVector)
  This function performs the Clarke transform to transform a three-phase vector to a two-phase quadrature vector.

  Clarke Transform:
  ```math
  \left[\begin{matrix}\alpha\\\beta\end{matrix}\right]=\frac{2}{3}\left[\begin{matrix}1&\tfrac{-1}{2}&\tfrac{-1}{2}\\0&\tfrac{\sqrt3}{2}&\tfrac{-\sqrt3}{2}\end{matrix}\right]\left[\begin{matrix}u\\v\\w\end{matrix}\right]
 ```


  ### Inputs:
  - `InputVector` is the pointer to the first element of the 3-element double vector to be transformed.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`


  ## int inv_clarke_trsfm(double *InputVector, double *OutputVector)
  This function performs the inverse Clarke transform to transform a two-phase quadrature vector to a three-phase vector.

  Inverse Clarke Transform:
  ```math
  \left[\begin{matrix}u\\v\\w\end{matrix}\right]=\frac{2}{3}\left[\begin{matrix}1&0\\\tfrac{-1}{2}&\tfrac{\sqrt3}{2}\\\tfrac{-1}{2}&\tfrac{-\sqrt3}{2}\end{matrix}\right]\left[\begin{matrix}\alpha\\\beta\end{matrix}\right]
  ```

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `OutputVector` is the pointer to the first element of the 3-element  double vector that contains the three-phase result.

  ### Returns:
  - `0`


  ## int park_trsfm(double *InputVector, double theta, double *OutputVector)
  This function performs the Park transform to rotate a quadrature 2-phase stationary vector to a rotated reference frame.

  Park Transform:
  ```math
  \left[\begin{matrix}d\\q\end{matrix}\right]=\left[\begin{matrix}\cos{\theta}&\sin{\theta}\\-\sin{\theta}&\cos{\theta}\end{matrix}\right]\left[\begin{matrix}\alpha\\\beta\end{matrix}\right]
  ```

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `theta` is the type-double angle to rotate the vector in rad.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`


  ## int inv_park_trsfm(double *InputVector, double theta, double *OutputVector)
  This function performs the inverse Park transform to rotate a quadrature 2-phase vector to a stationary reference frame.

  Inverse Park Transform:
  ```math
  \left[\begin{matrix}\alpha\\\beta\end{matrix}\right]=\left[\begin{matrix}\cos{\theta}&-\sin{\theta}\\\sin{\theta}&\cos{\theta}\end{matrix}\right]\left[\begin{matrix}d\\q\end{matrix}\right]
  ```

  ### Inputs:
  - `InputVector` is the pointer to the first element of the 2-element double vector to be transformed.
  - `theta` is the type-double angle to rotate the vector in rad.
  - `OutputVector` is the pointer to the first element of the 2-element double vector that contains the quadrature result of the vector.

  ### Returns:
  - `0`

  
</details>

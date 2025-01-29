Amar 1 ta matrix nxn matrix hbe x-matrix.
  if 
  All the elements in the diagonals of the matrix are non-zero.
All other elements are 0.
  1 ta for loop chai i=0 to n porjonto
nested for chalai j=0 to n porjonto 
diagonal hbe if i=j hoy
and diagonal non-zero hoy so,
if(i==j)
                {
                    if(grid[i][j]!=0)
                    {
                        type=true;
                    }
                   if(grid[i][j]==0)
                   {
                    type=false;
                   }
                }

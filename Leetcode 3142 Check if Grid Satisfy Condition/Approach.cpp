Amar 1 ta 2D array ba matrix ase.
amar condition
Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return true if all the cells satisfy these conditions, otherwise, return false.
  1 ta for loop chalai i=0 to n porjonto row traverse
nested for loop chalai j=0 to n porjonto column traverse 
check bound to avoid runtime error
 if(i + 1 < grid.size() &&grid[i][j]!=grid[i+1][j])
                {
                    type=false;

                }
                if(j + 1 < grid[i].size() &&grid[i][j]==grid[i][j+1])
                {
                    type=false;

                }
na hoile 
               if(!type)  karon initial type false.
                {
                return type;
                }

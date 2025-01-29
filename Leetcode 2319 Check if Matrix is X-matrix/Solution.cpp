#include<vector>
 class Solution 
 { 
    public: bool checkXMatrix(vector<vector<int>>& grid) 
    {
         bool type=true; 
         for(int i=0;i<grid.size();i++)
          { 
            for(int j=0;j<grid.size();j++) 
            { 
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
               // if(i!=j)
               // {
                   //if(grid[i][j]==0)
                    //{
                       // type=true;
                  //  }
                  // if(grid[i][j]!=0)
                  // {
                   // type=false;
                 //  }
               // }
                  if (i == j || i + j ==grid.size() - 1) 
                { 
                    if (grid[i][j] == 0) 
                    { 
                        type= false; 
                    }
                } 
                else 
                { 
                    if (grid[i][j] != 0) 
                    { 
                        type= false; 
                    }
                }
                if(!type) 
                {
                    return false;
                }
            }
          }
          return type;
    }
 };
                                               

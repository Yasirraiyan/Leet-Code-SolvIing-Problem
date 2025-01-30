#include<vector>
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int primarysum=0;
        int secondarysum=0;
        int finalsum;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
              if(i==j)
              {
                primarysum+=mat[i][j];
              }
            }
        }
         for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
              if(i+j==mat.size()-1)
              {
                secondarysum+=mat[i][j];
              }
            }
        }
        if((mat.size())%2==1)
        {
           primarysum-=mat[mat.size()/2][mat.size()/2];
        }
        finalsum=primarysum+secondarysum;
        return finalsum;
    }
};

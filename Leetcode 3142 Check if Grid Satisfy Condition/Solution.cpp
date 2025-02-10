class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        bool type=true;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i + 1 < grid.size() &&grid[i][j]!=grid[i+1][j])
                {
                    type=false;

                }
                if(j + 1 < grid[i].size() &&grid[i][j]==grid[i][j+1])
                {
                    type=false;

                }
                if(!type)
                {
                return type;
                }

            }
        }
        return type;
    }
};

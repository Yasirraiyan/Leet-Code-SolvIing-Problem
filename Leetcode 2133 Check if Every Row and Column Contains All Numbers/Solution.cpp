class Solution 
{
public:
    int findsize(vector<vector<int>>& matrix)
    {
        int size;
        for(int i=0;i<matrix.size();i++)
            {
                        size=matrix[i].size();
                        break;    
            }
        return size;
    }
    bool checkValid(vector<vector<int>>& matrix)
{
        bool checkcol=true;
        bool checkrow=true;
        bool isvalid=true;
        int size=findsize(matrix);
        unordered_map<int,int>freq;
        unordered_set<int>set1;
        for(int i=1;i<=size;i++)
            {
                set1.insert(i);
            }
        for(int j=0;j<matrix.size();j++)
            {
                for(int k=0;k<matrix.size();k++)
                    {
                        freq[matrix[j][k]]++;
                    }
            }
        for(int i=0;i<matrix.size();i++)
            {
                unordered_map<int,int>freqrow;
                for(int j=0;j<matrix[i].size();j++)
                    {
                        freqrow[matrix[i][j]]++;
                        if(set1.find(matrix[i][j])!=set1.end())
                        {
                        if(freqrow[matrix[i][j]]>1)
                        {
                            checkrow=false;
                            break;
                        }  
                    }
                        else
                        {
                            checkrow=false;
                        }
                if(!checkrow) break;
                    }
                    }
        for(int i=0;i<matrix[0].size();i++)
            {
                unordered_map<int,int>freqcol;
                for(int j=0;j<matrix.size();j++)
                    {
                        freqcol[matrix[j][i]]++;
                        if(set1.find(matrix[j][i])!=set1.end())
                        {
                        if(freqcol[matrix[j][i]]>1)
                        {
                            checkcol=false;
                            break;
                        }
                            else
                        {
                                checkcol=true;
                            }
                        }
                        else
                        {
                            checkcol=false;
                            break;
                        }
                    }
                if(!checkcol) break;
            }
        for(auto it:freq)
            {
                if(it.second!=size)
                {
                    isvalid=false;
                    break;
                }
            }
        if(!checkcol||!checkrow)
        {
            isvalid=false;
        }
        else
        {
            isvalid=true;
        }
        return isvalid;
}
};

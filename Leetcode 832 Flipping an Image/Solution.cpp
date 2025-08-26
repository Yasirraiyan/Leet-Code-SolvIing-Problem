class Solution {
public:
 vector<int>flip(vector<int>&v)
 {
    vector<int>vv;
    for(int i=v.size()-1;i>=0;i--)
    {
        vv.push_back(v[i]);
    }
    return vv;
 }
 vector<int>invert(vector<int>&v)
 {
    
    for(int j=0;j<v.size();j++)
    {
        if(v[j]==0)
        {
          v[j]=1;
        }
       else if(v[j]==1)
        {
          v[j]=0;
        }
        
        //v[j]^=1;
    }
    return v;
 }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
     {
        for(int i=0;i<image.size();i++)
        {
          vector<int> row=image[i];
          row=flip(row);
          row=invert(row);
          image[i]=row;
        }
        return image;
    }
};

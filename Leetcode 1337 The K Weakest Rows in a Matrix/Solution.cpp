class Solution 
{
public:
static bool cmp(pair<int, int> a, pair<int, int> b)
{
  if(a.second==b.second)
  return a.first<b.first;
  return a.second<b.second;
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
       int count=0;
      vector<pair<int, int>> v ;
      for(int i=0;i<mat.size();i++)
      {
        count=0;
        for(int j=0;j<mat[i].size();j++)
        {
          if(mat[i][j]==1)
          {
            count++;
            
          }
          else
          {
            break;
          } 
        }
         v.push_back({i,count});
      }
     sort(v.begin(),v.end(),cmp);
     vector<int>ans;
     for(auto it:v)
     {
      ans.push_back(it.first);
      if(ans.size()==k)
      {
        break;
      }
     }
     return ans;
    }
};

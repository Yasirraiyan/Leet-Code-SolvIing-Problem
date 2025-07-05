class Solution 
{
public:
 int findmax(vector<int>&arr)
 {
  int max=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]>max)
    {
      max=arr[k];
    }
  }
  return max;
 }
 int findmin(vector<int>&arr)
 {
  int min=arr[0];
  for(int k=1;k<arr.size();k++)
  {
    if(arr[k]<min)
    {
      min=arr[k];
    }
  }
  return min;
 }
    int secondHighest(string s) 
    {
      vector<int>v;
      for(int i=0;i<s.size();i++)
      {
        if(isdigit(s[i]))
        {
          v.push_back(s[i]-'0');
        }
      }
      unordered_map<int,int>freq;
      for(int j=0;j<v.size();j++)
      {
        freq[v[j]]++;
      }
      vector<int>vv;
      for(auto it:freq)
      {
        vv.push_back(it.first);
      }
      if(vv.size()<2)return -1;
      int ans;
        sort(vv.begin(), vv.end());
      if(vv.size()>=2)
      {
          if(vv.size()==3)
          {
            for(int i=0;i<vv.size();i++)
            {
              if(vv[i]!=findmax(vv)&&vv[i]!=findmin(vv))
              {
                  ans=vv[i];
                  break;
              }
            }
          }
      }
      ans=vv[vv.size()-2];
      return ans;
    }
};

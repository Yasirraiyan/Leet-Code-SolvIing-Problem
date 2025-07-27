class Solution 
{
public:
 const long long MOD = 1e9 + 7;
  vector<long long>PSum(vector<long long>&v)
  {
    vector<long long>p(v.size(),1);
    v[0]=1;
    for(int i=1;i<v.size();i++)
    {
      p[i]=(p[i-1]+v[i])%MOD;
    }
    return p;
  }
    int valueAfterKSeconds(int n, int k)
    {
      vector<long long>v(n,1);
      v[0]=1;
      int count=0;
      for(int i=1;i<k+1;i++)
      {
       // v[i]=PSum(v);
       v=PSum(v);
        count++;
        if(count==k)
        {
          break;
        }
      }
      int ans=v[v.size()-1]%1000000007;
      return ans;
    }
};

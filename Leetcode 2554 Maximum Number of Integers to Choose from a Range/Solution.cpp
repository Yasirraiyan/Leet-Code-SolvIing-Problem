class Solution 
{
public:
 int findsum(int a,int b)
 {
  return a+b;
 }
    int maxCount(vector<int>& banned, int n, int maxSum) 
{
      int count=0;
        unordered_set<int>set1;
        for(int j=0;j<banned.size();j++)
        {
          set1.insert(banned[j]);
        }
        vector<int>vv;
        for(int i=1;i<=n;i++)
        {
          if(set1.find(i)==set1.end())
          {
            vv.push_back(i);
          }
        }
        sort(vv.begin(),vv.end());
        vector<int>vvv;
        int sum=0;

        for(int i=0;i<vv.size();i++)
        {
              sum+=vv[i];
              if(sum<=maxSum)
              {
                vvv.push_back(vv[i]);
              }
        }
count=vvv.size();
return count;
    }
};

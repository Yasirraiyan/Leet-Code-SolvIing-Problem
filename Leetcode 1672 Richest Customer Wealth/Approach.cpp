Amar 1 ta 2-D array ase.Amar etar protita segment er sum ber kore maximum return korte hbe.
So, 1st e 1 ta for loop chalai i=0 to i<arr.size() porjonto.
  Nested for chalai j=0 to j<arr[i].size() porjonto.

Karon jodi ami 1st row er sum chai taile i=0; j<arr[i].size() hoy mane arr[0] namok row means 1st row te loop chalai all number sum kori.
then sum kori sum+=arr[i][j];
Eta protita row er sum tai etake 1 ta vector array te rakhi karon lagbe max. Dhori vector array er nam ans.
  tai kori
sum+=accounts[i][j];
              ans.push_back(sum);

loop er code:
-------------
  vector<int>ans;
        for(int i=0;i<accounts.size();i++)
        {
          int sum=0;
          for(int j=0;j<accounts[i].size();j++)
          {
              sum+=accounts[i][j];
              ans.push_back(sum);
          }
        }
then max chaise tai inital max=ans[0];
1 ta loop chalai k=0 to k<ans.size()  porjonto and k++ kori
  chack max
if(ans[k]>max)
          {
            max=ans[k];
          }
return kori max.
  loop er code:
----------------
   int max=ans[0];
        for(int k=0;k<ans.size();k++)
        {
          if(ans[k]>max)
          {
            max=ans[k];
          }
        }

Full code:
---------

  class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts)
{
        vector<int>ans;
        for(int i=0;i<accounts.size();i++)
        {
          int sum=0;
          for(int j=0;j<accounts[i].size();j++)
          {
              sum+=accounts[i][j];
              ans.push_back(sum);
          }
        }
        int max=ans[0];
        for(int k=0;k<ans.size();k++)
        {
          if(ans[k]>max)
          {
            max=ans[k];
          }
        }
        return max;
    }
};

class Solution
 {
  public:
    int findmax(vector<int>&arr)
    {
      int max=arr[0];
      for(int i=1;i<arr.size();i++)
     {
      if(arr[i]>max)
      {
        max=arr[i];
      }
     }
     return max;
    }
    int largestAltitude(vector<int>&gain)
    {
      int n=gain.size();
      vector<int>reserve(n+1);
       reserve[0]=0;
       int ans;
       for(int j=1;j<=n;j++)
       {
        reserve[j]=reserve[j-1]+gain[j-1];
        
       }
       ans=findmax(reserve);
       return ans;
    }
 };

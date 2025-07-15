class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int>set1;
        int ans;
        for(int i=0;i<arr.size();i++)
        {
          set1.insert(arr[i]);
        }
        int count=0;
        for(int j=1;count<k;j++)
        {
          if(set1.find(j)==set1.end())
          {
            count++;
            if(count==k)
            {
                 ans=j;
                 break;
            }
          }
        }
return ans;
    }
};

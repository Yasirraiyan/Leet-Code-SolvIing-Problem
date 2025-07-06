class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
       for(int i=0;i<nums.size();i++)
       {
        freq[nums[i]]++;
       }
       int n=nums.size();
       vector<int>reserve;
       for(int j=0;j<=n;j++)
       {
        reserve.push_back(j);
       }
       int  miss;
       for(int k=0;k<reserve.size();k++)
       {
        if(freq[reserve[k]]==0)
        {
            miss=reserve[k];
            break;
        }
       }
       return miss;
    }
};

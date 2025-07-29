class Solution 
{
public:
    int CalculateSum(vector<int>&v)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
            {
                sum+=v[i];
            }
        return sum;
    }
    bool findSubarrays(vector<int>& nums)
    {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i;j<nums.size();j++)
                    {
                        int subarraysize=j-i+1;
                                if(subarraysize==2)
                                {
                          vector<int>sub={nums[i],nums[j]};
                                {
                                    freq[CalculateSum(sub)]++;    
                                }
                            }
                    }
            }
        bool find=false;
        for(auto it:freq)
            {
                if(it.second>1)
                {
                    find=true;
                    break;
                }
            }
        return find;
    }
};

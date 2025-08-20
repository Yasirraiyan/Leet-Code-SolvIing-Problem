class Solution
{
public:
    bool TestPrime(int n)
    {
        bool test=true;
        if(n<2) return false;
        for(int i=2;i*i<=n;i++)
            {
                if(n%i== 0)
                {
                    test=false;
                    break;
                }
            }
        return test;
    }
    int findmax(vector<int>&arr)
    {
        int max=arr[0];
        for(int j=1;j<arr.size();j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
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
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
            {
                if(TestPrime(nums[i]))
                {
                    v.push_back(i);
                }
            }
        if(v.size()==1) return 0;
        int max=findmax(v);
        int min=findmin(v);
        int ans=max-min;
        return ans;
    }
};

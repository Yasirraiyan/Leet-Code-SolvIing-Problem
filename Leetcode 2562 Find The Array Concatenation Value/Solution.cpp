class Solution 
{
public:
    long long findTheArrayConcVal(vector<int>& nums) 
    {
        int low=0;
        int high=nums.size()-1;
        long long sum=0;
        while(low<=high)
        {
             if (low == high) 
             {
        sum += nums[low];
        low++;
        high--; // middle element
               }
               else
               { 
            string a=to_string(nums[low]);
           string  b=to_string(nums[high]);
           string c=a+b;
            long long generate=stoll(c);
            sum+=generate;
            low++;
            high--;
               }
        }
        return sum;
    }
};

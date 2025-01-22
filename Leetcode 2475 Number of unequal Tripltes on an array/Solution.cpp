class Solution
{
public:
    int unequalTriplets(vector<int>& nums)
{
        int count = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int j = i + 1; j < nums.size(); j++)
              {
                for (int k = j + 1; k < nums.size(); k++)
                  {
                    if (0 <= i && i < j && j < k && nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) 
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};









































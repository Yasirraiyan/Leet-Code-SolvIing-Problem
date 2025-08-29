প্রশ্নটি পড়ার পর approach কেমন ভাবা যায়

Question summary:

তোমার কাছে একটি array nums আছে।

তুমি ঠিক k বার array এর element নেগেটিভ করতে পারো (i.e., nums[i] = -nums[i])।

একই index একাধিক বার ব্যবহার করা যাবে।

লক্ষ্য: maximized sum of array after k operations।

Step 1: Observation (ধরি array দেখার পরে)

নেগেটিভ সংখ্যা গুলোকে positive করলে sum বেড়ে যাবে।

উদাহরণ: nums = [-3, 2, 4] → -3 → 3 করলে sum বাড়বে।

সবচেয়ে ছোট absolute value element কে নেগেট করলে sum কম কমাবে না।

যদি সব element positive হয় আর k এখনও বাকি থাকে, তুমি ছোট element টাকে আবার negate করতে পারো।

Step 2: Strategy

প্রথমে negative elements গুলো positive করতে হবে, কারণ এটা sum বাড়াতে সবচেয়ে efficient।

তারপর যদি k বাকি থাকে:

sort করে array এবং smallest absolute value element কে negate করলে sum impact সবচেয়ে কম।

যদি k odd হয়, একবার negate করতে হবে, যদি even হয়, negate করলে sum impact হবে zero (two negation cancel out)।

Step 3: Technique

Greedy approach ব্যবহার হয়েছে:

ছোট negative elements গুলোকে প্রথমে positive করা।

বাকি k odd হলে smallest element কে negate করা।

Sorting ব্যবহার করা হয়েছে, কারণ negative elements এবং smallest element খুঁজতে সহজ হয়।

Solution code line-by-line analysis
class Solution {
public:


class declaration। LeetCode style.

Helper functions
int findmin(vector<int>& nums)
{
    int min=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<min)
        {
            min=nums[i];
        }
    }
    return min;
}


findmin: array এর smallest element খুঁজে বের করে।

এখানে linear search ব্যবহার হয়েছে।

bool FindNeg(vector<int>&nums)
{
    for(int k=0;k<nums.size();k++)
    {
        if(nums[k]<0)
        {
            return true;
        }
    }
    return false;
}


FindNeg: array এ negative number আছে কিনা চেক করে।

সত্যি হলে true, নাহলে false।

int FindSum(vector<int>&nums)
{
    int sum=0;
    for(int k=0;k<nums.size();k++)
    {
        sum+=nums[k];
    }
    return sum;
}


FindSum: array elements এর sum calculate করে।

Tip: এই helper functions না লিখেও STL ব্যবহার করা যায়: int sum = accumulate(nums.begin(), nums.end(), 0);

Main function
int largestSumAfterKNegations(vector<int>& nums, int k) 
{
    sort(nums.begin(),nums.end());


প্রথমে array sort করা হয়েছে।

কারন negative elements গুলোকে প্রথমে positive করতে হবে, তাই smallest elements আগে sort করে রাখা ভালো।

    for(int j=0;j<nums.size()&&k>0;j++)
    {
        if(nums[j]<0&&k>0)
        {
            nums[j]=-nums[j];
            k--;
        }
        if(k==0) break;
    }


loop through array:

যদি element negative হয় এবং k>0 → negate করো।

k কমানো হচ্ছে k--।

loop break, যখন k==0।

এখানে main greedy step হচ্ছে: negative elements কে positive করা, যতক্ষণ k আছে।

    sort(nums.begin(),nums.end());


আবার sort করা হয়েছে।

কারন: এখন আমরা smallest absolute value element কে negate করতে চাই, যদি k odd হয়।

    if(k%2==1)
    {
        nums[0]=-nums[0];
    }


যদি k odd হয়, smallest element negate করতে হবে।

এটি sum impact minimize করার জন্য।

    int ans=FindSum(nums);
    return ans;


সবশেষে array sum calculate করে return করা হয়েছে।

Step-by-step Example (Test case)

Input: nums = [2,-3,-1,5,-4], k = 2

Sort → [-4,-3,-1,2,5]

Loop to negate negative:

nums[0] = -(-4) = 4, k=1

nums[1] = -(-3) = 3, k=0

No need to check k%2 → k=0

Sum: 4+3+(-1)+2+5 = 13 → Output ✅

Summary of Approach

Sort array (negative elements প্রথমে)

Negate all negative numbers until k runs out

Check remaining k → if odd, negate smallest number

Return sum

Technique: Greedy + Sorting

Why greedy works: because negating smallest negative numbers maximizes sum at each step.

Time complexity: O(n log n) (sorting dominates)

Space complexity: O(1) extra

Full Code:
----------

class Solution {
public:
 int findmin(vector<int>& nums)
 {
    int min=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<min)
        {
            min=nums[i];
        }
    }
    return min;
 }
 bool FindNeg(vector<int>&nums)
 {
    for(int k=0;k<nums.size();k++)
    {
        if(nums[k]<0)
        {
            return true;
        }
    }
    return false;
 }
 int FindSum(vector<int>&nums)
 {
    int sum=0;
      for(int k=0;k<nums.size();k++)
    {
        sum+=nums[k];
    }
  return sum;
 }
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
            for(int j=0;j<nums.size()&&k>0;j++)
            {
                //if(FindNeg(nums))
                //{
                if(nums[j]<0&&k>0)
                {
                    nums[j]=-nums[j];
                    k--;
                }
               
            
            
             if(k==0) break;
            }
            sort(nums.begin(),nums.end());
            if(k%2==1)
            {
                nums[0]=-nums[0];
            }
            int ans=FindSum(nums);
            return ans;
        
    }
};

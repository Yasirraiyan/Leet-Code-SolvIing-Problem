প্রশ্ন বিশ্লেষণ:

আমাদের একটি even-length array nums আছে।

আমাদের pair তৈরি করতে হবে যাতে প্রতিটি element একবারই ব্যবহার হয়।

আমাদের লক্ষ্য হলো maximum pair sum কে minimize করা।

উদাহরণ:
nums = [3,5,2,3]

সব possible pairing:

(3,5) + (2,3) → pair sums = 8, 5 → max=8

(3,3) + (5,2) → pair sums = 6,7 → max=7 ✅ (minimum max)

মোট কথা:

আমরা চাই max(a+b) কম।

intuition: ছোট এবং বড় element একত্র করলে max pair sum কম হয়।

Solution Approach:

Step 1: Sort the array

sort(nums.begin(), nums.end());


কেন? sorted array হলে আমরা smallest element ও largest element জুটিতে পারি।

উদাহরণ: [2,3,3,5]

জুটি তৈরি: (2,5) এবং (3,3) → max pair sum = 7 ✅

Step 2: Two-pointer technique

int i=0;
int j=nums.size()-1;
while(i<j)
{
    int sum=nums[i]+nums[j];
    v.push_back(sum);
    i++;
    j--;
}


i → left pointer (smallest number)

j → right pointer (largest number)

প্রতি iteration:

left+right জোড়া sum করা

sum কে vector v তে রাখা

i++ ও j-- → move inward

কারণ:

ছোট element + বড় element = balanced pair sum

sorted না হলে, আমরা একা বড় element জুড়ে pair করলে max sum অনেক বড় হতে পারে।

Step 3: Find maximum sum from pairs
int ans=findmax(v);


এখানে আমরা vector v থেকে largest sum বের করি।

findmax function:

int findmax(vector<int>& nums) {
    int max=nums[0];
    for(int k=1;k<nums.size();k++)
    {
        if(nums[k]>max)
        {
            max=nums[k];
        }
    }
    return max;
}


simple linear search → O(n/2) = O(n)

Step 4: Return answer
return ans;


মানে: minimized maximum pair sum

Time Complexity Analysis:

Sorting → O(n log n)

Two-pointer sum creation → O(n)

Max finding → O(n)

Total = O(n log n)

Test Case Walkthrough (line by line)

Test case: [3,5,2,3]

Sort nums → [2,3,3,5]

i=0, j=3 → sum = 2+5=7 → v=[7]

i=1, j=2 → sum = 3+3=6 → v=[7,6]

i=2, j=1 → loop stops

findmax(v) → max(7,6) = 7

return 7 ✅

Test case: [3,5,4,2,4,6]

Sort → [2,3,4,4,5,6]

i=0,j=5 → sum=2+6=8 → v=[8]

i=1,j=4 → sum=3+5=8 → v=[8,8]

i=2,j=3 → sum=4+4=8 → v=[8,8,8]

findmax(v) → 8

return 8 ✅

Key Technique Used:

Greedy Approach: Always pair smallest + largest → minimize max pair sum

Two-pointer Technique: Efficient pairing in sorted array

Why it works: Pairing extreme numbers balances the sums → max sum reduced

How to think when reading question:

“Pair elements” → likely greedy / two-pointer

“Minimize the maximum” → pair small + large

Check constraints → even length, unique pairing

Sorted array simplifies pairing → natural hint for two-pointer

💡 Summary in Bangla:

প্রথমে array sort করো

তারপর smallest+largest করে জুটি বানাও

প্রতিটি জুটির sum খুঁজে largest sum বের করো

Largest sum হলো minimized maximum pair sum

Full Code:
--------------\

  class Solution 
{
public:
int findmax(vector<int>& nums)
{
    int max=nums[0];
    for(int k=1;k<nums.size();k++)
    {
        if(nums[k]>max)
        {
            max=nums[k];
        }
    }
    return max;
}
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
       int i=0;
       int j=nums.size()-1;
       vector<int>v;
       while(i<j)
       {
        int sum=nums[i]+nums[j];
        v.push_back(sum);
        i++;
        j--;
       }
    int ans=findmax(v);
    return ans;
    }
};

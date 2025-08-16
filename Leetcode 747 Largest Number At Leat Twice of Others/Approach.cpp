Problem Understanding (প্রশ্ন বোঝা)

Question:

একটি integer array nums দেওয়া আছে।

তোমাকে largest element খুঁজে বের করতে হবে।

Largest element কি array-এর সব অন্য element-এর কমপক্ষে 2 গুণ বড় কিনা তা চেক করতে হবে।

যদি হ্যাঁ → return largest element-এর index।

যদি না → return -1।

Example:

[3,6,1,0] → largest = 6 → সব element-এর সাথে compare করলে 6 >= 2*x → হ্যাঁ, index=1 → return 1

[1,2,3,4] → largest = 4 → 4 >= 2*3 → না → return -1

Solution Approach in Code

Step 1: Find the maximum element

int findmax(vector<int>& arr)
{
    if(arr.empty()) return -1; // empty array check
    int max_val = arr[0]; // প্রথম element ধরে নিলাম max
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > max_val) {
            max_val = arr[i]; // নতুন max found
        }
    }
    return max_val;
}


এখানে findmax function largest element খুঁজে বের করে।

প্রথমে arr[0] কে ধরে নেওয়া হলো max।

তারপর array traverse করে যদি নতুন বড় value পাওয়া যায় → update।

শেষে max_val return।

Bangla explanation:

প্রথম element ধরে largest মান হিসেব করি। পরে array traverse করে সব element check করি, যদি কোন element বড় হয় → সেটাকে largest হিসাবে update করি।

Step 2: Check condition “largest at least twice all others”

bool Test(vector<int>& nums)
{
    int max = findmax(nums);
    bool test = true;
    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] != max && 2 * nums[j] > max)
        {
            test = false;
            break;
        }
    }
    return test;
}


এখানে Test function check করে largest element কি সব element-এর 2 গুণ বড় কিনা।

যদি কোন element-এর 2 গুণ largest-এর চেয়ে বেশি হয় → condition fail → false return।

অন্যথায় true return।

Bangla explanation:

Largest element ছাড়া সব element চেক করি। যদি কোন element থাকে যার 2 গুণ largest থেকে বড় → largest dominant নয়।

Step 3: Main function dominantIndex

int dominantIndex(vector<int>& nums) 
{
    int dominent;
    int ans;
    int max = findmax(nums);
    if(Test(nums)) // যদি largest element সব others-এর কমপক্ষে 2 গুণ বড় হয়
    {
        for(int k = 0; k < nums.size(); k++)
        {
            if(nums[k] == max)
            {
                dominent = max;
                break;
            }
        }
    }
    else
    {
        return -1; // condition fail হলে -1 return
    }

    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] == dominent)
        {
            ans = j;
            break;
        }
    }

    return ans;
}


Step by step explanation:

max = findmax(nums) → largest element বের করা হলো।

Test(nums) → check largest is at least 2x others।

যদি true → proceed

যদি false → return -1

Dominant element-এর মান dominent এ assign করা হলো।

Array traverse করে dominant element-এর index বের করা হলো।

ans return।

Bangla explanation:

প্রথমে largest খুঁজে বের করি। পরে check করি largest সব element-এর 2 গুণ বড় কিনা।
যদি condition satisfy করে → index খুঁজে return করি।
না হলে -1 return করি।

Why It Passes Test Cases

findmax নিশ্চিত largest value খুঁজে পায়।

Test ensures largest at least twice others, তাই problem condition satisfy হয়।

তারপর dominantIndex সঠিক index return করে।

Constraint অনুযায়ী largest element unique, তাই multiple matches নিয়ে সমস্যা নেই।

Example walkthrough:

nums = [3,6,1,0]
max = 6
Test(nums):
    check 3 → 2*3 = 6 → ok
    check 1 → 2*1 = 2 < 6 → ok
    check 0 → 2*0 = 0 < 6 → ok
Test returns true
dominant = 6
find index of 6 → index = 1
return 1


✅ Correct output.

nums = [1,2,3,4]
max = 4
Test(nums):
    check 1 → 2*1=2 < 4 → ok
    check 2 → 2*2=4 == 4 → ok
    check 3 → 2*3=6 > 4 → fail
Test returns false
return -1


✅ Correct output.

Summary in Bangla

Largest element খুঁজে বের করি (findmax)

Largest element সব other elements-এর কমপক্ষে 2 গুণ বড় কিনা চেক করি (Test)

যদি condition satisfy করে → largest element-এর index return করি

যদি না → -1 return করি

Code accepted হওয়ার কারণ: Largest unique, condition সঠিকভাবে check করা হয়েছে, এবং array constraints ছোট (2 ≤ n ≤ 50), তাই time complexity ঠিক আছে।


Full Code:
-----------

  class Solution
 {
public:
int findmax(vector<int>& arr)
 {
    if(arr.empty()) return -1; // empty array check

    int max_val = arr[0]; // প্রথম element ধরে নিলাম max
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > max_val) {
            max_val = arr[i]; // new max found
        }
    }
    return max_val;
}
bool Test(vector<int>&nums)
{
    int max=findmax(nums);
    bool test=true;
    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]!=max&&2*nums[j]>max)
        {
            test=false;
            break;
        }
    }
    return test;
}
    int dominantIndex(vector<int>& nums) 
    {
        int dominent;
         int ans;
         int max=findmax(nums);
        if(Test(nums))
        {
            for(int k=0;k<nums.size();k++)
            {
                    if(nums[k]==max&&2*nums[k]>max)
                    {
                       dominent=max;
                       break;
                    }
            }
        }
        else
        {
            return -1;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==dominent)
            {
                ans=j;
                break;
            }
        }
  
        return ans;
    }
};

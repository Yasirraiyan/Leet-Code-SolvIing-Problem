সমস্যা সংক্ষেপে:

আমাদের একটি array nums এবং একটি target দেওয়া আছে। আমাদের চারটি ভিন্ন index নির্বাচন করতে হবে, যার মান যোগফল target হবে। আমাদের output হলো সমস্ত unique quadruplets।

Solution Technique

এই সমস্যার জন্য সাধারণভাবে যে টেকনিক ব্যবহার করা হয় তা হলো:

Sorting: Array-কে ascending order-এ sort করি যাতে আমরা duplicate avoid করতে পারি এবং two-pointer approach ব্যবহার করতে পারি।

Two-pointer approach: প্রথম দুইটি element loop দিয়ে fix করি, বাকি দুটি element জন্য left এবং right pointer ব্যবহার করি।

Duplicate Avoidance: Quadruplet duplicate এড়াতে adjacent elements skip করি।

Long long type: integer overflow এড়াতে sum calculation-এ long long ব্যবহার করি (কারণ constraints বড়)।

Step by Step Code Explanation
sort(nums.begin(), nums.end());


Array-কে ascending order-এ sort করি।

কারণ: sort করলে আমরা duplicate elements সহজে skip করতে পারি এবং two-pointer logic ব্যবহার করতে পারি।

vector<int>v;
vector<vector<int>>vv;


v হলো temporary container (এখানে optional)

vv হলো আমাদের final result vector যেখানে সব quadruplets থাকবে।

for(int i=0;i<nums.size();i++)
{
    if (i > 0 && nums[i] == nums[i-1]) continue;


প্রথম element fix করি।

Duplicate check: যদি আগের element এর সমান হয় তাহলে skip করি, যাতে duplicate quadruplet না আসে।

    for(int j=i+1;j<nums.size();j++)
    {
        if (j > i + 1 && nums[j] == nums[j-1]) continue;


দ্বিতীয় element fix করি।

আবার duplicate check করি।

        int left=j+1;
        int right=nums.size()-1;


এখন বাকি দুই element খুঁজতে left ও right pointer set করি।

left শুরু হবে j+1 থেকে, right শুরু হবে শেষ থেকে।

        while(left<right)
        {
            long long sum=(long long)nums[left]+nums[right]+nums[i]+nums[j];


Quadruplet sum calculate করি।

Long long ব্যবহার করি কারণ sum integer range ছাড়িয়ে যেতে পারে।

            if(sum==target)
            {
                vv.push_back({nums[i], nums[j], nums[left], nums[right]});
                while(left<right&&nums[left]==nums[left+1]) left++;
                while(left<right&&nums[right]==nums[right-1]) right--;
                left++;
                right--;
            }


যদি sum == target হয়, quadruplet result vector-এ push করি।

Duplicate avoid: left এবং right duplicate skip করি।

left++, right-- করি পরবর্তী নতুন element চেক করার জন্য।

            else if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }


যদি sum < target → left++ (কারণ array sort করা আছে, বড় sum করতে left এগোতে হবে)

যদি sum > target → right-- (ছোট sum করতে right পিছনে সরাতে হবে)

return vv;


সব unique quadruplet return করি।

Test Case Walkthrough
Test Case 1

Input:

nums = [1,0,-1,0,-2,2], target = 0


Sort nums: [-2,-1,0,0,1,2]

i=0 → nums[i]=-2

j=1 → nums[j]=-1

left=2 → nums[left]=0

right=5 → nums[right]=2

sum = -2 + -1 + 0 + 2 = -1 → <0 → left++

left=3 → nums[left]=0 → sum=-2+-1+0+2=-1 → left++

left=4 → nums[left]=1 → sum=-2+-1+1+2=0 → match → add [-2,-1,1,2]

skip duplicates → left=5, right=4 → exit while

j=2 → nums[j]=0

left=3 → nums[left]=0

right=5 → nums[right]=2

sum=-2+0+0+2=0 → match → add [-2,0,0,2]

i=1 → nums[i]=-1

j=2 → nums[j]=0

left=3 → nums[left]=0

right=5 → nums[right]=2

sum=-1+0+0+2=1 → >0 → right--

right=4 → nums[right]=1 → sum=-1+0+0+1=0 → match → add [-1,0,0,1]

Output:

[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Test Case 2

Input:

nums = [2,2,2,2,2], target = 8


Sort nums: [2,2,2,2,2]

i=0 → nums[i]=2

j=1 → nums[j]=2

left=2 → nums[left]=2

right=4 → nums[right]=2

sum=2+2+2+2=8 → match → add [2,2,2,2]

skip duplicates left/right → left=3, right=3 → exit while

Output:

[[2,2,2,2]]

Summary in Bangla

Array sort করি।

প্রথম দুই element fix করি (i, j loop)।

বাকি দুই element খুঁজতে two-pointer technique।

Duplicate avoid করতে left/right এবং i/j skip করি।

Sum calculate করতে long long ব্যবহার করি।

Sum match হলে quadruplet add করি।

Technique:

Sorting + Two-pointer + Duplicate avoidance.


  Example Input
nums = [1,0,-1,0,-2,2], target = 0

Step 1: Sort the array
nums = [-2, -1, 0, 0, 1, 2]

Step 2: Fix first two elements (i and j)
i = 0 → nums[i] = -2
j	nums[j]	left	nums[left]	right	nums[right]	sum	Action
1	-1	2	0	5	2	-2+(-1)+0+2 = -1	< target → left++
1	-1	3	0	5	2	-1	< target → left++
1	-1	4	1	5	2	0	== target → Add quadruplet [-2,-1,1,2], skip duplicates, left++, right--
2	0	3	0	5	2	0	== target → Add quadruplet [-2,0,0,2], skip duplicates, left++, right--
i = 1 → nums[i] = -1
j	nums[j]	left	nums[left]	right	nums[right]	sum	Action
2	0	3	0	5	2	1	> target → right--
2	0	3	0	4	1	0	== target → Add quadruplet [-1,0,0,1], skip duplicates
Step 3: Color-coded pointer visualization
nums: [-2, -1, 0, 0, 1, 2]
         i  j  L        R


i (first element) → red

j (second element) → blue

left (third element) → green

right (fourth element) → yellow

Quadruplet found: [-2,-1,1,2]

Pointer moves:

left++ → move green pointer right
right-- → move yellow pointer left


Next quadruplet: [-2,0,0,2]

i=0 (red), j=2 (blue), left=3 (green), right=5 (yellow)


Next quadruplet: [-1,0,0,1]

i=1 (red), j=2 (blue), left=3 (green), right=4 (yellow)

Step 4: Duplicate avoidance

if(i > 0 && nums[i] == nums[i-1]) continue; → Skip same i

if(j > i+1 && nums[j] == nums[j-1]) continue; → Skip same j

while(left<right && nums[left]==nums[left+1]) left++; → Skip same left

while(left<right && nums[right]==nums[right-1]) right--; → Skip same right

ফলাফল: সব unique quadruplets পাওয়া যায়।

✅ Final Output

[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example Input
nums = [1,0,-1,0,-2,2], target = 0

Step 1: Sort the array
nums = [-2, -1, 0, 0, 1, 2]

Step 2: Pointer Visualization
Index: 0   1   2   3   4   5
Nums: -2  -1   0   0   1   2
       i   j   L           R


Legend:

i → red → প্রথম element

j → blue → দ্বিতীয় element

L → green → left pointer (তৃতীয় element)

R → yellow → right pointer (চতুর্থ element)

Step 3: Pointer Movement & Quadruplet Formation
i = 0, nums[i] = -2

j = 1, nums[j] = -1

L = 2, nums[L] = 0
R = 5, nums[R] = 2
Sum = -2 + -1 + 0 + 2 = -1 < target → move L++

L = 3, nums[L] = 0
R = 5, nums[R] = 2
Sum = -2 + -1 + 0 + 2 = -1 < target → move L++

L = 4, nums[L] = 1
R = 5, nums[R] = 2
Sum = -2 + -1 + 1 + 2 = 0 → match! Add [-2,-1,1,2]
Skip duplicates → L++, R--
L = 5, R = 4 → exit while


j = 2, nums[j] = 0

L = 3, nums[L] = 0
R = 5, nums[R] = 2
Sum = -2 + 0 + 0 + 2 = 0 → match! Add [-2,0,0,2]
Skip duplicates → L++, R--
L = 4, R = 4 → exit while

i = 1, nums[i] = -1

j = 2, nums[j] = 0

L = 3, nums[L] = 0
R = 5, nums[R] = 2
Sum = -1 + 0 + 0 + 2 = 1 > target → move R--

L = 3, nums[L] = 0
R = 4, nums[R] = 1
Sum = -1 + 0 + 0 + 1 = 0 → match! Add [-1,0,0,1]
Skip duplicates → L++, R--
L = 4, R = 3 → exit while

Step 4: Duplicate Avoidance

i loop: skip same nums[i]

j loop: skip same nums[j]

left pointer: skip same nums[L]

right pointer: skip same nums[R]

Step 5: Final Quadruplets
[[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]


✅ Pointer Summary

i, j → fix first 2 elements

left, right → two-pointer scan for remaining 2 elements

Duplicate skip ensures unique quadruplets only

Sorted array + two-pointer → efficient approach

Full Code:
------------

  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>vv;
        for(int i=0;i<nums.size();i++)
        {
              if (i > 0 && nums[i] == nums[i-1]) continue; 
            for(int j=i+1;j<nums.size();j++)
            {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left=j+1;
                int right=nums.size()-1;
                while(left<right)
                {
                   long long sum=(long long)nums[left]+nums[right]+nums[i]+nums[j];
                  
                    if(sum==target)
                    {
                        vv.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                    }
                 else   if(sum<target)
                    {
                        left++;
                    }
                      else
                    {
                       right--;
                    }
                }
            }
           
        }
        return vv;

    }
};

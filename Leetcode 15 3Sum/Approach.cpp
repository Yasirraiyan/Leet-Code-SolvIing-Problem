Problem Summary (Bangla)

আমাদেরকে একটি integer array দেওয়া আছে, nums, এবং আমাদের করতে হবে সব triplets [nums[i], nums[j], nums[k]] বের করা যেখানে:

i != j != k

nums[i] + nums[j] + nums[k] == 0

একই triplet duplicate না হবে।

Example: nums = [-1,0,1,2,-1,-4] → Output: [[-1,-1,2],[-1,0,1]]

Solution Technique

এই সমস্যার জন্য two-pointer technique ব্যবহার করা হয়। Approach:

প্রথমে array sort করা।

একেকটা element nums[i] কে fixed করে ধরি।

বাকি দুটি element খুঁজব low এবং high pointer দিয়ে:

low = i + 1

high = n - 1

তারপর sum = nums[i] + nums[low] + nums[high] দেখি:

যদি sum == 0 → valid triplet

যদি sum < 0 → low++ (কারণ array sorted, বড় মান লাগবে)

যদি sum > 0 → high-- (কারণ ছোট মান লাগবে)

Duplicate skip করার জন্য:

i, low, high এর জন্য duplicate check করা হয়

এই approach O(n^2) time complexity এ কাজ করে, যা n <= 3000 এর জন্য acceptable।

Code Line by Line Explanation
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int> v;                    // এক triplet temporarily রাখার জন্য (এখানে শেষ version এ আর ব্যবহার হয়নি)
        vector<vector<int>> vv;           // সব valid triplets রাখার জন্য
        sort(nums.begin(),nums.end());    // array sort করা, যেন two-pointer technique use করা যায়


sort করা খুব গুরুত্বপূর্ণ কারণ:

Duplicate handling সহজ হয়

Two-pointer logic কাজ করে

        for(int i=0;i<nums.size();i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // duplicate skip


এখানে আমরা i pointer দিয়ে fixed element বাছাই করি।

যদি আগের element এর মতো হয়, তাহলে skip করি, যাতে duplicate triplet না আসে।

            int low = i + 1;                // left pointer
            int high = nums.size() - 1;     // right pointer
            while(low < high)
            {


Two-pointer start:

low → i+1 (পরবর্তী element)

high → last element

                if(nums[i] + nums[low] + nums[high] == 0)
                {
                     vv.push_back({nums[i], nums[low], nums[high]}); // valid triplet push


যদি sum == 0 → আমরা valid triplet পেয়েছি, push করি vv তে

                     while (low < high && nums[low] == nums[low + 1]) low++;   // skip duplicates
                     while (low < high && nums[high] == nums[high - 1]) high--; // skip duplicates
                     low++;   // next possible triplet
                     high--;  // next possible triplet
                }


Duplicate numbers skip করা হচ্ছে, যাতে একই combination আবার না আসে।

তারপর pointer move করি: low++, high--

                else if(nums[i] + nums[low] + nums[high] < 0)
                {
                    low++;      // sum কম → bigger number দরকার → low++ 
                }
                else if(nums[i] + nums[low] + nums[high] > 0)
                {
                    high--;     // sum বেশি → smaller number দরকার → high--
                }
            }
        }
        return vv; // সব valid triplets return
    }
};

Example Test Case (Step by Step)
Input:
nums = [-1,0,1,2,-1,-4]


Step 1: Sort

nums = [-4, -1, -1, 0, 1, 2]


Step 2: i=0, nums[i]=-4

low=1 (-1), high=5 (2)

sum = -4 + (-1) + 2 = -3 < 0 → low++

low=2 (-1) → sum = -4 + (-1) + 2 = -3 → low++

low=3 (0) → sum = -4 + 0 + 2 = -2 → low++

low=4 (1) → sum = -4 + 1 + 2 = -1 → low++

low=5 → stop

Step 3: i=1, nums[i]=-1

low=2 (-1), high=5 (2)

sum = -1 + (-1) + 2 = 0 → push [-1,-1,2]

skip duplicates → low=3, high=4

sum = -1 + 0 + 1 = 0 → push [-1,0,1]

pointers cross → stop

Step 4: i=2, nums[i]=-1

duplicate, skip

Step 5: i=3, nums[i]=0

low=4, high=5 → sum = 0 + 1 + 2 = 3 > 0 → high--

low=4, high=4 → stop

Final output:

vv = [[-1,-1,2], [-1,0,1]]


✅ Matches expected output

Key Points in Bangla

Sort array → two-pointer & duplicate skip সহজ হয়

Fixed element i + two-pointer (low, high)

Duplicate handling: i, low, high

Pointer movement: sum < 0 → low++, sum > 0 → high--

Time Complexity: O(n^2)

Space Complexity: O(1) extra (apart from output)

Full Code:
-----------

  class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int>v;
        vector<vector<int>>vv;
        sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++)
     {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
        int low=i+1;
        int high=nums.size()-1;
        while(low<high)
        {
            if(nums[i]+nums[low]+nums[high]==0)
            {
               /* v.push_back(nums[i]);
                v.push_back(nums[low]);
                v.push_back(nums[high]);
                */
                 vv.push_back({nums[i], nums[low], nums[high]}); 
                  while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
            }
         else   if(nums[i]+nums[low]+nums[high]<0)
            {
                low++;
            }
           else   if(nums[i]+nums[low]+nums[high]>0)
            {
               high--;
            }
        }
       // vv.push_back(v);
     }
     return vv;
    }
};

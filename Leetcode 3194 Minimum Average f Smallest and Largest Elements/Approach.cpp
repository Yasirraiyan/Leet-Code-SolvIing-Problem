প্রশ্ন বোঝার লজিক:

আমাদের কাছে একটি nums array আছে, যার দৈর্ঘ্য even।

কাজ করতে হবে এমনভাবে:

প্রতিবার smallest element এবং largest element বের করতে হবে।

এদের গড় (average) বের করতে হবে (min + max) / 2 এবং একটি নতুন array averages-এ যোগ করতে হবে।

সব শেষে averages থেকে smallest value বের করতে হবে।

প্রশ্ন থেকেই বোঝা যায় যে:

প্রথমে ছোটো এবং বড়ো মান বের করতে হবে → তাই array sort করা logical।

তারপর ধারাবাহিকভাবে smallest + largest বের করতে হবে → তাই two-pointer technique ব্যবহার করা সুবিধাজনক।

শেষে averages array থেকে min value বের করতে হবে → সোজা linear search করে min বের করা যায়।

কোডের লজিক ও লাইনে লাইনে ব্যাখ্যা
class Solution
{
public:
    double findmin(vector<double>&arr)
    {
        double min=arr[0];
        for(int j=1;j<arr.size();j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
            }
        }
        return min;
    }


এখানে একটি ছোট ফাংশন findmin বানানো হয়েছে।

এটি linear scan করে arr এর smallest element খুঁজে বের করে।

এটি averages array থেকে minimum return করবে।

    double minimumAverage(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());


প্রথমে array nums sort করা হচ্ছে।

sorted array থেকে left-most = smallest, right-most = largest পাওয়া সহজ।

        int low=0;
        int high=nums.size()-1;
        vector<double>v;


দুইটি pointer রাখা হয়েছে:

low → smallest element দেখবে।

high → largest element দেখবে।

v → averages সংরক্ষণের জন্য।

        while(low<high&&!nums.empty())
        {
            double avg=(nums[low]+nums[high])/2.0;
            v.push_back(avg);
            low++;
            high--;
            if(nums.empty()) break;
        }


while loop চালানো হয়েছে যতক্ষণ low < high থাকে।

প্রতিবার:

nums[low] এবং nums[high] এর average বের করা হচ্ছে।

v.push_back(avg) দিয়ে averages array-এ যোগ করা হচ্ছে।

তারপর pointer update করা হচ্ছে: low++, high--

এখানে nums.empty() চেক technically প্রয়োজন নেই কারণ আমরা pointer ব্যবহার করেছি।

        double ans=findmin(v);
        return ans;
    }
};


শেষে v (averages) থেকে smallest element বের করতে findmin ব্যবহার করা হয়েছে।

এটিই final answer।

টেকনিক/প্রক্রিয়া:

Sorting: smallest ও largest সহজে খুঁজে বের করতে।

Two-pointer approach: low থেকে smallest, high থেকে largest নিয়ে ধারাবাহিকভাবে average বের করা।

Linear search for min: averages array থেকে minimum বের করা।

কেন accepted হলো?

Sorting + two-pointer সব case এ correct small & large pairing দেয়।

n/2 বার loop চলে → সব elements use হয়।

Average ঠিকমতো বের হচ্ছে → floating-point division ব্যবহার করা হয়েছে (nums[low]+nums[high])/2.0।

findmin সব averages এর মধ্যে সঠিক smallest return করছে।

টেকনিক সংক্ষেপে বাংলায়:

Problem type: Pair smallest & largest → get min of averages

Technique:

Sort + Two pointers → efficiently pick min & max

Store averages → vector

Linear search min → final result

Key insight: Sorting করে two-pointer ব্যবহার করলে O(n log n) + O(n) time complexity এ solve করা যায়।

Input:
nums = [7,8,3,4,15,13,4,1]

Step 1: sort(nums.begin(), nums.end())

Sorted nums:

nums = [1,3,4,4,7,8,13,15]


ছোট মানটি এখন left-most, বড় মানটি right-most।

Step 2: initialize pointers
int low=0;
int high=nums.size()-1; // high=7
vector<double>v;


low → 0 → points to 1 (smallest)

high → 7 → points to 15 (largest)

v → empty, averages রাখবে

Step 3: while(low<high && !nums.empty())

Condition: low < high → 0 < 7 ✅

nums.empty() → false ✅

Iteration 1:
double avg = (nums[low] + nums[high])/2.0;


avg = (1 + 15)/2.0 = 16/2 = 8.0

v.push_back(avg); // v = [8.0]
low++;  // low = 1 → points to 3
high--; // high = 6 → points to 13


nums array একই থাকে, কারণ erase করা হয়নি।

Iteration 2:

low=1 → 3, high=6 → 13

avg = (3 + 13)/2.0 = 16/2 = 8.0

v.push_back(avg) → v = [8.0, 8.0]

low++, high-- → low=2 → 4, high=5 → 8

Iteration 3:

low=2 → 4, high=5 → 8

avg = (4 + 8)/2.0 = 12/2 = 6.0

v.push_back(avg) → v = [8.0, 8.0, 6.0]

low++, high-- → low=3 → 4, high=4 → 7

এখন low == high → loop শেষ

Iteration 4:

low=3 → 4, high=4 → 7

Condition low<high → 3<4 ✅

avg = (4 + 7)/2.0 = 11/2 = 5.5

v.push_back(avg) → v = [8.0, 8.0, 6.0, 5.5]

low++, high-- → low=4, high=3 → loop ends

Step 4: find minimum of averages
double ans = findmin(v);


v = [8.0, 8.0, 6.0, 5.5]

findmin scans array:

min = 8.0 → compare 8.0 → no change

compare 6.0 → min=6.0

compare 5.5 → min=5.5 ✅

Step 5: return ans
return ans; // 5.5

✅ Output matches Example 1: 5.5
Technique used:

Sorting: ছোট এবং বড় মান সহজে বের করার জন্য।

Two-pointer: low → smallest, high → largest, প্রতিবার average বের করতে।

Vector + min search: averages রাখা এবং minimum বের করা।

Example 2 এবং 3

প্রকৃতপক্ষে same approach, শুধু numbers change হয়:

Example 2: nums = [1,9,8,3,10,5] → sort → [1,3,5,8,9,10] → averages = [5.5,6,6.5] → min=5.5

Example 3: nums = [1,2,3,7,8,9] → sort → [1,2,3,7,8,9] → averages = [5,5,5] → min=5.0

সবকেসে logic এক।


  Full Code:
--------------

  class Solution
 {
public:
double findmin(vector<double>&arr)
{
    double min=arr[0];
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]<min)
        {
            min=arr[j];
        }
    }
    return min;
}
    double minimumAverage(vector<int>& nums)
     {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        vector<double>v;
        while(low<high&&!nums.empty())
        {
            //nums.erase(nums.begin()+low);
            // nums.erase(nums.begin()+high);
             double avg=(nums[low]+nums[high])/2.0;
             v.push_back(avg);
             low++;
             high--;
             if(nums.empty()) break;
        }
        double ans=findmin(v);
        return ans;
    }
};

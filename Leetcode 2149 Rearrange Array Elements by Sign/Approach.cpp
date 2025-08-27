প্রশ্ন বুঝে নেওয়া

আমাদের কাছে একটি nums array আছে যা সমসংখ্যক ধনাত্মক ও ঋণাত্মক সংখ্যা নিয়ে গঠিত।
শর্তগুলো:

প্রতিটি consecutive pair এর সংখ্যা হবে বিপরীত চিহ্নের।
অর্থাৎ যদি একটি ধনাত্মক → তারপর ঋণাত্মক, আবার ঋণাত্মক → ধনাত্মক।

একই চিহ্নের সংখ্যাগুলোর order original array অনুযায়ী থাকবে।

array টি ধনাত্মক দিয়ে শুরু হবে।

উদাহরণ:

nums = [3,1,-2,-5,2,-4]
positive = [3,1,2]
negative = [-2,-5,-4]
rearranged = [3,-2,1,-5,2,-4]  ✅

Solution Approach (কেন এই কোড লেখা হলো)

ধাপ ১: দুইটি pointer ব্যবহার করা

int i = 0; // ধনাত্মক সংখ্যা রাখার index
int j = 1; // ঋণাত্মক সংখ্যা রাখার index


আমরা জানি array ধনাত্মক দিয়ে শুরু হবে, তাই i = 0।

এবং ঋণাত্মক সংখ্যা সবসময় positive number এর পর থাকবে, তাই j = 1।

ধাপ ২: নতুন array তৈরি করা

vector<int> v(nums.size(), 0);


নতুন array v তৈরি করেছি যাতে আমরা sequentially ধনাত্মক ও ঋণাত্মক সংখ্যাগুলো রাখি।

সব element প্রাথমিকভাবে 0 দিয়ে initialize করা হয়েছে।

ধাপ ৩: original array traverse করা

for(int k = 0; k < nums.size(); k++)
{
    if(nums[k] > 0) // ধনাত্মক হলে
    {
        v[i] = nums[k]; // i index এ রাখি
        i += 2;         // পরবর্তী ধনাত্মক রাখার index 2 step পরে
    }
    if(nums[k] < 0) // ঋণাত্মক হলে
    {
        v[j] = nums[k]; // j index এ রাখি
        j += 2;         // পরবর্তী ঋণাত্মক রাখার index 2 step পরে
    }
}


লজিক:

ধনাত্মক সংখ্যা সবসময় even index এ রাখি: 0, 2, 4,...

ঋণাত্মক সংখ্যা সবসময় odd index এ রাখি: 1, 3, 5,...

এভাবে automatically consecutive pair opposite sign হবে।

এবং যেহেতু আমরা array traverse করি original order অনুযায়ী, তাই same sign সংখ্যাগুলো original order মেইন্টেইন হবে।

কেন এই কোড accepted হলো

সব ধনাত্মক সংখ্যা even index এ থাকবে।

সব ঋণাত্মক সংখ্যা odd index এ থাকবে।

ধনাত্মক এবং ঋণাত্মক সংখ্যা সমান হওয়ার কারণে সব index perfectly filled হবে।

Original order বজায় থাকে → condition 2 পূরণ।

Consecutive pair opposite sign → condition 1 পূরণ।

ধনাত্মক দিয়ে শুরু → condition 3 পূরণ।

Time Complexity: O(n) (array একবার traverse)
Space Complexity: O(n) (নতুন array v তৈরি)

Test Case দিয়ে যাচাই

Test Case 1:

nums = [3,1,-2,-5,2,-4]


positive = [3,1,2] → index 0,2,4

negative = [-2,-5,-4] → index 1,3,5

Result: [3,-2,1,-5,2,-4] ✅

Test Case 2:

nums = [-1,1]


positive = [1] → index 0

negative = [-1] → index 1

Result: [1,-1] ✅

Test Case 3:

nums = [5,-3,2,-4,1,-2]


positive = [5,2,1] → index 0,2,4

negative = [-3,-4,-2] → index 1,3,5

Result: [5,-3,2,-4,1,-2] ✅

সব ক্ষেত্রে code ঠিক কাজ করে।

Technique

Two-pointer technique বা alternate index filling।

Positive ও Negative দুইটি group separately maintain করে, তারপর alternate index এ insert।

Competitive programming এ এটি reordering problems with constraints এর জন্য commonly used।

কীভাবে তুমি এই approach ভাবতে পারো

প্রশ্নে বলা আছে “positive দিয়ে শুরু + opposite sign consecutive” → মনে করো even-odd index pattern।

Original order বজায় রাখতে হবে → traverse original array।

Alternating positions → i=0, j=1 → positive, negative।

Iterate & place → DONE ✅

Full Code:
-----------

  class Solution
 {
public:
    vector<int> rearrangeArray(vector<int>& nums)
     {
       int i=0;
       int j=1;
       vector<int>v(nums.size(),0);
       for(int k=0;k<nums.size();k++)
       {
        if(nums[k]>0)
        {
            v[i]=nums[k];
            i+=2;
        }
        if(nums[k]<0)
        {
            if(j<nums.size())
            {
            v[j]=nums[k];
            j+=2;
            }
        }
        
       }
      
       return v;

     }
};

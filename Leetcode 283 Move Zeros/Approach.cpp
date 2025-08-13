Problem বোঝা
প্রশ্ন বলছে:

তোমাকে একটা integer array nums দেওয়া আছে।

Array-তে যতগুলো 0 আছে, সেগুলো end এ পাঠাতে হবে।

বাকি non-zero elements-এর relative order ঠিক রাখতে হবে (মানে যেভাবে তারা আগে ছিল, সেই ক্রমে থাকতে হবে)।

কাজটা in-place করতে হবে (মানে নতুন array বানানো যাবে না, পুরোটাই ওই nums এর ভেতরে করতে হবে)।

প্রথমে problem observe করলে মাথায় যা আসবে
Relative order রাখতে হবে → Sorting করলে হবে না, কারণ order বদলে যাবে।

0-গুলো শেষে যাবে → মানে প্রথমে non-zero গুলো একসাথে আনতে হবে।

In-place → অতিরিক্ত array ব্যবহার করা যাবে না, তাই index shifting করব।

ভাবনার ধাপ
Array টা একবার traverse করব।

একটা pointer (nonzeroindex) রাখব, যেটা বলে দেবে non-zero element পরবর্তী কোন position-এ বসাতে হবে।

Traverse করার সময় যখন non-zero element পাব, তখন ওই position-এ বসিয়ে pointer বাড়িয়ে দেব।

শেষে যত জায়গা ফাঁকা আছে, সব জায়গায় 0 বসিয়ে দেব।

Solution Flow
nonzeroindex = 0 (প্রথম position যেখানে non-zero বসবে)।

Loop i = 0 থেকে n-1 পর্যন্ত:

যদি nums[i] != 0 হয় →

nums[nonzeroindex] = nums[i] বসাও।

nonzeroindex++ করো।

Loop শেষ হলে nonzeroindex থেকে শেষ পর্যন্ত সব জায়গায় 0 বসিয়ে দাও।

কোড ব্যাখ্যা (Line-by-Line)
cpp
Copy
Edit
class Solution 
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int nonzeroindex = 0; // প্রথম non-zero বসানোর index
        int zeroindex = nums.size() - 1; // এখানে দরকার নেই, শুধু লেখা আছে কিন্তু ব্যবহার হয়নি
        
        // Step 1: Non-zero গুলো সামনে নিয়ে আসা
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) // যদি non-zero হয়
            {
                nums[nonzeroindex] = nums[i]; // ওই position-এ বসাও
                nonzeroindex++; // পরের position এ যাও
            }
        }

        // Step 2: বাকি সব জায়গায় 0 বসানো
        for (int j = nonzeroindex; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }
};
Test Case Execution
উদাহরণ: nums = [0,1,0,3,12]
শুরুর অবস্থা:

ini
Copy
Edit
nums = [0,1,0,3,12]
nonzeroindex = 0
First Loop: (non-zero গুলো সামনে আনছে)

i=0 → nums[0]=0 → কিছু করব না।

i=1 → nums[1]=1 → nums[0] = 1, nonzeroindex=1
→ nums এখন [1,1,0,3,12]

i=2 → nums[2]=0 → কিছু করব না।

i=3 → nums[3]=3 → nums[1] = 3, nonzeroindex=2
→ nums এখন [1,3,0,3,12]

i=4 → nums[4]=12 → nums[2] = 12, nonzeroindex=3
→ nums এখন [1,3,12,3,12]

Second Loop: (nonzeroindex=3, এখন থেকে শেষ পর্যন্ত 0 বসানো)

j=3 → nums[3]=0 → nums=[1,3,12,0,12]

j=4 → nums[4]=0 → nums=[1,3,12,0,0]

Final Output:

csharp
Copy
Edit
[1,3,12,0,0]
কেন কোড Accepted হলো
Time Complexity: O(n) → কারণ আমরা দুইটা loop চালিয়েছি, কিন্তু প্রতিটা element সর্বোচ্চ ২ বার process হয়েছে।

Space Complexity: O(1) → in-place modification, extra array নেই।

Order preserved: কারণ আমরা শুধু non-zero গুলো একই ক্রমে সামনে এনেছি, 0 গুলো পরে দিয়েছি।

Constraints-এর মধ্যে efficient solution।

যেভাবে এই approach মাথায় আনা যায়
Relative order রাখতে হবে শুনে বুঝব → Sorting নয়, Shift করব।

Shift করার সময় একটা pointer লাগবে যেটা দেখাবে কোথায় non-zero বসাতে হবে।

প্রথমে non-zero সামনে আনি, পরে বাকি অংশে 0 বসাই।

এটা একটা classic two-pointer technique এর simplified form।

Full Code:
-----------

class Solution 
{
public:
    void moveZeroes(vector<int>& nums)
     {
        int nonzeroindex=0;
        int zeroindex=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[nonzeroindex]=nums[i];
                nonzeroindex++;
            }
            
            
        }
        for(int j=nonzeroindex;j<nums.size();j++)
        {
            nums[j]=0;
        }
    }
};
  

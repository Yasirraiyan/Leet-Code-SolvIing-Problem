✅ Problem বোঝার চেষ্টা:

তোমাকে এমন একটি সংখ্যার খোঁজ করতে বলা হয়েছে যেটি k-তম বড় সংখ্যা।

📌 Example 1:
nums = [3,2,1,5,6,4], k = 2
→ Sorted form: [1,2,3,4,5,6] → 2nd largest = 5 ✅

📌 Example 2:
nums = [3,2,3,1,2,4,5,5,6], k = 4
→ Sorted: [1,2,2,3,3,4,5,5,6] → 4th largest = 4 ✅


---

🧠 কিভাবে চিন্তা করবো?

তোমার চিন্তা করা উচিত:

1. "k-th largest" মানে হচ্ছে পেছন থেকে k-তম উপাদান।


2. অর্থাৎ nums যদি বড় থেকে ছোট ক্রমে সাজানো থাকে, তাহলে k-1 index-এ যেই সংখ্যা আছে, সেটিই হবে উত্তর।



✅ তাহলে তুমি যদি nums কে বড় থেকে ছোটে সাজাও (descending), তাহলে সরাসরি nums[k-1] রিটার্ন করলেই হবে।

কিন্তু তোমার কোডে তুমি ascending order এ sort করেছো, তাই তুমি শেষে থেকে শুরু করে k-তম উপাদান বের করেছো।


---

✅ কোড বিশ্লেষণ (তোমার দেওয়া):

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int count=0;
        sort(nums.begin(),nums.end()); // Step 1: nums sort করা হচ্ছে (ascending)
        int ans;
        for(int j=nums.size()-1;j>=0;j--) // Step 2: শেষ থেকে (largest থেকে) শুরু করছি
        {
            count++; // Step 3: কত তম largest দেখতে চাই তা count করছি
            if(count==k) // Step 4: যদি এটা আমাদের k-th হয়
            {
                ans=nums[j]; // তাহলে এটা আমাদের উত্তর
                break;
            }
        }
        return ans;
    }
};


---

✅ ধাপে ধাপে ব্যাখ্যা (Line by Line):

sort(nums.begin(), nums.end());

🔸 nums array টা ascending order এ সাজানো হচ্ছে।
Example: [3,2,1,5,6,4] → [1,2,3,4,5,6]


---

for(int j = nums.size() - 1; j >= 0; j--)

🔸 এখন আমরা শেষ index (সবচেয়ে বড় সংখ্যা) থেকে k-তম index পর্যন্ত count করবো।


---

count++;
    if(count == k) {
        ans = nums[j];
        break;
    }

🔸 যতবার আমরা একেকটা সংখ্যা দেখি, count++ করে যাচ্ছি।
🔸 যদি count == k হয়, এর মানে k-তম largest পেয়ে গেছি। তখন সেটাকে ans এ রেখে return করবো।


---

✅ Math ব্যাখ্যা (Bangla):

ধরা যাক:

তুমি nums = [3,2,1,5,6,4] দিলে,

আর k = 2


তাহলে ascending sort করলে nums = [1,2,3,4,5,6]
এখন পেছন থেকে k-তম মানে হচ্ছে index n-k = 6-2 = 4
মানে nums[4] = 5
→ এটা ঠিক আছে।

তুমি loop চালিয়ে পেছন থেকে count করে সেই জায়গায় গিয়েই return করেছো।
তাই তোমার কোড কাজ করছে এবং Accepted।


---

✅ কেন এটা Accepted:

Time Complexity: O(n log n) (কারণ sort করার জন্য)

Space Complexity: O(1) (in-place sort করা হচ্ছে)


যেহেতু n <= 10^5, এবং sort এর সময়সীমা acceptable, তাই তোমার solution Accepted হয়েছে

  Full Code:
----------------

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
{
       
        int count=0;
        sort(nums.begin(),nums.end());
        int ans;
        for(int j=nums.size()-1;j>=0;j--)
            {
               
                count++;
                if(count==k)
                {
                    ans=nums[j];
                    break;
                }
            }
        return ans;
    }
};

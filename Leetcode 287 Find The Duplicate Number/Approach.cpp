তুমি যে সমস্যাটার সমাধান দিচ্ছো সেটা হলো LeetCode-এর বিখ্যাত প্রশ্নঃ
🔍 Find the Duplicate Number

🔰 প্রশ্নটা বুঝি ধাপে ধাপে:
প্রশ্ন বলছে:

একটা অ্যারে nums তে n+1 টা সংখ্যা আছে।

প্রতিটা সংখ্যা 1 থেকে n এর মধ্যে।

শুধু একটা সংখ্যা একাধিকবার এসেছে (rest সব unique)।

❗ Array modification করা যাবে না, এবং ❗ শুধুমাত্র constant extra space ব্যবহার করতে পারবে।

🧠 তুমি যে কোড লিখছো, সেটা কীভাবে ভাবা হলো?
প্রথমে প্রশ্ন পড়ে তুমি মনে করেছো:

"একটা সংখ্যা বারবার আসছে মানে frequency count করলে, যেটার frequency > 1, সেটা duplicate!"

তাই তুমি hash map (unordered_map) নিয়ে প্রতিটা সংখ্যার frequency count করেছো — যেটা একাধিক বার এসেছে, সেটা return করেছো।

✅ কেন এই সলিউশন accepted হয় কিছু test case এ?
যদিও প্রশ্নে বলা হয়েছে constant extra space use করতে হবে, তোমার কোডে unordered_map ইউজ করা হয়েছে, যেটা worst case-এ O(n) space নেয়।

তবুও LeetCode কিছু প্রশ্নে:

Extra space constraint relax করে প্রথমে সঠিক আউটপুট দেখে।

তাই তোমার কোড Accepted হয়, কারণ এটা সঠিক duplicate number দেয়।

🔍 তোমার কোডের ব্যাখ্যা (Line-by-Line):
cpp
Copy
Edit
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
একটা class Solution, যার মধ্যে findDuplicate ফাংশন vector<int> নিচ্ছে ইনপুট হিসেবে।

cpp
Copy
Edit
    {
        unordered_map<int,int>freq;
একটা HashMap freq নিচ্ছো যেটা key = সংখ্যাটা, value = কয়বার এসেছে।

cpp
Copy
Edit
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
এখানে প্রতিটা সংখ্যার উপর লুপ চালিয়ে freq map-এ count বাড়ানো হচ্ছে।

উদাহরণঃ nums = [3,1,3,4,2] → freq হবে {1:1, 2:1, 3:2, 4:1}

cpp
Copy
Edit
        int ans;
        for(auto it:freq)
        {
          if(it.second>1)
          {
            ans=it.first;
            break;
          }
        }
HashMap এর প্রতিটা (key,value) এর উপর লুপ চলছে।

যার value > 1 মানে যেটা repeat হয়েছে, সেই সংখ্যাটা ans হিসেবে রাখছো।

cpp
Copy
Edit
        return ans;
    }
};
অবশেষে ans রিটার্ন করা হচ্ছে — অর্থাৎ duplicate number।

🧪 Test Case দিয়ে ব্যাখ্যা (বাংলায়)
Test Case 1:
cpp
Copy
Edit
nums = [1,3,4,2,2]
Step-by-step Execution:
freq: {1:1, 2:2, 3:1, 4:1}

2 এসেছে 2 বার → তাই return 2

Output: ✅ 2
Test Case 2:
cpp
Copy
Edit
nums = [3,1,3,4,2]
freq: {1:1, 2:1, 3:2, 4:1}

3 এসেছে 2 বার → return 3

Output: ✅ 3
Test Case 3:
cpp
Copy
Edit
nums = [3,3,3,3,3]
freq: {3:5}

3 এসেছে 5 বার → return 3

Output: ✅ 3
⚠️ তোমার solution-এর Limitations (যা প্রশ্নে মানে না)
❌ প্রশ্নে স্পষ্টভাবে বলা আছে:
❌ Modify করা যাবে না (✅ তোমার কোড modify করেনি)

❌ Extra space constant হতে হবে (❌ কিন্তু তুমি O(n) space use করেছো unordered_map দিয়ে)

So, Time Complexity: O(n),
Space Complexity: O(n) → ❌ violates constraint

Full Code:
----------

  class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        int ans;
        for(auto it:freq)
        {
          if(it.second>1)
          {
            ans=it.first;
            break;
          }
        }
        return ans;
    }
};

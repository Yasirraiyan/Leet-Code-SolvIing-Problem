তুমি যে প্রশ্নটা বলেছো, সেটার মূল বিষয় হচ্ছে:
দুইটি ভিন্ন অ্যারে (nums1 ও nums2) দেওয়া আছে।
তোমাকে বের করতে হবে:

answer1 – কতগুলো index i আছে এমন, যাদের nums1[i] মান nums2 তে আছে।

answer2 – কতগুলো index i আছে এমন, যাদের nums2[i] মান nums1 তে আছে।

উদাহরণ:
text
Copy
Edit
Input: nums1 = [2,3,2], nums2 = [1,2]
Output: [2,1]
👉 nums1 এর index 0 এবং 2 তে 2 আছে যা nums2-তে আছে → count = 2
👉 nums2 এর index 1 তে 2 আছে যা nums1-এ আছে → count = 1
→ Final উত্তর: [2,1]

✅ Step-by-step Thinking & Approach (Bangla)
প্রথমে প্রশ্নটা পড়েই ভাবো:

“আমার nums1[i] এর প্রতিটা element কি nums2 এর মধ্যে আছে?”

আর ঠিক একইভাবে nums2[i] এর প্রতিটা element কি nums1 এর মধ্যে আছে?

তুমি যদি প্রতিটা সংখ্যা বারবার খুঁজতে যাও O(n * m) হবে, যেটা সময় নষ্ট করে।
তাই আমরা unordered_set ব্যবহার করবো – কারণ এতে খোঁজার সময় O(1)।

unordered_set এর কাজ:

এটা একটা HashSet টাইপ ডেটা স্ট্রাকচার। একটা ভ্যালু আছে কিনা সেটা খুব দ্রুত চেক করা যায়।

Approach:

প্রথমে nums1 আর nums2 এর সব ভ্যালু দিয়ে দুইটা unordered_set বানাও: set1 এবং set2

তারপর nums1 এর প্রতিটা element চেক করো set2 তে আছে কিনা – যদি থাকে, count2 বাড়াও।

আবার nums2 এর প্রতিটা element চেক করো set1 তে আছে কিনা – যদি থাকে, count1 বাড়াও।

🔍 Code Explanation (Bangla line by line)
cpp
Copy
Edit
class Solution 
{
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1;
        unordered_set<int> set2;
🔹 set1 হচ্ছে nums1 এর unique values রাখবে
🔹 set2 হচ্ছে nums2 এর unique values রাখবে

cpp
Copy
Edit
        int count1=0;
        int count2=0;
🔹 count1 = কতগুলো index nums2-এর মধ্যে আছে যা nums1-এ ছিল
🔹 count2 = কতগুলো index nums1-এর মধ্যে আছে যা nums2-এ ছিল

cpp
Copy
Edit
        for(int i=0;i<nums1.size();i++)
        {
            set1.insert(nums1[i]);
        }
🔹 nums1 এর সব element set1 এ রাখছি যাতে পরে খোঁজ করা সহজ হয়

cpp
Copy
Edit
        for(int j=0;j<nums2.size();j++)
        {
            set2.insert(nums2[j]);
        }
🔹 একইভাবে nums2 এর সব ভ্যালু set2 তে রাখছি

cpp
Copy
Edit
        vector<int> ans;
🔹 শেষে return করার জন্য একটা vector বানালাম

🔽 এখন শুরু করবো গণনা:

cpp
Copy
Edit
        for(int k=0;k<nums1.size();k++)
        {
            if(set2.find(nums1[k])!=set2.end())
            {
                count2++;
            }
        }
🔹 nums1[k] এর মান set2 তে থাকলে, তার মানে nums1[k] → nums2 তে আছে
🔹 তাই count2++

cpp
Copy
Edit
        for(int i=0;i<nums2.size();i++)
        {
            if(set1.find(nums2[i])!=set1.end())
            {
                count1++;
            }
        }
🔹 ঠিক একইভাবে, nums2[i] এর মান যদি set1 তে থাকে → nums2[i] → nums1 তে আছে
🔹 তাই count1++

cpp
Copy
Edit
        ans.push_back(count2);
        ans.push_back(count1);
        return ans;
    }
};
🔹 শেষমেশ count2 আর count1 কে return করলাম → answer1, answer2 হিসেবে

✅ Test with Example:
Input:
cpp
Copy
Edit
nums1 = [4,3,2,3,1]
nums2 = [2,2,5,2,3,6]
Execution:
set1 = {1, 2, 3, 4}

set2 = {2, 3, 5, 6}

✔️ nums1 → index 1 (3), 2 (2), 3 (3) → all in set2 → count2 = 3
✔️ nums2 → index 0 (2), 1 (2), 3 (2), 4 (3) → in set1 → count1 = 4

→ Final Output: [3, 4]

🔚 Complexity:
Time: O(n + m) → একবার করে সব loop (nums1 + nums2)

Space: O(n + m) → দুইটা set এর জন্য

FUll Code:
----------

  class Solution 
{
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int>set1;
        unordered_set<int>set2;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums1.size();i++)
        {
          set1.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++)
        {
          set2.insert(nums2[j]);
        }
        vector<int>ans;
        for(int k=0;k<nums1.size();k++)
        {
          if(set2.find(nums1[k])!=set2.end())
          {
            count2++;
          }
        }
        for(int i=0;i<nums2.size();i++)
        {
          if(set1.find(nums2[i])!=set1.end())
          {
            count1++;
          }
        }
        ans.push_back(count2);
        ans.push_back(count1);
        return ans;
        

        
    }
};

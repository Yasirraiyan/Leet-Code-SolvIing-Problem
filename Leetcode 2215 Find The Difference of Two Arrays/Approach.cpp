✅ 1. প্রশ্ন বুঝে নাও:

দুটি অ্যারে আছে।

প্রতিটিতে repeated values থাকতে পারে, কিন্তু আমাদের unique value নিয়েই কাজ করতে হবে।

আমাদের এমন value খুঁজে বের করতে হবে যা:

nums1 এ আছে কিন্তু nums2 তে নেই (➡️ answer[0])

nums2 এ আছে কিন্তু nums1 তে নেই (➡️ answer[1])




---

✅ 2. Efficient চিন্তা:

যদি প্রতিটা এলিমেন্টের membership চেক করতে চাই তবে টাইম কম রাখতে unordered_set ইউজ করা বেস্ট।

কারণ unordered_set-এ কোনো ভ্যালু একবারই থাকে এবং .find() O(1) টাইমে চেক করতে পারে।


✅ 4. অপ্টিমাইজড কোডটা কীভাবে কাজ করে, লাইন বাই লাইন ব্যাখ্যা:

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
{
    vector<vector<int>> ans(2);

➡️ আমরা answer নামে 2D ভেক্টর নিয়েছি, যাতে ans[0] এবং ans[1] থাকবে।

unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

➡️ nums1 এবং nums2 এর distinct (একক) ভ্যালুগুলো নিয়ে দুইটা set তৈরি করেছি।
➡️ এতে করে আমরা খুব দ্রুত চেক করতে পারবো যে কোনো ভ্যালু অন্য array-তে আছে কি না।


---

for(int num : set1) {
        if(set2.find(num) == set2.end()) {
            ans[0].push_back(num);
        }
    }

➡️ set1 এর প্রতিটা ইউনিক এলিমেন্টে যাচ্ছি।
➡️ যদি সেটা set2 তে না থাকে ➡️ মানে nums2 তে নেই ➡️ তাহলে answer[0] তে রেখে দিচ্ছি।


---

for(int num : set2) {
        if(set1.find(num) == set1.end()) {
            ans[1].push_back(num);
        }
    }

➡️ এবার set2 এর প্রতিটা ইউনিক এলিমেন্ট চেক করলাম।
➡️ যদি সেটা set1 তে না থাকে ➡️ মানে nums1 এ নেই ➡️ তাহলে answer[1] তে রেখে দিচ্ছি।


---

return ans;
}

➡️ অবশেষে 2D ভেক্টর answer রিটার্ন করলাম।


---

✅ Final Optimized Code:

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                ans[0].push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};


---

🧪 উদাহরণ টেস্ট কেস দিয়ে যাচাই:

Example 1:

nums1 = [1,2,3], nums2 = [2,4,6]
set1 = {1,2,3}, set2 = {2,4,6}
ans[0]: 1,3 (nums1 তে আছে, nums2 তে নাই)
ans[1]: 4,6 (nums2 তে আছে, nums1 তে নাই)
✅ Output: [[1,3],[4,6]]

Example 2:

nums1 = [1,2,3,3], nums2 = [1,1,2,2]
set1 = {1,2,3}, set2 = {1,2}
ans[0]: 3 (nums1 তে আছে, nums2 তে নাই)
ans[1]: [] (সব nums2 এর ভ্যালু nums1 এ আছে)
✅ Output: [[3],[]]


---

  Full Code:
--------------


class Solution
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>>ans(2);
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++)
            {
                set1.insert(nums1[i]);
            }
        for(int j=0;j<nums2.size();j++)
            {
                set2.insert(nums2[j]);
            }
        for(int k=0;k<nums1.size();k++)
            {
                if(set2.find(nums1[k])==set2.end())
                {
                if (find(ans[0].begin(), ans[0].end(), nums1[k]) == ans[0].end())
                {
                    ans[0].push_back(nums1[k]);
                }
                }
    
            }
        for(int j=0;j<nums2.size();j++)
            {
                if(set1.find(nums2[j])==set1.end())
                {
                    if (find(ans[1].begin(), ans[1].end(), nums2[j]) == ans[1].end()) {
                    ans[1].push_back(nums2[j]);
                    }
            }

            }
        
        return ans;
        
    }
};

🔍 Step-by-step Thinking Approach (Bangla)
✅ Step 1: প্রশ্ন থেকে কি বুঝলাম?
arr হচ্ছে strictly increasing positive সংখ্যা নিয়ে গঠিত একটা অ্যারে।

কিছু সংখ্যা মিসিং — যেগুলো arr-এ নেই, কিন্তু 1 থেকে শুরু করে পরপর থাকা উচিত ছিল।

আমাদের k-তম মিসিং পজিটিভ ইন্টিজারটা বের করতে হবে।

📌 যেমনঃ
arr = [2,3,4,7,11], k = 5
Missing numbers: [1,5,6,8,9,...] → 5th one is 9.

🧠 কিভাবে চিন্তা করবো?
প্রথমেই একটা গুরুত্বপূর্ণ প্রশ্ন করো:

❓ "আমি যদি 1 থেকে শুরু করে প্রতিটা পজিটিভ নাম্বার চেক করি, তাহলে কি আমি মিসিং সংখ্যা গুলো খুঁজে পেতে পারি?"

হ্যাঁ, পারি।
তুমি 1 থেকে শুরু করে চেক করতে পারো arr এর মধ্যে সেই নাম্বার আছে কি না।

✅ Algorithm (Bangla)
arr কে একটি unordered_set-এ রাখো, যাতে O(1)-time এ খুঁজে পাওয়া যায়।

count = 0 রাখো — কয়টা মিসিং নাম্বার পেয়েছি তা ট্র্যাক করার জন্য।

num = 1 থেকে শুরু করে চেক করো:

যদি num → set-এ না থাকে, তাহলে সেটা missing number। count++ করো।

যদি count == k, তাহলে উত্তর num ই।

যখনই k-টা missing number পেয়ে গেছো, break করে দাও।

✅ Code Explanation (Bangla)
cpp
Copy
Edit
class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int> set1;
        int ans;

        // Step 1: সব elements কে সেট-এ রাখছি
        for(int i = 0; i < arr.size(); i++)
        {
            set1.insert(arr[i]);
        }

        int count = 0;

        // Step 2: 1 থেকে শুরু করে প্রতিটা সংখ্যা চেক করছি
        for(int j = 1; count < k; j++)
        {
            // যদি j সেটে না থাকে, তাহলে এটা মিসিং নাম্বার
            if(set1.find(j) == set1.end())
            {
                count++;

                // যদি এইটাই k-তম মিসিং সংখ্যা হয়
                if(count == k)
                {
                    ans = j;
                    break;
                }
            }
        }

        return ans;
    }
};
🧪 Test Case Walkthrough
🔹 Test 1:
cpp
Copy
Edit
Input: arr = [2,3,4,7,11], k = 5
Missing numbers: [1,5,6,8,9,...]

5th missing number = 9

Output: ✅ 9

🔹 Test 2:
cpp
Copy
Edit
Input: arr = [1,2,3,4], k = 2
Missing numbers: [5,6,7,...]

2nd missing = 6

Output: ✅ 6

✅ Time Complexity:
O(n + k), যেখানে n হচ্ছে arr.size(), আর k হচ্ছে কতটা পর্যন্ত missing নাম্বার খুঁজবো।

Worst case যদি arr অনেক dense হয়, তাহলে j বড় হতে পারে। তবে k <= 1000, তাই acceptable।

Full Code:
-----------

  class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int>set1;
        int ans;
        for(int i=0;i<arr.size();i++)
        {
          set1.insert(arr[i]);
        }
        int count=0;
        for(int j=1;count<k;j++)
        {
          if(set1.find(j)==set1.end())
          {
            count++;
            if(count==k)
            {
                 ans=j;
                 break;
            }
          }
        }
return ans;
    }
};

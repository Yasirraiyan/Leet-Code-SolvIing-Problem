🧠 প্রশ্ন বোঝা (Understanding the Problem)
আমাদেরকে 1 থেকে n পর্যন্ত সংখ্যা থেকে কিছু সংখ্যা বেছে নিতে হবে, শর্তগুলো:

বেছে নেয়া সংখ্যা banned array-তে থাকতে পারবে না।

একটা সংখ্যা একবারই নেয়া যাবে।

সব বেছে নেয়া সংখ্যার যোগফল maxSum এর বেশি হওয়া যাবে না।

এই শর্তগুলো মেনে যত বেশি সংখ্যা নেয়া যায়, সেই সংখ্যাটিই রিটার্ন করতে হবে।

📚 উদাহরণ 1:
makefile
Copy
Edit
banned = [1,6,5], n = 5, maxSum = 6

বেছে নেওয়া যাবে: 2, 3, 4

এদের যোগফল: 
2+3=5 (ok), 
2+4=6 (ok),
2+3+4=9 (too much)

তাহলে 2 এবং 4 নিলে 6 হয় — ঠিক।

সর্বোচ্চ 2 টা সংখ্যা নেয়া যাবে।
🔍 সমাধানের থিংকিং প্রসেস (How to Think Step-by-Step)
Step 1:
banned লিস্টে যেগুলো আছে, সেগুলো বাদ দিতে হবে — তাই আমরা একটা unordered_set ব্যবহার করি যাতে O(1) টাইমে চেক করা যায়।

Step 2:
1 থেকে n পর্যন্ত প্রতিটা সংখ্যা চেক করি:

যদি সেটা banned-এ না থাকে → আমরা সেটা রাখার যোগ্য মনে করি।

Step 3:
এই valid সংখ্যাগুলা ছোট থেকে বড় সাজিয়ে নেই (sort)।
কারণ আমরা ছোট ছোট সংখ্যা নিলে কম যোগফলে বেশি সংখ্যা নিতে পারবো।

Step 4:
এখন যোগফল বের করি:

যতক্ষণ না sum <= maxSum, ততক্ষণ সংখ্যা যোগ করি এবং কাউন্ট বাড়াই।

✅ কোড ব্যাখ্যা (Line-by-Line Bangla Explanation)
cpp
Copy
Edit
class Solution {
public:

    // extra function, actually unused – removeable
    int findsum(int a,int b)
    {
        return a+b;
    }

    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;

        // Step 1: banned সংখ্যা গুলো hash set-এ রাখা
        unordered_set<int> set1;
        for(int j=0; j<banned.size(); j++) {
            set1.insert(banned[j]);
        }

        // Step 2: 1 থেকে n পর্যন্ত valid সংখ্যা বের করা
        vector<int> vv;
        for(int i=1; i<=n; i++) {
            if(set1.find(i) == set1.end()) {
                vv.push_back(i);  // valid সংখ্যা
            }
        }

        // Step 3: ছোট থেকে বড় সাজানো
        sort(vv.begin(), vv.end());

        // Step 4: যোগফল হিসেব করে কটি সংখ্যা নেয়া যায় বের করা
        vector<int> vvv;
        int sum = 0;
        for(int i=0; i<vv.size(); i++) {
            sum += vv[i];
            if(sum <= maxSum) {
                vvv.push_back(vv[i]);
            }
        }

        // Step 5: নেয়া সংখ্যার সংখ্যা রিটার্ন করা
        count = vvv.size();
        return count;
    }
};
🧪 টেস্ট কেস চলো ব্যাখ্যা করি:
🔸 Test Case 1:
cpp
Copy
Edit
Input: banned = [1,6,5], n = 5, maxSum = 6
✅ Valid numbers: 2, 3, 4
→ Sorted: 2, 3, 4
→ Prefix sum:

2 → sum = 2 ✅

3 → sum = 5 ✅

4 → sum = 9 ❌ (exceeds maxSum)

✅ নেওয়া যায়: 2, 3 → 2 সংখ্যা
Output: 2

🔸 Test Case 2:
cpp
Copy
Edit
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
✅ Valid: [8]
→ 8 > 1 → কোনো সংখ্যাও নেয়া যাবে না
Output: 0

🔸 Test Case 3:
cpp
Copy
Edit
Input: banned = [11], n = 7, maxSum = 50
✅ Valid: [1,2,3,4,5,6,7]
Sum = 28 < 50
Output: 7

✅ Accepted কেনো হয়েছে?
Efficient use of unordered_set → O(1) check

Sorted valid numbers → greedy approach

Loop sum check → ensures maxCount with minimum sum

🔧 Optimization Tips:
vvv vector না রেখে শুধু count করলেই চলে, যেমন:

cpp
Copy
Edit
int sum = 0, count = 0;
for (int i = 0; i < vv.size(); i++) {
    if (sum + vv[i] > maxSum) break;
    sum += vv[i];
    count++;
}
🔚 Final Note:
এই প্রবলেমটা একটা ক্লাসিক greedy with filtering স্টাইল।

প্রথমে valid candidate বাছাই,

এরপর যত ছোট সংখ্যায় সম্ভব সেটি optimize করা।
এটা competitive coding এ অনেক কাজে লাগে।

Full Code:
----------

  class Solution {
public:
 int findsum(int a,int b)
 {
  return a+b;
 }
    int maxCount(vector<int>& banned, int n, int maxSum) {
      int count=0;
        unordered_set<int>set1;
        for(int j=0;j<banned.size();j++)
        {
          set1.insert(banned[j]);
        }
        vector<int>vv;
        for(int i=1;i<=n;i++)
        {
          if(set1.find(i)==set1.end())
          {
            vv.push_back(i);
          }
        }
        sort(vv.begin(),vv.end());
        vector<int>vvv;
        int sum=0;

        for(int i=0;i<vv.size();i++)
        {
              sum+=vv[i];
              if(sum<=maxSum)
              {
                vvv.push_back(vv[i]);
              }
        }
count=vvv.size();
return count;
    }
};

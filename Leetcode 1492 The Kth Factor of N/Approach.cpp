🔶 প্রশ্ন বিশ্লেষণ (Problem Analysis):

আপনাকে একটি সংখ্যা n এবং একটি ধনাত্মক সংখ্যা k দেওয়া হয়েছে।
চাওয়া হচ্ছে: n এর factors গুলো নিয়ে একটা ascending sorted list বানান, এরপর k-th factor (মানে k-তম সংখ্যাটি) বের করুন।
যদি total factor সংখ্যা k-র চেয়ে কম হয়, তাহলে -1 return করতে হবে।

উদাহরণ:

n = 12 হলে, factors: [1, 2, 3, 4, 6, 12]
যদি k = 3 হয় ➤ ৩য় সংখ্যাটি 3 → output = 3

n = 7, k = 2 ➤ factors: [1, 7] → ২য় সংখ্যাটি 7

n = 4, k = 4 ➤ factors: [1, 2, 4] → ৪টি নেই, তাই output = -1



---

🔶 সমাধান ভাবনা (How to think the solution):

Step by step চিন্তা:

1. আমরা জানি কোন সংখ্যা n এর factor তখনই হয় যখন n % i == 0 হয় (মানে n কে i দিয়ে ভাগ করলে ভাগশেষ 0 হয়)।


2. তাই আমরা i = 1 থেকে n পর্যন্ত প্রতিটি সংখ্যায় চেক করবো n % i == 0 কিনা।


3. যদি হয়, তাহলে আমরা সেই factor টাকে count করবো (ধরি count নামক ভেরিয়েবলে count রাখছি)।


4. যদি কখনো count == k হয়ে যায় ➤ মানে আমরা k-তম factor পেয়ে গেছি ➤ তখন সেটাই return করবো।


5. যদি count < k হয় পুরো লুপ শেষে ➤ return -1;




---

🔶 কোড ব্যাখ্যা (Code Explanation Line by Line in Bangla):

class Solution 
{
public:
    int kthFactor(int n, int k) 
    {
        int ans = -1;         // শুরুতে ধরে নিই k-th factor নেই, তাই ans = -1
        int count = 0;        // কতটি factor এখন পর্যন্ত পেয়েছি, তার হিসাব রাখবে

        for (int i = 1; i <= n; i++)   // 1 থেকে n পর্যন্ত সব সংখ্যা ঘুরে দেখবো
        {
            if (n % i == 0)           // যদি i দ্বারা n ভাগ যায় ➤ factor পাওয়া গেল
            {
                count++;              // একটা নতুন factor পাওয়া গেল, তাই count বাড়ালাম

                if (count == k)       // যদি এখন পাওয়া গ্যাছে k-তম factor
                {
                    ans = i;          // এই i ই k-তম factor
                    break;            // এখন আর খোঁজার দরকার নাই ➤ break
                }
            }
        }
        return ans;                   // loop শেষে ans return করবো (কিংবা -1)
    }
};


---

🔶 টেস্ট কেস বিশ্লেষণ (Test Case Explanation in Bangla):

✅ উদাহরণ 1:

Input: n = 12, k = 3

12 এর factors:

1 (12%1==0) → count = 1

2 (12%2==0) → count = 2

3 (12%3==0) → count = 3 → k = 3 পাওয়া গ্যাছে → return 3



✅ উদাহরণ 2:

Input: n = 7, k = 2

7 এর factors:

1 → count = 1

2,3,4,5,6 → ভাগ যায় না

7 → count = 2 → k=2 পাওয়া গ্যাছে → return 7



✅ উদাহরণ 3:

Input: n = 4, k = 4

4 এর factors:

1 → count = 1

2 → count = 2

4 → count = 3
➤ আর কিছু নেই ➤ count < k ➤ return -1




---

🔶 সময় জটিলতা (Time Complexity):

আমরা 1 থেকে n পর্যন্ত i ঘুরাচ্ছি
➤ তাই Time Complexity: O(n)

অতিরিক্ত কোন জায়গা নিচ্ছি না
➤ Space Complexity: O(1)


Full Code:
--------------

  class Solution 
{
public:
    int kthFactor(int n, int k) 
    {
        int ans=-1;
        int count=0;
        for(int i=1;i<=n;i++)
            {
                if(n%i==0)
                {
                    count++;
                    if(count==k)
                    {
                        ans=i;
                        break;
                    }
                }
            }
        return ans;
    }
};

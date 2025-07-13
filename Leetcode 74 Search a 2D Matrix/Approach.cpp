✅ প্রশ্ন বুঝে চিন্তার ধাপ

প্রথমে প্রশ্নে বলা হয়েছে:

> প্রতিটি row sorted

প্রতিটি পরবর্তী row-এর প্রথম সংখ্যা আগের row-এর শেষ সংখ্যার চেয়ে বড়




📌 এর মানে পুরো matrix-টা আসলে একটি sorted 1D array এর মতো behave করে।

🔍 এখন প্রশ্ন চায়: এমন একটি target matrix-এ আছে কিনা, এবং সমাধানের টাইম কমপ্লেক্সিটি হবে O(log(m * n))।


---



তুমি এইভাবে চিন্তা করেছো:

> "আমি যদি পুরো matrix ঘুরে দেখি এবং সব সংখ্যা unordered_set-এ রাখি, তাহলে আমি O(1) টাইমে target আছে কিনা খুঁজে পেতে পারি।"




---

🔍 তোমার কোডটি

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unordered_set<int> set1;
        bool find = false;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                set1.insert(matrix[i][j]); // সমস্ত ভ্যালু set এ ঢোকানো
            }
        }

        if (set1.find(target) != set1.end()) {
            find = true; // যদি পাওয়া যায়, তাহলে true সেট করা
        }

        return find;
    }
};


---

✅ লাইন বাই লাইন ব্যাখ্যা (Line-by-line Bangla Explanation)

🔸 unordered_set<int> set1;

👉 তুমি একটি সেট ব্যবহার করছো যাতে ডুপ্লিকেট ছাড়া সব ভ্যালু রাখা যায় এবং দ্রুত সার্চ করা যায়।


---

🔸 Outer loop: for (int i = 0; i < matrix.size(); i++)

👉 এটি প্রতিটি row এর উপর লুপ।


---

🔸 Inner loop: for (int j = 0; j < matrix[i].size(); j++)

👉 এটি প্রতিটি row এর প্রতিটি column (element) এর উপর লুপ।


---

🔸 set1.insert(matrix[i][j]);

👉 প্রতিটি এলিমেন্ট set-এ insert করছো।


---

🔸 if (set1.find(target) != set1.end())

👉 যদি target সেটে পাওয়া যায়, তাহলে true return করবে।


---

✅ উদাহরণ দিয়ে দেখি:

matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]];
target = 3

তোমার কোড কী করবে:

সব ভ্যালু set-এ ঢোকাবে: {1,3,5,7,10,11,16,20,23,30,34,60}

তারপর target = 3 সেটে আছে কিনা চেক করবে → ✅ পাওয়া যাবে


➡️ Return করবে true


---
Full Code:
-----------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unordered_set<int>set1;
        bool find=false;
        for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                    {
                        set1.insert(matrix[i][j]);
                    }
            }
        if(set1.find(target)!=set1.end())
        {
            find=true;
        }
        return find;
    }
};
  

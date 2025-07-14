🔶 Step 1: Loop Iteration Process (বাংলায় ব্যাখ্যা)

আমরা নিচের কোড ব্যবহার করি:

for(int i = 0; i < matrix.size() - 1; i++) {
    for(int j = 0; j < matrix[0].size() - 1; j++) {
        if(matrix[i][j] != matrix[i+1][j+1]) {
            return false;
        }
    }
}
return true;

🔁 লুপ কিভাবে কাজ করে?

চলক (variable)	অর্থ ও ব্যাখ্যা

i	সারি (row) নম্বর, ০ থেকে m-2 পর্যন্ত
j	কলাম (column) নম্বর, ০ থেকে n-2 পর্যন্ত
matrix[i][j]	বর্তমান উপাদান
matrix[i+1][j+1]	পরবর্তী ডায়াগোনালের উপাদান


> ✅ আমরা শুধু matrix[i][j] == matrix[i+1][j+1] চেক করলেই বুঝতে পারি সব ডায়াগোনালে উপাদান একই আছে কিনা।




---

🔶 Step 2: উদাহরণ — 3x4 Matrix

matrix = [
  [1, 2, 3, 4],
  [5, 1, 2, 3],
  [9, 5, 1, 2]
]


---

✅ Cross-Check Table (Based on Your Notebook Style):

🔍 টেবিলের ব্যাখ্যা:

matrix[i][j] কে matrix[i+1][j+1] এর সাথে তুলনা করা হচ্ছে।

যেখানে তুলনা করা সম্ভব না (index limit ছাড়িয়ে যায়), সেগুলো বাদ।


📊 Cross-check Table:

i	j	matrix[i][j]	matrix[i+1][j+1]	তুলনা	সঠিক কিনা

0	0	1	1	1 == 1	✅ হ্যাঁ
0	1	2	2	2 == 2	✅ হ্যাঁ
0	2	3	3	3 == 3	✅ হ্যাঁ
0	3	4	❌ বাইরে	তুলনা সম্ভব নয়	✖️ বাদ
1	0	5	5	5 == 5	✅ হ্যাঁ
1	1	1	1	1 == 1	✅ হ্যাঁ
1	2	2	2	2 == 2	✅ হ্যাঁ
1	3	3	❌ বাইরে	তুলনা সম্ভব নয়	✖️ বাদ



---

🧾 ম্যাট্রিক্সে চিহ্নিত ডায়াগোনাল:

Matrix:
[
  [1, 2, 3, 4],
  [5, 1, 2, 3],
  [9, 5, 1, 2]
]

Diagonal Lines:
↘ 1 (0,0) → 1 (1,1) → 1 (2,2)
↘ 2 (0,1) → 2 (1,2) → 2 (2,3)
↘ 3 (0,2) → 3 (1,3)
↘ 4 (0,3)
↘ 5 (1,0) → 5 (2,1)
↘ 9 (2,0)

✅ প্রতিটি ডায়াগোনালে উপাদান একই → এটি Toeplitz Matrix


---

🔶 Step 3: চূড়ান্ত কোড (Accepted ✅)

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() - 1; i++) {
            for(int j = 0; j < matrix[0].size() - 1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
    }
};


---

🔶 Complexity:

ধরন	মান

⏱️ Time	O(m * n)
💾 Space	O(1)
✅ Extra Memory	প্রয়োজন নেই



---

🧠 মনে রাখার ট্রিক:

> matrix[i][j] == matrix[i+1][j+1] → এটাই হল Toeplitz চেক করার মূল সূত্র।
শুধুমাত্র ম্যাট্রিক্সের শেষ row এবং column বাদ দিয়ে লুপ চালালেই কাজ হবে।




---

📁 GitHub Markdown Table Ready Version

### ✅ Toeplitz Matrix Check — Leetcode 766

**Matrix:**

[ [1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2] ]

| i | j | matrix[i][j] | matrix[i+1][j+1] | সমান কিনা |
|---|---|--------------|------------------|-------------|
| 0 | 0 | 1            | 1                | ✅           |
| 0 | 1 | 2            | 2                | ✅           |
| 0 | 2 | 3            | 3                | ✅           |
| 1 | 0 | 5            | 5                | ✅           |
| 1 | 1 | 1            | 1                | ✅           |
| 1 | 2 | 2            | 2                | ✅           |

**Time Complexity:** O(m * n)  
**Space Complexity:** O(1)

Full Code:
----------

class Solution
{
  public:
  bool isToeplitzMatrix(vector<vector<int>>&matrix)
  {
    bool istoeplitz=true;
    for(int i=0;i<matrix.size()-1;i++)
    {
      for(int j=0;j<matrix[i].size()-1;j++)
      {
        if(matrix[i][j]!=matrix[i+1][j+1])
        {
           istoeplitz=false;
           break;
        }
      }
    }
    return istoeplitz;
  }
};

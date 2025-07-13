
তোমাকে একটি n x n সাইজের ম্যাট্রিক্স দেওয়া হবে যেখানে:

প্রতিটি row এবং column ascending (বাড়তে থাকা) order-এ সাজানো।

তোমাকে sorted order অনুযায়ী k-তম smallest element বের করতে হবে।

তোমার সলিউশন এর মেমোরি কমপ্লেক্সিটি O(n²) এর চেয়ে ভালো হওয়া উচিত (advanced optimization hint)।



---

🔸 উদাহরণ দিয়ে বোঝা যাক:

Input:

matrix = [[1,5,9],
          [10,11,13],
          [12,13,15]]
k = 8

এই ম্যাট্রিক্সে সব এলিমেন্ট sort করলে পাই:

[1, 5, 9, 10, 11, 12, 13, 13, 15]
                      ↑
                      8th smallest = 13


---

✅ তোমার কোডের ধারণা (Approach):

তুমি brute-force approach নিয়েছো:

✨ Step-by-step কী চিন্তা করে সমাধান লিখলে:

1. Input বুঝে নিয়েছো — একটা ম্যাট্রিক্স (2D vector) এবং একটা সংখ্যা k।


2. সমস্ত এলিমেন্ট বের করেছো ম্যাট্রিক্স থেকে:

for(int i=0;i<matrix.size();i++)
    for(int j=0;j<matrix[i].size();j++)
        v.push_back(matrix[i][j]);

🔍 এখানে তুমি ম্যাট্রিক্সকে 1D array-এ রূপান্তর করছো।


3. sort(v.begin(), v.end()) দিয়ে সব এলিমেন্ট sort করেছো।


4. k-th smallest element খুঁজে নিয়েছো:

if(k==j+1) ans = v[j];


5. শেষে return করেছো ans.




---

💡 কোড কেন কাজ করছে?

তুমি ম্যাট্রিক্স থেকে সব সংখ্যা নিয়ে sorting করে ফেলেছো। এরপর যেহেতু index 0-based, তাই k-1 index এর মানটাই হলো k-th smallest।



---

📌 Time & Space Complexity:

Time:

Matrix traversal: O(n²)

Sorting: O(n² log n²) = O(n² log n)


Space:

Extra vector: O(n²)
⛔️ কিন্তু প্রশ্নে বলা হয়েছে “Better than O(n²) memory” — তাই এটিকে optimal বলা যাবে না। এটা brute force solution।




---

✅ কেনো তোমার কোড "Accepted" হলো?

Leetcode-এ সাধারণত:

Brute force solutionও Accepted হয় যদি input constraint-এর মধ্যে কাজ করে।

এখানে n <= 300 → মোট n² = 90000 এলিমেন্ট পর্যন্ত manageable।



---

✅ কিভাবে চিন্তা করে এই solution লেখা যায়?

প্রশ্নটি পড়েই তুমি চিন্তা করতে পারো:

ম্যাট্রিক্সের সব সংখ্যা যদি হাতে থাকত, তাহলে sort করে k-th smallest বের করা সহজ।

তাহলে প্রথম ধাপ: ম্যাট্রিক্স থেকে সব সংখ্যা বের করে একটি vector-এ রেখে sort করা।


এখানে row এবং column উভয়ই sorted, কিন্তু তুমি সেটা use করোনি (তাই এটি brute-force)।


---

📚 টেস্টকেস দিয়ে বুঝে দেখো

Input: matrix = [[-5]], k = 1
v = [-5]
sorted = [-5]
k = 1 → answer = v[0] = -5 ✅

Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]], k = 4
v = [1,2,3,4,5,6,7,8,9]
sorted = same
answer = v[3] = 4 ✅




  Full Code:
--------------
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v;
        int count=0;
        int ans;
        for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                    {
                        v.push_back(matrix[i][j]);
                    }
            }
        sort(v.begin(),v.end());
        for(int j=0;j<v.size();j++)
            {
                if(k==j+1)
                {
                    ans=v[j];
                    break;
                }
            }
        return ans;
    }
};

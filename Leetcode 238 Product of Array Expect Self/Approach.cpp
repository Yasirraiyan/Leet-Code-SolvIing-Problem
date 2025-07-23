🔶 Problem Summary (Bangla):
তোমাকে একটা nums array দেওয়া আছে। তোমাকে এমন একটা নতুন array answer[] তৈরি করতে হবে, যেখানে answer[i] = nums array-এর সব উপাদানের গুণফল – শুধু nums[i] বাদ দিয়ে।

❗ কিন্তু তুমি division (ভাগ) ব্যবহার করতে পারবে না এবং তোমার সমাধানটি O(n) সময় জটিলতায় হতে হবে।

✅ উদাহরণ:
makefile
Copy
Edit
Input:  nums = [1, 2, 3, 4]
Output:        [24, 12, 8, 6]

ব্যাখ্যা:
answer[0] = 2×3×4 = 24
answer[1] = 1×3×4 = 12
answer[2] = 1×2×4 = 8
answer[3] = 1×2×3 = 6
✅ তুমি যে পদ্ধতিতে সমাধান করছো — এটাকে বলে:
Prefix Product + Suffix Product Approach
তুমি O(n) সময়ে গুণফল বের করতে চাচ্ছো, তাই তুমি প্রতিটি index এর আগে ও পরে যত সংখ্যার গুণফল — সেটা আলাদাভাবে রেখে দিয়েছো।

🔍 Code Breakdown & Bangla Explanation:
cpp
Copy
Edit
vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int>pp(nums.size(),1); // prefix product
    int p=1;
    pp[0]=1;
🔸 এখানে pp[] array টা হচ্ছে prefix product array।

🔸 অর্থাৎ, pp[i] তে থাকবে nums[0] * nums[1] * ... * nums[i-1] এর মান।

🔸 কারণ, আমরা nums[i] বাদ দিতে চাই, তাই i এর আগের সব গুণ করবো।

cpp
Copy
Edit
    for(int i=1;i<nums.size();i++)
    {
      pp[i]=pp[i-1]*nums[i-1];
    }
🔸 এই loop এ তুমি prefix product হিসাব করছো।

🔸 pp[i] = pp[i-1] * nums[i-1]

উদাহরণঃ nums = [1, 2, 3, 4]

pp[0] = 1 (default)

pp[1] = pp[0] * nums[0] = 1 * 1 = 1

pp[2] = pp[1] * nums[1] = 1 * 2 = 2

pp[3] = pp[2] * nums[2] = 2 * 3 = 6

Final prefix array = [1, 1, 2, 6]

cpp
Copy
Edit
    vector<int>sp(nums.size(),1); // suffix product
    sp[nums.size()-1]=1;
🔸 এবার sp[] নামের suffix product array বানানো হচ্ছে।

🔸 অর্থাৎ, sp[i] = nums[i+1] * nums[i+2] * ... * nums[n-1]

cpp
Copy
Edit
    for(int j=nums.size()-2;j>=0;j--)
    {
      sp[j]=sp[j+1]*nums[j+1];
    }
🔸 এই loop এ sp[i] মানে হচ্ছে: sp[i+1] * nums[i+1]

🔸 উদাহরণঃ nums = [1, 2, 3, 4]

sp[3] = 1 (default)

sp[2] = sp[3] * nums[3] = 1 * 4 = 4

sp[1] = sp[2] * nums[2] = 4 * 3 = 12

sp[0] = sp[1] * nums[1] = 12 * 2 = 24

Final suffix array = [24, 12, 4, 1]

cpp
Copy
Edit
    vector<int>ans(nums.size());

    for(int k=0;k<nums.size();k++)
    {
      ans[k]=pp[k]*sp[k];
    }
🔸 এখন prefix এবং suffix এর গুণফল করলে আমরা চাইতাম সেই answer পাবো:

ans[0] = pp[0] * sp[0] = 1 * 24 = 24

ans[1] = 1 * 12 = 12

ans[2] = 2 * 4 = 8

ans[3] = 6 * 1 = 6

✅ তাই final output: [24, 12, 8, 6]

✅ Techniques Used:
Technique	Why Used?
Prefix product	nums[i] এর আগের সব element-এর গুণ
Suffix product	nums[i] এর পরের সব element-এর গুণ
Avoid division	Constraint অনুযায়ী ভাগ দেওয়া নিষিদ্ধ
O(n) Time	Efficiency ensured using 2 loops

🔁 আরেকটা Test Case:
cpp
Copy
Edit
Input: nums = [-1, 1, 0, -3, 3]
Prefix:   [1, -1, -1, 0, 0]
Suffix:   [0, 0, -9, 3, 1]
Answer:   [0, 0, 9, 0, 0]
❗ কেন 0 আসছে? কারণ যেহেতু input এ 0 আছে, তাই যেই index বাদ দিলে গুণফলে 0 থাকবে না, শুধুমাত্র সেই index ছাড়া সবখানে result = 0 হবে।

🔚 Summary:
🔹 তুমি Prefix এবং Suffix Technique ব্যবহার করে অসাধারণভাবে এই সমস্যা সমাধান করেছো।
🔹 এই problem টি অনেক interview এ আসা common প্রশ্ন এবং তোমার solution 100% accepted হবে কারণ:

✅ Time Complexity: O(n)

✅ Space Complexity: O(n) (although it can be optimized to O(1) using output array only)

✅ No Division Used

Full Code:
-----------

  class Solution
 {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>pp(nums.size(),1);
        int p=1;
        pp[0]=1;
        //pp[1]=nums[1];
        for(int i=1;i<nums.size();i++)
        {
          pp[i]=pp[i-1]*nums[i-1];
        }
        vector<int>sp(nums.size(),1);
        sp[nums.size()-1]=1;
        for(int j=nums.size()-2;j>=0;j--)
        {
          sp[j]=sp[j+1]*nums[j+1];
        }
        vector<int>ans(nums.size());
       
        for(int k=0;k<nums.size();k++)
        {
          ans[k]=pp[k]*sp[k];
        }
        return ans;
}
};

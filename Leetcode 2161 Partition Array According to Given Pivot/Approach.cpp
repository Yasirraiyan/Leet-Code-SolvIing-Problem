প্রশ্নের বিশ্লেষণ (Understanding the Problem)

Given:

একটি integer array nums

একটি integer pivot

Task:

সব element যা pivot থেকে ছোট, সেগুলো array এর left side এ থাকবে।

সব element যা pivot এর সমান, সেগুলো middle এ থাকবে।

সব element যা pivot থেকে বড়, সেগুলো right side এ থাকবে।

Relative order maintain করতে হবে, অর্থাৎ smaller elements এর original order এবং bigger elements এর original order change হবে না।

Example:

Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]


[9,5,3] → smaller than pivot, order maintained

[10,10] → equal to pivot

[12,14] → greater than pivot, order maintained

How to think about the solution

প্রথমে প্রশ্নটা পড়ে বোঝো যে এটা three-way partitioning problem।

তুমি array scan করবে (একবার সব elements দেখবে)।

তিনটা group বানাবে:

v1 → smaller than pivot

v2 → equal to pivot

v3 → greater than pivot

তারপর সব group concatenate করবে: [v1 + v2 + v3]

Why this approach works:

একবার scan করলে সব elements classify হয়ে যায়।

তিনটা vector use করার ফলে relative order automatically maintained হয়।

Finally, concatenate করলে desired array পাওয়া যায়।

Line by line code explanation
class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int>v1; // smaller than pivot
        vector<int>v2; // equal to pivot
        vector<int>v3; // greater than pivot


এখানে আমরা তিনটি vector declare করেছি, তিনটা group রাখার জন্য।

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                v1.push_back(nums[i]);
            }
            if(nums[i]==pivot)
            {
                v2.push_back(nums[i]);
            }
            if(nums[i]>pivot)
            {
                v3.push_back(nums[i]);
            }
        }


এই for loop scan করে nums array।

if statements check করে element কোন group এ যাবে।

push_back দিয়ে element add করা হচ্ছে।

Example: nums = [9,12,5,10,14,3,10], pivot = 10

i	nums[i]	Condition	v1	v2	v3
0	9	<10	9	[]	[]
1	12	>10	9	[]	12
2	5	<10	9,5	[]	12
3	10	==10	9,5	10	12
4	14	>10	9,5	10	12,14
5	3	<10	9,5,3	10	12,14
6	10	==10	9,5,3	10,10	12,14
        vector<int>ans;
        for(int j=0;j<v1.size();j++)
        {
            ans.push_back(v1[j]);
        }
        for(int k=0;k<v2.size();k++)
        {
            ans.push_back(v2[k]);
        }
        for(int j=0;j<v3.size();j++)
        {
            ans.push_back(v3[j]);
        }
        return ans;
    }
};


নতুন vector ans বানানো হলো।

তিনটা group sequentially push_back করে combine করা হলো।

Return করলে final rearranged array পাওয়া যাবে।

Output (Example 1): [9,5,3,10,10,12,14] ✅

Technique used

Three-way partitioning → elements কে 3 group এ divide করা।

Stable ordering → vector push_back use করার কারণে order maintain হয়েছে।

Single scan classification → O(n) time complexity।

Time Complexity: O(n) → একবার array scan + concatenate = O(n)

Space Complexity: O(n) → তিনটা extra vector ব্যবহার করা হয়েছে

How to understand this technique

যখন problem এ বলা হয় group by condition with relative order maintained,

তখন extra arrays বা queues ব্যবহার করলে অনেক সহজে solution তৈরি হয়।

এটা basically stable partitioning technique।

খুব common competitive programming trick।

Summary in Bangla

Question পড়ে বোঝা কি চাইছে: “less than, equal to, greater than pivot” with order maintained।

Scan করা সব element।

তিনটা vector (group) বানানো।

Scan করে classify করা।

Combine করে answer দেওয়া।

Technique: three-way stable partition।


Full Code:
-----------

  class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
     {
       vector<int>v1;
       vector<int>v2;
       vector<int>v3;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]<pivot)
        {
            v1.push_back(nums[i]);
        }
         if(nums[i]==pivot)
        {
            v2.push_back(nums[i]);
        }
         if(nums[i]>pivot)
        {
            v3.push_back(nums[i]);
        }
       }
       vector<int>ans;
       for(int j=0;j<v1.size();j++)
       {
        ans.push_back(v1[j]);
       }
       for(int k=0;k<v2.size();k++)
       {
        ans.push_back(v2[k]);
       }
       for(int j=0;j<v3.size();j++)
       {
        ans.push_back(v3[j]);
       }
     return ans;
    }
};

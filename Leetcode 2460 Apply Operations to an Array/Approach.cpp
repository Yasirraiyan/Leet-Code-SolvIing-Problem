প্রশ্ন থেকে ভাবনার ধারা

প্রশ্নের মূল ধারণা:

আমাদের কাছে একটি array আছে: nums.

আমরা n-1 operation করতে পারি, যেখানে i-th operation হলো:

যদি nums[i] == nums[i+1], তাহলে:

nums[i] *= 2

nums[i+1] = 0

অন্যথায়, skip করতে হবে।

সব operations sequentially হবে (একবারে নয়)।

শেষে সব 0 গুলো array এর শেষে shift করতে হবে।

টেকনিক/ধারনা:

এই ধরণের সমস্যা sequential update + zero shifting type।

Step 1: Sequentially element compare করা এবং modify করা।

Step 2: সব non-zero element আগের দিকে, zero element পরে রাখা।

কোডের logic step-by-step
int i = 0;
int j = 1;
while (j < nums.size()) {
    if (nums[i] == nums[j]) {
        nums[i] *= 2;   // i-th element double
        nums[j] = 0;    // j-th element zero
        i = j;          // i pointer update
        j++;
    } else {
        i++;
        j++;
    }
}


ব্যাখ্যা:

আমরা দুইটা pointer ব্যবহার করেছি: i এবং j (neighbor comparison এর জন্য)।

যদি nums[i] == nums[j], তাহলে i-th element double করা এবং j-th element zero করা।

পরে, i কে j তে move করা হয়েছে, কারণ আমরা sequentially check করি।

যদি equal না হয়, তাহলে i এবং j দুটোই এক step move।

Test case visualization:

nums = [1, 2, 2, 1, 1, 0]

i	j	Array after operation	Explanation
0	1	[1,2,2,1,1,0]	1 != 2, skip
1	2	[1,4,0,1,1,0]	2==2, double 2 -> 4, next zero
2	3	[1,4,0,1,1,0]	0!=1, skip
3	4	[1,4,0,2,0,0]	1==1, double 1 -> 2, next zero
4	5	[1,4,0,2,0,0]	0==0, double 0->0, already 0
Zero shift
vector<int> v1; // non-zero
vector<int> v2; // zero
for(int k=0; k<nums.size(); k++) {
    if(nums[k]!=0) v1.push_back(nums[k]);
    else v2.push_back(nums[k]);
}
vector<int> ans;
for(int j=0; j<v1.size(); j++) ans.push_back(v1[j]);
for(int k=0; k<v2.size(); k++) ans.push_back(v2[k]);
return ans;


ব্যাখ্যা:

প্রথমে non-zero element আলাদা করা হয়েছে।

পরে zero element আলাদা করা হয়েছে।

সব non-zero আগে এবং zero পরে push করে final array তৈরি করা হয়েছে।

Test case:

[1,4,0,2,0,0] → non-zero: [1,4,2], zero: [0,0,0]
→ final: [1,4,2,0,0,0] ✅

Code Writing এর ভাবনা

প্রথমে sequential operation বুঝতে হবে।

দুই pointer i এবং j neighbor comparison এর জন্য।

condition check: nums[i] == nums[j] → modify।

শেষে zeros shift করতে এক extra pass।

Technique:

Two-pointer sequential check

Array partitioning (non-zero + zero)

Simulation of operations

কেন accepted

Operations সঠিকভাবে sequentially apply করা হয়েছে।

Zero shift final array ঠিকভাবে তৈরি করছে।

Constraints অনুযায়ী O(n) solution, n ≤ 2000 → efficient।

Summary (বাংলায়)

Read question: neighbor equality → double left, zero right → sequentially → zero shift।

Technique: two-pointer + simulation + array partition।

Code approach:

Sequentially apply operations

i,j pointers দিয়ে neighbor check

Double left, zero right

Zero shift: two vectors (non-zero, zero) → merge

Why accepted:

সব test case sequential operation অনুযায়ী correct

Zero shifting done correctly

Time complexity O(n) → within limit

Full Code:
----------

  class Solution
 {
public:
    vector<int> applyOperations(vector<int>& nums)
     {
     int i=0;
     int j=1;
     vector<int>v(nums.size());
     while(/*i<nums.size()&&*/j<nums.size())
     {
        if(nums[i]==nums[j])
        {
          nums[i]*=2;
          nums[j]=0;
          i=j;
          j++;
        }
        else
        {
            i++;
            j++;
        }
     }
     vector<int>v1;
     vector<int>v2;
     for(int k=0;k<nums.size();k++)
     {
        if(nums[k]!=0)
        {
            v1.push_back(nums[k]);
        }
        else
        {
            v2.push_back(nums[k]);
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
     return ans;
    }
};

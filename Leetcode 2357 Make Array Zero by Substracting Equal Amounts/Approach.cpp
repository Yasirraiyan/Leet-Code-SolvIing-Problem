Code Line by Line Explanation
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;


count = আমরা কতবার operation করেছি তা ট্র্যাক করার জন্য।

শুরুতে 0।

        priority_queue<int, vector<int>, greater<int>> minHeap;


এখানে আমরা min-heap বানাচ্ছি।

greater<int> মানে smallest element সবসময় উপরে থাকবে।

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                minHeap.push(nums[i]);
            }
        }


আমরা শুধুমাত্র positive elements heap-এ push করছি।

Zero elements ignore করা হচ্ছে।

Example 1: [1,5,0,3,5] → heap = [1,3,5,5]

Example 2: [0] → heap empty → while loop skip হবে।

        while(!minHeap.empty()) {
            int top = minHeap.top();
            minHeap.pop();


top = current smallest non-zero number

এই number আমরা পরবর্তী subtraction এ ব্যবহার করব।

Example 1:

প্রথমবার top = 1

            while(!minHeap.empty() && minHeap.top() == top) {
                minHeap.pop();
            }


যদি heap-এ top এর সাথে সমান আরও element থাকে, একসাথে pop করে দিচ্ছি।

মানে duplicate smallest element remove করা হচ্ছে।

Example 1:

প্রথমবার top = 1 → heap = [3,5,5]

কোন duplicate নেই → শুধু next step

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > 0 && top > 0) {
                    nums[i] = nums[i] - top;
                }
            }


সব positive elements থেকে top subtract করা হচ্ছে।

Zero elements ignore।

Example 1 Step 1:

nums = [1,5,0,3,5], top = 1
nums -> [0,4,0,2,4]


Example 1 Step 2: next top = 2 → [0,4,0,2,4] - 2 → [0,2,0,0,2]

Example 1 Step 3: next top = 2 → [0,2,0,0,2] - 2 → [0,0,0,0,0]

            count++;


এক operation সম্পন্ন হয়েছে → count বাড়াও।

        }
        return count;
    }
};


যতবার while-loop চলেছে, তার মানে distinct positive numbers-এ operation হয়েছে।

return count = minimum number of operations needed।

Mathematical / Logical Insight

আমরা সবসময় smallest non-zero element select করি → minimum subtraction.

একবারে duplicate smallest remove করা হচ্ছে → efficiency।

Operations শেষ হওয়ার পর সব element 0 হয়।

Minimum operations = number of distinct positive integers in the array।

Example Walkthrough

Example 1: [1,5,0,3,5]

Step	Heap	Top	nums after subtract	count
1	[1,3,5,5]	1	[0,4,0,2,4]	1
2	[2,4,4]	2	[0,2,0,0,2]	2
3	[2,2]	2	[0,0,0,0,0]	3

→ Output = 3 ✅

Example 2: [0]

Heap empty → while loop skip → Output = 0 ✅

  Full Code:
-----------------

  class Solution 
{
public:
int minimumOperations(vector<int>& nums)
     {
        int count=0;
       priority_queue<int,vector<int>,greater<int>>minHeap;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]!=0)
        {
            minHeap.push(nums[i]);
        }
       }
       while(!minHeap.empty())
       {
        int top=minHeap.top();
        minHeap.pop();
        while(!minHeap.empty()&&minHeap.top()==top)
       {
  minHeap.pop();
       }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0&&top>0)
            {
            nums[i]=nums[i]-top;
            }
           
        }
        count++;
       }
       return count;
    }
};

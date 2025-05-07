Amar 1 ta array ase jekhane [0,n] range er sob number ase.Kintu kono array te eder moddhe jekono 1 ta number missing.

Test Case:
-------------
  Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

For this array size:3
Sum from [0,3] is:total sum= =0+1+2+3=6
In array there are 3 numbers:3,0,1
  miss=2
  array sum=3+0+1=4;
  now 6-4=totalsum-arraysum;=ans
  return kori ans

 So,
Appreoach:
---------------
  first e int n e nums.size() nei
  1 ta variable nei aactual sum =0 initially eta diye [0,n] porjonto sobar sum nibo;
Tai
1 ta for loop chalai i=0 to i<=n porjonto i++ kori [1,n] or [0,n] porjonto sum ber kori traverse kore totalsum+=i kori
why [0,n] r [1,n] same
because
0+n=n;
array sum ber kori
for loop chalai j=0 to j<arr.size() j++ kori arrysum+=arr[j] kori .Array sum pailam
 ans=total-array=6-4=2=miss

return kori miss.

Full Code:
-----------
  class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
       int arraysum=0;
       for(int i=0;i<nums.size();i++)
       {
        arraysum+=nums[i];
       }
       int n=nums.size();
       int actualsum=0;
       for(int j=1;j<=n;j++)
       {
        actualsum+=j;
       }
       int miss;
       miss=actualsum-arraysum;
       return miss;
    }
};

Test By Case:
--------------
  চলো তোমার দেওয়া কোডটাকে নিচের একটি পূর্ণাঙ্গ main() সহ C++ প্রোগ্রামে লিখি এবং একটি টেস্ট কেস দিয়ে চালাই:

✅ Full C++ Code:
cpp
Copy
Edit
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arraysum = 0;
        for (int i = 0; i < nums.size(); i++) {
            arraysum += nums[i];
        }

        int n = nums.size();
        int actualsum = 0;
        for (int j = 1; j <= n; j++) {
            actualsum += j;
        }

        int miss = actualsum - arraysum;
        return miss;
    }
};

int main() {
    Solution sol;

    // Test case 1: nums = [3, 0, 1]
    vector<int> nums = {3, 0, 1};
    cout << "Missing number is: " << sol.missingNumber(nums) << endl;

    return 0;
}
✅ Output:
csharp
Copy
Edit
Missing number is: 2
🔍 বিশ্লেষণ:
কোড কাজ করছে কেন?
nums = [3, 0, 1]

arraysum = 3 + 0 + 1 = 4

n = 3 → [0,1,2,3] → যোগফল 0+1+2+3 = 6

কিন্তু তুমি actualsum হিসাব করেছো 1 + 2 + 3 = 6, কারণ 0 বাদ দিয়েছো। তবুও এখানে উত্তর ঠিক আসছে কারণ 0 যোগ করলেও রেজাল্ট একই।

⚠️ Warning:
তবে যদি টেস্ট কেস হয়: nums = [0, 1] → n = 2 → রেঞ্জ [0, 1, 2] → যোগফল 3

cpp
Copy
Edit
nums = [0, 1]
arraysum = 1
actualsum (তোমার কোডে) = 1 + 2 = 3
miss = 3 - 1 = **2** ✅ ঠিক আছে
কিন্তু:

cpp
Copy
Edit
nums = [1] → n = 1
arraysum = 1
actualsum = 1
miss = 0 (ভুল হবে, আসলে 0 অনুপস্থিত)
তাই সঠিক ও নিশ্চিতভাবে কাজ করতে চাইলে 0-সহ actualsum হিসাব করতে হবে:

✅ সঠিক কোড (উন্নত সংস্করণ):
cpp
Copy
Edit
int n = nums.size();
int actualsum = n * (n + 1) / 2; // 0 to n পর্যন্ত যোগফল
int arraysum = 0;
for (int i = 0; i < nums.size(); i++) {
    arraysum += nums[i];
}
return actualsum - arraysum;
  

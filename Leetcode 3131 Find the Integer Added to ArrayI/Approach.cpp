Amar 2 ta array ase nums1 nums2 eder moddhe kobn integer array 1 e jog korle array 2 eer soman hbe.
  Exa:
--------
  Input: nums1 = [2,6,4], nums2 = [9,7,5]

Output: 3

Explanation:

The integer added to each element of nums1 is 3.
  3 kmne
  nums1 er sum=2+6+4=12
  nums2 er sum=9+7+5=21;
  diff=21-12=9
    eder both er size=3;
   same 
tai (21-12)/3=3;
Input: nums1 = [10], nums2 = [5]

Output: -5

Explanation:

The integer added to each element of nums1 is -5.
  kmne 5-10 jokhon size =1 taile -5
  abar 
  Example 3:

Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]

Output: 0

Explanation:

The integer added to each element of nums1 is 0.

both size()=4
  nums 1 er sum=4
  nums2 er sum=4;
diff=4-4=0;
tai=(4-4)/4=0;
Approach:
----------
  2 ta variable nei sum1 ja initial 0 eta diye array 1 er sum ber korbo
  sum2 ja initial 0 eta diye array 2 er sum ber korbo
1 ta for loop chalai i=0 to i<nums1.size() porjonto i++ kori nums1 traverse kori 
sum1+=nums1[i] kori nums1 er sum ber kori
aro 1 ta for loop chalai j=0 to j<nums2.size() porjonto j++ kori nums2 traverse kori 
sum2+=nums2[j] kori nums2 er sum ber kori
check kori same size and size 1 er theke boro 
So,
     if(nums1.size()>1&&nums2.size()>1)
          {
          if(nums1.size()==nums2.size())
          {
hoile 
diff ber kori 
result e rakhi 
So,
  int result=sum2-sum1;
 divide koroi
 ans=result/static_cast<int>(nums1.size());
return kori ans.
Static Cast kn:
----------------
  তুমি খুব ভালো প্রশ্ন করেছো — static_cast<int>(nums1.size()) কেন ব্যবহার করা হয়েছে, আর সরাসরি nums1.size() দিয়ে ভাগ না করলেই বা কি হত?

চল, ধাপে ধাপে বাংলা + ম্যাথেমেটিক্যাল ব্যাখ্যা করি যেন সহজে বুঝতে পারো:

🧠 static_cast মানে কী?
static_cast<Type>(value) হল C++ এ টাইপ কনভার্সনের জন্য ব্যবহৃত একটা মেথড, যেটা কম্পাইল টাইমে (program compile হওয়ার সময়) টাইপ বদলে দেয়।

ধরো:

cpp
Copy
Edit
double x = static_cast<double>(5); // x = 5.0
এখানে 5 ইন্টিজার ছিল, আমরা জোর করে ডাবল বানালাম।

🎯 আমাদের প্রশ্নের কোডটা:
cpp
Copy
Edit
return (sum2 - sum1) / static_cast<int>(nums1.size());
ধরা যাক:

sum2 এবং sum1 হচ্ছে int টাইপ ভেরিয়েবল।

nums1.size() হলো size_t টাইপ, যেটা মূলত unsigned int টাইপের মতো — মানে এটা কখনোই নেগেটিভ হয় না।

❓ তাহলে প্রশ্ন: সরাসরি ভাগ করলে সমস্যা কী?
cpp
Copy
Edit
(sum2 - sum1) / nums1.size();
এখানে sum2 - sum1 হচ্ছে int (signed), কিন্তু nums1.size() হচ্ছে size_t (unsigned)।
C++-এ যখন signed এবং unsigned টাইপ একসাথে কোনো অপারেশনে ব্যবহার করো, তখন C++ automatic type conversion করে — কিন্তু সেটা সবসময় নিরাপদ না।

🔥 সম্ভাব্য সমস্যা:
Unexpected result: যদি sum2 - sum1 নেগেটিভ হয়, আর তুমি unsigned দিয়ে ভাগ করো, তাহলে ফলাফল অদ্ভুত আসতে পারে।

Warning/Error: অনেক কম্পাইলার টাইপ মিক্সিং-এর জন্য warning দেয়, production code-এ এটা এড়ানো উচিত।

📊 একে ম্যাথের মতো ধরো:
ধরো:

cpp
Copy
Edit
sum1 = 20;
sum2 = 10;
nums1.size() = 5;
তাহলে:

cpp
Copy
Edit
(sum2 - sum1) = -10;
এখন যদি:

cpp
Copy
Edit
-10 / 5 = -2 ✅ (যদি টাইপ মেশ না করে)
কিন্তু যদি টাইপ মিক্স হয়:

cpp
Copy
Edit
-10 / size_t(5) → টাইপ কনভার্সন → undefined বা অদ্ভুত ফলাফল
তাই এই ঝামেলা এড়াতে আমরা লিখি:

cpp
Copy
Edit
(sum2 - sum1) / static_cast<int>(nums1.size());
এখানে আমরা জোর করে nums1.size() কে int বানিয়ে দিচ্ছি যাতে দুইটা ভেরিয়েবলই int টাইপে থাকে — তখন কম্পাইলার কোনো গড়বড় করবে না।

✅ কখন static_cast ব্যবহার করবে?
যখন টাইপ mismatch হচ্ছে দুই ভেরিয়েবলের মধ্যে

যখন signed-unsigned সমস্যা হতে পারে

যখন কম্পাইলার warning দিচ্ছে টাইপ কনভার্সনের জন্য

যখন তুমি জানো কনভার্সন নিরাপদ — যেমন size_t → int যদি জানো যে ভ্যালু ছোট

✨ সংক্ষেপে:
কারণ	ব্যাখ্যা
টাইপ mismatch	size_t unsigned আর sum1/sum2 signed
নিরাপদ ফলাফল	টাইপ মিক্সিং এড়ানো
স্পষ্টতা	প্রোগ্রামের behavior নির্ভরযোগ্য হয়
Warning এড়ানো	Clean এবং safe code
তুমি চাইলে আমি এই ব্যাখ্যার ওপর একটা ছোট C++ প্রোগ্রাম লিখে দেখতে পারি যেটা দুইভাবে divide করে — একবার static_cast দিয়ে আর একবার ছাড়া — তাতে পার্থক্য পরিষ্কার হবে। বললেই করে দিচ্ছি!
 For this exa:
--------------
  Example 2:

Input: nums1 = [10], nums2 = [5]

Output: -5

Explanation:

The integer added to each element of nums1 is -5.
   size 1 
  tai 5-10=-5
  So,
  if(nums1.size()==1&&nums2.size()==1)
        {
            ans=nums2[0]-nums1[0];
        }

Full Code:
-----------
  class Solution 
{
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans;
        vector<int>result;
        if(nums1.size()==1&&nums2.size()==1)
        {
            ans=nums2[0]-nums1[0];
        }
          int sum1=0;
          int sum2=0;
          if(nums1.size()>1&&nums2.size()>1)
          {
          if(nums1.size()==nums2.size())
          {
          for(int i=0;i<nums1.size();i++)
          {
            sum1+=nums1[i];
          }
          for(int j=0;j<nums2.size();j++)
          {
            sum2+=nums2[j];
          }
          int result=sum2-sum1;
          ans=result/static_cast<int>(nums1.size());
        //ans=result/(nums1.size());
          }
          }
          return ans;
          
    }
};

🔍 প্রশ্নটি বুঝে সমাধানের ধারণা কিভাবে বানাতে হয়:
প্রশ্নটি বলছে:

দুইটি ইনপুট অ্যারে nums1 এবং nums2 দেয়া আছে — দুইটিই sorted in non-decreasing order (মানে বাড়তে থাকা ক্রমে সাজানো)।
আমাদের এমন সর্বনিম্ন সংখ্যাটি বের করতে হবে, যেটি উভয় অ্যারেতে কমন আছে।
যদি কোন কমন সংখ্যা না থাকে — return -1.

✅ সমাধানের ধাপ ও লজিক (Approach in Bangla):
আমরা যেহেতু দুইটি sorted অ্যারে পেয়েছি, তাই efficient সমাধান চাওয়ার সবচেয়ে ভালো উপায় হল —
👉 একটি অ্যারেকে hash/set করে ফেলি, আরেকটাতে গিয়ে দেখি কোন কমন এলিমেন্ট আছে কিনা।

তুমি ঠিক তাই করেছো:

▶️ Step-by-step:
🔹 Step 1: nums1 কে unordered_set এ রূপান্তর করো
cpp
Copy
Edit
unordered_set<int> set1;
for(int i = 0; i < nums1.size(); i++) {
    set1.insert(nums1[i]);
}
👉 এতে nums1 এর সব এলিমেন্ট O(1) টাইমে খোঁজা যাবে।

🔹 Step 2: nums2 তে লুপ চালিয়ে দেখি কোন এলিমেন্ট set1-এ আছে কিনা
cpp
Copy
Edit
vector<int> v;
for(int j = 0; j < nums2.size(); j++) {
    if(set1.find(nums2[j]) != set1.end()) {
        v.push_back(nums2[j]);  // কমন হলে যোগ করি
    }
}
🔹 Step 3: যদি v ফাঁকা হয়, return -1, নাহলে v থেকে মিনিমাম বের করি
cpp
Copy
Edit
if(v.empty()) return -1;
ans = findmin(v);
return ans;
🔹 Helper function: findmin()
cpp
Copy
Edit
int findmin(vector<int>& v) {
    int min = v[0];
    for(int k = 1; k < v.size(); k++) {
        if(v[k] < min) {
            min = v[k];
        }
    }
    return min;
}
🧪 Test Case দিয়ে ব্যাখ্যা:
Test Case 1:
cpp
Copy
Edit
nums1 = [1, 2, 3], nums2 = [2, 4]
Step 1:
set1 = {1, 2, 3}

Step 2:
nums2 এর 2 → set1 এ আছে → v = [2]
nums2 এর 4 → নেই

Step 3:
v = [2], findmin(v) = 2 → return 2

✅ Output: 2

Test Case 2:
cpp
Copy
Edit
nums1 = [1, 2, 3, 6], nums2 = [2, 3, 4, 5]
Step 1:
set1 = {1, 2, 3, 6}

Step 2:
nums2 এর 2 → আছে → v = [2]
nums2 এর 3 → আছে → v = [2, 3]
nums2 এর 4, 5 → নেই

Step 3:
v = [2, 3], findmin = 2 → return 2

✅ Output: 2

⚙️ কোড আরও Efficient করা যায়?
তুমি set দিয়ে O(n + m) টাইমে কাজ করেছো, যেটা ভালো।
কিন্তু যেহেতু দুইটি অ্যারে sorted, তাই আমরা দুইটি pointer দিয়ে O(n + m) টাইমে আরও কম মেমরিতে কাজ করতে পারি।

তবুও, তোমার কোড ACCEPTED হয়েছে কারণ:

✅ Time Complexity: O(n + m)
✅ Space Complexity: O(n)
✅ যথেষ্ট Efficient
✅ সহজেই বোঝা যায়

✅ Final Tips:
তুমি সুন্দরভাবে ভেবেছো – "কমন" বলতে বুঝিয়েছো set1.find() দিয়ে মিল খোঁজো

"সর্বনিম্ন" বের করেছো findmin() দিয়ে

ভুলভাবে else ans = -1 লিখেছিলে, যেটা প্রয়োজন নেই কারণ আমরা শেষে যাচাই করছি v.empty() কিনা।

  Full Code for Solution1:
---------------------------

  class Solution 
{
  int findmin(vector<int>& v)
  {
    int min=v[0];
    for(int k=1;k<v.size();k++)
    {
            if(v[k]<min)
            {
              min=v[k];
            }
    }
    return min;
  }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1;
        int ans;
        for(int i=0;i<nums1.size();i++)
        {
          set1.insert(nums1[i]);
        }
        vector<int>v;
        for(int j=0;j<nums2.size();j++)
        {
          if(set1.find(nums2[j])!=set1.end())
          {
            v.push_back(nums2[j]);
          }
          else
          {
            ans=-1;
          }
        }
        if(v.empty()) return -1;
        ans=findmin(v);
        return ans;
    }
};

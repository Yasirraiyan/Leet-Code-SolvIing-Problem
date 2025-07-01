✅ 🔎 ধাপ 1: প্রশ্ন বোঝা (What is Twin Sum?)

প্রশ্নে বলা হয়েছে:

তোমাকে একটি লিংকড লিস্ট দেওয়া হবে যার সাইজ n, এবং n even (সম সংখ্যা) হবে।

0-indexed হিসেবে i তম নোড এর twin হচ্ছে (n - 1 - i) তম নোড।

যেমন:

যদি লিস্ট হয় [5, 4, 2, 1], তাহলে:

0 তম নোড = 5

3 তম নোড = 1

→ Twin sum = 5 + 1 = 6

1 তম নোড = 4

2 তম নোড = 2

→ Twin sum = 4 + 2 = 6


সবগুলোর মধ্যে ম্যাক্সিমাম টুইন সাম = 6।




---

✅ 🧠 কিভাবে চিন্তা করবে?

প্রথমেই ভাবো:

Twin নোড মানে একটা নোড আর তার বিপরীত পাশে থাকা নোড (mirror image)।

দুই পাশে থেকে দুইটি নোড নাও, যোগ করো, সেগুলোর মধ্যে যেটা সবচেয়ে বেশি সেটাই return করতে হবে।



---

✅ 🧩 সমাধান কৌশল (Approach):

1. প্রথমে লিংকড লিস্টকে ভেক্টরে রূপান্তর করো (vector<int> v), যাতে করে index দিয়ে access করা যায়।


2. তারপর টুইন হিসেবে প্রতি i তম ও n-1-i তম নোডের যোগফল বের করো।


3. প্রতিটি যোগফল vector<int> vv তে রেখে শেষে তার মধ্যে থেকে সর্বোচ্চ মানটা return করো।




---

✅ কোড বিশ্লেষণ ধাপে ধাপে:

vector<int> v;
while(head != nullptr)
{
    v.push_back(head->val);
    head = head->next;
}

🔹 এই অংশে head থেকে সব নোডের ভ্যালু v নামের ভেক্টরে রাখা হচ্ছে।
🔸 উদাহরণ: head = [4, 2, 2, 3] → v = [4, 2, 2, 3]


---

vector<int> vv(v.size(), 0);
for(int i = 0; i < v.size(); i++)
{
    vv[i] = v[i] + v[v.size() - i - 1];
}

🔹 এখানে প্রতিটি i তম উপাদান এর সাথে তার টুইন n-1-i যোগ করে vv তে রাখা হচ্ছে।
🔸 উদাহরণ: vv[0] = v[0] + v[3] = 4 + 3 = 7
vv[1] = v[1] + v[2] = 2 + 2 = 4
vv[2] = v[2] + v[1] = 2 + 2 = 4
vv[3] = v[3] + v[0] = 3 + 4 = 7

📌 vv = [7, 4, 4, 7]


---

int findmax(vector<int>& arr)
{
    int max = arr[0];
    for(int j = 1; j < arr.size(); j++)
    {
        if(arr[j] > max)
        {
            max = arr[j];
        }
    }
    return max;
}

🔹 এই অংশে vv এর মধ্যে সর্বোচ্চ মানটি খুঁজে বের করা হচ্ছে।
🔸 max(vv) = 7


---

✅ 🔚 Return Statement:

int ans = findmax(vv);
return ans;

🔚 তুমি vv থেকে সর্বোচ্চ Twin Sum বের করে ans রিটার্ন করছো — যা সঠিক!


---

✅ উদাহরণ দিয়ে যাচাই (Test Case):

✅ Test Case 1:

Input: [5, 4, 2, 1]
v = [5, 4, 2, 1]
vv = [5+1=6, 4+2=6, 2+4=6, 1+5=6]
→ max = 6 ✅

✅ Test Case 2:

Input: [4, 2, 2, 3]
v = [4, 2, 2, 3]
vv = [4+3=7, 2+2=4, 2+2=4, 3+4=7]
→ max = 7 ✅

✅ Test Case 3:

Input: [1, 100000]
v = [1, 100000]
vv = [1+100000=100001, 100000+1=100001]
→ max = 100001 ✅


---

✅ কেন কোডটি Accepted হচ্ছে?

Time Complexity: O(n) (একবার লিস্ট traverse, একবার ভেক্টর loop)

Space Complexity: O(n) (ভেক্টর ব্যবহার করা হয়েছে)

Problem Constraint অনুযায়ী: 2 <= n <= 10^5 — যা এই complexity দ্বারা সহজেই handle হয়।


Full Code:
------------
class Solution
{
public:
    int findmax(vector<int>&arr)
    {
        int max=arr[0];
        for(int j=1;j<arr.size();j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
                }
            }
        return max;
    }
    int pairSum(ListNode* head) 
    {
        vector<int>v;
        while(head!=nullptr)
            {
                v.push_back(head->val);
                head=head->next;
            }
        vector<int>vv(v.size(),0);
        for(int i=0;i<v.size();i++)
            {
                vv[i]=v[i]+v[v.size()-i-1];
            }
        int ans=findmax(vv);
        return ans;
    }
};
  

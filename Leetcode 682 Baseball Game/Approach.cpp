✅ প্রশ্ন বিশ্লেষণ (Understand the Problem):
প্রশ্ন বলছে:
একটি operations নামের স্ট্রিং এর তালিকা দেওয়া আছে, যেটিতে নিচের চার ধরণের অপারেশন থাকতে পারে:

ইনটিজার x → এটি একটি নতুন স্কোর, এটিকে রেকর্ডে যোগ করতে হবে।

"C" → আগের স্কোরটি ইনভ্যালিড (বাতিল) করতে হবে, মানে স্ট্যাক থেকে রিমুভ করবো।

"D" → আগের স্কোরের ডাবল করে রেকর্ডে যোগ করবো।

"+" → আগের দুইটি স্কোরের যোগফল করে রেকর্ডে যোগ করবো।

আমাদের টার্গেট হলো, সব অপারেশন শেষে রেকর্ডে যা থাকবে, তার যোগফল বের করা।

🧠 সমাধান ভাবনা (How to Think):
আমরা যেহেতু আগের স্কোরগুলো ট্র্যাক করতে চাই এবং মাঝে মাঝে রিমুভ বা ডাবল করতে চাই — stack হলো সবচেয়ে উপযুক্ত ডেটা স্ট্রাকচার এখানে।

🧮 উদাহরণ বিশ্লেষণ (Example: ["5","2","C","D","+"]) — ব্যাখ্যা সহ:
Step	Operation	Stack	Explanation
1	"5"	[5]	নতুন স্কোর 5 যোগ করলাম।
2	"2"	[5, 2]	নতুন স্কোর 2 যোগ করলাম।
3	"C"	[5]	আগের স্কোর (2) বাতিল করলাম।
4	"D"	[5, 10]	আগের স্কোর (5) ডাবল করে 10 যোগ করলাম।
5	"+"	[5, 10, 15]	আগের দুইটি স্কোর যোগফল 5+10 = 15 যোগ করলাম।

Final Sum = 5 + 10 + 15 = 30

✅ কোড বিশ্লেষণ (Line-by-Line Explanation in Bangla):
cpp
Copy
Edit
int calPoints(std::vector<std::string>& operations) 
{
    stack<int> st;        // রেকর্ড রাখার জন্য স্ট্যাক
    int sum = 0;          // শেষে যোগফল রাখবে

    for (int i = 0; i < operations.size(); i++) 
    {
        if (operations[i] == "C") 
        {
            if (!st.empty()) 
                st.pop();  // আগের স্কোর মুছে ফেলি
        } 
        else if (operations[i] == "D") 
        {
            if (!st.empty()) 
                st.push(2 * st.top()); // আগের স্কোরের ডাবল যোগ করি
        } 
        else if (operations[i] == "+") 
        {
            if (st.size() >= 2) 
            {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); 
                st.push(top1); // top1 আবার ফিরিয়ে দেই
                st.push(top1 + top2); // যোগফল যোগ করি
            }
        } 
        else 
        {
            // স্ট্রিং কে ইন্টেজারে রূপান্তর করি
            int val = std::stoi(operations[i]);
            // ভ্যালিড রেঞ্জ কিনা দেখি
            if (val >= -30000 && val <= 30000) 
                st.push(val); // স্কোর রেকর্ড করি
        }
    }

    // সব স্কোর যোগ করি
    while (!st.empty()) 
    {
        sum += st.top();
        st.pop();
    }

    return sum;
}
✅ কেন সলিউশন Accepted হয়েছে?
সব কন্ডিশন হ্যান্ডেল করা হয়েছে (C, D, +, integer)

স্ট্যাক ব্যবহার করে আগের স্কোরগুলো ট্র্যাক করা হয়েছে

ইনপুট রেঞ্জ অনুযায়ী নিরাপত্তা চেক রাখা হয়েছে (value check)

লজিক পুরোপুরি প্রশ্ন অনুসারে কাজ করছে

🧪 টেস্ট কেস দিয়ে যাচাই:
Input: ["5","2","C","D","+"]
Stack Steps: [5], [5,2], [5], [5,10], [5,10,15]

Final Sum = 5+10+15 = 30

Input: ["1","C"]
Stack: [1] → [] → sum = 0 ✅

🔁 ভবিষ্যতে কীভাবে বুঝবো?
প্রতিবার যখন প্রশ্নে "সদ্য আগের ভ্যালু নিয়ে কিছু করতে হবে" বলা থাকে, তখন stack চিন্তা করো।
এই প্রবলেমে C, D, + সবই আগের ভ্যালুগুলোর উপর ভিত্তি করে কাজ করছে, তাই stack ঠিকঠাক সমাধান।

📌 টেকঅ্যাও (Key Learnings):
✅ Stack ব্যবহার করলে আগের ইনফো সহজে পাওয়া যায়।

✅ ইনপুট হিসেবে অপারেশন গুলো স্ট্রিং আকারে আসলেও আমরা integer-এ রূপান্তর করে কাজ করতে পারি।

✅ Special operations গুলোতে অবশ্যই পূর্ববর্তী স্কোর আছে কিনা সেটা চেক করা দরকার।

Full Code:
-----------
#include <iostream>
#include <vector>
#include <stack>
class Solution 
{
public:
int calPoints(std::vector<std::string>& operations) 
{
   stack<int>st;
   int ans;
   int sum=0;
     for(int i=0;i<operations.size();i++)
   {
    if(operations[i]=="C")
    {
      if (!st.empty()) 
      st.pop();
    }
    else if(operations[i]=="D")
    {
      if(!st.empty())
      {
        st.push(2*st.top());
      }
    }
    else if(operations[i]=="+")
    {
   if(st.size()>=2)
   {
   int top1=st.top();
   st.pop();
   int top2=st.top();
   st.push(top1);
 int top3=top1+top2;
 st.push(top3);
 }
    }
   else
   {
    int val=std::stoi(operations[i]);
    if(val>=-30000&&val<=30000)
    {
      st.push(val);
    }
   }
   }
  while(!st.empty())
   {
    sum+=st.top();
    st.pop();
   }
 return sum;
}
};

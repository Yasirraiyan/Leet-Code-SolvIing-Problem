✅ প্রশ্নটা প্রথমে বুঝে নেওয়া (Understanding the Problem)
প্রশ্নটি:

🔸 তোমাকে একটি ইংরেজি বর্ণমালার অক্ষরের স্ট্রিং s দেওয়া হবে।
🔸 তোমার কাজ হচ্ছে এমন সবচেয়ে বড় অক্ষরটি (alphabet অনুযায়ী) খুঁজে বের করা, যেটি s স্ট্রিং-এ উভয়ভাবে (both uppercase and lowercase) আছে।
🔸 অর্থাৎ যদি 'A' ও 'a' দুইটাই থাকে, তাহলে সেটা valid candidate।
🔸 Return করতে হবে সেই অক্ষরটিকে Uppercase আকারে।
🔸 যদি এমন কোনো অক্ষর না থাকে, return "" (empty string)।

🎯 তোমার চিন্তার ধাপ (How You Thought the Approach)
প্রশ্ন পড়ার পর তোমার মাথায় যা এসেছে:

প্রথমে বুঝলে – আমাকে string-এর সব অক্ষর জানতে হবে, যেন আমি যাচাই করতে পারি কোন অক্ষর দুইভাবে আছে।

তাহলে আমি unordered_set<char> ব্যবহার করে O(1) time-এ অক্ষর পাওয়া যাবে।

তারপর স্ট্রিং এর প্রতিটা অক্ষরের জন্য tolower() এবং toupper() দিয়ে চেক করবো – দুইটিই যদি set-এ থাকে, তাহলে valid।

valid অক্ষরগুলোর মধ্যে থেকে alphabet অনুযায়ী সবচেয়ে বড়টা বের করতে হবে — এজন্য vector<char> এ রাখবো, পরে তার মধ্যে থেকে max বের করবো।

🔍 কোড লাইন-বাই-লাইন ব্যাখ্যা (Line-by-Line Explanation in Bangla)
cpp
Copy
Edit
unordered_set<char> set1;
🔸 একটি সেট নিচ্ছো যেখানে সব অক্ষর রাখবে। কেন? যেন খুব দ্রুত চেক করা যায় কোনো অক্ষর আছে কি না।

cpp
Copy
Edit
for(int i=0;i<s.size();i++)
{
    set1.insert(s[i]);
}
🔸 s এর প্রতিটা অক্ষরকে set1 এ রেখে দিচ্ছো।

উদাহরণ:
"lEeTcOdE" → set1 = {'l','E','e','T','c','O','d'}

cpp
Copy
Edit
vector<char> reserve;
🔸 এমন অক্ষর রাখবে যেগুলো ছোট ও বড় — দুই case-এই আছে।

cpp
Copy
Edit
for(int j=0;j<s.size();j++)
{ 
    char lower = tolower(s[j]);
    char upper = toupper(s[j]);

    if(set1.find(lower)!=set1.end() && set1.find(upper)!=set1.end())
    {
        reserve.push_back(upper);
    }
}
🔸 প্রতিটা অক্ষরের lower ও upper case বের করছো।
🔸 চেক করছো দুইটা কি set এ আছে?
🔸 যদি থাকে → তাহলে upper (output uppercase হবে তাই) → reserve এ রাখছো।

cpp
Copy
Edit
if (reserve.empty()) {
    return "";
}
🔸 যদি reserve খালি হয় → এমন অক্ষরই নেই → return ""

cpp
Copy
Edit
char max=reserve[0];
for(int k=1;k<reserve.size();k++)
{
    if(reserve[k]>max)
    {
        max=reserve[k];
    }
}
🔸 এখন reserve থেকে সবচেয়ে বড় অক্ষর খুঁজছো → যেটা alphabet অনুযায়ী সবচেয়ে পেছনে (Z সবচেয়ে বড়)।

cpp
Copy
Edit
string result="";
result+=max;
return result;
🔸 সবশেষে max কে string বানিয়ে return করছো।

🧪 উদাহরণ দিয়ে বিশ্লেষণ (Test Case Analysis in Bangla)
✅ উদাহরণ ১:
cpp
Copy
Edit
Input: "lEeTcOdE"
Set তৈরি: {'l','E','e','T','c','O','d'}
Valid pair: 'E' এবং 'e'
Reserve → ['E']
Max → 'E'
✅ Output: "E"

✅ উদাহরণ ২:
cpp
Copy
Edit
Input: "arRAzFif"
Set: {'a','r','R','A','z','F','i','f'}
Valid: A (a,A), R (r,R), F (f,F)
Reserve → ['A','R','F']
Max → 'R'
✅ Output: "R"

✅ উদাহরণ ৩:
cpp
Copy
Edit
Input: "AbCdEfGhIjK"
Set: সব অক্ষর একেকটা case এ আছে, pair নেই
Reserve → খালি
✅ Output: ""

Full Code:
------------

#include<vector>
#include<iostream>
#include<cctype>
#include<string>
using namespace std;
class Solution {
public:
    string greatestLetter(string s) 
    {
       unordered_set<char>set1;
       string ans="";
       vector<char>reserve;
       for(int i=0;i<s.size();i++)
       {
        set1.insert(s[i]);
       }
       for(int j=0;j<s.size();j++)
       { 
        char lower = tolower(s[j]);
            char upper = toupper(s[j]);
        //if(set1.find(tolower(s[j]))!=set1.end()&&set1.find(toupper(s[j]))!=set1.end())
       if(set1.find(lower)!=set1.end()&&set1.find(upper)!=set1.end())
        {
            reserve.push_back(upper);
        }
       }
        if (reserve.empty()) 
        {
            return "";
        }
       string result="";
       char max=reserve[0];
       for(int k=1;k<reserve.size();k++)
       {
        if(reserve[k]>max)
        {
          max=reserve[k];
        }
       }
       result+=max;
       return result;
    }
};

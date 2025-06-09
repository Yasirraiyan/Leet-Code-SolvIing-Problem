🔎 কীভাবে প্রশ্নটা পড়ে বুঝব এবং সেই অনুযায়ী সমাধান ভাবব?
🧠 Step-by-step Problem Analysis:
🔹 প্রশ্নে কী বলেছে?
তোমাকে একটি string s দেওয়া আছে যেটাতে শুধু এই ৬টি ক্যারেক্টার থাকবে:
👉 '(', ')', '{', '}', '[', ']'

তোমার কাজ হলো দেখতে —
এই ব্র্যাকেটগুলো সঠিকভাবে match এবং nest (অর্থাৎ ভিতরে ভিতরে) হয়েছে কিনা।

✅ Valid হলে কখন হবে?
প্রতিটা open bracket-এর একটা matching close bracket থাকতে হবে।

matching টা same type হতে হবে (যেমন ( এর সাথে )).

Brackets এর অর্ডার ঠিক থাকতে হবে।
যেমন:
👉 ([]) — Valid
❌ ([)] — Invalid (কারণ nesting ভুল)

🧠 এখন ভাবি, কোন Data Structure ব্যবহার করব?
এই ধরনের matching বা nesting problem এ সবসময় stack ব্যবহার করতে হয়। কারণ stack:

LIFO (Last In First Out) পদ্ধতিতে কাজ করে

প্রথমে যেটা খোলা হয়েছিল সেটা শেষে বন্ধ হবে — ঠিক ব্র্যাকেটের মতো।

🔧 এখন কোডটা line by line বুঝি (Bangla তে):
cpp
Copy
Edit
#include<stack>
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char>st;  // ব্র্যাকেট মেলানোর জন্য একটা stack তৈরি করলাম
        bool isvalid=true; // শুরুতে ধরে নিচ্ছি সবকিছু valid

        for(int i=0;i<s.size();i++)  // স্ট্রিংয়ের প্রতিটা ক্যারেক্টার ঘুরে দেখব
        {
            if(s[i]=='('||(s[i]=='{')||(s[i]=='[')) // যদি কোনো open bracket পাই
            {
                st.push(s[i]); // তাহলে stack এ রাখি
            }

            // যদি বন্ধ ব্র্যাকেট পাই এবং stack খালি না থাকে এবং top-এ মিল পাই
            else if (!st.empty()&&((s[i] == ')' && st.top() == '(') ||
                                   (s[i] == '}' && st.top() == '{') ||
                                   (s[i] == ']' && st.top() == '['))) 
            {
                st.pop(); // তাহলে top থেকে open bracket টা মুছে ফেলি
            }

            else  // না মিললে, বা stack খালি থাকলে invalid
            {
                isvalid=false;
                break;  // আর চেক করার দরকার নেই
            }
        }

        // সবকিছু দেখে শেষেও যদি কিছু রয়ে যায় stack এ, তাহলে invalid
        if(!st.empty())
        {
            isvalid=false;
        }

        return isvalid; // শেষে valid কিনা তা return করি
    }
};
🧪 উদাহরণ দিয়ে চলো বুঝি
Example 1:
text
Copy
Edit
Input: "()"
Stack:
push('(')
')' দেখে '(' pop হয় ✅
stack খালি ✅
Result: true
Example 2:
text
Copy
Edit
Input: "()[]{}"
All open bracket → push  
Then matching close → pop  
সব মিলেছে ✅  
Result: true
Example 3:
text
Copy
Edit
Input: "(]"
push('(')  
']' দেখে top = '(', মেলে না ❌  
Result: false
Example 4:
text
Copy
Edit
Input: "([])"
push('(')  
push('[')  
']' দেখে '[' মিলে যায় → pop  
')' দেখে '(' মিলে যায় → pop  
stack খালি ✅  
Result: true
🔁 ভবিষ্যতে কীভাবে মনে রাখবে?
যখনই ব্র্যাকেট/ট্যাগ/নেস্টিং এর problem পাবে, stack use করো।

Open → push

Close → top দেখে match হলে pop, না হলে invalid

শেষে stack খালি → valid

✅ সংক্ষেপে বুঝে রাখো:
ধাপ	ব্যাখ্যা
Stack তৈরি	সব open bracket রাখার জন্য
Traverse	এক এক করে string এর প্রতিটি ক্যারেক্টার চেক করো
Push	যদি open bracket হয়
Pop	যদি close bracket হয় এবং top এ match থাকে
Invalid	যদি mismatch হয় বা stack খালি হয়ে যায়
শেষ চেক	সব শেষে যদি stack খালি না থাকে, invalid

  Full Code:
------------
  #include<stack>
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char>st;
        bool isvalid=true;
         for(int i=0;i<s.size();i++)
        {
          if(s[i]=='('||(s[i]=='{')||(s[i]=='['))
          {
            st.push(s[i]);
          }
       else if (!st.empty()&&((s[i] == ')' && st.top() == '(') ||  (s[i] == '}' && st.top() == '{') ||(s[i] == ']' && st.top() == '['))) 
    {
     st.pop();
}
  else
  {
    isvalid=false;
    break;
  }
  }
  if(!st.empty())
  {
    isvalid=false;
  }
  return isvalid;
 }
};

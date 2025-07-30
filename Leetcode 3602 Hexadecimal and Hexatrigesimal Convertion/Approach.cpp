🔍 প্রশ্ন বিশ্লেষণ (Understanding the Question)
তোমাকে একটি পূর্ণসংখ্যা n দেওয়া হবে।
তুমি দুটি কাজ করবে:

n² কে Hexadecimal (base-16) ফরম্যাটে রূপান্তর করবে।

n³ কে Hexatrigesimal (base-36) ফরম্যাটে রূপান্তর করবে।

তারপর দুটি রূপান্তরিত string কে জোড়া দিবে এবং return করবে।

✅ উদাহরণ ব্যাখ্যা
Example 1:

vbnet
Copy
Edit
Input: n = 13
n² = 169 → hexadecimal = A9
n³ = 2197 → hexatrigesimal = 1P1
Output: "A91P1"
Example 2:

yaml
Copy
Edit
Input: n = 36
n² = 1296 → hexadecimal = 510
n³ = 46656 → hexatrigesimal = 1000
Output: "5101000"
🧠 কীভাবে সমাধান ভাববে (Thinking the Approach)
প্রশ্ন দেখে প্রথমেই বুঝবে, এখানে দুটো base conversion করতে হবে:

Base 10 থেকে Base 16

Base 10 থেকে Base 36

তাই তুমি নিচেরভাবে ভাবতে পারো:

n² বের করো, তারপর সেটাকে Hexadecimal বানাও।

n³ বের করো, তারপর সেটাকে Base 36 বানাও।

তারপর দুইটার Concatenation return করো।

তোমার কোডে এই তিনটি স্টেপ সুন্দরভাবে আলাদা করে লেখা আছে।

🧪 Code Explanation Line by Line (Bangla)
cpp
Copy
Edit
class Solution {
public:
এই লাইনে Solution নামে একটা ক্লাস শুরু হলো।

🔸 Hexadecimal Converter Function: hexdec
cpp
Copy
Edit
string hexdec(int n)
{
    string ans = "";
    while(n > 0)
    {
        int rem = n % 16;
n কে 16 দিয়ে ভাগ করে রিমাইন্ডার বের করছো — অর্থাৎ বর্তমান digit।

cpp
Copy
Edit
        if(rem < 10)
        {
            ans += to_string(rem); // 0-9 এর জন্য
        }
যদি রিমাইন্ডার 0 থেকে 9 হয়, সরাসরি সংখ্যা যোগ করো।

cpp
Copy
Edit
        if(rem >= 10 && rem <= 15)
        {
            ans += char('A' + (rem - 10)); // 10=A, 11=B, ..., 15=F
        }
যদি রিমাইন্ডার 10-15 হয়, তাহলে 'A' থেকে শুরু করে লেটার যোগ করো।

cpp
Copy
Edit
        n = n / 16;
    }
    reverse(ans.begin(), ans.end()); // কারণ আমরা রিভার্স অর্ডারে পেয়েছি
    return ans;
}
শেষে রিভার্স করে সঠিক অর্ডারে রিটার্ন করো।

🔸 Base-36 Converter Function: hextri
cpp
Copy
Edit
string hextri(int n)
{
    string ans = "";
    while(n > 0)
    {
        int rem = n % 36;
এবার 36 দিয়ে ভাগ করে রিমাইন্ডার বের করো।

cpp
Copy
Edit
        if(rem < 10)
        {
            ans += to_string(rem);
        }
        if(rem >= 10 && rem <= 35)
        {
            ans += char('A' + (rem - 10)); // 10=A, ..., 35=Z
        }
এখানেও একইভাবে রিমাইন্ডার 0-9 হলে সংখ্যা, আর 10-35 হলে A-Z যোগ করো।

cpp
Copy
Edit
        n = n / 36;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
শেষে রিভার্স করে return করো।

🔸 Main Function: concatHex36
cpp
Copy
Edit
string concatHex36(int n) 
{
    long long a = n * n;
    long long b = n * n * n;
n² এবং n³ হিসাব করো। long long নিচ্ছো যাতে overflow না হয়।

cpp
Copy
Edit
    string s1 = hexdec(a);  // hexadecimal string
    string s2 = hextri(b);  // base-36 string
দুটো converter function কল করো।

cpp
Copy
Edit
    string ans = s1 + s2;  // concatenate
    return ans;
}
শেষে একসাথে যোগ করে উত্তর return করো।

🧪 টেস্ট কেস দিয়ে চেক করি
✅ Input: n = 13
cpp
Copy
Edit
n² = 169 → hexdec(169) = "A9"
n³ = 2197 → hextri(2197) = "1P1"
Result: A91P1
✅ Input: n = 36
cpp
Copy
Edit
n² = 1296 → hexdec(1296) = "510"
n³ = 46656 → hextri(46656) = "1000"
Result: 5101000
🟢 Time & Space Complexity:
hexdec = O(log₁₆(n²)) = O(log n)

hextri = O(log₃₆(n³)) = O(log n)

So, total time = O(log n)

Space: O(log n) for each string

✅ কেনো কোড Accept হয়েছে?
তুমি base conversion এর জন্য সঠিক লজিক লিখেছো।

String concatenation ঠিকমতো করেছো।

Edge case (e.g. 0, 1) বাদে সব কেস কভার করেছে।

Full Code:
-----------

  class Solution {
public:
 string hexdec(int n)
 {
    string ans="";
    while(n>0)
    {
      int rem=n%16;
      if(rem<10)
      {
        ans+=to_string(rem);
      }
      if(rem>=10&&rem<=15)
      {
        ans+=char('A'+(rem-10));
      }
      n=n/16;
    }
    reverse(ans.begin(), ans.end());
    return ans;
 }
 string hextri(int n)
 {
   string ans="";
    while(n>0)
    {
      int rem=n%36;
      if(rem<10)
      {
        ans+=to_string(rem);
      }
      if(rem>=10&&rem<=35)
      {
        ans+=char('A'+(rem-10));
      }
      n=n/36;
    }
    reverse(ans.begin(), ans.end());
    return ans;
 }
    string concatHex36(int n) 
    {
        long long a=n*n;
        long long b=n*n*n;
        string s1=hexdec(a);
        string s2=hextri(b);
        string ans=s1+s2;
        return ans;
    }
};

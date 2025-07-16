🔍 সমস্যা বুঝি:
তোমাকে এমন একটি পূর্ণসংখ্যা x দেওয়া হবে, এবং তোমার কাজ হলো:

তার বর্গমূল (square root) বের করা

কিন্তু দশমিক নয়, বরং নীচের দিকে রাউন্ড করা পূর্ণসংখ্যা রিটার্ন করতে হবে

এবং কোনো sqrt, pow, x ** 0.5 এরকম ফাংশন/অপারেটর ব্যবহার করা যাবে না।

✅ কোড লজিক (Binary Search):
আমরা জানি, sqrt(x) এর মান সর্বোচ্চ x পর্যন্ত হতে পারে (যেমন sqrt(9) = 3, কিন্তু তার range 1 থেকে 9 এর ভিতরে)।

আমরা Binary Search ব্যবহার করবো এই রেঞ্জে (1 থেকে x) এই চেক করতে করতে যে কোন সংখ্যার square করলে x এর সমান হয় বা কম হয়।

🔍 কোড ব্যাখ্যা লাইন বাই লাইন:
cpp
Copy
Edit
class Solution 
{
public:
    int mySqrt(int x) 
    {
একটা ক্লাস Solution বানানো হয়েছে যেখানে ফাংশন mySqrt আছে, যা int x ইনপুট নেয় এবং তার স্কয়ার রুট রিটার্ন করে।

cpp
Copy
Edit
        int ans;
        long long high = x;
        long long low = 1;
ans ভেরিয়েবলটা স্কয়ার রুট হিসাবে ধরে রাখা হবে।

low = 1 থেকে শুরু করে high = x পর্যন্ত Binary Search চালানো হবে।

long long ব্যবহার করা হয়েছে যেন mid * mid করলে overflow না হয়।

cpp
Copy
Edit
        if(x == 0) return 0;
যদি ইনপুট x = 0 হয় তাহলে স্কয়ার রুট 0 হয়, সরাসরি রিটার্ন করে।

cpp
Copy
Edit
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
Binary Search এর স্ট্যান্ডার্ড ফর্মুলা mid = low + (high - low)/2।

cpp
Copy
Edit
            if(mid * mid < x)
            {
                ans = (int)mid;
                low = mid + 1;
            }
যদি mid^2 < x হয়, তাহলে mid হতে পারে স্কয়ার রুট অথবা আরো বড় সংখ্যাও হতে পারে।
তাই ans আপডেট করি এবং ডান পাশে খুঁজি low = mid + 1 করে।

cpp
Copy
Edit
            else if(mid * mid == x)
            {
                ans = (int)mid;
                break;
            }
যদি একদম mid^2 == x হয়, তাহলে perfect square। ans সেট করে লুপ ব্রেক করি।

cpp
Copy
Edit
            else
            {
                high = mid - 1;
            }
যদি mid^2 > x হয়, তাহলে বড় হয়ে যাচ্ছে, তাই high কমিয়ে ছোট রেঞ্জ দেখি।

cpp
Copy
Edit
        }
        return ans;
    }
};
লুপ শেষে ans রিটার্ন করি।

📘 Test Case 1: x = 4
makefile
Copy
Edit
Initial: low = 1, high = 4

1st iteration:
mid = (1 + 4) / 2 = 2
2^2 = 4 == x → perfect match
ans = 2, break

Return: 2
📘 Test Case 2: x = 8
vbnet
Copy
Edit
Initial: low = 1, high = 8

1st iteration:
mid = 4 → 4^2 = 16 > 8 → high = 3

2nd iteration:
mid = 2 → 2^2 = 4 < 8 → ans = 2, low = 3

3rd iteration:
mid = 3 → 3^2 = 9 > 8 → high = 2

=> Loop ends, return ans = 2
🤔 কেন Accepted হলো?
Time Complexity: O(log x) → Binary Search হওয়ার কারণে।

No Built-in Function Used → problem constraint মানা হয়েছে।

Handles Large Values Safely → long long ব্যবহার করা হয়েছে mid * mid overflow এড়াতে।

🧠 তুমি কীভাবে সমাধান ভাববে?
x এর স্কয়ার রুট মানে এমন একটি সংখ্যা যার বর্গ x এর সমান বা তার কম।

Binary Search হলো এমন একটি efficient পদ্ধতি যা sorted range এ apply করা যায়। এখানে আমরা 1 থেকে x range ধরে Binary Search করবো।

আমরা যখনই mid * mid <= x পাই, সেটিকে potential উত্তর হিসাবে রাখি।

Binary Search এ left/right এ move করার মূল strategy হলো:

mid² < x	mid² > x	mid² == x
উত্তর হতে পারে, ডানদিকে যাই	বড় হয়ে গেছে, বামদিকে যাই	perfect উত্তর, রিটার্ন করি

Test Code:
-----------

  🔢 Test Input:
cpp
Copy
Edit
x = 8
🧪 Code with Line-by-Line Execution:
cpp
Copy
Edit
class Solution 
{
public:
    int mySqrt(int x) 
    {
🔸 ক্লাস Solution এর মধ্যে mySqrt ফাংশন শুরু। x = 8 পাঠানো হয়েছে।

cpp
Copy
Edit
        int ans;
        long long high = x;     // high = 8
        long long low = 1;      // low = 1
🔸 আমরা Binary Search এর জন্য low = 1 এবং high = 8 নিলাম।
🔸 ans কোনো মান রাখার জন্য ব্যবহার করবো।

cpp
Copy
Edit
        if(x == 0) return 0;
🔸 x = 8 তাই এই লাইন স্কিপ।

cpp
Copy
Edit
        while(low <= high)
🔸 প্রথমবার: low = 1, high = 8 → শর্ত সত্য → লুপে ঢুকবো।

🔁 1st Iteration:
cpp
Copy
Edit
long long mid = low + (high - low) / 2;
// mid = 1 + (8 - 1) / 2 = 1 + 3 = 4
cpp
Copy
Edit
if(mid * mid < x)
🔸 mid = 4, তাই mid * mid = 16
🔸 16 > 8 → এই শর্ত false

cpp
Copy
Edit
else if(mid * mid == x)
🔸 16 != 8 → false

cpp
Copy
Edit
else
{
    high = mid - 1;   // high = 4 - 1 = 3
}
🔸 এবার high ছোট করে দিলাম।

🔁 2nd Iteration:
cpp
Copy
Edit
low = 1, high = 3
mid = 1 + (3 - 1)/2 = 1 + 1 = 2
cpp
Copy
Edit
if(mid * mid < x) → 2*2 = 4 < 8 → true
🔸 ans = 2, কারণ 2 হয়তো আমাদের উত্তর।
🔸 low = mid + 1 = 3

cpp
Copy
Edit
ans = (int)mid;   // ans = 2
low = mid + 1;    // low = 3
🔁 3rd Iteration:
cpp
Copy
Edit
low = 3, high = 3
mid = 3 + (3 - 3)/2 = 3
cpp
Copy
Edit
if(mid * mid < x) → 3*3 = 9 < 8 → false
cpp
Copy
Edit
else if(mid * mid == x) → 9 == 8 → false
cpp
Copy
Edit
else
{
    high = mid - 1 = 2
}
🛑 End of Loop:
cpp
Copy
Edit
while(low <= high) → 3 <= 2 → false
🔸 লুপ শেষ। এখন ans = 2

cpp
Copy
Edit
return ans;
✅ Final Output:
makefile
Copy
Edit
Output: 2
Explanation: sqrt(8) ≈ 2.828 → নিচের দিক থেকে পূর্ণসংখ্যায় রাউন্ড করলে 2
🔎 Step-by-Step Variable Table
Iteration	low	high	mid	mid²	Action	ans
1	1	8	4	16	high = mid - 1	—
2	1	3	2	4	ans = mid, low++	2
3	3	3	3	9	high = mid - 1	2
Exit	3	2	—	—	loop ends	2

🧪 Extra Test: x = 0
cpp
Copy
Edit
if(x == 0) return 0;
→ একদম শুরুতেই return 0 করে দিবে।

🧪 Extra Test: x = 4
cpp
Copy
Edit
low = 1, high = 4
mid = 2 → 2*2 = 4 → match → return 2


  Full Code:
------------

 class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        long long low=0;
        long long  high=num;
       long long mid;
        bool isperfect=false;
        if(num==0) return 0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(mid*mid==num)
            {
             isperfect=true;
             break;
            }
          else  if(mid*mid>num)
            {
             high=mid-1;
            }
            else
            {
            low=mid+1;
            }
        }
        return isperfect;
    }
};

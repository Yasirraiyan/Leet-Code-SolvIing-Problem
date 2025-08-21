🔹 API কী?

👉 API (Application Programming Interface) হচ্ছে একটা function / method যেটা আমরা সরাসরি লিখিনি, বরং আমাদের জন্য আগে থেকেই তৈরি করে দেওয়া হয়েছে। আমরা শুধু এটাকে call করি, আর result পাই।

এই সমস্যায় আমাদের জন্য একটা API দেওয়া আছে:

int guess(int num);
এটা একটা সংখ্যা (num) নেয়, তারপর তিনটা অবস্থার মধ্যে একটা রিটার্ন করে:

-1 → যদি num আমাদের গেস করা সংখ্যার থেকে বড় হয়

1 → যদি num আমাদের গেস করা সংখ্যার থেকে ছোট হয়

0 → যদি num ঠিক সঠিক হয়

🔹 সাধারণ থিওরি (Common Theory)
আমরা 1 থেকে n এর মধ্যে একটা সংখ্যা বাছাই করি।

আমরা API-কে একটা guess(num) কল দিয়ে বলি:

যদি API বলে -1, তার মানে আমরা বেশি বড় গেস করেছি → আমাদের ছোট দিকে (left) খুঁজতে হবে।

যদি API বলে 1, তার মানে আমরা কম গেস করেছি → আমাদের ডান দিকে (right) খুঁজতে হবে।

যদি API বলে 0, তার মানে আমরা সঠিক সংখ্যাটা পেয়ে গেছি।

এইভাবে আমরা Binary Search ব্যবহার করি → প্রতিবার মাঝখানের সংখ্যা (mid) চেক করি, আর API অনুযায়ী search range ছোট করি।

🔹 তোমার দেওয়া কোডের ব্যাখ্যা (Line by Line)
cpp
Copy
Edit
class Solution 
{
public:
    int guessNumber(int n) 
    {
        int low=0;          // search শুরু হবে 0 থেকে
        int high=n;         // শেষ হবে n এ
        int mid;            // মধ্যবিন্দু রাখার জন্য
👉 এখানে আমরা শুরুতে সার্চের range [0, n] ধরে নিয়েছি।

cpp
Copy
Edit
        while(low<=high)    // যতক্ষণ পর্যন্ত range valid থাকে
        {
            int mid=low+(high-low)/2;  // মাঝের সংখ্যা বের করলাম
            int res=guess(mid);        // API কে কল করে result আনলাম
👉 এখানে mid বের করা হচ্ছে আর সেই mid কে API-তে পাঠানো হচ্ছে। API আমাদের বলবে mid ছোট, বড় নাকি ঠিক।

cpp
Copy
Edit
            if(-1==res) 
            {
                high=mid-1;  // mid বড় হয়ে গেছে → high কে ছোট করলাম
            }
            else if(1==res)
            {
                low=mid+1;   // mid ছোট হয়ে গেছে → low কে বড় করলাম
            }
            else if(res==0) 
                return mid; // mid ঠিক হয়ে গেছে → answer পেয়ে গেছি
👉 এখানে তিনটা কন্ডিশন চেক করা হচ্ছে। API যে অনুযায়ী result দেয়, সে অনুযায়ী low আর high আপডেট হয়।

cpp
Copy
Edit
        }
        return low;   // fallback (normally এখানে আসবে না, কারণ mid পাওয়ার আগেই return হয়ে যাবে)
    }
};
🔹 উদাহরণ (Example Walkthrough)
ধরো, n = 10 এবং number হচ্ছে 6।

প্রথমে low=0, high=10 → mid=5

guess(5) → API রিটার্ন করে 1 (কারণ 5 < 6)

তাই আমরা বলি low=6

এবার low=6, high=10 → mid=8

guess(8) → API রিটার্ন করে -1 (কারণ 8 > 6)

তাই আমরা বলি high=7

এবার low=6, high=7 → mid=6

guess(6) → API রিটার্ন করে 0

সঠিক answer পাওয়া গেল → return 6

✅ এভাবে API শুধু আমাদেরকে বলে দেয় → আমরা সঠিক পথে যাচ্ছি নাকি উল্টা পথে। আর Binary Search ব্যবহার করে আমরা দ্রুত সঠিক সংখ্যা বের করে ফেলি।

কিভাবে ভাববো (Problem → Idea)

আমাদের কাছে isBadVersion(x) একটা মনোটনিক ফাংশন:
1..good, good, ..., good, bad, bad, ..., bad..n
মানে কোনো একটা পজিশন firstBad থেকে পরের সবই bad।

মনোটনিক বুলিয়ান অ্যারের boundary খুঁজতে সবচেয়ে কম কলে সমাধান = Binary Search।
কারণ প্রত্যেক ধাপে সার্চ স্পেস অর্ধেকে নেমে আসে → API কল O(log n)।

মূল আইডিয়া (Binary Search Boundary)

একটা রেঞ্জ রাখি: low = 1, high = n

mid দেখবো:

যদি isBadVersion(mid) == true → প্রথম bad mid-এর বাম পাশে বা mid-এই আছে → high = mid - 1

যদি false → প্রথম bad mid-এর ডান পাশে → low = mid + 1

লুপ শেষ হলে low হবে first bad version।

ইনভ্যারিয়েন্ট (প্রমাণের intuition):
প্রতিটা স্টেপে আমরা নিশ্চিত করি:

1..low-1 সবগুলো confirmed good

high+1..n সবগুলো confirmed bad
লুপ থামে যখন low > high ⇒ ঠিক সেই “সীমান্ত” পয়েন্টটাই low, আর যেহেতু low > high, তাই low “confirmed bad” সাইডে পড়ে ⇒ low = first bad।

তোমার কোড (C++) — লাইন-বাই-লাইন ব্যাখ্যা
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int low=1;              // সার্চ রেঞ্জের শুরু
        int high=n;             // সার্চ রেঞ্জের শেষ

        if(n==1) return n;      // n==1 হলে 1-ই উত্তর (এটা আসলে অতিরিক্ত; না দিলেও ঠিক কাজ করবে)

        while(low<=high)        // ক্লাসিক বাইনারি সার্চ on a closed interval [low, high]
        {
            int mid=low+(high-low)/2;   // overflow-safe mid

            if(isBadVersion(mid))       // mid bad হলে boundary বামে বা mid-এই
            {
                high=mid-1;             // তাই ডান দিক ছোটাই (mid বাদ দিয়ে)
            }
            else                        // mid good হলে boundary ডান দিকে
            {
                low=mid+1;              // তাই বাম দিক বড়াই (mid বাদ দিয়ে)
            }
        }
        return low;              // লুপ শেষে low = first bad version
    }
};


ছোট টিউন-আপ: if(n==1) return n; এই লাইনটা না থাকলেও লজিক ঠিক কাজ করে। while-এর ভেতরেই কেস কভার হয়ে যায়।

ড্রাই-রান (Test-by-test)
Example 1

Input: n = 5, bad = 4

শুরু: low=1, high=5

mid = 1 + (5-1)/2 = 3 → isBadVersion(3)=false → low=4, high=5

mid = 4 + (5-4)/2 = 4 → isBadVersion(4)=true → low=4, high=3

low(4) > high(3) ⇒ লুপ শেষ → return 4 ✅

Example 2

Input: n = 1, bad = 1

শুরু: low=1, high=1

mid = 1 → isBadVersion(1)=true → high=0

low(1) > high(0) ⇒ return 1 ✅

Edge Case A: n = 2, bad = 1

low=1, high=2

mid=1 → bad → high=0

end → return 1 ✅

Edge Case B: n = 2, bad = 2

low=1, high=2

mid=1 → good → low=2

mid=2 → bad → high=1

end → return 2 ✅

Random Case: n = 7, bad = 5

low=1, high=7

mid=4 → good → low=5, high=7

mid=6 → bad → low=5, high=5

mid=5 → bad → low=5, high=4

end → return 5 ✅

সব কেসেই boundary ঠিকঠাক ধরা পড়ছে।

কেন এটা Accepted (Complexity & Calls)

API calls: প্রতি ইটারেশনে ১টা isBadVersion কল ⇒ সর্বোচ্চ ~⌈log2(n)⌉ কল।

Time: O(log n)

Space: O(1)


Full Code:
---------------

  // The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int low=1;
        int high=n;
        if(n==1) return n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isBadVersion(mid))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};

mid ক্যালকুলেশন overflow-safe (low+(high-low)/2) ⇒ বড় n (যেমন 2^31-1) হলেও সেফ।

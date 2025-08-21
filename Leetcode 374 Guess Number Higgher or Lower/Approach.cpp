ভাবনা (Approach) — কেন বাইনারি সার্চ?

সংখ্যাটা 1..n রেঞ্জে আছে।

আপনি যখনই একটা guess করবেন, API বলে দেয় বড় না ছোট—মানে বর্তমান রেঞ্জটা দুইভাগে ভাগ হয়ে যায়।

যেটা ক্লাসিক Binary Search সিচুয়ারি:

guess(mid) == 0 হলে ঠিক সংখ্যাই পেয়েছি → return mid

guess(mid) == -1 (আমার guess বড় হয়েছে) → আসল সংখ্যা mid-1 এর ভেতরে → high = mid - 1

guess(mid) == 1 (আমার guess ছোট হয়েছে) → আসল সংখ্যা mid+1 এর পরে → low = mid + 1

Complexity: প্রতি ধাপে রেঞ্জ অর্ধেক হয় ⇒ O(log n) টাইম, O(1) স্পেস।

লাইনে-লাইনে কী হচ্ছে? (আপনার মূল কোডের ব্যাখ্যা)
class Solution 
{
public:
    int guessNumber(int n) 
    {
        int low=0;            // আপনি 0 থেকে শুরু করেছেন; সাধারণত 1 দেওয়া নিরাপদ/পরিস্কার।
        int high=n;
        int mid;
        while(low<=high)      // রেঞ্জ শেষ না হওয়া পর্যন্ত
        {
            int mid=low+(high-low)/2;   // overflow-safe mid
            int res=guess(mid);         // API-র ফিডব্যাক নিলাম

            if(-1==res)                 // আমার guess বড় → high কমবে
            {
                high=mid-1;
            }
            else if(1==res)             // আমার guess ছোট → low বাড়বে
            {
                low=mid+1;
            }
            else if(res==0) return mid; // মিল পেয়ে গেছি → ফিরিয়ে দেই
        }
        return low; // আপনার কোডে সেফটি হিসেবে low ফিরিয়েছেন; আমাদের ক্লিন ভার্সনে
                    // লুপেই return হয়ে যায়, না হলে -1 দেবো।
    }
};

কেন এই সমাধান Accepted হয়?

সঠিকতা: প্রতিবার সঠিক দিকে রেঞ্জ সংকুচিত করি (API higher/lower বলে দেয়)।

টার্মিনেশন গ্যারান্টি: low বাড়ে বা high কমে—সুতরাং একসময় guess(mid)==0 হবে।

Overflow সেফ: mid = low + (high-low)/2 ব্যবহার।

জটিলতা: O(log n) — বড় n এর জন্য খুবই কার্যকর।

টেস্ট কেসে ধাপে ধাপে (Dry Run)
Example 1

Input: n=10, pick=6
শুরু: low=1, high=10

Step 1: mid=(1+10)/2=5 → guess(5)=1 (ছোট) → low=6

Step 2: mid=(6+10)/2=8 → guess(8)=-1 (বড়) → high=7

Step 3: mid=(6+7)/2=6 → guess(6)=0 → return 6

Example 2

Input: n=1, pick=1
শুরু: low=1, high=1

Step 1: mid=1 → guess(1)=0 → return 1

Example 3

Input: n=2, pick=1
শুরু: low=1, high=2

Step 1: mid=(1+2)/2=1 → guess(1)=0 → return 1

(অতিরিক্ত) Worst-edge চিন্তা: n=2^31-1, pick=n

রেঞ্জ ডানদিকে সরে সরে যাবে; প্রতিবার guess(mid)=1 হবে, low বাড়বে।


Full Code;
------------

  /** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    int guessNumber(int n) 
    {
        int low=0;
        int high=n;
        int mid;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int res=guess(mid);
            if(-1==res) 
            {
            high=mid-1;
            }
           else if(1==res)
           {
            low=mid+1;
           }
            else if(res==0) return mid;
           
        }
        return low;
    }
};

O(log n) ধাপে গিয়ে অবশেষে mid==pick এ পৌঁছে যাবে।

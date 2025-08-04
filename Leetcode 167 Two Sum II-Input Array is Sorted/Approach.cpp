সমস্যা সংক্ষিপ্ত পরিচিতি:
তোমাকে একটি সোজা সাজানো (sorted) অ্যারে দেওয়া আছে, যেখানে ইনডেক্স ১ থেকে শুরু হয় (1-indexed)। তোমার কাজ হলো দুটি এমন সংখ্যার ইনডেক্স (index1, index2) বের করা যাদের যোগফল দেওয়া লক্ষ্য (target) এর সমান।
শর্ত:

index1 < index2

একটি সংখ্যা দুইবার ব্যবহার করা যাবে না

সমাধান একটাই নিশ্চিত করা আছে

অতিরিক্ত স্পেস O(1) হতে হবে (অর্থাৎ শুধু কয়েকটা ভেরিয়েবল ব্যবহার করবে, অতিরিক্ত কোনো বড় ডাটা স্ট্রাকচার ব্যবহার যাবে না)

কোড (Solution):
cpp
Copy
Edit
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans;
        while (left <= right)
        {
            if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if (numbers[left] + numbers[right] == target)
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
বিস্তারিত ব্যাখ্যা - ধাপে ধাপে (Bangla):
১. টেকনিক: Two Pointers (দুইটি সূচক)
অ্যারে sorted (সাজানো) থাকায় আমরা দুইপয়েন্টার পদ্ধতি ব্যবহার করতে পারি।

দুইটি সূচক — left (শুরুর দিকে) আর right (শেষের দিকে) — দিয়ে শুরু করি।

২. কেন Two Pointers?
কারণ অ্যারে সাজানো, তাই numbers[left] ছোট বা সমান, আর numbers[right] বড় বা সমান।

যদি তাদের যোগফল target থেকে ছোট হয়, তাহলে আমরা জানি left এর মান বাড়ালে (একটা ডানে সরে) যোগফল বাড়বে।

যদি যোগফল বেশি হয়, তাহলে right কে বাম দিকে সরালে যোগফল কমবে।

এই পদ্ধতিতে আমরা লিনিয়ার টাইমে (O(n)) সমাধান পেতে পারি।

৩. কোড লাইন বাই লাইন ব্যাখ্যা:
int left = 0;
শুরুতে left পয়েন্টার অ্যারের প্রথম উপাদানে (0-ভিত্তিক ইনডেক্স)।

int right = numbers.size() - 1;
আর right পয়েন্টার শেষ উপাদানে।

vector<int> ans;
ফলাফল সংরক্ষণের জন্য খালি ভেক্টর।

while (left <= right)
যতক্ষণ left এবং right পয়েন্টার পারস্পরিক অতিক্রম করেনি (left ≤ right)।

৪. লুপের ভিতরের কাজ:
if (numbers[left] + numbers[right] < target)
যদি দুই সংখ্যার যোগফল টার্গেটের থেকে ছোট হয়, অর্থাৎ যোগফল বাড়াতে হবে, তাই left কে এক ধাপ ডানে নিয়ে যাই (left++), যেন বড় সংখ্যা আসতে পারে।

else if (numbers[left] + numbers[right] == target)
যদি যোগফল ঠিক টার্গেট হয়, তাহলে কাজ শেষ!
ইনডেক্স ১ থেকে শুরু তাই left+1 এবং right+1 রেজাল্টে পুশ করি।
এরপর লুপ ব্রেক করি।

else (অর্থাৎ যোগফল টার্গেট থেকে বেশি)
তাহলে যোগফল কমাতে হবে, তাই right কে এক ধাপ বামে সরাই (right--).

৫. লুপ শেষ হলে:
return ans;
ফলাফল রিটার্ন করি যা দুটি ইনডেক্স ধারণ করে।

টেস্ট কেস দিয়ে ব্যাখ্যা (Line by line):
উদাহরণ ১:
Input: numbers = [2,7,11,15], target = 9

left = 0 (value=2), right = 3 (value=15)

2 + 15 = 17 > 9 → right-- (right=2)

left=0 (2), right=2 (11)

2 + 11 = 13 > 9 → right-- (right=1)

left=0 (2), right=1 (7)

2 + 7 = 9 == target → push (0+1=1), (1+1=2) → break
Output: [1, 2]

উদাহরণ ২:
Input: numbers = [2,3,4], target = 6

left=0 (2), right=2 (4)

2 + 4 = 6 == target → push (1, 3), break
Output: [1, 3]

উদাহরণ ৩:
Input: numbers = [-1, 0], target = -1

left=0 (-1), right=1 (0)

-1 + 0 = -1 == target → push (1, 2), break
Output: [1, 2]

কেন accepted? (কারণ):
সঠিকতা (Correctness):

দুই pointer পদ্ধতি sorted array তে সঠিকভাবে কাজ করে।

একবারে একটি সঠিক জোড়া খুঁজে পাওয়া নিশ্চিত (because test data guarantee one solution)।

কার্যকারিতা (Efficiency):

টাইম কমপ্লেক্সিটি O(n), যেখানে n = numbers.size()।

স্পেস কমপ্লেক্সিটি O(1), শুধুমাত্র দুই পয়েন্টার আর রেজাল্ট vector।

অন্যান্য শর্ত পূরণ:

একই উপাদান একাধিকবার ব্যবহার করা হয় না।

ইনডেক্স ১ থেকে শুরু হওয়া রিটার্ন (left+1, right+1) ঠিকভাবে দেয়া হয়েছে।

কোড লেখার চিন্তা ধারা:
প্রথমে বুঝতে হবে ইনপুট অ্যারে sorted → two pointers সহজ।

দুই দিক থেকে সূচক রেখে, যোগফল কম/বেশি হলে সামঞ্জস্য করতে হবে।

লক্ষ্য যোগফল পাওয়া মাত্র সূচক গুলো রিটার্ন করতে হবে।

ইনডেক্স ১ থেকে শুরু হওয়ার কথা মাথায় রেখে সূচক +1 করা দরকার।

অপ্রয়োজনীয় জায়গায় অতিরিক্ত স্পেস বা ডাটা স্ট্রাকচার এড়ানো।

সারমর্ম:
Two pointers technique ব্যবহার করে আমরা sorted array তে O(n) সময়ে যোগফল target এর সাথে মিলিয়ে দুটি সংখ্যার ইনডেক্স খুঁজে পাই।
left ও right পয়েন্টার প্রয়োগ করে কমপ্লেক্সিটি কম রাখি এবং কোন অতিরিক্ত স্পেস ব্যবহার করি না।
কোডে while লুপে প্রতিবার যোগফল দেখে পয়েন্টার সরিয়ে, অবশেষে সঠিক জোড়া পেয়ে রিটার্ন করি।
সব টেস্ট কেসে সফল হওয়ার কারণ হলো — সম্পূর্ণ নিশ্চিত মাত্র একটি সমাধান, এবং two pointers পদ্ধতির সরলতা ও কার্যকারিতা।

Full Code:
-----------

  class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left=0;
        int right=numbers.size()-1;
        vector<int>ans;
        while(left<=right)
        {
          if(numbers[left]+numbers[right]<target)
          {
            left++;
          }
         else  if(numbers[left]+numbers[right]==target)
          {
            ans.push_back(left+1);
            ans.push_back(right+1);
            break;
          }
          else
          {
            right--;
          }
        }
        return ans;
    }
};

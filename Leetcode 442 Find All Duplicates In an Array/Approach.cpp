Amar 1 ta array ase.Amar chaise array te jara duplicate ase tader k array akare.Ekhn duplicate mane jader (frequency>1).Kintu ekhane bolse jara exactly 2 bar ase mane(frequency==2) tader k chaise array akare.

So,
  ami 1 ta unordered_map<int,int>freq nei etay value r sathe tader frequency jora rakhbo map akare.Karon chaise jader freq=2 tader man mane jader it>second==2 tader it.first
  as vecor akare ans chaise tai 1 ta vector nei vector<int>ans etay it.first rekhe return kobo

 So,
  1 ta loop chalai for i=0 to i<nums.size() porjonto i++ kori 
  and freq[nums[i]]++; kori 
 ete amar frequency r nums map create hoilo
 So,
ekhon 
1 ta for loop chalai range based
 for(auto it:freq)
   map traverese kori  
check kori frequency jader 2
  So,
  Condition check:
if(it.second==2)
  mane 2 bar jara ase
 tader man lagbe mab=ne ans e push kori it.first
  So,
 for(auto it:freq)
        {
          if(it.second==2)
          {
            result.push_back(it.first);
          }
        }
return kori result;

Full Code:
----------
  class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int>result;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        for(auto it:freq)
        {
          if(it.second==2)
          {
            result.push_back(it.first);
          }
        }
        return result;

    }
};

Test Code:
----------

  🔍 লাইন বাই লাইন বিশ্লেষণ:
✅ class Solution
👉 একটি ক্লাস তৈরি করছো Solution নামে, LeetCode বা অনুরূপ প্ল্যাটফর্মে এটা প্রয়োজন হয়।

✅ vector<int> findDuplicates(vector<int>& nums)
👉 findDuplicates ফাংশনটি ডিফাইন করছো, যেটা একটি ভেক্টর ইনপুট নেয় nums নামে, এবং একটি ভেক্টর রিটার্ন করে যেটাতে থাকবে যেসব সংখ্যা ঠিক দুইবার এসেছে।

✅ vector<int> result;
👉 এটা একটা খালি ভেক্টর যেটাতে পরে আমরা আমাদের উত্তর (duplicate নাম্বার) রাখবো।

✅ unordered_map<int, int> freq;
👉 এখানে একটা unordered_map তৈরি করছো, যা প্রতিটি সংখ্যার frequency বা কতবার এসেছে তা হিসাব রাখবে।

✅ for(int i = 0; i < nums.size(); i++)
👉 এই for লুপে nums অ্যারেটার প্রতিটি সংখ্যায় একবার করে ঘুরবে।

✅ freq[nums[i]]++;
👉 প্রতিবার লুপে nums[i] সংখ্যাটি map-এ ১ বাড়িয়ে নিচ্ছে।
🔹 ধরো nums[i] = 2 হলে:
freq[2]++ হবে, অর্থাৎ 2 এর মান ১ বাড়বে।

📌 এই লুপ শেষে freq এর মান হবে এমন:

উদাহরণ ইনপুট nums = [4,3,2,7,8,2,3,1] হলে:

yaml
Copy
Edit
freq = {
  1: 1,
  2: 2,
  3: 2,
  4: 1,
  7: 1,
  8: 1
}
✅ for(auto it : freq)
👉 unordered_map এর প্রতিটি item নিয়ে আবার একবার করে লুপ চালাচ্ছো।
it.first = সংখ্যাটি
it.second = ওই সংখ্যাটি কয়বার এসেছে

✅ if(it.second == 2)
👉 যদি কোনো সংখ্যার frequency 2 হয় (অর্থাৎ, ঠিক দুইবার এসেছে), তাহলে সেই সংখ্যাটিই আমরা খুঁজছি।

✅ result.push_back(it.first);
👉 ওই সংখ্যা result অ্যারেতে যোগ করছো।

✅ return result;
👉 সব duplicate পাওয়া শেষ হলে, result অ্যারে return করছো।

📘 Example Test:
Input: nums = [4,3,2,7,8,2,3,1]

১ম লুপে freq হবে:

Copy
Edit
2 → 2 বার
3 → 2 বার
অন্যান্য → 1 বার
২য় লুপে:

2 এবং 3 এর frequency 2, তাই result = [2, 3]

✔ Output = [2, 3] ✅



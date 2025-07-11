সমস্যা (Problem) কী?
তোমাকে একটি ইন্টিজার অ্যারে দেওয়া আছে, nums।

একটি সংখ্যা "লোনলি" হবে যদি:

সে অ্যারেতে শুধুমাত্র একবারই (exactly once) আসে,

এবং তার পাশের সংখ্যাগুলো (যেমন, x-1 এবং x+1) অ্যারেতে না থাকে।

তোমাকে সব লোনলি সংখ্যা রিটার্ন করতে হবে।

কীভাবে চিন্তা করবে? (How to think the solution?)
বার্তা গণনা করতে হবে (Frequency count):
প্রথমেই অ্যারে nums-এর প্রতিটি সংখ্যার কতবার আছে সেটা বের করতে হবে।
কারণ লোনলি হওয়ার জন্য সংখ্যাটি অবশ্যই একবারই থাকতে হবে।

তালিকায় থাকা সংখ্যাগুলো ট্র্যাক করতে হবে (Set of numbers):
যাতে দ্রুত x-1 এবং x+1 আছে কিনা চেক করা যায়।
এর জন্য একটি সেট (unordered_set) ভালো।

প্রতিটি সংখ্যা পরীক্ষা করতে হবে:
যদি freq[x] == 1 হয় এবং x-1, x+1 উভয়ই সেটে না থাকে তাহলে সেটা লোনলি।

সব লোনলি সংখ্যাগুলো সংগ্রহ করতে হবে এবং রিটার্ন দিতে হবে।

তোমার কোডের ব্যাখ্যা (Your code explanation):
CheckLonely ফাংশন:
cpp
Copy
Edit
bool CheckLonely(vector<int>& nums, int x, unordered_set<int>& set1, unordered_map<int,int>& freq)
{
    bool islonely = false;

    if(freq[x] == 1) // যদি সংখ্যা x একবারই থাকে
    {
        if((set1.find(x+1) == set1.end()) && (set1.find(x-1) == set1.end())) // এবং x+1 ও x-1 অ্যারেতে না থাকে
        {
            islonely = true;
        }
        else
        {
            islonely = false;
        }
    }
    else
    {
        islonely = false; // যদি একবার না থাকে, লোনলি না
    }
    return islonely;
}
এখানে, তোমার লজিক সোজা ও স্পষ্ট:

প্রথমে freq[x]==1 চেক করো, মানে x একবারই আছে।

তারপর চেক করো x+1 এবং x-1 নেই কি।

থাকলে false, না থাকলে true।

findLonely ফাংশন:
cpp
Copy
Edit
vector<int> findLonely(vector<int>& nums) 
{
    unordered_map<int,int> freq;
    unordered_set<int> set1;
    for(int i=0; i<nums.size(); i++)
    {
        freq[nums[i]]++;    // প্রতিটি সংখ্যার frequency গোনা
        set1.insert(nums[i]); // প্রতিটি সংখ্যাকে set এ যোগ করা
    }

    vector<int> ans;
    for(int k=0; k<nums.size(); k++)
    {
        if(CheckLonely(nums, nums[k], set1, freq))
        {
            ans.push_back(nums[k]);
        }
    }
    return ans;
}
প্রথম লুপে freq এবং set তৈরী।

দ্বিতীয় লুপে প্রতিটি সংখ্যা চেক করো লোনলি কিনা।

লোনলি হলে ans-এ push_back করো।

কেন তোমার কোড accepted?
কারণ এটি সঠিকভাবে frequency এবং উপস্থিতি চেক করছে।

প্রত্যেক সংখ্যার জন্য লোনলি চেক ঠিকঠাক হচ্ছে।

TC: O(N) যেখানে N=nums.size(), কারণ frequency ও set তৈরি O(N), এবং প্রতিটি element চেক করাও O(N)।

SC: O(N) frequency ও set এর জন্য।

টেস্ট কেস দিয়ে লাইন বাই লাইন ব্যাখ্যা
নিচে একটি টেস্ট কেস নিয়ে দেখি কিভাবে কাজ করে:

cpp
Copy
Edit
nums = [10, 6, 5, 8]
প্রথম লুপে:

freq:
10 → 1
6 → 1
5 → 1
8 → 1

set1 = {10, 6, 5, 8}

দ্বিতীয় লুপে প্রতিটি x এর জন্য CheckLonely চালানো হবে:

১) x = 10
freq[10] = 1 (true)

set1.find(9) → 9 নেই → true

set1.find(11) → 11 নেই → true

তাই 10 লোনলি → ans.push_back(10)

২) x = 6
freq[6] = 1 (true)

set1.find(5) → 5 আছে → false

তাই 6 লোনলি না

৩) x = 5
freq[5] = 1 (true)

set1.find(4) → 4 নেই → true

set1.find(6) → 6 আছে → false

তাই 5 লোনলি না

৪) x = 8
freq[8] = 1 (true)

set1.find(7) → 7 নেই → true

set1.find(9) → 9 নেই → true

তাই 8 লোনলি → ans.push_back(8)

Final Output: [10, 8]

  
  Full Code:
------------

  class Solution
 {
public: 
bool CheckLonely(vector<int>&nums,int x,unordered_set<int>& set1, unordered_map<int,int>& freq)
{
  bool islonely=false;
    if(freq[x]==1)
    {
      if((set1.find(x+1)==set1.end())&&(set1.find(x-1)==set1.end()))
      {
        islonely=true;
      }
      else
      {
        islonely=false;
      }
    }
    else
    {
      islonely=false;
    }
  return islonely;
}

    vector<int> findLonely(vector<int>& nums) 
    {
       unordered_map<int,int> freq;
  unordered_set<int> set1;
for(int i=0;i<nums.size();i++)
{
  freq[nums[i]]++;
  set1.insert(nums[i]);
}
      vector<int>ans;
      for(int k=0;k<nums.size();k++)
      {
        if(CheckLonely(nums,nums[k],set1,freq))
        {
          ans.push_back(nums[k]);
        }
      }
      return ans;
    }
};

  

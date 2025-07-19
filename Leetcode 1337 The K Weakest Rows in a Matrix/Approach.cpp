প্রবলেমটা কি?
তোমার একটা m x n মেট্রিক্স mat আছে, যেখানে 1 হলো সৈনিক আর 0 হলো নাগরিক।

সৈনিক সবসময় মেট্রিক্সের প্রতিটি রো এর বাম দিকেই থাকবে, অর্থাৎ 1 গুলো সবসময় 0 এর আগে থাকবে।

তোমাকে বলতে হবে সেই k টি রো যেগুলো সবচেয়ে দুর্বল, অর্থাৎ যাদের সৈনিকের সংখ্যা সবচেয়ে কম, আর যদি সৈনিকের সংখ্যা সমান হয় তাহলে রো নম্বর কম সেটা আগে আসবে।

তোমার দেয়া কোড:
cpp
Copy
Edit
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int count = 0;
        vector<pair<int, int>> v;
        
        for(int i = 0; i < mat.size(); i++) {
            count = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
                else {
                    break;
                }
            }
            v.push_back({i, count});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans;
        for(auto it : v) {
            ans.push_back(it.first);
            if(ans.size() == k) {
                break;
            }
        }
        
        return ans;
    }
};
কিভাবে চিন্তা করব? (Approach)
প্রতিটি রোতে কতজন সৈনিক আছে সেটা গোনা — যেহেতু 1 সবসময় আগে থাকবে, 0 আসলে আর গণনা বন্ধ করতে পারি (break)।

প্রতিটি রো এর (রো নম্বর, সৈনিক সংখ্যা) একটা জোড়া তৈরি করি, যেমন (index, soldiers_count)।

এই জোড়াগুলোকে সৈনিক সংখ্যার কম থেকে বেশি এবং সৈনিক সমান হলে রো নম্বর অনুযায়ী ছোট থেকে বড় ক্রমে সাজাই।

তারপর প্রথম k সংখ্যক রো এর index গুলো return করব।

কোডের লাইন বাই লাইন ব্যাখ্যা (Bangla):
cpp
Copy
Edit
static bool cmp(pair<int, int> a, pair<int, int> b)
{
  if(a.second == b.second)      // যদি সৈনিক সংখ্যা দুই রো এর সমান হয়
    return a.first < b.first;   // তাহলে ছোট রো নম্বরকে আগে রাখো
  return a.second < b.second;   // নাহলে যাদের সৈনিক সংখ্যা কম তাদের আগে রাখো
}
এটা একটা compare ফাংশন যেটা sort এ ব্যবহার করা হয়।

pair এর first = row index, second = soldier count।

cpp
Copy
Edit
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
mat হলো ইনপুট matrix, k হলো কতগুলো দুর্বল রো বের করতে হবে।

cpp
Copy
Edit
  int count = 0;
  vector<pair<int, int>> v;
count দিয়ে সৈনিকের সংখ্যা গোনা হবে।

v হলো vector যা প্রতিটি রো এর (index, soldier_count) সংরক্ষণ করবে।

cpp
Copy
Edit
  for(int i=0; i<mat.size(); i++)
  {
    count = 0;
    for(int j=0; j<mat[i].size(); j++)
    {
      if(mat[i][j] == 1)
      {
        count++;  // সৈনিক পাওয়া গেলে কাউন্ট বাড়াও
      }
      else
      {
        break;  // ০ পাওয়ার পর আর কাউন্ট করা লাগবে না, কারণ সৈনিক সবসময় বাম পাশে
      }
    }
    v.push_back({i, count});  // রো নম্বর এবং সৈনিক সংখ্যা ভেক্টরে যুক্ত করো
  }
প্রতিটি রোতে প্রবেশ করে সেখানে 1 কতবার আছে গোনা হয়।

0 পেলেই break করে।

cpp
Copy
Edit
  sort(v.begin(), v.end(), cmp);
সৈনিক সংখ্যা অনুযায়ী ছোট থেকে বড় এবং যদি সৈনিক সমান হয় তাহলে রো নম্বর ছোট থেকে বড় করে sort।

cpp
Copy
Edit
  vector<int> ans;
  for(auto it : v)
  {
    ans.push_back(it.first);  // sorted ভেক্টর থেকে রো নম্বরগুলো নেওয়া
    if(ans.size() == k)       // k সংখ্যক দুর্বল রো পাওয়া গেলে loop বন্ধ
      break;
  }
  return ans;
প্রথম k রো এর index return করা হচ্ছে।

কিভাবে কোড accepted হয়?
কোড পুরোপুরি প্রবলেমের শর্ত মেনে কাজ করে।

সৈনিক সংখ্যা কম হওয়া ভিত্তিতে রো গুলো সাজানো হচ্ছে।

যদি সৈনিক সংখ্যা সমান হয়, তাহলে ইনডেক্স ছোটকে আগে রাখা হচ্ছে।

break করা হয়েছে সৈনিক ০ পাওয়ার পর, যা অপ্টিমাইজড।

তারপর প্রথম k দুর্বল রো return করাই।

উদাহরণ দিয়ে step-by-step ব্যাখ্যা:
Input:

lua
Copy
Edit
mat = [[1,1,0,0,0],
       [1,1,1,1,0],
       [1,0,0,0,0],
       [1,1,0,0,0],
       [1,1,1,1,1]], 
k = 3
Step 1: সৈনিক গণনা (count soldiers in each row)
Row 0: 1,1 → 2 soldiers

Row 1: 1,1,1,1 → 4 soldiers

Row 2: 1 → 1 soldier

Row 3: 1,1 → 2 soldiers

Row 4: 1,1,1,1,1 → 5 soldiers

Step 2: pair vector তৈরি হবে
ini
Copy
Edit
v = [(0,2), (1,4), (2,1), (3,2), (4,5)]
Step 3: sort করবে soldier count অনুযায়ী, soldier same হলে row index অনুযায়ী
Sorted v হবে:

css
Copy
Edit
[(2,1), (0,2), (3,2), (1,4), (4,5)]
Step 4: প্রথম k=3 টা index নেবে
ini
Copy
Edit
ans = [2, 0, 3]
Test Case ব্যাখ্যা (Bangla):
তুমি প্রথমে প্রত্যেক রো এর সৈনিক গুণে ফেলবে।

সৈনিক সংখ্যা কম হলে ঐ রো দুর্বল।

সৈনিক সংখ্যা সমান হলে ছোট ইনডেক্সের রো দুর্বল।

তাই sorted vector থেকে k টা রো index নিবে।

Summary:
কেন count করলাম? সৈনিকের সংখ্যা নির্ণয়ের জন্য।

কেন break করলাম? ০ পাওয়ার পর আর সৈনিক পাওয়া যাবে না, এটা অপ্টিমাইজেশনের জন্য।

কেন pair vector? যাতে index আর সৈনিক সংখ্যা একসাথে রাখা যায়।

কেন custom comparator? সৈনিক সংখ্যা ও index দুইটাই প্রাধান্য দেয়ার জন্য।

কেন sort করলাম? দুর্বল রো গুলো সাজানোর জন্য।

কেন প্রথম k টা নিলাম? প্রশ্ন অনুসারে k টা দুর্বল রো return করার জন্য।

Full Code:
------------

  class Solution {
public:
static bool cmp(pair<int, int> a, pair<int, int> b)
{
  if(a.second==b.second)
  return a.first<b.first;
  return a.second<b.second;
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int count=0;
      vector<pair<int, int>> v ;
      for(int i=0;i<mat.size();i++)
      {
        count=0;
        for(int j=0;j<mat[i].size();j++)
        {
          if(mat[i][j]==1)
          {
            count++;
            
          }
          else
          {
            break;
          }
         
         
          //count=0;
        }
         v.push_back({i,count});
      }
     sort(v.begin(),v.end(),cmp);
     vector<int>ans;
     for(auto it:v)
     {
      ans.push_back(it.first);
      if(ans.size()==k)
      {
        break;
      }
     }
     return ans;
    }
};

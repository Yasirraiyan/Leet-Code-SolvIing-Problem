Amar 1 ta array ase candies.1 ta int ase extra candies. Ami prottekke extra candies dile ba protteker sathe extra candies jog korle jodi array r max number er beshi ba equal hoy taile array te true push korbo
Naile false push korbo.
  Amar 1 ta bool array return chaise.
  First e 1 ta function banai main function er baire ja array r max xcalculate krbe

Helper Function:
----------------
   int getmax(vector<int>arr)
  {
    int max=arr[0];
    for(int i=1;i<arr.size();i++)
    {
      if(arr[i]>max)
      {
        max=arr[i];
      }
    }
    return max;
  }
Explaination:
--------------
  এই getmax ফাংশনটি একটি vector<int> (অর্থাৎ int টাইপের ভেক্টর) ইনপুট হিসেবে নেয় এবং সেই ভেক্টরের মধ্যে যেটা সবচেয়ে বড় সংখ্যা আছে, সেটি রিটার্ন করে।

চলো লাইন বাই লাইন ব্যাখ্যা করি:

cpp
Copy
Edit
int getmax(vector<int> arr)
এটা একটি ফাংশনের ডেফিনিশন যেটার নাম getmax।

এটি ইনপুট হিসেবে vector<int> arr নেয়, যেখানে arr হচ্ছে পূর্ণসংখ্যার (integer) একটি লিস্ট বা অ্যারে টাইপের ভেক্টর।

ফাংশনের রিটার্ন টাইপ int, মানে এটি একটি সংখ্যা রিটার্ন করবে।

cpp
Copy
Edit
int max = arr[0];
ভেক্টরের প্রথম উপাদানকে (index 0) ধরে নেওয়া হয়েছে যে সেটাই এখন পর্যন্ত সবচেয়ে বড় সংখ্যা।

cpp
Copy
Edit
for(int i = 1; i < arr.size(); i++)
ভেক্টরের দ্বিতীয় উপাদান (index 1) থেকে শুরু করে শেষ পর্যন্ত for লুপ চালানো হচ্ছে।

cpp
Copy
Edit
if(arr[i] > max)
{
    max = arr[i];
}
যদি কোনো উপাদান বর্তমান max থেকে বড় হয়, তাহলে max কে সেই উপাদানের মান দিয়ে আপডেট করা হচ্ছে।

cpp
Copy
Edit
return max;
লুপ শেষ হওয়ার পরে, যেটা max তে আছে (মানে সবচেয়ে বড় সংখ্যা), সেটি রিটার্ন করা হচ্ছে।

📌 সংক্ষেপে বাংলায় বুঝি:
getmax ফাংশনটি একটি সংখ্যা তালিকা (ভেক্টর) নেয় এবং তার মধ্যে সবচেয়ে বড় সংখ্যাটি খুঁজে বের করে রিটার্ন করে।

যেমন:


vector<int> numbers = {5, 9, 3, 15, 7};
int result = getmax(numbers);
// result = 15

#include <iostream>
#include <vector>
using namespace std;

// সর্বোচ্চ মান বের করার ফাংশন
int getmax(vector<int> arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // ইনপুট ভেক্টর
    vector<int> numbers = {5, 9, 3, 15, 7};

    // getmax ফাংশন কল করা
    int result = getmax(numbers);

    // আউটপুট
    cout << "সর্বোচ্চ সংখ্যা হলো: " << result << endl;

    return 0;
}
📝 আউটপুট হবে:

সর্বোচ্চ সংখ্যা হলো: 15
🔍 বাংলায় সংক্ষিপ্ত ব্যাখ্যা:
আমরা numbers নামের একটি সংখ্যা তালিকা তৈরি করেছি।

তারপর সেই তালিকাটি getmax ফাংশনে পাঠিয়েছি।

getmax ফাংশনটি ভেতরে গিয়ে লুপ চালিয়ে দেখেছে কোন সংখ্যাটি সবচেয়ে বড়, এবং সেটাই রিটার্ন করেছে।

Erpor main function e 1 ta vector array create kori bool type er.Karon amr ans e return chaise bool type array
 1 ta loop chalai j=0 to j<candies.size() porjonto j++ kori
  Check kori protteker sathe extra candies jog kore max er besi ba soman kina
tai helper function getmax() call kor
So,
  Code:
  ------

   if(candies[j]+extraCandies>=getmax(candies)) 
  jodi true hoy tai 
ans e push kori true;
naile 
else 
push kori false;
So,
  Code is:
------------
  if(candies[j]+extraCandies>=getmax(candies))
          {
            ans.push_back(true);
          }
          else
          {
            ans.push_back(false);
          }
return kori ans;
Code With loop:
---------------
  for(int j=0;j<candies.size();j++)
        {
          if(candies[j]+extraCandies>=getmax(candies))
          {
            ans.push_back(true);
          }
          else
          {
            ans.push_back(false);
          }
        }

Main Function:
---------------

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool>ans;
        for(int j=0;j<candies.size();j++)
        {
          if(candies[j]+extraCandies>=getmax(candies))
          {
            ans.push_back(true);
          }
          else
          {
            ans.push_back(false);
          }
        }
        return ans;
    }

Full Code:
-----------

  #include<vector>
#include<iostream>
#include<cctype>
class Solution 
{
public:
  int getmax(vector<int>arr)
  {
    int max=arr[0];
    for(int i=1;i<arr.size();i++)
    {
      if(arr[i]>max)
      {
        max=arr[i];
      }
    }
    return max;
  }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool>ans;
        for(int j=0;j<candies.size();j++)
        {
          if(candies[j]+extraCandies>=getmax(candies))
          {
            ans.push_back(true);
          }
          else
          {
            ans.push_back(false);
          }
        }
        return ans;
    }
};






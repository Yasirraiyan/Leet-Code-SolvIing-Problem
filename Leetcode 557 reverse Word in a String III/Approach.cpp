Problem Understanding (কোথা থেকে কী ধাপ আসবে)

প্রশ্নে বলা হয়েছে:

একটি sentence s দেওয়া আছে।

প্রতিটি word এর character order reverse করতে হবে।

Word-এর order বা position change হবে না।

Word গুলো single space দিয়ে separate।

কোন extra leading বা trailing space নেই।

Example:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"


এখানে:

"Let's" → "s'teL"

"take" → "ekat"

"LeetCode" → "edoCteeL"

"contest" → "tsetnoc"

Solution Approach (কিভাবে চিন্তা করা যায়)

১. Word টুকরা বের করা:

sentence কে "words" এ ভাগ করতে হবে।

C++ এ আমরা stringstream ব্যবহার করতে পারি।

ss >> word প্রতিবার এক word নেয়।

২. প্রতিটি word reverse করা:

এক word reverse করতে two-pointer technique ব্যবহার করতে পারি।

left pointer = 0, right pointer = word.size()-1

left এবং right swap করা হবে যতক্ষণ left < right।

৩. সব reversed word combine করা:

সব reversed word গুলো আবার একত্রে sentence বানাতে হবে।

word গুলোর মধ্যে space যোগ করতে হবে।

Line by Line Bangla Explanation of Code
class Solution 
{
public:


এখানে আমরা Solution class declare করছি, LeetCode standard practice।

string Reverse(string a)
{
    int i=0;
    int j=a.size()-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
    return a;
}


Explanation:

string Reverse(string a) → একটি function যা একটি word reverse করে return করবে।

i=0, j=a.size()-1 → left এবং right pointer initialization।

while(i<j) → যতক্ষণ left pointer < right pointer:

swap(a[i], a[j]) → left ও right character swap করা।

i++ → left pointer বাড়ানো

j-- → right pointer কমানো

শেষে reversed string a return করা।

Technique: Two-pointer method for reversing a string efficiently.

string reverseWords(string s) 
{
    stringstream ss(s);
    vector<string>v;
    string word;


stringstream ss(s) → input string কে word-wise access করার জন্য।

vector<string> v → reversed words store করার জন্য।

string word → temporary variable প্রতিটি word read করার জন্য।

while(ss>>word)
{
    v.push_back(word);
}


এখানে আমরা সব words vector এ রাখছি।

ss >> word → space দিয়ে separate করে word read করে।

for(int k=0;k<v.size();k++)
{
    v[k]=Reverse(v[k]);
}


প্রতিটি word reverse করা হচ্ছে।

v[k]=Reverse(v[k]) → previously defined Reverse function call করা।

string ans="";
for(int j = 0; j < v.size(); j++)
{
    if(j > 0) ans += " "; // previous word-এর পরে space
    ans += v[j];
}
return ans;


সব reversed word একত্র করা হচ্ছে।

প্রথম word-এর আগে space লাগবে না, তাই if(j > 0) check করা হয়েছে।

শেষে combined string ans return।

Why This Solution Works / Accepted

Correctness:

প্রতিটি word আলাদা করা হয়েছে → satisfies the word separation constraint।

প্রতিটি word reverse করা হয়েছে → satisfies character order reversal।

সব word আবার original order-এ join করা হয়েছে → satisfies word order preservation।

Efficiency:

O(n) time complexity:

word split → O(n)

reverse each word → O(n)

join → O(n)

Extra space: O(n) → vector for storing words.

Test Case Validity:

Example 1:

Input: "Let's take LeetCode contest"

Step1: split -> ["Let's","take","LeetCode","contest"]
Step2: reverse each -> ["s'teL","ekat","edoCteeL","tsetnoc"]
Step3: join -> "s'teL ekat edoCteeL tsetnoc"
Output matches expected


Example 2:

Input: "Mr Ding"

Split -> ["Mr","Ding"]
Reverse -> ["rM","gniD"]
Join -> "rM gniD"


All test cases passed because every constraint is satisfied।

Techniques Used

Two-pointer method → String reverse efficiently.

String stream → Word tokenization.

Vector storage → Intermediate storage for word manipulation.

String concatenation with space → Final sentence formation.

Brief Bangla Summary of How to Think

প্রশ্ন পড়ে identify করো: word আলাদা করতে হবে, reverse করতে হবে, order preserve করতে হবে।

ছোট ছোট step এ ভাগ করো: split → reverse → join

প্রতিটি step implement করতে simple, reusable function ব্যবহার করো (Reverse function)।

Edge cases automatically handled:

single word → works

multiple words → works

normal space constraints → handled by stringstream

Full Code:
-----------------

  class Solution 
{
public:
string Reverse(string a)
{
    int i=0;
    int j=a.size()-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
    return a;
}
    string reverseWords(string s) 
    {
        stringstream ss(s);
        vector<string>v;
        string word;
        while(ss>>word)
        {
            v.push_back(word);
        }
        for(int k=0;k<v.size();k++)
        {
            v[k]=Reverse(v[k]);
        }
        string ans="";
       for(int j = 0; j < v.size(); j++)
        {
            if(j > 0) ans += " "; // previous word-এর পরে space
            ans += v[j];
        }
return ans;
    }
};

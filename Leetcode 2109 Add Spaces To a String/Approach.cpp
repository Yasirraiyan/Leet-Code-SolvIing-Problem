Problem Understanding (প্রথমে প্রশ্ন থেকে কী বুঝতে হবে)

আমাদের একটা string s আছে, যেমন "LeetcodeHelpsMeLearn".

আর একটি integer array spaces, যেমন [8,13,15], যা বলে কোথায় space বসাতে হবে।

মানে, spaces[i] হলো সেই index যেখানে space বসানো হবে আগে।

Output: নতুন string, যেখানে সেই positions-এ space বসানো আছে।

Example:

s = "LeetcodeHelpsMeLearn"
spaces = [8,13,15]
output = "Leetcode Helps Me Learn"


Index 8 → 'H' এর আগে space

Index 13 → 'M' এর আগে space

Index 15 → 'L' এর আগে space

Approach (কীভাবে solve করব)

Two pointers / iterative approach:

i → string s এর index track করবে।

j → spaces array এর index track করবে।

Step by step logic:

প্রথমে empty string res বানাও।

loop চালাও i from 0 to s.size()-1।

প্রতি step-এ check করো:

যদি i == spaces[j] → তখন res এ আগে space যোগ করো, তারপর j++।

তারপর s[i] add করো res এ।

i++ দিয়ে move করো next character-এ।

Technique:

এটা হলো two-pointer or single-pass traversal technique।

আমরা s আর spaces দুইটা array একসাথে traverse করছি।

Time complexity = O(n + m) → n = s.size(), m = spaces.size()

Extra space = O(n + m) → because new string res তৈরি হচ্ছে।

Line by line Bangla explanation
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0;              // i pointer: s string traverse করতে
        int j=0;              // j pointer: spaces array traverse করতে
        string res;           // final result string
        
        while(i<s.size())     // প্রতিটি character traverse করব
        {
            if(j<spaces.size() && i==spaces[j]) // check: i কি spaces[j]-এর সাথে match করছে?
            {
                res += ' ';   // যদি match করে → space add করো
                j++;          // next space index-এ move করো
            }
            
            res += s[i];      // current character add করো
            i++;              // next character এ move করো
        }
        
        return res;           // final modified string return করো
    }
};

Step by step Example walkthrough

Example 1:

s = "LeetcodeHelpsMeLearn"
spaces = [8,13,15]


Initialize: i=0, j=0, res=""

Loop:

i=0 → i!=spaces[j]=8 → add 'L' → res="L"

i=1 → add 'e' → res="Le"

...

i=8 → i==spaces[j]=8 → add space → res="Leetcode " → j++

i=8 → add 'H' → res="Leetcode H"

...

i=13 → i==spaces[j]=13 → add space → res="Leetcode Helps " → j++

i=13 → add 'M' → res="Leetcode Helps M"

...

i=15 → i==spaces[j]=15 → add space → res="Leetcode Helps Me " → j++

i=15 → add 'L' → res="Leetcode Helps Me L"

Continue until end.

Final Output: "Leetcode Helps Me Learn"

✅ Accepted test cases:

কেন accepted? কারণ:

প্রতিটি index ঠিকঠাক check করা হয়েছে।

Original string-এর order maintained হয়েছে।

সব spaces index properly inserted হয়েছে।

Technique Summary

Two-pointer / single-pass:

এক pointer দিয়ে string traverse করা।

আরেক pointer দিয়ে spaces array traverse করা।

Why efficient:

শুধু একবার string traverse করা, কোন extra nested loop নেই।

Time complexity = O(n+m), Space complexity = O(n+m)

When to use:

যখন আমাদের একটি ordered list অনুযায়ী extra operations (যেমন space insertion) করতে হবে।

Competitive programming-এ index-based insertion/merge প্রোবলেমে খুব useful।

💡 Bangla short tips:

সবসময় problem পড়ার পরে মনে করো: কোথায় pointer/loop use করতে পারি।

কোন insertion/condition আছে কি? → সেটাকে pointer দিয়ে track করো।

একবার traverse → efficient solution।

Full Code:
-------------
  class Solution
 {
public:
    string addSpaces(string s, vector<int>& spaces) {
     int i=0;
     int j=0;
     string res;
     while(i<s.size())
     {
        if(j<spaces.size()&&i==spaces[j])
        {
            res+=' ';
            j++;
        }
        res+=s[i];
        i++;
     }
     return res;
    }
};

Full C

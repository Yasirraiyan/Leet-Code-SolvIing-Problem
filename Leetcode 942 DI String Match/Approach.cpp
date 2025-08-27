প্রশ্নটি বোঝা:

আমাদের কাছে একটি স্ট্রিং s আছে যা শুধু 'I' (Increase) এবং 'D' (Decrease) দিয়ে গঠিত। আমাদের কাজ:

একটি Permutation perm বের করতে হবে যার দৈর্ঘ্য n+1 যেখানে n = s.size().

শর্ত হলো:

s[i] == 'I' → perm[i] < perm[i+1]

s[i] == 'D' → perm[i] > perm[i+1]

আমরা 0 থেকে n পর্যন্ত সমস্ত সংখ্যা ব্যবহার করতে পারি।

উদাহরণ: s = "IDID" → [0,4,1,3,2] (একটি সঠিক উত্তর, অন্যেও হতে পারে)

কোডের মূল ধারণা (Approach)

আমাদের আছে দুইটি pointer বা সীমা:

low = 0 → সবচেয়ে ছোট সংখ্যা এখনো ব্যবহার করা হয়নি

high = n → সবচেয়ে বড় সংখ্যা এখনো ব্যবহার করা হয়নি

আমরা s স্ট্রিং ধরে ধরে দেখি:

যদি s[i] == 'I' → perm[i] তে low assign করি, তারপর low++
কারণ আমরা চাই ছোট সংখ্যা আগে, তারপর বড় সংখ্যা → "Increase"

যদি s[i] == 'D' → perm[i] তে high assign করি, তারপর high--
কারণ আমরা চাই বড় সংখ্যা আগে, তারপর ছোট সংখ্যা → "Decrease"

শেষে, perm[n] তে শুধু low (বা high, যেকোনোই কারণ low == high) assign করি।

এটি Greedy technique বা লজিক ব্যবহার করে করা হয়:

প্রশ্ন পড়েই তুমি বুঝছো: 'I' মানে ছোট → বড়, 'D' মানে বড় → ছোট।

তাই দুই প্রান্ত (low এবং high) ব্যবহার করলে সহজে permutation বানানো যায়।

Step by Step উদাহরণ
Testcase 1: s = "IDID"
low = 0, high = 4, n = 4
perm = [_,_,_,_,_]

i=0, s[0]='I'
perm[0] = low = 0 → perm = [0,_,_,_,_]
low++

i=1, s[1]='D'
perm[1] = high = 4 → perm = [0,4,_,_,_]
high--

i=2, s[2]='I'
perm[2] = low = 1 → perm = [0,4,1,_,_]
low++

i=3, s[3]='D'
perm[3] = high = 3 → perm = [0,4,1,3,_]
high--

শেষে perm[4] = low = 2 → perm = [0,4,1,3,2]


✅ সব শর্ত মেনে চলে:

0<4 (I)

4>1 (D)

1<3 (I)

3>2 (D)

Testcase 2: s = "III"
low = 0, high = 3, n = 3
perm = [_,_,_,_]

i=0, s[0]='I' → perm[0]=0, low++
i=1, s[1]='I' → perm[1]=1, low++
i=2, s[2]='I' → perm[2]=2, low++

perm[3] = low = 3
perm = [0,1,2,3]


✅ সব শর্ত ঠিক আছে: সবই increasing।

কেন Accepted?

O(n) টাইম কমপ্লেক্সিটি → ১০^৫ পর্যন্ত মানের জন্য ঠিক আছে।

O(n) স্পেস ব্যবহার হয়েছে → perm array।

সব testcase pass করে কারণ:

আমরা সব number ব্যবহার করি 0..n

'I' এবং 'D' অনুযায়ী greedy approach দিয়ে assign করি

প্রতিটি সংখ্যা একবারই ব্যবহার হয়

কোডের বাংলা ব্যাখ্যা
class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        int n = s.size();
        vector<int> perm(n+1);
        int low = 0;
        int high = n;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'I')
            {
                perm[i] = low; // ছোট থেকে বড়
                low++;
            }
            else // s[i] == 'D'
            {
                perm[i] = high; // বড় থেকে ছোট
                high--;
            }
        }

        perm[n] = low; // বা high, শেষ element
        return perm;
    }
};

কীভাবে প্রশ্ন পড়েই কোড লেখা হয়

'I' → ছোট → বড়, 'D' → বড় → ছোট → বুঝে নিতে হবে number allocation।

0..n সংখ্যা সব ব্যবহার করতে হবে → low & high pointer logical।

Single pass loop → O(n) → efficient।

শেষে একটাই number assign করতে হবে → low == high।

Summary (বাংলা)

Technique: Greedy (low & high pointer ব্যবহার করে assign করা)

Logic:

'I' → ছোট সংখ্যা দিয়ে শুরু

'D' → বড় সংখ্যা দিয়ে শুরু

Time complexity: O(n)

Space complexity: O(n)

Testcase verified: সব 'I' এবং 'D' combination কাজ করে।

Full Code:
-----------

class Solution
 {
public:
    vector<int> diStringMatch(string s) 
    {
      int  n=s.size();
      vector<int>perm(n+1);
      //perm.push_back(s.size());
        int low=0;
        int high=n;
        for(int i=0;i<s.size();i++)
        {
       /// while(low<high)
       // {
          if(s[i]=='I')
          {
            perm[i]=low;
            low++;
           
          }
          if(s[i]=='D')
          {
            perm[i]=high;
            high--;
          }
       // }
        }
        perm[n]=low;
        return perm;
    }
};

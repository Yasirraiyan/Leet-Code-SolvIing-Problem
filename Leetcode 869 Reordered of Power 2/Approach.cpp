১️⃣ সমস্যা বোঝা (Problem Understanding)

Given: একটি integer n।

Task: আমরা চাই n-এর digits এমনভাবে rearrange করা যায় কি না, যাতে resulting number কোন 2-এর power হয়।

Constraint: Leading digit কখনোই 0 হতে পারবে না।

উদাহরণ:

Input: 1 → Output: true (কারণ 1 = 2^0)

Input: 10 → Output: false

২️⃣ Approach চিন্তা করা (Step-by-step Logic)

Valid function: Check করে leading digit zero না হয়।

TestPowerOfTwo function: Check করে number কি 2^k।

reorderedPowerOf2 function: মূল function।

Steps:

n কে string এ convert করা।

Sort করা → next_permutation use করার জন্য।

সব permutation generate করা।

Valid permutation গুলোর integer list তৈরি।

প্রতিটি integer check করা → 2^k কি না।

যদি match পাওয়া যায় → return true, অন্যথায় false।

Idea:
Problem পড়ে মনে হচ্ছে সব permutations check করতে হবে, যার leading digit zero নয়, এবং যেটি 2^k হতে পারে। তাই permutation + validation + power check combination naturally এসেছে।

৩️⃣ Code Analysis (Line-by-line)
bool Valid(string s)
{
    return s[0]!='0';
}


Purpose: Check করে leading digit zero নয়।
Example: "012" → Invalid, "120" → Valid

bool TestPowerOfTwo(int n)
{
    if(n==1) return true;
    if(n <= 0) return false;  
    while(n%2==0)
    {
        n/=2;
    }
    return n==1;
}


Purpose: Check if number is power of two
Logic:

n = 1 → true

n <= 0 → false

n কে বারবার 2 দিয়ে divide করা

শেষ n = 1 হলে → power of 2

bool reorderedPowerOf2(int n) 
{
    if(n==1) return true;  // Early return
    string a = to_string(n);
    sort(a.begin(), a.end());  // next_permutation use এর জন্য

    vector<string> v;
    do
    {
        v.push_back(a);
    } while(next_permutation(a.begin(), a.end()));


Purpose: সব permutations generate করা → v vector এ store করা

    vector<int> vv;
    for(int j=0; j<v.size(); j++)
    {
        if(Valid(v[j]))
        {
            vv.push_back(stoi(v[j]));
        }
    }


Purpose:

Leading digit zero check (Valid)

Valid permutations কে integer list vv এ convert

    for(int k=0; k<vv.size(); k++)
    {
        if(TestPowerOfTwo(vv[k]))
        {
            return true; // found
        }
    }
    return false;
}


Purpose:

প্রতিটি valid permutation test করা

যদি 2^k হয় → true, break

সব test fail হলে → false

৪️⃣ Example/Test Case Analysis

Test Case 1: n = 1

Early return → true ✅

Test Case 2: n = 10

a = "10" → sorted = "01"

permutations: "01", "10"

Valid: only "10" (leading zero check)

TestPowerOfTwo(10) → false

Output: false ✅

Test Case 3: n = 128

a = "128" → sorted = "128"

permutations: "128", "182", "218", "281", "812", "821"

সব Valid

TestPowerOfTwo(128) → true → break

Output: true ✅

৫️⃣ Complexity Analysis

Time Complexity:

Permutations: O(d!) → d = number of digits ≤ 10 → max 10! ≈ 3.6M → feasible

TestPowerOfTwo: O(log n) per number → ≤ 30

Total worst case: O(10! * log n) → feasible

Space Complexity:

Store all permutations → O(d!)

Additional vectors → O(d!)

৬️⃣ সারসংক্ষেপ (Summary)

Approach:

Digits rearrange → সব permutation generate

Validity check → leading digit zero নয়

Test each permutation → power of 2

Early return optimization → n = 1

Accepted কারণ:

Number of digits max 10 → permutation feasible

TestPowerOfTwo O(log n)

সব test case pass ✅

Full Code:
------------

  class Solution 
{
public:
bool Valid(string s)
{
    return s[0]!='0';
}
bool TestPowerOfTwo(int n)
{
    bool test=false;
   if(n==1) return true;
   if (n <= 0) return false;  
while(n%2==0)
   {
    
    n/=2;
   }
   return n==1;
}
    bool reorderedPowerOf2(int n) 
    {
        if(n==1) return true;
        string a=to_string(n);
        sort(a.begin(), a.end());  
        vector<string>v;
        bool poss=false;
        do
        {
            v.push_back(a);
        }while(next_permutation(a.begin(),a.end()));
        vector<int>vv;
        for(int j=0;j<v.size();j++)
        {
            if(Valid(v[j]))
            {
               vv.push_back(stoi(v[j]));
            }
        }
      
for(int k=0;k<vv.size();k++)
{
    if(TestPowerOfTwo(vv[k]))
    {
        poss=true;
        break;
    }
}
return poss;
    }
};

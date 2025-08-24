🔹 Problem টি কী বলছে?

আমাদের একটা string s দেওয়া আছে। শুধু vowel (a, e, i, o, u ছোট হাতা/বড় হাতা) গুলোকে উল্টাতে হবে (reverse করতে হবে)। বাকী consonant বা অন্য character গুলো তাদের position এ অপরিবর্তিত থাকবে।

🔹 Approach চিন্তা করার উপায়

Observation:
যদি পুরো string উল্টাই, তাহলে consonant-এর position বদলে যাবে ❌, যা আমরা চাই না।
সুতরাং, কেবল vowel গুলোকে একে অপরের সাথে swap করতে হবে।

Vowel খুঁজে বের করা:
একটা function TestVowel() বানানো হয়েছে, যা চেক করবে কোনো character vowel কিনা।

a, e, i, o, u

A, E, I, O, U

এই check করলে vowel গুলো আলাদা করা সহজ হবে। ✅

Two Pointer Technique (মূল টেকনিক):

শুরুতে একটা pointer low = 0 (string-এর শুরু থেকে)।

আরেকটা pointer high = n-1 (string-এর শেষ থেকে)।

এখন যতক্ষণ না দুই pointer একে অপরকে cross করে:

low → vowel পাওয়া পর্যন্ত সামনে যাবে।

high → vowel পাওয়া পর্যন্ত পেছনে আসবে।

দুটো vowel পেলে, তাদের swap করব।

এভাবে vowel গুলো reverse হয়ে যাবে।

🔹 কেন এটা Accepted হবে?

আমরা শুধু vowel character গুলো swap করছি।

low < high condition রাখায়, সঠিকভাবে vowel swap হচ্ছে।

একবার পুরো string maximum n বার loop হবে। অর্থাৎ O(n) time complexity → constraint (3*10^5 পর্যন্ত) এর জন্য efficient ✅।

🔹 Step by Step Example দিয়ে বোঝাই
Example 1:

s = "IceCreAm"

Vowels = I, e, e, A

Reverse হলে → A, e, e, I

Execution:

low=0 → 'I' vowel ✅

high=6 → 'm' vowel না → পিছিয়ে আসে → high=6 থেকে 5 ('A') → vowel ✅

Swap → 'I' ↔ 'A' → s = "AceCreIm"

low=1 ('c') vowel না → যায় low=2 → 'e' vowel ✅

high=5 ('e') vowel ✅

Swap 'e' ↔ 'e' (কোনো পরিবর্তন হবে না)

শেষে result: "AceCreIm" ✅

Example 2:

s = "leetcode"

Vowels = e, e, o, e

Reverse করলে → e, o, e, e

Execution:

low=0 → 'l' vowel না → low=1 ('e') vowel ✅

high=7 → 'e' vowel ✅

Swap 'e' ↔ 'e' → কোনো পরিবর্তন নাই

low=2 ('e') vowel ✅

high=6 ('d') vowel না → পিছিয়ে high=5 ('o') vowel ✅

Swap 'e' ↔ 'o' → s = "leotcede"

তারপর low=3, high=4 → 't', 'c' vowel না, লুপ শেষ।

Final Output = "leotcede" ✅

🔹 কোন টেকনিক ব্যবহার হলো?

➡️ Two Pointers + Swapping technique।
এটা অনেক string problem এ use হয় যখন শুধু নির্দিষ্ট কিছু element কে left/right থেকে খুঁজে swap করতে হয়।

🔹 Summary (Bangla Shortcut Recap):

Vowel চেকের জন্য helper function বানানো।

দুই পাশে pointer বসিয়ে vowel খুঁজে swap করা।

এতে vowel reverse হয়ে যায়, consonant একই জায়গায় থাকে।

Complexity: O(n), যা constraint এর জন্য perfect।

তাহলে এই solution accepted হচ্ছে কারণ —

✅ Efficient (O(n))

✅ সঠিকভাবে vowel reverse করছে

✅ Consonant disturb করছে না


Full Code:
-----------

  class Solution
 {
public:
 bool TestVowel(char a)
 {
    if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||
        a=='A'||a=='E'||a=='I'||a=='O'||a=='U') 
        {
        return true;
    }
    return false;
 }
 void swap(char &a,char &b)
 {
    char temp=a;
    a=b;
    b=temp;
 }
    string reverseVowels(string s) 
    {
        int low=0;
        int high=s.size()-1;
        while(low<high)
        {
             while(low<high&&!TestVowel(s[low])) low++;
              while(low<high&&!TestVowel(s[high])) high--;
            if(/*TestVowel(s[low])&&TestVowel(s[high]&&*/low<high)
            {
               swap(s[low],s[high]);
                low++;
            high--;
            }
           
        }
        return s;
    }
};

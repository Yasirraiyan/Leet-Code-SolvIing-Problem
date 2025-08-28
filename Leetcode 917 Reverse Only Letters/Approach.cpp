১️⃣ প্রশ্ন পড়ে ভাবা (Problem Understanding)

প্রশ্নে বলা হয়েছে:

তোমার একটি স্ট্রিং s আছে।

সব English letters (a-z, A-Z) reverse করতে হবে।

সব non-letter character (যেমন: -, 1, !) তাদের অসলে অবস্থানেই থাকবে।

স্ট্রিংয়ের length 1 থেকে 100 এর মধ্যে।

উদাহরণ:

Input: "a-bC-dEf-ghIj"
Letters: a b C d E f g h I j  → reverse → j I h g f E d C b a
Output: "j-Ih-gfE-dCba"


চিন্তা করার উপায়:

যদি তুমি সব letter আলাদা করে reverse করতে চাও, non-letter কে “skip” করতে হবে।

এটা two-pointer technique দিয়ে খুব সহজে করা যায়।

২️⃣ Solution Approach (Technique)

Technique: Two-pointer approach

ধাপগুলো:

Pointers:

low = 0 (স্ট্রিং এর শুরু)

high = s.size() - 1 (স্ট্রিং এর শেষ)

Loop: while(low < high)

Check করো s[low] letter নাকি। যদি না হয় → low++

Check করো s[high] letter নাকি। যদি না হয় → high--

যদি উভয় letter হয় → swap(s[low], s[high])

তারপর low++, high--

Return: s

৩️⃣ Code ব্যাখ্যা (Line by Line)
class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int low = 0;                // শুরু pointer
        int high = s.size() - 1;    // শেষ pointer

        while(low < high) {         // loop চলবে যতক্ষণ low < high
            if(!isalpha(s[low])) {  // যদি low position এ letter না হয়
                low++;               // skip করে next position এ যাও
            }
            else if(!isalpha(s[high])) { // যদি high position এ letter না হয়
                high--;                 // skip করে previous position এ যাও
            }
            else {                       // উভয়ই letter হলে swap করো
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }

        return s;                        // reversed string return করো
    }
};


isalpha() function:

এটি চেক করে character letter কিনা।

isalpha('a') → true, isalpha('-') → false

swap() function:

দুইটা character এর value change করে দেয়

৪️⃣ Test Case দিয়ে চিন্তা করা
Test Case 1:
s = "ab-cd"


Step by step:

low=0, high=4
s[0]='a', s[4]='d'  → swap → "db-ca"
low=1, high=3
s[1]='b', s[3]='c'  → swap → "dc-ba"
low=2, high=2 → stop
Output: "dc-ba"


✅ Correct

Test Case 2:
s = "a-bC-dEf-ghIj"


Step by step:

Original letters only: a b C d E f g h I j
Reverse letters: j I h g f E d C b a

Loop:
- low=0('a'), high=12('j') → swap → j-bC-dEf-ghIa
- low=1('-') → skip low → low=2
- high=11('I') → swap → j-Ih-gfE-dCba
...
Final: "j-Ih-gfE-dCba"


✅ Correct

Test Case 3:
s = "Test1ng-Leet=code-Q!"


Step by step:

non-letters: 1, -, =, ! → skip

letters reversed → "Qedo1ct-eeLg=ntse-T!"

Output matches expected

✅ Correct

৫️⃣ কেন two-pointer technique ব্যবহার হলো?

আমরা O(n) time এ solution চাই।

Two-pointer technique দিয়ে একবার loop চালিয়ে সব letter swap করা যায়।

Non-letter skip করার জন্য extra space লাগবে না।

Complexity:

Time: O(n) → একবার traverse করতে হবে

Space: O(1) → inplace swap

৬️⃣ চিন্তা করার ধাপ (Problem → Code)

প্রশ্ন বুঝো: কোন character reverse হবে, কোন থাকবে।

কোন technique efficient → two-pointer

Edge case: স্ট্রিং সব letter না হলেও কাজ করবে

Step-by-step swap & skip logic → code এ implement

Full Code:
-----------
  class Solution
 {
public:
    string reverseOnlyLetters(string s) 
    {
        int low=0;
        int high=s.size()-1;
        while(low<high)
        {
            if(!isalpha(s[low]))
            {
                low++;
            }
            else  if(!isalpha(s[high]))
            {
                high--;
            }
            else 
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};

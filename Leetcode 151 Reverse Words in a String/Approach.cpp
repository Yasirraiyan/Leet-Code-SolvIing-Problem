১️⃣ প্রশ্নটি বুঝে নেওয়া (Problem Understanding)

Question summary:

তোমাকে একটি string s দেওয়া হয়েছে।

কাজ: s-এর সব words-এর order reverse করতে হবে।

Constraint:

Words এক বা একাধিক space দিয়ে আলাদা হতে পারে।

Extra space, leading space, trailing space থাকলে ignore করতে হবে।

Output-এ শুধু একটিমাত্র space থাকবে word-এর মধ্যে।

Examples থেকে বুঝা:

"the sky is blue" → "blue is sky the"

" hello world " → "world hello" (extra space remove করা হয়েছে)

"a good example" → "example good a" (extra spaces reduce করা হয়েছে)

→ এই প্রশ্নটা basically হলো: Words কে extract করে reverse করা এবং single space দিয়ে join করা।

২️⃣ Approach ভাবা (How to think solution)

১. Word extract করা:

আমাদের ঠিক কোন word আছে, সেটা বের করতে হবে।

String-এ অনেক extra space থাকতে পারে।

তাই simple stringstream বা split technique use করা যায়।

২. Word reverse করা:

Extract করা words গুলোকে reverse করে দিতে হবে।

Reverse করা হলে order ঠিক হয়ে যাবে।

৩. Word join করা:

Reverse word list থেকে final sentence তৈরি করা।

Join করতে হবে single space দিয়ে, এবং extra space থাকবে না।

→ এই approach-এর advantage:

সহজ, readable।

O(n) time, O(n) extra space (vector of words)

৩️⃣ Code logic line-by-line Bangla explanation
class Solution
{
public:
    // helper function: vector<string> reverse
    vector<string> reverse(vector<string>& vs)
    {
        int low = 0;
        int high = vs.size() - 1;
        while(low < high)
        {
            swap(vs[low], vs[high]); // first word ↔ last word
            low++;
            high--;
        }
        return vs; // reversed word vector
    }

    string reverseWords(string s)
    {
        string word;  
        stringstream ss(s); // string কে stream-এ convert করি
        vector<string> words; 
        while(ss >> word)
        {
            words.push_back(word); // stream থেকে word টা read করে vector-এ push
        }

        reverse(words); // helper function দিয়ে vector reverse করা

        string reversedSentence;
        for(int i = 0; i < words.size(); i++)
        {
            reversedSentence += words[i]; // word add করা
            if(i != words.size() - 1) 
                reversedSentence += " "; // শুধু word-এর মধ্যে space add
        }

        return reversedSentence; // final reversed sentence return
    }
};

৪️⃣ Test Case দিয়ে Step-by-step Execution

Example: s = " hello world "

stringstream ss(s) → "hello world" (automatic ignore leading/trailing space)

while(ss >> word) →

word = "hello" → push_back → words = ["hello"]

word = "world" → push_back → words = ["hello", "world"]

reverse(words) → words = ["world", "hello"]

Join with space → reversedSentence = "world hello"

Return "world hello" ✅

→ perfectly matches expected output।

৫️⃣ Technique used and why it works

Stringstream Technique

stringstream automatically ignore করে multiple spaces, leading/trailing spaces।

Perfect for extracting words.

Vector reverse Technique

Words vector reverse করা হচ্ছে O(n) time-এ।

Relative order ঠিক থাকছে।

Join with single space

Prevent extra space.

→ এই technique use করা হয়েছে কারণ:

Clean, simple solution

Extra space issue handled automatically

O(n) time complexity, space vector + final string → O(n)

৬️⃣ Key Points তুমি মনে রাখবে

এই প্রশ্নে reverse করার জন্য যে technique apply করা হয়েছে, সেটা হলো Two-Pointer Swap Technique। আমি ধাপে ধাপে ব্যাখ্যা করি কিভাবে এটা কাজ করছে।

১️⃣ কোন vector/array reverse করতে হবে

আমরা words কে একটি vector<string> এ রেখেছি:

words = ["the", "sky", "is", "blue"];


আমাদের goal:

["blue", "is", "sky", "the"]

২️⃣ Two-Pointer Swap Technique ব্যাখ্যা

Concept:

দুইটা pointer use করি:

low = 0 → প্রথম element থেকে শুরু

high = n-1 → last element থেকে শুরু

Loop until low < high

প্রতিবার swap করি:

swap(vs[low], vs[high]);
low++;
high--;


Logic: প্রথম element ↔ last element, second ↔ second last, …

শেষে pointers meet করলে সব elements reverse হয়ে যায়।

Example:

words = ["the", "sky", "is", "blue"];
low = 0, high = 3

1st iteration: swap("the", "blue") → ["blue", "sky", "is", "the"], low=1, high=2
2nd iteration: swap("sky", "is") → ["blue", "is", "sky", "the"], low=2, high=1
Loop ends: reversed!

৩️⃣ কেন এই technique use করা হলো

Efficient:

O(n/2) swaps → O(n) time

In-place:

Vector নিজেই reverse, extra memory লাগে না

Simple:

কোন complex logic নেই, just two pointers

৪️⃣ Final note

Two-Pointer Swap হলো standard technique for reversing arrays or vectors in-place।

Competitive programming & interviews-এ এটা commonly use হয়।

তোমার এই solution-এ এটা helper function হিসেবে implement করা হয়েছে:

vector<string> reverse(vector<string>& vs)
{
    int low = 0;
    int high = vs.size() - 1;
    while(low < high)
    {
        swap(vs[low], vs[high]);
        low++;
        high--;
    }
    return vs;
}

Full Code:
----------

  class Solution
 {
public:
 vector<string> reverse(vector<string>&vs)
 {
    int low=0;
    int high=vs.size()-1;
    while(low<high)
    {
        swap(vs[low],vs[high]);
        low++;
        high--;
    }
    return vs;
 }
    string reverseWords(string s)
     {
          string word;  
        stringstream ss(s);
        vector<string>words;
        while(ss>>word)
        {
            words.push_back(word);
        }
      reverse(words);
         string reversedSentence;
    for(int i = 0; i < words.size(); i++)
     {
        reversedSentence += words[i];
        if(i != words.size() - 1) reversedSentence += " "; // add space between words
    }
    return reversedSentence;
    }
};

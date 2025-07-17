✅ Problem বুঝি:

> প্রশ্ন: তোমাকে এমন একটা স্ট্রিং s দেওয়া হয়েছে যেখানে শব্দ এবং স্পেস (space) আছে। তোমার কাজ হলো — সেই স্ট্রিং-এর শেষ শব্দের দৈর্ঘ্য (length) বের করা।



Word মানে কি?
একটি শব্দ হচ্ছে এমন একটা সাবস্ট্রিং যেখানে শুধু অক্ষর আছে, স্পেস না। যেমনঃ
👉 "Hello World" → শেষ শব্দ "World" → length = 5
👉 "   fly me   to   the moon  " → শেষ শব্দ "moon" → length = 4



---

✅ কিভাবে চিন্তা করা যায় সমাধান:

🔹 তুমি যেহেতু জানো যে space দিয়ে word গুলো আলাদা করা আছে, তাহলে split করে সব word আলাদা করা যায়।

🔹 তারপর যে word গুলো পেলে, তার মধ্যে শেষ word টা নিয়ে তার length বের করলেই তো হয়।


---

✅ কোড ব্যাখ্যা (line by line in Bangla):

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string>words;            // সব word গুলো রাখার জন্য একটি vector নিচ্ছি
        stringstream ss(s);            // string কে word আলাদা করতে stringstream ব্যবহার করব
        string word;                   // প্রতিটা শব্দ রাখার জন্য একটি temporary string

        while(ss >> word)              // stringstream থেকে এক এক করে word বের করবো
        {
            words.push_back(word);     // প্রতিটা word vector-এ সংরক্ষণ করছি
        }

        string a = words[words.size()-1];  // vector-এর শেষ element (শেষ word) নিচ্ছি
        int count = 0;
        for(int i = 0; i < a.size(); i++)  // সেই word এর character গুলো count করছি
        {
            count++;
        }
        return count;                       // count return করছি
    }
};


---

✅ Test Case ধরে ব্যাখ্যা (line by line):

🧪 Test Case 1:

Input: s = "Hello World"

stringstream ss(s) → string কে শব্দভাগ করবে।

while(ss >> word):

word = "Hello" → push → words = ["Hello"]

word = "World" → push → words = ["Hello", "World"]



➡️ শেষ word = "World" → size = 5 → return 5 ✅


---

🧪 Test Case 2:

Input: s = "   fly me   to   the moon  "

stringstream ignore করে leading/trailing spaces → word গুলো পাবে:

"fly", "me", "to", "the", "moon" → vector = ["fly", "me", "to", "the", "moon"]


শেষ word = "moon" → size = 4 → return 4 ✅



---

🧪 Test Case 3:

Input: s = "luffy is still joyboy"

word গুলো = ["luffy", "is", "still", "joyboy"]

শেষ word = "joyboy" → size = 6 → return 6 ✅


 Full Code:
--------------

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word)
            {
                words.push_back(word);
            }
        string a=words[words.size()-1];
        int count=0;
        for(int i=0;i<a.size();i++)
            {
                count++;
            }
        return count;
    }
};

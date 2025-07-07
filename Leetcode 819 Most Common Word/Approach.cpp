🔸 ১. Word গুনতে হবে → মানে Frequency Count দরকার
🔹 প্রশ্নে বলা হয়েছে:

"সবচেয়ে বেশি বার যে শব্দটা এসেছে (most frequent word)"
মানে, আমাদের প্রতিটা শব্দের সংখ্যা গুনতে হবে।

📌 এখানেই মাথায় আসবে:
"আমি কি একটা HashMap/Dictionary ব্যবহার করতে পারি?"
➡️ হ্যাঁ, এটা হলো word frequency বের করার standard উপায়।

cpp
Copy
Edit
unordered_map<string, int> freq;
🔸 ২. Punctuation বাদ দিতে হবে (",", ".", "!" ইত্যাদি)
🔹 প্রশ্নে বলা হয়েছে:

"words can not contain punctuation symbols"

মানে, ball, এবং ball এক জিনিস। তাই punctuation গুলো রিমুভ করতে হবে।

📌 ভাববে:

আমি paragraph টাকে traverse করে isalnum() বা isalpha() দিয়ে শুধু letter নিলেই তো punctuation বাদ যাবে।

আর punctuation পেলেই space দিয়ে দিই, যেন পরে split করা যায়।

🔸 ৩. Case insensitive → ছোট হাতের অক্ষরে কনভার্ট করতে হবে
🔹 প্রশ্নে বলা হয়েছে:

"The words in paragraph are case-insensitive"

📌 বুঝতে হবে:

Ball, BALL, ball → এগুলো সব একই।

তাই, পুরো string টাকে tolower() দিয়ে ছোট হাতের অক্ষরে রূপান্তর করে নিতে হবে।

🔸 ৪. Words আলাদা করা (Split into words)
📌 যতক্ষণ পর্যন্ত paragraph পুরোপুরি clean না করি, ততক্ষণ পর্যন্ত word split করতে পারব না।
তাই punctuation remove করে → space দিয়ে split করব।
C++ এ এ জন্য stringstream ব্যবহার করা হয়।

🔸 ৫. Banned word বাদ দিতে হবে
🔹 প্রশ্নে বলা হয়েছে:

"Return the most frequent word that is not banned."

📌 তাই ভাববে:

একটা unordered_set<string> bannedWords; রাখি।

তারপর word traverse করার সময় যদি সেটা banned-এ না থাকে → তখনই গুনবো।

🔸 ৬. Max Frequency Word Return করতে হবে
📌 এখন hashmap তৈরি হয়ে গেছে।
তুমি চেক করবে কোন word এর frequency সবচেয়ে বেশি:

cpp
Copy
Edit
int maxFreq = 0;
string ans = "";
for (auto it : freq) {
    if (it.second > maxFreq) {
        maxFreq = it.second;
        ans = it.first;
    }
}
return ans;
🧠 সংক্ষেপে চিন্তার সারসংক্ষেপ:
ধাপ	চিন্তা করবো
🔹 Step 1	punctuation বাদ দিয়ে সব lowercase এ কনভার্ট করবো
🔹 Step 2	string টাকে word-এ ভেঙে ফেলবো
🔹 Step 3	banned list কে set এ রাখবো
🔹 Step 4	banned ছাড়া word গুলোর frequency count করবো
🔹 Step 5	সবচেয়ে বেশি যে word টা এসেছে সেটা return করবো

✅ উপসংহার (Conclusion)
এই প্রশ্নটা তোমাকে শেখায়:

Data clean কিভাবে করতে হয়

HashMap দিয়ে frequency count কিভাবে করতে হয়

Set দিয়ে banned word exclude করা যায় কিভাবে

Real-world string manipulation problem কিভাবে handle করতে হয়






🔶 প্রশ্ন বিশ্লেষণ (How to Think from the Question)
প্রশ্নে যা বলা আছে:

একটি string paragraph দেওয়া আছে।

একটি string array banned দেওয়া আছে।

তোমার কাজ হচ্ছে paragraph থেকে সবচেয়ে বেশি বার যেই শব্দটা এসেছে এবং সেটি banned list-এ নেই, সেই শব্দটি return করা।

বিশেষ নিয়ম:

Word গুলো case-insensitive (মানে "Ball" আর "ball" একই ধরা হবে)।

Punctuation (যেমন .,!?;) কে ignore করতে হবে।

Return হবে lowercase এ।

🔷 Step-by-Step Approach (সমাধানের ধাপগুলো):
Step 1: Paragraph-কে প্রি-প্রসেস করো:

সব punctuation বাদ দাও।

সব ছোটহাতের অক্ষরে রূপান্তর করো।

space দিয়ে word ভাগ করো।

**Step 2: Banned word গুলোকে Set-এ রাখো (O(1) lookup speed)।

**Step 3: Frequency Count করো (HashMap দিয়ে) banned ছাড়া word গুলোর।

**Step 4: সবচেয়ে বেশি যে word এসেছে সেটা খুঁজে বের করো।

✅ তোমার দেওয়া কোড + ব্যাখ্যা:
cpp
Copy
Edit
class Solution 
{
public:
    // 🔸 Utility function: findMax() => সর্বোচ্চ frequency খুঁজে বের করে
    int findMax(vector<int>& arr)
    {
        int maxElement = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] > maxElement) 
            {
                maxElement = arr[i]; 
            }
        }
        return maxElement;
    }
🔹 ব্যাখ্যা:
findMax() ফাংশনটা vector থেকে সবচেয়ে বড় সংখ্যা খুঁজে বের করে — এটা frequency max খুঁজতে ব্যবহৃত হবে।

cpp
Copy
Edit
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        string cleanText = "";

        // 🔸 Step 1: paragraph থেকে punctuation বাদ দিয়ে সব ছোটহাতের অক্ষরে রূপান্তর
        for (char c : paragraph)
        {
            if (isalpha(c))
            {
                cleanText += tolower(c); 
            } 
            else 
            {
                cleanText += ' ';
            }
        }
🔹 ব্যাখ্যা:

isalpha(c) চেক করে অক্ষর কিনা (punctuation বাদ দেয়)

সব lowercase করে

punctuation এর জায়গায় space বসানো হয় যাতে পরে সহজে word split করা যায়

cpp
Copy
Edit
        vector<string> words;

        stringstream ss(cleanText);
        string word;

        // 🔸 Step 2: string থেকে প্রতিটি শব্দ আলাদা করো (split by space)
        while (ss >> word) 
        {
            words.push_back(word);
        }
🔹 ব্যাখ্যা:

stringstream দিয়ে space অনুযায়ী word split করে একটা vector এ রাখছে।

cpp
Copy
Edit
        unordered_set<string> set1;
        for (int i = 0; i < banned.size(); i++)
        {
            set1.insert(banned[i]);
        }
🔹 ব্যাখ্যা:

banned word গুলোকে unordered_set এ রাখছে যাতে lookup O(1) টাইমে হয়।

cpp
Copy
Edit
        vector<string> v;
        for (int j = 0; j < words.size(); j++)
        {
            if (set1.find(words[j]) == set1.end()) // 🔸 not banned
            {
                v.push_back(words[j]);
            }
        }
🔹 ব্যাখ্যা:

সব word থেকে banned না এমন word গুলো আলাদা করে রাখছে vector v তে।

cpp
Copy
Edit
        unordered_map<string, int> freq;
        for (int k = 0; k < v.size(); k++)
        {
            freq[v[k]]++;
        }
🔹 ব্যাখ্যা:

frequency হিসাব রাখছে HashMap দিয়ে।

cpp
Copy
Edit
        vector<int> f;
        for (auto it : freq)
        {
            f.push_back(it.second);
        }

        int maxfreq = findMax(f);
🔹 ব্যাখ্যা:

frequency গুলো আলাদা করে একটা vector এ রাখছে, তারপর সর্বোচ্চটা খুঁজে maxfreq বের করছে।

এই অংশটা সরাসরি HashMap থেকেই max খুঁজলে efficient হতো। নিচে suggest করব।

cpp
Copy
Edit
        string ans = "";
        for (auto it : freq)
        {
            if (it.second == maxfreq)
            {
                ans += it.first;
                break;
            }
        }

        return ans;
    }
};
🔹 ব্যাখ্যা:

যে word-এর frequency maxfreq এর সমান, সেটাই return করছে।

🧪 Test Case Walkthrough:
✅ Test Case 1:
cpp
Copy
Edit
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
banned = ["hit"]
Step-by-step:

Punctuation remove → "bob hit a ball the hit ball flew far after it was hit"

Lowercase → ঠিকই হয়েছে

Split → [bob, hit, a, ball, the, hit, ball, flew, far, after, it, was, hit]

Remove banned "hit" → [bob, a, ball, the, ball, flew, far, after, it, was]

Frequency:

ball → 2

বাকিগুলো 1 বার করে

✅ Answer = "ball"

Full Code:
------------

  class Solution 
{
public:
    int findMax(vector<int>&arr)
     {
    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); ++i)
     {
        if (arr[i] > maxElement) 
        {
            maxElement = arr[i]; 
        }
    }
    return maxElement;
}
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
       string cleanText = "";


for (char c : paragraph)
 {
    if (isalpha(c))
     {
        cleanText += tolower(c); 
    } else 
    {
        cleanText += ' ';
    }
}


vector<string> words;




    
    stringstream ss(cleanText);
    string word;

    while (ss >> word) 
    {
        words.push_back(word);
    }
    unordered_set<string>set1;
    for(int i=0;i<banned.size();i++)
    {
      set1.insert(banned[i]);
    }
    vector<string>v;
    for(int j=0;j<words.size();j++)
    {
      if(set1.find(words[j])==set1.end())
      {
        v.push_back(words[j]);
      }
    }
    unordered_map<string,int>freq;
    for(int k=0;k<v.size();k++)
    {
      freq[v[k]]++;
    }
    vector<int>f;
    for(auto it:freq)
    {
      f.push_back(it.second);
    }
    int maxfreq=findMax(f);
    string ans="";
    for(auto it:freq)
    {
      if(it.second==maxfreq)
      {
           ans+=it.first;
           break;
      }
    }
    return ans;
    }
};

🧠 প্রশ্ন বিশ্লেষণ (Understanding the Problem)
প্রশ্ন বলছে:

দুটি বাক্য আছে — s1 এবং s2, যেখানে শব্দগুলো একটি করে space দিয়ে আলাদা।

আমাদের এমন শব্দ বের করতে হবে যেগুলো:

s1-এ ঠিক একবার এসেছে এবং s2-তে একবারও আসেনি
অথবা

s2-তে ঠিক একবার এসেছে এবং s1-তে একবারও আসেনি

Output: এমন সব uncommon word-এর list।

✅ তোমার কোডের ব্যাখ্যা (Line-by-Line Bangla Explanation)
cpp
Copy
Edit
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
🔸 class Solution এর মধ্যে uncommonFromSentences ফাংশন লেখা হয়েছে, যেখানে ইনপুট s1 এবং s2 নামক দুটি string বাক্য এবং রিটার্ন করবে vector<string> — অর্থাৎ uncommon শব্দের লিস্ট।

cpp
Copy
Edit
vector<string> words1;
stringstream ss1(s1);  
string word1;

while (ss1 >> word1) {
    words1.push_back(word1);
}
🔹 এখানে তুমি s1 কে word এ ভেঙে words1 ভেক্টরে রাখছো।
🔸 stringstream ব্যবহার করে space দিয়ে আলাদা প্রতিটি শব্দ >> অপারেটরে পড়া যায়।

cpp
Copy
Edit
vector<string> words2;
stringstream ss2(s2);  
string word2;

while (ss2 >> word2) {
    words2.push_back(word2);
}
🔹 একইভাবে s2 বাক্যটাকে ভেঙে words2 ভেক্টরে রাখলে।

cpp
Copy
Edit
unordered_set<string> set1, set2;
unordered_map<string,int> freq1, freq2;
🔸 set1 ও set2: প্রতিটি বাক্যের মধ্যে কোন শব্দ আছে, তা দ্রুত চেক করতে (for existence checking)।
🔸 freq1 ও freq2: প্রতিটি বাক্যের শব্দ কয়বার এসেছে, তা গুনতে (frequency tracking)।

cpp
Copy
Edit
for(int i = 0; i < words1.size(); i++) {
    set1.insert(words1[i]);
    freq1[words1[i]]++;
}
🔹 এখানে s1 এর প্রতিটি শব্দ set1 এবং freq1 এ যোগ করছো।

cpp
Copy
Edit
for(int j = 0; j < words2.size(); j++) {
    set2.insert(words2[j]);
    freq2[words2[j]]++;
}
🔹 একই কাজ s2 বাক্যের জন্য।

cpp
Copy
Edit
vector<string> ans;
🔸 Output result রাখার জন্য।

cpp
Copy
Edit
for(int k = 0; k < words2.size(); k++) {
    if ((set1.find(words2[k]) == set1.end()) && (freq2[words2[k]] == 1)) {
        ans.push_back(words2[k]);
    }
}
🔹 এই লুপে s2-এর প্রতিটি শব্দ দেখে চেক করছো:

যদি ওই শব্দ s1-এ না থাকে

এবং s2-তে একবারই আসে → তখনই সেই uncommon word।

cpp
Copy
Edit
for(int m = 0; m < words1.size(); m++) {
    if ((set2.find(words1[m]) == set2.end()) && (freq1[words1[m]] == 1)) {
        ans.push_back(words1[m]);
    }
}
🔹 একইভাবে s1-এর মধ্যে যেগুলো আছে s2-তে নেই এবং s1-এ মাত্র একবার এসেছে → সেই uncommon word।

cpp
Copy
Edit
return ans;
🔸 শেষে uncommon শব্দগুলোর list return করছো।

🧪 Test Case দিয়ে যাচাই (With Explanation):
cpp
Copy
Edit
int main() {
    Solution sol;
    vector<string> result = sol.uncommonFromSentences("this apple is sweet", "this apple is sour");
    for(string word : result) cout << word << " ";
    return 0;
}
Input:
ini
Copy
Edit
s1 = "this apple is sweet"
s2 = "this apple is sour"
Step by Step:
s1 → {this, apple, is, sweet}

s2 → {this, apple, is, sour}

Frequency map:

freq1 → this(1), apple(1), is(1), sweet(1)

freq2 → this(1), apple(1), is(1), sour(1)

Now check:

sweet: only in s1, freq = 1 ✅

sour: only in s2, freq = 1 ✅

Output:
css
Copy
Edit
["sweet", "sour"]
✅ সঠিক উত্তর।

✅ তোমার সমাধান কেন সঠিক?
তুমি word frequency + existence দুইটাই ব্যবহার করেছো।

তোমার লজিক অনুযায়ী “একটা বাক্যে আছে, আরেকটায় নেই এবং মাত্র একবার এসেছে” → এটাই তো uncommon definition।

তুমি line-by-line check করেছো প্রতিটি বাক্যের জন্য আলাদাভাবে।

📌 সংক্ষেপে:
তুমি প্রথমে word গুলো ভেঙে list বানিয়েছো ✅

তারপর frequency এবং presence check করার জন্য set ও map ব্যবহার করেছো ✅

তারপর logic চেক করে output বানিয়েছো ✅

Full Code:
----------
class Solution 
{
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
      vector<string> words1;

    stringstream ss1(s1);  
    string word1;

    while (ss1>> word1) 
    {       
        words1.push_back(word1); 
    }
  vector<string> words2;

    stringstream ss2(s2);  
    string word2;

    while (ss2>> word2) 
    {       
        words2.push_back(word2); 
    }  
    unordered_set<string>set1;
    unordered_set<string>set2;
    unordered_map<string,int>freq1;
     unordered_map<string,int>freq2;
    for(int i=0;i<words1.size();i++)
    {
      set1.insert(words1[i]);
      freq1[words1[i]]++;
    }
    for(int j=0;j<words2.size();j++)
    {
      set2.insert(words2[j]);
      freq2[words2[j]]++;
    }
    vector<string>ans;
    for(int k=0;k<words2.size();k++)
    {
      if((set1.find(words2[k])==set1.end())&&(freq2[words2[k]]==1))
      {
          ans.push_back(words2[k]);
      }
    }
    for(int m=0;m<words1.size();m++)
    {
      if(set2.find(words1[m])==set2.end()&&(freq1[words1[m]]==1))
      {
          ans.push_back(words1[m]);
      }
    }
return ans;
    }
};

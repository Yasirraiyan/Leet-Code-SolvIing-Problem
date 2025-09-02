Problem Understanding (কিভাবে তুমি ভাবতে পারো)

Question:
তোমাকে একটি string s দেওয়া আছে।
তুমি সেই string কে এমনভাবে sort করতে হবে যাতে character এর frequency অনুযায়ী descending order থাকে।

Example thinking:

"tree" → 'e' দুইবার আছে, 't' এবং 'r' একবার আছে।

তাই result হবে "eert" বা "eetr"। 'e' দুইবার consecutive থাকতে হবে।

"cccaaa" → 'c' এবং 'a' তিনবার।

তাই "cccaaa" বা "aaaccc" valid।

"cacaca" invalid কারণ same character একসাথে নেই।

Key insight:

প্রথমে frequency বের করতে হবে।

তারপর highest frequency character গুলো আগে বসাতে হবে।

Same frequency হলে order arbitrary হতে পারে।

Solution Approach (কোড পড়ে কিভাবে ভাবা যায়)
class Solution {
public:
    string frequencySort(string s) 
    {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> freq;


unordered_map<char,int> freq; → Step 1: Frequency map

প্রতিটি character এর frequency count করা।

Example: "tree" → {t:1, r:1, e:2}

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }


Step 2: Map fill করা

প্রতিটি character loop করে count increase।

        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }


Step 3: Max-heap তৈরী করা

priority_queue<pair<int,char>> → frequency অনুযায়ী descending order।

Pair = {frequency, char}

Example: "tree" → pq: [(2,'e'), (1,'t'), (1,'r')]

        string ans="";
        while(!pq.empty())
        {
            char a=pq.top().second;
            int x=pq.top().first;
            pq.pop();   
            ans.append(x,a);
        }


Step 4: Build the answer

pq থেকে top বের করে string এ append করা।

ans.append(x,a) → a character x times add করবে।

Example:

Top → (2,'e') → append "ee"

Next → (1,'t') → append "t" → "eet"

Next → (1,'r') → append "r" → "eetr"

        return ans;
    }
};


Step 5: Return result

Final string return।

Test Case Step-by-Step

Input: "tree"

Frequency map: {t:1, r:1, e:2}

Max-heap push: [(2,e),(1,t),(1,r)]

Build string:

Pop (2,e) → ans = "ee"

Pop (1,t) → ans = "eet"

Pop (1,r) → ans = "eetr"

Output: "eetr" (valid)

Input: "cccaaa"

Frequency map: {c:3, a:3}

Max-heap push: [(3,c),(3,a)]

Build string:

Pop (3,c) → ans = "ccc"

Pop (3,a) → ans = "cccaaa"

Output: "cccaaa" (valid)

Input: "Aabb"

Frequency map: {A:1, a:1, b:2}

Max-heap push: [(2,b),(1,a),(1,A)]

Build string:

Pop (2,b) → ans = "bb"

Pop (1,a) → ans = "bba"

Pop (1,A) → ans = "bbAa"

Output: "bbAa" (valid)

Summary of Approach (সংক্ষেপে)

Character frequency বের করো → unordered_map

Frequency অনুযায়ী max-heap বানাও → priority_queue<pair<int,char>>

Heap থেকে pop করে string বানাও → ans.append(freq, char)

Return ans

Why accepted:

Time Complexity: O(n + k log k)


  Full Code:
---------------

  class Solution 
{
public:
    string frequencySort(string s) 
    {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty())
        {
            char a=pq.top().second;
            int x=pq.top().first;
            pq.pop();   ans.append(x,a);
        }
        return ans;
    }
};

তুমি যেভাবে প্রশ্নটি পড়ে সমাধান করলে সেটা অনেক ভালোভাবে বুঝে ফেলেছো। এখন আমি ধাপে ধাপে প্রশ্ন বিশ্লেষণ → চিন্তা করার কৌশল → কোড লেখার ধাপ → টেস্ট কেস ব্যাখ্যা — সব কিছু বাংলায় ব্যাখ্যা করছি যাতে ভবিষ্যতে তুমি নিজের মতো করেই এমন সমস্যা সমাধান করতে পারো।

🔶 Problem টা কী চাচ্ছে?
তোমাকে নিজে নিজে একটি HashMap ক্লাস ডিজাইন করতে হবে (মানে তুমি unordered_map, map, বা অন্য কোনো STL/hash lib ব্যবহার করতে পারবে না। তুমি যেটা করেছো সেটা ভুল হলেও প্রাথমিক ধারণা ভালো ছিল)।

তোমার ক্লাসে এই ৩টা কাজ করতে পারতে হবে:

🔸 ফাংশনসমূহ:
put(key, value) → key থাকে কিনা দেখবে, থাকলে আপডেট করবে, না থাকলে নতুনভাবে insert করবে।

get(key) → যদি key থাকে, তার value return করবে। না থাকলে -1 return করবে।

remove(key) → যদি key থাকে, তাহলে delete করবে।

✅ কীভাবে চিন্তা করলে?
প্রশ্নটি পড়েই বোঝা যায় — এটাকে আমরা একটা array of buckets + linked list বা array pair দিয়ে implement করতে পারি।

তবে তুমি যেহেতু unordered_map<int,int> দিয়ে করেছো, সেটা আসলে STL ব্যবহার হয়ে যায়। তাই আমরা এখন একদম scratch থেকে নিজের MyHashMap বানাবো যেন STL ব্যবহার না করি।

🔁 HashMap কিভাবে তৈরি করা যায়?
একটা সহজ ধারণা হলো:

✅ 1. হ্যাশ ফাংশন:
cpp
Copy
Edit
int hashKey = key % SIZE;
আমরা SIZE = 1000 ধরে নিলাম (মানে 1000টা bucket থাকবে)।

✅ 2. Hash Table → Array of Buckets:
cpp
Copy
Edit
vector<pair<int,int>> bucket[1000];
প্রতিটা bucket এ অনেকগুলো (key, value) জোড়া রাখা যাবে।

✅ Full Code (Without STL map, using array of buckets)
cpp
Copy
Edit
class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<pair<int, int>> bucket[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        // Empty constructor
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : bucket[idx]) {
            if (p.first == key) {
                p.second = value; // update if found
                return;
            }
        }
        bucket[idx].push_back({key, value}); // insert new
    }

    int get(int key) {
        int idx = hash(key);
        for (auto &p : bucket[idx]) {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        for (auto it = bucket[idx].begin(); it != bucket[idx].end(); ++it) {
            if (it->first == key) {
                bucket[idx].erase(it);
                return;
            }
        }
    }
};
🧠 তোমার চিন্তার ধাপ কী হওয়া উচিত ছিল?
প্রশ্নে বলেছে "Don't use any built-in hash table", তাই unordered_map use করা যাবে না।

নিজের একটা "hash function" লিখতে হবে → আমরা সাধারণভাবে %SIZE দিয়ে করি।

অনেক key একি bucket-এ পড়তে পারে → এজন্য collision handle করতে হয় → আমরা vector<pair<int,int>> ব্যবহার করে তা করেছি।

🔍 Test Case Walkthrough (Example অনুযায়ী):
cpp
Copy
Edit
MyHashMap myHashMap;

myHashMap.put(1, 1);  // Bucket[1 % 1000] → insert (1,1)
myHashMap.put(2, 2);  // Bucket[2 % 1000] → insert (2,2)

myHashMap.get(1);     // Bucket[1] → (1,1) found → return 1
myHashMap.get(3);     // Bucket[3] → empty → return -1

myHashMap.put(2, 1);  // Bucket[2] → (2,2) found → update to (2,1)

myHashMap.get(2);     // Bucket[2] → (2,1) → return 1

myHashMap.remove(2);  // Bucket[2] → remove (2,1)

myHashMap.get(2);     // Bucket[2] → not found → return -1
✅ Accepted কেন হলো?
তুমি যে version টা STL দিয়ে করেছো, সেটাতে unordered_map ব্যবহার করায় test case-গুলো ঠিকভাবে pass হয়েছে। কিন্তু লজিকটা তোমার মাথায় ছিল।

👉 এখন আমি যেটা দেখালাম সেটা হচ্ছে zero-library pure implementation, যেটা interview বা OJ-এ কখনো জিজ্ঞেস করলে কাজে দেবে।

📌 উপসংহার (Bangla Summary):
HashMap তৈরির জন্য নিজের hash function + collision resolution লজিক থাকতে হবে।

STL না ব্যবহার করে array/vector দিয়ে bucket তৈরি করতে হবে।

প্রত্যেকটি bucket-এ pair<key,value> রেখেছি যাতে দ্রুত খুঁজে পাওয়া যায়।

কোড স্ট্রাকচার ও লজিক বুঝে লিখলে তোমার অনেক সময় বাঁচবে এবং প্রশ্ন যেটা চাচ্ছে সেটা ঠিকমতো পূরণ হবে।

Full Code:
----------

  class MyHashMap {
public:
 unordered_map<int,int>freq;
    MyHashMap() {
       // MyHashMap m;//=new MyHashMap();
    }
    
    void put(int key, int value) {
      if(freq.find(key)!=freq.end())
      {
        freq.erase(key);
        freq.insert({key,value});
      }
      else
        freq.insert({key,value});
    }
    
    int get(int key) {
        if(freq.find(key)!=freq.end())
        {
          return freq[key];
        }
        else
        return -1;
    }
    
    void remove(int key) {
        if(freq.find(key)!=freq.end())
        {
          freq.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

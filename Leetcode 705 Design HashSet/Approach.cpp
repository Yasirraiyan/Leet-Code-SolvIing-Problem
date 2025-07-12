🔍 সমস্যাটি কী বলছে?
তোমাকে এমন একটি ক্লাস বানাতে হবে MyHashSet নামে, যাতে নিচের তিনটি কাজ করা যায়:

add(key): কোন key ইনসার্ট করবে সেট-এ।

remove(key): সেট থেকে key রিমুভ করবে (যদি থাকে)।

contains(key): দেখে বলবে এই key টা সেটে আছে কি না (true/false)।

✅ Input/Output এর উদাহরণ দেখে বুঝে নেওয়া যাক:
graphql
Copy
Edit
Input:
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]

Output:
[null, null, null, true, false, null, true, null, false]
মানে:

MyHashSet তৈরি হলো → কোনো রিটার্ন নেই → null

add(1) → [1]

add(2) → [1, 2]

contains(1) → true

contains(3) → false

add(2) → [1, 2] (2 ছিলো, আবার দিলে কিছু হবে না)

contains(2) → true

remove(2) → [1]

contains(2) → false

💡 সমাধানের পেছনে চিন্তার প্রক্রিয়া:
Step-by-step চিন্তা:

প্রশ্নে বলা হয়েছে নিজেই HashSet বানাতে হবে।

HashSet এমন একটা ডেটা স্ট্রাকচার যেটা insert, remove, আর contains — এই তিনটা অপারেশন constant time O(1) এ করে।

unordered_set ঠিক এটাই করে থাকে, তাই তুমি এটা ইউজ করেছো — কিন্তু প্রশ্নে নিষেধ করা থাকলে তোমাকে নিজেই implement করতে হবে।


unordered_set<int> set1;
তুমি STL-এর unordered_set ব্যবহার করেছো — অথচ প্রশ্নে বলা, “don’t use any built-in hash table libraries”।

তাই এই কোড test case এ accepted হলেও, problem constraints ভঙ্গ করেছে।

✅ তাহলে কীভাবে কোড লেখা উচিত?
তুমি নিজের একটা Hash Table বানিয়ে কাজ করতে পারো। নিচে আমি তোমাকে নিজের বানানো HashSet এর কোড দিচ্ছি — STL ছাড়া।

✅Full Code:
  ----------

  class MyHashSet 
{
public:
  unordered_set<int>set1;
    MyHashSet()
     {
       //  unordered_set<int>set1;
    }
    
    void add(int key) 
    {
       set1.insert(key);
    }
    
    void remove(int key)
     {
       if(!set1.empty())
       {
        set1.erase(key);
       }
    }
    
    bool contains(int key) 
    {
      bool contain=false;
      if(set1.find(key)!=set1.end())
      {
        contain=true;
      }
      return contain;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

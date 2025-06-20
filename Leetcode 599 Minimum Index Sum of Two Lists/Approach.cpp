🔶❓ Problem Summary (Bangla):

তোমাকে দুটি স্ট্রিং-এর লিস্ট দেওয়া আছে — list1 এবং list2।
তুমি এমন common string খুঁজবে যা দুটি লিস্টেই আছে এবং তার i + j (index যোগফল) সবচেয়ে কম।
একাধিক common string থাকতে পারে যাদের index যোগফল সমান — সবগুলো return করতে হবে।


---

🧠 চিন্তা করার ধাপ:

1. Common string বের করতে হবে ⇒ তাই unordered_set দিয়ে list1 রাখি।


2. তারপর list2 তে ঘুরি, যদি কোনো স্ট্রিং common হয় তাহলে list1 থেকে তার index বের করি।


3. i + j হিসাব করি (index যোগফল)। যদি এই sum সবচেয়ে ছোট হয় তাহলে reserve ক্লিয়ার করে নতুনটা রাখি। যদি সমান হয়, নতুনটাও রাখি।




---

✅ Code Explanation Line-by-Line (Bangla):

class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)

🔹 ক্লাস Solution এর মধ্যে একটা ফাংশন বানিয়েছি findRestaurant
🔹 এটা দুটি ইনপুট নেয় list1 আর list2, আর রিটার্ন করে একটা vector<string> মানে common restaurant নামগুলোর লিস্ট।


---

unordered_set<string> r;
        for(int i = 0; i < list1.size(); i++)
        {
            r.insert(list1[i]);
        }

🔹 unordered_set ব্যবহার করেছি যাতে O(1) সময় কমন চেক করা যায়।
🔹 list1 এর সব স্ট্রিং r নামে সেটে রাখলাম।


---

int min = INT_MAX;
        vector<string> reserve;

🔹 min স্টোর করে রাখবে এখন পর্যন্ত পাওয়া সবচেয়ে ছোট i + j যোগফল।
🔹 reserve হচ্ছে উত্তর রাখার ভেক্টর।


---

for(int j = 0; j < list2.size(); j++)

🔹 list2 তে ঘুরবো index j নিয়ে।


---

if(r.find(list2[j]) != r.end())

🔹 যদি list2[j] স্ট্রিংটা list1 (মানে r) তে থাকে, তখন এটা একটা common string।


---

for(int i = 0; i < list1.size(); i++)
                {
                    if(list1[i] == list2[j])

🔹 এখন list1 থেকে ওই স্ট্রিং-এর index i বের করছি।
🔹 তুমি এখানে loop দিয়ে খুঁজে বের করেছো।


---

int sum = i + j;

🔹 index যোগফল হিসাব করছি: sum = i + j


---

if(sum < min)
                        {
                            reserve.clear();
                            reserve.push_back(list2[j]);
                            min = sum;
                        }

🔹 যদি এই যোগফল এখন পর্যন্ত সবচেয়ে ছোট হয় তাহলে:
  ✅ আগে যেগুলো ছিল সব মুছে ফেলি
  ✅ নতুনটা রাখি
  ✅ min আপডেট করি


---

else if(sum == min)
                        {
                            reserve.push_back(list2[j]);
                        }

🔹 যদি একই sum পাওয়া যায় তাহলে এটাকেও রেখে দিই।


---

break;
                    }
                }

🔹 একবার মিল পেলে break করে বাহিরে চলে আসি (কারণ list1[i] == list2[j] তো একবারই হবে, unique)।


---

return reserve;

🔹 শেষে common স্ট্রিংগুলো রিটার্ন করি যাদের index sum সবচেয়ে কম।

Full Code:
-----------++
class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_set<string>r;
        for(int i=0;i<list1.size();i++)
            {
                r.insert(list1[i]);
            }
        int min=INT_MAX;
        vector<string>reserve;
        for(int j=0;j<list2.size();j++)
            {
                if(r.find(list2[j])!=r.end())
                {
                    for(int i=0;i<list1.size();i++)
                        {
                            
                        if(list1[i]==list2[j])
                        {
                            int sum=i+j;
                            
                        if(sum<min)
                            {
                                
                            reserve.clear();
                    reserve.push_back(list2[j]);
                              
                              min=sum  ;
                            }
                            else if(sum==min)
                            {
                                reserve.push_back(list2[j]);
                            }
                            break;
                        }
                        }
                }
            }
        return reserve;
    
        
                
            
    }
};
  

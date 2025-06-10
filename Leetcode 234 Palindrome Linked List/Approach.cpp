🔍 প্রশ্ন বিশ্লেষণ (Reading the question and understanding the goal):
প্রশ্নে বলছে:
একটা singly linked list দেওয়া আছে।

চেক করতে হবে এটি Palindrome কিনা — মানে, লিস্টটি সামনে থেকে এবং পেছন থেকে পড়লেও যদি একই থাকে তাহলে এটি Palindrome।

✅ উদাহরণ:
Input: [1,2,2,1] → Palindrome → Output: true

Input: [1,2] → Not a palindrome → Output: false

✅ কোড এক্সপ্লেইনেশন (Line-by-line Bangla ব্যাখ্যা)
cpp
Copy
Edit
#include<stack> // স্ট্যাক লাইব্রেরি ইনক্লুড করা হয়েছে
cpp
Copy
Edit
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
isPalindrome ফাংশন শুরু, এটি একটা ListNode* (linked list এর head) ইনপুট নেয় এবং bool রিটার্ন করে।

cpp
Copy
Edit
        stack<ListNode*> st;
        ListNode* current = head;
এখানে একটা stack নেওয়া হয়েছে যাতে আমরা সব ListNode* পুশ করতে পারি।

current পয়েন্টার দিয়ে লিস্টে ট্রাভার্স করবো।

cpp
Copy
Edit
        while(current != nullptr)
        {
            st.push(current);
            current = current->next;
        }
পুরো লিংকড লিস্ট ট্রাভার্স করে প্রতিটা ListNode* স্ট্যাক-এ push করছি।

ফলে স্ট্যাক এ ঢুকবে: প্রথমে 1, তারপর 2, তারপর 2, তারপর 1।

cpp
Copy
Edit
        string reserve = "";
        while(!st.empty())
        {
            reserve += to_string(st.top()->val);
            st.pop();
        }
এখন স্ট্যাক থেকে pop করে প্রতিটা val কে স্ট্রিং এ যোগ করছি।

যেহেতু স্ট্যাক LIFO, তাই পেছন দিক থেকে ভ্যালুগুলা আসছে।

reserve স্ট্রিং এখন পুরো লিস্টের reverse order-এ ভ্যালু স্টোর করে।

উদাহরণ: [1,2,2,1] হলে, reserve হবে "1221"

cpp
Copy
Edit
        string reverese = "";
        for(int i = reserve.size() - 1; i >= 0; i--)
        {
            reverese += reserve[i];
        }
এবার reserve স্ট্রিং টা আবার রিভার্স করে নতুন একটা reverese স্ট্রিং তৈরি করলাম।

এখানে reverese = "1221" → রিভার্স করলে "1221"

cpp
Copy
Edit
        bool ispalindrome = false;
        if(reverese == reserve)
        {
            ispalindrome = true;
        }
এখন চেক করলাম reserve ও reverese একই কিনা। যদি হয়, তাহলে এটি palindrome।

cpp
Copy
Edit
        return ispalindrome;
    }
};
শেষে true বা false রিটার্ন করা হচ্ছে।

✅ Test Case Walkthrough:
Example: head = [1, 2, 2, 1]
Step 1: Stack Push
Stack (top → bottom)
1
2
2
1

Step 2: reserve = "" → "1221"
(স্ট্যাক থেকে pop করে val যোগ করলাম)

Step 3: reverese = "1221" (reserve রিভার্স করে)
Step 4: Comparison
"1221" == "1221" → ✅ True → Return true

🤔 কেন কোডটি Accepted হলো?
কোডটি ঠিকমত কাজ করছে এবং সঠিক output দিচ্ছে।

টাইম কমপ্লেক্সিটি: O(n) (একবার ট্রাভার্স এবং একবার স্ট্যাক পপ)

স্পেস কমপ্লেক্সিটি: O(n) (স্ট্যাকে n টা ListNode*)
  Full Code:
  ---------

  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<stack>
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<ListNode*>st;
        ListNode* current=head;
        while(current!=nullptr)
        {
          st.push(current);
          current=current->next;
        }
        string reserve="";
        while(!st.empty())
        {
          reserve+=to_string(st.top()->val);
          st.pop();
        }
        string reverese="";
        for(int i=reserve.size()-1;i>=0;i--)
        {
          reverese+=reserve[i];
        }
        bool ispalindrome=false;
        if(reverese==reserve)
        {
          ispalindrome=true;
        }
        return ispalindrome;
    }
};

🧠 প্রশ্ন বোঝার চেষ্টা (How to Understand the Problem):
প্রশ্ন বলছে:

একটি Linked List দেওয়া আছে। সব odd index (1st, 3rd, 5th…) এর নোডগুলো একসাথে রাখো, তারপর even index (2nd, 4th, 6th…) এর নোডগুলো রাখো।

📌 মনে রেখো, index মানে position, মানে 1-based position.

🎯 উদাহরণ:

yaml
Copy
Edit
Input:  [1, 2, 3, 4, 5]
Odd positions: 1, 3, 5 → [1, 3, 5]
Even positions: 2, 4   → [2, 4]
Output: [1, 3, 5, 2, 4]
🔎 তুমি কীভাবে চিন্তা করেছো? (Your approach):
তুমি ভেবেছো:

দুইটা আলাদা vector রাখব — একটা odd position এর জন্য (v2), একটা even position এর জন্য (v1)

তারপর এগুলাকে আবার একত্র করে নতুন লিস্ট বানিয়ে ফিরিয়ে দিব।

এটা লজিকালি সঠিক, তাই তোমার solution Accepted হয়েছে।

✅ কোড ব্যাখ্যা (Line-by-Line in Bangla):
cpp
Copy
Edit
vector<ListNode*> v1; // even position nodes
vector<ListNode*> v2; // odd position nodes
int index = 1;
🔹 v1 তে even indexed node গুলো রাখছো।
🔹 v2 তে odd indexed node গুলো রাখছো।

cpp
Copy
Edit
while (head != nullptr) {
    if (index % 2 == 0) v1.push_back(head);
    if (index % 2 != 0) v2.push_back(head);
    head = head->next;
    index++;
}
🔹 প্রতিটি নোডের জন্য, index দেখে তুমি ঠিক করছো সেটা even নাকি odd।
🔹 তারপর head কে পরের দিকে এগিয়ে নিচ্ছো।

cpp
Copy
Edit
vector<ListNode*> vf;
for (int j = 0; j < v2.size(); j++) vf.push_back(v2[j]); // odd nodes first
for (int k = 0; k < v1.size(); k++) vf.push_back(v1[k]); // then even nodes
🔹 সব odd নোড আগে রাখছো vf তে, তারপর even নোড।

cpp
Copy
Edit
if (vf.empty()) return nullptr;
ListNode* headd = vf[0]; // নতুন হেড
ListNode* curr = headd;
for (int i = 1; i < vf.size(); i++) {
    curr->next = vf[i];
    curr = curr->next;
}
curr->next = nullptr;
return headd;
🔹 এই অংশে তুমি নতুন লিস্ট তৈরি করছো — প্রতিটি নোডকে পরপর next করে দিয়েছো।
🔹 সবশেষে curr->next = nullptr; দিয়েছো যাতে লিস্টের শেষে কিছু random pointer না থাকে।

Test Code by testcase:
---------------------

✅ Test Case 1:
🔹 Input: head = [1, 2, 3, 4, 5]
🔧 Step-by-Step Execution:
Initial Linked List:
makefile
Copy
Edit
Index:     1   2   3   4   5
Nodes:    [1,  2,  3,  4,  5]
🔁 While Loop:
Iteration 1:
index = 1 → odd → v2 = [1]

Iteration 2:
index = 2 → even → v1 = [2]

Iteration 3:
index = 3 → odd → v2 = [1, 3]

Iteration 4:
index = 4 → even → v1 = [2, 4]

Iteration 5:
index = 5 → odd → v2 = [1, 3, 5]

🔗 Join vectors:
vf = [1, 3, 5, 2, 4]

🔄 Link Construction:
cpp
Copy
Edit
ListNode* headd = vf[0]; // 1
curr = headd;

curr->next = 3 → curr
curr->next = 5 → curr
curr->next = 2 → curr
curr->next = 4 → curr
curr->next = nullptr
✅ Final Linked List:
Copy
Edit
1 → 3 → 5 → 2 → 4
✅ Output:
cpp
Copy
Edit
[1, 3, 5, 2, 4]
✅ Test Case 2:
🔹 Input: head = [2, 1, 3, 5, 6, 4, 7]
Index-wise:
makefile
Copy
Edit
Index:     1   2   3   4   5   6   7
Nodes:    [2,  1,  3,  5,  6,  4,  7]
🔁 While Loop:
index	node	group	vector
1	2	odd	v2 = [2]
2	1	even	v1 = [1]
3	3	odd	v2 = [2, 3]
4	5	even	v1 = [1, 5]
5	6	odd	v2 = [2, 3, 6]
6	4	even	v1 = [1, 5, 4]
7	7	odd	v2 = [2, 3, 6, 7]

🔗 Final Merge:
vf = [2, 3, 6, 7, 1, 5, 4]

🔄 Link Build:
cpp
Copy
Edit
vf = [2, 3, 6, 7, 1, 5, 4]
ListNode* headd = vf[0]; // 2

→ 3 → 6 → 7 → 1 → 5 → 4 → nullptr
✅ Final Output:
cpp
Copy
Edit
[2, 3, 6, 7, 1, 5, 4]
✅ সংক্ষিপ্ত রিভিউ:
Test Case Input	Output	Matches Expected?	✅
[1, 2, 3, 4, 5]	[1, 3, 5, 2, 4]	✅	✅
[2, 1, 3, 5, 6, 4, 7]	[2, 3, 6, 7, 1, 5, 4]	✅	✅

📌 শেষ কথা:
তোমার এই কোড test case অনুযায়ী ঠিকঠাক কাজ করছে।
যদিও এটি vector-based (O(n) space), তবুও structure ঠিক রাখার কারণে Accepted হয়।

Full Code:
------------

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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      //  vector<ListNode*>reserve;
       vector<ListNode*>v1;
        vector<ListNode*>v2;
        int index=1;
        while(head!=nullptr)
        {
          if(/*head->val*/index%2==0)
          {
           v1.push_back(head);
          }
            if(/*head->val*/index%2!=0)
          {
           v2.push_back(head);
          }
          head=head->next;
          index++;
        }
       
        vector<ListNode*>vf;
        for(int j=0;j<v2.size();j++)
        {
          vf.push_back(v2[j]);
        }
        for(int k=0;k<v1.size();k++)
        {
          vf.push_back(v1[k]);
        }
        if (vf.empty()) return nullptr; 
        ListNode* headd=(vf[0]);
        ListNode* curr=headd;
        for(int i=1;i<vf.size();i++)
        {
          curr->next=vf[i];
          curr=curr->next;
        }
        curr->next=nullptr;
  return headd;
    }
};

🔶 প্রশ্ন বিশ্লেষণ (Understanding the Problem)
তোমাকে একটি BST (Binary Search Tree) এর root দেওয়া আছে এবং একটি নতুন val দেওয়া আছে যেটা BST-তে ইনসার্ট করতে হবে। BST-র প্রপার্টি হচ্ছে:

বাম পাশে সব নোডের ভ্যালু ছোট হয়।

ডান পাশে সব নোডের ভ্যালু বড় হয়।

👉 আমাদের কাজ হলো সেই নতুন ভ্যালুটা এমনভাবে ইনসার্ট করা যাতে BST এর বৈশিষ্ট্য ঠিক থাকে।

🔷 সমাধান ভাবনা (Approach to Think the Solution)
প্রশ্নটা পড়েই তুমি ভাবতে পারো:

BST-তে নতুন মান ঢোকাতে গেলে কোথায় ঢুকবে সেটা নির্ধারণ করতে হয়।

যদি val < root->val হয়, তাহলে বাম দিকে যাবে।

যদি val > root->val হয়, তাহলে ডান দিকে যাবে।

যতক্ষণ না null পাবে, traversal করে যেতে হবে।

null পাওয়া মাত্র, সেখানেই নতুন TreeNode(val) ইনসার্ট করবে।

✅ Recursion দিয়ে খুব সহজে করা যায়, কারণ প্রতিটা সাবট্রিও তো নিজে একটা BST।

✅ কোড ব্যাখ্যা (Line-by-Line Explanation in Bangla)
cpp
Copy
Edit
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        // Step 1: যদি রুট ফাঁকা হয়, নতুন নোড বানিয়ে রিটার্ন করো
        if (!root) return new TreeNode(val);

        // Step 2: যদি ভ্যালু বড় হয় রুট থেকে, তাহলে ডানে যাবে
        if (root->val < val)
        {
            // রিকারসিভভাবে ডানে ইনসার্ট করো
            root->right = insertIntoBST(root->right, val);
        }

        // Step 3: যদি ভ্যালু ছোট হয় রুট থেকে, তাহলে বাঁয়ে যাবে
        else if (root->val > val)
        {
            // রিকারসিভভাবে বাঁয়ে ইনসার্ট করো
            root->left = insertIntoBST(root->left, val);
        }

        // Step 4: রুট রিটার্ন করো যাতে parent subtree ঠিক থাকে
        return root;
    }
};
🧪 টেস্ট কেস ধরে ব্যাখ্যা (Example Walkthrough)
➤ Example 1:
sql
Copy
Edit
Input: root = [4,2,7,1,3], val = 5
BST tree:
       4
      / \
     2   7
    / \
   1   3
Insert 5 → Goes to right of 4 → left of 7 → Insert at left of 7

Output: [4,2,7,1,3,5]
Traversal:

5 > 4 → go right (7)

5 < 7 → go left → left child is null → insert new node(5)

✅ কেন এই কোড Accepted হলো? (Why is it Accepted?)
BST insertion-এর রিকারসিভ রুল মেনে করা হয়েছে।

nullptr পেলে নতুন TreeNode(val) তৈরি করা হয়েছে।

Time Complexity: O(log n) (average BST height)

Space Complexity: O(h), h = height of tree (due to recursion stack)

📌 তোমার নিজের চিন্তা কিভাবে গঠন করবে? (How to Think This Yourself)
প্রশ্নে বলা হচ্ছে BST, তাই ইনঅর্ডার রুল মনে রাখো।

রিকারসিভ ভাবো – যে সাবট্রি ইনসার্ট করার পর আবার মূল ট্রি ঠিকমতো গড়বে।

Null পেলে নতুন নোড তৈরি করে ফিরে আসবে।

Insertion মানে একদম পাতা লেভেলে ঢুকানো, তাই recursion ভালোভাবে কাজ করবে।

🔁 আরো একটি উদাহরণ পরীক্ষা করে দেখি
➤ Example 2:
sql
Copy
Edit
Input: root = [40,20,60,10,30,50,70], val = 25
BST:

        40
       /  \
     20    60
    / \    / \
  10  30  50 70

Insert 25:
→ 25 < 40 → go left (20)
→ 25 > 20 → go right (30)
→ 25 < 30 → go left of 30 (null) → insert here

Final BST:
        40
       /  \
     20    60
    / \    / \
  10  30  50 70
      /
    25
🔚 শেষ কথা (Summary)
প্রশ্ন বুঝে নাও BST ইনসার্ট করতে হলে কী করতে হয়।

নতুন ভ্যালুটা কিসের থেকে ছোট বা বড় সেটা দেখে রিকারসিভ traversal করো।

null পেলে insert করে ফিরে আসো।

পুরো কোড রিকারসিভভাবে root ঠিক রেখে নতুন সাবট্রির pointer সেট করে দেয়।

Full Code:
-----------


 * Definition for a binary tree node.
 * struct TreeNode
  {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
      if(!root) return new TreeNode(val);
     
          if(root->val<val)
          {
           root->right= insertIntoBST(root->right,val);
          } 
          if(root->val>val)
          {
           root->left= insertIntoBST(root->left,val);
          }
          return root;
    }
};

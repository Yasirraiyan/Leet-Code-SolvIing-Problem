1️⃣ প্রশ্ন পড়ে কীভাবে চিন্তা করতে হবে

প্রশ্ন বলছে:

> "Given the root of a binary tree, return the preorder traversal of its nodes’ values."



মানে আমাদের Binary Tree-এর Preorder Traversal বের করতে হবে।

Preorder Traversal এর রুল:

1. Root node first (visit root)
2. Traverse left subtree
3. Traverse right subtree

(এটাকে আমরা “Root → Left → Right” বলে মনে রাখি)

📌 উদাহরণ:
ধরো এই ট্রি —

1
     \
      2
     /
    3

Preorder করলে হবে:

প্রথমে Root 1

তারপর Left নেই → Skip

তারপর Right → 2, তারপর 2-এর Left → 3
ফাইনাল আউটপুট: [1, 2, 3]



---

2️⃣ কৌশল (Approach)

প্রশ্নে যেহেতু ট্রি দেওয়া আছে এবং আমরা সব নোড একবার করে দেখতে চাই, DFS (Depth First Search) এবং Recursive Preorder Traversal ই সবচেয়ে সহজ পদ্ধতি।

আমাদের করতে হবে:

1. যদি root nullptr হয় → কিছুই রিটার্ন করব না (base case)


2. root-এর value রেকর্ড করব (visit)


3. বাম দিকে recursive call করব


4. ডান দিকে recursive call করব




---

3️⃣ কেন ভেক্টর v ক্লাসের বাইরে (গ্লোবাল মেম্বার)

যেহেতু recursive function Preorder এর মধ্যে vector ফেরত দেওয়ার দরকার নেই, আমরা ক্লাসের ভেতরে একবার vector ডিফাইন করে সেটাতে সব value push করব।

preorderTraversal() ফাংশনে v.clear() করা হয় যাতে আগের টেস্ট কেসের ডেটা মুছে যায়।



---

4️⃣ কোড ব্যাখ্যা (Line by Line)

class Solution
{
public:
    vector<int> v; // Output রাখার জন্য গ্লোবাল মেম্বার ভেক্টর

    void Preorder(TreeNode* root)
    {
        if(root == nullptr) return; // Base case: নোড নেই

        v.push_back(root->val); // ধাপ 1: root visit করলাম

        if(root->left != nullptr) Preorder(root->left); // ধাপ 2: বাম দিকে গেলাম
        if(root->right != nullptr) Preorder(root->right); // ধাপ 3: ডান দিকে গেলাম
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        v.clear(); // আগের কেসের ডেটা মুছে ফেলি
        Preorder(root); // রিকারশন চালু
        return v; // রেজাল্ট ফেরত
    }
};


---

5️⃣ টেস্ট কেস অনুযায়ী ব্যাখ্যা

Example 1:

root = [1,null,2,3]
Tree:
    1
     \
      2
     /
    3

ধাপে ধাপে:

Visit 1 → v = [1]

Left নেই

Right → 2 → v = [1, 2]

2 এর Left → 3 → v = [1, 2, 3]
✅ Output: [1, 2, 3]



---

Example 2:

root = [1,2,3,4,5,null,8,null,null,6,7,9]

        1
      /   \
     2     3
    / \     \
   4   5     8
      / \     \
     6   7     9

ধাপে ধাপে:

Visit 1 → [1]

Go Left → Visit 2 → [1, 2]

Left → Visit 4 → [1, 2, 4]

Back, Right → Visit 5 → [1, 2, 4, 5]

Left → Visit 6 → [1, 2, 4, 5, 6]

Right → Visit 7 → [1, 2, 4, 5, 6, 7]

Back to root, Right → Visit 3 → [1, 2, 4, 5, 6, 7, 3]

Right → Visit 8 → [1, 2, 4, 5, 6, 7, 3, 8]

Right → Visit 9 → [1, 2, 4, 5, 6, 7, 3, 8, 9]
✅ Output: [1, 2, 4, 5, 6, 7, 3, 8, 9]



---

Example 3:

root = [] → কিছু নেই → Output: []

Example 4:

root = [1] → শুধু root → Output: [1]


---

6️⃣ গাণিতিকভাবে (Complexity Analysis)

প্রতিটি নোড একবারই ভিজিট হচ্ছে → Time Complexity = O(n)

রিকারশন স্ট্যাক সর্বোচ্চ O(h) (h = height of tree) → Space Complexity = O(h)



---

7️⃣ কেন Accepted

সব Edge case handle হয়েছে (nullptr, এক নোড, skewed tree, পূর্ণ binary tree)

সঠিক Preorder রুল (Root → Left → Right) অনুসরণ করা হয়েছে

প্রতিটি নোড একবার ভিজিট করা হয়েছে → Efficient (O(n))

প্রতিটি টেস্ট কেসে ঠিক আউটপুট এসেছে


Full Code:
------------

class Solution
{
public:
    vector<int>v;
    void Preorder(TreeNode* root)
    {
        if(root==nullptr) return;
        v.push_back(root->val);
        if(root->left!=nullptr) Preorder(root->left);
        if(root->right!=nullptr) Preorder(root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        v.clear();
        Preorder(root);
        return v;
    }
};

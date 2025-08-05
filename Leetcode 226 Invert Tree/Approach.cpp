১. প্রশ্ন পড়ে সমাধানের আইডিয়া (Approach Thinking Process)

প্রশ্ন:
তোমাকে একটা binary tree দেওয়া আছে, তোমাকে এই ট্রিটা invert করতে হবে — মানে প্রতিটা নোডের left ও right child অদল-বদল করে দিতে হবে।

📌 উদাহরণ 1:

4               4
  / \             / \
 2   7   --->    7   2
/ \ / \         / \ / \
1 3 6 9         9 6 3 1

প্রশ্ন দেখে প্রথমেই বোঝা যায় —
প্রতিটি node-এর জন্য কাজ একই রকম:

1. তার left এবং right child অদল-বদল করো


2. তারপর একই কাজ left subtree এবং right subtree তে করো



এটা ঠিক recursive definition এর মতো:

> InvertTree(root) = Swap(root->left, root->right)
তারপর InvertTree(root->left) এবং InvertTree(root->right)



এখানে recursion use করলে খুব clean হবে।


---

২. কোড লেখার চিন্তা

যদি root == nullptr হয় → কিছু করার দরকার নেই

না হলে:

root->left এবং root->right swap করো

recursive call দাও root->left ও root->right এ


শেষে পুরো ট্রির root return করো



---

৩. তোমার কোড লাইন-বাই-লাইন ব্যাখ্যা

class Solution 
{
public:
    void invert(TreeNode* root)
    {
        if(root==nullptr) return;

🔹 কাজ:
যদি নোড খালি (null) হয় → আর কিছু করার দরকার নেই, return করো।
📌 Base case for recursion.


---

TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

🔹 কাজ:
এখানে swap করা হচ্ছে।
ধরা যাক:

root->left = L
 root->right = R

Swap করলে:

root->left = R
 root->right = L

এটা প্রতিটি নোডে হবে।


---

invert(root->left);
        invert(root->right);

🔹 কাজ:
এখন left subtree ও right subtree তে একই প্রক্রিয়া apply করা হচ্ছে।
Recursion এর মাধ্যমে নিচের সব নোডেও swap হবে।


---

}
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
};

🔹 কাজ:
invertTree শুধু helper function invert() কে কল করে এবং পুরো ট্রি ইনভার্ট হয়ে গেলে root return করে।
এটাই final answer হবে।


---

৪. গাণিতিকভাবে ব্যাখ্যা (Recursion Tree Example)

ধরা যাক input:

root = [2,1,3]

Step-by-step:

1. Call invert(2) → swap(1, 3) → এখন root=2, left=3, right=1


2. Call invert(3) → left=null, right=null → return


3. Call invert(1) → left=null, right=null → return



Final:

2
  / \
 3   1


---

⏳ Time Complexity:

প্রতিটি নোড একবার করে ভিজিট → O(N)
📦 Space Complexity:

Recursion depth = height of tree → Worst case O(N) (skewed tree), Best case O(log N) (balanced tree)



---

৫. কেন কোড টেস্টকেস পাস করল

কারণ প্রতিটি নোডের left-right অদল-বদল হচ্ছে

Recursion এর কারণে পুরো ট্রি traverse হচ্ছে

Base case (root == nullptr) থাকার কারণে null এ থেমে যাচ্ছে

Root return করার ফলে modified ট্রি output হচ্ছে


Full Code:
-----------

class Solution 
{
public:
    void invert(TreeNode* root)
    {
        if(root==nullptr) return;
           TreeNode* temp=root->left;
                    root->left=root->right;
                    root->right=temp;
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
};

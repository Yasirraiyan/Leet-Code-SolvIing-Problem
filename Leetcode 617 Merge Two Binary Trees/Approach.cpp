প্রথমে প্রশ্নটা বোঝা

প্রশ্ন বলছে:

আমাদের কাছে দুটি binary tree আছে — root1 আর root2।

এই দুটো গাছকে মার্জ (merge) করতে হবে নতুন একটা গাছ বানিয়ে।

Merge Rule:

1. যদি দুইটা নোড একই পজিশনে থাকে (overlap হয়), তাহলে value যোগ করতে হবে।


2. যদি কোনো পজিশনে একটিই নোড থাকে, তাহলে সেই নোডটাই রেখে দিতে হবে।



শুরু হবে দুই রুট (root) নোড থেকে।



---

ভাবনার ধাপ (Approach Thinking)

1. রিকার্সিভ চিন্তা (Recursive Thinking)
দুইটা গাছ মার্জ করতে গেলে প্রথমেই রুট নোড থেকে শুরু করতে হবে।
প্রতিটা নোডের ক্ষেত্রে তিনটা অবস্থা হতে পারে:

Case 1: দুই নোড-ই আছে → তাদের মান যোগ করে নতুন নোড বানাও।

Case 2: একটা নোড নেই → অন্য নোডটাই রিটার্ন করো।

Case 3: দুই নোডই নেই → nullptr রিটার্ন করো (base case)।



2. Divide and Conquer
রুট মার্জ করার পরে, left subtree মার্জ করব রুটের বাম সন্তান দিয়ে
আর right subtree মার্জ করব রুটের ডান সন্তান দিয়ে।


3. রিকার্সন কলিং
এইভাবে বারবার কল হলে, সব নোড প্রক্রিয়া হয়ে যাবে।




---

কোডের লাইন বাই লাইন ব্যাখ্যা

class Solution 
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {

🔹 আমরা mergeTrees ফাংশন লিখছি যেটা দুইটা TreeNode* ইনপুট নিয়ে মার্জড ট্রি রিটার্ন করবে।


---

if(root1==nullptr) return root2;

🔹 Base Case 1:
যদি root1 না থাকে (nullptr), তাহলে root2-এর নোডটাই রিটার্ন করে দাও।
মানে ওই জায়গায় শুধু root2 আছে, মার্জ করার কিছু নেই।


---

if(root2==nullptr) return root1;

🔹 Base Case 2:
যদি root2 না থাকে, তাহলে root1 ফেরত দাও।


---

TreeNode* root3 ;

🔹 মার্জড নোডের জন্য নতুন একটা পয়েন্টার root3 বানালাম।


---

if(root1->val!=root2->val)
        {
            int s=root1->val+root2->val;
            root3=new TreeNode(s);
        }
        if(root1->val==root2->val)
        {
            int s=root1->val+root2->val;
            root3=new TreeNode(s);
        }

🔹 এখানে আসলে দুইটা if আলাদা রাখার দরকার নেই, কারণ দুই ভ্যালু সমান হোক বা না হোক, যোগফলই লাগবে।
তুমি দুটো আলাদা করেছ, কিন্তু কাজ ঠিকই হচ্ছে কারণ দুই কেসেই sum করে নতুন নোড বানানো হচ্ছে।

📌 গণিত উদাহরণ:
যদি root1->val = 3 আর root2->val = 5 হয়,
তাহলে s = 3 + 5 = 8 হবে, এবং নতুন root3-এর মান হবে 8।


---

root3->left= mergeTrees(root1->left,root2->left);

🔹 Left subtree মার্জ করার জন্য রিকার্সিভ কল দিলাম।
এই কলের ভেতর আবার একই লজিক চালু হবে।


---

root3->right= mergeTrees(root1->right,root2->right);

🔹 Right subtree মার্জ করলাম রিকার্সন দিয়ে।


---

return root3;
    }
};

🔹 নতুন মার্জড নোড (root3) ফেরত দিলাম।
এইভাবে রিকার্সন সব subtree মার্জ করে ফাইনাল ট্রি বানাবে।


---

টেস্ট কেস দিয়ে বোঝা

Example 1

root1 = [1,3,2,5]
root2 = [2,1,3,null,4,null,7]

ধাপে ধাপে মার্জ:

1. রুট: 1 + 2 = 3


2. Left child: 3 + 1 = 4


3. Left-left child: 5 + null = 5


4. Left-right child: null + 4 = 4


5. Right child: 2 + 3 = 5


6. Right-right child: null + 7 = 7



ফাইনাল ট্রি:

3
     / \
    4   5
   / \    \
  5   4    7

আউটপুট: [3,4,5,5,4,null,7]


---

সংক্ষেপে চিন্তার ফ্লো

1. Base Case → null চেক করো।


2. Sum Node Values → দুই নোড থাকলে যোগ করো।


3. Recursive Merge → left ও right subtree মার্জ করো।


4. Return → নতুন মার্জড নোড রিটার্ন করো।


Full Code:
-----------

  class Solution 
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        TreeNode* root3 ;
                if(root1->val!=root2->val)
                {
                    int s=root1->val+root2->val;
                    root3=new TreeNode(s);
                }
                if(root1->val==root2->val)
                {
                    int s=root1->val+root2->val;
                    root3=new TreeNode(s);
                }
               root3->left= mergeTrees(root1->left,root2->left);
               root3->right= mergeTrees(root1->right,root2->right);
        return root3;
    }
};

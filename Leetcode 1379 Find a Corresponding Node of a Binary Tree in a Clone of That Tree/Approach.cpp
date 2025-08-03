✅ প্রশ্ন বিশ্লেষণ (Problem Understanding)

প্রশ্নটা বলছে:

তোমার কাছে দুইটা বাইনারি ট্রি আছে:

original (মূল গাছ)

cloned (একই original গাছের কপি, মানে একদম একই structure, মান same, কিন্তু reference আলাদা)


আর একটা নোড target দেওয়া আছে যেটা original গাছের ভিতরের একটি নোডের রেফারেন্স।


🔍 তোমার কাজ: cloned গাছের সেই নোডটা রিটার্ন করা যেটা target নোডের অবস্থান অনুযায়ী ক্লোন।

> মানে target গাছের যেই পজিশনে আছে, cloned গাছেও ঠিক সেই পজিশনের নোড return করতে হবে।




---

✅ কি কি constraint বা নিয়ম দেওয়া আছে?

দুইটা ট্রি structure একদম একই (value ও একই), কিন্তু reference আলাদা।

কোনো গাছ বা নোড modify করা যাবে না।

প্রতি গাছে node সংখ্যা [1, 10⁴] পর্যন্ত হতে পারে (মানে O(n) চলবে)।

Target কখনো null না।



---

✅ সমাধান ভাবার পদ্ধতি (Approach Thinking):

1. target node এর value তোমার কাছে আছে, কিন্তু তুমি original এর রেফারেন্স পাবে না, তাই value match দিয়ে কাজ করতে পারো।


2. যেহেতু original আর cloned structurally same, তাই যদি তুমি original ট্রিতে BFS করো, সেই সাথে cloned ট্রিতেও একসাথে BFS করো, তাহলে target নোড যেখান থেকে পাবে original এ, ওই অবস্থানে cloned এর নোড-টা হবে তোমার উত্তর।




---

✅ কোড ব্যাখ্যা (Code Explanation Line by Line)

class Solution 
{
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {

➤ একটা ফাংশন, যেটা original, cloned, এবং target নোড নেয়। আমাদের কাজ cloned গাছ থেকে সেই নোড খুঁজে বের করা যেটা target এর ক্লোন।

queue<TreeNode*> q1;
        queue<TreeNode*> q2;

➤ দুইটা Queue নিচ্ছি BFS করার জন্য – একটাতে original গাছ BFS করবো আরেকটাতে cloned গাছ।

q1.push(original);
        q2.push(cloned);

➤ দুটো গাছেই root থেকে BFS শুরু করছি।

TreeNode* ans;

➤ উত্তর রাখার জন্য একটা পয়েন্টার নিচ্ছি।

while(!q1.empty() && !q2.empty())
        {

➤ যতক্ষণ না পর্যন্ত দুইটা queue ফাঁকা হচ্ছে, আমরা level by level BFS চালিয়ে যাবো।

TreeNode* front1 = q1.front();
            TreeNode* front2 = q2.front();

➤ original গাছ থেকে একটি নোড, এবং তার একই পজিশনের cloned গাছ থেকে একটি নোড নিচ্ছি।

if(front1->val == target->val)
            {
                ans = front2;
                break;
            }

➤ যদি original গাছের নোডটা target এর সমান হয় (মানে value-wise match হয়), তাহলে ওই পজিশনের cloned গাছের নোড-টাই আমাদের উত্তর।

📌 Note: আমরা value দিয়ে চেক করছি কারণ target node এর reference অন্য, তবে যেহেতু values unique, তাই value দিয়েই identify করা নিরাপদ।

q1.pop();
            q2.pop();

➤ যেহেতু আমরা নোডগুলো চেক করেছি, তাই এখন queue থেকে বের করে দিচ্ছি।

if (front1->left && front2->left) 
            {
                q1.push(front1->left);
                q2.push(front2->left);
            }

➤ যদি বাম সন্তান থাকে, তাহলে তাকে queue-তে যোগ করবো।

if (front1->right && front2->right) 
            {
                q1.push(front1->right);
                q2.push(front2->right);
            }

➤ ডান সন্তান থাকলে সেটাকেও queue তে পুশ করবো।

}
        return ans;
    }
};


---

✅ গাণিতিক বিশ্লেষণ (Mathematical Analysis)

Time Complexity: O(n) — সব নোড traverse করতে হতে পারে, কারণ worst case এ target শেষ leaf এ থাকতে পারে।

Space Complexity: O(n) — Queue তে একসাথে level এর সব নোড থাকতে পারে।



---

✅ Test Case উদাহরণ দিয়ে ব্যাখ্যা

Input:

original = [7,4,3,null,null,6,19]
cloned   = [7,4,3,null,null,6,19]
target = node with value 3

Visualization:

Original:
      7
     / \
    4   3
       / \
      6   19

Target = node 3

Cloned Tree is exactly same, only pointer is different.

Step-by-step BFS:

1. Queue1 = [7], Queue2 = [7] → not match


2. Queue1 = [4,3], Queue2 = [4,3] → 3 matches


3. Return corresponding cloned 3 node ✅




---

✅ Follow-up: যদি Tree-তে repeated values থাকে?

তাহলে value দিয়ে চেনা যাবে না, কারণ একাধিক নোডে same value থাকতে পারে।

➡️ তখন value দিয়ে না চেক করে pointer comparison করতে হবে:

if (front1 == target)
{
    return front2;
}


---

🔚 সংক্ষেপে (Summary):

প্রশ্ন বোঝা: Cloned গাছ থেকে target এর সমান reference খুঁজে বের করা।

সমাধান ভাবা: BFS করে দুটো গাছ একসাথে traverse করে value match পেলে সেই পজিশনের cloned node return করা।

Time: O(n), Space: O(n)

যদি repeated value থাকে: pointer দিয়ে compare করতে হবে।


Full Code:
-------------

  class Solution
{
public:

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)   
{  
    queue<TreeNode*>q1;  
    queue<TreeNode*>q2;  
    q1.push(original);  
    q2.push(cloned);  
    TreeNode* ans;  
    while(!q1.empty()&&!q2.empty())  
    {  
      TreeNode* front1=q1.front();  
      TreeNode* front2=q2.front();  
      if(front1->val==target->val)//&&front2->val==target->val)  
      {  
          ans=front2;  
          break;  
      }  
      q1.pop();  
      q2.pop();  
      if (front1->left && front2->left)   
      {  
            q1.push(front1->left);  
            q2.push(front2->left);  
        }  

        if (front1->right && front2->right)   
        {  
            q1.push(front1->right);  
            q2.push(front2->right);  
        }  
    }  
    return ans;  
}

};

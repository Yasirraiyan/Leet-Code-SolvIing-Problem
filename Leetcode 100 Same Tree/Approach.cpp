🔍 প্রশ্ন বিশ্লেষণ (Understanding the Problem):

তোমাকে দুটি বাইনারি ট্রি দেওয়া হয়েছে — p এবং q।
তুমি চেক করবে:

1. ট্রি দুটির গঠন (structure) একই কি না।


2. প্রতিটি নোডের মান (value) একই কি না।




---

✅ টেস্টকেসগুলো বিশ্লেষণ করি:

🔹 Example 1:

p = [1,2,3], q = [1,2,3]
       1              1
      / \            / \
     2   3          2   3

👉 গঠন এবং মান — উভয়ই এক → Output: true

🔹 Example 2:

p = [1,2], q = [1,null,2]
       1           1
      /             \
     2               2

👉 গঠন আলাদা (একটার left আছে, আরেকটার right) → Output: false

🔹 Example 3:

p = [1,2,1], q = [1,1,2]
       1           1
      / \         / \
     2   1       1   2

👉 গঠন ঠিক আছে কিন্তু মান ভিন্ন → Output: false


---

💡 সমাধানের আইডিয়া (Thinking Approach):

তুমি দুইটা ট্রিকে level-order traversal (BFS) করে প্রতিটি node এর pointer বা nullptr সহ একটা vector এ এনেছো।

তারপর সেই দুটি vector তুলনা করেছো:

যদি size আলাদা হয় → false

যদি একই index-এ একজন null আরেকজন non-null হয় → false

যদি দুইটা node আছে কিন্তু তাদের value ভিন্ন হয় → false

সব match হলে → true



---

📘 Step-by-step ব্যাখ্যা (Line-by-line Explanation in Bangla)

vector<TreeNode*> BFS(TreeNode* p)

🔹 BFS() function পুরো tree কে BFS করে সব নোড vector এ রাখে, এমনকি nullptr ও।

if(p==nullptr) return v;

🔹 যদি root ই null হয়, তাহলে খালি vector ফেরত।

queue<TreeNode*>q1;
q1.push(p);

🔹 BFS শুরু হচ্ছে queue দিয়ে — root push করো।

while(!q1.empty())

🔹 যতক্ষণ queue খালি না, loop চলবে।

TreeNode* curr=q1.front();
v.push_back(curr);
q1.pop();

🔹 queue থেকে node বের করে vector এ রাখো।

if(curr!=nullptr)
{
    q1.push(curr->left);
    q1.push(curr->right);
}

🔹 যদি curr null না হয়, তাহলে তার left ও right push করো — তা না হলে nullptr পুশ হবে না।

🔹 একারণে তুমি nullptr ও সংরক্ষণ করছো vector-এ → যাতে গঠন মেলানো যায়।


---

bool isSameTree(TreeNode* p, TreeNode* q)

🔹 Main function — দুই tree থেকে vector বের করো BFS দিয়ে।

if(v1.size()!=v2.size()) return false;

🔹 যদি BFS এর result size আলাদা → গঠন আলাদা → false

for(int i=0;i<v1.size();i++)
{
    if(v1[i]==nullptr&&v2[i]==nullptr) continue;
    if(v1[i]==nullptr||v2[i]==nullptr) return false;

🔹 যদি দুজনেই null → ঠিক আছে
🔹 যদি একজন null আরেকজন না হয় → গঠন আলাদা → false

if(v1[i]->val!=v2[i]->val)
{
    issame=false;
    break;
}

🔹 যদি value mismatch হয় → false


---

📐 ম্যাথেমেটিক্যাল ভাবনা:

একটা Binary Tree হল Directed Graph (DAG)-এর special case, যেখানে:

Root থেকে ডান ও বাম দিকে দুটি branch

Height বা level অনুসারে আমরা প্রতি level-এর node তুলনা করি।


BFS ব্যবহার করে level-order traversal করলে:

প্রতিটি level-এর সব node দেখতে পারি

আমরা null pointers ও ট্র্যাক করতে পারি, তাই structure match ও করা যায়।



---

✅ Accepted কেন হয়?

1. সব নোড ঠিকভাবে সংরক্ষণ করছো (even nullptr)


2. গঠন + মান দুইটাই চেক করছো


3. Edge cases (e.g., both null, one null, size mismatch) কভার করছো




---

🔁 Test by Test Case:

Case 1:

p = [1,2,3], q = [1,2,3]
BFS(p) = [1,2,3,null,null,null,null]
BFS(q) = [1,2,3,null,null,null,null]
→ Same → true

Case 2:

p = [1,2], q = [1,null,2]
BFS(p) = [1,2,null,null]
BFS(q) = [1,null,2,null]
→ Mismatch at index 1 → false

Case 3:

p = [1,2,1], q = [1,1,2]
BFS(p) = [1,2,1,null,null,null,null]
BFS(q) = [1,1,2,null,null,null,null]
→ Mismatch at index 1 or 2 → false

Full Code:
------------

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode*> BFS(TreeNode* p)
    {
        vector<TreeNode*>v;
        if(p==nullptr) return v;
        queue<TreeNode*>q1;
        q1.push(p);
        while(!q1.empty())
            {
                TreeNode* curr=q1.front();
                
                v.push_back(curr);
                q1.pop();
                
                if(curr!=nullptr)
                {
                    q1.push(curr->left);
                    
                    q1.push(curr->right);
                }
                
                
                
            }
        return v;
    }
                
                
        
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        vector<TreeNode*>v1=BFS(p);
        vector<TreeNode*>v2=BFS(q);
        if(v1.size()!=v2.size()) return false;
        bool issame=true;
        for(int i=0;i<v1.size();i++)
            {
                if(v1[i]==nullptr&&v2[i]==nullptr) continue;
                if(v1[i]==nullptr||v2[i]==nullptr) return false;
                
                        if(v1[i]->val!=v2[i]->val)
                        {
                            issame=false;
                            break;
                        }
                    }
                        
                        
            
        return issame;
        
    }
}; 

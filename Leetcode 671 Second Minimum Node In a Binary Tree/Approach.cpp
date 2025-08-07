🔍 Step-by-Step বুঝে নাও প্রশ্নটা:
Objective:
পুরো tree traversal করে সব node-এর value নিয়ে সেটির মধ্যে second smallest মান বের করতে হবে। যদি না থাকে (মানে সব value একই), তাহলে -1 return করতে হবে।

✅ Input Example 1:
yaml
Copy
Edit
Input: [2,2,5,null,null,5,7]
       2
      / \
     2   5
        / \
       5   7
সব values: [2,2,5,5,7]

Unique values: [2,5,7]

Second smallest = 5 ✅

✅ Input Example 2:
css
Copy
Edit
Input: [2,2,2]
       2
      / \
     2   2
সব values: [2,2,2]

Unique values: [2]

Second smallest নেই, তাই output: -1

🧠 কিভাবে approach ভাববো?
Tree-এর সব nodes-এর value বের করবো → BFS traversal দিয়ে।

সব value থেকে unique values বের করবো → unordered_map বা set ব্যবহার করে।

তারপর unique values গুলো sort করে দ্বিতীয়টা নেব।

যদি second min না থাকে (মানে unique value মাত্র একটা), তাহলে -1 return করবো।

🔎 কোড বিশ্লেষণ (Line-by-line) — বাংলায় ব্যাখ্যা সহ:
cpp
Copy
Edit
class Solution 
{
public:
 // Step 1: Tree traversal using BFS (Level Order Traversal)
 vector<int>BFS(TreeNode* root)
 {
  queue<TreeNode*>q;
  q.push(root); // প্রথমে root কে queue তে ঢুকালাম
  vector<int>v;
  
  while(!q.empty())
  {
    TreeNode* front=q.front(); // queue থেকে সামনের node নিয়ে এলাম
    q.pop();
    
    if(front!=nullptr)
    {
      v.push_back(front->val); // node এর value vector এ যোগ করলাম
    }

    // যদি child থাকে, তাদের queue তে ঢুকিয়ে দিলাম
    if(front->left!=nullptr) q.push(front->left);
    if(front->right!=nullptr) q.push(front->right);
  }
  return v; // সব node এর value return করলাম
 }
cpp
Copy
Edit
    int findSecondMinimumValue(TreeNode* root) 
    {
      vector<int>vv = BFS(root); // BFS চালিয়ে সব value নিয়ে এলাম

      unordered_map<int,int>freq;
      for(int i=0;i<vv.size();i++)
      {
        freq[vv[i]]++; // frequency হিসাব রাখলাম
      }
উদ্দেশ্য: unique values বের করা

cpp
Copy
Edit
      vector<int>v;
      for(auto it:freq)
      {
        v.push_back(it.first); // map থেকে unique value গুলো vector এ রাখলাম
      }

      sort(v.begin(),v.end()); // sort করলে second smallest পাওয়া যাবে
cpp
Copy
Edit
      int secondmin;
      if(v.size()>=2) // যদি কমপক্ষে ২টি unique মান থাকে
      {
        secondmin = v[1]; // দ্বিতীয় ছোটটা হল second minimum
      }
      else
      {
        return -1; // না থাকলে -1 return করবো
      }

      return secondmin; // উত্তর return করলাম
    }
};
✅ কেন এই কোড Accepted হয়?
✅ Tree traversal করা হয় BFS দিয়ে → সব value একবারে পাওয়া যায়।

✅ unordered_map দিয়ে duplicate ছাড়াই unique values রাখা হয়।

✅ Unique value sort করে আমরা second minimum নির্ভুলভাবে বের করতে পারি।

✅ Time Complexity: O(n + k log k) যেখানে n = nodes, k = unique values → efficient।

🧪 Test Case দিয়ে বোঝা:
Test Case 1:
cpp
Copy
Edit
Input: [2,2,5,null,null,5,7]

Tree:
       2
      / \
     2   5
        / \
       5   7

Traversal: BFS → [2,2,5,5,7]
Unique Values: {2, 5, 7}
Sorted: [2, 5, 7]
Second minimum: 5 ✅
Test Case 2:
cpp
Copy
Edit
Input: [2,2,2]

Tree:
      2
     / \
    2   2

Traversal: BFS → [2,2,2]
Unique Values: {2}
Sorted: [2]
Second min নেই → return -1 ✅
✍️ Summary of Thought Process (Bangla):
প্রশ্নে বলা ছিল tree-এর সব value থেকে second smallest বের করতে।

যেহেতু tree-এর গঠন special ছিল (root.val = min(left.val, right.val)), তাই জানি smallest value হবে root.val

BFS দিয়ে traversal করলাম।

map দিয়ে unique values রাখলাম।

sort করে second minimum বের করলাম।

Full Code:
-----------

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
 vector<int>BFS(TreeNode* root)
 {
  queue<TreeNode*>q;
  q.push(root);
  vector<int>v;
  while(!q.empty())
  {
    TreeNode* front=q.front();
    q.pop();
    if(front!=nullptr)
    {
    v.push_back(front->val);
  }
  if(front->left!=nullptr) q.push(front->left);
  if(front->right!=nullptr) q.push(front->right);
  
  }
  return v;
 }
    int findSecondMinimumValue(TreeNode* root) 
    {
      vector<int>vv=BFS(root);
        unordered_map<int,int>freq;
        for(int i=0;i<vv.size();i++)
        {
          freq[vv[i]]++;
        }
        vector<int>v;
        for(auto it:freq)
        {
          v.push_back(it.first);
        }
        sort(v.begin(),v.end());
        int ans;
        int secondmin;
        if(v.size()>=2)
        {
        secondmin=v[1];
        }
        else
        {
          return -1;
        }
        ans=secondmin;
        return ans;

    }
};

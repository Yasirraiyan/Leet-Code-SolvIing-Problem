✅ প্রশ্নটা কী বলছে?
প্রশ্নটা বলছে:
একটা বাইনারি ট্রি দেওয়া আছে, তোমাকে সেই ট্রির নোডগুলো level order traversal করতে হবে।

Level Order Traversal মানে কী?

👉 Level by level, অর্থাৎ:

প্রথমে root (level 0),

তারপর তার left এবং right child (level 1),

তারপর তাদের child গুলো (level 2),

এভাবে যতদূর যায়।

⏳ এই traversal-টা BFS (Breadth-First Search) দিয়ে হয় — Queue ব্যবহার করে।

📥 উদাহরণ ১:
Input: root = [3,9,20,null,null,15,7]

এই ট্রি এমন:

markdown
Copy
Edit
        3
       / \
      9  20
         / \
        15  7
Level-wise দেখলে:

Level 0: [3]

Level 1: [9, 20]

Level 2: [15, 7]

✅ Output হবে: [[3],[9,20],[15,7]]

🧠 এখন চিন্তা করো কীভাবে সমাধান করব?
Approach (ধাপে ধাপে ভাবনা):

যদি root না থাকে, তাহলে সরাসরি [] রিটার্ন করবো।

আমরা queue ব্যবহার করবো যেন প্রথমে root থেকে child গুলো পাই।

প্রত্যেক level-এ কতগুলো node আছে, সেটা queue.size() দিয়ে বের করবো।

সেই লেভেলের সব node প্রসেস করব (pop করব, এবং তাদের value একটি vector<int> তে রাখব)।

প্রতিটি node-এর left এবং right child থাকলে queue তে push করব।

প্রতিটি level শেষে সেই level-এর vector টা main result vector এ রাখব।

✅ Code: Line by Line Bangla ব্যাখ্যা সহ
cpp
Copy
Edit
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>v;   // সব লেভেলের জন্য ফাইনাল রেজাল্ট

        if (root == nullptr) return v;  // যদি root না থাকে, খালি রিটার্ন করো

        queue<TreeNode*>q;  // লেভেল অর্ডার করার জন্য queue
        q.push(root);       // root কে queue তে ঢুকালাম

        while(!q.empty())   // যতক্ষণ queue খালি না হয়
        {
            int size = q.size();   // এই লেভেল-এ কতগুলো নোড আছে
            vector<int>vv;         // এই লেভেলের নোডগুলোর মান রাখবে

            for (int i = 0; i < size; ++i)
            {
                TreeNode* front=q.front();  // queue থেকে সামনের নোড নিলাম
                q.pop();                    // pop করলাম

                vv.push_back(front->val);   // এই নোডের মান result-এ রাখলাম

                if(front->left!=nullptr)    // যদি বাম সন্তান থাকে
                {
                    q.push(front->left);   // queue তে ঢুকালাম
                }

                if(front->right!=nullptr)   // যদি ডান সন্তান থাকে
                {
                    q.push(front->right);  // queue তে ঢুকালাম
                }
            }

            v.push_back(vv);  // এই লেভেলের রেজাল্ট main vector এ রাখলাম
        }

        return v;   // সব লেভেল শেষ, রেজাল্ট রিটার্ন
    }
};
🔍 Test Case ব্যাখ্যা:
Test 1:
cpp
Copy
Edit
Input: [3,9,20,null,null,15,7]
Level-wise traversal:

লেভেল	queue এর অবস্থা (step by step)
0	[3] → output: [3]
1	[9, 20] → output: [9, 20]
2	[15, 7] → output: [15, 7]

⏹ Final: [[3], [9, 20], [15, 7]]

Test 2:
cpp
Copy
Edit
Input: [1]
একমাত্র root node 1 → level 0 → output: [[1]]

Test 3:
cpp
Copy
Edit
Input: []
Tree নাই → output: []

✅ Time and Space Complexity:
Time Complexity: O(n) — প্রতিটি node একবার করে ভিজিট করছো

Space Complexity:

Worst case: O(n) — queue-তে এক লেভেলের সব node থাকতে পারে (যদি ট্রি খুব wide হয়)

🔚 সংক্ষেপে মনে রাখো:
এই সমস্যার জন্য BFS ব্যবহার করো

প্রতিটি level আলাদা vector-এ রাখো

queue দিয়ে এক এক করে level প্রসেস করো

Full Code:
----------

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
 
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      vector<vector<int>>v;
      if (root == nullptr) return v;
     
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty())
      {
         int size = q.size();   
          vector<int>vv;
         for (int i = 0; i < size; ++i)
            {     
        TreeNode* front=q.front();
        q.pop();
        vv.push_back(front->val);
        if(front->left!=nullptr)
        {
          q.push(front->left);
        }
        if(front->right!=nullptr)
        {
          q.push(front->right);
        }
      }
      v.push_back(vv);
      }
//for(int i=0;i<vv.size();i++)
//{
  
//}
return v;
    }
};

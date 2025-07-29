🔶 সমস্যার ব্যাখ্যা (Problem Explanation)

তোমাকে একটি Binary Tree দেওয়া হয়েছে। সমস্যা বলছে:

> যদি গাছের প্রতিটি node এর মান (value) একই হয়, তাহলে return true, না হলে false।



এক কথায়, এই গাছটি uni-valued কিনা সেটা নির্ণয় করতে হবে।


---

🔶 কীভাবে চিন্তা শুরু করবো? (How to Think)

প্রথমেই লক্ষ্য করি, আমরা একটি binary tree পেয়েছি এবং আমাদের প্রতিটি node ঘুরে দেখতে হবে যে সবার value একই কিনা।

চিন্তার ধাপ:

1. যেকোনো traversal (DFS বা BFS) করে tree এর প্রতিটি node-এর value collect করো।


2. এই value গুলোর মধ্যে যদি একের বেশি ভিন্ন value থাকে, তাহলে tree uni-valued না।


3. সব value যদি একই হয়, তাহলে uni-valued।



আমরা এখানে BFS traversal ব্যবহার করেছি।


---

🔶 কোড ব্যাখ্যা ধাপে ধাপে (Line-by-Line Code Explanation in Bangla)

class Solution
{
public:

➤ Solution ক্লাস শুরু। এতে bfs() এবং isUnivalTree() ফাংশন আছে।


---

🔹 BFS Function

vector<int>bfs(TreeNode* root)
{
    vector<int>v;
    if(!root) return v;

➤ bfs() ফাংশন একটি level-order traversal করে সব node এর value v তে জমা রাখে। যদি root না থাকে তাহলে খালি ভেক্টর ফেরত দেয়।

queue<TreeNode*>q;
    q.push(root);

➤ BFS করার জন্য একটি queue নেয়া হলো এবং root node queue-তে ঢুকানো হলো।

while(!q.empty())
    {
        TreeNode* curr=q.front();
        q.pop();
        v.push_back(curr->val);

➤ queue যতক্ষণ খালি না হয়, ততক্ষণ চলবে। সামনে থেকে একটি node নিয়ে তার value v তে রাখা হলো।


---

🔹 Children check:

if(curr->left!=nullptr)
        {
            q.push(curr->left);
            v.push_back(curr->left->val);
        }
        if(curr->right!=nullptr)
        {
            q.push(curr->right);
            v.push_back(curr->right->val);
        }
    }

➤ যদি current node-এর left বা right child থাকে, তাহলে সেটাকেও queue তে ঢুকাও এবং তার value v তে রাখো।

❗Note: এখানে একটু optimization করা যেত: child node গুলোর value আলাদা করে v.push_back() করার দরকার নেই কারণ BFS তে পরের iteration-এ ওদের value নেয়া হবে।


---

return v;
}

➤ অবশেষে v নামক vector টা return করলো যাতে সব node-এর value আছে।


---

🔹 isUnivalTree Function

bool isUnivalTree(TreeNode* root) 
{
    vector<int>v=bfs(root);

➤ bfs() এর মাধ্যমে সব node value একটি vector v তে আনলাম।

unordered_map<int,int>freq;
    for(int i=0;i<v.size();i++)
    {
        freq[v[i]]++;
    }

➤ freq নামক hash map এ প্রতিটি ভ্যালুর frequency count করছি।

vector<int>vv;
    for(auto it:freq)
    {
        vv.push_back(it.first);
    }

➤ ভিন্ন ভিন্ন মান (value) vv নামক vector এ রেখেছি।

bool unique=true;
    if(vv.size()!=1) 
    {
        unique=false;
    }
    return unique;
}

➤ যদি vv.size() != 1, তাহলে বুঝতে পারি tree টি uni-valued না।


---

✅ উদাহরণ দিয়ে বুঝি (Test Case Analysis)


---

✅ Example 1:

Input: [1,1,1,1,1,null,1]

1
       / \
      1   1
     / \   \
    1   1   1

➤ সব node-এর value = 1
➤ freq map: {1: 6}
➤ vv.size() = 1
🔚 Output: true


---

❌ Example 2:

Input: [2,2,2,5,2]

2
     / \
    2   2
   / \
  5   2

➤ node values: 2,2,2,5,2
➤ freq map: {2: 4, 5: 1}
➤ vv.size() = 2
🔚 Output: false


---

🔶 Time and Space Complexity

Time Complexity: O(n) → n = number of nodes (traverse every node once)

Space Complexity: O(n) → BFS queue and value vector both may take O(n) space

  Full Code:
---------------

class Solution
{
public:
    vector<int>bfs(TreeNode* root)
    {
        vector<int>v;
        if(!root) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
        if(curr->left!=nullptr)
            {
                q.push(curr->left);
                v.push_back(curr->left->val);
                //q.pop();
            }
                if(curr->right!=nullptr)
                {
                    
                q.push(curr->right);
                v.push_back(curr->right->val);
                //q.pop();
            }
            }
        return v;
        
    }
    bool isUnivalTree(TreeNode* root) 
    {
        vector<int>v=bfs(root);
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
            {
                freq[v[i]]++;
            }
        vector<int>vv;
        for(auto it:freq)
            {
                vv.push_back(it.first);
            }
        bool unique=true;
        if(vv.size()!=1) 
        {
            unique=false;
        }
        return unique;
    }
};

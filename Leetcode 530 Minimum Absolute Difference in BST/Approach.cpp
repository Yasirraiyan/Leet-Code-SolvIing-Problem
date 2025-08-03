🔍 Step 1: প্রবলেম বিশ্লেষণ (Reading the Problem Carefully)
চিন্তা করো:
তোমাকে একটি BST দেওয়া হয়েছে। BST-এর গুণগত বৈশিষ্ট্য হলো –

বাম সাবট্রির প্রতিটি ভ্যালু root.val এর চেয়ে ছোট,

ডান সাবট্রির প্রতিটি ভ্যালু root.val এর চেয়ে বড়।

তোমার কাজ: BST-এর যেকোনো দুই ভিন্ন ভিন্ন নোডের মধ্যে যেই দুইটা ভ্যালুর absolute difference সবচেয়ে কম, সেটা বের করা।

👉 মনে রাখো:
Minimum absolute difference পেতে চাইলে sorted order-এ adjacent element গুলোর মধ্যে difference হিসেব করলেই হয়।

💡 Approach চিন্তা:
✅ Core idea:
BST-এর inorder traversal করলে ভ্যালুগুলো ascending order-এ পাওয়া যায়। কিন্তু তুমি এখানে BFS (level order traversal) ব্যবহার করেছো, তারপর sort করেছো। এটা কাজ করবে ঠিকই, কিন্তু optimal না (time: O(n log n))।

✅ তোমার কোড ব্যাখ্যা (line-by-line Bangla)
cpp
Copy
Edit
vector<int>BFS(TreeNode* root)
➡️ একটি helper ফাংশন বানিয়েছো, যেটা BST-এর সব node-কে level order traversal (BFS) করে vector<int> তে রেখে দেবে।

cpp
Copy
Edit
queue<TreeNode*>q;
q.push(root);
vector<int>v;
➡️ queue ব্যবহার করে BFS করছো, আর v তে ভ্যালুগুলো রাখছো।

cpp
Copy
Edit
while(!q.empty())
{
    TreeNode* front = q.front();
➡️ queue থেকে সামনে যেটা আছে সেটা বের করছো।

cpp
Copy
Edit
    if(front!=nullptr)
    {
        v.push_back(front->val);
    }
➡️ যদি নাল না হয়, তাহলে তার ভ্যালু v তে রাখছো।

cpp
Copy
Edit
    if(front->left!=nullptr)
    {
        q.push(front->left);
    }
    if(front->right!=nullptr)
    {
        q.push(front->right);
    }
    q.pop();
}
➡️ তার বাম ও ডান সন্তান থাকলে queue তে দিচ্ছো এবং সামনে থেকে pop করছো। এভাবে সব নোড একবার করে ভিজিট হবে।

cpp
Copy
Edit
int findmin(vector<int>&arr)
➡️ এই ফাংশনটা vector থেকে মিনিমাম ভ্যালু বের করে দেয়।

cpp
Copy
Edit
sort(vv.begin(), vv.end());
➡️ BFS দিয়ে যেহেতু sorted order পাইনি, তাই এখন sort করছো।

cpp
Copy
Edit
for(int j=0; j<vv.size(); j++)
{
    if(j+1<vv.size())
    {
        r.push_back(abs(vv[j] - vv[j+1]));
    }
}
➡️ Sorted array থেকে adjacent element গুলোর absolute difference নিচ্ছো।

cpp
Copy
Edit
int mindiff = findmin(r);
return mindiff;
➡️ সব ডিফারেন্স থেকে সবচেয়ে ছোটটা রিটার্ন করছো।

🧪 Test Case দিয়ে Line-by-Line চলি
Example 1:
css
Copy
Edit
Input: root = [4,2,6,1,3]
BST Tree:

markdown
Copy
Edit
      4
     / \
    2   6
   / \
  1   3
BFS Output:
v = [4,2,6,1,3]
Sorted: vv = [1,2,3,4,6]

Adjacent differences:

|2-1| = 1

|3-2| = 1

|4-3| = 1

|6-4| = 2

So, min = 1 ⇒ ✅ Output: 1

⏱️ Time & Space Complexity:
Type	Value
Time	O(n log n) → for sort
Space	O(n) → for vector storage

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
    if(front!=nullptr)
    {
    v.push_back(front->val);
    }
    if(front->left!=nullptr)
    {
      q.push(front->left);
    }
     if(front->right!=nullptr)
    {
      q.push(front->right);
    }
    q.pop();
  }
  return v;
}
int findmin(vector<int>&arr)
{
  int min=arr[0];
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]<min)
    {
      min=arr[i];
    }
  }
  return min;
}
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int>vv=BFS(root);
        vector<int>r;
        sort(vv.begin(),vv.end());
        for(int j=0;j<vv.size();j++)
        {
          if(j+1<vv.size())
          {
            r.push_back(abs(vv[j]-vv[j+1]));
          }
        }
        int mindiff=findmin(r);
        return mindiff;
    }
};

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
static bool Compare(TreeNode* a,TreeNode* b)
{
  return a->val<b->val;
}
vector<TreeNode*>BFS(TreeNode* root)
{
  vector<TreeNode*>v;
  if(root==nullptr) return v;
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty())
  {
    TreeNode* front=q.front();
    v.push_back(front);
    q.pop();
    if(front->left!=nullptr) q.push(front->left);
    if(front->right!=nullptr) q.push(front->right);

  }
  return v;
}
    TreeNode* increasingBST(TreeNode* root)
     {
        vector<TreeNode*>vv=BFS(root);
        std::sort(vv.begin(),vv.end(),Compare);
        TreeNode* newRoot;
        for(int i=0;i<vv.size();i++)
        {
          vv[i]->left = nullptr;
            if(i + 1 < vv.size()) vv[i]->right = vv[i + 1];
            else vv[i]->right = nullptr;
        }
   
        return vv[0];
    }
};

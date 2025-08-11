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
  vector<int>v;
  if(!root) return v;
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty())
  {
    TreeNode* front=q.front();
    v.push_back(front->val);
    q.pop();
    if(front->left!=nullptr) q.push(front->left);
    if(front->right!=nullptr) q.push(front->right);
  }
  return v;
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>v1=BFS(root1);
        vector<int>v2=BFS(root2);
        vector<int>v3;
        for(int i=0;i<v1.size();i++)
        {
          v3.push_back(v1[i]);
        }
        for(int j=0;j<v2.size();j++)
        {
          v3.push_back(v2[j]);
        }
       sort(v3.begin(),v3.end());
       return v3;
    }
};

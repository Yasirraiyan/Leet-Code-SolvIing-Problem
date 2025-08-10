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
 int findlargest(vector<int>&v)
 {
  int max=v[0];
  for(int i=1;i<v.size();i++)
  {
    if(v[i]>max)
    {
      max=v[i];
    }
  }
  return max;
 }
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>vv;
        if(root==nullptr) return vv;
        while(!q.empty())
        {
          int size=q.size();
         v.clear();
           for(int i=0;i<size;i++)
           {
          
                 TreeNode* front=q.front();
                 q.pop();
                 v.push_back(front->val);
                 
               if(front->left!=nullptr) q.push(front->left);
                if(front->right!=nullptr) q.push(front->right);
           }
           vv.push_back(findlargest(v));
          
         
         

        }
        
        
       //   v.clear();
        
        return vv;
    }
};

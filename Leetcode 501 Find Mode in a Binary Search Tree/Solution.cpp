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
     v.push_back(front->val);
     q.pop();
     if(front->left!=nullptr)q.push(front->left);
     if(front->right!=nullptr)q.push(front->right);
  }
  return v;
 }
 int findmax(vector<int>&v)
 {
  int max=v[0];
  for(int j=0;j<v.size();j++)
  {
    if(v[j]>max)
    {
      max=v[j];
    }
  }
return max;
 }
    vector<int> findMode(TreeNode* root)
     {
        vector<int>v=BFS(root);
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
        {
          freq[v[i]]++;
        }
        vector<int>vv;
        for(auto it:freq)
        {
          vv.push_back(it.second);
        }
        int maxf=findmax(vv);
        vector<int>ans;
         for(auto it:freq)
        {
          if(it.second==maxf)
          {
             ans.push_back(it.first);
          }
        }
        return ans;

    }
};

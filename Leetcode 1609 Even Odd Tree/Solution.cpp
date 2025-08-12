**
 * Definition for a binary tree node.
 * struct TreeNode 
{
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
class Solution 
{
public:
 bool TestEven(vector<vector<int>>&v)
 {
   bool test=false;
   for(int i=0;i<v.size();i++)
   {
    if (i % 2 != 0) continue;
    for(int j=0;j<v[i].size();j++)
    {
      if (v[i][j] % 2 == 0) return false;
      if (j + 1 < v[i].size() && v[i][j] >= v[i][j + 1])
                return false;
   test=true;
    }
   }
   return true;
 }
 bool TestOdd(vector<vector<int>>&v)
 {
   bool test=false;
   for(int i=0;i<v.size();i++)
   {
     if (i % 2 == 0) continue;
    for(int j=0;j<v[i].size();j++)
    {
        if (v[i][j] % 2 != 0) return false;
        if (j + 1 < v[i].size() && v[i][j] <= v[i][j + 1])
                return false;

            test = true;
    }
   }
   return true;
 }
    bool isEvenOddTree(TreeNode* root) 
    {
         vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
          int size=q.size();
          vector<int>v;
          for(int k=0;k<size;k++)
          {

          
          TreeNode* front=q.front();
          q.pop();
          v.push_back(front->val);
          if(front->left!=nullptr) q.push(front->left);
          if(front->right!=nullptr) q.push(front->right);

        }
        result.push_back(v);
        }
       bool test=false;
     return TestEven(result) && TestOdd(result) || (TestEven(result) && result.size() == 1);

    }
};

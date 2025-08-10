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
class Solution {
public:
  int findsum(const vector<int>&v)
  {
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
      sum+=v[i];
    }
    return sum;
  }
  int findmax(const vector<int>&v)
  {
    int max=v[0];
    for(int j=1;j<v.size();j++)
    {
      if(v[j]>max)
      {
        max=v[j];
      }
    }
    return max;
  }
    int maxLevelSum(TreeNode* root)
     {
      if(!root) return 0;
      
        queue<TreeNode*>q;
        q.push(root);
          vector<int>vv;
         
        while(!q.empty())
        {
          int size=q.size();
            vector<int>v;
         
          for(int i=0;i<size;i++)
          {
              TreeNode* front=q.front();
                q.pop();
          v.push_back(front->val);
        
            if(front->left!=nullptr) q.push(front->left);
           if(front->right!=nullptr) q.push(front->right);
          }
          
          vv.push_back(findsum(v));
      
        
        }
        int max=findmax(vv);
        int ans;
        for(int j=0;j<vv.size();j++)
        {
          if(vv[j]==max)
          {
                 ans=j+1;
                 break;
          }
        }
        return ans;
    }
};

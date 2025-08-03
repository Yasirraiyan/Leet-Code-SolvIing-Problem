 * Definition for a binary tree node.
 * struct TreeNode 
 {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };


class Solution 
{
public:
 
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(original);
        q2.push(cloned);
        TreeNode* ans;
        while(!q1.empty()&&!q2.empty())
        {
          TreeNode* front1=q1.front();
          TreeNode* front2=q2.front();
          if(front1->val==target->val)//&&front2->val==target->val)
          {
              ans=front2;
              break;
          }
          q1.pop();
          q2.pop();
          if (front1->left && front2->left) 
          {
                q1.push(front1->left);
                q2.push(front2->left);
            }

            if (front1->right && front2->right) 
            {
                q1.push(front1->right);
                q2.push(front2->right);
            }
        }
        return ans;
    }
};

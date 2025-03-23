class Solution 
{
public:
    bool checkTree(TreeNode* root) 
    {
      bool check=false;
        int sum=0;
        sum+=(root->right->val)+(root->left->val);
        if(sum==root->val)
        {
          check=true;
        }
        return check;
    }
};

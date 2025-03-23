class Solution 
{
public:
    int countNodes(TreeNode* root) 
{
        int count=0;
        if(root==nullptr)
        {
          return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

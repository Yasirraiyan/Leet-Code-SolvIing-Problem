class Solution 
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        TreeNode* root3 ;
                if(root1->val!=root2->val)
                {
                    int s=root1->val+root2->val;
                    root3=new TreeNode(s);
                }
                if(root1->val==root2->val)
                {
                    int s=root1->val+root2->val;
                    root3=new TreeNode(s);
                }
               root3->left= mergeTrees(root1->left,root2->left);
               root3->right= mergeTrees(root1->right,root2->right);
        return root3;
    }
};

class Solution 
{
public:
    void postorder(TreeNode* root,vector<int>&v)
    {
        if(root==nullptr) return;
        if(root->left!=nullptr)
        {
            postorder(root->left,v);
        }
        if(root->right!=nullptr)
        {
            postorder(root->right,v);
        }
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>v;
        v.clear();
        postorder(root,v);
        
        
        return v;
    }
};

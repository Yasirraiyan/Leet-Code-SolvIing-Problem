class Solution
{
public:
    vector<int>v;
    void Preorder(TreeNode* root)
    {
        if(root==nullptr) return;
        v.push_back(root->val);
        if(root->left!=nullptr) Preorder(root->left);
        if(root->right!=nullptr) Preorder(root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        v.clear();
        Preorder(root);
        return v;
    }
};

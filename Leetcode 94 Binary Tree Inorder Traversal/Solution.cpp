class Solution 
{
public:
    void inorder(TreeNode* root,vector<TreeNode*>&v)
    {
        if(root==nullptr) return;
        if(root->left!=nullptr) inorder(root->left,v);
        v.push_back(root);
        if(root->right!=nullptr) inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<TreeNode*>v;
        inorder(root,v);
        vector<int>ans;
        for(int i=0;i<v.size();i++)
            {
                if(v[i]!=nullptr)
                {
            
        ans.push_back(v[i]->val);
                }
            }
        return ans;
    }
};

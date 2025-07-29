class Solution 
{
public:
    TreeNode* insert(TreeNode* root,TreeNode* node)
    {
        if(root==nullptr) return node;
        if(node->val<root->val)
        {
            root->left=insert(root->left,node);
        }
        else
        {
            root->right=insert(root->right,node);
        }
        return root;
    }
    vector<TreeNode*> bfs(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>v;
        while(!q.empty())
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr);
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
        return v;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root==nullptr) return nullptr;
        vector<TreeNode*>vv=bfs(root);
        unordered_set<int>set1;
        set1.insert(key);
        vector<TreeNode*>v;
        for(int j=0;j<vv.size();j++)
            {
                 if(set1.find(vv[j]->val)==set1.end())
                 {
                     v.push_back(vv[j]);
                 }

                
            }
    TreeNode* newroot=nullptr;
        for(TreeNode* node:v)
            {
                node->left=nullptr;
                node->right=nullptr;
                newroot=insert(newroot,node);
            }
        return newroot;
    }
};

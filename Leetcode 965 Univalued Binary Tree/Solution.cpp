class Solution
{
public:
    vector<int>bfs(TreeNode* root)
    {
        vector<int>v;
        if(!root) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
        if(curr->left!=nullptr)
            {
                q.push(curr->left);
                v.push_back(curr->left->val);
                //q.pop();
            }
                if(curr->right!=nullptr)
                {
                    
                q.push(curr->right);
                v.push_back(curr->right->val);
                //q.pop();
            }
            }
        return v;
        
    }
    bool isUnivalTree(TreeNode* root) 
    {
        vector<int>v=bfs(root);
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
            {
                freq[v[i]]++;
            }
        vector<int>vv;
        for(auto it:freq)
            {
                vv.push_back(it.first);
            }
        bool unique=true;
        if(vv.size()!=1) 
        {
            unique=false;
        }
        return unique;
    }
};

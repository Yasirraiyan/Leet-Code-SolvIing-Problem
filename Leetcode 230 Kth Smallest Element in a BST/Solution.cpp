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
                TreeNode* t=q.front();
                v.push_back(t->val);
                q.pop();
                if(t->left!=nullptr)
                {
                    q.push(t->left);
                }
                if(t->right!=nullptr)
                {
                    q.push(t->right);
                }
            }
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>vv=bfs(root);
        sort(vv.begin(),vv.end());
        unordered_map<int,int>freq;
        for(int i=0;i<vv.size();i++)
            {
                freq[vv[i]]++;
            }
        vector<int>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        sort(v.begin(),v.end());
        int ans;
        for(int j=0;j<v.size();j++)
            {
                if(j+1==k)
                {
                    ans=v[j];
                    break;
                }
            }
        return ans;
        
    }
};

class Solution
{
public:
    vector<TreeNode*> BFS(TreeNode* p)
    {
        vector<TreeNode*>v;
        if(p==nullptr) return v;
        queue<TreeNode*>q1;
        q1.push(p);
        while(!q1.empty())
            {
                TreeNode* curr=q1.front();
                
                v.push_back(curr);
                q1.pop();
                
                if(curr!=nullptr)
                {
                    q1.push(curr->left);
                    
                    q1.push(curr->right);
                } 
            }
        return v;
    }         
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*>v1=BFS(p);
        vector<TreeNode*>v2=BFS(q);
        if(v1.size()!=v2.size()) return false;
        bool issame=true;
        for(int i=0;i<v1.size();i++)
            {
                if(v1[i]==nullptr&&v2[i]==nullptr) continue;
                if(v1[i]==nullptr||v2[i]==nullptr) return false;
                        if(v1[i]->val!=v2[i]->val)
                        {
                            issame=false;
                            break;
                        }
                    }
            
        return issame;
    }
}; 

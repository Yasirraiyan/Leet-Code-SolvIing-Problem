class Solution 
{
public:
    
    vector<int>BFS(TreeNode* root)
    {
        vector<int>v;
        if(root==nullptr) return v;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        //vector<int>v;
        while(!q.empty())
            {
                TreeNode* front=q.front().first;
                int currsum=q.front().second;
                q.pop();
                if(!front->left&&!front->right)
                {
                v.push_back(currsum);
                }
                
                //q.pop();
                if(front->left)
                {
                    q.push({front->left,front->left->val+currsum});
                        }
                        if(front->right)
                        {
                            q.push({front->right,front->right->val+currsum});
                        }
                }
            
            
        return v;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        bool has=false;
        vector<int>vv=BFS(root);
        sort(vv.begin(),vv.end());
        int left=0;
        int right=vv.size()-1;
        while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(vv[mid]==targetSum)
                {
                    has=true;
                    break;
                }
                else if(vv[mid]<targetSum)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        return has;
    }
};

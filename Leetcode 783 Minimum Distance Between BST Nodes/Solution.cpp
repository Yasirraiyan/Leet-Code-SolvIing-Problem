class Solution 
{
public:
    int findmin(vector<int>&arr)
    {
        int min=arr[0];
        for(int j=1;j<arr.size();j++)
            {
                if(arr[j]<min)
                {
                    min=arr[j];
                }
            }
        return min;
    }
    vector<int>BFS(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty())
            {
                TreeNode* front=q.front();
                if(front!=nullptr)
                {
                v.push_back(front->val);
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
        return v;
    }
    int minDiffInBST(TreeNode* root)
    {
        vector<int>vv=BFS(root);
        vector<int>v;
        sort(vv.begin(),vv.end());
        for(int i=1;i<vv.size();i++)
            {
                v.push_back(abs(vv[i]-vv[i-1]));
            }
        int mindiff=findmin(v);
        return mindiff;
    }
};

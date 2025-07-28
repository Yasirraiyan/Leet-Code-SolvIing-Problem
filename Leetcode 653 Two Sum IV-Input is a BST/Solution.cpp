/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    bool Target(int a,int b,int target)
    {
        bool find=false;
        int sum=a+b;
        if(sum==target)
        {
            find=true;
        }
        return find;
    }
    vector<int> BFS(TreeNode* root)
    {
        vector<int>v;
        if(root==nullptr) return v;
        queue<TreeNode*>q;
        q.push(root);
        //vector<int>v;
        while(!q.empty())
            {
                TreeNode* f=q.front();
                //int front=q.front()->val;
                v.push_back(f->val);
                q.pop();
                if(f->left!=nullptr)
                {
                    q.push(f->left);
                }
                if(f->right!=nullptr)
                {
                q.push(f->right);
            }
            }
        return v;
    }
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int>v=BFS(root);
        for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                    {
                        if(Target(v[i],v[j],k))
                        {
                            return true;
                        }
                    }
            }
            
        return false;
    }
};

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
int left=0;
        int right=v.size()-1;
        sort(v.begin(),v.end());
        bool find=false;
        while(left<right)
            {
                if(v[left]+v[right]<k)
                {
                    left++;
                }
                else if(v[left]+v[right]==k)
                {
                    find=true;
                    break;
                }
                else
                {
                    right--;
                }
            }
        
            
        return find;
    }
};

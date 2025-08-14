class Solution 
{
public:
vector<int> Tilt(TreeNode* root)
{
    vector<int>v;
     TiltHelper(root,v);
     return v;
}
int findsum(vector<int>&v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    return sum;
}
int TiltHelper(TreeNode* root,vector<int>&v)
{
    if(root==nullptr) return 0;
    int leftsum=TiltHelper(root->left,v);
    int rightsum=TiltHelper(root->right,v);
    int tilt=abs(leftsum-rightsum);
    v.push_back(tilt);
    return leftsum+rightsum+root->val;
}
    int findTilt(TreeNode* root) 
    {
        vector<int>vv=Tilt(root);
       int ans=findsum(vv);
       return ans;

    }
};

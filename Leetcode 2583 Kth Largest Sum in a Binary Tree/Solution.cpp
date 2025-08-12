class Solution 
{
public:
vector<long long>SUMBFS(TreeNode* root)
{
    vector<long long>v;
    if(!root) return v;
  queue<TreeNode*>q;
  q.push(root);

  long long sum=0;
  while(!q.empty())
  {
    int size=q.size();
    sum=0;
    for(int i=0;i<size;i++)
    {
    TreeNode* front=q.front();
    q.pop();
    sum+=front->val;
  
   
   if(front->left!=nullptr) q.push(front->left);
   if(front->right!=nullptr) q.push(front->right);
  }
   v.push_back(sum);
 
}
return v;
}
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
       vector<long long>vv=SUMBFS(root);
       sort(vv.begin(),vv.end());
       vector<int>v;
       long long ans=-1;
       if (k > (int)vv.size()) return ans;
  ans=vv[vv.size()-k];
   
       return ans;
    }
};

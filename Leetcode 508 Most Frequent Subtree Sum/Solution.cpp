class Solution 
{
public:
int findSubtreeSum(TreeNode* root,vector<int>&v)
 {
  if(root==nullptr) return 0;
  int leftsum=findSubtreeSum(root->left,v);
  int rightsum=findSubtreeSum(root->right,v);
  int sum=root->val+leftsum+rightsum;
  v.push_back(sum);
  return sum;
 }
 int findmax(vector<int>&v)
 {
  int max=v[0];
  for(int j=1;j<v.size();j++)
  {
    if(v[j]>max)
    {
      max=v[j];
    }
  }
  return max;
 }
    vector<int> findFrequentTreeSum(TreeNode* root)
     {
        vector<int>v;
        findSubtreeSum(root,v);
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
        {
          freq[v[i]]++;
        }
        vector<int>vv;
        for(auto it:freq)
        {
          vv.push_back(it.second);
        }
        int maxf=findmax(vv);
        vector<int>ans;
        for(auto it:freq)
        {
          if(it.second==maxf)
          {
            ans.push_back(it.first);
          }
        }
        return ans;
    }
};

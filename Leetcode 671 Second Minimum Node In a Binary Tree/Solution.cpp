class Solution 
{
public:
 vector<int>BFS(TreeNode* root)
 {
  queue<TreeNode*>q;
  q.push(root);
  vector<int>v;
  while(!q.empty())
  {
    TreeNode* front=q.front();
    q.pop();
    if(front!=nullptr)
    {
    v.push_back(front->val);
  }
  if(front->left!=nullptr) q.push(front->left);
  if(front->right!=nullptr) q.push(front->right);
  
  }
  return v;
 }
    int findSecondMinimumValue(TreeNode* root) 
    {
      vector<int>vv=BFS(root);
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
        int secondmin;
        if(v.size()>=2)
        {
        secondmin=v[1];
        }
        else
        {
          return -1;
        }
        ans=secondmin;
        return ans;

    }
};

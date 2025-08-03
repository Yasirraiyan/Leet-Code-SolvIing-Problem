 * Definition for a binary tree node.
 * struct TreeNode 
 {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

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
    if(front!=nullptr)
    {
    v.push_back(front->val);
    }
    if(front->left!=nullptr)
    {
      q.push(front->left);
    }
     if(front->right!=nullptr)
    {
      q.push(front->right);
    }
    q.pop();
  }
  return v;
}
int findmin(vector<int>&arr)
{
  int min=arr[0];
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]<min)
    {
      min=arr[i];
    }
  }
  return min;
}
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int>vv=BFS(root);
        vector<int>r;
        sort(vv.begin(),vv.end());
        for(int j=0;j<vv.size();j++)
        {
          if(j+1<vv.size())
          {
            r.push_back(abs(vv[j]-vv[j+1]));
          }
        }
        int mindiff=findmin(r);
        return mindiff;
    }
};

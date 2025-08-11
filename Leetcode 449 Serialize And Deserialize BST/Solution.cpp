class Codec 
{
public:
vector<int>BFS(TreeNode* root)
{
  queue<TreeNode*>q;
 vector<int>v;
 if(!root) return v;
   q.push(root);
  while(!q.empty())
  {
    TreeNode* front=q.front();
    v.push_back(front->val);
    q.pop();
    if(front->left!=nullptr)
    {
      q.push(front->left);
    }
    if(front->right!=nullptr)
    {
      q.push(front->right);
    }
  }
  return v;
}
TreeNode* insertBST(TreeNode* root,int val)
{
  if(!root) return new TreeNode(val);
  if(val<root->val) root->left=insertBST(root->left,val);
  if(val>root->val) root->right=insertBST(root->right,val);
  return root;
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
     {
        vector<int>vv=BFS(root);
        if(vv.empty()) return "";
        string ans="";
        for(int i=0;i<vv.size();i++)
        {
          ans+=to_string(vv[i])+' ';
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
      stringstream ss(data);
      int n;
        vector<int>vv;
       while(ss>>n)
       {
        vv.push_back(n);
       }
        if(vv.size()==0) return NULL;
        TreeNode* root=new TreeNode(vv[0]);
        for(size_t k=1;k<vv.size();k++)
        {
          root=insertBST(root,vv[k]);
        }
        return root;
    }
};

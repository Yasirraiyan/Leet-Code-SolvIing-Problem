class Solution 
{
public:
 
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      vector<vector<int>>v;
      if (root == nullptr) return v;
     
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty())
      {
         int size = q.size();   
          vector<int>vv;
         for (int i = 0; i < size; ++i)
            {     
        TreeNode* front=q.front();
        q.pop();
        vv.push_back(front->val);
        if(front->left!=nullptr)
        {
          q.push(front->left);
        }
        if(front->right!=nullptr)
        {
          q.push(front->right);
        }
      }
      v.push_back(vv);
      }
//for(int i=0;i<vv.size();i++)
//{
  
//}
return v;
    }
};

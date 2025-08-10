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
class Solution {
public:
bool CheckLeaf(TreeNode* root)
 {
 
    if(root == nullptr) return false;
bool isleaf=false;
return (root->left==nullptr&&root->right==nullptr) ;
       
 
  
    
 }
 vector<int>Leaf(TreeNode* root)

{
  vector<int>lf;
   if(root == nullptr) return lf;

  if(CheckLeaf(root))
  {
    lf.push_back(root->val);
  return lf;
  }
   vector<int> leftLeaves = Leaf(root->left);
    for (int i = 0; i < (int)leftLeaves.size(); i++) {
        lf.push_back(leftLeaves[i]);
    }

    // ডান subtree থেকে leaf গুলো নিয়ে আসুন
    vector<int> rightLeaves = Leaf(root->right);
    for (int i = 0; i < (int)rightLeaves.size(); i++) {
        lf.push_back(rightLeaves[i]);
    }
 return lf;
}   
bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
      vector<int>v=Leaf(root1);
      vector<int>vv=Leaf(root2);
        unordered_set<int>set1;
        if(v.size() != vv.size()) return false;
        bool similar=true;
         
         for(int i=0;i<v.size();i++)
         {
          if(v[i]!=vv[i])
          {
            similar=false;
            break;
          }
         }
        return similar;
    }
};

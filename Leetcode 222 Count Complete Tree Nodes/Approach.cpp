Amar 1 ta tree r node:
root,left subtree r node gula, right subtree r node gular

root 1 ta node
So,
1+left_subtree r node+ right_subtree r node

As tree r level onk gula thakte pare
Tai bar bar traverse korbo
Tai recursion apply korbo ba function er 
recursive call korbo.

  Jodi root na thake mane node na thake taie
Tree er node 0 
So,
root hoilo null
Condition:
-----------

  if(root==nullptr)
  {
return 0;
}
na hoile
root+leftsubtree+rightsubtree
  So,
  multiple level tai recursive call for function
So,
Function hoilo
int countnodes(TreeNode *root)
Recursive approach;
-----------------------

 int  ans=1+countnodes(root->left)+countnodes(root->right)
  return ans;

Full Code:
-----------

  class Solution 
{
public:
    int countNodes(TreeNode* root) 
{
        int count=0;
        if(root==nullptr)
        {
          return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

Amar 1 ta tree ase.Level more tan 1 hote pare. Amar chaise left leaf er jogfol.
Age test korbo eta leaf kina
mane etar left->left==nullptr && left->right==nullptr taile leaf
as root theke test tai 
(root->left->left==nullptr)&&(root->left->right==nullptr)
  root!=nullptr root null hole leaf nai ba tree nai
So,
  condition is:
-------------------

  if((root->left!=nullptr)&&(root->left->left==nullptr)&&(root->left->right==nullptr))
      {
            sum+=root->left->val;
      }
jodi root null hoy taile return 0;
So,
     if(root==nullptr)
      {
        return 0;
      }
As root er level 1 er beshi hte pare tai recursive call korbo
both right and left subtree te
So,
 sum+= sumOfLeftLeaves(root->left);
        sum+= sumOfLeftLeaves(root->right);
return kori sum.

Full Code:
------------
  class Solution 
{
public:

    int sumOfLeftLeaves(TreeNode* root) 
    {
      int sum=0;
      if(root==nullptr)
      {
        return 0;
      }
      if((root->left!=nullptr)&&(root->left->left==nullptr)&&(root->left->right==nullptr))
      {
            sum+=root->left->val;
      }
     
      sum+= sumOfLeftLeaves(root->left);
        sum+= sumOfLeftLeaves(root->right);
      return sum;
       
    }
};

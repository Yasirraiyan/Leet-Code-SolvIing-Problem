Amar 1 ta tree ase.Amar check korte hbe j er children gular sum root er soman kina.
1 ta varable nei sum ja initial 0.
initial 1 ta variable nei check bool type ja initial false.Eta dia check korbo same kina
sum+=root->left->val;
sum+=root->right->val;
 check for same:
--------------------
root->val==sum
  So,
  if(sum==root->val)
        {
          check=true;
        }
return kori check.

Full Code:
-----------

  class Solution 
{
public:
    bool checkTree(TreeNode* root) 
    {
      bool check=false;
        int sum=0;
        sum+=(root->right->val)+(root->left->val);
        if(sum==root->val)
        {
          check=true;
        }
        return check;
    }
};
  

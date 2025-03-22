Amar 1 ta binary search tree (BST) ase.root er array ase. 2 ta pointer ase low,high .amar range [low,high] er joto node ase sobar sum chaise.
  initial `1 ta varible nei int sum ja 0
check kori root array r value range e kinas 
so,
  if(root->val>=low&&root->val<=high)

  hoile 
sum+=root->val kori
mani root array r value add kori
as 
BST er level 1 er beshi thakte pare 
tai 
function recursive call kori
  sum+=rangeSumBST(root->left,low,high);
   sum+=rangeSumBST(root->right,low,high);
sum return kori

Full Code:
-----------
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
 class Solution 
 {
public:
 int rangeSumBST(TreeNode *root,int low,int high)
 {
     if (!root) return 0;
    int sum=0;
    if(root->val>=low&&root->val<=high)
    {
   sum+=root->val;
    }
   sum+=rangeSumBST(root->left,low,high);
   sum+=rangeSumBST(root->right,low,high);
   return sum;
 }
 };
 

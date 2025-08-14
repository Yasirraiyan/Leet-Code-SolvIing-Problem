প্রশ্নের বিশ্লেষণ (How to think about the problem)

Node Tilt:

প্রতিটি node এর tilt = |sum of left subtree nodes − sum of right subtree nodes|

যদি কোন child না থাকে, তার subtree sum = 0।

Total Tilt:

সব node এর tilt যোগ করতে হবে।

ধাপে ধাপে চিন্তাভাবনা:

যেহেতু tilt নির্ভর করে subtree sums এর উপর, আমরা post-order traversal ব্যবহার করতে পারি।

প্রথমে left subtree sum বের করো।

তারপর right subtree sum বের করো।

তারপর node tilt বের করে যোগ করো।

প্রতিটি node এর জন্য subtree sum ফাংশন থেকে রিটার্ন করতে হবে, যাতে parent node tilt হিসাব করতে পারে।

কোডের স্ট্রাকচার ও লজিক
class Solution 
{
public:
    vector<int> Tilt(TreeNode* root)
    {
        vector<int>v;
        TiltHelper(root,v);
        return v;
    }


Tilt ফাংশন:

মূল উদ্দেশ্য: সব node এর tilt vector<int> v তে collect করা।

আমরা helper function ব্যবহার করি যেটা subtree sum হিসাব করে এবং tilt যোগ করে।

int TiltHelper(TreeNode* root,vector<int>&v)
{
    if(root==nullptr) return 0; // যদি node null হয়, sum=0


Base case: যদি node খালি (nullptr) হয়, তাহলে subtree sum = 0।

    int leftsum=TiltHelper(root->left,v);   // left subtree sum বের করা
    int rightsum=TiltHelper(root->right,v); // right subtree sum বের করা


Recursive call:

প্রথমে left subtree sum বের করি

তারপর right subtree sum বের করি

(এই জন্য post-order traversal ব্যবহার করা হয়)

    int tilt=abs(leftsum-rightsum); // tilt হিসাব
    v.push_back(tilt);              // tilt vector এ add করা


Node এর tilt = leftsum এবং rightsum এর absolute difference

tilt vector এ store করি পরে সব tilt যোগ করার জন্য

    return leftsum+rightsum+root->val; // এই node সহ subtree sum return
}


Node সহ subtree sum parent কে return করি

এটি parent node tilt হিসাব করার জন্য লাগে

int findsum(vector<int>&v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    return sum;
}


সব node tilt যোগ করে total tilt বের করার জন্য।

int findTilt(TreeNode* root) 
{
    vector<int>vv=Tilt(root);   // সব tilt vector পাই
    int ans=findsum(vv);         // total tilt বের করি
    return ans;
}


মূল ফাংশন:

Tilt() কল করে সব node tilt বের করি

findsum() ব্যবহার করে total tilt বের করি

return করি

Test Case Walkthrough
Example 1: [1,2,3]

Tree:

    1
   / \
  2   3


Step by step:

TiltHelper(2)

leftsum = 0, rightsum = 0

tilt = |0-0| = 0

return 2 (subtree sum)

TiltHelper(3)

leftsum = 0, rightsum = 0

tilt = |0-0| = 0

return 3 (subtree sum)

TiltHelper(1)

leftsum = 2, rightsum = 3

tilt = |2-3| = 1

return 1+2+3 = 6

Vector of tilts: [0,0,1]
Sum: 0+0+1=1 ✅

Example 2: [4,2,9,3,5,null,7]

Tree:

        4
       / \
      2   9
     / \    \
    3   5    7


Step by step (post-order):

Node 3: tilt = 0

Node 5: tilt = 0

Node 2: tilt = |3-5| = 2

Node 7: tilt = 0

Node 9: tilt = |0-7| = 7

Node 4: tilt = |(3+5+2) - (9+7)| = |10-16| = 6

Vector of tilts: [0,0,2,0,7,6]
Sum: 15 ✅

কেন Accepted হলো

সব node post-order traverse করা হয়েছে → সব subtree sum সঠিক।

tilt correctly calculate করা হয়েছে: left sum - right sum।

সব tilt vector এ store করা হয়েছে, পরে sum করা হয়েছে।

Edge cases যেমন null node handled হয়েছে (sum=0)।

Time complexity: O(N) (N = number of nodes) → প্রত্যেক node একবার visit করা হয়েছে।

Space complexity: O(N) (tilt vector + recursion stack)।

✅ সংক্ষেপে approach:

Recursive function ব্যবহার করে post-order traversal

প্রতিটি node এর left sum, right sum বের করা

tilt বের করে vector এ রাখা

subtree sum return করা parent node এর জন্য

সব tilt যোগ করে final answer return করা

Full Code:
-------------

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
vector<int> Tilt(TreeNode* root)
{
    vector<int>v;
     TiltHelper(root,v);
     return v;
}
int findsum(vector<int>&v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    return sum;
}
int TiltHelper(TreeNode* root,vector<int>&v)
{
    if(root==nullptr) return 0;
    int leftsum=TiltHelper(root->left,v);
    int rightsum=TiltHelper(root->right,v);
    int tilt=abs(leftsum-rightsum);
    v.push_back(tilt);
    return leftsum+rightsum+root->val;
}
    int findTilt(TreeNode* root) 
    {
        vector<int>vv=Tilt(root);
       int ans=findsum(vv);
       return ans;

    }
};

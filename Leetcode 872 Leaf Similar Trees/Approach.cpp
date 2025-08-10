প্রশ্নটা কী বলছে?
দুইটা বাইনারি ট্রির লিফ (leaf) নোডগুলো একে অপরের সাথে লিফ সিকুয়েন্স (left to right leaf node values) যদি একই হয়, তাহলে ওরা leaf-similar।

অর্থাৎ, দুইটা ট্রির সবগুলো লিফ (যেগুলো left থেকে right ক্রমানুসারে) একসাথে তুলনা করতে হবে।

যদি দুটোর লিফ গুলোর মান একই ক্রমে থাকে, তাহলে return true, নাহলে false।

কোডের মূল অংশের ব্যাখ্যা
১. CheckLeaf ফাংশন:
cpp
Copy
Edit
bool CheckLeaf(TreeNode* root) {
    if(root == nullptr) return false;
    return (root->left == nullptr && root->right == nullptr);
}
কোন নোড লিফ কিনা সেটা চেক করে।

লিফ মানে: কোন চাইল্ড নেই। তাই, লেফট আর রাইট দুইটাই নাল হলে সেটা লিফ।

২. Leaf ফাংশন:
cpp
Copy
Edit
vector<int> Leaf(TreeNode* root) {
    vector<int> lf;
    if(root == nullptr) return lf;

    if(CheckLeaf(root)) {
        lf.push_back(root->val);
        return lf;
    }

    vector<int> leftLeaves = Leaf(root->left);
    for (int i = 0; i < (int)leftLeaves.size(); i++) {
        lf.push_back(leftLeaves[i]);
    }

    vector<int> rightLeaves = Leaf(root->right);
    for (int i = 0; i < (int)rightLeaves.size(); i++) {
        lf.push_back(rightLeaves[i]);
    }
    return lf;
}
এটা রিকার্সিভ (recursive) ফাংশন।

যেকোনো নোডকে ইনপুট হিসেবে নেয়, তারপর তার লিফ গুলো খুঁজে বের করে vector<int> আকারে রিটার্ন করে।

কাজের ধাপ:

যদি নোড null হয়, তাহলে খালি vector রিটার্ন করবে।

যদি নোডটা লিফ হয়, তাহলে তার মান একটিমাত্র ভেক্টরে রাখবে আর রিটার্ন করবে।

না হলে,

লেফট subtree এর লিফ গুলো বের করবে (recursive call)

রাইট subtree এর লিফ গুলো বের করবে

দুটো ভেক্টরের মান মিলিয়ে একটা বড় ভেক্টর বানাবে।

অর্থাৎ লিফ গুলো left থেকে right order এ একত্রে বের হবে।

৩. leafSimilar ফাংশন:
cpp
Copy
Edit
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v = Leaf(root1);
    vector<int> vv = Leaf(root2);

    if(v.size() != vv.size()) return false; // লিফ গুলো সংখ্যা যদি না মেলে, false

    for(int i=0; i < v.size(); i++) {
        if(v[i] != vv[i]) {
            return false; // যেকোনো পয়েন্টে মান না মেলে false
        }
    }
    return true; // সব মিললে true
}
প্রথমে দুটো ট্রির লিফ সিকুয়েন্স বের করল।

তারপর দুটো সিকুয়েন্সের সাইজ চেক করল।

পরবর্তীতে এক এক করে মান গুলো তুলনা করল।

সব মিললে true রিটার্ন করবে, অন্যথায় false।

কিভাবে তুমি কোডটা লিখতে পারো প্রশ্নটা পড়ে?
প্রথমে বুঝবে লিফ সিকুয়েন্স বলতে কী বুঝাচ্ছে?

লিফ গুলো left থেকে right ক্রমানুসারে একটার পর একটা।

লিফ গুলো বের করতে কী করা যায়?

রিকার্সিভ traversal (inorder / preorder / postorder) করার সময় check করতে হবে নোড লিফ কিনা।

লিফ হলে সেটাকে collect করতে হবে।

লিফগুলো একসাথে নিয়ে এলেই সমস্যার সমাধান?

হ্যাঁ, দুইটা ট্রির লিফ সিকুয়েন্স বের করার পর তুলনা করলেই কাজ শেষ।

কোডিং স্টেপ:

লিফ চেক করার ফাংশন লিখো (CheckLeaf)

লিফ গুলো বের করার রিকার্সিভ ফাংশন লিখো (Leaf)

লিফ সিকুয়েন্স তুলনা করার ফাংশন (leafSimilar)

কেন এই কোড accepted হয়? (Testcase ধরে বুঝি)
Example:

root1 = [3,5,1,6,2,9,8,null,null,7,4]
root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

কোড প্রথমে Leaf(root1) বলবে:

লিফ গুলো: 6,7,4,9,8 (left to right)

তারপর Leaf(root2) বলবে:

লিফ গুলো: 6,7,4,9,8

লিফ গুলো একই সিকুয়েন্স পাওয়া গেলে true দিবে।

লাইন বাই লাইন কোডে কী হচ্ছে? (সংক্ষেপে)
cpp
Copy
Edit
bool CheckLeaf(TreeNode* root) {
    if(root == nullptr) return false;  // নোড না থাকলে false
    return (root->left == nullptr && root->right == nullptr); // কোন চাইল্ড নেই? লিফ
}

vector<int> Leaf(TreeNode* root) {
    vector<int> lf;
    if(root == nullptr) return lf;    // খালি ভেক্টর

    if(CheckLeaf(root)) {             // যদি লিফ হয়,
        lf.push_back(root->val);     // তার মান যোগ করো
        return lf;                   // রিটার্ন করো
    }

    vector<int> leftLeaves = Leaf(root->left);   // লেফট subtree থেকে লিফ সংগ্রহ
    for (auto val : leftLeaves) {
        lf.push_back(val);
    }

    vector<int> rightLeaves = Leaf(root->right); // রাইট subtree থেকে লিফ সংগ্রহ
    for (auto val : rightLeaves) {
        lf.push_back(val);
    }
    return lf;   // পুরো লিফ সিকুয়েন্স রিটার্ন
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v = Leaf(root1);      // root1 এর লিফ সিকুয়েন্স
    vector<int> vv = Leaf(root2);     // root2 এর লিফ সিকুয়েন্স

    if(v.size() != vv.size()) return false;   // সাইজ না মেলে false

    for(int i=0; i<v.size(); i++) {
        if(v[i] != vv[i]) return false;        // কোন মান না মেলে false
    }
    return true;    // সব মিলে গেলে true
}
সংক্ষিপ্ত উপসংহার:
তুমি প্রথমে লিফ চেক করার একটা ফাংশন করো।

তারপর রিকার্সিভভাবে লিফ নোড গুলো বের করো left subtree থেকে, তারপর right subtree থেকে।

লিফ গুলো যোগ করে একটা vector বানাও।

দুইটা ট্রির লিফ vector তুলনা করো।

মিললে true, না হলে false রিটার্ন করো।

  Full Code:
----------------

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

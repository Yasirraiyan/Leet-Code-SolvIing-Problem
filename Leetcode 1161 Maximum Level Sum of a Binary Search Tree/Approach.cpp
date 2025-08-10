প্রশ্নের সারাংশ:
আমাদের একটা বাইনারি ট্রি দেয়া আছে। ট্রির লেভেল গুলো ১ থেকে শুরু। প্রথম লেভেলের মান হলো রুটের মান, দ্বিতীয় লেভেলের মান হলো রুটের বাচ্চাদের মান, তৃতীয় লেভেলের মান হলো তাদের বাচ্চাদের মান, ইত্যাদি।
তুমি এমন একটা লেভেল বের করতে হবে যার সমস্ত নোডের মান যোগফল সবচেয়ে বেশি।

কোডের মূল ধাপগুলো:
১. বাইনারি ট্রি লেভেল-বাই-লেভেল ট্রাভার্সাল (BFS) করা হচ্ছে:
cpp
Copy
Edit
queue<TreeNode*> q;
q.push(root);
এখানে আমরা একটি কিউ তৈরি করেছি এবং প্রথমে রুট নোড কিউতে ঢুকিয়েছি।

এরপর আমরা কিউ খালি না হওয়া পর্যন্ত ট্রি এর প্রতিটি লেভেলের নোডগুলোকে একবারে প্রসেস করব।

২. প্রতিটি লেভেলের সব নোড একসাথে প্রসেস:
cpp
Copy
Edit
int size = q.size();
vector<int> v;
for(int i = 0; i < size; i++) {
    TreeNode* front = q.front();
    q.pop();
    v.push_back(front->val);
    if(front->left != nullptr) q.push(front->left);
    if(front->right != nullptr) q.push(front->right);
}
size হলো ওই লেভেলের নোড সংখ্যা।

তারপর লুপে প্রত্যেক নোডের মান v ভেক্টরে যোগ করি।

একই সাথে, ঐ নোডের বাচ্চাদের কিউতে ঢুকিয়ে দেই, যাতে পরের লেভেল প্রসেস করা যায়।

৩. প্রতি লেভেলের মানের যোগফল বের করা:
cpp
Copy
Edit
vv.push_back(findsum(v));
এখানে findsum ফাংশন দিয়ে ঐ লেভেলের সব নোডের মানের যোগফল বের করে vv ভেক্টরে রাখছি।

অর্থাৎ, vv[0] হলো লেভেল ১ এর যোগফল, vv[1] হলো লেভেল ২ এর যোগফল, ইত্যাদি।

৪. সবচেয়ে বড় যোগফল খুঁজে বের করা:
cpp
Copy
Edit
int max = findmax(vv);
findmax ফাংশন vv ভেক্টর থেকে সর্বোচ্চ মান খুঁজে দেয়।

৫. সর্বোচ্চ যোগফল যেই লেভেলে আছে সেটি বের করা:
cpp
Copy
Edit
int ans;
for(int j = 0; j < vv.size(); j++) {
    if(vv[j] == max) {
        ans = j + 1;
        break;
    }
}
return ans;
যেহেতু লেভেল ১ থেকে শুরু, তাই ইন্ডেক্সের সাথে ১ যোগ করি।

প্রথমে যেই লেভেলে সর্বোচ্চ যোগফল পাওয়া যায় সেটাই রিটার্ন করি।

তোমার ভাবনা কোডে কিভাবে রূপ পেল:
ট্রাভার্সাল ভাবনা:
প্রশ্ন পড়ে বুঝলে, তুমি বুঝতে পারছো লেভেল অনুযায়ী ট্রি ট্রাভার্স করলেই সহজ হবে। তাই কিউ ব্যবহার করে লেভেল-বাই-লেভেল ট্রাভার্সাল করার চিন্তা করেছো।

প্রতিটি লেভেলের মান গুলো আলাদা আলাদা রাখার চিন্তা:
প্রতিটি লেভেলের মানের যোগফল বের করার জন্য আলাদা ভেক্টরে সব লেভেলের যোগফল রাখতে হবে।

সর্বোচ্চ মান খুঁজে বের করার জন্য ফাংশন বানানো:
বড় সংখ্যাটা বের করার জন্য আলাদা findmax ফাংশন লিখেছো, যা বড় সংখ্যাটা খুঁজে দিবে।

সঠিক লেভেল নির্ণয় করার জন্য লেভেল + 1 যুক্ত করেছো:
কারণ ভেক্টরের ইন্ডেক্স ০ থেকে শুরু, কিন্তু লেভেল ১ থেকে।

লাইন বাই লাইন কোড পরীক্ষা (Example: [1,7,0,7,-8,null,null]):
লেভেল	নোড (Queue থেকে)	যোগফল (v)	vv (সর্বোচ্চ মান গুলো)
1	1	1	[1]
2	7, 0	7 + 0 = 7	[1, 7]
3	7, -8	7 + (-8) = -1	[1, 7, -1]

এখন findmax ফাংশনে সর্বোচ্চ ৭ পাওয়া যাবে।

vv এর মধ্যে ৭ vv[1] এ আছে, অর্থাৎ লেভেল ২ তে।

তাই রিটার্ন হবে ২।

কোড কেন Accepted হয়?
সময় জটিলতা:
ট্রি’র প্রতিটি নোড একবার করে প্রসেস করা হচ্ছে, তাই O(N) যেখানে N = নোড সংখ্যা।

সঠিক লেভেল নির্ণয়:
লেভেল এক্সটি সর্বোচ্চ যোগফলের লেভেল ঠিকমতো রিটার্ন করা হচ্ছে।

নাল পয়েন্টার চেক:
শিশু নোডগুলো নাল কিনা যাচাই করে, তাই কোন runtime error হয় না।

সীমাবদ্ধ ইনপুট:
constraints অনুযায়ী কাজ সঠিকভাবে করে।

বাংলায় সারমর্ম:
তুমি লেভেল-বাই-লেভেল (BFS) ট্রাভার্স করেছো।

প্রতিটি লেভেলের মান গুলো আলাদা ভেক্টরে রেখেছো।

সর্বোচ্চ যোগফল বের করে সেটার লেভেল রিটার্ন করেছো।

কোডে সবটা ঠিক আছে, তাই accepted হয়েছে।


Full Code:
------------

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
  int findsum(const vector<int>&v)
  {
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
      sum+=v[i];
    }
    return sum;
  }
  int findmax(const vector<int>&v)
  {
    int max=v[0];
    for(int j=1;j<v.size();j++)
    {
      if(v[j]>max)
      {
        max=v[j];
      }
    }
    return max;
  }
    int maxLevelSum(TreeNode* root)
     {
      if(!root) return 0;
      
        queue<TreeNode*>q;
        q.push(root);
          vector<int>vv;
         
        while(!q.empty())
        {
          int size=q.size();
            vector<int>v;
         
          for(int i=0;i<size;i++)
          {
              TreeNode* front=q.front();
                q.pop();
          v.push_back(front->val);
        
            if(front->left!=nullptr) q.push(front->left);
           if(front->right!=nullptr) q.push(front->right);
          }
          
          vv.push_back(findsum(v));
      
        
        }
        int max=findmax(vv);
        int ans;
        for(int j=0;j<vv.size();j++)
        {
          if(vv[j]==max)
          {
                 ans=j+1;
                 break;
          }
        }
        return ans;
    }
};

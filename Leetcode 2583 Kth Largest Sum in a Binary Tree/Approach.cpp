প্রশ্নটা কেমন
আমাদের একটা বাইনারি ট্রি দেওয়া আছে, যেখানে প্রতিটি নোডের একটা মান আছে।

ট্রির প্রতিটি লেভেলের (স্তরের) সব নোডের মান যোগ করতে হবে, যেটাকে বলা হচ্ছে level sum।

তোমাকে k-তম সবচেয়ে বড় লেভেল সাম বের করতে হবে।

যদি লেভেল সংখ্যা k-থেকে কম হয়, তাহলে -1 রিটার্ন করতে হবে।

কিভাবে সমাধানের ভাবনা (Approach)
১. লেভেল বাই লেভেল ট্রি ট্রাভার্সাল:

ট্রি’র লেভেল গুলো আলাদা করে নিতে হবে। এর জন্য আমরা সাধারণত BFS (Breadth First Search) বা Queue ব্যবহার করি।

কারণ Queue ব্যবহার করলে, একবারে আমরা একই লেভেলের সব নোড প্রসেস করতে পারি।

২. প্রতিটি লেভেলের নোড মান যোগ করা:

একবার Queue-তে ওই লেভেলের সব নোড বের করে তাদের মান যোগ করতে হবে।

৩. সকল লেভেলের যোগফল জমা রাখা:

প্রতিটি লেভেলের যোগফল একটা ভেক্টরে রাখবো।

৪. সর্বোচ্চ থেকে k-তম বড় মান বের করা:

লেভেলগুলোর যোগফল গুলোকে সাজিয়ে (sort)

k-তম বড় মান নির্বাচন করা (যেমন sorted array থেকে v[v.size()-k])

৫. যদি লেভেল সংখ্যা কম হয় তাহলে -1 রিটার্ন করা।

কোডটা কীভাবে কাজ করে লাইন বাই লাইন
cpp
Copy
Edit
vector<long long> SUMBFS(TreeNode* root)
{
    vector<long long> v;   // এখানে লেভেলগুলোর যোগফল রাখা হবে
    if(!root) return v;    // যদি ট্রি খালি হয়, খালি ভেক্টর রিটার্ন

    queue<TreeNode*> q;
    q.push(root);          // রুট নোড Queue তে ঢুকিয়ে দেয়া হলো

    long long sum = 0;
    while(!q.empty())      // যতদিন Queue খালি না হবে
    {
        int size = q.size();  // এই লেভেলে কয়টা নোড আছে সেটি জানতে হবে
        sum = 0;             // লেভেল স্যাম এর জন্য sum রিসেট করা হলো
        for(int i = 0; i < size; i++)  // লেভেলের সব নোড প্রসেস করবো
        {
            TreeNode* front = q.front();  // সামনে থেকে নোড নেয়া হলো
            q.pop();
            sum += front->val;            // মান যোগ করা হলো

            // পরের লেভেলের জন্য তার বাচ্চাদের Queue তে ঢুকানো হলো
            if(front->left != nullptr) q.push(front->left);
            if(front->right != nullptr) q.push(front->right);
        }
        v.push_back(sum);  // এই লেভেলের যোগফল ভেক্টরে রাখা হলো
    }
    return v;  // সব লেভেলের যোগফল ফিরিয়ে দেয়া হলো
}
cpp
Copy
Edit
long long kthLargestLevelSum(TreeNode* root, int k) 
{
    vector<long long> vv = SUMBFS(root);  // লেভেল সাম নিয়ে এলাম

    sort(vv.begin(), vv.end());  // ছোট থেকে বড় সাজালাম

    long long ans = -1;
    if (k > (int)vv.size()) return ans;  // লেভেল কম হলে -1 রিটার্ন

    ans = vv[vv.size() - k];  // k-তম বড় মান নেওয়া হলো

    return ans;
}
কেন এই কোড টেস্ট কেস পাস করে?
বৈধতা চেক: প্রথমেই চেক করা হয়, ট্রি খালি কিনা। খালি হলে খালি ভেক্টর রিটার্ন, ফলে কনসোল সমস্যা হয় না।

ব্রেডথ ফার্স্ট সার্চ (BFS) দিয়ে একেক লেভেলের সব নোডের মান একসাথে যোগ করা হয়, ফলে লেভেল সাম সঠিক পাওয়া যায়।

সকল লেভেলের যোগফল আলাদা ভেক্টরে রাখা হয়।

ভেক্টর সাজানো হয় (sort), তাই k-তম বড় মান পেতে সুবিধা হয়।

k-এর তুলনায় লেভেল সংখ্যা কম হলে -1 রিটার্ন করার কারণে আউট অফ বাউন্ড সমস্যা হয় না।

তাই সব ধরণের টেস্ট কেস (ছোট ট্রি, বড় ট্রি, যেখানে k বেশি, যেখানে k ছোট) সঠিকভাবে কাজ করে।

সহজ ভাষায় ধারনা


  Full Code:
--------------

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
vector<long long>SUMBFS(TreeNode* root)
{
    vector<long long>v;
    if(!root) return v;
  queue<TreeNode*>q;
  q.push(root);

  long long sum=0;
  while(!q.empty())
  {
    int size=q.size();
    sum=0;
    for(int i=0;i<size;i++)
    {
    TreeNode* front=q.front();
    q.pop();
    sum+=front->val;
  
   
   if(front->left!=nullptr) q.push(front->left);
   if(front->right!=nullptr) q.push(front->right);
  }
   v.push_back(sum);
 
}
return v;
}
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
       vector<long long>vv=SUMBFS(root);
       sort(vv.begin(),vv.end());
       vector<int>v;
       long long ans=-1;
       if (k > (int)vv.size()) return ans;
   
     ans=vv[vv.size()-k];
   
       return ans;
    }
};

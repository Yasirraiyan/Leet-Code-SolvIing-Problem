Problem Summary (সংক্ষেপে সমস্যা)
তোমাকে একটা বাইনারি ট্রি (binary tree) দেওয়া আছে। ট্রির প্রতিটি লেভেল (বা রো) থেকে সবচেয়ে বড় ভ্যালু গুলো বের করে একটা অ্যারে হিসেবে দিতে হবে।

উদাহরণ:

ইনপুট: [1,3,2,5,3,null,9]

আউটপুট: [1,3,9]
কারণ:

Level 0: শুধু ১ আছে → max = 1

Level 1: ৩ এবং ২ আছে → max = 3

Level 2: ৫, ৩, null, ৯ আছে → max = 9

Solution Approach - কী ভাবতে হবে?
১. Level-order traversal (বা Breadth First Search - BFS) প্রয়োগ করবো।
২. প্রতি লেভেলে ট্রির সকল নোড ভ্যালু গুলো নিয়ে তাদের মধ্যে সবচেয়ে বড় ভ্যালু খুঁজে নিবো।
৩. সেই সবচেয়ে বড় ভ্যালুগুলো একটা ভেক্টরে (list) রেখে দিবো।
৪. সব লেভেল শেষে সেই লিস্ট রিটার্ন করবো।

Code Explanation (কোড লাইন বাই লাইন)
cpp
Copy
Edit
class Solution {
public:
    // একটা সহায়ক ফাংশন, যা একটি vector থেকে সবচেয়ে বড় মান বের করবে
    int findlargest(vector<int>&v) {
        int max = v[0];
        for(int i = 1; i < v.size(); i++) {
            if(v[i] > max) {
                max = v[i];
            }
        }
        return max;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> v;      // প্রতি লেভেলের নোড ভ্যালুগুলো রাখার জন্য
        queue<TreeNode*> q; // BFS এর জন্য কিউ

        vector<int> vv;     // শেষের রেজাল্ট রাখবে

        if(root == nullptr) return vv;  // যদি ট্রি খালি হয়, ফাঁকা ভেক্টর রিটার্ন করো

        q.push(root);  // প্রথমে রুট নোড কিউতে ঢোকাও

        // কিউ খালি না হওয়া পর্যন্ত লুপ চালাবে
        while(!q.empty()) {
            int size = q.size();  // এই লেভেলে কয়টা নোড আছে

            v.clear();  // পূর্বের লেভেলের ভ্যালু মুছে ফেলো

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front(); // কিউ থেকে সামনের নোড নাও
                q.pop();

                v.push_back(front->val);    // সেই নোডের মান v তে যোগ করো

                // লেফট চাইল্ড থাকলে কিউতে ঢোকাও
                if(front->left != nullptr) q.push(front->left);

                // রাইট চাইল্ড থাকলে কিউতে ঢোকাও
                if(front->right != nullptr) q.push(front->right);
            }
            
            // প্রতি লেভেল শেষে ঐ লেভেলের max ভ্যালু vv তে যোগ করো
            vv.push_back(findlargest(v));
        }

        return vv;  // সব লেভেলের max ভ্যালু রিটার্ন করো
    }
};
কেন এটা accepted হয়?
BFS লেভেল-বাই-লেভেল traversal আমাদের প্রত্যেক লেভেলের সব নোড একসাথে প্রোসেস করতে দেয়।

লেভেলের সব নোড ভ্যালু ভেক্টরে জমা হয়।

একটা ছোট ফাংশন findlargest() দিয়ে সেই লেভেলের সর্বোচ্চ মান বের করা হয়।

তারপর প্রতিটি লেভেলের max মান vv তে push_back করা হয়।

শেষে এই vv রিটার্ন করলেই চলে।

Example Test Case দিয়ে ব্যাখ্যা (Line by Line):
Input: [1,3,2,5,3,null,9]

প্রথমে root = 1, q = {1}

while loop starts:

size = 1, v.clear()

pop 1 from q, v = {1}

push left child 3, right child 2 into q → q = {3, 2}

findlargest({1}) → 1

vv = {1}

size = 2, v.clear()

pop 3 from q, v = {3}

push 3 (left child of 3), 5 (right child of 3) into q → q = {2, 5, 3}

pop 2 from q, v = {3, 2}

push right child 9 of 2 into q → q = {5, 3, 9}

findlargest({3, 2}) → 3

vv = {1, 3}

size = 3, v.clear()

pop 5 from q, v = {5} (no children)

pop 3 from q, v = {5, 3} (no children)

pop 9 from q, v = {5, 3, 9} (no children)

q is empty now

findlargest({5, 3, 9}) → 9

vv = {1, 3, 9}

Loop ends because q is empty.

Return vv = {1, 3, 9}.

তোমার ভাবনার জন্য:
প্রথমে বুঝো তোমার কিউতে কোন নোডগুলো আছে।

একবারে একটি লেভেল ধরে নাও (queue.size())

ঐ লেভেলের সব নোডের ভ্যালু নাও, তাদের মধ্যে সবচেয়ে বড় খুঁজে বের করো

পরের লেভেলের জন্য তাদের চাইল্ড গুলো কিউতে ঢোকাও

এই প্রক্রিয়া শেষ হওয়া পর্যন্ত চালিয়ে যাও।

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
 int findlargest(vector<int>&v)
 {
  int max=v[0];
  for(int i=1;i<v.size();i++)
  {
    if(v[i]>max)
    {
      max=v[i];
    }
  }
  return max;
 }
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>vv;
        if(root==nullptr) return vv;
        while(!q.empty())
        {
          int size=q.size();
         v.clear();
           for(int i=0;i<size;i++)
           {
          
                 TreeNode* front=q.front();
                 q.pop();
                 v.push_back(front->val);
                 
               if(front->left!=nullptr) q.push(front->left);
                if(front->right!=nullptr) q.push(front->right);
           }
           vv.push_back(findlargest(v));
          
         
         

        }
        
        
       //   v.clear();
        
        return vv;
    }
};

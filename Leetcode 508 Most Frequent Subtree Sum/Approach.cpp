সমস্যা (Problem) সংক্ষেপে
তোমার কাছে একটি বাইনারি ট্রি আছে (TreeNode *root)।

প্রতিটি নোডের একটি সাবট্রি থাকে (তার নিজেই এবং তার সব চাইল্ড নোড)।

সাবট্রি সামের মান = সেই সাবট্রির সব নোডের মান যোগফল।

তোমাকে সেই সাবট্রি সামের মধ্যে সবচেয়ে বেশি বার আসা মানগুলো বের করতে হবে।

যদি অনেকগুলো মান একই ফ্রিকোয়েন্সি থাকে (টাই থাকে), তাহলে সবগুলো রিটার্ন করতে হবে।

কোডের মূল ধারণা (Approach):
Recursive Tree Traversal করে প্রতিটি নোডের সাবট্রি সাম বের করা।

সেই সব সাবট্রি সামের ভেক্টরে সেভ করা।

তারপর ওই ভেক্টরের সব মানের ফ্রিকোয়েন্সি বের করা (frequency map)।

সর্বোচ্চ ফ্রিকোয়েন্সি বের করা।

যেসব মান ওই সর্বোচ্চ ফ্রিকোয়েন্সি পেয়েছে, সেগুলো রিটার্ন করা।

ধাপে ধাপে ব্যাখ্যা
cpp
Copy
Edit
class Solution 
{
public:
    // 1. findSubtreeSum ফাংশন: প্রতিটি নোডে সাবট্রি সাম বের করবে এবং v ভেক্টরে সেভ করবে
    int findSubtreeSum(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr) return 0;  // যদি নোড না থাকে, মান ০

        // রিকার্সিভলি বাম সাবট্রি সাম বের করো
        int leftsum = findSubtreeSum(root->left, v);

        // রিকার্সিভলি ডান সাবট্রি সাম বের করো
        int rightsum = findSubtreeSum(root->right, v);

        // নিজের মান + বাম + ডান যোগফল = সাবট্রি সাম
        int sum = root->val + leftsum + rightsum;

        // এই সাবট্রি সামকে ভেক্টরে পুশ করো (ভবিষ্যতে frequency গণনা করার জন্য)
        v.push_back(sum);

        // সাবট্রি সাম রিটার্ন করো, যাতে প্যারেন্ট নোড ব্যবহার করতে পারে
        return sum;
    }

    // 2. findmax ফাংশন: একটি ভেক্টরের মধ্যে সবচেয়ে বড় মান খুঁজে বের করবে
    int findmax(vector<int>& v)
    {
        int max = v[0];
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j] > max)
            {
                max = v[j];
            }
        }
        return max;
    }

    // 3. মূল ফাংশন যা চাহিদামতো ফলাফল রিটার্ন করবে
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        vector<int> v;
        // সাবট্রি সবার সমূহ খুঁজে ভেক্টরে রাখো
        findSubtreeSum(root, v);

        unordered_map<int, int> freq;  // মানের frequency রেকর্ড রাখবে

        // ভেক্টরের সব সাবট্রি সামের frequency গণনা করো
        for (int i = 0; i < v.size(); i++)
        {
            freq[v[i]]++;
        }

        vector<int> vv;  // frequency গুলো সংগ্রহ করার জন্য

        // map থেকে frequency গুলো vv তে পুশ করো
        for (auto it : freq)
        {
            vv.push_back(it.second);
        }

        // সবচেয়ে বড় frequency খুঁজে বের করো
        int maxf = findmax(vv);

        vector<int> ans;  // শেষ ফলাফল রাখার জন্য

        // যেসব মানের frequency maxf এর সমান, সেগুলো ans এ রাখো
        for (auto it : freq)
        {
            if (it.second == maxf)
            {
                ans.push_back(it.first);
            }
        }

        // ans রিটার্ন করো
        return ans;
    }
};
তুমি কীভাবে ভাববে কোড লেখার সময়? (Stepwise Thought Process)
প্রশ্ন পড়ে বুঝতে হবে — “সাবট্রি সুম” কী?

একটা নোড নিয়ে তার নিচের সব নোডের মান যোগ করতেই সাবট্রি সুম।

এই সাবট্রি সুম প্রতিটি নোডের জন্য আলাদা হবে।

তাই ট্রি ট্রাভার্সাল (postorder) করব, কারণ সাবট্রি সুম বের করতে বাম ও ডান সাবট্রি আগে দরকার।

সাবট্রি সুম বের করলে সেগুলো কোথায় রাখব?

সবগুলো সুম এক জায়গায় রাখতে হবে, তাই ভেক্টর ব্যবহার।

এরপর সেই ভেক্টর থেকে frequency বের করতে হবে।

frequency বের করতে মাপ ব্যবহার করব।

frequency গুলো থেকে সবচেয়ে বেশি বার আসা মান গুলো বের করব।

শেষে সেই মানগুলো রিটার্ন করব।

কিভাবে টেস্ট কেস একসেপ্ট হয়?
Test case 1: root = [5,2,-3]

সাবট্রি সুম:

নোড 2 এর সাবট্রি সুম = 2

নোড -3 এর সাবট্রি সুম = -3

রুট 5 এর সাবট্রি সুম = 5 + 2 + (-3) = 4

frequency: 2=1, -3=1, 4=1 (সব একই ফ্রিকোয়েন্সি)

তাই সবগুলো ফলাফল [2, -3, 4] রিটার্ন হয়।

Test case 2: root = [5,2,-5]

সাবট্রি সুম:

2 এর সাবট্রি সুম = 2

-5 এর সাবট্রি সুম = -5

5 এর সাবট্রি সুম = 5 + 2 + (-5) = 2

frequency: 2=2, -5=1

সর্বোচ্চ frequency = 2 (সর্বোচ্চ বার ২ এসেছে 2 মানটি)

তাই ফলাফল = [2]

সারসংক্ষেপ
প্রথমে ট্রি রিকার্সিভলি ট্রাভার্স করে সাবট্রি সুম বের করো।

সব সাবট্রি সুম একটি ভেক্টরে রাখো।

ভেক্টর থেকে frequency গুলো বের করো।

সর্বোচ্চ frequency যেগুলো পেয়েছে, সেগুলো ans এ পুশ করো।

ans রিটার্ন করো।


Full Code:
---------------

  class Solution 
{
public:
int findSubtreeSum(TreeNode* root,vector<int>&v)
 {
  if(root==nullptr) return 0;
  int leftsum=findSubtreeSum(root->left,v);
  int rightsum=findSubtreeSum(root->right,v);
  int sum=root->val+leftsum+rightsum;
  v.push_back(sum);
  return sum;
 }
 int findmax(vector<int>&v)
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
    vector<int> findFrequentTreeSum(TreeNode* root)
     {
        vector<int>v;
        findSubtreeSum(root,v);
        unordered_map<int,int>freq;
        for(int i=0;i<v.size();i++)
        {
          freq[v[i]]++;
        }
        vector<int>vv;
        for(auto it:freq)
        {
          vv.push_back(it.second);
        }
        int maxf=findmax(vv);
        vector<int>ans;
        for(auto it:freq)
        {
          if(it.second==maxf)
          {
            ans.push_back(it.first);
          }
        }
        return ans;
    }
};

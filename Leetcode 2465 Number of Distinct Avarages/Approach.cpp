প্রথমে প্রশ্ন পড়ে চিন্তার ধাপ

প্রশ্নটা বলছে:

আমাদের কাছে একটা even length array nums আছে।

যতক্ষণ পর্যন্ত array খালি না হয়, ততক্ষণ করতে হবে:

1. min বের করে remove করো


2. max বের করে remove করো


3. (min + max) / 2 → এই average রাখো



শেষে কতগুলো ভিন্ন ভিন্ন average হয়েছে সেটা return করতে হবে।



---

চিন্তার ধাপ

1. প্রশ্নে যেটা ঘটছে

প্রতিবার দুইটা element বাদ যাচ্ছে → একদম smallest আর largest।

ওই দুইটার average আমরা হিসাব করবো।

একই average একাধিকবার হতে পারে, কিন্তু distinct গুনতে হবে।



2. সম্ভাব্য সমাধান চিন্তা

Step 1: বারবার min এবং max বের করা।

Step 2: ওই দুটো array থেকে remove করা।

Step 3: average হিসাব করে একটা list/set-এ রাখা।

Step 4: শেষে unique count বের করা।



3. Data Structure ভাবনা

Set দিলে সরাসরি unique count পাওয়া যেতো।

তুমি এখানে vector + unordered_map দিয়ে unique বের করেছো।

এটা valid এবং accepted হবে কারণ complexity manageable।



4. Time Complexity

প্রতিবার min & max বের করা O(n) এবং remove করাও O(n) → মোট O(n^2)

ছোট array হলে ঠিক আছে (LeetCode constraints অনুযায়ী acceptable)।





---

এখন কোড লাইন-বাই-লাইন ব্যাখ্যা

class Solution 
{
public:
    int findmax(vector<int>&v)
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

এখানে findmax ফাংশন: vector-এর মধ্যে সবচেয়ে বড় element বের করছে।

শুরুতে max হিসাবে প্রথম element নিলাম।

লুপ দিয়ে compare করে বড় হলে update করলাম।

গাণিতিকভাবে:




---

int findmin(vector<int>&v)
    {
        int min=v[0];
        for(int j=1;j<v.size();j++)
            {
                if(v[j]<min)
                {
                    min=v[j];
                }
            }
        return min;
    }

একইভাবে findmin ফাংশন: সবচেয়ে ছোট element বের করছে।

গাণিতিকভাবে:




---

double findavg(vector<int>&v)
    {
        int min=findmin(v);
        int max=findmax(v);
        double avg=(min+max)/2.0;
        return avg;
    }

এই ফাংশন findmin ও findmax ডেকে average বের করছে।

গাণিতিকভাবে:

এখানে /2.0 তাই decimal (double) result আসবে।



---

int distinctAverages(vector<int>& nums)
    {
        vector<double>vv;
        int n=nums.size();
         while(!nums.empty())
             {
                 int min=findmin(nums);
                 int max=findmax(nums);
                 double avg=(min+max)/2.0;
                 vv.push_back(avg);
                 nums.erase(std::find(nums.begin(),nums.end(),min));
                 nums.erase(std::find(nums.begin(),nums.end(),max));
             }

এখানে মূল logic:

যতক্ষণ nums খালি না হয়:

1. min বের করা


2. max বের করা


3. average বের করে vv তে push করা


4. erase দিয়ে min এবং max nums থেকে মুছে ফেলা (প্রথম occurrence)




প্রতিবার দুইটা element বাদ যাচ্ছে, তাই loop চলবে n/2 বার।



---

unordered_map<double,int>freq;
        for(int k=0;k<vv.size();k++)
            {
                freq[vv[k]]++;
            }

এখানে frequency map বানানো হচ্ছে, যাতে duplicate গোনা না হয়।

key = average value, value = কতবার হয়েছে।



---

vector<double>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }

map থেকে শুধু unique average গুলো বের করে vector v তে রাখা হচ্ছে।



---

int ans=v.size();
        return ans;
    }
};

শেষে unique average count return করা হচ্ছে।



---

Test Case উদাহরণ

Example 1:
nums = [4,1,4,0,3,5]

Step-by-step:

1. min=0, max=5 → avg=(0+5)/2=2.5
nums=[4,1,4,3]


2. min=1, max=4 → avg=(1+4)/2=2.5
nums=[4,3]


3. min=3, max=4 → avg=(3+4)/2=3.5
nums=[]



vv = [2.5, 2.5, 3.5] → unique = {2.5, 3.5} → উত্তর = 2 ✅


---

Example 2:
nums = [1,100]

min=1, max=100 → avg=50.5

unique count = 1 ✅



---

কেন কোড Accepted হবে

Problem-এর logic পুরোপুরি implement করা হয়েছে।

Constraints অনুযায়ী O(n^2) ঠিক আছে কারণ n ছোট।

Floating point average double type-এ handle করা হয়েছে।

Duplicate average গুলো filter করা হয়েছে map দিয়ে।



---
Full Code:
------------

class Solution 
{
public:
    int findmax(vector<int>&v)
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
    int findmin(vector<int>&v)
    {
        int min=v[0];
        for(int j=1;j<v.size();j++)
            {
                if(v[j]<min)
                {
                    min=v[j];
                }
            }
        return min;
    }
    double findavg(vector<int>&v)
    {
        int min=findmin(v);
        int max=findmax(v);
        double avg=(min+max)/2.0;
        return avg;
    }
    int distinctAverages(vector<int>& nums)
    {
        vector<double>vv;
        int n=nums.size();
         while(!nums.empty())
             {
                 int min=findmin(nums);
                 int max=findmax(nums);
                 double avg=(min+max)/2.0;
                 vv.push_back(avg);
                 nums.erase(std::find(nums.begin(),nums.end(),min));
                 nums.erase(std::find(nums.begin(),nums.end(),max));
             }
        unordered_map<double,int>freq;
        for(int k=0;k<vv.size();k++)
            {
                freq[vv[k]]++;
            }
        vector<double>v;
        for(auto it:freq)
            {
                v.push_back(it.first);
            }
        int ans=v.size();
        return ans;
    }
};

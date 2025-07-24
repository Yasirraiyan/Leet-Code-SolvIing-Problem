🔶 প্রবলেমটি বুঝি:

তিনটি সংখ্যা দেওয়া আছে nums array তে। এগুলোর দ্বারা কোনো ত্রিভুজ (triangle) গঠন করা যাবে কিনা — যদি যায় তাহলে সেটা equilateral, isosceles, না scalene — সেটা return করতে হবে।


---

🔷 Triangle গঠন করার শর্ত (Triangle Inequality):

তিনটি পার্শ্ব a, b, c দ্বারা একটি ত্রিভুজ গঠিত হতে হলে, নিচের শর্তগুলো পূরণ করতে হবে:

a + b > c
b + c > a
c + a > b

যেকোনো দুই পার্শ্বের যোগফল তৃতীয় পার্শ্বের চেয়ে বড় হতে হবে।


---

🔷 Triangle এর প্রকারভেদ:

1. Equilateral (সমবাহু): তিনটি পার্শ্বই সমান।


2. Isosceles (সমদ্বিবাহু): ঠিক দুইটি পার্শ্ব সমান।


3. Scalene (বিষমবাহু): সব পার্শ্ব ভিন্ন।




---

✅ প্রবলেম সলভ করার ধাপসমূহ (Approach):

1. ✅ প্রথমে চেক করব তিনটি সংখ্যা দ্বারা কোনো triangle গঠন করা যায় কিনা (triangle inequality check)।


2. ❌ যদি না যায়, তাহলে সরাসরি return করব "none"।


3. ✅ যদি যায়, তাহলে frequency check করব — কয়টি সংখ্যা সমান।

যদি তিনটিই সমান হয় → "equilateral"

যদি দুইটি সমান হয় → "isosceles"

যদি সব আলাদা হয় → "scalene"





---

🔠 এখন কোডের লাইনে লাইনে ব্যাখ্যা করি:

class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_map<int,int>freq;
        string ans="";

🔸 আমরা frequency count করার জন্য unordered_map<int, int> freq নিচ্ছি, যেখানে সংখ্যা কয়বার এসেছে সেটা গণনা হবে।
🔸 ans স্টোর করবে ফাইনাল উত্তর।


---

for(int i=0;i<nums.size();i++) {
            freq[nums[i]]++;
        }

🔸 তিনটি সংখ্যার frequency গণনা করছি — যদি কোনো সংখ্যা ৩ বার থাকে → সমবাহু, ২ বার → সমদ্বিবাহু।


---

int a=nums[0];
        int b=nums[1];
        int c=nums[2];

        if(a+b<=c||b+c<=a||c+a<=b) {
            return "none";
        }

🔸 Triangle Inequality Check করলাম। যদি ত্রিভুজ গঠনই না করে তাহলে সরাসরি return "none"।


---

bool three=false;
        bool two=false;
        for(int j=0;j<nums.size();j++) {
            if(freq[nums[j]]==3) {
                three=true;
            }
            else if(freq[nums[j]]==2) {
                two=true;
            }
        }

🔸 এখন আমরা frequency দেখে সিদ্ধান্ত নিচ্ছি:

৩ বার → সমবাহু

২ বার → সমদ্বিবাহু



---

if(three) {
            ans= "equilateral";
        }
        else if(two) {
            ans= "isosceles";
        }
        else {
            ans="scalene";
        }
        return ans;

🔸 এবার আমরা three, two ভেরিয়েবল দেখে উত্তর set করছি এবং return করছি।


---

📌 উদাহরণ দিয়ে ব্যাখ্যা:

➤ Test case: nums = [3,3,3]

1. 3 + 3 > 3, সব তিনটি শর্ত পূর্ণ, তাই Triangle গঠন হয় ✅


2. তিনটি সংখ্যার frequency → 3: 3 বার


3. তিনটি সংখ্যা সমান → Return: "equilateral"




---

➤ Test case: nums = [3,4,5]

1. 3 + 4 = 7 > 5, 4 + 5 = 9 > 3, 5 + 3 = 8 > 4 ✅


2. তিনটি সংখ্যা ভিন্ন → Return: "scalene"




---

➤ Test case: nums = [1,2,3]

1. 1 + 2 = 3 <= 3 ❌ Triangle inequality fail → Return: "none"




---

✅ এই কোড Accepted কেন?

সঠিকভাবে triangle inequality check করছে।

তারপরে frequency count করে সঠিকভাবে Triangle এর type চিহ্নিত করছে।

সব condition cover করা হয়েছে।

Time Complexity: O(1) (কারণ input সবসময় 3 elements)

Space Complexity: O(1)

Full Code:
-------------

class Solution
{
public:
    string triangleType(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
        string ans="";
        for(int i=0;i<nums.size();i++)
            {
                freq[nums[i]]++;
            }
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a+b<=c||b+c<=a||c+a<=b)
        {
            return "none";
            //return ans;
        }
        bool three=false;
        bool two=false;
        for(int j=0;j<nums.size();j++)
            {
                if(freq[nums[j]]==3)
                {
                   /* ans=*///return "equilateral";
                    three=true;
                }
                else if(freq[nums[j]]==2)
                {
                    /*ans=*///return "isosceles";
                    two=true;
                }
            }
        if(three) 
        {
            ans= "equilateral";
        }
       else if(two) 
       {
           ans= "isosceles";
       }
        else 
       {
           ans="scalene";
       }
            return ans;
    }
    
};

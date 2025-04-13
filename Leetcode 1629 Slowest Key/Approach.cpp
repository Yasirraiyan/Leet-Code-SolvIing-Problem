প্রব্লেম বর্ণনা:
একটি নতুন কী-প্যাড টেস্ট করা হচ্ছে। একজন টেস্টার n সংখ্যক কী টিপে, একবারে একটি করে। আপনাকে দুটি জিনিস দেওয়া হবে:

keysPressed: একটি স্ট্রিং যার দৈর্ঘ্য n, যেখানে keysPressed[i] হলো i-তম প্রেস করা কী।

releaseTimes: একটি সর্টেড লিস্ট, যেখানে releaseTimes[i] হলো i-তম কী রিলিজ হওয়ার সময়।

প্রথম কী (0-তম ইনডেক্সে) টিপা হয় সময় 0-এ, এবং প্রতিটি পরবর্তী কী ঠিক আগের কী রিলিজ হওয়ার সময়ে প্রেস করা হয়।

আমাদের বের করতে হবে কোন কী প্রেসের ডিউরেশন (duration) সবচেয়ে বেশি ছিল। i-তম কী প্রেসের ডিউরেশন হলো releaseTimes[i] - releaseTimes[i - 1] (এবং 0-তম কী প্রেসের ডিউরেশন হলো releaseTimes[0] - 0)।

যদি একাধিক কী প্রেস একই সর্বোচ্চ ডিউরেশন থাকে, তাহলে lexicographical order-এ (অর্থাৎ ডিকশনারি অর্ডারে) বড় কীটি রিটার্ন করতে হবে।

উদাহরণ ১:
releaseTimes = [9, 29, 49, 50]

keysPressed = "cbcd"

ব্যাখ্যা:

'c' প্রেসের ডিউরেশন = 9 - 0 = 9

'b' প্রেসের ডিউরেশন = 29 - 9 = 20

'c' প্রেসের ডিউরেশন = 49 - 29 = 20

'd' প্রেসের ডিউরেশন = 50 - 49 = 1

এখানে সবচেয়ে বেশি ডিউরেশন হলো 20 ('b' এবং 'c' দুটোরই)। কিন্তু lexicographical order-এ 'c' > 'b', তাই উত্তর 'c'।

সমাধানের ধারণা:
প্রতিটি কী প্রেসের ডিউরেশন বের করা:

প্রথম কী (i=0) এর ডিউরেশন = releaseTimes[0] - 0

বাকি কীগুলোর জন্য (i > 0), ডিউরেশন = releaseTimes[i] - releaseTimes[i - 1]

সর্বোচ্চ ডিউরেশন খুঁজে বের করা:

সব ডিউরেশন এর মধ্যে সবচেয়ে বড় মানটি বের করতে হবে।

সর্বোচ্চ ডিউরেশন যুক্ত কী গুলো থেকে lexicographical order-এ বড় কীটি নির্বাচন করা:

যদি একাধিক কী একই সর্বোচ্চ ডিউরেশন পায়, তাহলে তাদের মধ্যে ডিকশনারি অর্ডারে বড় কীটি নিতে হবে।

কোড বিশ্লেষণ (Bangla):
cpp
Copy
class Solution {
public:
    int findmax(vector<int>& arr) {
        int max = arr[0];
        for(int m = 1; m < arr.size(); m++) {
            if(arr[m] > max) {
                max = arr[m];
            }
        }
        return max;
    }
    
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> reserve; // এই ভেক্টরে প্রতিটি কী প্রেসের ডিউরেশন স্টোর করা হবে
        char maxKey = '\0'; // সর্বোচ্চ ডিউরেশন যুক্ত কী স্টোর করার জন্য
        
        // 1. প্রতিটি কী প্রেসের ডিউরেশন বের করে reserve ভেক্টরে স্টোর করা
        for(int i = 0; i < releaseTimes.size(); i++) {
            if(i == 0) {
                reserve.push_back(releaseTimes[0]);
            } else {
                reserve.push_back(releaseTimes[i] - releaseTimes[i - 1]);
            }
        }
        
        // 2. সব ডিউরেশন এর মধ্যে সর্বোচ্চ মান বের করা
        int maxtime = findmax(reserve);
        
        // 3. সর্বোচ্চ ডিউরেশন যুক্ত কী গুলো থেকে lexicographical order-এ বড় কীটি নেওয়া
        for(int m = 0; m < reserve.size(); m++) {
            if(reserve[m] == maxtime) {
                // maxKey এবং keysPressed[m] এর মধ্যে বড়টি maxKey-এ অ্যাসাইন করা হয়
                maxKey = max(maxKey, keysPressed[m]);
            }
        }
        
        return maxKey;
    }
};
কোডের ধাপগুলো:
reserve ভেক্টরে প্রতিটি কী প্রেসের ডিউরেশন স্টোর করা হয়।

findmax() ফাংশন দিয়ে reserve ভেক্টরের সর্বোচ্চ মান বের করা হয় (maxtime)।

যে সব কী প্রেসের ডিউরেশন maxtime এর সমান, তাদের মধ্যে lexicographical order-এ বড় কীটি maxKey-এ স্টোর করা হয়।

সর্বশেষে maxKey রিটার্ন করা হয়।

উদাহরণ ১ এর জন্য কোড রান:
reserve = [9, 20, 20, 1]

maxtime = 20

maxKey প্রথমে '\0', তারপর 'b' (20 পেয়ে), তারপর 'c' (আরেক 20 পেয়ে, এবং 'c' > 'b')।

শেষ পর্যন্ত maxKey = 'c' রিটার্ন হয়।

Time Complexity:
ডিউরেশন ক্যালকুলেশন: O(n)

সর্বোচ্চ মান খুঁজা: O(n)

সর্বোচ্চ ডিউরেশন যুক্ত কী খুঁজা: O(n)

মোট: O(n)

Space Complexity:
reserve ভেক্টর: O(n) স্পেস নেয়।

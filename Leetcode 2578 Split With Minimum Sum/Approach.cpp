সমাধান ব্যাখ্যা (Bangla):
এই সমস্যায় একটি ইতিবাচক পূর্ণসংখ্যা num দেওয়া আছে, এবং আমাদের এটি দুটি অ-নেগেটিভ পূর্ণসংখ্যা num1 এবং num2 তে বিভক্ত করতে হবে এমনভাবে যে:

num1 এবং num2 এর সংমিশ্রণটি num এর একটি পারমুটেশন হতে হবে।

এর মানে হল যে, num1 এবং num2-এর প্রতিটি অঙ্কের সংখ্যার যোগফল num এর প্রতিটি অঙ্কের সংখ্যা সমান হতে হবে।

num1 এবং num2 তে শূন্য থাকতে পারে, এবং তাদের মধ্যে অর্ডার পরিবর্তন হতে পারে।

আমাদের লক্ষ্য হল এমন দুটি সংখ্যা তৈরি করা, যাদের যোগফল সর্বনিম্ন হবে।

সমাধান পদ্ধতি:
সংখ্যাটি একক অঙ্কে বিভক্ত করা: প্রথমে, num সংখ্যাটি একক অঙ্কে বিভক্ত করা হয়। যেমন ধরুন, num = 4325, এর অঙ্কগুলো হবে [4, 3, 2, 5]।

অঙ্কগুলো সাজানো: num এর অঙ্কগুলোকে সর্ট (ascending order) করা হয়। এর ফলে, সংখ্যা কমপক্ষে সংখ্যাগুলি আলাদা করা যাবে। যেমন, [4, 3, 2, 5] কে সাজালে [2, 3, 4, 5] হবে।

অঙ্কগুলো ভাগ করা: সাজানো অঙ্কগুলোকে দুটি সংখ্যায় বিভক্ত করা হয়। সংখ্যাগুলি যতটা সম্ভব সমান করার জন্য, আমরা অঙ্কগুলোকে অনুক্রমে দুটি সংখ্যায় ভাগ করি।

num1 এবং num2 এ অঙ্কগুলো আলতোভাবে রাখা হয়। যেমন, [2, 3, 4, 5] এর মধ্যে [2, 4] যাবে num1 তে এবং [3, 5] যাবে num2 তে।

সংখ্যা তৈরি করা: দুটি সংখ্যা তৈরি করার জন্য, প্রতিটি সংখ্যা reserve1 এবং reserve2 থেকে একত্রিত করা হয়। এতে করে, আমরা num1 এবং num2 পাবো।

যোগফল বের করা: num1 এবং num2 এর যোগফল বের করে তা রিটার্ন করা হয়।

উদাহরণ:
ধরা যাক, ইনপুট num = 4325:

ধাপ 1: অঙ্কগুলো বের করা: [4, 3, 2, 5]

ধাপ 2: সাজানো অঙ্কগুলো: [2, 3, 4, 5]

ধাপ 3: অঙ্কগুলো ভাগ করা:

num1 পায় [2, 4]

num2 পায় [3, 5]

ধাপ 4: num1 = 24 এবং num2 = 35 হবে।

ধাপ 5: সমষ্টি হবে 24 + 35 = 59

অতএব, সর্বনিম্ন যোগফল হবে 59।

কোড বিশ্লেষণ (Bangla):
cpp
Copy
Edit
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        vector<int> ans; // num এর অঙ্কগুলো রাখার জন্য
        vector<int> reserve1; // num1 তৈরি করতে
        vector<int> reserve2; // num2 তৈরি করতে
        int sum1 = 0; // num1 এর মান
        int sum2 = 0; // num2 এর মান

        // ধাপ 1: num এর অঙ্কগুলো বের করা
        while (num > 0) {
            int rem = num % 10; // শেষ অঙ্ক বের করা
            ans.push_back(rem);  // ans ভেক্টরে অঙ্কটি রাখা
            num = num / 10;      // num থেকে শেষ অঙ্কটি বাদ দেওয়া
        }

        // ধাপ 2: অঙ্কগুলো সাজানো
        sort(ans.begin(), ans.end());

        // ধাপ 3: অঙ্কগুলো reserve1 এবং reserve2 তে ভাগ করা
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 0) {
                reserve1.push_back(ans[i]); // even index এর অঙ্ক num1 তে
            } else {
                reserve2.push_back(ans[i]); // odd index এর অঙ্ক num2 তে
            }
        }

        // ধাপ 4: reserve1 এবং reserve2 থেকে দুটি সংখ্যা তৈরি করা
        for (int j = 0; j < reserve1.size(); j++) {
            sum1 += reserve1[j] * pow(10, reserve1.size() - j - 1); // num1 তৈরি
        }
        for (int k = 0; k < reserve2.size(); k++) {
            sum2 += reserve2[k] * pow(10, reserve2.size() - k - 1); // num2 তৈরি
        }

        // ধাপ 5: num1 এবং num2 এর যোগফল রিটার্ন করা
        int result = sum1 + sum2;
        return result;
    }
};
কোড বিশ্লেষণ:
অঙ্ক বের করা:

num থেকে এক এক করে অঙ্ক বের করতে num % 10 ব্যবহার করা হয় এবং প্রতিটি অঙ্ক ans ভেক্টরে রাখা হয়।

এরপর num = num / 10 ব্যবহার করে সংখ্যাটি ছোট করা হয়।

অঙ্ক সাজানো:

sort(ans.begin(), ans.end()) ব্যবহার করে অঙ্কগুলোকে সাজানো হয়, যাতে ছোট অঙ্কগুলো প্রথমে আসে।

অঙ্ক ভাগ করা:

সাজানো অঙ্কগুলো reserve1 এবং reserve2 তে ভাগ করা হয়। এমনভাবে ভাগ করা হয় যে, প্রথম অঙ্ক num1 পায় এবং পরবর্তী অঙ্ক num2 পায়, এবং এই প্রক্রিয়া চলতে থাকে।

সংখ্যা তৈরি করা:

reserve1 এবং reserve2 থেকে সংখ্যাগুলো তৈরি করা হয়। প্রতিটি অঙ্ক তার উপযুক্ত স্থান মান অনুযায়ী যোগ করা হয়।

যোগফল রিটার্ন:

দুইটি সংখ্যা তৈরির পর, তাদের যোগফল রিটার্ন করা হয়।

সময় এবং স্থান জটিলতা:
সময় জটিলতা: অঙ্কগুলোর সাজানোর জন্য O(d log d) সময় লাগে, যেখানে d হলো অঙ্কের সংখ্যা। অন্যান্য অপারেশনগুলো O(d) সময় নেবে। তাই, মোট সময় জটিলতা হবে O(d log d)।

স্থান জটিলতা: আমরা ভেক্টর ব্যবহার করছি যাতে অঙ্কগুলি সংরক্ষণ করা যায়, তাই স্থান জটিলতা হবে O(d)।

উদাহরণ ব্যাখ্যা:
ধরা যাক, ইনপুট num = 4325:

অঙ্কগুলো: [4, 3, 2, 5]

সাজানো অঙ্ক: [2, 3, 4, 5]

ভাগ করা অঙ্ক:

num1 পায় [2, 4] -> num1 = 24

num2 পায় [3, 5] -> num2 = 35

যোগফল: 24 + 35 = 59

অতএব, সর্বনিম্ন যোগফল হবে 59।









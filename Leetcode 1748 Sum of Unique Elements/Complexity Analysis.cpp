Complexity Foir Approach2:
--------------------------
  তুমি এই কোডটি লিখেছো Leetcode এর সমস্যা "1748. Sum of Unique Elements" সমাধান করার জন্য। চল এখন ধাপে ধাপে বুঝে নেই এই কোডটা কীভাবে কাজ করে এবং কেন এটা সঠিক ও অপ্টিমাইজড সমাধান।

🧠 সমস্যা কী বলে?
তোমাকে একটা পূর্ণসংখ্যার array দেওয়া হবে nums নামে। তোমার কাজ হল সেই সব সংখ্যা যোগ করা যেগুলো array-তে ঠিক একবারই এসেছে।

উদাহরণ:
nums = [1,2,3,2]
এখানে 1 এবং 3 একবার এসেছে → তাদের যোগফল 1+3 = 4

✅ তোমার কোডের ব্যাখ্যা (বাংলায়):
cpp
Copy
Edit
unordered_map<int,int> freq;
👉 এটা একটি hash map বা dictionary তৈরি করে যেটা প্রতিটি সংখ্যার frequency (কতবার এসেছে) রাখবে।

cpp
Copy
Edit
for(int i = 0; i < nums.size(); i++) {
    freq[nums[i]]++;
}
👉 প্রতিটি সংখ্যার জন্য তার frequency map-এ 1 করে বাড়াচ্ছে।
উদাহরণস্বরূপ:
nums = [1,2,3,2] হলে:
freq হবে → {1:1, 2:2, 3:1}

cpp
Copy
Edit
int sum = 0;
for(auto it : freq) {
    if(it.second == 1) {
        sum += it.first;
    }
}
👉 এখন freq map-এর প্রতিটি element-এ লুপ চালিয়ে দেখা হচ্ছে, যে সংখ্যার frequency 1 মানে ঠিক একবার এসেছে, তাদের sum এ যোগ করছে।

🎯 Output:
সেই সব সংখ্যা যেগুলো একবার এসেছে, তাদের যোগফল return করা হচ্ছে।

⏱️ কমপ্লেক্সিটি বিশ্লেষণ:
Time Complexity: O(n)
কারণ তুমি শুধু দুইটা লুপ চালিয়েছো → একবার input array-তে, আরেকবার map-এ।

Space Complexity: O(n)
কারণ frequency map এ সর্বোচ্চ n টি unique সংখ্যা রাখতে হতে পারে।

🔚 সারসংক্ষেপে:
তুমি unordered_map ব্যবহার করে প্রতিটি সংখ্যার গুনতি করেছো।

যেগুলো একবার এসেছে শুধু সেগুলোকেই যোগফলে নিয়েছো।

এটা একদম অপ্টিমাইজড এবং Accepted solution।

Complexity For Approach1:
------------------------------
  তোমার দেওয়া এই কোডটি একটি brute-force পদ্ধতিতে সমাধান করেছে, এবং এতে nested loop ব্যবহার করা হয়েছে। এখন আমরা এর Time Complexity এবং Space Complexity বিশ্লেষণ করি:

✅ Code Summary:
তুমি প্রতিটি সংখ্যার জন্য অন্য একটি লুপ চালিয়ে দেখছো সেই সংখ্যা array-তে ঠিক কতবার এসেছে। যদি exactly একবার পাও, তাহলে সেটি যোগফলে যোগ করছো এবং ans vector-এ রাখছো।

⏱️ Time Complexity:
cpp
Copy
Edit
for(int i=0; i<nums.size(); i++) {
    for(int j=0; j<nums.size(); j++) {
        if(nums[i] == nums[j]) {
            count++;
        }
    }
}
এখানে দুইটি nested loop → প্রতিটির দৈর্ঘ্য n হলে, মোট কম্পিউটেশন হবে:

✅ Time Complexity = O(n²)

উদাহরণ: যদি nums এর size হয় 1000, তাহলে 1000x1000 = 10^6 বার comparison হবে।

💾 Space Complexity:
std::vector<int> ans → worst case-এ n সংখ্যাই একবার করে আসতে পারে → O(n)

sum, count → primitive variables → O(1)

✅ Space Complexity = O(n)

📌 Final Complexity:
✅ Time Complexity: O(n²)

✅ Space Complexity: O(n)

🔁 Optimization Suggestion:
এই কোডটি ছোট ইনপুটের জন্য ঠিক আছে, কিন্তু বড় ইনপুটে ধীর হবে। আগের মতো unordered_map ব্যবহার করলে তুমি কোডটিকে O(n) টাইমে অপ্টিমাইজ করতে পারো।

তুমি কি চাও আমি দুটো কোডের পারফরমেন্স পার্থক্য graph/chart দিয়ে দেখাই?









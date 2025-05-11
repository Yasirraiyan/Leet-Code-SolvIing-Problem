অসাধারণ! তুমি নিজে নিজে আবারও একটা সুন্দর সলিউশন তৈরি করেছো — এবং এটা Accepted হওয়াটাই প্রমাণ করে যে তোমার চিন্তা ধারা একদম সঠিক পথে এগোচ্ছে। এখন চল তোমার কোডের প্রতিটা অংশ ব্যাখ্যা করি বাংলায়, সাথে সব টেস্ট কেস বিশ্লেষণ করে দেখাই কেনো এটা Accepted হয়েছে।

✅ Problem Summary (Bangla):
তোমাকে একটা nums নামের অ্যারে দেওয়া হয়েছে, যেখানে প্রতিটি সংখ্যা একবার অথবা দুইবার আছে।

🔸 তোমার কাজ: যেসব সংখ্যা ঠিক দুইবার আছে, তাদের bitwise XOR বের করে রিটার্ন করো।

✅ তুমি যেভাবে চিন্তা করেছো (Approach):
cpp
Copy
Edit
unordered_map<int,int> freq; // প্রতিটি সংখ্যার frequency রাখার জন্য
int sum = 0;
🔹 তুমি frequency বের করার জন্য unordered_map ব্যবহার করেছো।
🔹 এরপর যে সংখ্যাগুলা ঠিক ২ বার এসেছে, সেগুলোর উপর XOR অপারেশন চালিয়ে sum এ রাখছো।

✅ তোমার মূল কোড ব্যাখ্যা (Bangla):
cpp
Copy
Edit
for(int i = 0; i < nums.size(); i++) {
    freq[nums[i]]++;
}
🔸 এখানে তুমি প্রতিটি সংখ্যার কয়বার এসেছে সেটা গুনে রাখছো।

cpp
Copy
Edit
for(auto it : freq) {
    if(it.second == 2) {
        sum ^= it.first;  // যেটা ২ বার এসেছে সেটা sum এ XOR করছো
    }
}
🔸 যদি frequency ২ হয়, তাহলে সেই সংখ্যাটিকে sum এর সাথে XOR করা হচ্ছে।

cpp
Copy
Edit
return sum;
🔸 শেষে সেই XOR ফলাফল রিটার্ন করা হচ্ছে।

✅ টেস্ট কেস বিশ্লেষণ করে দেখা যাক
🔹 Test Case 1:
Input: [1, 2, 1, 3]
freq:

1 → 2

2 → 1

3 → 1

Repeated: 1
➡️ XOR = 1

✅ Output: 1 ✔️

🔹 Test Case 2:
Input: [1, 2, 3]
freq:

1 → 1

2 → 1

3 → 1

❌ No number appears twice
➡️ XOR = 0

✅ Output: 0 ✔️

🔹 Test Case 3:
Input: [1, 2, 2, 1]
freq:

1 → 2

2 → 2

Repeated: 1, 2
➡️ 1 ^ 2 = 3

✅ Output: 3 ✔️

✅ কেনো তোমার সলিউশন Accepted হয়েছে:
দিক	বিশ্লেষণ
✅ Logic	Frequency count + XOR অপারেশন সঠিক
✅ Time Complexity	O(n) — efficient for 1 <= n <= 500
✅ Edge Case Handled	No duplicates → return 0
✅ Memory	map-এর জন্য O(n) space

✅ Summary (Bangla Recap):
তুমি frequency map দিয়ে নির্ভুলভাবে ২ বার আসা সংখ্যাগুলো বের করেছো।

XOR অপারেশন দিয়ে সঠিকভাবে সব repeated সংখ্যাকে মিলিয়েছো।

তোমার কোড সব edge cases ঠিকমতো হ্যান্ডেল করে।

তুমি এইটা একদম নিজের চিন্তাভাবনায় তৈরি করেছো — এটা বড় গর্বের বিষয়।


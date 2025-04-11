 বিশ্লেষণ (Bangla):
🔁 Time Complexity বিশ্লেষণ (Recurrence Relation দিয়ে):
তোমার ফাংশনে getmax() প্রতি লুপে কল হচ্ছে, এবং getmax() নিজে O(n):

text
Copy
Edit
T(n) = n * O(n) = O(n²)
বা recurrence relation দিয়ে লিখলে:

r
Copy
Edit
T(n) = T(n - 1) + n, কারণ প্রতি ধাপে পুরো array তে getmax চালায়
এটা summation এর মতো:

r
Copy
Edit
T(n) = n + (n - 1) + (n - 2) + ... + 1 = n(n+1)/2 = O(n²)
💾 Space Complexity বিশ্লেষণ:
আমরা ans নামের একটি নতুন vector তৈরি করেছি, যার সাইজ হবে n।

তাই Space = O(n)

✅ Summary:
Aspect	Value	ব্যাখ্যা (Bangla)
Time Complexity	O(n²)	কারণ প্রতি আইটেমের জন্য আবার পুরো ভেক্টর স্ক্যান
Space Complexity	O(n)	কারণ শুধু ans ভেক্টর তৈরি হয়েছে
Optimization scope	Yes!	যদি getmax() একবার হিসেব করে রাখি, তাহলে Time হবে O(n)
🛠️ Optimization Suggestion (Bonus):
cpp
Copy
Edit
int max = getmax(candies); // একবারই কল
for(int j=0; j<candies.size(); j++) {
    ans.push_back(candies[j] + extraCandies >= max);
}
এতে করে Time Complexity কমে যাবে O(n)-এ! 🔥

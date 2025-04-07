 কোড বিশ্লেষণ: finalString ফাংশন
cpp
Copy
Edit
if(s[j]=='i')
{
  final = reverse(final);
}
else
{
  final += s[j];
}
⏱️ Time Complexity বিশ্লেষণ
🟡 reverse(final):
reverse() ফাংশনের মধ্যে একটি লুপ রয়েছে যা স্ট্রিং s-এর দৈর্ঘ্য k পর্যন্ত চলে।

এটি প্রতি i এর জন্য চলতে পারে → O(k)
যেখানে k হচ্ছে সেই সময়ে final স্ট্রিং-এর দৈর্ঘ্য।

🔴 Worst Case Scenario:
যদি ইনপুট স্ট্রিং s = "iiii...i" (সব ক্যারেক্টার i) হয়:

তাহলে প্রতিবার reverse() চলবে।

1st time: 0 ক্যারেক্টার → 0 ops

2nd time: 1 ক্যারেক্টার → 1 ops

3rd time: 2 ক্যারেক্টার → 2 ops

…

n-th time: (n-1) ক্যারেক্টার → (n-1) ops

📐 Sum = 0 + 1 + 2 + ... + (n-1) = n(n-1)/2 →
✅ 🔴 Final Time Complexity = O(n²)

💾 Space Complexity বিশ্লেষণ
🔵 স্ট্রিং final:
নতুন স্ট্রিং তৈরি হচ্ছে যেখানে i বাদে সব ক্যারেক্টার যাচ্ছে, আর মাঝে মাঝে reverse() হচ্ছে।

যদিও reverse()-এর ভিতরে নতুন স্ট্রিং ans তৈরি হচ্ছে, সেটা সর্বোচ্চ n দৈর্ঘ্যের।

✅ 🔵 Final Space Complexity = O(n)

📊 Summary (Color-coded)
বিভাগ	ব্যাখ্যা	কমপ্লেক্সিটি
🔴 Time	Worst case: প্রতিবার reverse(final) → Sum = 1+2+...+n → O(n²)	O(n²)
🔵 Space	নতুন স্ট্রিং final এবং ans → সর্বোচ্চ n ক্যারেক্টার ব্যবহার	O(n)

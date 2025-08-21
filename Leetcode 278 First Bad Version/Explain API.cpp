🔹 Common Theory: API কীভাবে কাজ করে?

isBadVersion(version) হচ্ছে একটা দেওয়া API (pre-defined function)।
মানে এই ফাংশনের ভেতরের কোড আমাদের জানার দরকার নাই বা আমরা লিখতে পারব না, শুধু ব্যবহার করব।

এটা মূলত boolean value রিটার্ন করে:

true (বা 1) → যদি ওই version থেকে শুরু করে সবগুলো version bad হয়।

false (বা 0) → যদি ওই version এখনো ভালো থাকে।

🔹 Problem Concept (বাংলায়):

ধরা যাক কোনো সফটওয়্যার এর অনেকগুলো version আছে [1, 2, 3, 4, 5 ... n]।

কোনো একটা version থেকে শুরু করে সবগুলো পরবর্তী version খারাপ হয়ে গেছে।
আমাদের কাজ হলো প্রথম খারাপ version (first bad version) খুঁজে বের করা।

API isBadVersion(version) দিয়ে আমরা চেক করতে পারব — এই version খারাপ নাকি ভালো।

🔹 Example দিয়ে বোঝানো যাক:

ধরা যাক total version = n = 5
আর ধরুন প্রথম bad version হলো 4।

মানে list এমন:

1 → good
2 → good
3 → good
4 → bad
5 → bad


এখন algorithm কাজ করবে এভাবে:

Step 1:
low = 1, high = 5
mid = 1 + (5-1)/2 = 3


👉 isBadVersion(3) কল করা হলো।
যেহেতু 3 এখনও good → API return করবে false।

তাহলে আমরা জানি bad version 3 এর পরে আছে।
low = mid+1 = 4

Step 2:
low = 4, high = 5
mid = 4 + (5-4)/2 = 4


👉 isBadVersion(4) কল করা হলো।
এবার যেহেতু 4 হলো bad → API return করবে true।

তাহলে আমরা জানি প্রথম bad version 4 অথবা তার আগে আছে।
high = mid-1 = 3

Step 3:
low = 4, high = 3


👉 লুপ শেষ (কারণ low > high)।

এখন আমরা return করব low = 4।
অর্থাৎ প্রথম bad version হলো 4 ✅

🔹 সহজ ব্যাখ্যা:

isBadVersion(mid) basically একটা yes/no checker এর মতো।

আমরা mid check করে দেখি bad version এখানে এসেছে নাকি এর আগে/পরে।

Binary Search এর মতো বার বার range ছোট করি।

শেষে low যেখানে দাঁড়ায় সেটাই প্রথম bad version।

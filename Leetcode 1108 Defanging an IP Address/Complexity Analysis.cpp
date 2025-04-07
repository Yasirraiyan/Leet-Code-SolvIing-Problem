তুমি যে defangIPaddr ফাংশনটি লিখেছো, সেটি একটি IP ঠিকানার প্রতিটি ডট (.) কে [.] দ্বারা প্রতিস্থাপন করে। এখন আসি টাইম এবং স্পেস কমপ্লেক্সিটি বিশ্লেষণে।

🔢 টাইম কমপ্লেক্সিটি বিশ্লেষণ (Time Complexity)
cpp
Copy
Edit
for(int i=0;i<address.size();i++)
এই লুপটি পুরো address স্ট্রিং-এর উপর চলে। যদি স্ট্রিং-এর দৈর্ঘ্য হয় n, তাহলে লুপ চলবে n বার।

cpp
Copy
Edit
if(address[i]=='.') ans+="[.]"; else ans+=address[i];
যখন address[i] == '.', তখন "[.]" অ্যাড হচ্ছে, যার দৈর্ঘ্য 3।

অন্যথায়, একটি ক্যারেক্টার যোগ হচ্ছে।

C++-এ += অপারেশন যদি প্রতিবারে নতুন স্ট্রিং তৈরি করে (যেটা সাধারণ std::string-এ হতে পারে), তাহলে এটা O(n²) পর্যন্ত হতে পারে। তবে, বাস্তব প্রয়োগে std::string অ্যামর্টাইজডভাবে resize করে, তাই গড়ে O(n) ধরতে পারি।

✅ Final Time Complexity:
O(n), যেখানে n = স্ট্রিং address এর দৈর্ঘ্য।

🧠 স্পেস কমপ্লেক্সিটি বিশ্লেষণ (Space Complexity)
আমরা একটা নতুন স্ট্রিং ans তৈরি করছি, যেখানে প্রতিটি ডট "[.]" দিয়ে রূপান্তরিত হচ্ছে।

যদি address-এ k সংখ্যক ডট থাকে, তাহলে আউটপুট স্ট্রিংয়ের সাইজ হবে n + 2k (প্রতি ডট-এর জন্য অতিরিক্ত 2 ক্যারেক্টার)।

সুতরাং, স্পেস কমপ্লেক্সিটি হবে O(n)।


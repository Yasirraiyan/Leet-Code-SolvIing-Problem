তোমার দেওয়া C++ কোডটি বিশ্লেষণ করে নিচে টাইম ও স্পেস কমপ্লেক্সিটি বুঝিয়ে দিচ্ছি বাংলা ভাষায়। সাথে তিনটি গ্রাফও তৈরি করেছি JPEG ফরম্যাটে:

📘 টাইম কমপ্লেক্সিটি বিশ্লেষণ (Time Complexity)
cpp
Copy
Edit
int cell = n * n;
int totalweight = w * cell;

if (totalweight <= maxWeight) {
    ans = cell;
} else {
    ans = maxWeight / w;
}
এই অংশে কোনো লুপ বা রিকারশন নেই, সব অপারেশনই constant time-এ হচ্ছে।
🔷 তাই টাইম কমপ্লেক্সিটি = O(1) (অর্থাৎ ইনপুট সাইজ বাড়লেও সময় একই থাকবে)

📗 স্পেস কমপ্লেক্সিটি বিশ্লেষণ (Space Complexity)
এই কোডে কয়েকটি integer ভেরিয়েবল ব্যবহার করা হয়েছে (cell, totalweight, ans)।
🔷 অতিরিক্ত মেমোরি ব্যবহৃত হচ্ছে না, তাই স্পেস কমপ্লেক্সিটিও = O(1)


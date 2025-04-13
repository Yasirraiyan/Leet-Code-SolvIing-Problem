C++ কোড বিশ্লেষণ

টাইম কমপ্লেক্সিটি ও স্পেস কমপ্লেক্সিটি (Bangla + Recurrence Relation সহ)

টাইম ও স্পেস কমপ্লেক্সিটির গ্রাফ আলাদাভাবে

কম্বাইন্ড গ্রাফ

JPEG ফরম্যাটে কালারফুল ব্যাখ্যা সহ ছবি

GitHub-এ আপলোড করা

🧠 ১. C++ কোডটি কী করে?
cpp
Copy
Edit
int findClosest(int x, int y, int z) {
    int a = abs(z - x);  // x এর সাথে z এর পার্থক্য
    int b = abs(z - y);  // y এর সাথে z এর পার্থক্য

    if (a < b) return 1; // x কাছাকাছি
    else if (a == b) return 0; // সমান দূরত্ব
    else return 2; // y কাছাকাছি
}
⏱️ ২. Time Complexity (Bangla + Recurrence)
👉 Step by step:
abs(z - x) → O(1)

abs(z - y) → O(1)

তুলনা (if, else if, else) → O(1)

✅ মোট Time Complexity:
mathematica
Copy
Edit
T(n) = O(1) + O(1) + O(1)
⇒ T(n) = O(1)
🔁 Recurrence Relation (ধরলে recursive হতো):

txt
Copy
Edit
T(n) = T(n - 1) + C → Not applicable here since no recursion/loop
📦 ৩. Space Complexity (Bangla)
int a, b, ans → Constant space

কোনো অ্যারে/ডাইনামিক মেমরি নেই

✅ Space Complexity:

mathematica
Copy
Edit
S(n) = O(1)

📊 Time Complexity বিশ্লেষণ (Bangla)
cpp
Copy
Edit
for(int j=1; j<=n; j++) {
    reserve[j] = reserve[j-1] + gain[j-1];  // O(n)
}
ans = findmax(reserve);  // O(n)
👉 মোট কাজের সংখ্যা = O(n) + O(n) = O(n)

📌 Recurrence Relation:
T(n) = T_prefix(n) + T_max(n)
    = n + n = 2n ⇒ O(n)

🧠 Space Complexity বিশ্লেষণ (Bangla)
cpp
Copy
Edit
vector<int> reserve(n + 1);  // O(n)
👉 শুধুমাত্র reserve[] নামক prefix sum array তৈরি করা হয়েছে, যার সাইজ n+1।
সুতরাং Space Complexity: O(n)

🧮 ম্যাথমেটিক্যাল বিশ্লেষণ:
Prefix sum:
S(i) = gain[0] + gain[1] + ... + gain[i-1] ⇒ Linear Summation

Max Search:
max = max(S(0), S(1), ..., S(n)) ⇒ Linear Scan


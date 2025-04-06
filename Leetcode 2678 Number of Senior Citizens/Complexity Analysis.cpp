Function Summary
✅ Code Functionality:
get() function দিয়ে index 11 ও 12 থেকে age তোলা হচ্ছে।

তারপর stoi() দিয়ে string থেকে int age বানানো হচ্ছে।

তারপর vector-এ age গুলো রাখা হচ্ছে।

অবশেষে age > 60 হলে count বাড়ানো হচ্ছে।

⏱ Time Complexity
ধরি, n = details.size()
প্রতিটি string এর length fix = 15

cpp
Copy
Edit
for (int j = 0; j < details.size(); j++) {
    ans.push_back(stoi(get(details[j])));
}
🔹 get(details[j]) — প্রতি iteration-এ 1 বার চলবে, complexity O(1)
🔹 stoi(...) — দুই digit number convert করছে, এটাও O(1)
👉 So, এই loop এর complexity: O(n)

cpp
Copy
Edit
for (int k = 0; k < ans.size(); k++) {
    if (ans[k] > 60) {
        count++;
    }
}
👉 এই loop ও O(n)

✅ Total Time Complexity:
mathematica
Copy
Edit
O(n) + O(n) = O(n)
Space Complexity
তুমি একটা vector<int> ans রাখছো — যা n সংখ্যক integer রাখছে।
➤ O(n)

কিছু string, int, counter — সব O(1)

✅ Total Space Complexity:
scss
Copy
Edit
O(n)

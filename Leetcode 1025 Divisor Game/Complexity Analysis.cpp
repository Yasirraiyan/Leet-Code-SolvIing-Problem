📘 Bangla বিশ্লেষণ (Mathematical with Recurrence Relation):
✅ Function:
cpp
Copy
Edit
bool divisorGame(int n) 
{
    bool win = false;
    if(n % 2 == 0)
    {
        win = true;
    }
    return win;
}
🧮 Time Complexity Analysis:
এই ফাংশনে শুধুমাত্র একটি if condition আছে এবং কিছু সাধারণ assignment ও return statement আছে।

এটি ইনপুট n এর উপর কোনো iteration বা recursion করে না।

সুতরাং, প্রত্যেক বার ফাংশন চালাতে সর্বোচ্চ নির্দিষ্ট সংখ্যক ধাপ লাগে।

🔁 Recurrence Relation:

r
Copy
Edit
T(n) = O(1)
🧠 অর্থাৎ, যত বড়ই n হোক না কেন, কাজের পরিমাণ একই থাকবে।

💾 Space Complexity Analysis:
শুধুমাত্র একটি bool টাইপ ভেরিয়েবল win ব্যবহার করা হয়েছে।

কোনো অ্যারে, লুপ বা অতিরিক্ত রিকার্সিভ কল নেই।

🔁 Recurrence Relation:

mathematica
Copy
Edit
S(n) = O(1)

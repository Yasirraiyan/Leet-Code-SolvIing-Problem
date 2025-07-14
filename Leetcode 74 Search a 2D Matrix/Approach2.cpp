Why right=mid-1 not left and left=mid+1 not right explain bangla mathemetically

🔍 Binary Search ধারণা (ধাপে ধাপে বুঝি):

আমরা প্রতি ধাপে mid index বের করি:

mid = left + (right - left)/2;

তারপর check করি তিনটা শর্ত:

1️⃣ যদি arr[mid] == target → মিলে গেছে → return mid

2️⃣ যদি arr[mid] < target → তাহলে target ডান পাশে (Right Half)

কেন left = mid + 1?

আমরা জানি arr[mid] ছোট, আর array sorted
⇒ তাহলে target অবশ্যই mid এর ডান পাশে হবে
⇒ তাই আমরা mid বাদ দিয়ে দেখি mid+1 থেকে right পর্যন্ত

> অর্থাৎ new range = [mid+1, right]



❌ যদি right = mid বা right = mid + 1 দাও?

তাহলে আবার সেই mid এলাকা ফিরে আসবে → infinite loop হতে পারে বা wrong answer


---

3️⃣ যদি arr[mid] > target → তাহলে target বাম পাশে (Left Half)

কেন right = mid - 1?

কারণ arr[mid] বড় → তাহলে target অবশ্যই mid এর বাম পাশে হবে
⇒ mid বাদ দিয়ে দেখি left থেকে mid-1 পর্যন্ত

> অর্থাৎ new range = [left, mid-1]



❌ যদি left = mid বা left = mid - 1 দাও?

তাহলে আবার mid থাকবে → বারবার সেই index ঘুরবে → ভুল উত্তর বা infinite loop


---

📊 Table & Mathematical Analysis:

ধরি:

arr = [2, 4, 6, 8, 10, 12, 14]
target = 10

Step	left	right	mid	arr[mid]	target	Action

1	0	6	3	8	10	8 < 10 → left = mid + 1 = 4
2	4	6	5	12	10	12 > 10 → right = mid - 1 = 4
3	4	4	4	10	10	match → return 4 ✅



---

⚠️ যদি আমরা ভুল করি:

❌ ভুল: right = mid দাও যখন mid > target

mid = 5, arr[mid] = 12 > 10
right = mid = 5

তাহলে again:

left = 4, right = 5 → mid = 4
next step → left = 4, right = 5 → mid = 4 (again!)
→ infinite loop বা ভুল উত্তর


---

✅ উপসংহার:

Condition	Why Update This Way?	Updated Range

target > mid	mid value ছোট, তাই mid বাদ দিয়ে ডানে যাই	left = mid + 1
target < mid	mid value বড়, তাই mid বাদ দিয়ে বামে যাই	right = mid - 1


> 👉 কারণ mid বাদ না দিলে mid বারবার আসবে, Binary Search কাজ করবে না বা ভুল রেজাল্ট দিবে।




---

🔔 মনে রাখো:

Binary Search এর core efficiency আসে "half space eliminate" করার ক্ষমতা থেকে।
তাই mid বাদ দিয়ে left বা right আপডেট করাই গাণিতিকভাবে সঠিক ও safe ✅


---🔍 Binary Search ধারণা (ধাপে ধাপে বুঝি):

আমরা প্রতি ধাপে mid index বের করি:

mid = left + (right - left)/2;

তারপর check করি তিনটা শর্ত:

1️⃣ যদি arr[mid] == target → মিলে গেছে → return mid

2️⃣ যদি arr[mid] < target → তাহলে target ডান পাশে (Right Half)

কেন left = mid + 1?

আমরা জানি arr[mid] ছোট, আর array sorted
⇒ তাহলে target অবশ্যই mid এর ডান পাশে হবে
⇒ তাই আমরা mid বাদ দিয়ে দেখি mid+1 থেকে right পর্যন্ত

> অর্থাৎ new range = [mid+1, right]



❌ যদি right = mid বা right = mid + 1 দাও?

তাহলে আবার সেই mid এলাকা ফিরে আসবে → infinite loop হতে পারে বা wrong answer


---

3️⃣ যদি arr[mid] > target → তাহলে target বাম পাশে (Left Half)

কেন right = mid - 1?

কারণ arr[mid] বড় → তাহলে target অবশ্যই mid এর বাম পাশে হবে
⇒ mid বাদ দিয়ে দেখি left থেকে mid-1 পর্যন্ত

> অর্থাৎ new range = [left, mid-1]



❌ যদি left = mid বা left = mid - 1 দাও?

তাহলে আবার mid থাকবে → বারবার সেই index ঘুরবে → ভুল উত্তর বা infinite loop


---

📊 Table & Mathematical Analysis:

ধরি:

arr = [2, 4, 6, 8, 10, 12, 14]
target = 10

Step	left	right	mid	arr[mid]	target	Action

1	0	6	3	8	10	8 < 10 → left = mid + 1 = 4
2	4	6	5	12	10	12 > 10 → right = mid - 1 = 4
3	4	4	4	10	10	match → return 4 ✅



---

⚠️ যদি আমরা ভুল করি:

❌ ভুল: right = mid দাও যখন mid > target

mid = 5, arr[mid] = 12 > 10
right = mid = 5

তাহলে again:

left = 4, right = 5 → mid = 4
next step → left = 4, right = 5 → mid = 4 (again!)
→ infinite loop বা ভুল উত্তর


---

✅ উপসংহার:

Condition	Why Update This Way?	Updated Range

target > mid	mid value ছোট, তাই mid বাদ দিয়ে ডানে যাই	left = mid + 1
target < mid	mid value বড়, তাই mid বাদ দিয়ে বামে যাই	right = mid - 1


> 👉 কারণ mid বাদ না দিলে mid বারবার আসবে, Binary Search কাজ করবে না বা ভুল রেজাল্ট দিবে।




---

🔔 মনে রাখো:

Binary Search এর core efficiency আসে "half space eliminate" করার ক্ষমতা থেকে।
তাই mid বাদ দিয়ে left বা right আপডেট করাই গাণিতিকভাবে সঠিক ও safe ✅


--

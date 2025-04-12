সময় ও স্পেস কমপ্লেক্সিটি বিশ্লেষণ (Time and Space Complexity Analysis in Bangla)
এই সমাধানটি nums1 ও nums2 অ্যারেতে একটি পূর্ণসংখ্যা x খুঁজে বের করে, যেটি nums1-এর প্রতিটি উপাদানের সাথে যোগ করলে nums2 পাওয়া যায়।

আলগোরিদমের ধাপসমূহ (Steps of the Algorithm)
সর্টিং (Sorting):

nums1 ও nums2 কে সর্ট করা হয়েছে।

ক্ষুদ্রতম অ্যারের জন্য শর্ত (Single Element Case):

যদি অ্যারের দৈর্ঘ্য ১ হয়, তাহলে সরাসরি x = nums2[0] - nums1[0] হিসাব করা হয়।

বড় অ্যারের জন্য শর্ত (Multiple Elements Case):

nums1 ও nums2-এর সমষ্টি (sum1 ও sum2) হিসাব করা হয়।

x = (sum2 - sum1) / nums1.size() হিসাব করা হয়।

সময় কমপ্লেক্সিটি (Time Complexity)
গাণিতিক বিশ্লেষণ (Mathematical Analysis)
সর্টিং (Sorting):

sort() ফাংশনের সময় কমপ্লেক্সিটি O(n log n) (যেখানে n অ্যারের দৈর্ঘ্য)।

যেহেতু দুটি অ্যারে সর্ট করা হচ্ছে, মোট সময় = O(2n log n) = O(n log n)।

সমষ্টি হিসাব (Sum Calculation):

দুটি অ্যারের সমষ্টি বের করতে O(n) সময় লাগে।

মোট সময় = O(2n) = O(n)।

অন্যান্য অপারেশন (Other Operations):

বিয়োগ, ভাগ, শর্ত পরীক্ষা — এগুলো O(1) সময় নেয়।

সর্বমোট সময় কমপ্লেক্সিটি (Total Time Complexity):
O(n log n) + O(n) = O(n log n)
(যেহেতু O(n log n) ডোমিনেট করে)

স্পেস কমপ্লেক্সিটি (Space Complexity)
গাণিতিক বিশ্লেষণ (Mathematical Analysis)
সর্টিং-এর জন্য অতিরিক্ত মেমরি (Extra Memory for Sorting):

C++-এর sort() সাধারণত O(log n) স্পেস নেয় (রিকার্সিভ কুইকসর্টের কারণে)।

ভেরিয়েবল স্টোরেজ (Variable Storage):

sum1, sum2, ans — এগুলো O(1) স্পেস নেয়।

সর্বমোট স্পেস কমপ্লেক্সিটি (Total Space Complexity):
O(log n)
(মূলত সর্টিং অ্যালগরিদমের জন্য অতিরিক্ত স্পেস)

গ্রাফিক্যাল রিপ্রেজেন্টেশন (Graphical Representation)
১. সময় কমপ্লেক্সিটি গ্রাফ (Time Complexity Graph)
X-অক্ষ (Input Size n): অ্যারের দৈর্ঘ্য

Y-অক্ষ (Time Taken): সময়

গ্রাফের প্রকৃতি:

লিনিয়ার (O(n)) থেকে খানিকটা উপরে, কিন্তু কোয়াড্রাটিক (O(n²)) থেকে অনেক নিচে।

রঙ: লাল (যেহেতু এটি লিনিয়ার থেকে দ্রুতগতি সম্পন্ন)।

২. স্পেস কমপ্লেক্সিটি গ্রাফ (Space Complexity Graph)
X-অক্ষ (Input Size n): অ্যারের দৈর্ঘ্য

Y-অক্ষ (Memory Used): মেমরি ব্যবহার

গ্রাফের প্রকৃতি:

লগারিদমিক (O(log n)), অর্থাৎ ধীরে ধীরে বাড়ে।

রঙ: নীল (যেহেতু এটি খুবই ধীরগতি সম্পন্ন)।

📌 নোট: এই গ্রাফগুলো GitHub-এ আপলোড করা যেতে পারে JPEG/PNG ফরম্যাটে, যেখানে:

লাল গ্রাফ → সময় কমপ্লেক্সিটি

নীল গ্রাফ → স্পেস কমপ্লেক্সিটি
  স্পেস কমপ্লেক্সিটি O(log n) কেন, O(1) নয়? (Why Space Complexity is O(log n) Not O(1)?)
১. সর্টিং অ্যালগরিদমের স্পেস ইউজ (Space Usage of Sorting Algorithm)
C++-এর std::sort() সাধারণত ইন্ট্রোসর্ট (Introsort) ব্যবহার করে, যা একটি হাইব্রিড অ্যালগরিদম (কুইকসর্ট + হিপসর্ট + ইনসার্শন সর্ট)।

কুইকসর্টের স্পেস কমপ্লেক্সিটি (QuickSort Space Complexity):
সেরা কেস (Best Case): O(log n)
(রিকার্সিভ কল স্ট্যাকের কারণে, যেহেতু প্রতিটি বিভাজনে অ্যারেটি প্রায় অর্ধেক হয়ে যায়)

ওয়ার্স্ট কেস (Worst Case): O(n)
(যদি পিভট সব সময় সবচেয়ে ছোট/বড় এলিমেন্ট হয়, তখন রিকার্সিভ ডেপথ n হয়)

যেহেতু std::sort() ওয়ার্স্ট কেস এড়াতে ইন্ট্রোসর্ট ব্যবহার করে, তাই এর স্পেস কমপ্লেক্সিটি গড়ে O(log n) হয়।

হিপসর্টের স্পেস কমপ্লেক্সিটি (HeapSort Space Complexity):
O(1) (ইন-প্লেস সর্টিং)

কিন্তু std::sort() শুধু হিপসর্ট ব্যবহার করে না, তাই মোট স্পেস O(log n) ধরা হয়।

২. ম্যাথমেটিক্যাল এক্সপ্ল্যানেশন (Mathematical Explanation)
ধরি, n = অ্যারের সাইজ।

রিকার্সিভ কুইকসর্টের স্পেস:
প্রতিটি রিকার্সিভ কল অ্যারেকে প্রায় অর্ধেক করে, তাই রিকার্সিভ ডেপথ = log₂ n।
∴ মোট স্পেস = O(log n)

কেন O(1) নয়?
যদি অ্যালগরিদম শুধু ইটারেটিভ হতো (যেমন: সিলেকশন সর্ট), তাহলে স্পেস O(1) হতো।

কিন্তু std::sort() রিকার্সিভ অ্যাপ্রোচ ব্যবহার করে, তাই অতিরিক্ত কল স্ট্যাক মেমরি নেয়।

৩. উদাহরণ দিয়ে ব্যাখ্যা (Explanation with Example)
ধরি, nums1 = [4, 2, 5, 1] এবং nums2 = [7, 5, 8, 4]

স্টেপ-বাই-স্টেপ মেমরি ইউজ (Step-by-Step Memory Usage):
std::sort(nums1) কল করলে:

প্রথম পার্টিশন: [2, 1] এবং [4, 5] (মধ্যবর্তী পিভট = 4)

রিকার্সিভলি [2, 1] সর্ট হয় → আবার পার্টিশন হয় [1] এবং [2]

কল স্ট্যাক ডেপথ = 2 (log₂ 4 = 2)

একইভাবে nums2 সর্ট করতে আরও O(log n) স্পেস লাগে।

∴ মোট স্পেস = O(log n) + O(log n) = O(log n)

৪. গ্রাফিক্যাল রিপ্রেজেন্টেশন (Graphical Representation)
অ্যারের সাইজ (n)	রিকার্সিভ ডেপথ (log₂ n)	স্পেস ইউজ (O(log n))
1	0	O(1)
2	1	O(1)
4	2	O(2)
8	3	O(3)
16	4	O(4)
📌 গ্রাফ:

X-অক্ষ: n (অ্যারের সাইজ)

Y-অক্ষ: স্পেস ইউজ (কল স্ট্যাক ডেপথ)

গ্রাফটি লগারিদমিক কার্ভ (log n) অনুসরণ করে → ধীরে ধীরে বাড়ে।

৫. O(1) স্পেস সমাধান (O(1) Space Solution)
যদি সর্টিং না করে শুধু মিনিমাম এলিমেন্ট বের করা হয়, তাহলে স্পেস O(1) হয়:

cpp
Copy
int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int min1 = *min_element(nums1.begin(), nums1.end());
    int min2 = *min_element(nums2.begin(), nums2.end());
    return min2 - min1;
}
কমপ্লেক্সিটি:
সময়: O(n)

স্পেস: O(1) (কোনো অতিরিক্ত মেমরি লাগে না)

এটি অপ্টিমাইজড সমাধান, যেখানে সর্টিংয়ের O(log n) স্পেস এড়ানো যায়। 🚀

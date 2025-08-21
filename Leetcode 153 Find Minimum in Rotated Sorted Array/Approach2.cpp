🔹 Problem আবার দেখা যাক

আমাদের কাছে একটা sorted ascending array আছে যেটা rotate করা হয়েছে।
আমাদের target → সেই array থেকে minimum element খুঁজে বের করা।
শর্ত → Time Complexity হতে হবে O(log n)।

👉 এই O(log n) দেখে সঙ্গে সঙ্গেই মাথায় আসতে হবে → এখানে Binary Search ইউজ করতে হবে।

🔹 Rotate হওয়ার পর array কেমন হয়?

যদি array [0,1,2,4,5,6,7] rotate করি 4 বার:
➡️ [4,5,6,7,0,1,2]

এখানে লক্ষ্য করো:

একদিকে বড় সংখ্যাগুলো → [4,5,6,7]

আরেকদিকে ছোট সংখ্যাগুলো → [0,1,2]

আর minimum element সবসময় second part-এর শুরুতে থাকে।

মানে rotate করার পর array দেখতে হবে:
[sorted বড় সংখ্যা] + [sorted ছোট সংখ্যা]

🔹 আমাদের লক্ষ্য

আমাদের binary search দিয়ে minimum element (rotation point) বের করতে হবে।

🔹 Binary Search কৌশল (Step by Step)

আমরা ধরব:

low = 0
high = n-1


প্রতিবার mid বের করব:

mid = low + (high - low) / 2


এখন nums[mid] আর nums[high] compare করবো।

✅ Case 1: যদি nums[mid] < nums[high]

মানে → mid থেকে high পর্যন্ত অংশ sorted।
তাহলে minimum mid বা তার বাঁদিকে আছে।
👉 তাই high = mid

✅ Case 2: যদি nums[mid] > nums[high]

মানে → mid এর ডানদিকে unsorted আছে, আর minimum সবসময় unsorted অংশেই থাকে।
👉 তাই low = mid + 1

✅ Case 3: যদি nums[mid] == nums[high]

(এই problem-এ সব element unique, তাই আসলে এই case আসবে না। তবুও safe রাখার জন্য high-- ব্যবহার করা হয়)।

🔹 Stopping Condition

যখন low == high, তখন আমরা minimum element পেয়ে গেছি।
👉 return nums[low]

🔹 Example দিয়ে Range Update বোঝানো
Example 1: nums = [3,4,5,1,2]
low=0, high=4
mid=2 → nums[mid]=5, nums[high]=2
5 > 2 → low = mid+1 = 3


এখন range → [3,4] → অর্থাৎ [1,2]

low=3, high=4
mid=3 → nums[mid]=1, nums[high]=2
1 < 2 → high = mid = 3


এখন low=3, high=3 → loop শেষ
👉 minimum = nums[3] = 1 ✅

Example 2: nums = [4,5,6,7,0,1,2]
low=0, high=6
mid=3 → nums[mid]=7, nums[high]=2
7 > 2 → low = mid+1 = 4


এখন range → [4,6] → অর্থাৎ [0,1,2]

low=4, high=6
mid=5 → nums[mid]=1, nums[high]=2
1 < 2 → high = mid = 5


এখন range → [4,5] → অর্থাৎ [0,1]

low=4, high=5
mid=4 → nums[mid]=0, nums[high]=1
0 < 1 → high = mid = 4


এখন low=4, high=4 → stop
👉 minimum = nums[4] = 0 ✅

Example 3: nums = [11,13,15,17]
low=0, high=3
mid=1 → nums[mid]=13, nums[high]=17
13 < 17 → high = mid = 1


এখন range → [0,1]

low=0, high=1
mid=0 → nums[mid]=11, nums[high]=13
11 < 13 → high = mid = 0


low=0, high=0 → stop
👉 minimum = nums[0] = 11 ✅

🔹 Technique Used

👉 Modified Binary Search

সাধারণ binary search-এ আমরা একটা fixed target খুঁজি।

এখানে আমাদের target হলো minimum element, তাই আমরা range update করছি mid আর high এর relation দিয়ে।

🔹 Math দিয়ে বোঝানো

ধরি array length n, rotate করলে minimum element সবসময় rotation index (k) তে থাকবে।

➡️ আমাদের কাজ হলো k বের করা।
Binary search দিয়ে আমরা প্রতি step-এ search space কে half (n/2) করে ফেলছি।

তাহলে complexity:

মানে → mid থেকে high পর্যন্ত অংশ sorted।
তাহলে minimum mid বা তার বাঁদিকে আছে।
👉 তাই high = mid how by example bangla
ChatGPT said:

খুব ভালো ধরেছো 👍
চল এবার Case 1 –
👉 যখন nums[mid] < nums[high], তখন আমরা কেন high = mid করি সেটা একটা example দিয়ে বিস্তারিত বোঝাই।

🎯 Example: nums = [4,5,6,7,0,1,2]

ধরি,

low = 0 → nums[low] = 4
high = 6 → nums[high] = 2
mid = (0+6)/2 = 3 → nums[mid] = 7


এখন দেখা যাচ্ছে:

nums[mid] = 7, nums[high] = 2
7 > 2   ✅


👉 তাহলে আমরা জানি minimum mid এর ডানদিকে আছে (এটা Case 2, তাই low=mid+1)।

🎯 এবার ধরো nums = [2,3,4,5,6,7,8]

ধরি,

low = 0 → nums[low] = 2
high = 6 → nums[high] = 8
mid = 3 → nums[mid] = 5


এখন compare করি:

nums[mid] = 5, nums[high] = 8
5 < 8   ✅


👉 মানে mid থেকে high পর্যন্ত অংশ [5,6,7,8] already sorted।
এই sorted অংশে minimum থাকতে পারে না, কারণ minimum সবসময় left part-এ থাকে।

তাহলে আমাদের খুঁজতে হবে:

হয় mid নিজেই minimum (যদি array rotate না করা থাকে),

নয় mid এর বাঁদিকে minimum আছে।

👉 তাই আমরা search space ছোট করে দেই:

high = mid

🎯 আরেকটা Example: nums = [3,4,5,1,2]

ধরি,

low = 0 → nums[low] = 3
high = 4 → nums[high] = 2
mid = 2 → nums[mid] = 5


Compare:

nums[mid] = 5, nums[high] = 2
5 > 2 → Case 2 → low=mid+1=3


এখন range [1,2]

low=3, high=4
mid=3 → nums[mid]=1, nums[high]=2
1 < 2 ✅


এখন বোঝা যাচ্ছে mid থেকে high (1,2) অংশ sorted।
👉 Minimum হয় mid (1), নয়ত তার বাঁদিকে।
তাই high=mid=3

শেষে low=3, high=3 → answer = 1 ✅

🔑 Key Idea (Bangla)

যদি nums[mid] < nums[high] হয়
👉 তাহলে বোঝায় mid থেকে high অংশ sorted।
👉 sorted অংশে minimum নেই (শুধু একমাত্র exception – mid নিজেই হতে পারে)।
👉 তাই আমরা high=mid করি → যেনো বাঁদিকটায় search হয়।
Reccurance Relation:
---------------------

  T(n) = T(n/2) + O(1)
=> T(n) = O(log n)

  
Full Code:
----------

  class Solution 
{
public:
    int findMin(vector<int>& nums)
{
    int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high])
            {
               high=mid;
            }
           else  if(nums[mid]>nums[high])
            {
              low=mid+1;
            }
            else
            {
                high--;
            }
        }
        return nums[low];
    }
};


🔍 Problem এর Understanding:

একটা মাউন্টেন অ্যারে এই রকম:

প্রথমে কিছু সংখ্যক এলিমেন্ট ক্রমাগত বাড়ে (increasing),

তারপর একটি পিক আসে (যেখানে আগের এবং পরের উভয়ের চেয়ে বড়),

তারপর ধীরে ধীরে কমে (decreasing)।


যেমন:
[0, 1, 0] → পিক = 1 (index 1)
[0, 2, 1, 0] → পিক = 2 (index 1)
[0, 10, 5, 2] → পিক = 10 (index 1)


---

🔎 লক্ষ্য:

তুমি এমন একটা index খুঁজবে যেখানে arr[i] > arr[i-1] এবং arr[i] > arr[i+1] — অর্থাৎ পিক এলিমেন্ট।


---

✅ Time Complexity:

তোমার সমাধানটি Binary Search ব্যবহার করে, তাই সময় কমে দাঁড়ায় O(log n)।


---

🧠 Approach - কেন Binary Search ব্যবহার করবো?

যেহেতু মাউন্টেন অ্যারে প্রথমে বাড়ে, পরে কমে, তাই আমরা এটা একটা ভাঙা পাহাড়ের মত ভাবতে পারি।

আমরা যদি কোন mid ইন্ডেক্স নিই, তাহলে তিনটি অবস্থা হতে পারে:

1️⃣ যদি arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] → আমরা পিক পেয়ে গেছি।

2️⃣ যদি arr[mid] < arr[mid+1] → এর মানে আমরা বাড়ার পথে আছি, তাই পিক ডান পাশে হবে → low = mid + 1

3️⃣ অন্যথায় → এর মানে আমরা কমার পথে আছি → পিক বাম পাশে → high = mid - 1


---

🔢 Code Line by Line Explanation in Bangla:

int low = 1;
int high = arr.size() - 2;

প্রথম ও শেষ ইন্ডেক্স কখনোই পিক হতে পারে না কারণ মাউন্টেন অ্যারে 3 বা তার বেশি লম্বা হয় এবং মাঝখানে পিক থাকে।

তাই আমরা binary search শুরু করছি 1 থেকে n-2 পর্যন্ত।


int ans = -1;

যদি পিক পাই, এই ভ্যারিয়েবলে সেট করবো।


while(low <= high) {
    int mid = low + (high - low) / 2;

Binary Search এর স্ট্যান্ডার্ড ফর্মুলা — Overflow এড়াতে।


if ((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])) {
        ans = mid;
        break;
    }

যদি mid তার দুই পাশে থেকেও বড় হয়, তাহলে এটাই পিক। ব্রেক করলাম।


if (arr[mid] < arr[mid+1]) {
        low = mid + 1;
    }

arr[mid] < arr[mid+1] → মানে আমরা এখনও বাড়ার পথে আছি, তাই পিক এর ডান দিকে আছে → Low বাড়াও।


else {
        high = mid - 1;
    }

অন্যথায় মানে আমরা কমার পথে আছি → পিক এর বাম দিকে আছে → High কমাও।


return ans;

পিক পাওয়া গেলে সেটি রিটার্ন করো।



---

🧪 Example Trace (arr = [0, 2, 1, 0])

Initial: low = 1, high = 2

1st Iteration:
mid = 1
arr[1] = 2, arr[0] = 0, arr[2] = 1
→ 2 > 0 && 2 > 1 → পিক পেয়ে গেছি → return 1


---

🔁 Complexity:

Time: O(log n) — প্রতি স্টেপে খুঁজে নিচ্ছি অর্ধেক।

Space: O(1) — কোন এক্সট্রা স্পেস ইউজ করিনি।



---

✅ Final Notes:

তুমি যেটা করেছো, সেটা একদম স্ট্যান্ডার্ড Binary Search Technique based approach।

তুমি প্রথমে বুঝেছো peak খোঁজা মানে এমন একটা index যেটা তার দুই পাশের থেকেও বড়।

তুমি এটা বুঝে ফেলেছো যে increasing হলে ডান দিকে যেতে হবে, decreasing হলে বাম দিকে যেতে হবে।



---

✅ উপসংহার:

তুমি এই সমস্যা সমাধানে problem pattern + binary search একসাথে apply করে দারুণ কাজ করেছো।

চিন্তা করার flow:

1. মাউন্টেন অ্যারে মানে increasing → peak → decreasing


2. তিনটি case ধরে binary search apply


3. mid এর অবস্থান অনুযায়ী direction নির্ধারণ


4. log(n) time এ পিক বের করে আনা

  Full Code:
----------------

class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int low=1;
        int high=arr.size()-2;
        int ans=-1;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1]))
                   {
                ans= mid;
                    break;
                    
                   }
                if(arr[mid]<arr[mid+1])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
                
            }
        return ans;
    }
};
  

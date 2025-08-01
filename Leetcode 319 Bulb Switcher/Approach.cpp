🔍 প্রোবলেম ভালো করে বুঝি (Understanding the Problem)
প্রতিটি রাউন্ডে:

Round 1 → সব বাল্ব ON করা হয়

Round 2 → প্রতি 2 নম্বর বাল্ব toggle (যেমন: 2, 4, 6...)

Round 3 → প্রতি 3 নম্বর বাল্ব toggle (যেমন: 3, 6, 9...)

...

Round i → প্রতি i-তম বাল্ব toggle

Toggle মানে হলো যদি ON থাকে OFF হবে, আর যদি OFF থাকে ON হবে।

🎯 টার্গেট:
শেষে কয়টি বাল্ব ON থাকবে?

✅ ইম্পরট্যান্ট অবজারভেশন (Observation)
একটি নির্দিষ্ট বাল্ব k কবে toggle হবে?

👉 সে তখন toggle হবে যখন i এমন একটা সংখ্যা হবে যা k কে divide করে: অর্থাৎ i is a divisor of k.

📌 অর্থাৎ:
একটা বাল্ব k total কতবার toggle হবে = k এর total divisor সংখ্যা।

🔁 এখন,

যদি কোনো সংখ্যার even সংখ্যক divisor থাকে, তবে সে বারবার toggle হয়ে শেষে OFF হয়ে যাবে।

আর যদি odd সংখ্যক divisor থাকে, তবে শেষে ON থাকবে।

💡 তাই, কোন সংখ্যা গুলোর odd number of divisors থাকে?
👉 Perfect Square সংখ্যা গুলোর!

যেমন:

9 → divisor: 1, 3, 9 → total 3 (odd) → ON

6 → divisor: 1, 2, 3, 6 → total 4 (even) → OFF

Conclusion: শুধুমাত্র perfect square index গুলোর বাল্ব গুলো শেষে ON থাকবে।

🔢 এখন আমাদের কাজ:
1 থেকে n পর্যন্ত কয়টা perfect square আছে?

উত্তর হবে: floor(sqrt(n))

🧠 এখন কিভাবে কোড করবো (How to think & write code)?
√n বের করবো

যতগুলো পূর্ণ সংখ্যা i আছে যেখানে i*i <= n, সেগুলোই হলো perfect squares

আমরা binary search দিয়ে efficient way-তে বের করবো, √n এর নিচের সবচেয়ে বড় পূর্ণসংখ্যা।

✅ কোড ব্যাখ্যা (Code Explanation):
cpp
Copy
Edit
class Solution 
{
public:
    // এই ফাংশনটা দিয়ে আমরা √n এর নিচের সবচেয়ে বড় পূর্ণসংখ্যা বের করবো
    int TestPerfectSquare(int n)
    {
        int low = 0;
        int high = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid < n)
            {
                low = mid + 1;
            }
            else if (1LL * mid * mid == n)
            {
                return mid; // exact square found
            }
            else
            {
                high = mid - 1;
            }
        }
        return high; // closest integer less than or equal to √n
    }

    int bulbSwitch(int n) 
    {
        if (n == 0 || n == 1) return n; // base case
        int ans = TestPerfectSquare(n); // count of perfect squares ≤ n
        return ans;
    }
};
✅ টেস্ট কেস ব্যাখ্যা (Test Cases)
Test Case 1:
Input: n = 3
Perfect squares ≤ 3: 1 → তাই শুধু 1 নম্বর বাল্ব ON থাকবে
✅ Output: 1

Test Case 2:
Input: n = 0
কোনো বাল্বই নাই
✅ Output: 0

Test Case 3:
Input: n = 1
Perfect squares: 1
✅ Output: 1

Test Case 4:
Input: n = 10
Perfect squares: 1, 4, 9
✅ Output: 3

✅ টাইম কমপ্লেক্সিটি:
TestPerfectSquare(n) → Binary Search → O(log n)

So, overall: O(log n) time & O(1) space

🧠 কিভাবে চিন্তা করা শিখবো (How to approach this type):
এই ধরণের toggle, ON/OFF, repeated action এর সমস্যা দেখলে divisor / pattern চিন্তা করা ভালো।

Perfect square এ focus করলেই মূল logic ধরা যায়।


Full Code:
----------

  class Solution 
{
public:
int TestPerfectSquare(int n)
    {
        int low=0;
        int high=n;
        bool test=false;
        
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(1LL*mid*mid<n)
                {
                    low=mid+1;
                }
                else if(1LL*mid*mid==n)
                {
                   
                    return mid;
                  
                }
                else
                {
                    high=mid-1;
                }
                    
            }
        return high;
        
    }

    int bulbSwitch(int n) 
    {
        int count=0;
        if(n==0||n==1) return n;
      
int ans=TestPerfectSquare(n);
        return ans;
    }
};

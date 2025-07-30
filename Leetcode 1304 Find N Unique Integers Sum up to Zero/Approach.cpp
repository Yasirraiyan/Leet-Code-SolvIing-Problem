🧠 প্রাথমিক সমস্যা বোঝা (Problem Understanding)

> তোমাকে n সংখ্যক unique integer দিতে হবে যেগুলোর সমষ্টি (sum) হবে 0।



🔍 উপসংহার:

তুমি n সংখ্যক ভিন্ন সংখ্যা দিয়ে একটি vector<int> বানাবে।

যেইভাবে বানাও না কেন, সংখ্যাগুলোর sum হতে হবে 0।



---

🧠 চিন্তার কৌশল (How to Think for the Solution)

Step 1: ধরো n = 1

শুধু 0 দিলেই হয়: [0], sum = 0 ✅


Step 2: ধরো n = 3

আমরা এমন সংখ্যা চাই, যেগুলোর যোগফল 0: ধরো [0, -1, 1] → ✅


Step 3: ধরো n = 4

ধরো: [-1, 1, -2, 2] → যোগফল = 0 ✅


🔗 Pattern:

তুমি সব সময় x এবং -x পেয়ার বানাতে পারো।

যদি n even হয়: সবকিছুকে x, -x জোড়ায় ভাগ করা যায়।

যদি n odd হয়: প্রথমে 0 রাখো, তারপর বাকি n-1 সংখ্যাকে x, -x জোড়ায় ভাগ করো।



---

✅ তোমার কোড ব্যাখ্যা (Line-by-line Explanation):

int findsum(vector<int>&v)
{
    int sum=0;
    for(int j=0;j<v.size();j++)
    {
        sum+=v[j];
    }
    return sum;
}

🔍 কাজ:

এই ফাংশনটি একটি ভেক্টরের সব সংখ্যার যোগফল বের করে।



---

vector<int> sumZero(int n) {
    vector<int>v;

    if(n%2!=0) v.push_back(0); // যদি n বিজোড় হয়, তাহলে 0 রাখো

উদাহরণ:

n=5 → 0 রাখলাম → এখন ৪টি সংখ্যা দরকার → ২টি x,-x পেয়ার



---

int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        v.push_back(i);
        v.push_back(-i);

🔍 কাজ:

প্রতিটি ধাপে i ও -i যোগ করো। এটা sumZero হবে কারণ i + (-i) = 0



---

sum=findsum(v);
        if(v.size()==n && sum==0)
        {
            break;
        }
    }
    return v;
}

🔍 এখানে:

v.size()==n হলে আর sum==0 হলে আমরা বুঝি target পূরণ হয়েছে → break করি।

যদিও sumZero ফাংশনের এই sum চেক করা লাগতো না কারণ i, -i জোড়ায় থাকলে সবসময় যোগফল 0 হবে।

কিন্তু তুমি একটা ব্যাকআপ চেক দিয়ে রেখেছো। ✔️



---

✅ Test Case চললে কি হবে?

Test Case 1: n = 5

Step-by-step:

n%2!=0 → তাই v = [0]

i=1 → [0,1,-1]

i=2 → [0,1,-1,2,-2] → size = 5, sum = 0 → ✅ done.


Output: [0, 1, -1, 2, -2] অথবা যে কোনো permutation → valid ✔️


---

🔢 ম্যাথেমেটিকালি চিন্তা করলে:

Sum of pair: x + (-x) = 0

মোট পেয়ার দরকার: n/2 (if even), n-1/2 (if odd)

যদি n odd → 0 + (x1 + -x1) + (x2 + -x2) + ...

Full Code:
------------

 class Solution {
public:
    int findsum(vector<int>&v)
    {
        int sum=0;
        for(int j=0;j<v.size();j++)
            {
                sum+=v[j];
            }
        return sum;
    }
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n%2!=0) v.push_back(0);
        int sum=0;
        for(int i=1;i<=n/2;i++)
            {
                v.push_back(i);
                v.push_back(-i);
                 sum=findsum(v);
                if(v.size()==n&&sum==0)
                {
                    break;
                }
            }
        return v;
    }
}; 

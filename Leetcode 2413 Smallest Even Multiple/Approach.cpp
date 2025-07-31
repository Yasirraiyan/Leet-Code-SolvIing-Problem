🔍 Step-by-Step Problem Analysis (Bangla)

✅ কি জানতে চাচ্ছে?

তোমাকে এমন একটা সংখ্যা বের করতে হবে যা:

1. n এর multiple (i.e., i % n == 0)


2. এবং 2-এর multiple (i.e., i % 2 == 0)


3. এবং সবচেয়ে ছোট এমন সংখ্যা — অর্থাৎ Smallest Even Multiple

🧠 চিন্তা করার পদ্ধতি (Approach):

Let's break it down:

1. আমরা i = n থেকে শুরু করে যতক্ষণ না এমন একটা i পাই যেটা 2 ও n দুটারই multiple, ততক্ষণ চলবো।


2. অর্থাৎ i % 2 == 0 && i % n == 0 যেটা satisfy করবে।


3. সেটা পেলেই return করবো।




---

✅ তোমার কোড বিশ্লেষণ (Line-by-Line Explanation):

class Solution 
{
public:
    int smallestEvenMultiple(int n)
    {
        int small;

🔹 small নামের একটা ভ্যারিয়েবল নিয়েছো যেখানে আমরা smallest multiple save করবো।


---

for(int i=n;i<=pow(2,31)-1;i++)

🔹 আমরা i = n থেকে শুরু করছি কারণ n এর আগে তো কোনো সংখ্যাই n এর multiple না হবে।
🔹 যতক্ষণ না এমন সংখ্যা পাই যেটা 2 এবং n উভয়েরই multiple — i % 2 == 0 && i % n == 0

📌 pow(2,31)-1 মানে 2^31 - 1, যেটা হলো int-এর max range (2147483647)। যদিও এতদূর যাওয়া লাগবে না।


---

{
                if(i%2==0&&i%n==0)
                {
                    small=i;
                    break;
                }
            }

🔹 চেক করছো i কি 2 এবং n উভয়েরই multiple?
🔹 হলে small = i করে break দিয়ে loop থেকে বের হয়ে যাচ্ছো।


---

return small;
    }
};

🔹 অবশেষে সেই smallest even multiple return করছো।


Full Code:
------------

class Solution 
{
public:
    int smallestEvenMultiple(int n)
    {
        int small;
        for(int i=n;i<=pow(2,31)-1;i++)
            {
                if(i%2==0&&i%n==0)
                {
                    small=i;
                    break;
                }
            }
        return small;
    }
};

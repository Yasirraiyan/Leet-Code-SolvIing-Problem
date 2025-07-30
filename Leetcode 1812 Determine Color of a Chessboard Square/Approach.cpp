🔍 কী জানতে চাচ্ছে?

তুমি যাচাই করবে স্কয়ারটি সাদা (white) কিনা।


---

🎯 লক্ষ্য:

একটি bool ফাংশন তৈরি করা – যদি স্কয়ারটি সাদা হয় true রিটার্ন করবে, আর কালো হলে false।


---

🔢 চেসবোর্ড বোঝা (Coordinate System)

চলো বোঝা যাক a1 কী বোঝাচ্ছে:

চেসবোর্ড দেখতে এমন:

a b c d e f g h
1 B W B W B W B W
2 W B W B W B W B
3 B W B W B W B W
4 W B W B W B W B
5 B W B W B W B W
6 W B W B W B W B
7 B W B W B W B W
8 W B W B W B W B

এক্স-অ্যাক্সিসে: a = 1, b = 2, ..., h = 8

ওয়াই-অ্যাক্সিসে: 1 = 1, ..., 8 = 8


সুতরাং a1 = (1, 1), b1 = (2, 1), c7 = (3, 7)

🔲 রং নির্ধারণ (Color Pattern)

একটা স্কয়ারের রং নির্ধারণ করা যায় এর (x + y) এর যোগফল দিয়ে:

যদি (x + y) জোড় (even) হয় → কালো (black) স্কয়ার

যদি (x + y) বিজোড় (odd) হয় → সাদা (white) স্কয়ার


উদাহরণ:

a1 → x = 1, y = 1 → sum = 2 → even → black → false

h3 → x = 8, y = 3 → sum = 11 → odd → white → true

c7 → x = 3, y = 7 → sum = 10 → even → black → false



---

✅ এখন তোমার কোড বিশ্লেষণ করি:

class Solution 
{
public:
    bool squareIsWhite(string coordinates)
    {
        int sum=0;
        for(int i=0;i<coordinates.size();i++)
        {
            if(isdigit(coordinates[i]))
            {
                sum += coordinates[i] - '0'; // '1' থেকে '8' → 1 থেকে 8
            }
            else
            {
                sum += coordinates[i] - 'a' + 1; // 'a' থেকে 'h' → 1 থেকে 8
            }
        }
        bool iswhite = false;
        if(sum % 2 != 0) // যদি যোগফল বিজোড় হয়
        {
            iswhite = true;
        }
        return iswhite;
    }
};


---

🔍 লাইন বাই লাইন বিশ্লেষণ:

Line 1–2:

class Solution 
{
public:

একটা ক্লাস Solution ডিফাইন করা হয়েছে যাতে তুমি লীটকোডে জমা দিতে পারো।

public: এর মানে, এই ফাংশন বাইরে থেকে এক্সেস করা যাবে।



---

Line 3:

bool squareIsWhite(string coordinates)

এটি একটি ফাংশন যা একটি string ইনপুট নেয় (যেমন "a1") এবং bool রিটার্ন করে।



---

Line 4:

int sum=0;

স্কয়ারের x + y যোগফল হিসাব করার জন্য একটি ভেরিয়েবল।



---

Line 5–11:

for(int i=0;i<coordinates.size();i++)
{
    if(isdigit(coordinates[i]))
    {
        sum += coordinates[i] - '0';
    }
    else
    {
        sum += coordinates[i] - 'a' + 1;
    }
}

লুপটি coordinates এর দুইটি ক্যারেক্টার পড়ে:

যদি ক্যারেক্টারটি একটি সংখ্যা (যেমন '1') হয় → '1' - '0' = 1

যদি অক্ষর (letter) হয় যেমন 'a' → 'a' - 'a' + 1 = 1, 'b' - 'a' + 1 = 2, ইত্যাদি



📌 এখানে cleverness হচ্ছে তুমি ASCII ব্যবহার করে অক্ষরটাকে সংখ্যায় রূপান্তর করেছো।


---

Line 12–16:

bool iswhite = false;
if(sum % 2 != 0)
{
    iswhite = true;
}
return iswhite;

যদি sum বিজোড় হয় (odd), তাহলে স্কয়ার সাদা → true

না হলে স্কয়ার কালো → false



---

✅ কিভাবে সমাধান ভাববে প্রশ্ন পড়ে?

1. প্রশ্ন থেকে বুঝো তুমি শুধু জানতে চাও সাদা না কালো।


2. বোর্ডের রং চক্রাকারে পরিবর্তন হয় → বোঝা গেল এটা (x+y)%2 দিয়ে নির্ধারণযোগ্য।


3. a থেকে h কে সংখ্যা বানিয়ে x হিসেবে নাও।


4. 1 থেকে 8 তো আগেই সংখ্যা → y


5. যোগ করো → বিজোড় হলে সাদা, জোড় হলে কালো।




---

✅ টেস্ট কেস বিশ্লেষণ:

Test 1:

coordinates = "a1"

a = 1, 1 = 1 → sum = 2 → even → black → false ✅


Test 2:

coordinates = "h3"

h = 8, 3 = 3 → sum = 11 → odd → white → true ✅


Test 3:

coordinates = "c7"

c = 3, 7 = 7 → sum = 10 → even → black → false ✅



---

🔚 উপসংহার:

তোমার কোডটা efficient ও সহজভাবে সমস্যার মূল প্যাটার্ন ধরেছে।

🎯 সময় জটিলতা: O(1) — কারণ শুধু ২ অক্ষর নিয়ে কাজ হচ্ছে।

🎯 স্পেস জটিলতা: O(1)


Full Code:
------------

class Solution 
{
public:
    bool squareIsWhite(string coordinates)
    {
        int sum=0;
        for(int i=0;i<coordinates.size();i++)
            {
                if(isdigit(coordinates[i]))
                {
                    sum+=coordinates[i]-'0';
                }
                else
                {
                    sum+=coordinates[i]-'a'+1;
                }
            }
        bool iswhite=false;
        if(sum%2!=0)
        {
            iswhite=true;
        }
        return iswhite;
    }
};  

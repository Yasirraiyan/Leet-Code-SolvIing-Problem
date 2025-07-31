Get App
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet. For example: A -> 1 B -> 2 C -> 3 ... Z -> 26 AA -> 27 AB -> 28  ...   Example 1: Input: columnNumber = 1 Output: "A" Example 2: Input: columnNumber = 28 Output: "AB" Example 3: Input: columnNumber = 701 Output: "ZY"   Constraints:


1 <= columnNumber <= 231 - 1 For the qu sol is class Solution { public: string convertToTitle(int columnNumber) { string ans=""; while(columnNumber>0) { int rem=columnNumber%26;
         if(rem==0)             {                 ans+='Z';                 columnNumber=columnNumber/26-1;             }             else             {                 ans+=(rem-1+'A');              columnNumber/=26;         }         }     string result="";     for(int i=ans.size()-1;i>=0;i--)         {             result+=ans[i];         }     return result;  
} }; explain approach of solution how i think solution approach by reading qu how write code why accepted test by testcase line by line explain briefly mathemetically bangla all thing
এক্সেল কলাম টাইটেল কনভার্শন সমস্যাটি সমাধানের জন্য আমরা একটি সংখ্যাকে তার সংশ্লিষ্ট অক্ষরের স্ট্রিং-এ রূপান্তর করব। যেমন, 1 → "A", 2 → "B", ..., 26 → "Z", 27 → "AA", 28 → "AB", ইত্যাদি। এটি মূলত একটি বেস-২৬ (Base-26) সংখ্যা পদ্ধতির সমস্যা, তবে এখানে একটি পার্থক্য আছে: সাধারণ বেস-২৬-এ ০ থেকে ২৫ পর্যন্ত ডিজিট থাকে, কিন্তু এখানে ১ থেকে ২৬ পর্যন্ত মান আছে (A=1, B=2, ..., Z=26)।

সমাধানের ধাপগুলি:
মডুলো অপারেশন (%) ব্যবহার করে বর্তমান অক্ষর বের করা:

columnNumber কে ২৬ দিয়ে মড করলে আমরা একটি রিমাইন্ডার (remainder) পাব।

যদি রিমাইন্ডার ০ হয়, তাহলে এটি 'Z' অক্ষরকে নির্দেশ করে (কারণ Z = 26)।

যদি রিমাইন্ডার ১ থেকে ২৫ পর্যন্ত হয়, তাহলে আমরা এটিকে 'A' থেকে শুরু করে ম্যাপ করব (যেমন, ১ → 'A', ২ → 'B', ..., ২৫ → 'Y')।

পরবর্তী সংখ্যার জন্য কলাম নাম্বার আপডেট করা:

যদি রিমাইন্ডার ০ হয় ('Z'), তাহলে আমরা columnNumber কে ২৬ দিয়ে ভাগ করে ১ বিয়োগ করব (কারণ 'Z' এর জন্য আমরা ২৬ নিই, যা পুরো একটি পূর্ণ সংখ্যা গঠন করে)।

অন্যথায়, আমরা শুধু columnNumber কে ২৬ দিয়ে ভাগ করব।

অক্ষরগুলোকে রিভার্স অর্ডারে সংযুক্ত করা:

যেহেতু আমরা লুপে প্রথমে সর্বনিম্ন সিগনিফিকেন্ট ডিজিট (LSB) পাই, তাই অক্ষরগুলো উল্টোভাবে সংযুক্ত হয়। তাই শেষে স্ট্রিংটিকে রিভার্স করতে হবে।

উদাহরণ দিয়ে ব্যাখ্যা:
টেস্ট কেস ১: columnNumber = 1
লুপ ১:

rem = 1 % 26 = 1

ans += (1 - 1 + 'A') = 'A'

columnNumber = 1 / 26 = 0 (লুপ শেষ)

রিভার্স করার পর: "A"

আউটপুট: "A" ✅

টেস্ট কেস ২: columnNumber = 28
লুপ ১:

rem = 28 % 26 = 2

ans += (2 - 1 + 'A') = 'B'

columnNumber = 28 / 26 = 1

লুপ ২:

rem = 1 % 26 = 1

ans += (1 - 1 + 'A') = 'A'

columnNumber = 1 / 26 = 0 (লুপ শেষ)

বর্তমান ans = "BA", রিভার্স করলে "AB"

আউটপুট: "AB" ✅

টেস্ট কেস ৩: columnNumber = 701
লুপ ১:

rem = 701 % 26 = 25 (কারণ 26 * 26 = 676, 701 - 676 = 25)

ans += (25 - 1 + 'A') = 'Y'

columnNumber = 701 / 26 = 26

লুপ ২:

rem = 26 % 26 = 0

ans += 'Z'

columnNumber = (26 / 26) - 1 = 0 (লুপ শেষ)

বর্তমান ans = "YZ", রিভার্স করলে "ZY"

আউটপুট: "ZY" ✅

গাণিতিকভাবে ব্যাখ্যা:
এটি বেস-২৬ কনভার্শন, তবে শূন্য-ভিত্তিক (0-based) না হয়ে এক-ভিত্তিক (1-based)। তাই যখনই rem = 0 হয়, আমরা 'Z' নিই এবং columnNumber থেকে ১ বিয়োগ করি।


Full Code:
----------
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans="";
        while(columnNumber>0)
            {
                int rem=columnNumber%26;
                
                if(rem==0)
                {
                    ans+='Z';
                    columnNumber=columnNumber/26-1;
                }
                else
                {
                    ans+=(rem-1+'A');
                
                columnNumber/=26;
            }
            }
        string result="";
        for(int i=ans.size()-1;i>=0;i--)
            {
                result+=ans[i];
            }
        return result;
    }
};
  

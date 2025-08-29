১️⃣ সমস্যা বোঝা (Problem Understanding)

প্রশ্ন:

আমাদের কাছে একটি ফ্লাওয়ারবেড আছে, যা 0 এবং 1 এর array।

0 = খালি প্লট

1 = ফ্লাওয়ার আছে

শর্ত: Adjacent (পাশের) প্লটে ফুল লাগানো যাবে না।

আমাদের জানতে হবে n ফুল নতুনভাবে লাগানো যাবে কিনা এই শর্ত মান্য করে।

উদাহরণ:

flowerbed = [1,0,0,0,1], n = 1
=> true
কেন? 0 এর মাঝে ফুল লাগানো সম্ভব (index 2)

flowerbed = [1,0,0,0,1], n = 2
=> false
কারণ একবারেই শুধু একটি ফুল লাগানো সম্ভব

২️⃣ সমাধানের জন্য চিন্তাভাবনা (Thinking Approach)

প্রথমে আমরা প্রত্যেক index চেক করব, যে এখানে ফুল লাগানো যাবে কিনা।

ফুল লাগানোর শর্ত:

বর্তমান index 0 হতে হবে

বাম পাশে (i-1) খালি অথবা array এর শুরুতে হতে হবে

ডান পাশে (i+1) খালি অথবা array এর শেষের আগে হতে হবে

যদি সব শর্ত মিলে, ফুল লাগাই (flowerbed[i] = 1) এবং n-- করি।

যদি n পৌঁছে 0, return true.

যদি সব index শেষ হয়ে যায় এবং n > 0, return false.

এই টেকনিকের নাম হচ্ছে Greedy Approach (লাভজনক নির্বাচনী পদ্ধতি): আমরা যত তাড়াতাড়ি সম্ভব ফুল লাগাই, যাতে শর্ত মেনে সর্বাধিক ফুল লাগানো যায়।

৩️⃣ কোড লাইন বাই লাইন ব্যাখ্যা
class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {


এখানে class Solution এবং member function canPlaceFlowers তৈরি করা হয়েছে।

flowerbed = input array, n = কতগুলো ফুল লাগানো হবে।

       int count=0;
       for(int i=0;i< flowerbed.size();i++)
       {
        if(flowerbed[i]==0)
        {
            count++;
        }
       }


প্রথমে আমরা খালি প্লটের সংখ্যা গুনেছি।

যদি খালি প্লটের সংখ্যা n এর থেকে ছোট হয়, তাহলে স্পষ্টভাবে false।

এটা optional, অনেক সলিউশন সরাসরি greedy লজিক দিয়ে কাজ করতে পারে।

       if(n==1&&flowerbed.size()==1&&flowerbed[0]==0) return true;


যদি array একটাই element এবং সেটা খালি হয়, এবং n=1, তাহলে সরাসরি true।

এটা Edge Case handling।

       if(count<n) return false;


যদি খালি প্লটের সংখ্যা মোট ফুলের চাহিদার থেকে কম হয়, তাহলে না লাগানো সম্ভব।

       if(count>n)
       {
           for(int i=0;i< flowerbed.size();i++)
       {


এখানে Greedy Approach loop শুরু।

       if(flowerbed[i]==0&&(i==0||flowerbed[i-1]==0)&&(i==flowerbed.size()-1||flowerbed[i+1]==0))
        {
            flowerbed[i]=1;
            n--;
             if(n==0) return true;
        }


Check শর্ত:

flowerbed[i]==0 → এই প্লট খালি

i==0 || flowerbed[i-1]==0 → বাম পাশে খালি অথবা শুরু

i==flowerbed.size()-1 || flowerbed[i+1]==0 → ডান পাশে খালি অথবা শেষ

যদি সব শর্ত মিলে:

এখানে ফুল লাগানো হয় flowerbed[i]=1

n-- করি

যদি n==0 → return true (সকল ফুল লাগানো সম্ভব)

       } 
     return n<=0;


সব loop শেষে যদি n > 0, return false।

অন্যথায়, সব ফুল লাগানো গেছে → true।

৪️⃣ কোডের মূল ধারণা (Technique & Logic)

Greedy approach: সম্ভাব্য সর্বাধিক সুবিধা (ফুল লাগানো) প্রথমে গ্রহণ।

Edge Case Handling: একমাত্র element, শুরু/শেষ প্লট, ছোট array।

Linearly traverse: O(n) complexity।

In-place modification: flowerbed পরিবর্তন করে n update করা।

৫️⃣ Test code line by line

Example 1:

flowerbed = [1,0,0,0,1], n=1


i=0 → 1 আছে, skip

i=1 → neighbor 1 আছে, skip

i=2 → 0, left 0, right 0 → place flower → n=0 → return true ✅

Example 2:

flowerbed = [1,0,0,0,1], n=2


i=2 → place flower → n=1

আর কোনো placeable plot নেই → loop শেষ → n>0 → return false ❌

৬️⃣ বাংলায় সংক্ষেপে

খালি প্লট চিহ্নিত করি

শর্ত মিলে গেলে ফুল লাগাই

n কমানো হয় প্রতিটি successful placement এ

n == 0 হলে true

সব প্লট চেক করার পর n > 0 হলে false

Full Code:
-----------

  class Solution
 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int count=0;
       for(int i=0;i< flowerbed.size();i++)
       {
        if(flowerbed[i]==0)
        {
            count++;
        }
       }
       if(n==1&&flowerbed.size()==1&&flowerbed[0]==0) return true;
       if(count<n) return false;
       if(count>n)
       {
           for(int i=0;i< flowerbed.size();i++)
       {
       if(flowerbed[i]==0/*&&n>0*/&&(i==0||flowerbed[i-1]==0)&&(i==flowerbed.size()-1||flowerbed[i+1]==0))
        {
            flowerbed[i]=1;
            n--;
             if(n==0) return true;
           
        }
       }
       } 
     return n<=0;
       
      // if(n<=0) return true;
    }
};

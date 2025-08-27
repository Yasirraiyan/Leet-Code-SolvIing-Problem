১️⃣ প্রশ্নটা কী বলছে?

আমাদের কাছে একটি array nums আছে। আমাদের করতে হবে:

যেকোনো দুইটি unmarked index i এবং j বেছে নাও।

শর্ত: 2 * nums[i] <= nums[j]

যদি শর্ত মিলে, i এবং j কে mark করো।

এই প্রক্রিয়াটি যতবার সম্ভব চালাতে হবে।

তারপর maximum marked indices এর সংখ্যা রিটার্ন করতে হবে।

উদাহরণ দিয়ে বোঝা যাক:
nums = [3,5,2,4]

sort করলে: [2,3,4,5]

smallest element = 2, largest element (যেখানে 2*2 <= ?) = 3?

pair = (2,3) → mark 2 এবং 3 → count = 2

আর কোনো valid pair নেই → answer = 2

২️⃣ কীভাবে সমাধান করার চিন্তা আসে?

ধাপে ধাপে বিশ্লেষণ:

যে operation allowed তা লক্ষ্য করো:

আমরা ছোট সংখ্যা nums[i] কে বাম দিক থেকে নেবো।

আমরা বড় সংখ্যা nums[j] বাম থেকে একটু পরে নেবো।

শর্ত: 2 * nums[i] <= nums[j]

সমাধান টেকনিক চিন্তা:

sort করার পর, আমরা সবচেয়ে ছোট সংখ্যাগুলো বাম থেকে নেবো এবং বড় সংখ্যাগুলো ডান দিক থেকে।

তারপর two pointer technique ব্যবহার করি:

i → ছোট সংখ্যা থেকে

j → i এর ডান থেকে বড় সংখ্যা থেকে

যদি শর্ত মিলে → mark i এবং j → count += 2 → i++, j++

যদি না মিলে → শুধু j++ (আরেকটা বড় সংখ্যা চেক করার জন্য)

কেন sort করলাম?

আমাদের প্রতিটি ছোট সংখ্যার জন্য সবচেয়ে ছোট "বড় number" খুঁজতে হবে যা condition পূরণ করে।

sorted হলে সহজে sequentially check করা যায়।

কেন i<nums.size()/2?

কারণ maximum possible pair formation = n/2

ছোটদের half নিলেই যথেষ্ট, বাকী সব বড় সংখ্যা check করবে।

৩️⃣ কোড লজিক (line by line)
sort(nums.begin(), nums.end()); 


array sort করলাম যাতে smallest থেকে largest elements sequentially check করা যায়।

int i=0, j=1, count=0;
vector<int> v;


i → left pointer (ছোট elements)

j → right pointer (বড় elements)

count → marked indices count

while(i < nums.size()/2 && j < nums.size()) 


শুধু left half (small numbers) নিয়ে কাজ করবো।

j সব elements check করতে পারে।

if(2 * nums[i] <= nums[j]) 


যদি pair formation condition পূরণ করে:

v.push_back(i);
v.push_back(j);
i++;
count += 2;
j++;


mark i এবং j → increment i এবং j

count += 2

else j++;


শর্ত না মিলে → শুধু j++ → next big number check

return count;


শেষ পর্যন্ত maximum marked indices return

৪️⃣ কিভাবে টেস্ট কেস অনুযায়ী কাজ করে?

Case 1: [3,5,2,4] → sort [2,3,4,5]

i=0, j=1 → 2*2 <= 3 → 4 <=3? No → j++

j=2 → 2*2 <=4 → 4 <=4 → yes → mark 0,2 → count=2 → i=1, j=3

i=1, j=3 → 2*3 <=5 → 6 <=5? No → j++

j=4 → exceeds size → stop → answer = 2

Case 2: [9,2,5,4] → sort [2,4,5,9]

i=0, j=1 → 2*2 <=4 → yes → mark → count=2 → i=1, j=2

i=1, j=2 → 2*4 <=5 → 8<=5? no → j++

j=3 → 2*4<=9 →8<=9 → yes → mark → count=4 → i=2,j=4 → stop

✅ Answer = 4

Case 3: [7,6,8] → sort [6,7,8]

i=0, j=1 → 2*6 <=7 →12<=7? No → j++

j=2 → 2*6<=8 → 12<=8? No → j++

j exceeds → stop → answer=0

৫️⃣ কোন টেকনিক ব্যবহার হয়েছে?

Two-pointer technique → left pointer smallest elements, right pointer larger elements

Sorting → smallest থেকে largest sequentially check করতে

Greedy approach → সবসময় smallest unmarked element থেকে pair formation চেষ্টা করো, তাহলে maximum marked indices পাওয়া যাবে

৬️⃣ কীভাবে তুমি প্রশ্ন পড়ে এই কোড লিখতে পারো?

প্রশ্নে বলা হয়েছে “pick two indices i,j with 2*nums[i] <= nums[j]”

maximum mark করতে হলে smallest element আগে pair করতে হবে → greedy thought

sorted করলে left pointer smallest element → right pointer largest element check

two-pointer natural fit → O(n log n) for sort + O(n) for two-pointer

💡 সংক্ষেপে:

Sort + two-pointer + greedy

প্রতি smallest element maximum possible large element এর সাথে pair করো → maximum marked indices

Full COde:
----------

class Solution 
{
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        int i=0;
        int j=1;
        int count=0;
        vector<int>v;
        sort(nums.begin(),nums.end());
        while(i<nums.size()/2&&j<nums.size())
        {
                 if(2*nums[i]<=nums[j])
                 {
                    v.push_back(i);
                    v.push_back(j);
                    i++;
                    count+=2;
                    j++;
                   
                 }
                 else
                 {
                    j++;
                 }
               //  i+=2;
                // j+=2;
        }
        return count;
    }
};

Test cases sequentially check করলে code এর correctness confirm হয়

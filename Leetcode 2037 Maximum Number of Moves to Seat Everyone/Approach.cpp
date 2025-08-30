সমস্যার সংক্ষিপ্ত ব্যাখ্যা:

তোমার কাছে nটি সিট এবং n জন শিক্ষার্থী আছে।

প্রতিটি সিটের অবস্থান seats[i] এবং শিক্ষার্থীর অবস্থান students[j] দেওয়া আছে।

তুমি প্রতিটি শিক্ষার্থীকে +/-1 করে সরাতে পারো।

লক্ষ্য: সকল শিক্ষার্থীকে এমনভাবে বসানো যাতে কেউ একই সিটে না বসে এবং মোট চলাচলের সংখ্যা কম হয়।

উদাহরণ:

seats = [3,1,5], students = [2,7,4]

যদি আমরা sorted করে মিলাই: seats = [1,3,5] এবং students = [2,4,7]

তারপর প্রথম ছাত্র 2 → 1 = 1 move, 4 → 3 = 1 move, 7 → 5 = 2 move

মোট = 4 ✅

সমাধানের approach / technique:
1️⃣ Greedy Approach (লালসা ভিত্তিক পদ্ধতি)

আমরা সর্বনিম্ন মোট চলাচল চাই।

মনে করো: কোন ছাত্রকে কোন সিটে বসানো উচিত?

সহজভাবে দেখা যায়, ছাত্রদের এবং সিটদের উভয়কে ছোট থেকে বড় ক্রমে সাজালে আমরা সর্বনিম্ন দূরত্ব পাবো।

কারণ বড় অবস্থানের ছাত্রকে ছোট সিটে দিলে অপ্রয়োজনীয় বড় move হবে।

Step-by-step ধারণা:

seats এবং students sort করা।

প্রতিটি sorted অবস্থানের i-তম ছাত্রকে i-তম সিটে বসানো।

abs(seats[i] - students[i]) যোগ করা।

এটাই Minimum Moves।

2️⃣ কোড বিশ্লেষণ
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        sort(seats.begin(), seats.end());         // Step 1: সিটগুলো ছোট থেকে বড় ক্রমে সাজানো
        sort(students.begin(), students.end());   // Step 2: ছাত্রদের অবস্থান ছোট থেকে বড় ক্রমে সাজানো
        int move = 0;                              // মোট move শুরুতে 0
        for(int j = 0; j < seats.size(); j++)      // Step 3: সব শিক্ষার্থী loop
        {
           move += abs(seats[j] - students[j]);    // Step 4: দূরত্ব যোগ করা
        }
        return move;                               // Step 5: মোট move return
    }
};

3️⃣ কেন accepted হলো

সমস্যার শর্ত অনুযায়ী n <= 100, তাই sorting O(n log n) এবং loop O(n) পুরোপুরি ঠিক আছে।

Greedy approach সব ক্ষেত্রে সর্বনিম্ন total moves দেয়।

এখানে আর কোনো overlap problem নেই কারণ sorted matching guarantee দেয় min sum of absolute differences।

4️⃣ কিভাবে বুঝবে কোন technique ব্যবহার হবে

প্রশ্নে আছে: সর্বনিম্ন যোগফল (sum of moves)।

আমাদের move হলো distance, অর্থাৎ |x - y|।

যখন আমাদের দুটো array মিলাতে হবে যাতে absolute differences কম হয় → Sorting + Greedy সবচেয়ে সাধারণ।

সাধারণ sense: বড় ছাত্রকে ছোট সিটে দিলে বড় distance হবে, তাই sorted matching logical।

5️⃣ কিভাবে test-case দিয়ে পরীক্ষা করবে
Example 1:
seats = [3,1,5];
students = [2,7,4];
Output: 4


Sorted:
seats = [1,3,5], students = [2,4,7]

|1-2| = 1

|3-4| = 1

|5-7| = 2

মোট = 4 ✅

Example 2:
seats = [2,2,6,6];
students = [1,3,2,6];
Output: 4


Sorted:
seats = [2,2,6,6], students = [1,2,3,6]

|2-1| = 1

|2-2| = 0

|6-3| = 3

|6-6| = 0

মোট = 4 ✅

6️⃣ Bangla Summary

Problem type: minimum total distance / moves → Greedy

Technique: Sort + Pairwise match

Why it works: sorted array মিলালে sum of absolute differences minimum হয়

Code structure:

Sort seats

Sort students

Loop এবং absolute difference যোগ করা

Return sum

Full Code:
------------

  class Solution 
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int move=0;
        for(int j=0;j<seats.size();j++)
        {
           move+=abs(seats[j]-students[j]);
        }
        return move;
    }
};

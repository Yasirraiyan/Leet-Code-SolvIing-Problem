Problem Understanding (কিভাবে সমাধান ভাবা যায়)

Question:

আমাদের কাছে even length skill array আছে।

আমাদের কাজ: খেলোয়াড়দের দুটি করে team বানাতে হবে যাতে প্রতিটি team's total skill সমান হয়।

Team chemistry = skill1 * skill2

Return all teams chemistry sum। যদি সম্ভব না হয়, return -1।

Example 1:
skill = [3,2,5,1,3,4]

Sort করলে: [1,2,3,3,4,5]

Target team sum: 1+5=6, 2+4=6, 3+3=6 → possible

Chemistry sum: 15 + 24 + 3*3 = 22 → Output

Observation:

To make all teams with equal sum, smallest + largest = sum of a team।

একইভাবে, second smallest + second largest, … must match।

Technique used: Two-pointer approach + sorting.

Solution Approach (তুমি কিভাবে ভাবলে)

Sort the array → Two-pointer easier।

Determine target sum → smallest + largest = total sum per team।

Check if perfect pairing possible → Two-pointer check: (v[0]+v[n-1], v[1]+v[n-2], …) সব same?

Compute chemistry → Pair multiply and sum।

Technique Summary:

Sorting + Two-pointer technique

Mathematical check: smallest + largest = team sum

Why accepted:

Sorting: O(n log n)

Two-pointer check: O(n)

Space: O(1) extra

Constraints satisfy → Efficient solution

Line-by-line Code Explanation (Bangla)
class Solution
{
public:
    bool Perfect(vector<int>&v,long long dominate)
    {
        sort(v.begin(),v.end()); // Step 1: array sort
        int low=0;
        int high=v.size()-1;
        while(low<high)
        {
            long long ans=(long long) v[low]+v[high]; // pair sum
            if(ans!=dominate) // যদি pair sum != target
                return false; // return false → cannot make equal teams
            low++;
            high--;
        } 
        return true; // সব pair sum == target → possible
    }

    long long dividePlayers(vector<int>& skill)
    {
        sort(skill.begin(),skill.end()); // Step 1: array sort
        long long ds = skill[0]+skill[skill.size()-1]; // target sum for each team
        long long ans=0;
        int low=0;
        int high=skill.size()-1;

        if (!Perfect(skill, ds)) // check if perfect pairing possible
        {
            return -1; // cannot form perfect teams
        }

        while(low<high)
        {
            ans+=(long long) skill[low]*skill[high]; // chemistry sum
            low++;
            high--;
        } 

        return ans; // return total chemistry sum
    }
};

Test Case Walkthrough

Test case 1: [3,2,5,1,3,4]

Sort → [1,2,3,3,4,5]

Target sum → 1+5 = 6

Perfect check (Two-pointer):

1+5=6 ✅

2+4=6 ✅

3+3=6 ✅ → True

Chemistry sum calculation:

15=5, 24=8, 3*3=9

Total = 22 ✅

Test case 2: [1,1,2,3]

Sort → [1,1,2,3]

Target sum → 1+3=4

Perfect check:

1+3=4 ✅

1+2=3 ❌ (!= target)

Return -1 ✅

Key Points / Bangla Notes

Why sort?

সহজে smallest+largest pair করা যায়।

Without sorting, checking all pair combinations inefficient।

Two-pointer technique

Low pointer → smallest

High pointer → largest

Move inward → O(n) check

Why long long?

Skill max 1000, n up to 10^5 → product বড় হতে পারে।

Complexity Analysis:

Time: O(n log n) for sort + O(n) for check → O(n log n) overall

Space: O(1) extra (besides input)

Technique Name:

Sorting + Two-pointer approach + Mathematical check

💡 Summary of Approach in Bangla:

Sort করা → Two-pointer easier

Determine team sum = smallest+largest

Perfect check → সব pair sum একই কি না

যদি possible → chemistry sum calculate

Output chemistry sum বা -1

Full Code:
----------

  class Solution
 {
public:
 bool Perfect(vector<int>&v,long long dominate)
 {
       sort(v.begin(),v.end());
       int ds=v[0]+v[v.size()-1];
       int low=0;
       int high=v.size()-1;
       long long ans=0;
       while(low<high)
       {
        long long ans=(long long) v[low]+v[high];
        if(ans!=dominate)
        return false;
        low++;
        high--;
       } 
       return true;
 }
    long long dividePlayers(vector<int>& skill)
     {
       sort(skill.begin(),skill.end());
      long long ds=skill[0]+skill[skill.size()-1];
      long long ans=0;
       int low=0;
       int high=skill.size()-1;
         if (!Perfect(skill, ds))
          {
            return -1; // cannot form perfect teams
        }
      if(Perfect(skill,ds))
      {
          while(low<high)
       {
      ans+=(long long) skill[low]*skill[high];
      
        low++;
        high--;
       } 
      }
      return ans;
    }
};

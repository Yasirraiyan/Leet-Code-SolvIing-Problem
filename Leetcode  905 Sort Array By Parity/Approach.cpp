Amar 1 ta array ase jar nam nums. Amar 1 ta array return korte hbe jei array er first e even numbers thakbe ar last e odd thakbe.
So, first e 1 ta vector aerray create kori ans.
1 ta for loop chalai i=0 to i<nums.size() porjonto.Nums array traverse kori'
Even test kori:
----------------
   if(nums[i]%2==0)
  true hoy tbe insert kori array r surute ba  begin e so,
  ans.insert(ans.begin(),nums[i]);

ans.push_front() kaj korbe na karon vector library te push_front() method nai.

Odd Test kori:
--------------
   if(nums[i]%2!=0)
  true hoy taile seshe thakbe odd so,
ans.push_back(nums[i]);
amr chaise array ta,
So,
return ans.

Full Code:
-----------

  #include<vector>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]%2==0)
        {
          ans.insert(ans.begin(),nums[i]);
        }
        if(nums[i]%2!=0)
        {
          ans.push_back(nums[i]);
        }
       } 
       return ans;
    }
};
  

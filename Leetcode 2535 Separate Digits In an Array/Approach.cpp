Amar 1 ta array ase jetar moddhe kisu number ase. Amar chaise ei array r number gular digit separate kore 1 ta array akare.
  So, 1 st e ami 1 ta function create kori digit separate er jonno 1 ta number er. Eta ami main function e call korbo ete subidha hoy.
  So, function is:
vector<int> separatedigit(int n)
  {
    vector<int>reserve;
    if (n == 0)
     {
            reserve.push_back(0);
        }
    while(n>0)
    {
        int rem=n%10;
        reserve.push_back(rem);
        n=n/10;

    }
  //  n=n/10;
   std::reverse(reserve.begin(), reserve.end());
    return reserve;
  }
Erpor main function e 1st e 1 ra vector create kori ans.Karon amar vector array return korbo. 1 ta for loop chalai i=0 i<n porjonto array traverse kori.Then function call kore push kori vector e.
   for(int i=0;i<nums.size();i++)
        {
            //result=separatedigit(i);
            vector<int>result=separatedigit(nums[i]);
          //ans.push_back(result);
          ans.insert(ans.end(), result.begin(), result.end());
        }
return kori ans.

  Full code:
------------

  #include<vector>
class Solution {
public:
  vector<int> separatedigit(int n)
  {
    vector<int>reserve;
    if (n == 0)
     {
            reserve.push_back(0);
        }
    while(n>0)
    {
        int rem=n%10;
        reserve.push_back(rem);
        n=n/10;

    }
  //  n=n/10;
   std::reverse(reserve.begin(), reserve.end());
    return reserve;
  }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        //vector<int>result;
        
        for(int i=0;i<nums.size();i++)
        {
            //result=separatedigit(i);
            vector<int>result=separatedigit(nums[i]);
          //ans.push_back(result);
          ans.insert(ans.end(), result.begin(), result.end());
        }
        return ans;

    }
};

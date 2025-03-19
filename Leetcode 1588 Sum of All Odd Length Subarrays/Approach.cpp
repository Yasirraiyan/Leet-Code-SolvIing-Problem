Main function er baire ekta function banai sumber kori aary e
initial sum=0;
1 ta for loop chlai i=0 to i<n porjo tyo i++ kor
  array traverse koroi
sum+=arr[i] kor
return kori sum
Helper Function:
---------------------
  int sum(vector<int>&nums)
  {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
      sum+=nums[i];
    }
    return sum;
  }
Sub array print:
----------------
  [1,2,3] er sub array gula:
[1, 2, 3], তাহলে এর উপঅ্যারে হবে:

একক উপাদান: [1], [2], [3]

একাধিক উপাদান: [1, 2], [2, 3]

পুরো অ্যারে: [1, 2, 3]
  for loop chalai i=0 i<n porjonto array traverse kor
2 ta suchok suru shesh 1 er jonno 0,1 j=0 to j<=i 
  j=i;j<n porjono
as i,j er moddhe sob print tai
nested for loop nei
k=i to k<=j kori
length [0,1,2] =2-0+1=3=j-i+1
  odd tes
 if((j-i+1)%2!=0) 
subaaaray te push
  if((j-i+1)%2!=0)
            {
                  vector<int> tempSubarray;
            
            
            for(int k=i;k<=j;k++)
            {
             //vector<int> tempSubarray;
            
                 tempSubarray.push_back(arr[k]);
              
            }
Sum ber kori function call:
----------------------------
   result+=sum(tempSubarray);
return kori result;

Full Code:
--------------

  class Solution 
{
public:
  int sum(vector<int>&nums)
  {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
      sum+=nums[i];
    }
    return sum;
  }
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
      int result=0;
        for(int i=0;i<arr.size();i++)
        {
          for(int j=i;j<arr.size();j++)
          {
            if((j-i+1)%2!=0)
            {
                  vector<int> tempSubarray;
            
            
            for(int k=i;k<=j;k++)
            {
             //vector<int> tempSubarray;
            
                 tempSubarray.push_back(arr[k]);
              
            }
            result+=sum(tempSubarray);
            }
          }
        }
        return result;
    }
};

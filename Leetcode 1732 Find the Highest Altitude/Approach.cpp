
Ami ekhane prefix sum er concept nie solve korsi:
-------------------------------------------------
As amar max chaise tai findmax()function banai array r maximum bair korbo ja helper function man Function er baire

Helper Function:
----------------
  int findmax(vector<int>&arr)
    {
      int max=arr[0];
      for(int i=1;i<arr.size();i++)
     {
      if(arr[i]>max)
      {
        max=arr[i];
      }
     }
     return max;
    }
First Solution approach:
-------------------------
  Amar 1 ta array ase jar nam gain
Amar notun array lagbe jate oi array r 0 index er man 0
Abar notun array r 1 index gain er 0 index er man er soman 
Kintu notun array r 2 no index er man oi gain array r 0 r 1 er man er sum er man er soman 
Abar notun array r 3 no index er man oi gain array r 0 theke 2 porjonto index er stored valuer sum er man er soman

So,
Ami ekhane prefix sum approach nisi

Prefix Sum approach:
---------------------
  First e ami 1 ta array create kori reserve jar lengh (n+1) .Ekhane n=gain.size()
  initial reserve[0]=0 karon 1 st e prefix sum e array first index value thake 0;
   reserve[1]=reserve[0]+gain[0]
reserve[2]=reserve[1]+gain[1]
  j hishabe nile j=2 hoy taile 1=j-1 
  So,
  reserve[j]=reserve[j-1]+gain[j-1];
  So, 
  as reserve[0]=0 ja initial nisi
    tai  0 index traverse er dorkar nai
So,
  1 ta for loop chalabo j=1 threke j<=gain.size() porjonto j++ ;[gain array traverse kori]
  ei loop er moddhe 
   reserve[j]=gain[j-1]+reserve[j-1]
  as amar int return korbo sudhu max tai 1 ta variable nei abns jate helper function findmax() call kore value rakhbo last e return korbo
  So,
  findmax() helper function call kori and ans e rakhi
So,
   ans=findmax(reserve);
return kori ans

Main Function:
--------------
  int largestAltitude(vector<int>&gain)
    {
      int n=gain.size();
      vector<int>reserve(n+1);
       reserve[0]=0;
       int ans;
       for(int j=1;j<=n;j++)
       {
        reserve[j]=reserve[j-1]+gain[j-1];
        
       }
       ans=findmax(reserve);
       return ans;

Full Code:
-----------
  class Solution
 {
  public:
    int findmax(vector<int>&arr)
    {
      int max=arr[0];
      for(int i=1;i<arr.size();i++)
     {
      if(arr[i]>max)
      {
        max=arr[i];
      }
     }
     return max;
    }
    int largestAltitude(vector<int>&gain)
    {
      int n=gain.size();
      vector<int>reserve(n+1);
       reserve[0]=0;
       int ans;
       for(int j=1;j<=n;j++)
       {
        reserve[j]=reserve[j-1]+gain[j-1];
        
       }
       ans=findmax(reserve);
       return ans;
    }
 };

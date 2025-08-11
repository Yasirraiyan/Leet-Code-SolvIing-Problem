class Solution 
{
public:
int One(int n)
{
  int count=0;
  while(n>0)
  {
    int rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
  }
  return count;
}
   static  bool Compare(int a,int b)
   {
     Solution sol;  
     int a1=sol.One(a);
     int b1=sol.One(b);
    if(a1==b1)
    {
      return a<b;
    }
     return a1<b1;
   }
    vector<int> sortByBits(vector<int>& arr)
     {
      sort(arr.begin(),arr.end(),Compare);
      return arr;
    }
};

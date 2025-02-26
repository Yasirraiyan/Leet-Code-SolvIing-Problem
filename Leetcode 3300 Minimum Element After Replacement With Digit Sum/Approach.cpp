Amar 1 ta array ase integer er. Ei array index e jei value store ase tader digit sum ber kore maximum ta return korte hbe.

  First e 1 ta helper function create kori digit sum calculate er jonno. Ete amar kaj korete subidha hbe.
   ei function e 1 ta while loop chalai where n>0
   ekta variable nei sum ja initial 0.
  sum+=n%10; kori loop er vitore n=n/10 kori.
  return kori sum;
  the loop is:
----------------
  while(n>0)
    {
        sum+=n%10;
        n=n/10;
    }

helper function:
----------------
  int digitsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n=n/10;
    }
   // n=n/10;
    return sum;
}
Ekhn main function e 1 ta array vector create kori ans name etate ami digit sum store korbo function call kore .Ete amar max ber korte subidha hbe.
1 ta for loop chalai i=0 to i<n porjonto given array nums ke traverse kori
then digit sum function call kori and ans array te push kori.
  
code is:
--------
  vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(digitsum(nums[i]));
        }
Amar chaise minumum ta.
  Tai initial min dhori ans[0].    Eta die compare kori aray r onno valuer sathe then update kori if needed.
  1 ta for loop chalai j=0 to  j<ans.size() porjonto j++ kori
  check kori 
   if(ans[j]<min)
            {
                min=ans[j];
            }
chaise min
tai return kori min.
Full code:
----------

  class Solution {
public:
int digitsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n=n/10;
    }
   // n=n/10;
    return sum;
}
    int minElement(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(digitsum(nums[i]));
        }
        int min=ans[0];
        for(int j=0;j<ans.size();j++)
        {
            if(ans[j]<min)
            {
                min=ans[j];
            }

        }
        return min;
        
    }
};

class Solution 
{
public:
    bool isBalanced(string num)
{
      int ans1=0;
      int ans2=0;
      bool isbalanced=true;
       for(int i=0;i<num.size();i++)
       {
        if(i%2==0)
        {
          ans1+=num[i]-'0';
        }
        if(i%2!=0)
        {
          ans2+=num[i]-'0';
        }
       } 
       if(ans1!=ans2)
       {
        isbalanced=false;
       }
       return isbalanced;
    }
};

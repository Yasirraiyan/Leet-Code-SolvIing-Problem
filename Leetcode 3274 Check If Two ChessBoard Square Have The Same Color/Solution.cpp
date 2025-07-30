class Solution {
public:
 int sum(string s)
 {
  int sum=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]>='a'&&s[i]<='z')
    {
    
      sum+=s[i]-'a'+1;
    }
    if(isdigit(s[i]))
    {
      sum+=s[i]-'0';
    }
  return sum;
 }
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int sum1=sum(coordinate1);
        int sum2=sum(coordinate2);
        bool check=false;
        if((sum1%2==0&&sum2%2==0)||(sum1%2!=0&&sum2%2!=0))
        {
          check=true;
        }
        return check;
    }
};

class Solution 
{
public:
   string convertbinary(int n)
   {
    string ans="";
      if (n == 0) return "0";
    while(n>0)
    {
        int rem=n%2;
        ans+=to_string(rem);
        n=n/2;
    }
    string result="";
    for(int i=ans.size()-1;i>=0;i--)
    {
        result+=ans[i];
    }
    return result;
   }
    string convertDateToBinary(string date) 
    {
       string c="";
       string ans="";
       for(int i=0;i<date.size();i++)
       {
       // c+=date[i];
        if(date[i]==' '||date[i]=='-')
        {
            if(!c.empty())
            {
            int a=stoi(c);
            string b=convertbinary(a);
            ans+=b;
            c="";
            }
        
        if(date[i]=='-')
        {
            ans+=date[i];
        }
        else if (date[i] == ' ')
               {
                   ans += ' ';
               }
       }
             else
           {
               c += date[i];  // শুধুমাত্র সংখ্যাগুলো জমা
           }
       }
        if(!c.empty())
            {
            int a=stoi(c);
            string b=convertbinary(a);
            ans+=b;
            }
       return ans;
    }
};

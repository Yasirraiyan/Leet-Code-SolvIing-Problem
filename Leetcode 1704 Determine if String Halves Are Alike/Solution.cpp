class Solution 
{
public:
   bool vowel(char s)
   {
    bool findvowel=false;
    
      if((s=='a')||(s=='e')||(s=='o')||(s=='i')||(s=='u')||(s=='A')||(s=='E')||(s=='O')||(s=='I')||(s=='U'))
      {
        findvowel=true;
      }
    
    return findvowel;
   }
    bool halvesAreAlike(string s) {
        bool alike=true;
        string a="";
        string b="";
      
        for(int j=0;j<s.size()/2;j++)
        {
          a+=s[j];
        }
        for(int k=s.size()/2;k<s.size();k++)
        {
          b+=s[k];
        }
        int count1=0;
        int count2=0;
        for(int m=0;m<a.size();m++)
        {
          if(vowel(a[m]))
          {
            count1++;
          }
        }
        for(int p=0;p<b.size();p++)
        {
          if(vowel(b[p]))
          {
            count2++;
          }
        }
        if(count1!=count2)
        {
          alike=false;
        }
        return alike;
    }
};

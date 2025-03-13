Amar 1 ta string ase ei string k equal 2 part e divide korbo.Kore check korbo both part e vowel er count same kina. same hoile true. naile false.

  1 st e 1 ta function banai findvowel ja bool type ja initial false.Eta diye test korbo j vowel ase kina. Etar parameter char s.
  check kori condition both for upper and lower case for 5 vowels :a,e,i,o,u
  and :A,E,I,O,U;
if((s=='a')||(s=='e')||(s=='i')||(s=='o')||(s=='u')||(s=='A')||(s=='E')||(s=='I')||(s=='O')||(s=='U'))
  hoile 
    findvowel=true;
return kori findvowel

Helper Function:
-----------------

   bool vowel(char s)
   {
    bool findvowel=false;
    
    
    
    if((s=='a')||(s=='e')||(s=='i')||(s=='o')||(s=='u')||(s=='A')||(s=='E')||(s=='I')||(s=='O')||(s=='U'))
      {
        findvowel=true;
      }
    
    return findvowel;
   }

Main Function e amar chaise ekta string k duita equal part e divide korle vowel count same kina
1 ta variable nei bool alike ja initial true.Eta diye test korbo alike kina
as 2 part e vag korbo equal e
2 ta variable nei string type a,b ja initial empty ba 0 ei duitay half of string rakhbo
1 ta for loop chalai i=0 to i<s.size()/2 porjonti i++ kori karon first half test karon jodi string size 4 hoy index(0,1,2,3) first half index(0,1) i=0 i<2 means i<4/2 means i<s.size()/2
  a+=s[i] kori
alada for loop chalai j=s.size()/2 to j<s.size() porjonto j++ kori karon 2nd  half test karon jodi string size 4 hoy index(0,1,2,3) second half index(2,3) j=2 mane j=4/2 or j=s.size()/2 to j<4 means j<s.size()
b+=s[j] kori
a b te vowel count kori 
ei jonno 2 ta variable nei count1,count2 jara initial 0
  count1 e a er vowel r count2 te b er vowel
a er vowel count e a traverse kori'
  so, 
  1 ta for loop chalai k=0 to k<a.size() porjonto k++ kori
  vowel function call kore check kori true kina hoile count1++ kori'
  So,
  if(vowel(a[k]))
          {
            count1++;
          }

 aro 1 ta for loop chalai alada  m=0 to m<b.size() porjonto m++ kori
  vowel function call kore check kori true kina hoile count2++ kori'

   So,
   for(int m=0;m<b.size();m++)
        {
          if(vowel(b[m]))
          {
            count2++;
          }
        }
check 2 ta count same kina
check for not same because initial value of bool alike is true
opposite value check for reduce runtime and quick exit so, time complexity reduced
not same hole 
alike false;
So,
   if(count1!=count2)
        {
          alike=false;
        }
return alike;

Full Code:
-----------

  class Solution 
{
public:
   bool vowel(char s)
   {
    bool findvowel=false;
    
    
    
    if((s=='a')||(s=='e')||(s=='i')||(s=='o')||(s=='u')||(s=='A')||(s=='E')||(s=='I')||(s=='O')||(s=='U'))
      {
        findvowel=true;
      }
    
    return findvowel;
   }
    bool halvesAreAlike(string s) 
    {
        bool alike=true;
        string a="";
        string b="";
      
        for(int i=0;i<s.size()/2;i++)
        {
          a+=s[i];
        }
        for(int j=s.size()/2;j<s.size();j++)
        {
          b+=s[j];
        }
        int count1=0;
        int count2=0;
        for(int k=0;k<a.size();k++)
        {
          if(vowel(a[k]))
          {
            count1++;
          }
        }
        for(int m=0;m<b.size();m++)
        {
          if(vowel(b[m]))
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
  

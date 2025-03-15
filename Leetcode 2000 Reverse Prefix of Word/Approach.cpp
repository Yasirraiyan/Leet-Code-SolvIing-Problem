Amar 1 ta string ase r 1 ta character ase .Ei character string er jei index e pawa jay 0 theke oi index if the index is i form a string from 0 to i.Eta reverse korbo 
baki gula same thakbe '

Exa:
------

  Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

  1 ta variable nei reverse1 etay reverse string rakhbo
1 ta variable nei find index etay ch jei index e ase ta rakhbo.
1 ta for loop chalai i=0 to i<word.size() porjonto i++ kori eta diye string traverse kori
check character find:
----------------------
  if(word[i]==ch)
      {
        findindex=i;
        break;
      }

Loop for finding index:
------------------------

   for(int i=0;i<word.size();i++)
     {
      if(word[i]==ch)
      {
        findindex=i;
        break;
      }
    
     }
Traverse string:
-----------------
  From 0 to traverse index
  1 ta for loop chalai j=findindex to j>=0 j--
  1 ta variable nei string type reserve1
   reserve1+=word[j] kori

  Loop is:
------------

  for(int j=findindex;j>=0;j--)
     {
      reserve1+=word[j];
     }

Traverse string from next index of target to end:
-----------------------------------------------------

  1 ta for loop chala k=findindex+1 to k<word.size();k++ kori
  1 ta variable nei reserve2 ja string type etay baki tuku traverse kore rakhbo
karon amr reverse er sathe bakituku same ja ase ta add korte hbe
So,
 for(int k=findindex+1;k<word.size();k++)
     {
             reserve2+=word[k];
     }

Final ans er jonno 1 ta variable nei string ans etay reserve1,reserve2 er sum string rakhi 
So,
   ans+=reserve1+reserve2;
Jodi character find na hoy 
taile word return kori

So,
   else
     {
        return word;
     }
Finally return kori ans

Full Code:
----------

  class Solution 
{
public:
    string reversePrefix(string word, char ch) 
    {
      int findindex=-1;
      string reserve1="";
      string reserve2="";
      string ans="";
     for(int i=0;i<word.size();i++)
     {
      if(word[i]==ch)
      {
        findindex=i;
        break;
      }
    
     }
     if(findindex!=-1)
     {
     for(int j=findindex;j>=0;j--)
     {
      reserve1+=word[j];
     }
     
     for(int k=findindex+1;k<word.size();k++)
     {
             reserve2+=word[k];
     }
     
     ans+=reserve1+reserve2;
     }
     else
     {
        return word;
     }
     return ans;
    }
};

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

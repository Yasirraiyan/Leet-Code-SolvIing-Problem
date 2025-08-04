class Solution 
{
public:
    bool detectCapitalUse(string word)
     {
    int upper=0;

    int lower=0;
    for(int i=0;i<word.size();i++)
    {
      if(isupper(word[i]))
      {
        upper++;
      }
       if(islower(word[i]))
      {
        lower++;
      }
    }
    bool detect=false;
    if(upper==word.size()||lower==word.size()||((upper==1)&&(isupper(word[0])&&lower==word.size()-1)))
    {
      detect=true;
    }
    return detect;
    }
};

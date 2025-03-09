class Solution 
{
public:
  bool palindrome(string s)
  {
    bool palindrome=false;
    string ans1="";
    string ans2="";
    for(int i=0;i<s.size();i++)
    {
      ans1+=s[i];
    }
     for(int j=s.size()-1;j>=0;j--)
    {
      ans2+=s[j];
    }
    if(ans1==ans2)
    {
      palindrome=true;
    }
    return palindrome;
  }
    string firstPalindrome(vector<string>& words) 
    {
      vector<string>reserve;
      string result="";
        for(int k=0;k<words.size();k++)
        {
            if(palindrome(words[k]))
            {
              reserve.push_back(words[k]);
            }
        }
        for(int m=0;m<reserve.size();m++)
        {
          result=reserve[m];
          break;
        }
        return result;
    }
};

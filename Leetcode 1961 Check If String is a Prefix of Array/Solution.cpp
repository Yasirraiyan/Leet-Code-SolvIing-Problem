class Solution 
{
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string ans="";
        bool prefix=false;
        for(int i=0;i<words.size();i++)
        {
          ans+=words[i];
          if(ans==s)
        {
             prefix=true;
             break;
        }
        }
       // if(ans==s)
       // {
            // prefix=true;
      //  }
        return prefix;
    }
};

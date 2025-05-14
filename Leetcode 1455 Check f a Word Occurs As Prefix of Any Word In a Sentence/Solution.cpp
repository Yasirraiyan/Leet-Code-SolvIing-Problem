class Solution 
{
public:
   bool CheckPrefix(string a,string  b)
   {
    bool isprefix=false;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
      ans+=a[i];
      if(ans==b)
      {
        isprefix=true;
        break;
      }
    }
    return isprefix;
   }
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans=-1;
        stringstream ss(sentence);
        string word;
        vector<string>reserve;
        while(ss>>word)
        {
             reserve.push_back(word);
        }
        for(int j=0;j<reserve.size();j++)
        {
          if(CheckPrefix(reserve[j],searchWord))
          {
            ans=j+1;
            break;
          }
        }
        return ans;
    }
};

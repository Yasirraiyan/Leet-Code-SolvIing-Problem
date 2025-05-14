class Solution 
{
public:
    bool digitCount(string num) 
    {
      unordered_map<char,int>freq;
      bool type=true;
      for(int i=0;i<num.size();i++)
      {
        freq[num[i]]++;
      }
      for(int j=0;j<num.size();j++)
      {
        if(freq['0'+j]!=num[j]-'0')
        {
          type=false;
          break;
        }
      }
      return type;
    }
};

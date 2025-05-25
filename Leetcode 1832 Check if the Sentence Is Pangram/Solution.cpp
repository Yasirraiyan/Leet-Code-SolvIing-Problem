class Solution 
{
public:
    bool checkIfPangram(string sentence) 
    {
        string reserve="abcdefghijklmnopqrstuvwxyz";
        unordered_map<char,int>freq;
        unordered_set<char>set1;
        bool check=true;
        for(int i=0;i<reserve.size();i++)
        {
          set1.insert(reserve[i]);
        }
        for(int j=0;j<sentence.size();j++)
        {
          freq[sentence[j]]++;
          if(set1.find(sentence[j])==set1.end())
          {
             check=false;
          }
         
        }
        
        for(char ch:set1)
        {
          if(freq[ch]<1)
          {
            check=false;
            break;
          }
        }
        return check;
    }
};

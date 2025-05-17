class Solution 
{
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        int count=0;
        unordered_map<string,int>freq1;
        unordered_map<string,int>freq2;
        for(int i=0;i<words1.size();i++)
        {
          freq1[words1[i]]++;
        }
        for(int j=0;j<words2.size();j++)
        {
          freq2[words2[j]]++;
        }
        for(int k=0;k<words1.size();k++)
        {
          for(int m=0;m<words2.size();m++)
          {
            if(words1[k]==words2[m])
            {
              if((freq1[words1[k]]==1)&&(freq2[words2[m]]==1))
              {
                count++;
              }
            }
          }
        }
        return count;
    }
};

class Solution 
{
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
      vector<string> words1;

    stringstream ss1(s1);  
    string word1;

    while (ss1>> word1) {       
        words1.push_back(word1); 
    }
  vector<string> words2;

    stringstream ss2(s2);  
    string word2;

    while (ss2>> word2) 
    {       
        words2.push_back(word2); 
    }  
    unordered_set<string>set1;
    unordered_set<string>set2;
    unordered_map<string,int>freq1;
     unordered_map<string,int>freq2;
    for(int i=0;i<words1.size();i++)
    {
      set1.insert(words1[i]);
      freq1[words1[i]]++;
    }
    for(int j=0;j<words2.size();j++)
    {
      set2.insert(words2[j]);
      freq2[words2[j]]++;
    }
    vector<string>ans;
    for(int k=0;k<words2.size();k++)
    {
      if((set1.find(words2[k])==set1.end())&&(freq2[words2[k]]==1))
      {
          ans.push_back(words2[k]);
      }
    }
    for(int m=0;m<words1.size();m++)
    {
      if(set2.find(words1[m])==set2.end()&&(freq1[words1[m]]==1))
      {
          ans.push_back(words1[m]);
      }
    }
return ans;
    }
};

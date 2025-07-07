class Solution 
{
public:
    int findMax(vector<int>&arr)
     {
    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); ++i)
     {
        if (arr[i] > maxElement) 
        {
            maxElement = arr[i]; 
        }
    }
    return maxElement;
}
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
       string cleanText = "";
for (char c : paragraph)
 {
    if (isalpha(c))
     {
        cleanText += tolower(c); 
    } else 
    {
        cleanText += ' ';
    }
}
vector<string> words;
    stringstream ss(cleanText);
    string word;
    while (ss >> word) 
    {
        words.push_back(word);
    }
    unordered_set<string>set1;
    for(int i=0;i<banned.size();i++)
    {
      set1.insert(banned[i]);
    }
    vector<string>v;
    for(int j=0;j<words.size();j++)
    {
      if(set1.find(words[j])==set1.end())
      {
        v.push_back(words[j]);
      }
    }
    unordered_map<string,int>freq;
    for(int k=0;k<v.size();k++)
    {
      freq[v[k]]++;
    }
    vector<int>f;
    for(auto it:freq)
    {
      f.push_back(it.second);
    }
    int maxfreq=findMax(f);
    string ans="";
    for(auto it:freq)
    {
      if(it.second==maxfreq)
      {
           ans+=it.first;
           break;
      }
    }
    return ans;
    }
};

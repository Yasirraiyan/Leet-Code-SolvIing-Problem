class Solution
 {
public:
 vector<string> reverse(vector<string>&vs)
 {
    int low=0;
    int high=vs.size()-1;
    while(low<high)
    {
        swap(vs[low],vs[high]);
        low++;
        high--;
    }
    return vs;
 }
    string reverseWords(string s)
     {
          string word;  
        stringstream ss(s);
        vector<string>words;
        while(ss>>word)
        {
            words.push_back(word);
        }
      reverse(words);
         string reversedSentence;
    for(int i = 0; i < words.size(); i++)
     {
        reversedSentence += words[i];
        if(i != words.size() - 1) reversedSentence += " "; // add space between words
    }
    return reversedSentence;
    }
};

class Solution
{
public:
    int lengthOfLastWord(string s) 
{
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word)
            {
                words.push_back(word);
            }
        string a=words[words.size()-1];
        int count=0;
        for(int i=0;i<a.size();i++)
            {
                count++;
            }
        return count;
    }
};

class Solution 
{
public:
string Reverse(string a)
{
    int i=0;
    int j=a.size()-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
    return a;
}
    string reverseWords(string s) 
    {
        stringstream ss(s);
        vector<string>v;
        string word;
        while(ss>>word)
        {
            v.push_back(word);
        }
        for(int k=0;k<v.size();k++)
        {
            v[k]=Reverse(v[k]);
        }
        string ans="";
       for(int j = 0; j < v.size(); j++)
        {
            if(j > 0) ans += " "; // previous word-এর পরে space
            ans += v[j];
        }
return ans;
    }
};

class Solution
 {
public:
 string Convert(string s)
 {
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        ans+=to_string(s[i]-'a'+1);
    }
    return ans;
 }
 int CalculateDigitSum(string s)
 {
    int sum=0;
    //int n=stoi(s);
     for(char c : s) 
     {
            sum += (c - '0');  // directly sum digits
        }
   
    return sum;
 }
    int getLucky(string s, int k) {
        int count=0;
        int ans=0;
        string str=Convert(s);
        while(count<k)
        {
          ans=CalculateDigitSum(str);
         str = to_string(ans);    
          count++;
          if(count==k)
          break;
        }
        return ans;
    }
};

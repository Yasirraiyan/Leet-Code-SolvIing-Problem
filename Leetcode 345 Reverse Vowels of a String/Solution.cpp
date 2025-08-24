class Solution
 {
public:
 bool TestVowel(char a)
 {
    if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||
        a=='A'||a=='E'||a=='I'||a=='O'||a=='U') 
        {
        return true;
    }
    return false;
 }
 void swap(char &a,char &b)
 {
    char temp=a;
    a=b;
    b=temp;
 }
    string reverseVowels(string s) 
    {
        int low=0;
        int high=s.size()-1;
        while(low<high)
        {
             while(low<high&&!TestVowel(s[low])) low++;
              while(low<high&&!TestVowel(s[high])) high--;
            if(/*TestVowel(s[low])&&TestVowel(s[high]&&*/low<high)
            {
               swap(s[low],s[high]);
                low++;
            high--;
            }
           
        }
        return s;
    }
};

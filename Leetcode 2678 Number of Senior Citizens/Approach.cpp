Amar 1 ta 0-indexed array ase details.Ja string er .Proti string er length 15.
The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.
  Tar mane 11 r 12 no character age represent kore 
tai eke alada korbo
1 ta helper function banai string get(string s) eta dia age er string calculate korbo 
1 ta for loop chalai i=0 to i<s.size() porjonto i++ kori string traverse kori
check age so, check character 11,12
So,
  if(i==11|i==12)
        {
            ans+=s[i];
            //break;
        }
So,
  Code with loop
for(int i=0;i<s.size();i++)
    {
        if(i==11|i==12)
        {
            ans+=s[i];
            //break;
        }
    }
returmn kori ans.

Helper Function:
-----------------

string get(string s)
  {
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(i==11|i==12)
        {
            ans+=s[i];
            //break;
        }
    }
    return ans;
  }
Main Function e 
amar age alada korbo string theke int type er maddhome
So, 
  1 ta vector array nei int er ans eta diye age er part alada kore rakhbo direct int e convert kore string k stoi() diye
So,
1 ta for loop chalai j=0 to j<details.size() porjonto j++ kori array traverse kori
ans array te push kori 
So,
  Code:
  -------

vector<int>ans;
        for(int j=0;j<details.size();j++)
        {
           ans.push_back(stoi(get(details[j])));
        }
ete amar age er part alada hoilo string theke int e convert hoye
aro 1 ta for loop chalai k=0 to k<ans.size() porjonto k++ kori ans array traverse kori
amar chaise koto jon senior 
So,
1 ta variable nei count ja initial 0 int type.Eta diya count korbo number jader age 60 er upore mane senior.
 check condition:
-----------------

  if(ans[k]>60)
  eta hoile 
  count++ kori

  So,
  Condition:
  ------------

  
            if(ans[k]>60)
            {
                count++;
            }
With Loop:
---------

   for(int k=0;k<ans.size();k++)
        {
            if(ans[k]>60)
            {
                count++;
            }
        }
return kori count;

Main Function:
---------------

int countSeniors(vector<string>& details) 
    {
        vector<int>ans;
        for(int j=0;j<details.size();j++)
        {
           ans.push_back(stoi(get(details[j])));
        }
        int count=0;
        for(int k=0;k<ans.size();k++)
        {
            if(ans[k]>60)
            {
                count++;
            }
        }
        return count;

    }

Full Code:
-----------

  class Solution 
{
public:
  string get(string s)
  {
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(i==11|i==12)
        {
            ans+=s[i];
            //break;
        }
    }
    return ans;
  }
    int countSeniors(vector<string>& details) 
    {
        vector<int>ans;
        for(int j=0;j<details.size();j++)
        {
           ans.push_back(stoi(get(details[j])));
        }
        int count=0;
        for(int k=0;k<ans.size();k++)
        {
            if(ans[k]>60)
            {
                count++;
            }
        }
        return count;

    }
};
  

Amar 1 ta array ase string er jar nam words. Ar 1 ta character ase.Amar lagbe kon array er string gular moddhe kader moddhe oi character ase tader index array akare return korte hbe.
  So, ami first e 1 ta helper function banai bool type jar moddhe parameter string ar char.
  1 ta variable nei bool contain ja initial false.
  1 ta for loop chlai i=0 to i<str.size() porjonto string traverse kori
check kori j string e characteer ase kina index wise hoile contain yrue;
return kori contain.
  Helper Function:
-------------------
  bool contain(string a, char b)
{
  bool contain=false;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b)
    {
      contain=true;
    }
  }
  return contain;

}

Main Function:
---------------
Amar array chaise index er jara mane condition.
  1 ta vector create kori ans.
  So, 1 ta for loop chalai i=0 to i<arr.size porjonto array traverse kori
function call kore check kori
if(contain(words[i],x))
  true holile
ans e push kor i 
ans.push_back(i);
 if(contain(words[i],x))
          {
            ans.push_back(i);
          }

for(int i=0;i<words.size();i++)
        {
          if(contain(words[i],x))
          {
            ans.push_back(i);
          }
        }


return kori ans.
=Main function:
-----------------
  vector<int> findWordsContaining(vector<string>& words, char x)
     {
        vector<int>ans;
        for(int i=0;i<words.size();i++)
        {
          if(contain(words[i],x))
          {
            ans.push_back(i);
          }
        }
        return ans;
    }

Full Code:
------------

  class Solution 
{
public:
bool contain(string a, char b)
{
  bool contain=false;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b)
    {
      contain=true;
    }
  }
  return contain;

}
    vector<int> findWordsContaining(vector<string>& words, char x)
     {
        vector<int>ans;
        for(int i=0;i<words.size();i++)
        {
          if(contain(words[i],x))
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};

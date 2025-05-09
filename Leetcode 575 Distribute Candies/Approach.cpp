Alice er kase  n ta candy ase.Alice wait gain kore ei karone uni doctor er kase gelo doctor bollo takey n/2 type er candy khaite everyday.n always even hoite hobe.

Test Case:
-----------
  Example 1:

Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
Example 2:

Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
Example 3:

Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.

Amar 1st case test kori candy ase:1,2,3 ;3 ta diff type er
array size=6
min(3,6/2)=3=output
2 nd case candy ase 1,2,3 ;3 ta diff type
array size=4
min(3,4/2)=2=output
3 rd ase candy ase 6;1 ta type
array size=4
min(1,4/2)=1=output

Approach:
---------
  So, Amar candy koto type er ase ta lagbe
 Map use kori number ar freq map banai
So,
1 st case 
  Map:Number:Freq
      1        2
      2        2
      3        2
      Ekhon ami jodi Number gula means it.first vector e push kori kore size nei oi vector er taile m=3 mane candyAse 3 type er
      Main vector er size 6.;n=6 
    So,
     n/2=6/2=3;
     min(m,n/2)=min(3,3)=3

  So,
  1 st e ekta unorderd_map<int,int>freq nei etay number er sathe frequency pair akare rakhbo
  1 ta loop chalai for int i=0 to i<candyType.size() porjonto i++ kori array traverese kori'
  And er pori freq[candyType[i]]++ kori ete amar map hoilo 
  For first case 
  it is:
  Map:Number:Freq
      1        2
      2        2
      3        2
    ekhn amar candy type[1,2,3] means it.first 
  1 ta for loop chalai range based map traverse kori
1 ta vector nei reserve etay 1 st rakhbo(it.first) eta candy tpe hobe er size means [1,2,3] 3 type er candy arraysize()=3 
  So,
  candyType=reserve.size(); eta ke m e rakhi 
     for(int i=0;i<candyType.size();i++)
        {
          freq[candyType[i]]++;
        }
        vector<int>reserve;
        for(auto it:freq)
        {
         reserve.push_back(it.first);
        }
   int m=reserve.size();
   int n=candyType.size()=6 for example 1
   ans variable nei tader min ber kori
So,
  ans=min(m,n/2)=3 for first case
  2nd case
  m=3
  ans=min(m,n/2)=min(3,4/2)=min(3,2)=2=outpit for secomnmd case
  So,
  ans=min(m,n/2) kori
return kori ans

Full Code:
----------
class Solution 
{
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_map<int,int>freq;
        for(int i=0;i<candyType.size();i++)
        {
          freq[candyType[i]]++;
        }
        vector<int>reserve;
        for(auto it:freq)
        {
         reserve.push_back(it.first);
        }
        int m=reserve.size();
        int n=candyType.size();
        int ans=min(m,n/2);
        return ans;
    }
};
   

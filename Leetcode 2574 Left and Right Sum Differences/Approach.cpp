Amar 1 ta array ase nums.Amar ei array r leftsum r rightsum er diff er 1 ta array return korte bolse

Exa:
----
  Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

Leftsum e [0,10,14,22] 
So,
  leftsum[0]=0;
  leftsum[1]=10=0+10=leftsum[0]+nums[0];
  leftsum[2]=14=4+10=leftsum[1]+nums[1];

So,
  ami proti index e tar ager sob index er moddhe stored value gular sum rakhi

So,
  Here the concept is prefix sum
Left sum r right sum er diff lagbe 
So,
  2 ta array ne reserve1 etate leftsum rakhi r reserve2 te right sum rakhi jader length n ;n=nums.size() karon pura array r sum nibo ta input array r equal hote hbe 
taile sob index er sum gula correctly pabo.

For left sum 
initial 
reserve1[0]=0;
  reserve[1]=reserve[0]+nums[0];
  reserve[2]=reserve[1]+nums[1];
 So,
   if i=2 1=i-1 && if i=1 0=i-1;
So,
  1 ta loop chalai for traverse the array i=0 to i<nums.size() porjonto 
and
 reserve1[i]=reserve1[i-1]+nums[i-1];
Kori
So,
for(int i=1;i<nums.size();i++)
        {
           reserve1[i]=reserve1[i-1]+nums[i-1];
        }
Ekhn rightsum
e 
nums = [10,4,8,3]
 rightSum is [15,11,3,0].

So,
  rightsum[0]=15=3+8+4=nums[3]+nums[2]+nums[1]
So,
as amar last index e value 0;
So,
reverse order e array traverse kori
index:0,1,2,3
traverse :3,2,1,0  ; 3=4-1= nums.size()-1;
So,
initially
 reserve2[nums.size()-1]=0;
aro 1 ta 
for loop chalai j=nums.size()-2;j>=0;j-- porjonto j=reserve2.size()-2 kno karon 3 no index reserve2.size()-1 initial 0 tai 2 theke traverse So, 2=4-2=nums.size()-2
reserve2[j]=nums[j+1]+reserve2[j+1]
Karon
when j=2
reserve2[2]=nums[3]+reserve2[3];  3=2+1=j+1

Difference chaise another array te
So,
1 ta array nei ans vector
So,
1 ta loop chalai for k=0 to k<reserve1.size() porjonto k++ kori reserve1 traverse kori
aro 1 ta for loop chalai nested m=0;m<reserve2.size() porjonto m++ kori reserve 2 traverse kori
as 
final[1]=reserve2[1]-reserve1[1];
tai 
k==m
So,
Condition 
if((k==m)
So,
modulas nisi 
So,
ans[k]=abs(reserve1[k]-reserve2[m]);

return kori ans.

Full Code:
-----------

class Solution 
{
public:
  
  
    vector<int> leftRightDifference(vector<int>& nums)
     {
        int leftsum=0;
        int rightsum=0;
        int n=nums.size();
        vector<int>reserve1(n,0);
        reserve1[0]=0;
        vector<int>reserve2(n,0);
        vector<int>ans(n);
        for(int i=1;i<nums.size();i++)
        {
           reserve1[i]=reserve1[i-1]+nums[i-1];
        }
        reserve2[nums.size()-1]=0;
        for(int j=nums.size()-2;j>=0;j--)
        {
          reserve2[j]=reserve2[j+1]+nums[j+1];
        }
        for(int k=0;k<reserve1.size();k++)
        {
          for(int m=0;m<reserve2.size();m++)
          {
            if((k==m)&&(k<reserve2.size()))
            {
              ans[k]=abs(reserve1[k]-reserve2[m]);
            }
          }
        }
        return ans;

    }
};
Concept Prefix Sum:
------------------
Karon array traverse e both forward and reverse traverse ami 1 ta index tar ager sob index er stored valuer sum rakhi tai.

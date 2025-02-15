Amar 1 ta array ase nums.Jekhane kono 0 nai .Ase 0 theke boro ar choto number.Amar chaise largest positive integer jetar negative value o array te ase.
  1 ta vector array create kori karon jei integer gula positive negative duitai ase tader rakhbo. Ete largest pete subidha hobe.
So, 1st e 1 ta for loop chalai i=0 to i<n porjonto ;i++ kori. Array traverses kori
nested for loop chalai j=i+1 to j<n porjonto karon nijer sathe nije compare korbo na.
  Different index test kori 
if(i!=j)
  check kori j positive ar er soman negative ase kina 
 if(nums[i]==-nums[j])
  jodi true hoy tobe positive max chaise so, 
test positive for i

                    if(nums[i]>0)
                    {

                    
                    reserve.push_back(nums[i]);
                    }
test positive for j
if(nums[j]>0)
                    {

                    
                    reserve.push_back(nums[j]);
                    }
duita check kori karon i teo thakte pare j teo pare.
  Number selection complete which are in both positive and negative in an array
largest check
aro 1 ta for loop chali k=0 k<reserve.size() porjonto 
initial largest=reserve[0].
  check max 
if(reserve[k]>max)
            {
                max=reserve[k];
            }
return kori max.
  Full code:
-------------
  class Solution 
{
public:
    int findMaxK(vector<int>& nums)
     {
        vector<int>reserve;
        for(int i=0;i<nums.size();i++)
        {
           for(int j=i+1;j<nums.size();j++)
           {
            if(i!=j)
            {
                if(nums[i]==-nums[j])
                {
                    if(nums[i]>0)
                    {

                    
                    reserve.push_back(nums[i]);
                    }
                    if(nums[j]>0)
                    {

                    
                    reserve.push_back(nums[j]);
                    }
                }

            }
           }
        }
         if (reserve.empty()) 
         {
            return -1; // No valid elements found
        }
         int max=reserve[0];
        for(int k=1;k<reserve.size();k++)
        {
          //  int max=reserve[0];
            if(reserve[k]>max)
            {
                max=reserve[k];
            }
            //else
           // max=-1;

        }
        return max;
    }
};
  

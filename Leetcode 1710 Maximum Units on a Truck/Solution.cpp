class Solution 
{
public:
 
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
     {
        int ans=0;
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b)
        { 
            return a[1] > b[1]; 
            }
            );
            int sumsec=0;
            for(int i=0;i<boxTypes.size();i++)
            {
              
                   
                   if(boxTypes[i][0]<=truckSize)//&&truckSize>0)
                   {
                    sumsec+=boxTypes[i][0]*boxTypes[i][1];
                    truckSize-=boxTypes[i][0];
                   }
                   else
                   {
                    sumsec+=truckSize*boxTypes[i][1];
                    break;
                   }
                   if(truckSize==0) break;
                    
                }
            
            return sumsec;
    }
};

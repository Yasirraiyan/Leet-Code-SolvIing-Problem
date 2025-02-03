class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int needTime;
        int count=0;
       for(int i=0;i<startTime.size();i++) 
       {
        for(int j=0;j<endTime.size();j++)
        {
            if(i==j)
            {
                  needTime=endTime[j]-startTime[i];
         if (queryTime >= startTime[i] && queryTime <= endTime[i])
         {
            count++;
         }
            }
        }
       }
        
       return count;
    }
};

class Solution {
public:
    double average(vector<int>& salary) {
       int min=salary[0];
       int max=salary[0];
       int sum=0;
       double avg;
       for(int i=0;i<salary.size();i++) 
       {
        sum+=salary[i];
        if(salary[i]>max)
        {
            max=salary[i];
        }
        if(salary[i]<min)
        {
            min=salary[i];
        }
       }
       sum=sum-min-max;
       avg=static_cast<double>(sum)/(salary.size()-2);
       return avg;


    }
};

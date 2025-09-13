class Solution 
{
public:
int findsum(vector<int>v)
{
    int sum=0;
    for(int k=0;k<v.size();k++)
    {
        sum+=v[k];
    }
    return sum;
}
    double trimMean(vector<int>& arr) {
       int n=arr.size();
       int remove=n*0.05;
       sort(arr.begin(),arr.end());
       int index;
       int count=0;
       for(int i=0;i<arr.size();i++)
       {
        count++;
        if(count==remove)
        {
             index=i;
             break;
        }
       }
       int indexx;
       int countt=0;
       for(int i=arr.size()-1;i>=0;i--)
       {
          countt++;
           if(countt==remove)
        {
             indexx=i;
             break;

        }
       }
       vector<int>vv;
       for(int j=index+1;j<indexx;j++)
       {
        vv.push_back(arr[j]);
       }
       int sum=findsum(vv);
       int size=vv.size();
       double avg=static_cast<double>(sum)/size; 
       return avg;
    }
};

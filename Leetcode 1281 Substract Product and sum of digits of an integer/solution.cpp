class Solution {
public:
    int subtractProductAndSum(int n) {
       long long int p=1;
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            sum+=d;
            p*=d;
            n=n/10;
        }
       
        cout<<sum<<endl;
        cout<<p<<endl;
        int result=p-sum;
        return result;
    }
};

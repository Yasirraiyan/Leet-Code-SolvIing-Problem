class Solution
 {
public:
 bool HasSequentialDigits(int n)
 {
  vector<int>v;
  bool has=true;
  while(n>0)
  {
    int rem=n%10;
    v.push_back(rem);
    n=n/10;
  }
  reverse(v.begin(),v.end());
  for(int i=0;i<v.size();i++)
  {
    if(i+1<v.size())
    {
      if(v[i+1]-v[i]!=1)
      {
        has=false;
        break;
      }
    }
  }
  return has;
 }
    vector<int> sequentialDigits(int low, int high)
     {
      static vector<int> all = {12,23,34,45,56,67,78,89, 123,234,345,456,567,678,789,  1234,2345,3456,4567,5678,6789, 12345,23456,34567,45678,56789,123456,234567,345678,456789,
                              1234567,2345678,3456789, 12345678,23456789,  123456789};
        vector<int>v;
        for(int i:all)
        {
          if(i<=high&&i>=low)
          {
          if(HasSequentialDigits(i))
          {
            v.push_back(i);
          }
        }
        }
        return v;
    }
};

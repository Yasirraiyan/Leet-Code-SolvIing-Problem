class ProductOfNumbers 
{
public:
// ProductOfNumbers p;
vector<int>stream;
    ProductOfNumbers()
     {
       // this->p=stream;
       this->stream=stream;
    }
    
    void add(int num)
     {
        stream.push_back(num);
    }
    
    int getProduct(int k) 
    {
      if(k>stream.size()) return 0;
       int p=stream[stream.size()-1];
      if (k == 1) return p == 0 ? 0 : p;
        //int p=stream[stream.size()-1];
        int count=0;
      for(int j=stream.size()-2;j>=0;j--)
      {
         p*=stream[j];
         count++;
         if(count==k-1)
         {
          break;
         }
      }
      return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

class RandomizedSet 
{
public:
unordered_set<int>set1;
    RandomizedSet()
{

        //this->set1=set1;
    }
    
    bool insert(int val) 
    {
        bool caninsert=false;
       
        if(set1.find(val)==set1.end())
        {
              caninsert=true;
             set1.insert(val);
        }
        return caninsert;
    }
    
    bool remove(int val) 
    {
        bool canremove=false;
        if(set1.find(val)!=set1.end())
        {
            set1.erase(val);
            canremove=true;
        }
        return canremove;
    }
    
    int getRandom() 
    {
        int ans=-1;
        int i=0;
        if(set1.size()>=1)
        {
            for(int val:set1)//int i=0;i<set1.size();i++)
            {
                //if(set1.find(val)!=set1.end())
                

                
               if(rand()%(++i)==0)
               {
                ans=val;
               }
              // break;
                }
               //break;
            }
        
        return ans;
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

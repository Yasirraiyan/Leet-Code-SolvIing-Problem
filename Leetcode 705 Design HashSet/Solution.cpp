class MyHashSet 
{
public:
  unordered_set<int>set1;
    MyHashSet()
     {
       //  unordered_set<int>set1;
    }
    
    void add(int key) 
    {
       set1.insert(key);
    }
    
    void remove(int key)
     {
       if(!set1.empty())
       {
        set1.erase(key);
       }
    }
    
    bool contains(int key) 
    {
      bool contain=false;
      if(set1.find(key)!=set1.end())
      {
        contain=true;
      }
      return contain;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

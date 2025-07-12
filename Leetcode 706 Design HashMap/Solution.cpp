class MyHashMap 
{
public:
 unordered_map<int,int>freq;
    MyHashMap() 
{
       // MyHashMap m;//=new MyHashMap();
    }
    
    void put(int key, int value) 
{
      if(freq.find(key)!=freq.end())
      {
        freq.erase(key);
        freq.insert({key,value});
      }
      else
        freq.insert({key,value});
    }
    
    int get(int key) 
{
        if(freq.find(key)!=freq.end())
        {
          return freq[key];
        }
        else
        return -1;
    }
    
    void remove(int key)
{
        if(freq.find(key)!=freq.end())
        {
          freq.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

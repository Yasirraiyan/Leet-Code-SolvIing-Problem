class Solution 
{
public:
    bool isPathCrossing(string path) 
    {
      bool iscross=false;
      unordered_map<char,int>freq;
      int x=0;
      int y=0;
      std::set<std::pair<int,int>> visited;
      visited.insert({x,y});
      for(int i=0;i<path.size();i++)
      {
        freq[path[i]]++;
        if(path[i]=='E')
        {
          x++;
        }
        if(path[i]=='W')
        {
          x--;
        }
        if(path[i]=='N')
        {
          y++;
        }
        if(path[i]=='S')
        {
          y--;
        }
        if((visited.find({x,y})!=visited.end()))
        {
          iscross=true;
          break;
        }
        visited.insert({x,y});
     
      }
      
      return iscross;
    }
};

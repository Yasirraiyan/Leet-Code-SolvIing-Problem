class Solution
 {
public:
 bool Perfect(vector<int>&v,long long dominate)
 {
       sort(v.begin(),v.end());
       int ds=v[0]+v[v.size()-1];
       int low=0;
       int high=v.size()-1;
       long long ans=0;
       while(low<high)
       {
        long long ans=(long long) v[low]+v[high];
        if(ans!=dominate)
        return false;
        low++;
        high--;
       } 
       return true;
 }
    long long dividePlayers(vector<int>& skill)
     {
       sort(skill.begin(),skill.end());
      long long ds=skill[0]+skill[skill.size()-1];
      long long ans=0;
       int low=0;
       int high=skill.size()-1;
         if (!Perfect(skill, ds))
          {
            return -1; // cannot form perfect teams
        }
      if(Perfect(skill,ds))
      {
          while(low<high)
       {
      ans+=(long long) skill[low]*skill[high];
      
        low++;
        high--;
       } 
      }
      return ans;
    }
};

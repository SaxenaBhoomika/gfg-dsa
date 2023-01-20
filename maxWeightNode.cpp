class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
        int u=0,k=0;

      unordered_map<int,int>m;

      for(int i=0; i<N; i++){

       if(Edge[i]==-1)

       continue;

          m[Edge[i]]+=i;

          if(u<m[Edge[i]]){

             u=m[Edge[i]];

             k=Edge[i];

          }

          

      }

      return k;
  }
};

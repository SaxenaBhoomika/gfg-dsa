class Solution {
  public:
    void solve(string s,int &o , int &fl){
        if(!s.length()) return;
          if(fl==0 && s.substr(0,s.length()/2)==s.substr(s.length()/2)){
              fl=1;
              o+=s.length()/2+1;
              return;
          }
          else{
              o++;
              
    solve(s.substr(0,s.length()-1),o,fl);
          }
    }
    int minOperation(string s) {
        // code here
        int o=0,fl=0;
        solve(s,o,fl);
        return o;
    }
};

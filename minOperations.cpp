class Solution {
  public:
    int solve(int a, int b) {
        // code here
        if(a==b)
        return 0;
        int x=a&b;
        if(x==a || x==b)
            return 1;
        return 2;
    
    }
};

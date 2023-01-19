class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
         if(A>B) swap (A,B);
        if( C>D) swap (C,D);
        int count = 0;
        while(A>C or B>D){
             if(A>B) swap (A,B);
             if( B>D ) {
                 B/=2;
                count++;
             }
             else if(A>C) {
                A/=2;
                 count++;
             }
        }
        return count;
    }
};

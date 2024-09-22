class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long bForm=n ;
        if ( n<0 )
        {
            x=1/x;
            bForm= -bForm;
        } 
        while ( bForm > 0){
            if ( bForm % 2 == 1){
            ans*=x;}
            x*=x;
            bForm= bForm/2;
        }
        return ans;
    }
};
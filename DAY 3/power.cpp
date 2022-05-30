class Solution {
public:
    double myPow(double x, int n) {
        
        double res=1.0f;
        for(long p=abs(n);p>0;){
            if(p%2==1){
                res=res*x;
                p--;
            }
            else{
                x=x*x;
                p/=2;
            }       
        }
        
        //for -ve powers
        if(n<0)
            return 1/res;
        return res;
    }
};
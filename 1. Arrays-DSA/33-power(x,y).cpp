Question link -> https://leetcode.com/problems/powx-n/
video -> https://www.youtube.com/watch?v=l0YC3876qxg&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV

Question -> Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Approch 1 ->

double myPow(double x, int n) {
    double ans = 1.0;
    //Value of INT_MAX is +2147483647. Value of INT_MIN is -2147483648
    //So for testcase where n is -2147483648, it can't be converted to 
    // +2147483648 as it exceeds INT limit. 
    // So we need to make n as long int
    long long nn = n;
    if(nn<0) nn = -1 * nn;
    while(nn)
    {
        //for ODD power
        //for eg 2^5 => 2 * 2^4
        if(nn%2 == 1)
        {
            ans *= x;
            nn -= 1;
        }
        //For EVEN power
        //for eg 2^10 => (2*2)^5
        else
        {
            x *= x;
            nn /= 2;
        }
    }
    if(n<0) ans = double(1.0)/double(ans);
    return ans;
}
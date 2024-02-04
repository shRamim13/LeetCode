#define mod 1000000007
class Solution 
{
    long long powfunc(int base , long long power){
        if(power==0){
            return 1;
        }
        long long ans=powfunc(base,power/2);
        ans*=ans;
        ans%=mod;
        if(power%2){
            ans*=base;
            ans%=mod;            
        }
        return ans;

    }

    public:
        int countGoodNumbers(long long n) 
        {
          return (powfunc(5,n/2+n%2)*powfunc(4,n/2))%mod;   
        }
};
#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 +5;
vector<bool> isPrime(N,true);
vector<int> primes;
void seive(){
    for(int i=2;i*i<N;i++)
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=false;
    for(int i=2;i<N;i++)
        if(isPrime[i])
            primes.push_back(i);
}
int main()
{
    seive();
    int t;
    int cs =1;
    cin>>t;
    while((t!=0))
    {
        printf("Case %d: ",cs++);
        long long ans=0l;
        for(int p: primes)
        {
            if(p>t) break;
            ans += upper_bound(primes.begin(),primes.end(),t-p)-primes.begin();
            if(2*p <= t) ans--; //(for condition 1. p1!=p2)
            
        }
        cout<<ans/2<<"\n";  // to remove the permuations
        cin>>t;
    }

    return 0;
}
/*
 * the key problem is find all the pair of primes such that thir sum is p1+p2 <= n
 *
 * but we need to follow the conditions
 *  1. p1 and p2 should be different (p1!=p2)
 *  2. we only want combinations so order does not matter.
 *  Example
 *
 *  n=10
 *  p1  p2
 *  2 -[2,3,5,7] -> 4-1 = 3
 *  3 -[2,3,5,7] -> 4-1 = 3
 *  5 -[2,3,5]   -> 3-1 = 2
 *  7 -[2,3]     -> 2   = 2
 *                 Total= 10
 */


#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<math.h>
#include <utility>
#include <sstream>
#include<bitset>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;

#define PI acos(-1)
#define E 2.718281828459
#define speed      ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

std::bitset<10000020> bs; // 10^7 + small extra bits should be enough for most prime-related problems
std::vector<ll> primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
          int sieve_size = upperbound + 1; // add 1 to include upperbound
           bs.reset(); bs.flip(); // set all numbers to 1
            bs.set(0, false); bs.set(1, false); // except index 0 and 1
          for (ll i = 2; i <= sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i!
          for (ll j = i * i; j <= sieve_size; j += i) bs.set((size_t)j, false);
           primes.push_back((int)i);
    }
}
vi primeFactors(ll N) {
      vi factors;          // vi "primes" (generated by sieve) is optional
      ll PF_idx = 0, PF = primes[PF_idx]; // using PF = 2, 3, 4, ..., is also ok.
      while ((PF * PF <= N)) { // stop at sqrt(N), but N can get smaller
        while (N % PF == 0) {
		N /= PF; factors.push_back(PF); } // remove this PF
            PF = primes[++PF_idx]; // only consider primes!
            }
          if (N != 1) factors.push_back(N); // special case if N is actually a prime
      return factors;
}
int gcd(int a, int b)
{
       return (b == 0 ? a : gcd(b, a % b));
}
map<ll,int> mp;
map<ll,int>::iterator it;
void sieve()
{
	for(int i=1;i<=200;i++)
	{
		mp[i*i*i]=i;
	}
	return;
}
int main(int argc, char** argv) {
	//freopen("c.txt","w",stdout);
	sieve();
	/*cout<<"Cube  =  6,  Triple  =  (3,4,5)\n";
    cout<<"Cube  =  12,  Triple  =  (6,8,10)\n";
    cout<<"Cube  =  18,  Triple  =  (2,12,16)\n";
    cout<<"Cube  =  18,  Triple  =  (9,12,15)\n";
    cout<<"Cube  =  19,  Triple  =  (3,10,18)\n";
    cout<<"Cube  =  20,  Triple  =  (7,14,17)\n";
    cout<<"Cube  =  24,  Triple  =  (12,16,20)\n";
    */
    for(int i=1;i<=200;i++)
    {
    	int x=i-1;
    	ll sum=pow(i,3);
    	ll k;
    	vector< pair<int, pair< int,int > > > test;
    	while(x>3&&((pow(x,3)+pow(x-1,2)+pow(x-2,3)))>=i)
    	{
    		k=sum-(pow(x,3));
    		for(int j=2;pow(j,3)<=k/2;j++)
    		{
    			ll v=k-pow(j,3);
    			it=mp.find(v);
    			if(it!=mp.end())
    			{
    				ll A=x,B=it->second,C=j;
    				if(A>B&&A>C&&B>C)
    				test.push_back(make_pair(C,make_pair(B,A)));
    				//printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,it->second,x);
				}
			}
    		x--;
		}
		if(!test.empty())
		{
			sort(test.begin(),test.end());
			for(int I=0;I<test.size();I++)
			{
				printf("Cube = %d, Triple = (%d,%d,%d)\n",i,test[I].first,test[I].second.first,test[I].second.second);
			}
		}
	}
	return 0;
}

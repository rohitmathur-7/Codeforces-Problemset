//Don't know the difficulty of this problem

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0,i<n;i++) cout<<arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
bitset<10000005> b;
vector<int> primes;
                     
//************************
//Important functions
                      
//gcd
/*
ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}
*/
                        
//extended euclid algorithm
/*
void extendedEuclidAlgorithm(ll a,ll b){
    //base case
    if(b==0){
        x=1;y=0;
        GCD=a;
        return;
    }
    //rec case
    extendedEuclidAlgorithm(b,a%b);
    ll cx=y;
    ll cy=x-((a/b)*y);
                    
    x=cx;
    y=cy;
}
*/
                        
//to compute a^b
/*
ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
*/
 
//to find multiplicative modulo inverse
/*
void multiplicative_modulo_inverse(ll a,ll m){
    if(gcd(a,m)==1){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        cout<<(x+m)%m<<endl;
    }
    else cout<<
Multiplicative modulo inverse is not possible!
<<endl;
}
*/
 
//prime sieve
// // /*
// void prime_sieve(ll *p){
//     for(ll i=3;i<=100000;i+=2) p[i]=1;
 
//     for(ll i=3;i<=100000;i+=2){
//     if(p[i]==1){
//         for(ll j=i*i;j<=100000;j+=i){
//             p[j]=0;
//         }
//         }
//         }
//     p[2]=1;
//     p[1]=0;p[0]=0;
// }
// */
//************************

// ll mex(ll n,ll b){
//     if(n%2!=0){
//         ll c=0;
//         while(c<=n+1){
//             if(c!=n && c!=b) return c;
//             c++;
//         }
//     }
//     if(n!=0) return 0;
//     else return 1;
// }

// ll calc_grundy(ll n,map<ll,ll> &m){
//     //base case
//     if(n==0 || n==1) return 0;

//     //rec case
//     if(n%2==0) m[n]=mex(calc_grundy(n-1,m),0);
//     else m[n]=mex(calc_grundy(n-1,m),0);
//     return m[n];
// }
bool ispower2(ll n){
    return(n and (n&(n-1))==0 );
}


void sieve(){
	b[0]=b[1]=1;
	b.set(); //sets all the bits as 1	
	for(long long int i=2;i<=10000000;i++){
		if(b[i]){
			primes.push_back(i);
			for(long long int j=i*i;j<=10000000;j+=i){
				b[j]=0;	
			}
		}
	}
}

bool isPrime(ll n){
    if(n<=10000000){
        return b[n]==1?true:false;
    }
    for(ll i=0;primes[i]*(ll)primes[i]<=n;i++){
        if(n%primes[i]==0) return false;
    }

    return true;
}

int main(){
    sieve();
    w(t){
        ll n;cin>>n;
        if(n==1) cout<<"FastestFinger"<<endl;
        else if(n==2) cout<<"Ashishgup"<<endl;
        else if(n%2!=0) cout<<"Ashishgup"<<endl;
        else if(ispower2(n)) cout<<"FastestFinger"<<endl;
        else if(isPrime(n/2)) cout<<"FastestFinger"<<endl;
        else cout<<"Ashishgup"<<endl;
    }
     
    return 0;
}
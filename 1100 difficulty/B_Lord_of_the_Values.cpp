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
/*
void prime_sieve(ll *p){
    for(ll i=3;i<=100000;i+=2) p[i]=1;
 
    for(ll i=3;i<=100000;i+=2){
    if(p[i]==1){
        for(ll j=i*i;j<=100000;j+=i){
            p[j]=0;
        }
        }
        }
    p[2]=1;
    p[1]=0;p[0]=0;
}
*/
//************************
 
int main(){
 
    w(t){
        ll n;cin>>n;
        ll arr[n];
        f(i,0,n){cin>>arr[i];}
        ll k=0;
        vl ans;
        f(i,0,n){
            ll c1=arr[i]-2*arr[i];
            ll c2=arr[i+1]-2*arr[i+1];
            // cout<<"c1: "<<c1<<" c2: "<<c2<<endl;
            while(arr[i]!=c1 || arr[i+1]!=c2){
                if(k%2==0){
                    arr[i]=arr[i]+arr[i+1];
                    // cout<<1<<" "<<i+1<<" "<<i+2<<endl;
                    ans.pb(1);
                    ans.pb(i+1);
                    ans.pb(i+2);
                }
                else{
                    arr[i+1]=arr[i+1]-arr[i];
                    // cout<<2<<" "<<i+1<<" "<<i+2<<endl;
                    ans.pb(2);
                    ans.pb(i+1);
                    ans.pb(i+2);
                }
                k++;
            }
            // cout<<arr[i]<<" "<<arr[i+1]<<endl; 
            i++;      
        }

        cout<<k<<endl;
        f(i,0,ans.size()){
            if(i%3==0 && i!=0) cout<<endl;
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
     
    return 0;
}
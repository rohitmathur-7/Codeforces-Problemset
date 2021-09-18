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
        ll arr[2*n];
        ll o=0,e=0;
        f(i,0,2*n){
            cin>>arr[i];
            if(arr[i]%2==0) e++;
            else o++;
        }

        bool three=false;
        ll nn=2*n;
        vl ans,eve,odd;
        if(o>=2*(n-1)){
            ll c=0;
            f(i,0,2*n){
                if(arr[i]%2!=0 && c<=2*(n-1)){
                    // cout<<i+1;
                    ans.pb(i+1);
                    c++;
                }
                else if(arr[i]%2!=0){
                    break;
                }
            }
            // cout<<endl;
        }
        else if(e>=2*(n-1)){
            ll c=0;
            f(i,0,2*n){
                if(arr[i]%2==0 && c<=2*(n-1)){
                    // cout<<i+1;
                    ans.pb(i+1);
                    c++;
                }
                else if(arr[i]%2==0){
                    break;
                }
            }
            // cout<<endl;
        }
        else{
            three=true;
            ll c=0;
            f(i,0,2*n){
                if((arr[i]%2==0 || arr[i]%2!=0) && c<=2*(n-1)){
                    // ans.pb(i+1);
                    if(arr[i]%2==0) eve.pb(i+1);
                    else odd.pb(i+1);
                    c++;
                }
                else break;
            }
            // cout<<endl;
        }

        if(three){
            // cout<<"called"<<endl;
            ll c=0;
            f(i,0,eve.size()){
                if(i+1<eve.size()) cout<<eve[i]<<" "<<eve[i+1]<<endl;
                else break;
                i++;
                c++;
                if(c==n-1) break;
            }   
            f(i,0,odd.size()){
                cout<<odd[i]<<" "<<odd[i+1]<<endl;
                i++;
                c++;
                if(c==n-1) break;
            }   
            // cout<<endl;
        }
        else{
            ll c=0;
            f(i,0,ans.size()){
                cout<<ans[i]<<" "<<ans[i+1]<<endl;
                i++;
                c++;
                if(c==n-1) break;
            }
            // cout<<endl;
        }
    }
     
    return 0;
}
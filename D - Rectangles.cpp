////////////////<------------- Xorcestor_X -------------->////////////////
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <queue>
#include <utility>
#include <stdexcept>

using namespace std;
#define endl "\n"
#define ll long long int
#define c(x) ll x;cin>>x
#define cc(x,y) ll x,y;cin>>x>>y
#define ccc(x,y,z) ll x,y,z; cin>>x>>y>>z
#define db long double
#define fast cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define inf 1e16
#define mod 1000000007
#define mod2 998244353
#define eps 1e-7
#define PI 3.1415926535897932385
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (ll)(x).size()
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define print(arr,n) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n) cout<<arr[i]<<" "; cout<<endl
#define print2(arr,n,m) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n){ rep(j,m) cout<<arr[i][j]<<" "; cout<<endl; }
#define dyn1(arr,n) ll* arr=new ll[n]; rep(i,n) arr[i]=0;
#define dyn2(arr,n,m) ll** arr=new ll*[(n)]; rep(i,n) arr[i]=new ll[m]; rep(i,n) rep(j,m) arr[i][j]=0
#define carr(arr,n) fr(i,0,n-1) cin>>arr[i]
#define carr2(arr,n,m) fr(i,0,n-1) fr(j,0,m-1) cin>>arr[i][j]
#define debug(a) cerr<<" :: "<<#a<<" == "<<a<<endl
#define debug2(a,b) cerr<<" :: "<<#a<<" == "<<a<<" :: "<<#b<<" == "<<b<<endl
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debugx(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debugx("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define bix(n) __builtin_popcount(n)
#define blx(n) __builtin_popcountll(n)
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
typedef vector<vector<ll>> matrix;

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b) { return b==0 ? a : gcd(b, a%b); }

ll reduce(ll& a,ll m){
    a%=m;
    a+=m;
    a%=m;
    return a;
}

ll max(ll x, ll y) {
    return (x > y) ? x : y;
}

ll min(ll x, ll y) {
    return (x < y) ? x : y;
}
 
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
       x += m0;
    return x;
}
 
 
 
ll fact[200010];

void compute_fact(ll modVal) {
  fact[0]=1;
  for(int i=1;i<=200004;i++) {
    fact[i]=(fact[i-1]*i)%modVal;
  }
}

ll ncr_mod(ll n,ll r,ll modVal) {
  if(r==0||n==r) return 1;
  if(n<r) return 0;
  return (((fact[n]*modInverse(fact[r],modVal))%modVal)*modInverse(fact[n-r],modVal))%modVal;
}



int main() {
    fast;
    cout<<setprecision(6)<<fixed;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    //  (a,b)  ll->ll
    //

    unordered_map<ll,ll> count;
    map<ll,vector<ll>> points;



    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        points[x].push_back(y);
    }


    ll total=0;

    for(auto itr=points.rbegin();itr!=points.rend();itr++){
        vector<ll> vect=itr->second;
        sort(vect.begin(),vect.end());
        int m=vect.size();

        for(int a=0;a<m;a++){
            for(int b=a+1;b<m;b++){
                ll key = vect[a]*((ll)(1e9+1))+vect[b];
                total+=count[key];
                count[key]++;
            }
        }
    }

    cout<<total<<endl;


    return 0;
}

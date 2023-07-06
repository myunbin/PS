#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e4;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

ll pw(ll a, ll b) {
    if (b==0) return 1ll;
    if (b%2) return a*pw(a,b-1)%MOD;
    ll r=pw(a,b/2)%MOD; return r*r%MOD;
}

ll d(ll n) {
    ll dig=1,ans=0,len=1;
    while (1) {
        if (dig*10>n) {
            ans+=(n-dig+1)*len;
            break;
        }
        else {
            ans+=9*dig*len;
        }
        dig*=10ll;
        len++;
    }
    return ans;
}

int main() {
    fio();
    ll n;
    cin>>n;

    ll ans=(3*n-4+MOD)%MOD;
    ans=(ans+(n+2)*pw(2,n-1)%MOD)%MOD;
    ans=(ans+((pw(2,n-1)+1)*d(n))%MOD)%MOD;
    
    cout<<ans;
    return 0;
}
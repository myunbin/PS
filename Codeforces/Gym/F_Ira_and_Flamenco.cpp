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
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

ll pw(ll a, ll b){
    if (b==0) return 1;
    if (b%2) return a*pw(a,b-1)%MOD;
    ll r=pw(a, b/2); return r*r%MOD;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    
    map<ll,ll> mp;
    for (ll &x:a) {
        cin>>x;
        mp[x]++;
    }

    cmprs(a);
    n=sz(a);

    int ri=0;
    ll cur=1, ans=0;
    
    for (int i=0; i<m; i++) {
        cur=(cur*mp[a[i]])%MOD;
    }

    for (int i=0; i<=n-m; i++) {
        int j=i+m-1;
        if (a[j]-a[i]==m-1) ans=(ans+cur)%MOD;

        if (j+1<=n) {
            cur=(cur*pw(mp[a[i]], MOD-2))%MOD;
            cur=(cur*mp[a[j+1]])%MOD;
        }   
    }
    cout<<ans<<endl;
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}
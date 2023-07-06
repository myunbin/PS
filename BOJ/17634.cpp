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
const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();

    ll N,A,B;
    cin>>N>>A>>B;

    ll G=gcd(A,B+1);
    ll T=A/G*B;

    if (2ll*LINF/B<A/G) {
        ll ans=0;
        for (int i=0; i<N; i++) {
            ll l,r; cin>>l>>r;
            ans+=(r-l+1);
        }
        cout<<ans;
        return 0;
    }

    vector<pll> v;
    ll ans=0;
    for (int i=0; i<N; i++) {
        ll l,r;
        cin>>l>>r;
        if (T<=r-l+1) ans=T;

        l%=T, r%=T;
        if (l>r) {
            v.pb({0,r});
            v.pb({l,T-1});
        }
        else v.pb({l,r});
    }
    v.pb({LINF,LINF});
    
    if (ans) {
        cout<<ans;
        return 0;
    }

    sort(all(v));
    
    ll le=0, ri=-1;
    for (auto [s,e]:v) {
        if (ri<s) {
            ans+=ri-le+1;
            le=s, ri=e;
        }
        else {
            ri=max(ri, e);
        }
    }

    cout<<ans;
    return 0;
}
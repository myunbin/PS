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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

struct rr{
    ll a,b,c;
};

int n;
vector<rr> v;

bool ok(ll x) {
    ll sum=0;
    for (auto [a,c,b]:v) {
        if (x<a) continue;
        sum+=(min(c,x)-a)/b+1;
    }
    return sum&1;
}

int main() {
    fio();
    cin>>n;
    v.resize(n);
    for (auto &[a,c,b]:v) {
        cin>>a>>c>>b;
    }    

    ll l=1ll, r=(1ll<<31)-1;
    ll ans=-1;
    while (l<=r) {
        ll m=(l+r)>>1;
        if (ok(m)) {   
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }

    if (ans==-1) cout<<"NOTHING";
    else {
        ll cnt=0;
        for (auto [a,c,b]:v) {
            if (a<=ans && ans<=c && (ans-a)%b==0) cnt++;
        }
        cout<<ans<<sp<<cnt;
    }
    return 0;
}
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
const int MAX = 303030; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    set<array<int,3>> s;
    for (int i=0; i<n; i++) {
        int a,b,c; 
        cin>>a>>b>>c;
        int g=gcd(gcd(a,b),c);
        a/=g, b/=g, c/=g;
        s.insert({a,b,c});
    }

    map<pii,ll> m;
    for (auto [a,b,c]:s) {
        int g=gcd(a,b);
        a/=g, b/=g;
        m[{a,b}]++;
    }

    vector<ll> a,p,pp;
    a.pb(0), p.pb(0), pp.pb(0);

    for (auto [x,cnt]:m) {
        a.pb(cnt);
        p.pb(p.back()+cnt);
        pp.pb(pp.back()+cnt*cnt);

    }

    int sz=sz(p)-1;
    ll ans=p[sz]*p[sz]*p[sz];
    for (int i=1; i<=sz; i++) {
        ans-=a[i]*a[i]*a[i];
        ans-=3ll*a[i]*a[i]*(p[sz]-p[i]);
        ans-=3ll*a[i]*(pp[sz]-pp[i]);
    }

    cout<<(ans/6)%MOD;
    return 0;
}
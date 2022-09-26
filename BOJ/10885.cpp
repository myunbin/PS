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

ll pw(int a, int b) {
    if (b==0) return 1ll;
    if (b&1) return (a*pw(a,b-1))%MOD;
    ll r=pw(a,b>>1); return (r*r)%MOD;
}

void solve() {
    int n;
    cin>>n;

    ll ans=-3;
    vector<int> a(n);
    for (int &x:a) cin>>x, ans=max(ans, 1ll*x);
    
    int p=0;
    vector<vector<int>> v;
    while (p<n) {
        vector<int> t;
        t.pb(0);
        while (p<n && a[p]!=0) t.pb(a[p]), p++;
        if (sz(t)>1) v.pb(t);
        p++;
    }
    
    int mx=0;
    for (auto vv:v) {
        int sz=sz(vv)-1;
        vector<int> neg, two(sz+1);
        for (int i=1; i<=sz; i++) {
            two[i]=two[i-1]+(abs(vv[i])==2);
            if (vv[i]<0) neg.pb(i);
        }
        if (sz(neg)%2==0) {
            mx=max(mx, two[sz]);
        }
        else {
            if (neg[0]+1<=sz) mx=max(mx, two[sz]-two[neg[0]]);
            if (1<=neg.back()-1) mx=max(mx, two[neg.back()-1]);
        }

        if (sz(neg)>1) ans=max(ans, 1ll);
    }
    
    if (mx>0) ans=pw(2, mx);
    cout<<(ans+MOD)%MOD<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
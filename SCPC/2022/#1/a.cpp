#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL)
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

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];

    map<ll, vector<ll>> m1,m2;
    for (int i=0; i<n; i++) m1[b[i]].pb(a[i]);

    sort(all(b));
    for (int i=0; i<n; i++) m2[b[i]].pb(a[i]);

    auto it1=m1.begin();
    auto it2=m2.begin();
    ll ans=0;
    while (it1!=m1.end()) {
        auto [x1,v1]=*it1;
        auto [x2,v2]=*it2;
        int s=sz(v1);
        for (int i=0; i<s; i++) ans+=abs(v1[i]-v2[i]);

        it1++,it2++;
    }

    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}
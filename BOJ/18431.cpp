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

int main() {
    fio();
    int n;
    cin>>n;
    vector<pii> a(n+2);
    vector<int> b(n+1), d1(n+3), d2(n+3);
    for (int i=1; i<=n+1; i++) cin>>a[i].F, a[i].S=i;
    for (int i=1; i<=n; i++) cin>>b[i];
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());

    for (int i=1; i<=n+1; i++) {
        if (i!=n+1) d1[i]=max(0, a[i].F-b[i]);
        if (i!=1) d2[i]=max(0, a[i].F-b[i-1]);
    }
    
    vector<int> pm(n+2), sm(n+3);
    for (int i=1; i<=n; i++) pm[i]=max(pm[i-1], d1[i]);
    for (int i=n+1; i>=2; i--) sm[i]=max(sm[i+1], d2[i]);

    vector<int> ans(n+2);
    for (int i=1; i<=n+1; i++) ans[a[i].S]=max(pm[i-1], sm[i+1]);
    
    for (int i=1; i<=n+1; i++) cout<<ans[i]<<sp;

    return 0;
}
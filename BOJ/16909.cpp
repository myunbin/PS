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

int n;
ll a[MAX];
int dl[MAX], dr[MAX];
int el[MAX], er[MAX];

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];

    ll ans=0;

    vector<pii> s;
    a[0]=a[n+1]=INF;

    for (int i=0; i<=n+1; i++) {
        while (!s.empty() && s.back().F<=a[i]) {
            dr[s.back().S]=i-1;
            s.pop_back();
        }
        s.pb({a[i],i});
    }

    s.clear();
    for (int i=n+1; i>=0; i--) {
        while (!s.empty() && s.back().F<a[i]) {
            dl[s.back().S]=i+1;
            s.pop_back();
        }
        s.pb({a[i],i});
    }

    a[0]=a[n+1]=0;

    s.clear();
    for (int i=0; i<=n+1; i++) {
        while (!s.empty() && s.back().F>=a[i]) {
            er[s.back().S]=i-1;
            s.pop_back();
        }
        s.pb({a[i],i});
    }

    s.clear();
    for (int i=n+1; i>=0; i--) {
        while (!s.empty() && s.back().F>a[i]) {
            el[s.back().S]=i+1;
            s.pop_back();
        }
        s.pb({a[i],i});
    }
    
    for (int i=1; i<=n; i++) {
        ans+=1ll*(i-dl[i]+1)*1ll*(dr[i]-i+1)*a[i];
        ans-=1ll*(i-el[i]+1)*1ll*(er[i]-i+1)*a[i];
    }
    
    cout<<ans<<endl;
    return 0;
}
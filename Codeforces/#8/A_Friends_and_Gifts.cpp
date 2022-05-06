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

void solve() {
    int n;
    cin>>n;
    vector<int> ind(n+1,0), no,ni, oud(n+1);
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        oud[i]=x;
        ind[x]=1;
    }

    vector<int> t;
    for (int i=1; i<=n; i++) {
        if (!oud[i]&&!ind[i]) t.pb(i);
    }
    
    if (sz(t)>1) {
        for (int i=0; i<sz(t); i++) {
            oud[t[i]]=t[(i+1)%sz(t)];
            ind[t[(i+1)%sz(t)]]=1;
        }
    }
    else if (sz(t)==1) {
        for (int i=1; i<=n; i++) {
            if (!ind[i] && i!=t[0]) {
                oud[t[0]]=i;
                ind[i]=1;
                break;
            }
        }
    }
    
    for (int i=1; i<=n; i++) if (!oud[i]) no.pb(i);
    for (int i=1; i<=n; i++) if (!ind[i]) ni.pb(i);
    for (int i=0; i<sz(no); i++) oud[no[i]]=ni[i];
    for (int i=1; i<=n; i++) cout<<oud[i]<<sp;
}

int main() {
    fio();
    int t=1;
    while (t--) solve();
    return 0;
}
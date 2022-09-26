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
    int n,m;
    cin>>n>>m;
    vector<int> g[MAX];
    for (int i=1; i<=m; i++) {
        int k; cin>>k;
        while (k--) {
            int x; cin>>x;
            g[i].pb(x);
        }
    }
    vector<int> res(n+1), rev(n+1), ans(n+1);
    for (int i=1; i<=n; i++) {
        cin>>res[i];
        ans[i]=res[i];
        rev[i]=res[i];
    }    
    
    for (int i=m; i>=1; i--) {
        bool isz=0;
        for (int x:g[i]) {
            if (!rev[x]) {
                isz=1;
                break;
            }
        }
        if (isz) {
            for (int x:g[i]) {
                rev[x]=ans[x]=0;
            }
        }
    }

    vector<int> tst(n+1);
    for (int i=1; i<=n; i++) tst[i]=ans[i];

    for (int i=1; i<=m; i++) {
        bool iso=0;
        for (int x:g[i]) {
            if (tst[x]) {
                iso=1;
                break;
            }
        }

        if (iso) {
            for (int x:g[i]) {
                tst[x]=1;
            }
        }
    }

    bool ok=1;
    for (int i=1; i<=n; i++) {
        if (tst[i]!=res[i]) {
            ok=0;
            break;
        }
    }

    if (ok) {
        cout<<"YES\n";
        for (int i=1; i<=n; i++) {
            cout<<ans[i]<<sp;
        }
    }
    else {
        cout<<"NO";
    }
    return 0;
}
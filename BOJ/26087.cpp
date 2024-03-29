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
const int MAX = 1010101; // PLZ CHK!

int p[MAX];

int fd(int a) {
    if (a==p[a]) return p[a];
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

ll f[MAX];

void init() {
    for (int i=0; i<MAX; i++) p[i]=i;

    f[0]=1, f[1]=1;
    for (int i=2; i<MAX; i++) {
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
}
int main() {
    fio();
    
    init();
    
    int n,q;
    cin>>n>>q;
    vector<pii> qry(q);
    for (auto &[s,e]:qry) cin>>s>>e;
    reverse(all(qry));

    vector<int> idx(n+1);
    for (auto [s,e]:qry) {
        int cur=fd(e);
        while (cur>=s) {
            idx[cur]=s;
            mg(cur-1, cur);
            cur=fd(cur);
        }
    }

    for (int i=1; i<=n; i++) {
        if (!idx[i]) cout<<0<<sp;
        else cout<<f[i-idx[i]+1]<<sp;    
    }
    return 0;
}
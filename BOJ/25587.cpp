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

int p[MAX], ps[MAX], pa[MAX], pb[MAX];
int a[MAX], b[MAX];
int cur;

int fd(int a) {
    if (p[a]==a) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    
    if (pa[a]+pa[b]>=pb[a]+pb[b]) {
        if (pa[a]<pb[a]) cur-=ps[a];
        if (pa[b]<pb[b]) cur-=ps[b];
    }
    else {
        if (pa[a]>=pb[a]) cur+=ps[a];
        if (pa[b]>=pb[b]) cur+=ps[b];
    }

    ps[a]+=ps[b];
    pa[a]+=pa[b];
    pb[a]+=pb[b];
    p[b]=a;
    
    return 1;
}


int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i, ps[i]=1;

    int n,m;
    cin>>n>>m;

    for (int i=1; i<=n; i++) cin>>pa[i];
    for (int i=1; i<=n; i++) cin>>pb[i];
    for (int i=1; i<=n; i++) cur+=(pb[i]>pa[i]);

    while (m--) {
        int x; cin>>x;
        if (x==2) cout<<cur<<endl;
        else {
            int y,z;
            cin>>y>>z;
            mg(y,z);
            // y=fd(y);
            // cout<<ps[y]<<sp<<pa[y]<<sp<<pb[y]<<sp<<cur<<endl;
        }
    }
    

    return 0;
}
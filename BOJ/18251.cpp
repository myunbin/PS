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
const int MAX = 303030; // PLZ CHK!

struct pt {
    int x,y;
    ll z;
};

int n, cnt=1, md=0;
pt v[MAX];

void dfs(int cur, int dep) {
    if (cur*2<=n) dfs(cur*2, dep+1);
    v[cur].x=cnt++, v[cur].y=dep;
    md=max(md, dep);
    if (cur*2+1<=n) dfs(cur*2+1, dep+1);
}

int main() {
    fio();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>v[i].z;

    dfs(1,1);
    sort(v+1, v+n+1, [](pt a, pt b){
        return a.x<b.x;
    });

    ll ans=-LINF;
    for (int i=1; i<=md; i++) {
        for (int j=i; j<=md; j++) {
            ll d[MAX]={0};
            d[0]=-LINF;
            for (int k=1; k<=n; k++) {
                if (i<=v[k].y && v[k].y<=j) d[k]=max(d[k-1]+v[k].z, v[k].z);
                else d[k]=d[k-1];
            }
            ans=max(ans, *max_element(d+1, d+n+1));
        }
    }
    cout<<ans;
    return 0;
}
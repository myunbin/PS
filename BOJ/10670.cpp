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
const int MAX = 21; // PLZ CHK!

int main() {
    fio();
    int n,l;
    cin>>n>>l;

    vector<vector<int>> t(n);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        int m;
        cin>>a[i]>>m;
        t[i].resize(m);
        for (int &x:t[i]) cin>>x;
    }

    int d[1<<MAX];
    memset(d,-1,sizeof d); 
    d[0]=0;

    int ans=INF;
    for (int i=0; i<(1<<n); i++) {
        if (d[i]==-1) continue;
        if (d[i]>=l) ans=min(ans, __builtin_popcount(i));

        for (int j=0; j<n; j++) {
            if (i&(1<<j)) continue;
            int k=ub(all(t[j]), d[i])-t[j].begin()-1;
            if (k>=0) d[i|(1<<j)]=max(d[i|(1<<j)], t[j][k]+a[j]);
        }
    }

    cout<<(ans==INF?-1:ans);
    return 0;
}
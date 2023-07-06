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
const int MAX = 202020; // PLZ CHK!

int n,d[MAX];
int mxd[MAX],mnd[MAX];
int a[MAX][2];

int ans=0;
void dfs(int cur) {
    if (cur>n) {
        mxd[cur]=mnd[cur]=d[cur];
        return;
    }
    
    for (int i=0; i<2; i++) {
        int nxt=a[cur][i];
        d[nxt]=d[cur]+1;
        dfs(nxt);
        mxd[cur]=max(mxd[cur], mxd[nxt]);
        mnd[cur]=min(mnd[cur], mnd[nxt]);
    }

    if (mxd[cur]-mnd[cur]>1) ans=-INF;
    pii p={mxd[a[cur][0]], mnd[a[cur][0]]}, q={mxd[a[cur][1]], mnd[a[cur][1]]};

    if (p<q) {
        // cout<<"!: "<<cur<<endl;
        ans++, swap(p,q);
    }
    if (p.S<q.F) ans=-INF;
}

int main() {
    fio();
    cin>>n;

    int cnt=n+1;
    for (int i=1; i<=n; i++) {
        cin>>a[i][0]>>a[i][1];
        if (a[i][0]==-1) a[i][0]=cnt++;
        if (a[i][1]==-1) a[i][1]=cnt++;
        mxd[i]=-1, mnd[i]=INF;
    }

    d[1]=0;
    dfs(1);

    // for (int i=1; i<=n; i++) {
    //     cout<<i<<": "<<mxd[i]<<sp<<mnd[i]<<endl;
    // }

    cout<<(ans<0?-1:ans);
    return 0;
}
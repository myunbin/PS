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

int N,M,L,in[MAX],c[MAX],d[MAX];
vector<int> g[MAX];

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int k; cin>>k;
        vector<int> a(k+1);
        for (int &x:a) cin>>x;

        for (int i=0; i<k; i++) {
            g[a[i]].pb(a[k]);
            in[a[k]]++;    
        }
    }

    cin>>L;
    fill(c,c+MAX,INF),fill(d,d+MAX,INF);

    for (int i=0; i<L; i++) {
        int x; cin>>x;
        c[x]=0;
    }

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (in[i]==0) {
            q.push(i);
            d[i]=c[i];
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        d[cur]=min(d[cur], c[cur]);
        if (d[cur]==0) {
            ans.pb(cur);
        }
        for (int nxt:g[cur]) {
            d[nxt]+=d[cur];
            if (--in[nxt]==0) {
                q.push(nxt);
            }
        }
    }
    
    sort(all(ans));
    cout<<sz(ans)<<endl;
    for (int x:ans) cout<<x<<sp;

    return 0;
}

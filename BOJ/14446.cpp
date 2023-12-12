#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("promote.in","r",stdin); freopen("promote.out","w",stdout)
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
const int MAX = 101010; // PLZ CHK!

int N,A[MAX],C[MAX],IC[MAX],S[MAX];
vector<int> G[MAX];

int cnt=1;
void dfs(int cur) {
    C[cur]=cnt++;
    IC[C[cur]]=cur;
    S[C[cur]]=1;
    for (int nxt:G[cur]) {
        dfs(nxt);
        S[C[cur]]+=S[C[nxt]];
    }
}

vector<int> tr[MAX<<2];
vector<int> init(int nd, int le, int ri) {
    if (le==ri) {
        tr[nd].pb(A[IC[le]]);
        return tr[nd];
    }
    int md=(le+ri)>>1;
    vector<int> L=init(nd<<1, le, md), R=init(nd<<1|1, md+1, ri);
    tr[nd].insert(tr[nd].end(), all(L));
    tr[nd].insert(tr[nd].end(), all(R));
    sort(all(tr[nd]));
    return tr[nd];
}

int qry(int nd, int le, int ri, int ql, int qr, int k) {
    if (qr<le || ri<ql) return 0;
    if (ql<=le && ri<=qr) return tr[nd].end()-ub(all(tr[nd]),k);
    int md=(le+ri)>>1;
    return qry(nd<<1,le,md,ql,qr,k)+qry(nd<<1|1,md+1,ri,ql,qr,k);
}

int main() {
    fio();
    // fileio();

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
    }

    for (int i=2; i<=N; i++) {
        int x; cin>>x;
        G[x].pb(i);
    }

    dfs(1);
    init(1,1,N);
    
    for (int i=1; i<=N; i++) {
        // cout<<i<<sp<<C[i]<<sp<<C[i]+S[C[i]]-1<<sp<<A[i]<<endl;
        int q=qry(1,1,N,C[i],C[i]+S[C[i]]-1,A[i]);
        cout<<q<<endl;
    }

    return 0;
}
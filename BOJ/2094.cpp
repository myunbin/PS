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
const int MAX = 50505; // PLZ CHK!

struct segtr{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1), a.resize(n+1);
    }

    void init() {
        for (int i=0; i<n; i++) tr[n+i] = a[i];
        for (int i=n-1; i; i--) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    void upd(int i, ll v) {
        tr[i+n] = max(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    ll qry(int l, int r) {
        if (l>r) return 0;

        ll ret = -LINF;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, tr[l++]);
            if (~r&1) ret = max(ret, tr[r--]);
        }
        return ret;
    }
};

int N,M;
vector<ll> Y,R,C;
set<ll> sy;
segtr seg;

int solve(int l, int r) {
    int x=lb(all(C),r)-C.begin(), y=lb(all(C),l)-C.begin();
    bool okx=(x<N && Y[x]==r), oky=(y<N && Y[y]==l);

    if (okx&&oky && R[x]>R[y]) return -1;
    ll q=seg.qry(lb(all(C),l+1)-C.begin(),x-1);
    if (okx&&q>=R[x]) return -1;
    if (oky&&q>=R[y]) return -1;
    if (okx&&oky&&x-y==r-l) return 1;
    return 0;
}

int main() {
    fio();
    cin>>N;
    Y.resize(N), R.resize(N), C.resize(N);
    seg.rst(MAX);

    for (int i=0; i<N; i++) {
        cin>>Y[i]>>R[i];
        C[i]=Y[i];
        seg.upd(i,R[i]);
    }
    cmprs(C);
    
    cin>>M;
    while (M--) {
        int l,r;
        cin>>l>>r;

        int res=solve(l,r);
        if (res==1) cout<<"true\n";
        else if (res==-1) cout<<"false\n";
        else cout<<"maybe\n";
    }
    
    return 0;
}
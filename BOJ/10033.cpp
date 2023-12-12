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
const int MAX = 101010; // PLZ CHK!

int N,p[MAX];
vector<int> C;
vector<pii> A;

struct segtr{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1,LINF);
    }

    void upd(int i, ll v) {
        tr[i+n] = min(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }

    ll qry(int l, int r) {
        ll ret = LINF;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, tr[l++]);
            if (~r&1) ret = min(ret, tr[r--]);
        }
        return ret;
    }
};

int main() {
    fio();
    cin>>N;
    A.resize(N);
    C.pb(-1);
    for (int i=0; i<N; i++) {
        int x; char c; cin>>x>>c;
        A[i]={x,(c=='W'?1:-1)};
        C.pb(x);
    }
    A.pb({0,-11});
    sort(all(A));
    cmprs(C);

    int ans=0;
    segtr es,os; es.rst(MAX<<1), os.rst(MAX<<1);
    es.upd(MAX,0);
    
    for (int i=1; i<=N; i++) {
        p[i]=p[i-1]+A[i].S;

        int q;
        if (i&1) {
            q=os.qry(0,MAX+p[i]);
            os.upd(MAX+p[i], i);
        }
        else {
            q=es.qry(0,MAX+p[i]);
            es.upd(MAX+p[i], i);
        }
        
        if (q<i) ans=max(ans, A[i].F-A[q+1].F);
    }

    cout<<ans;

    return 0;
}
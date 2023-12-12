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

struct star {
    int x,y,b;
    bool operator < (const star &ot) const {
        if (x==ot.x) {
            if (y==ot.y) return b>ot.b;
            return y>ot.y;
        }
        return x<ot.x;
    }
};
struct segtr{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1,0);
    }

    void upd(int i, ll v) {
        tr[i+n] = max(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    void upd0(int i) {
        tr[i+n] = 0; i+=n; //AWARE OF UPD POLICY!!
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


int N,L;
star A[MAX];
int d[MAX];
map<int,multiset<int>> Y;

int main() {
    fio();
    cin>>N>>L;
    vector<int> y;
    for (int i=1; i<=N; i++) {
        cin>>A[i].x>>A[i].y>>A[i].b;
        y.pb(A[i].y), y.pb(A[i].y-L), y.pb(A[i].y-1);
    }
    
    cmprs(y);
    sort(A+1,A+N+1);
    segtr seg; seg.rst(4*MAX);

    typedef array<int,3> arr;
    priority_queue<arr,vector<arr>,greater<arr>> pq;
    for (int i=1; i<=N; i++) {
        while (!pq.empty() && pq.top()[0]<A[i].x-L) {
            auto [xx,yy,dd]=pq.top(); pq.pop();

            seg.upd0(lb(all(y),yy)-y.begin());
            Y[yy].erase(Y[yy].find(dd));
            if (!Y[yy].empty()) seg.upd(lb(all(y),yy)-y.begin(),*Y[yy].rbegin());
        }

        int l=lb(all(y),A[i].y-L)-y.begin();
        int r=lb(all(y),A[i].y-1)-y.begin();
        int u=lb(all(y),A[i].y)-y.begin();

        d[i]=A[i].b+seg.qry(l,r);
        seg.upd(u,d[i]);

        pq.push({A[i].x,A[i].y,d[i]});
        Y[A[i].y].insert(d[i]);
    }

    cout<<*max_element(d+1,d+N+1);
    return 0;
}
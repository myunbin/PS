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
const int MAX = 2020202; // PLZ CHK!

int N,M,A[MAX];
vector<int> B;

struct fwt {
    // 1-indexed!
    vector<ll> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, ll v) {
        for (; i<sz(tr); i+=(i&-i)) tr[i]+=v;
    }
    ll qry(int r) { //[1,r]
        ll sum=0;
        for (; r; r-=(r&(-r))) sum+=tr[r];
        return sum;
    }
    ll qry(int l, int r) { //[l, r]
        if(l==0) return qry(r);
        return qry(r)-qry(l-1);
    }
};

struct QQ {
    int op,x,l,r;
};

QQ Q[MAX];
int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i];
        B.pb(A[i]);
    }
    cin>>M;
    for (int i=0; i<M; i++) {
        cin>>Q[i].op;
        if (Q[i].op==1) {
            cin>>Q[i].x;
            B.pb(Q[i].x);
        }
        else {
            cin>>Q[i].l>>Q[i].r;
            B.pb(Q[i].l), B.pb(Q[i].r);
        }
    }

    cmprs(B);
    for (int i=0; i<N; i++) A[i]=lb(all(B),A[i])-B.begin()+1;
    for (int i=0; i<M; i++) {
        if (Q[i].op==1) Q[i].x=lb(all(B),Q[i].x)-B.begin()+1;
        else {
            Q[i].l=lb(all(B),Q[i].l)-B.begin()+1;
            Q[i].r=lb(all(B),Q[i].r)-B.begin()+1;
        }
    }

    fwt fw; fw.rst(MAX*2);

    for (int i=0; i<N; i++) fw.upd(A[i],1);
    for (int i=0; i<M; i++) {
        if (Q[i].op==1) fw.upd(Q[i].x,1);
        else cout<<(B[Q[i].r-1]-B[Q[i].l-1]+1-fw.qry(Q[i].l,Q[i].r))<<endl;
    }

    return 0;
}
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
const int MAX = 1010101; // PLZ CHK!

int N,Q;
char S[MAX];

struct Node {
    int v,lv,rv;
    Node() : v(0),lv(0),rv(0){}
};
Node tr[MAX<<2];

Node operator + (const Node &p, const Node &q) {
    Node ret;
    int f=min(p.lv,q.rv);
    ret.v=p.v+q.v+f*2;
    ret.lv=p.lv+q.lv-f;
    ret.rv=p.rv+q.rv-f;
    return ret;
}

void init(int nd, int le, int ri) {
    if (le==ri) {
        if (S[le]=='(') tr[nd].lv++;
        else tr[nd].rv++;
        return;
    }

    int md=(le+ri)>>1;
    init(nd<<1,le,md), init(nd<<1|1,md+1,ri);
    tr[nd]=tr[nd<<1]+tr[nd<<1|1];
}

Node qry(int nd, int le, int ri, int ql, int qr) {
    if (qr<le || ri<ql) return Node();
    if (ql<=le && ri<=qr) return tr[nd];
    int md=(le+ri)>>1;
    return qry(nd<<1,le,md,ql,qr)+qry(nd<<1|1,md+1,ri,ql,qr);
}

int main() {
    fio();
    cin>>(S+1)>>Q;
    N=strlen(S+1);
    init(1,1,N);

    while (Q--) {
        int l,r;
        cin>>l>>r;
        cout<<qry(1,1,N,l,r).v<<endl;
    }

    return 0;
}
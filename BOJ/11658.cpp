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
const int MAX = (1<<10)+50; // PLZ CHK!

struct SEG{
    //0-indexed!
    int tr[3030];
    int n;
    void rst(int sz) {for (n=1; n<sz; n<<=1);}

    void upd(int i, int v) {
        tr[i+n]=v; i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i]=tr[i<<1]+tr[i<<1|1];
    }

    int qry(int l, int r) {
        int ret=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret+=tr[l++];
            if (~r&1) ret+=tr[r--];
        }
        return ret;
    }
};

struct seg2d {
    SEG tr[3030];
    int n;
    void rst(int sx, int sy) {
        for (n=1; n<sx; n<<=1);
        for (int i=0; i<=2*n; i++) tr[i].rst(sy);
    }

    void upd(int i, int j, int v) {
        tr[i+n].upd(j,v); i+=n;
        for (i>>=1; i; i>>=1) tr[i].upd(j,tr[i<<1].qry(j,j)+tr[i<<1|1].qry(j,j));
    }

    int qry(int x1, int y1, int x2, int y2) {
        int ret=0;
        for (x1+=n,x2+=n; x1<=x2; x1>>=1,x2>>=1) {
            if (x1&1) ret+=tr[x1++].qry(y1,y2);
            if (~x2&1) ret+=tr[x2--].qry(y1,y2);
        }
        return ret;
    }
};

int N,M;
seg2d S;

int main() {
    fio();

    cin>>N>>M;
    
    S.rst(N,N);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int x; cin>>x;
            S.upd(i,j,x);
        }
    }

    while (M--) {
        int w; cin>>w;
        if (w==0) {
            int x,y,c;
            cin>>x>>y>>c;
            S.upd(x,y,c);
        }
        else {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<S.qry(x1,y1,x2,y2)<<endl;
        }
    }
    return 0;
}
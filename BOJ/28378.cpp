#include <bits/stdc++.h>
using namespace std;

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
const int MAX = 22; // PLZ CHK!

typedef array<int,MAX> perm;
perm ID;
int W,H,Q;

struct seg{
    vector<perm> tr;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2, ID);
    }

    perm mrg(perm a, perm b) {
        perm c;
        for (int i=1; i<MAX; i++) c[i]=a[b[i]];
        return c;
    }
    
    void upd(int nd, int le, int ri, int i, perm v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd]=v;
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = mrg(tr[nd<<1],tr[nd<<1|1]);
    }
    
    perm qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return ID;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return mrg(qry(nd<<1, le, md, ql, qr), qry(nd<<1|1, md+1, ri, ql, qr));
    }

    perm qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
    void upd(int i, perm v) {
        upd(1, 0, n-1, i, v);
    }
};

int ans(perm a) {
    int v[MAX]={0}, ret=W;
    for (int i=1; i<=W; i++) {
        if (v[i]) continue;
        ret--;
        for (int j=i; !v[j]; j=a[j]) v[j]=1;
    }
    return ret;
}

int main() {
    fio();
    for (int i=1; i<MAX; i++) ID[i]=i;

    cin>>W>>H>>Q;
    seg SS;
    SS.rst(H+10);

    while (Q--) {
        int y,x1,x2;
        cin>>y>>x1>>x2;

        y=H-y+1;
        perm O=ID;
        swap(O[min(x1,x2)],O[max(x1,x2)]);

        perm E=SS.qry(y,y);
        if (E==ID) SS.upd(y,O);
        else SS.upd(y,ID);

        perm q=SS.qry(1,H);
        cout<<ans(q)<<endl;
    }

    return 0;
}
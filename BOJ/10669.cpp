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
const int MAX = 1010; // PLZ CHK!

struct pt{
    int x,y; char z;
    bool operator < (const pt &ot) const {
        if (x==ot.x) return y<ot.y;
        return x<ot.x;
    }
};

struct SEG{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
    }
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd] = v;
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    ll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return 0;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return qry(nd<<1, le, md, ql, qr)+qry(nd<<1|1, md+1, ri, ql, qr);
    }
    ll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<pt> a(n);
    for (auto &[x,y,z]:a) cin>>x>>y>>z;
    sort(all(a));

    pii ans={0,0};
    for (int i=0; i<n; i++) {
        SEG sh,sg; 
        sg.rst(MAX);
        
        int p1=i, p2=i;
        while (p2<n && a[p2].x==a[i].x) {
            if (a[p2].z=='G') sg.upd(a[p2].y, 1);
            p2++;
        }
        
        for (int j=i; j>=0; j--) {
            while (p1>=0 && a[p1].x==a[j].x) {
                if (a[p1].z=='G') sg.upd(a[p1].y, 1);    
                p1--;
            }

            if (a[j].z=='H') {
                int xl=a[j].x, xr=a[i].x;
                int yl=min(a[j].y, a[i].y), yh=max(a[j].y, a[i].y);
                
                if (sg.qry(yl,yh)>0) {
                    ans=max(ans, make_pair(1,0));
                    continue;
                }

                int le=yh, ri=1000;
                int mxy=0, mny=1000;
                while (le<=ri) {
                    int md=(le+ri)>>1;
                    if (sg.qry(yh,md)==0) {
                        le=md+1;
                        mxy=md;
                    }
                    else ri=md-1;
                }

                le=0, ri=yl;
                while (le<=ri) {
                    int md=(le+ri)>>1;
                    if (sg.qry(md,yl)==0) {
                        ri=md-1;
                        mny=md;
                    }
                    else le=md+1;
                }

                int cnt=0;
                int y1=MAX, y2=0;
                for (int k=j; k<=i; k++) {
                    if (a[k].z=='H' && mny<=a[k].y && a[k].y<=mxy) {
                        cnt++, y1=min(y1, a[k].y), y2=max(y2, a[k].y);
                    }
                }

                if (ans.F<cnt) {
                    ans.F=cnt;
                    ans.S=(xr-xl)*(y2-y1);
                }
                else if (ans.F==cnt) {
                    ans.S=min(ans.S, (xr-xl)*(y2-y1));
                }
            }
        }
    }

    cout<<ans.F<<endl<<ans.S;
    return 0;
}
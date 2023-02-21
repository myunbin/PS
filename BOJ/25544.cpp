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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

struct segtr{
    //0-indexed!
    vector<int> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1, 0);
    }

    void upd(int i, int v) {
        tr[i+n] = max(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    int qry(int l, int r) {
        if (l>r) return 0;
        int ret = 0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, tr[l++]);
            if (~r&1) ret = max(ret, tr[r--]);
        }
        return ret;
    }
};

struct pt {
    int x,y,idx;
};

int main() {
    fio();
    int n;
    cin>>n;

    vector<int> ny(n);
    vector<pt> p(n);
    for (int i=0; i<n; i++) {
        cin>>p[i].x>>p[i].y;
        p[i].idx=i;
        ny[i]=p[i].y;
    }

    cmprs(ny);
    for (auto &[x,y,i]:p) {
        y=lb(all(ny),y)-ny.begin()+1;
    }
    
    int d1[MAX]={0}, d2[MAX]={0}, d3[MAX]={0}, d4[MAX]={0};
    segtr seg1, seg2, seg3, seg4;
    seg1.rst(MAX), seg2.rst(MAX), seg3.rst(MAX), seg4.rst(MAX);

    sort(all(p), [](pt a, pt b){
        if (a.x==b.x) return a.y>b.y;
        return a.x<b.x;
    });
    
    for (int i=0; i<n; i++) {
        d1[p[i].idx]=seg1.qry(0, p[i].y-1)+1;
        seg1.upd(p[i].y, d1[p[i].idx]);
    }

    sort(all(p), [](pt a, pt b){
        if (a.x==b.x) return a.y<b.y;
        return a.x>b.x;
    });

    for (int i=0; i<n; i++) {
        d2[p[i].idx]=seg2.qry(p[i].y+1, MAX-1)+1;
        seg2.upd(p[i].y, d2[p[i].idx]);
    }

    sort(all(p), [](pt a, pt b){
        if (a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });

    for (int i=0; i<n; i++) {
        d3[p[i].idx]=seg3.qry(p[i].y+1, MAX-1)+1;
        seg3.upd(p[i].y, d3[p[i].idx]);
    }

    sort(all(p), [](pt a, pt b){
        if (a.x==b.x) return a.y>b.y;
        return a.x>b.x;
    });

    for (int i=0; i<n; i++) {
        d4[p[i].idx]=seg4.qry(0, p[i].y-1)+1;
        seg4.upd(p[i].y, d4[p[i].idx]);
    }

    int ans=-1;
    for (int i=0; i<n; i++) {
        int idx=p[i].idx;
        if ((d1[idx]>=2) && (d2[idx]>=2) && (d3[idx]>=2) && (d4[idx]>=2)) {
            ans=max(ans, d1[idx]+d2[idx]+d3[idx]+d4[idx]-3);
        } 
    }
    cout<<(ans!=-1?n-ans:-1);
    return 0;
}
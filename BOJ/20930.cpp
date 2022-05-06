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
const int MAX = 202020; // PLZ CHK!

struct pt {
    int s,e,i;
    bool operator < (const pt &o) const {
        if (s==o.s) return e>o.e;
        return s<o.s;
    }
};

int p[MAX];
int f(int a) {
    if (a==p[a]) return a;
    return p[a]=f(p[a]);
}

void m(int a, int b) {
    a=f(a), b=f(b);
    if (a==b) return;
    p[b]=a;
}

void ff(vector<pt> &a) {
    pii lst={-INF,-INF};
    for (auto [s,e,i]:a) {
        if (s<=lst.F) m(i,lst.S);
        lst=max(lst,{e,i});
    }
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    int n,q;
    cin>>n>>q;
    vector<pt> xx, yy;

    for (int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        xx.pb({min(x1,x2),max(x1,x2),i});
        yy.pb({min(y1,y2),max(y1,y2),i});
    }
    sort(all(xx)), sort(all(yy));

    ff(xx),ff(yy);
    while (q--) {
        int u,v; 
        cin>>u>>v;
        cout<<(f(--u)==f(--v))<<endl;   
    }    
    return 0;
}
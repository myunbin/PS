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
const int MAX = 20202; // PLZ CHK!

struct ev{
    int x,y1,y2,s;
    bool operator < (const ev &ot) const {
        if (x==ot.x) return s>ot.s;
        return x<ot.x;
    }
};

int sm[MAX<<2], on[MAX<<2];

void upd(int nd, int le, int ri, int ql, int qr, int v) {
    if (qr<le || ri<ql) return;
    
    if (ql<=le && ri<=qr) sm[nd]+=v;
    else {
        int md=(le+ri)>>1;
        upd(nd<<1, le, md, ql, qr, v);
        upd(nd<<1|1, md+1, ri, ql, qr, v);
    }

    if (sm[nd]>0) on[nd]=ri-le+1;
    else {
        if (le==ri) on[nd]=0;
        else on[nd]=on[nd<<1]+on[nd<<1|1];
    }
}

int main() {
    fio();
    
    int n;
    cin>>n;

    vector<ev> vv, vh;
    const int OFF=10001;

    for (int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int mnx=min(x1,x2), mxx=max(x1,x2);
        int mny=min(y1,y2), mxy=max(y1,y2);
        vv.pb({mnx, OFF+mny, OFF+mxy-1, 1});
        vv.pb({mxx, OFF+mny, OFF+mxy-1, -1});

        vh.pb({mny, OFF+mnx, OFF+mxx-1, 1});
        vh.pb({mxy, OFF+mnx, OFF+mxx-1, -1});        
    }

    sort(all(vv)), sort(all(vh));

    // for (auto [x,y1,y2,s]:v) {
    //     cout<<x<<sp<<y1-OFF<<sp<<y2-OFF<<sp<<s<<endl;
    // }
    
    int ans=0;

    for (auto [x,y1,y2,s]:vv) {
        int bf=on[1];
        upd(1,0,MAX,y1,y2,s);
        int af=on[1];
        ans+=abs(af-bf);
        // cout<<abs(af-bf)<<endl;
    }

    memset(sm,0,sizeof sm), memset(on,0,sizeof on);

    for (auto [y,x1,x2,s]:vh) {
        int bf=on[1];
        upd(1,0,MAX,x1,x2,s);
        int af=on[1];
        ans+=abs(af-bf);
    }

    cout<<ans;
    
    return 0;
}
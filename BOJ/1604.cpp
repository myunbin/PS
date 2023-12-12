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

int ccw(pll p1, pll p2, pll p3) {
    ll t1=p1.F*p2.S+p2.F*p3.S+p3.F*p1.S;
	ll t2=p1.S*p2.F+p2.S*p3.F+p3.S*p1.F;
	
	if(t1==t2) return 0;
	else return t1<t2 ?-1:1; 
}

int ist(pll a1, pll a2, pll b1, pll b2) {
    ll c1=ccw(a1,a2,b1)*ccw(a1,a2,b2);
    ll c2=ccw(b1,b2,a1)*ccw(b1,b2,a2);

    if (c1==0 && c2==0) {
        if (a1>a2) swap(a1,a2);
        if (b1>b2) swap(b1,b2);
        return b1<=a2&&a1<=b2;
    }
    return (c1<=0 && c2<=0);
}

bool in(pll a1, pll a2, pll b1, pll b2) {
    auto [x1,y1]=a1; auto [x2,y2]=a2; auto [x3,y3]=b1; auto [x4,y4]=b2;
    ll mo=(x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
    ll xj=(x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4);
    ll yj=(x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4);
    // cout<<xj<<sp<<mo<<sp<<yj<<sp<<mo<<endl;
    if (mo<0) return (10ll*mo<xj&&xj<-10ll*mo && 10ll*mo<yj&&yj<-10ll*mo);
    else return (-10ll*mo<xj&&xj<10ll*mo && -10ll*mo<yj&&yj<10ll*mo);
}

vector<pll> SQ={{-10,10},{10,10},{10,-10},{-10,-10}};

int main() {
    fio();

    int N;
    cin>>N;
    vector<pair<pll,pll>> seg;
    for (int i=0; i<N; i++) {
        pll a,b;
        cin>>a.F>>a.S>>b.F>>b.S;
        seg.pb({a,b});
    }

    int ans=1; N=sz(seg);
    for (int i=0; i<N; i++) {
        bool ok=0;
        for (int j=0; j<4; j++) {
            if (ist(seg[i].F,seg[i].S,SQ[j],SQ[(j+1)%4])) {
                ok=1;
                break;
            }
        }
        if (!ok) continue;

        int t=1;
        for (int j=0; j<i; j++) {
            auto [a1,a2]=seg[i]; auto [b1,b2]=seg[j];
            if (ist(a1,a2,b1,b2) && in(a1,a2,b1,b2)) t++;
        }
        ans+=t;
    }

    cout<<ans;
    return 0;
}
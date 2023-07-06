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

int s,n,k,r1,r2,c1,c2;
vector<string> go(int t, int x1, int x2, int y1, int y2) {
    if (t==0) {
        vector<string> ret;
        ret.pb("0");
        return ret;
    }

    int m=1; for (int i=0; i<t-1; i++) m*=n;
    vector<string> ret;
    for (int i=0; i<n; i++) {
        int mnx=m*i, mxx=m*(i+1)-1;
        if (mxx<x1 || x2<mnx) continue;
        
        vector<string> tmp;
        for (int j=0; j<n; j++) {
            int mny=m*j, mxy=m*(j+1)-1;
            if (mxy<y1 || y2<mny) continue;

            int xx1=max(0,x1-mnx), xx2=min(mxx-mnx, x2-mnx);
            int yy1=max(0,y1-mny), yy2=min(mxy-mny, y2-mny);
            vector<string> res;
            if ((n-k)/2<=i&&i<(n+k)/2 && (n-k)/2<=j&&j<(n+k)/2) {
                string one;
                for (int k=yy1; k<=yy2; k++) one+='1';
                for (int k=xx1; k<=xx2; k++) res.pb(one);
            }
            else res=go(t-1,xx1,xx2,yy1,yy2);

            if (tmp.empty()) for (string tt:res) tmp.pb(tt);
            else {
                for (int k=0; k<sz(tmp); k++) {
                    tmp[k]+=res[k];
                }
            }
        }
        for (string tt:tmp) ret.pb(tt);
    }

    return ret;
}
int main() {
    fio();
    
    cin>>s>>n>>k>>r1>>r2>>c1>>c2;
    vector<string> ans=go(s,r1,r2,c1,c2);
    for (string x:ans) cout<<x<<endl;

    return 0;
}
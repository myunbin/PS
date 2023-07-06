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
const int MAX = 10101; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    
    vector<int> d;
    d.pb(0);
    for (int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        if (y==0) continue;
        d.pb((d.back()+y+4)%4);
    }
    // for (int i=0; i<n; i++) cout<<d[i]<<sp; cout<<endl;
    int mxx=0, mxy=0, mnx=0, mny=0, cx=0, cy=0;
    for (int i=0; i<n; i++) {
        if (d[i]==0) {
            cout<<(mxx-cx+1)<<sp;
            cx=mxx+1;
        }
        else if (d[i]==1) {
            cout<<(mxy-cy+1)<<sp;
            cy=mxy+1;
        }
        else if (d[i]==2) {
            cout<<(cx-mnx+1)<<sp;
            cx=mnx-1;
        }
        else {
            cout<<(cy-mny+1)<<sp;
            cy=mny-1;
        }

        mxx=max(mxx, cx);
        mxy=max(mxy, cy);
        mnx=min(mnx, cx);
        mny=min(mny, cy);
    }
    return 0;
}
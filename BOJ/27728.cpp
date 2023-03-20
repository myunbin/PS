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
const int MAX = 555; // PLZ CHK!

struct tp{
    int sx,sy,l,i;
};

int main() {
    fio();
    int n,q;
    cin>>n>>q;
    
    ll a[MAX][MAX]={0}, p[MAX][MAX]={0};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
            p[i][j]=p[i][j-1]+a[i][j];
        }
    }

    vector<tp> qr(q);
    for (int i=0; i<q; i++) {
        cin>>qr[i].sx>>qr[i].sy>>qr[i].l;
        qr[i].i=i;
    }

    sort(all(qr), [](tp a, tp b){
        return a.sx-a.l<b.sx-b.l;
    });

    vector<ll> ans(q);
    int ci=1;
    ll mn[MAX];
    fill(mn+1,mn+n+1,LINF);
    for (auto [sx,sy,l,i]:qr) {
        while (ci<=sx-l) {
            for (int j=1; j<=n; j++) mn[j]=min(mn[j], p[ci][n]-p[ci][j-1]);
            ci++;
        }
        ll v=LINF;
        for (int j=sy-1; j<=n; j++) {
            ll t=p[sx][j]-p[sx][sy-1]+mn[j+1];
            v=min(v,t);
        }
        ans[i]=v;
    }

    for (auto x:ans) cout<<x<<endl;
    return 0;
}
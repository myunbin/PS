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

void init(string &s) {
    reverse(all(s)), s+="!", reverse(all(s));
}

void pf(string &s, string &t, vector<int> &pf) {
    int n=sz(s)-1, m=sz(t)-1, j=1;
    for (int i=1; i<=m; i++) {
        while (j<=n && s[j]!=t[i]) j++;
        pf[i]=j++;
    }
}

void sf(string &s, string &t, vector<int> &sf) {
    int n=sz(s)-1, m=sz(t)-1, j=n;
    for (int i=m; i>=1; i--) {
        while (j>=1 && s[j]!=t[i]) j--;
        sf[i]=j--;
    }   
}

void cc(string &s, vector<vector<int>> &p) {
    int n=sz(s)-1;
    p.resize(26,vector<int>(n+1));
    for (int i=0; i<='z'-'a'; i++) {
        for (int j=1; j<=n; j++) {
            p[i][j]=p[i][j-1]+(s[j]==(char)(i+'a'));
        }
    }
}

void solve() {
    string x,y,w;
    cin>>x>>y>>w;
    int n=sz(x),m=sz(y),k=sz(w);
    init(x),init(y),init(w);

    vector<int> xp(k+1),xs(k+1),yp(k+1),ys(k+1);
    pf(x,w,xp), pf(y,w,yp);
    sf(x,w,xs), sf(y,w,ys);

    vector<vector<int>> xc,yc;
    cc(x,xc), cc(y,yc);

    // for (int i=1; i<=k; i++) cout<<yp[i]<<sp; cout<<endl;
    // for (int i=1; i<=k; i++) cout<<ys[i]<<sp; cout<<endl; cout<<endl;

    for (int i=1; i<=k+1; i++) {
        int xl,xr,yl,yr;
        if (i==k+1) xl=xp[k]+1,xr=n,yl=yp[k]+1,yr=m;
        else xl=xp[i-1]+1,xr=xs[i]-1,yl=yp[i-1]+1,yr=ys[i]-1;

        // cout<<yl<<sp<<yr<<endl;

        if (xl>xr || yl>yr) continue;

        for (int c=0; c<='z'-'a'; c++) {
            int c1=xc[c][xr]-xc[c][xl-1];
            int c2=yc[c][yr]-yc[c][yl-1];
            if (c1 && c2) {
                cout<<1<<endl;
                return;
            }   
        }
    }

    cout<<0<<endl;
}

int main() {
    fio();
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
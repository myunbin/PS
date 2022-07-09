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
const int MAX = 1010; // PLZ CHK!

int n,m;
string a,b;
int d[MAX][MAX];

int go(int i, int j) {
    if (i>=n || j>=m) return 0;
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    if (i<n && j<m) ret=max(ret, (a[i]==b[j]?3:-2)+go(i+1,j+1));
    if (i<n) ret=max(ret, -2+go(i+1,j));
    if (j<m) ret=max(ret, -2+go(i,j+1));
    return ret;
}

string aa,bb;

void trk(int i, int j) {
    if (i>=n || j>=m) return;
    if (go(i,j)==0) return;

    if (go(i,j)==(a[i]==b[j]?3:-2)+go(i+1,j+1)) aa+=a[i], bb+=b[j], trk(i+1,j+1);
    else if (go(i,j)==-2+go(i+1,j)) aa+=a[i], trk(i+1,j);
    else if (go(i,j)==-2+go(i,j+1)) bb+=b[j], trk(i,j+1);
}
int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>n>>a>>m>>b;
    int mx=-1; pii s;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mx<go(i,j)) {
                mx=go(i,j);
                s={i,j};
            }
        }
    }
    cout<<mx<<endl;
    trk(s.F,s.S);
    cout<<aa<<endl<<bb<<endl;
    return 0;
}
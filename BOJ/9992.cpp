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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 111; // PLZ CHK!

string s;
int dp[MAX][MAX];

bool okp(string a, string b) {
    if (sz(a)>sz(b)) swap(a,b);
    if (sz(b)<2) return 0;

    for (int i=0; i<sz(a); i++) {
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

bool oks(string a, string b) {
    if (sz(a)>sz(b)) swap(a,b);
    if (sz(b)<2) return 0;

    reverse(all(a)), reverse(all(b));
    for (int i=0; i<sz(a); i++) {
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

const int MOD=2014;

int go(int i, int j) {
    if (i==j) return 1;
    
    int &ret=dp[i][j];
    if (ret!=-1) return ret;

    ret=1;
    for (int k=i; k<j; k++) {
        string x=s.substr(i,k-i+1), y=s.substr(k+1, j-k);
        if (okp(x,y)) {
            if (sz(x)>sz(y)) ret=(ret+go(i,k))%MOD;
            if (sz(x)<sz(y)) ret=(ret+go(k+1,j))%MOD;
        }
        if (oks(x,y)) {
            if (sz(x)>sz(y)) ret=(ret+go(i,k))%MOD;
            if (sz(x)<sz(y)) ret=(ret+go(k+1,j))%MOD;
        }
    }

    return ret;
}

int main() {
    fio();
    memset(dp,-1,sizeof dp);

    cin>>s;
    cout<<(go(0,sz(s)-1)-1+MOD)%MOD;
    return 0;
}
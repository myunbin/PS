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
const int MAX = 22; // PLZ CHK!

int n;
ll d[MAX][MAX], d2[MAX][MAX];
string s;

ll go(int i, int j);
ll go2(int i, int j);

ll go2(int i, int j) {
    if (i>j) return 0;
    if (i==j) return 1ll*(s[i]-'0');
    ll &ret=d2[i][j];
    if (ret!=LINF) return ret;

    for (int k=i; k<j-1; k+=2) {
        if (s[k+1]=='+') ret=min(ret, go2(i,k)+go2(k+2,j));
        if (s[k+1]=='-') ret=min(ret, go2(i,k)-go(k+2,j));
        if (s[k+1]=='*') {
            ret=min(ret, go2(i,k)*go2(k+2,j));
            ret=min(ret, go(i,k)*go2(k+2,j));
            ret=min(ret, go2(i,k)*go(k+2,j));
            ret=min(ret, go(i,k)*go(k+2,j));
        }
    }
    return ret;
}

ll go(int i, int j) {
    if (i>j) return 0;
    if (i==j) return 1ll*(s[i]-'0');
    ll &ret=d[i][j];
    if (ret!=-LINF) return ret;

    for (int k=i; k<j-1; k+=2) {
        if (s[k+1]=='+') ret=max(ret, go(i,k)+go(k+2,j));
        if (s[k+1]=='-') ret=max(ret, go(i,k)-go2(k+2,j));
        if (s[k+1]=='*') {
            ret=max(ret, go(i,k)*go(k+2,j));
            ret=max(ret, go2(i,k)*go2(k+2,j));
        }
    }
    return ret;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) d[i][j]=-LINF, d2[i][j]=LINF;

    cin>>n>>s;
    cout<<go(0,n-1);

    return 0;
}
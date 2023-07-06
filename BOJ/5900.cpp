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
const int MAX = 3333; // PLZ CHK!

int c[MAX][11];
int n,k;

string ans;
void go(int i, int j, int x) {
    // base case
    if (i==0) return;
    
    if (x<=c[i-1][j]) {
        ans+='0';
        go(i-1, j, x);
    }
    else {
        ans+='1';
        go(i-1, j-1, x-c[i-1][j]);
    }
}

int main() {
    fio();
    cin>>n>>k;

    if (k==1) {
        cout<<1;
        for (int i=0; i<n-1; i++) cout<<0;
        return 0;
    }

    c[0][0]=1;
    for (int i=1; i<MAX; i++) {
        c[i][0]=1;
        for (int j=1; j<=min(i,10); j++) {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]=min(c[i][j], (int)1e7);
        }
    }
   
    go(MAX-1, k, n);
    int p=0;
    while (ans[p]=='0') p++;

    for (int i=p; i<sz(ans); i++) cout<<ans[i];
    return 0;
}
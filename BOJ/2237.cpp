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

const int MAXT=10000;
const int MAXN=100;

int N,T,A[MAXN+10],P[MAXN+10];
int d[MAXN+10][2*MAXT+10];

void f(int i, int j) {
    if (i==2) {
        P[i]=0;
        return;
    }
    
    if (d[i][j]==d[i-1][j-A[i]]) {
        P[i]=1;
        f(i-1,j-A[i]);
    }
    else {
        P[i]=0;
        f(i-1,j+A[i]);
    }
}

int main() {
    fio();
    cin>>N>>T; T+=MAXT;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
    }  

    d[2][MAXT+A[1]-A[2]]=1;    
    for (int i=3; i<=N; i++) {
        for (int j=0; j<=2*MAXT; j++) {
            if (j-A[i]>=0) d[i][j]|=d[i-1][j-A[i]];
            if (j+A[i]<=2*MAXT) d[i][j]|=d[i-1][j+A[i]];
        }
    }

    f(N,T);
    vector<int> ans;
    for (int i=N-1,j=N; i>=2 && j>=2; i--) {
        if (P[i]==0) {
            while (j>=2 && i<j && P[j]) {
                ans.pb(i);
                j--;
            }
            j--;
        }
    }
    while (sz(ans)<N-1) ans.pb(1);

    for (int x:ans) cout<<x<<endl;
    return 0;
}
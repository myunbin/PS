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
const int MAX = 5050; // PLZ CHK!

int N,X[MAX][MAX];
ll A[MAX],P[MAX],D[MAX][MAX];

void solve() {
    memset(A,0,sizeof A);
    memset(D,0,sizeof D);

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        P[i]=P[i-1]+A[i];
        X[i][i+1]=i;
    }

    for (int k=2; k<=N; k++) {
        for (int i=1; i+k<=N+1; i++) {
            D[i][i+k]=LINF;
            for (int j=X[i][i+k-1]; j<=X[i+1][i+k]; j++) {
                if (j<=i) continue;
                if (j>=i+k) break;
                if (D[i][i+k]>D[i][j]+D[j][i+k]+P[i+k-1]-P[i-1]) {
                    D[i][i+k]=D[i][j]+D[j][i+k]+P[i+k-1]-P[i-1];
                    X[i][i+k]=j;
                }
            }
        }
    }

    cout<<D[1][N+1]<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
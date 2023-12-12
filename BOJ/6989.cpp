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
const int MAX = 155; // PLZ CHK!

int N,K,A[MAX],P[MAX],B[MAX][MAX];
bitset<MAX*MAX*100/2> D[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=2; i<=N+1; i++) {
        cin>>A[i];
        P[i]=P[i-1]+A[i];
    }
    cin>>K;

    for (int i=2; i<=N+1; i++) {
        B[i][i]=A[i];
        for (int j=i+1; j<=N+1; j++) {
            B[i][j]=B[i][j-1]+P[j]-P[i-1];
        }
    }

    if (B[2][N+1]<K) {
        cout<<K;
        return 0;
    }

    D[0].set(0), D[1].set(0);
    for (int i=2; i<=N+1; i++) {
        for (int j=0; j<=i-1; j++) {
            // for (int x=0; x<=B[2][N+1]; x++) {
            //     if (x-B[j+2][i]>=0) D[i][x]|=D[j][x-B[j+2][i]];
            // }
            D[i]|=(D[j]<<B[j+2][i]);
        }
    }

    // for (int x=K; x<=B[2][N+1]; x++) {
    //     if (!D[N+1][x]) {
    //         cout<<x<<sp;
    //         break;
    //     }
    // }

    int ans;
    for (ans=K; D[N+1].test(ans); ans++);
    cout<<ans;

    return 0;
}
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
const int MAX = 555; // PLZ CHK!

int N,X[MAX],A[MAX],B[MAX];
int d[MAX][MAX];

int go(int i, int j) {
    if (i==N) return (X[N]-A[N]<=X[j]);
    if (j==N) return 0;

    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    int t=max(i,j)+1;

    for (int k=t; k<=N; k++) {
        if (X[i]+A[i]>=X[k]) {
            ret+=go(k,j);
            ret%=1000;
        }
    }

    for (int k=t; k<=N; k++) {
        if (X[j]>=X[k]-A[k] && B[k]) {
            ret+=go(i,k);
            ret%=1000;
        }
    }
    
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>X[i]>>A[i]>>B[i];
    }

    cout<<go(1,1);
    
    return 0;
}
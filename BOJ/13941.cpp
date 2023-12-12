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
const int MAX = 20; // PLZ CHK!

int N,K;
int C[MAX][MAX],D[1<<MAX];

int go(int s) {
    if (__builtin_popcount(s)==K) return 0;
    int &ret=D[s];
    if (ret!=-1) return ret;

    ret=INF;
    for (int i=0; i<N; i++) {
        if (!(s&(1<<i))) continue;
        for (int j=0; j<N; j++) {
            if (i==j || !(s&(1<<j))) continue;
            ret=min(ret, C[i][j]+go(s^(1<<i)));
            ret=min(ret, C[j][i]+go(s^(1<<j)));
        }
    }
    return ret;
}

int main() {
    fio();
    memset(D,-1,sizeof D);
    cin>>N>>K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>C[i][j];
        }
    }

    cout<<go((1<<N)-1);
    return 0;
}
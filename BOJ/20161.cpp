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
const int MAX = 111; // PLZ CHK!

int N,K,A[MAX],B[MAX],d[MAX][(1<<10)+10];

int go(int i, int s) {
    if (i+K>N+1) {
        for (int j=0; j<K; j++) {
            bool on=s&(1<<j);
            if (on^B[i+j]) return INF;
        }
        return 0;
    }

    int &ret=d[i][s];
    if (ret!=-1) return ret;

    ret=INF;
    if ((s&1)==B[i]) {
        int ns=(s>>1)|(A[i+K]<<(K-1));
        ret=min(ret, go(i+1,ns));
    }

    int ts=s;
    for (int j=0; j<K; j++) ts^=(1<<j);

    for (int j=0; j<K; j++) {
        int ns=ts^(1<<j);
        if ((ns&1)==B[i]) {
            ns=(ns>>1)|(A[i+K]<<(K-1));
            ret=min(ret, 1+go(i+1,ns));
        }
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N>>K;
    for (int i=0; i<N; i++) cin>>A[i];
    for (int i=0; i<N; i++) cin>>B[i];

    int s=0;
    for (int i=0; i<K; i++) {
        if (A[i]) s^=(1<<i);
    }

    int ans=go(0,s);
    cout<<(ans>=INF?-1:ans);
    
    return 0;
}
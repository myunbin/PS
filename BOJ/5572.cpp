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
const int MAX = 1010; // PLZ CHK!

int N,M,H,K,S[MAX];
int ld[MAX][MAX], ldi[MAX][MAX], res[MAX];
vector<int> sw[101010];

int sum=0;
void go(int cur, int hgt, int prv, int idx) {
    if (hgt==H) {
        res[idx]=S[cur];
        if (idx<=K) sum+=S[cur];
        return;
    }
    
    if (cur==prv && ld[cur][hgt]) {
        sw[ldi[cur][hgt]].pb(idx);
        go(ld[cur][hgt], hgt, cur, idx);
    }
    else go(cur, hgt+1, cur, idx);
}

int main() {
    fio();
    cin>>N>>M>>H>>K;
    for (int i=1; i<=N; i++) cin>>S[i];
    
    for (int i=1; i<=M; i++) {
        int a,b;
        cin>>a>>b;
        ld[a][b]=a+1, ld[a+1][b]=a;
        ldi[a][b]=ldi[a+1][b]=i;
    }

    for (int i=1; i<=N; i++) go(i,0,i,i);

    int ans=sum;
    for (int i=1; i<=M; i++) {
        int a=sw[i][0], b=sw[i][1];
        if (a>b) swap(a,b);

        if (a<=K && b<=K) continue;
        else if (a>K && b>K) continue;
        else if (a<=K && b>K) {
            ans=min(ans, sum-res[a]+res[b]);
        }
    }
    
    cout<<ans;
    return 0;
}
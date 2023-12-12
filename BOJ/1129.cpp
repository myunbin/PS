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
const int MAX = 55; // PLZ CHK!

int N,A[MAX];
int d[MAX][MAX];

int go(int i, int j, int x) {
    if (i==N) return abs(A[j]-A[N])<=x;
    if (j==N) return abs(A[i]-A[N])<=x;

    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=0;
    int k=max(i,j)+1;
    if (abs(A[i]-A[k])<=x) ret|=go(k,j,x);
    if (abs(A[j]-A[k])<=x) ret|=go(i,k,x);

    return ret;
}

bool ok(int x) {
    memset(d,-1,sizeof d);
    return go(1,1,x);
}

vector<int> ans1,ans2;
void trk(int i, int j, int x) {
    if (i==N || j==N) return;

    int k=max(i,j)+1;
    int d1=abs(A[i]-A[k]), d2=abs(A[j]-A[k]);
    if ((d1<=x && go(k,j,x)) && (d2<=x && go(i,k,x))) {
        ans1.pb(A[k]);
        trk(k,j,x);
    }
    else if (d1<=x && go(k,j,x)) {
        ans1.pb(A[k]);
        trk(k,j,x);
    }
    else if (d2<=x && go(i,k,x)) {
        ans2.pb(A[k]);
        trk(i,k,x);
    }
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];
    sort(A+1,A+N+1);

    int le=0, ri=A[N]-A[1], ans=ri;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ans=md;
            ri=md-1;
        }
        else le=md+1;
    }

    memset(d,-1,sizeof d);
    go(1,1,ans);

    ans1.pb(A[1]);
    trk(1,1,ans);
    reverse(all(ans2));

    for (int x:ans1) cout<<x<<sp; for (int x:ans2) cout<<x<<sp;
    return 0;
}
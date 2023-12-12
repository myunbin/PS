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
const int MAX = 15; // PLZ CHK!

int N,A[MAX+10];
int d[MAX*2+10][(1<<MAX)+1];

int go(int i, int s) {
    if (i>2*N) return INF;
    if (i%2 && s==(1<<N)-1) return 0;
    
    int &ret=d[i][s];
    if (ret!=-1) return ret;

    ret=INF;
    if (i%2==0) {
        for (int x=0; x<N; x++) {
            for (int y=x+1; y<N; y++) {
                if ((s&(1<<x)) && (s&(1<<y))) continue;
                ret=min(ret, max(A[x],A[y])+go(i+1,s|(1<<x)|(1<<y)));
            }
        }
    }
    else {
        for (int x=0; x<N; x++) {
            if ((s&(1<<x))==0) continue;
            ret=min(ret, A[x]+go(i+1,s^(1<<x)));
        }
    }

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>N;
    for (int i=0; i<N; i++) cin>>A[i];

    cout<<go(0,0);

    return 0;
}
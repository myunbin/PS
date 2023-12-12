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
const int MAX = 1010101; // PLZ CHK!

ll N,P[MAX],Q[MAX],X[MAX],Y[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>P[i];
    for (int i=1; i<=N; i++) cin>>Q[i];

    for (int i=1; i<=N; i++) X[i]=P[i]+Q[i];
    for (int i=1; i<=N; i++) Y[i]=P[i]-Q[i];

    sort(X+1,X+N+1), sort(Y+1,Y+N+1);
    ll mx=0,sx=0,sy=0;
    for (int i=1; i<=N; i++) {
        mx+=1ll*(i-1)*X[i]-sx;
        mx+=1ll*(i-1)*Y[i]-sy;
        sx+=X[i], sy+=Y[i];
    }

    ll tt=0, s1=0, s2=0;
    sort(P+1,P+N+1), sort(Q+1,Q+N+1);
    for (int i=1; i<=N; i++) {
        tt+=1ll*(i-1)*P[i]-s1;
        tt+=1ll*(i-1)*Q[i]-s2;
        s1+=P[i], s2+=Q[i];
    }
    tt*=2;
    
    cout<<tt-mx;
    return 0;
}
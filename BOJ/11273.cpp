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
const int MAX = 10101; // PLZ CHK!

int G,M;
vector<int> X[MAX];

struct Cir{
    int x,y,r;
};

Cir S[MAX*2];

int main() {
    fio();

    cin>>G;
    for (int i=0; i<G; i++) {
        int x,y; cin>>x>>y;
        X[x].pb(y);
    }
    cin>>M;
    for (int i=0; i<M; i++) {
        cin>>S[i].x>>S[i].y>>S[i].r;
    }

    int ans=0;
    for (int x=0; x<MAX; x++) {
        int Y[MAX]={0};
        for (int i=0; i<M; i++) {
            auto [a,b,r]=S[i];
            if (a-r<=x && x<=a+r) {
                int dy=(int)sqrt(1.0*r*r-1.0*(a-x)*(a-x));
                Y[max(0,b-dy)]++, Y[min(10001,b+dy+1)]--;
            }
        }

        for (int y=1; y<MAX; y++) Y[y]+=Y[y-1];
        
        for (int y:X[x]) {
            if (Y[y]>0) ans++;
        }
    }

    cout<<G-ans;

    return 0;
}
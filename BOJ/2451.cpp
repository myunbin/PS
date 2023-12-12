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
const int MAX = 3030; // PLZ CHK!

int N; ll D[MAX];
vector<int> I[MAX],O[MAX];
vector<int> ans;

void trk(int i) {
    if (i==0) return;
    
    ll x=0,y=0;
    for (int j=i; j>=1; j--) {
        x+=ub(all(O[j]),i)-O[j].begin();
        y+=sz(I[j]);

        if (D[i]==D[j-1]+1ll*(i-j+1)*(i-j)/2-x+y-x) {
            ans.pb(i-j+1);
            trk(j-1);
            break;
        }
    }
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) {
        while (1) {
            int x; cin>>x;
            if (x==0) break;
            if (x<i) I[i].pb(x);
            else O[i].pb(x);
        }
        sort(all(I[i])), sort(all(O[i]));
    }

    D[0]=0;
    for (int i=1; i<=N; i++) {
        D[i]=LINF;

        ll x=0, y=0;
        for (int j=i; j>=1; j--) {
            x+=ub(all(O[j]),i)-O[j].begin();
            y+=sz(I[j]);
            D[i]=min(D[i], D[j-1]+1ll*(i-j+1)*(i-j)/2-x+y-x);
        }
    } 
    
    cout<<D[N]<<endl;
    trk(N); reverse(all(ans));
    cout<<sz(ans)<<sp; for (int x:ans) cout<<x<<sp;
    return 0;
}
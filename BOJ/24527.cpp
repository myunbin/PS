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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

ll h;

double p[MAX];

pll f(ll a, ll b) {
    ll le=1, ri=h;
    ll x=1, y=1;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        if (md*(md-1)/2+1 <= a) {
            x=md;
            le=md+1;
        }
        else ri=md-1;
    }

    y=a-(x-1)*x/2;
    //start = y, end = y+h-x, cnt = h-x+2
    double upd=(double)b/(double)(h-x+2);
    p[y]+=upd, p[y+h-x+2]-=upd;
    return {x,y};
}

int main() {
    fio();

    int q,r;
    cin>>h>>q>>r;
    for (int i=0; i<q; i++) {
        ll a,b;
        cin>>a>>b;
        f(a,b);
    }    

    double pp[MAX]={0.0};
    for (int i=1; i<=h+1; i++) p[i]+=p[i-1];
    for (int i=1; i<=h+1; i++) pp[i]=pp[i-1]+p[i];

    cout<<fixed;
    cout.precision(10);
    for (int i=0; i<r; i++) {
        int a,b;
        cin>>a>>b;
        cout<<pp[b]-pp[a-1]<<endl;
    }
    return 0;
}
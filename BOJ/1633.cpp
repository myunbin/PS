#include <bits/stdc++.h>
using namespace std;

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

int n;
vector<pii> a(1010);
int d[1010][16][16];

int go(int i, int x, int y) {
    if (i==n) {
        if (x==15 && y==15) return 0;
        return -INF;   
    }

    int &ret=d[i][x][y];
    if (ret!=-1) return ret;

    ret=go(i+1, x, y);
    if (x+1<=15) ret=max(ret, a[i].F+go(i+1, x+1, y));
    if (y+1<=15) ret=max(ret, a[i].S+go(i+1, x, y+1));
    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    
    while (!cin.eof()) {
        int x,y;
        cin>>x>>y;
        a[n++]={x,y};
    }
    
    cout<<go(0,0,0);

    return 0;
}
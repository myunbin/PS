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
const int MAX = 22; // PLZ CHK!

vector<vector<int>> a(MAX, vector<int>(MAX));
int ans=MAX*MAX;
int n;

void go(int i, vector<int> x, vector<int> y, vector<int> z, int cnt) {
    if (i==n) {
        for (int j=0; j<n; j++) {
            if (x[j]) return;
        }
        ans=min(ans, cnt);
        return;
    }

    for (int j=0; j<n; j++) {
        if (x[j]) {
            cnt++;
            z[j]=!z[j];
            y[j]=!y[j];
            if (j-1>=0) y[j-1]=!y[j-1];
            if (j+1<n) y[j+1]=!y[j+1];
        }
    }

    go(i+1,y,z,a[i+2],cnt);
}

void init(int j, vector<int> a0, vector<int> a1, int cnt) {
    if (j==n) {
        vector<int> tt(MAX,0);
        go(0,tt,a0,a1,cnt);
        return;
    }

    init(j+1, a0, a1, cnt);

    a0[j]=!a0[j];
    if (j-1>=0) a0[j-1]=!a0[j-1];
    if (j+1<n) a0[j+1]=!a0[j+1];
    a1[j]=!a1[j];
    init(j+1, a0, a1, cnt+1);
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>a[i][j];
        }
    }
    
    init(0,a[0],a[1],0);
    cout<<(ans==MAX*MAX?-1:ans);
    return 0;
}
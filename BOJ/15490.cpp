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

int N,A[MAX],D[2][MAX][MAX][2][2];

int go(int a, int i, int j, int x, int y) {
    if (i>j) {
        if (a) return (y==0);
        return (x==0);
    }

    int &ret=D[a][i][j][x][y];
    if (ret!=-1) return ret;

    ret=0;
    if (a==0) {
        ret|=!go(a^1,i+1,j,(x+A[i])%2, y);
        if (i<j) ret|=!go(a^1,i+2,j,(x+A[i]+A[i+1])%2,y);

        ret|=!go(a^1,i,j-1,(x+A[j])%2,y);
        if (i<j) ret|=!go(a^1,i,j-2,(x+A[j]+A[j-1])%2,y);
    }
    else {
        ret|=!go(a^1,i+1,j,x,(y+A[i])%2);
        if (i<j) ret|=!go(a^1,i+2,j,x,(y+A[i]+A[i+1])%2);

        ret|=!go(a^1,i,j-1,x,(y+A[j])%2);
        if (i<j) ret|=!go(a^1,i,j-2,x,(y+A[j]+A[j-1])%2);
    }

    return ret;
}

int main() {
    fio();
    memset(D,-1,sizeof D);

    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>A[i];
        A[i]&=1;
    }

    cout<<(go(0,1,N,0,0)?"Yes":"No");
    return 0;
}
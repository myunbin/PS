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
const int MAX = 101010; // PLZ CHK!

int n,m,k;
vector<vector<vector<int>>> s;
vector<vector<int>> a;

vector<vector<int>> rt(vector<vector<int>> &v) {
    int r=sz(v[0]), c=sz(v);
    vector<vector<int>> ret(r, vector<int>(c,0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            ret[i][j]=v[c-1-j][i];
        }
    }
    return ret;
}

bool ok(int x, int y, vector<vector<int>> &v) {
    int r=sz(v), c=sz(v[0]);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (x+i>=n || y+j>=m) return 0;
            if (v[i][j] && a[x+i][y+j]) return 0;
        }
    }
    return 1;
}

void st(int x, int y, vector<vector<int>> &v) {
    int r=sz(v), c=sz(v[0]);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            a[x+i][y+j]|=v[i][j];
        }
    }
}

void ck(vector<vector<int>> &v) {
    vector<vector<int>> t=v;
    for (int r=0; r<4; r++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (ok(i,j,t)) {
                    st(i,j,t);
                    return;
                }
            }
        }    
        t=rt(t);
    }   
}

int main() {
    fio();

    cin>>n>>m>>k;
    a.resize(n,vector<int>(m,0));
    s.resize(k);

    for (int i=0; i<k; i++) {
        int r,c;
        cin>>r>>c;
        s[i].resize(r,vector<int>(c,0));
        for (int x=0; x<r; x++) {
            for (int y=0; y<c; y++) {
                cin>>s[i][x][y];
            }
        }
    }

    for (int i=0; i<k; i++){
        ck(s[i]);
        // vector<vector<int>> t=s[i];
        // for (int r=0; r<4; r++) {
        //     for (auto v:t) {
        //         for (int x:v) cout<<x<<sp;
        //         cout<<endl;
        //     }
        //     t=rt(t);
        //     cout<<endl;
        // }

        // cout<<endl;
    } 
    

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) ans+=a[i][j];
    }
    
    cout<<ans;
    return 0;
}
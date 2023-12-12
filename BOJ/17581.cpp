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

int N,B[10][10][10],ok=0;
vector<vector<char>> A[6];

vector<vector<char>> rot(vector<vector<char>> t) {
    vector<vector<char>> ret=t;
    for (int i=0; i<N; i++) ret[0][i]=ret[i][N-1];
    for (int i=0; i<N; i++) ret[i][N-1]=ret[N-1][N-i-1];
    for (int i=0; i<N; i++) ret[N-1][N-i-1]=ret[N-i-1][0];
    for (int i=0; i<N; i++) ret[N-i-1][0]=t[0][i];
    return ret;
}

vector<vector<char>> flip(vector<vector<char>> t) {
    vector<vector<char>> ret=t;
    for (int i=0; i<N/2; i++) {
        for (int j=0; j<N; j++) {
            swap(ret[0][j], ret[N-i-1][j]);
        }
    }
    return ret;
}

void go(int idx) {
    if (ok) return;

    if (idx==6) {
        ok=1;
        return;
    }

    for (int i=0; i<8; i++) {        
        int x=i%4, y=i/4;
        vector<vector<char>> T=A[idx];
        while (x--) T=rot(T);
        if (y) T=flip(T);
        
        if (idx==0) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][y][0]+=(T[x][y]=='X');
                }
            }
        }
        if (idx==1) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[N-1][x][y]+=(T[x][y]=='X');
                }
            }
        }
        if (idx==2) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][y][N-1]+=(T[x][y]=='X');
                }
            }
        }
        if (idx==3) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[0][x][y]+=(T[x][y]=='X');
                }
            }
        }
        if (idx==4) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][0][y]+=(T[x][y]=='X');
                }
            }
        }
        if (idx==5) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][N-1][y]+=(T[x][y]=='X');
                }
            }
        }
        
        for (int x=0; x<N; x++) {
            for (int y=0; y<N; y++) {
                for (int z=0; z<N; z++) {
                    if (B[x][y][z]>1) {
                        if (idx==0) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[x][y][0]-=(T[x][y]=='X');
                                }
                            }
                        }
                        if (idx==1) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[N-1][x][y]-=(T[x][y]=='X');
                                }
                            }
                        }
                        if (idx==2) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[x][y][N-1]-=(T[x][y]=='X');
                                }
                            }
                        }
                        if (idx==3) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[0][x][y]-=(T[x][y]=='X');
                                }
                            }
                        }
                        if (idx==4) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[x][0][y]-=(T[x][y]=='X');
                                }
                            }
                        }
                        if (idx==5) {
                            for (int x=0; x<N; x++) {
                                for (int y=0; y<N; y++) {
                                    B[x][N-1][y]-=(T[x][y]=='X');
                                }
                            }
                        }
                        return;
                    }
                }
            }
        }

        go(idx+1);

        if (idx==0) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][y][0]-=(T[x][y]=='X');
                }
            }
        }
        if (idx==1) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[N-1][x][y]-=(T[x][y]=='X');
                }
            }
        }
        if (idx==2) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][y][N-1]-=(T[x][y]=='X');
                }
            }
        }
        if (idx==3) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[0][x][y]-=(T[x][y]=='X');
                }
            }
        }
        if (idx==4) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][0][y]-=(T[x][y]=='X');
                }
            }
        }
        if (idx==5) {
            for (int x=0; x<N; x++) {
                for (int y=0; y<N; y++) {
                    B[x][N-1][y]-=(T[x][y]=='X');
                }
            }
        }
    }
}

void solve() {
    for (int i=0; i<6; i++) A[i].clear();
    memset(B,0,sizeof B);
    ok=0;

    cin>>N;
    if (N==0) exit(0);

    for (int i=0; i<6; i++) {
        A[i].resize(N,vector<char>(N));
        for (int x=0; x<N; x++) {
            for (int y=0; y<N; y++) {
                cin>>A[i][x][y];
            }
        }
    }

    go(0);

    cout<<(ok?"Yes\n":"No\n");
}

int main() {
    fio();
    while (1) {
        solve();
    }
    return 0;
}
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
const int MAX = 505050; // PLZ CHK!

int N,A,B,DA,DB;
int V[2][MAX],D[2][MAX];

int main() {
    fio();
    fill(D[0],D[0]+MAX,INF);
    fill(D[1],D[1]+MAX,INF);

    cin>>N>>A>>B>>DA>>DB;

    queue<pii> q;

    V[0][abs(A-B)]=1, D[0][abs(A-B)]=0;
    q.push({0,abs(A-B)});

    while (!q.empty()) {
        auto [cp,cd]=q.front(); q.pop();
        cout<<cp<<sp<<cd<<endl;

        int nd1,nd2;
        if (cp==0) {
            nd1=abs(cd+DA); 
            if (nd1>N) nd1-=N;
            nd1=min(nd1,N-nd1);

            nd2=abs(cd-DA);
            nd2=min(nd2,N-nd2);
        }
        else {
            nd1=abs(cd+DB);
            if (nd1>N) nd1-=N;
            nd1=min(nd1,N-nd1);

            nd2=abs(cd-DB);
            nd2=min(nd2,N-nd2);
        }

        int np=cp^1;
        if (!V[np][nd1]) {
            V[np][nd1]=1;
            D[np][nd1]=D[cp][cd]+1;
            q.push({np,nd1});
        }
        if (!V[np][nd2]) {
            V[np][nd2]=1;
            D[np][nd2]=D[cp][cd]+1;
            q.push({np,nd2});
        }
    }

    int ans=min(D[0][0],D[1][0]);
    if (ans==INF) cout<<"Evil Galazy";
    else cout<<ans;

    return 0;
}
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
const int MAX = 505; // PLZ CHK!

int N;
string A[MAX][MAX],D[MAX];
int B[MAX][MAX],C[MAX];

void kmp(string s, string t) {
    if (sz(s)!=sz(t)) {
        cout<<"NONE\n";
        exit(0);
    }

    s+=s;
    int n=sz(s), m=sz(t);
    int f[2020202]={0};

    for (int i=1, j=0; i<m; i++) {
        while (j>0 && t[i]!=t[j]) j=f[j-1];
        if (t[i]==t[j]) f[i]=(++j);
    }

    vector<int> ans;
    for (int i=1,j=0; i<n-1; i++) {
        while (j>0 && s[i]!=t[j]) j=f[j-1];
        if (s[i]==t[j]) {
            if (j==m-1) {
                ans.pb(i-m+1);
                j=f[j];
            }
            else j++;
        }
    }

    if (sz(ans)>1) {
        cout<<"MANY\n";
        exit(0);
    }

    if (ans.empty() || ans[0]==0 || ans[0]>=m) {
        cout<<"NONE\n";
        exit(0);
    }

    string x=s.substr(0,ans[0]);
    string y=s.substr(ans[0],m-ans[0]);
    cout<<"UNIQUE"<<endl<<x<<endl<<y<<endl;
}

int main() {
    fio();
    memset(C,-1,sizeof C);

    cin>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>A[i][j];
            B[i][j]=sz(A[i][j]);
        }
    }

    if (N==2) {
        kmp(A[1][2], A[2][1]);        
        return 0;
    }

    for (int i=3; i<=N; i++) {
        int len=B[i][1]+B[i][2]-B[1][2];
        if (len<=0 || len&1) {
            cout<<"NONE\n";
            return 0;
        }
        C[i]=len>>1;
    }

    int len1=B[1][2]+B[1][3]-B[2][3];
    if (len1<=0 || len1%2) {
        cout<<"NONE\n";
        return 0;
    }
    else C[1]=len1>>1;

    int len2=B[2][1]+B[2][3]-B[1][3];
    if (len2<=0 || len2%2) {
        cout<<"NONE\n";
        return 0;
    }
    else C[2]=len2>>1;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i==j) continue;
            if (C[i]==-1 || C[j]==-1) {
                cout<<"NONE\n";
                return 0;
            }

            if (C[i]+C[j]!=sz(A[i][j])) {
                cout<<"NONE\n";
                return 0;
            }

            string x=A[i][j].substr(0,C[i]);
            string y=A[i][j].substr(C[i],C[j]);

            if (D[i].compare("")==0) D[i]=x;
            else if (D[i]!=x) {
                cout<<"NONE\n";
                return 0;
            }

            if (D[j].compare("")==0) D[j]=y;
            else if (D[j]!=y) {
                cout<<"NONE\n";
                return 0;
            }
        }
    }

    cout<<"UNIQUE\n";
    for (int i=1; i<=N; i++) cout<<D[i]<<endl;

    return 0;
}
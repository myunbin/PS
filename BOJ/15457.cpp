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
const int MAX = 202020; // PLZ CHK!

int N,D,A[MAX][2];
int d[MAX];
set<pii> B,E;

int main() {
    fio();
    cin>>N>>D;

    queue<int> q;
    for (int i=1; i<=2*N; i++) {
        cin>>A[i][0]>>A[i][1];
        if (i<=N && A[i][1]==0) {
            q.push(i);
            d[i]=1;
        } 
        else if (i<=N) B.insert({A[i][1],i});

        if (i>N && A[i][0]==0) {
            q.push(i);
            d[i]=1;
        }
        else if (i>N) E.insert({A[i][0],i});
    }

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        if (cur<=N) {
            int ct=A[cur][0], nt=max(0,A[cur][0]-D);
            auto it=E.lb(pii(nt,0));
            if (it==E.end()) continue;

            vector<pii> del;
            while (it!=E.end() && nt<=it->F && it->F<=ct) {
                if (d[it->S]) continue;

                q.push(it->S);
                d[it->S]=d[cur]+1;
                del.pb(*it);
                it++;
            }
            for (pii p:del) E.erase(p);
        }
        else {
            int ct=A[cur][1], nt=max(0,A[cur][1]-D);
            auto it=B.lb(pii(nt,0));
            if (it==B.end()) continue;

            vector<pii> del;
            while (it!=B.end() && nt<=it->F && it->F<=ct) {
                if (d[it->S]) continue;
                q.push(it->S);
                d[it->S]=d[cur]+1;
                del.pb(*it);
                it++;
            }
            for (pii p:del) B.erase(p);
        }
    }

    for (int i=1; i<=N; i++) cout<<(d[i]?d[i]:-1)<<endl;
    return 0;
}
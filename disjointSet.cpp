#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank ,parent ,size;

    public:
        DisjointSet(int n) {
            rank.resize(n+1 ,0);
            parent.resize(n+1);
            size.resize(n+1 ,1);

            for(int i=0 ;i<=n ;i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }   

        //TC for Union : O(4*alpha) approx O(1) same for findParent
        void unionByRank(int u ,int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
        
        void unionBySize(int u ,int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;
            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            
        }
};

int main(){
    DisjointSet ds(5);

    ds.unionBySize(1, 2);
    ds.unionBySize(3, 4);
    ds.unionBySize(2, 3);

    cout << ds.findParent(1) << endl;  // should give representative of the set containing 1
    cout << ds.findParent(4) << endl;  // same representative as 1 after unions

    return 0;
}

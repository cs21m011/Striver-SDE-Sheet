// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        vector<int> cost(V,INT_MAX),parent(V,-1);
        vector<bool> mst(V,false);
        
        parent[0]=-1;
        cost[0]=0;
        
        //MST will have V-1 edges
        for(int i=0;i<V-1;i++){
            int min_cost=INT_MAX,u;
            
            //finding the minimum cost vertex
            for(int j=0;j<V;j++){
                if(mst[j]==false && cost[j]<min_cost){
                    min_cost=cost[j];
                    u=j;
                }
            }
            
            //adding the minimum cost edge to the vertex
            mst[u]=true;
            for(auto it:adj[u]){
                int v=it[0],weight=it[1];
                
                if(mst[v]==false && weight<cost[v]){
                    parent[v]=u;
                    cost[v]=weight;
                }
            }
        } 
        
        //iterating through the cost array gives the total cost of mst
        int res=0;
        for(int i=0;i<V;i++)
            res=res+cost[i];
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
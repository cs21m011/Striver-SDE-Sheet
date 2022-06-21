// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        
        vector<int> cost(V,INT_MAX);
        vector<bool> relaxed(V,false);
        cost[S]=0;
        
        for(int i=0;i<V-1;i++){
            //finding the minimum weight vertex
            int min_cost=INT_MAX,u;
            for(int j=0;j<V;j++){
                if(cost[j]<min_cost && relaxed[j]==false){
                    u=j;
                    min_cost=cost[j];
                }
            }
            relaxed[u]=true;
            
            //finding the distances to the adjacent vertices of u
            for(auto it:adj[u]){
                int v=it[0],weight=it[1];
                if(relaxed[v]==false && cost[u]+weight<cost[v])
                    cost[v]=cost[u]+weight;
            }
        }
        return cost;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
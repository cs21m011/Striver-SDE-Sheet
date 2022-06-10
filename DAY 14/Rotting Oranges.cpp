class Solution {
    struct Node{
        int time,i,j;
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        //finding all the rotten orange locations
        queue<struct Node> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    struct Node p;
                    p.time=0;
                    p.i=i;
                    p.j=j;
                    q.push(p);
                }
            }
        }
        
        
        //rottening the fresh oranges
        int res=0;
        while(!q.empty()){
            struct Node p=q.front();
            int i=p.i,j=p.j;
            
            //fresh orange on right side
            if(i<m && j<n-1 && grid[i][j+1]==1){
                grid[i][j+1]=2;
                
                //adding the node to queue
                struct Node temp;
                temp.time=p.time+1;
                temp.i=p.i;
                temp.j=p.j+1;
                
                q.push(temp);
            }
            
            //fresh orange on bottom side
            if(i<m-1 && j<n && grid[i+1][j]==1){
                grid[i+1][j]=2;
                
                //adding the node to queue
                struct Node temp;
                temp.time=p.time+1;
                temp.i=p.i+1;
                temp.j=p.j;
                
                q.push(temp);
            }
            
            //fresh orange on left side
            if(j>0 && i<m && j<n && grid[i][j-1]==1){
                grid[i][j-1]=2;
                
                //adding the node to queue
                struct Node temp;
                temp.time=p.time+1;
                temp.i=p.i;
                temp.j=p.j-1;
                
                q.push(temp);
            }
            
            //fresh orange on top side
            if(i>0 && i<m && j<n && grid[i-1][j]==1){
                grid[i-1][j]=2;
                
                //adding the node to queue
                struct Node temp;
                temp.time=p.time+1;
                temp.i=p.i-1;
                temp.j=p.j;
                
                q.push(temp);
            }
            
            
            q.pop();
            
            if(q.size()==1){
                struct Node pp;
                pp=q.front();
                res=pp.time;
            }
        }
        
        //checking for fresh oranges that can't be rotten
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return res; 
    }
};
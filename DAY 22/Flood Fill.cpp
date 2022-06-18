class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        
        int m=image.size(),n=image[0].size();
        dfs(image,sr,sc,color,m,n,image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int m,int n,int p){
        if(sr<0 || sr>=m || sc<0 || sc>=n)
            return;
        if(image[sr][sc]!=p)
            return;
        
        
        image[sr][sc]=color;
        //left pixel
        dfs(image,sr,sc-1,color,m,n,p);
        //right pixel
        dfs(image,sr,sc+1,color,m,n,p);
        //top pixel
        dfs(image,sr-1,sc,color,m,n,p);
        //bottom pixel
        dfs(image,sr+1,sc,color,m,n,p);
    }
};
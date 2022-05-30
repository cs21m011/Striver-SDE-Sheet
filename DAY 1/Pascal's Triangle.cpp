class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        
        if(numRows==1){
            v={{1}};
            return v;
        }
        if(numRows==2){
            v={{1},{1,1}};
            return v;
        }
        
        v={{1},{1,1}};
        for(int i=2;i<numRows;i++){
            vector<int> k; 
            k.push_back(1); //pacing 1 at beginning
            for(int j=1;j<i;j++){
                //adding the elements in the upper row
                int p=v[i-1][j-1]+v[i-1][j];
                k.push_back(p);
            }
            k.push_back(1); //palcing 1 at ending
            
            v.push_back(k);
        }
        return v;
    }
};
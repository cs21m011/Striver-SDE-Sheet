class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort all the pairs based on the first number 
        sort(intervals);
        
        vector<vector<int>> v;
        int n=intervals.size();
        
        for(int i=0,j=0;i<n;){
            pair<int,int> p;
            p.first=intervals[i][0];
            p.second=intervals[i][1];
            
            //comparing the pairs for merging
            for(j=i+1;j<n;j++){
                if(p.second>=intervals[j][0] && intervals[j][1]>=p.first)
                    p.second=intervals[j][1]>p.second?intervals[j][1]:p.second;
                else
                    break;
            }
            
            //pair is stored in p
            v.push_back({p.first,p.second});
            i=j;
        }
        return v;
    }
    
    void sort(vector<vector<int>>& intervals){
        int n=intervals.size();
        
        for(int i=0;i<n-1;i++){
            int swap=0;
            for(int j=0;j<n-i-1;j++){
                if(intervals[j][0]>intervals[j+1][0]){
                    int temp1=intervals[j][0];
                    intervals[j][0]=intervals[j+1][0];
                    intervals[j+1][0]=temp1;
                    
                    int temp2=intervals[j][1];
                    intervals[j][1]=intervals[j+1][1];
                    intervals[j+1][1]=temp2;
                    
                    swap=1;
                }
            }
            if(swap==0)
                break;
        }
    }
};

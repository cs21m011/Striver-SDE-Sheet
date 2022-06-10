void heapify(vector<int>&,int,int);


vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size(),start=n/2-1;

    //heapifying the vector A
    for(int i=start;i>=0;i--)
        heapify(A,n,i);
    
    //heapifying the vector B
    for(int i=start;i>=0;i--)
        heapify(B,n,i);

    //finding the combinations
    vector<int> v;
    for(int i=1,j=0,k=0;i<=C;j++,k++){
        //for the maximum elements
        v.push_back(A[j]+B[k]);

        //for the diagonal elements
        i++;
        int p=A[j+1]+B[k],q=A[j]+B[k+1];
        if(i<=C){
            if(p>q){
                v.push_back(p);
                p=-1;
            }
            else{
                v.push_back(q);
                q=-1;
            }
        }

        i++;
        if(i<=C){
            if(p>q)
                v.push_back(p);
            else
                v.push_back(q);
        }
    }
    return v;
}

void heapify(vector<int>& nums,int n,int i){
    int largest=i;
    int left=2*i+1,right=2*i+2;

    if(left<n && nums[left]>nums[largest])
        largest=left;
    if(right<n && nums[right]>nums[largest])
        largest=right;

    if(largest!=i){
        int temp=nums[largest];
        nums[largest]=nums[i];
        nums[i]=temp;

        heapify(nums,n,largest);
    }
}


int findMinimumCoins(int amount) {
    // Write your code here
    int coin_array[]={1000,500,100,50,20,10,5,2,1};
    int count=0,n=sizeof(coin_array)/sizeof(coin_array[0]);
    
    for(int i=0;i<n && amount>0;){
        if(amount>=coin_array[i]){
            amount=amount-coin_array[i];
            count++;
        }
        else
            i++;
    }
    return count;
}

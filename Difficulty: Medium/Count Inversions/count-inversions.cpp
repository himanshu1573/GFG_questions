class Solution {
public:
    vector<int> temp;
    vector<int> arr; 

    long long merge(int left,int mid,int right){
        int i=left;
        int j=mid+1;
        int k=left;
        long long inversions=0; 
        
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            } else {
                temp[k++]=arr[j++];
                inversions+=(mid-i+1);
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=right){
            temp[k++]=arr[j++];
        }
        for(i=left;i<=right;i++){
            arr[i]=temp[i];
        }
        return inversions;
    }

    long long divide(int left,int right){
        long long inversions=0;
        if(left<right){
            int mid=left+(right-left)/2;
            inversions+=divide(left,mid);
            inversions+=divide(mid+1,right);
            inversions+=merge(left,mid,right);
        }
        return inversions;
    }

    long long inversionCount(vector<int> &input_arr) {
        int n=input_arr.size();
        
       
        this->arr=input_arr; 
        this->temp.resize(n);
        
        return divide(0,n-1);
    }
};












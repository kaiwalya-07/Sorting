#include<iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e){
    
    int n1= mid-s+1;
    int n2=e-mid;

    int M[n1], N[n2];

    for(int i=0;i<n1;i++){
        M[i]=arr[s+i];
    }
     for(int j=0;j<n2;j++){
        N[j]=arr[mid+1+j];
    }

    int i,j,k;
    i=0;
    j=0;
    k=s;

     while (i < n1 && j < n2) {
        if (M[i] <= N[j]) {
            arr[k] = M[i];
            i++;
        } else {
            arr[k] = N[j];
            j++;
        }
        k++;
     }   

       while (i < n1) {
        arr[k] = M[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = N[j];
        j++;
        k++;
    }
    

}


void mergeSort(int arr[], int s, int e){

if(s<e){
int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);

    }
}

int main(){
int arr[]={12,24,7,30,53,11,45,10};
int n=sizeof(arr)/sizeof(arr[0]);

mergeSort(arr,0,n-1);


int m;
for(m=0;m<n;m++){

    cout<<arr[m];
    
}




    return 0;

}
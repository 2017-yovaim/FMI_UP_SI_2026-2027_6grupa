#include <iostream>

void readArray(int[], int);
bool contains(const int a[], int n, const int b[], int m);

int main(){
    int n, m;
    std::cin>>n>>m;

    int arr1[1024], arr2[1024];
    readArray(arr1, n);
    readArray(arr2, m);
    std::cout<<contains(arr1, n, arr2, m);

}

void readArray(int arr[], int size){
    for(int i=0; i < size; i++){
        std::cin>>arr[i];
    }
}

bool contains(const int a[], int n, const int b[], int m){
    int j = 0;
    for(int i=0; i<n; i++){
        if(a[i] == b[j]){
            j++;
            if(j == m){
                return true;
            }
        }
        else{
            j = 0; 
        }
    }
    return false;
}
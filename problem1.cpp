#include <iostream>

void readArray(int[], int);
bool contains(const int a[], int n, const int b[], int m);

int main(){
    int n=-1, m=-1;

    while(n<0){
        std::cout<<"Enter a valid length of array 1";
        std::cin>>n;
    }
    while(m<0){
        std::cout<<"Enter a valid length of array 2";
        std::cin>>m;
    }

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
    if(n==0){
        if(m==0){
            return true;
        }
        return false;
    }
    if(m==0){
        return true;
    }

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
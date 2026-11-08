#include <iostream>

void reverseRange(int a[], int l, int r);
void readArray(int[], int);
void displayArray(int[], int);

int main()
{
    int n=-1, l=-1, r=-1;
    int arr[1024];

    while(n<0)
    {
        std::cout<<"Enter a valid length for the array"<<std::endl;
        std::cin>>n;
    }
    readArray(arr, n);

    while(l < 0 || l >= n)
    {
        std::cout<<"Enter a valid index for the start of the subarray"<<std::endl;
        std::cin>>l;
    }
    while(r <= l|| r >= n)
    {
        std::cout<<"Enter a valid index for the end of the subarray"<<std::endl;
        std::cin>>r;
    }
    
    displayArray(arr, n);

    reverseRange(arr, l, r);

    displayArray(arr, n);

    return 0;
}

void readArray(int arr[], int size){
    for(int i=0; i < size; i++)
    {
        std::cin>>arr[i];
    }
}

void displayArray(int arr[], int n){
    for(int i=0; i<n; i++){
        std::cout<<arr[i];
    }
    std::cout<<std::endl;
}

void reverseRange(int a[], int l, int r)
{
    while(l < r){
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}
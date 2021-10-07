#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    // Divide arr[] into two arrays which will then be put in sorted order into arr[]

    // 
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2];
    // So we declare two arrays of appropriate length.

    // We fill the two created arrays with each half respectively.
    for(int i=0; i<n1; i++)
    {
        a[i]=arr[l+i]; // arr[l+i] : l for where ever your starting from and i let's you increment there on
    }

    for(int i=0; i<n2; i++)
    {
        b[i]=arr[mid+1+i]; // mid is added to start from mid, that's it.
    }

    // 
    int i=0, j=0; // you are essentially taking three pointers for arr, a, b.
    int k=l;
    // These pointers are going to decide which elements go into arr for sorted order.

    while(i<n1 && j<n2) // Decides which element foes in first as we do simultaenous comaprison.
    {
        if(a[i] < b[j])
        {
            arr[k]=a[i];
            i++; k++;
        }
        else
        {
            arr[k]=b[j];
            j++; k++;
        }
    }

    // If the lists are of different length then some residuary elements are going to be left behind.
    while(i<n1)
    {
        arr[k]=a[i];
        i++; k++;
    }

    while(j<n2)
    {
        arr[k]=b[j];
        j++; k++;
    }

}

void mergeSort(int arr[], int l, int r) // here both l and r are true values, as in l = 0, r = len-1. 
{
    if (l < r)
    {
        // Logic of merge sort starts from here 
        
        int mid = (l + r) / 2; // Since mergeSort is a divide and conquer algo. We have a mid to divide.

        mergeSort(arr, l, mid); // This recursively breaks down the first half of the array. 
        
        mergeSort(arr, mid + 1, r); // Breaks down second half of array.
        // Remeber this is mid+1, because mid is already inclued in the first half
        
        // As we see in merge() once the array is broken down at each recursive step it is put 
        // together in the right order. Thus coming out of recursion as a whole you have a sorted array.

        merge(arr, l, mid, r); // Merge should know where you're STARTING, ENDING and *where you're cutting
        // the array from*.
    }
}


 
#include<stdio.h>   
#include<string.h>

void bubblesort(int arr[], int n)
    {
        int i, j, temp;
        for(i =0; i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if (arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
int main()
{
    /*
    int arr[100], n, i;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("Mang sau khi sap xep: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
    */
    int arr[]={31,13,14,536,912,-513,145};
    int n=sizeof(arr)/sizeof(arr[0]); //sizeof(arr) trả về số byte của mảng arr, sizeof(arr[0]) trả về số byte của phần tử đầu tiên của mảng arr ví dụ ở đây
    // sizeof(arr)=7*4=28, sizeof(arr[0])=4 => n=28/4=7
    bubblesort(arr, n);
    printf("Array after sorting:\n ");  
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;

}
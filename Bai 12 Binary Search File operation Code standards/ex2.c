#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int left, int right, int target)
{
   if (right >= left)
   {
        int mid = left + (right  - left)/2;
 
        // Nếu giá trị giữa mảng bằng với x, trả về chỉ số của nó
        if (arr[mid] == target)  return mid;
 
        // Nếu x nhỏ hơn giá trị giữa mảng, tìm kiếm trong phần trái của mảng
        if (arr[mid] > target) return binarySearch(arr, left, mid-1, target);
 
        // Nếu x lớn hơn giá trị giữa mảng, tìm kiếm trong phần phải của mảng
        return binarySearch(arr, mid+1, right, target);
   }

   
 
   // Nếu không tìm thấy x
   return -1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main()
{
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
       printf("i = %d\n", arr[i]);
    }
    
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n-1, x);
    if (result == -1)
        printf("Khong tim thay %d trong mang.\n", x);
    else
        printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
    free(arr);
    return 0;
}

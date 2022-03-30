#include <stdio.h>
#include <stdlib.h>




int main()
{

    int arr[] = {3, 4, 1, 5, 8, 100, 0, 5, 10, 13, 11, 9, 10};
    int temp;
    int j;
    // 算法实现：直接插入排序是将无序序列中的数据插入到有序的序列中，在遍历无序序列时，
    // 首先拿无序序列中的首元素去与有序序列中的每一个元素比较并插入到合适的位置，
    // 一直到无序序列中的所有元素插完为止。
    for(int i = 1; i < 13; i++)
    {
        if(arr[i] < arr[i-1])
        {
            continue;
            
        }
        temp = arr[i];
        for(j = i-1;j >= 0 && temp > arr[j]; j--)
        {
            arr[j+1] = arr[j];
        }

        arr[j+1] = temp;
        // if(i > (j+1))//如果有序队列中没有进行比较，就让比较的这一位留在原地，避免重复赋值
        // {
        //     arr[j+1] = temp;
            
        // }
    }
    
    for(int i = 0; i < 13; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
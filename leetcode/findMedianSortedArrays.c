/*************************************************************************
	> File Name: findMedianSortedArrays.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 06:49:28 PM CST
 ************************************************************************/

#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main()
{
    //int nums1[] = {0, 2, 4, 6, 8, 10};
    //int nums2[] = {1, 3, 5, 7, 9, 11};
    int nums1[] = {3, 4};
    int nums2[] = {1, 2, 5, 6};
    double d = findMedianSortedArrays(nums1, 2, nums2, 4);
    printf("d = %.1f\n", d);
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int mid1, mid2;
    double median;
    mid1 = nums1Size/2;
    mid2 = nums2Size/2;
    if(nums1Size == 0 && nums2Size == 0)
    {
        median = 0.0;
        return median;
    }
    if(nums1Size == 0)
    {
        if(nums2Size % 2)
            median = (double)*(nums2 + mid2);
        else
            median = (double)(*(nums2 + mid2) + *(nums2 + mid2 - 1)) / 2.0; 
        return median;
    }
    else if(nums2Size == 0)
    {
        if(nums1Size % 2)
            median = (double)*(nums1 + mid1);
        else
            median = (double)(*(nums1 + mid1) + *(nums1 + mid1 - 1)) / 2.0; 
        return median;
    }
    if(nums1Size == 1 && nums2Size == 1)
    {
        median = (*nums1 + *nums2) / 2.0;
        return median;
    }
    if(nums1Size == 1)
    {
        if(nums2Size % 2)
        {
            if(*nums1 < *(nums2 + mid2 - 1))
                median = (*(nums2 + mid2 - 1) + *(nums2 + mid2)) / 2.0;
            else if(*nums1 > *(nums2 + mid2 + 1))
                median = (*(nums2 + mid2 + 1) + *(nums2 + mid2)) / 2.0;
            else
                median = (double)(*(nums2 + mid2) + *nums1) / 2.0;
            return median;
        }
        else
        {
            if(*nums1 > *(nums2 + mid2))
                median = (double)*(nums2 + mid2);
            else if(*nums1 < *(nums2 + mid2 -1))
                median = (double)*(nums2 + mid2 - 1);
            else
                median = (double)*nums1;
            return median;
        }
    }
    else if(nums2Size == 1)
    {
        if(nums1Size % 2)
        {
            if(*nums2 < *(nums1 + mid1 - 1))
                median = (*(nums1 + mid1 - 1) + *(nums1 + mid1)) / 2.0;
            else if(*nums2 > *(nums1 + mid1 + 1))
                median = (*(nums1 + mid1 + 1) + *(nums1 + mid1)) / 2.0;
            else
                median = (double)(*(nums1 + mid1) + *nums2) / 2.0;
            return median;
        }
        else
        {
            if(*nums2 > *(nums1 + mid1))
                median = (double)*(nums1 + mid1);
            else if(*nums2 < *(nums1 + mid1 -1))
                median = (double)*(nums1 + mid1 - 1);
            else
                median = (double)*nums2;
            return median;
        }
    }
    if(nums1Size == 2 && nums2Size == 2)
    {
        if(*nums1 <= *nums2 && *(nums1 + 1) <= *(nums2 + 1))
            median = (*nums2 + *(nums1 + 1)) /2.0;
        else if(*nums1 >= *nums2 && *(nums1 + 1) >= *(nums2 + 1))
            median = (*nums1 + *(nums2 + 1)) /2.0;
        else if(*nums1 >= *nums2 && *(nums1 + 1) <= *(nums2 + 1))
            median = (*nums1 + *(nums1 + 1)) / 2.0;
        else if(*nums1 <= *nums2 && *(nums1 + 1) >= *(nums2 + 1))
            median = (*nums2 + *(nums2 + 1)) / 2.0;
        return median;
    }
    if(*(nums1 + mid1) <= *(nums2 + mid2))
    {
        if(mid1 <= mid2)
            median = findMedianSortedArrays(nums1 + mid1, nums1Size - mid1, nums2, nums2Size - mid1);
        else
            median = findMedianSortedArrays(nums1 + mid2, nums1Size - mid2, nums2, nums2Size - mid2);
    }
    else
    {
        if(mid1 <= mid2)
            median = findMedianSortedArrays(nums1, nums1Size - mid1, nums2 + mid1, nums2Size - mid1);
        else
            median = findMedianSortedArrays(nums1, nums1Size - mid2, nums2 + mid2, nums2Size - mid2);
    }
    return median;
}

/*
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int mid1, mid2;
    double median;
    mid1 = nums1Size/2;
    mid2 = nums2Size/2;
    if(nums1Size == 0 && nums2Size == 0)
    {
        median = 0.0;
        printf("median = %.1f\n", median);
        return median;
    }
    if(nums1Size == 0)
    {
        if(nums2Size % 2)
        {
            median = (double)*(nums2 + mid2);
            printf("median = %.1f\n", median);
            return median;
        }
        else
        {
            median = (double)(*(nums2 + mid2) + *(nums2 + mid2 - 1)) / 2.0; 
            printf("median = %.1f\n", median);
            return median;
        }
    }
    else if(nums2Size == 0)
    {
        if(nums1Size % 2)
        {
            median = (double)*(nums1 + mid1);
            printf("median = %.1f\n", median);
            return median;
        }
        else
        {
            median = (double)(*(nums1 + mid1) + *(nums1 + mid1 - 1)) / 2.0; 
            printf("median = %.1f\n", median);
            return median;
        }
    }
    if(nums1Size == 1 && nums2Size == 1)
    {
        median = (*nums1 + *nums2) / 2.0;
        printf("median = %.1f\n", median);
        return median;
    }
    if(nums1Size == 1)
    {
        if(nums2Size % 2)
        {
            if(*nums1 > *(nums2 + mid2 - 1) && *nums1 < *(nums2 + mid2 + 1))
                median = (*nums1 + *(nums2 + mid2)) / 2.0;
            else
                median = (double)*(nums2 + mid2);
            printf("median = %.1f\n", median);
            return median;
        }
        else
        {
            if(*nums1 > *(nums2 + mid2))
            {
                median = (double)*(nums2 + mid2);
                printf("median = %.1f\n", median);
                return median;
            }
            else if(*nums1 < *(nums2 + mid2 -1))
            {
                median = (double)*(nums2 + mid2 - 1);
                printf("median = %.1f\n", median);
                return median;
            }
            else
            {
                median = (double)*nums1;
                printf("median = %.1f\n", median);
                return median;
            }
        }
    }
    else if(nums2Size == 1)
    {
        if(nums1Size % 2)
        {
            if(*nums2 > *(nums1 + mid1 - 1) && *nums2 < *(nums1 + mid1 + 1))
                median = (*nums2 + *(nums1 + mid1)) / 2.0;
            else
                median = (double)*(nums1 + mid1);
            printf("median = %.1f\n", median);
            return median;
        }
        else
        {
            if(*nums2 > *(nums1 + mid1))
            {
                median = (double)*(nums1 + mid1);
                printf("median = %.1f\n", median);
                return median;
            }
            else if(*nums2 < *(nums1 + mid1 -1))
            {
                median = (double)*(nums1 + mid1 - 1);
                printf("median = %.1f\n", median);
                return median;
            }
            else
            {
                median = (double)*nums2;
                printf("median = %.1f\n", median);
                return median;
            }
        }
    }
    if(*(nums1 + mid1) <= *(nums2 + mid2))
    {
        if(mid1 <= mid2)
            findMedianSortedArrays(nums1 + mid1, nums1Size - mid1, nums2, nums2Size - mid1);
        else
            findMedianSortedArrays(nums1 + mid2, nums1Size - mid2, nums2, nums2Size - mid2);
    }
    else
    {
        if(mid1 <= mid2)
            findMedianSortedArrays(nums1, nums1Size - mid1, nums2 + mid1, nums2Size - mid1);
        else
            findMedianSortedArrays(nums1, nums1Size - mid2, nums2 + mid2, nums2Size - mid2);
    }
}
*/

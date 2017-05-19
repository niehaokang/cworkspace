/*************************************************************************
	> File Name: twoSum.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: Mon 27 Mar 2017 06:47:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
int * twoSum(int *nums, int numsSize, int target)
{
    int i, j;
    int *result = (int*)malloc(sizeof(int) * 2);
    struct value_Map{
        int index;
        int value;
    };
    struct value_Map vm[numsSize];
    for( i = 0; i < numsSize; i++ )
    {
        vm[i].index = i;
        vm[i].value = target - nums[i];
    }
    j = 0;
    for(i = 0; i < numsSize; i++ )
    {
        for( j =0 ; j < numsSize; j++ )
        {
            if(vm[i].index != j && vm[i].value == nums[j])
            {
                result[0] = i;
                result[1] = vm[j].index;
            }
        }
    }
    return result;
}
int main()
{
    int nums[4] = {2, 7, 1, 15};
    int *r = twoSum(nums, 4, 22);
    printf("%d + %d = %d\n", nums[*r], nums[*(r+1)], nums[*r] + nums[*(r+1)]);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int* nums, int numsSize, int target, int* returnSize, int* isSuccess){
    int* result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i=0; i<numsSize-1; i++){
        for (int j=1; j<5; j++){
            if (nums[i] + nums[j] == target){
                printf("%d %d\n", nums[i], nums[j]);
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

int main(){
    int nums[10] = {1, 2, 3, 4, 5};
    int target = 6;
    int numsSize = sizeof(nums)/ sizeof(nums[0]);
    int returnSize, isSuccess;
    int *result = twoSum(nums, numsSize, target, &returnSize, &isSuccess);
    int i;
    if (isSuccess == 1){
        printf("Indices: ");
        for (i=0; i<returnSize; i++){
            printf("%d ", result[i]);
        }
    }
    else {
        printf("No two numbers add up to the target");
    }

    return 0;

    // สำหรับคำถาม
    /* ตอบ ยังไม่เหมาะสมเท่าที่ควรเนื่องจาก:
        - returnSize ควรเป็นตัวแปรที่ควบคุม size ของ result และไม่จำเป็นต้องส่งค่าเป็น pointer เข้าฟังก์ชั่นเพื่อไปแก้ไขค่าในฟังก์ชั่น 
        - ควรนำ result มาอยู่ใน main() แล้วส่ง address เข้าไปในฟังก์ชั่นเพื่อแก้ไขค่าแทน การทำแบบนี้จะช่วยให้โปรแกรมเข้าใจง่ายและไม่ต้องจอง address หลายครั้ง
    */
}
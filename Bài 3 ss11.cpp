#include <stdio.h>

int main() {
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target;
    int left = 0;
    int right = size - 1;
    int foundIndex = -1;
    printf("Nhap vao mot so nguyen de tim kiem: ");
    scanf("%d", &target);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedArray[mid] == target) {
            foundIndex = mid;
            break; 
        }
        if (sortedArray[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (foundIndex != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d.\n", target, foundIndex);
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    }

    return 0;
}

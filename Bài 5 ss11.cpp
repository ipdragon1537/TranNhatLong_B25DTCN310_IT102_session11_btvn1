#include <stdio.h>
#include <string.h>

int main() {
    char mang_chuoi[][50] = {"apple", "banana", "orange", "grape", "strawberry"};
    int kich_co_mang = sizeof(mang_chuoi) / sizeof(mang_chuoi[0]);
    char chuoi_tim[50];
    int vi_tri = -1;
    int i;

    printf("Nhap vao mot chuoi de tim kiem: ");
    fgets(chuoi_tim, 50, stdin);
    chuoi_tim[strcspn(chuoi_tim, "\n")] = 0;

    for (i = 0; i < kich_co_mang; i++) {
        if (strcmp(mang_chuoi[i], chuoi_tim) == 0) {
            vi_tri = i;
            break;
        }
    }

    if (vi_tri != -1) {
        printf("Tim thay chuoi \"%s\" tai vi tri %d.\n", chuoi_tim, vi_tri);
    } else {
        printf("Khong tim thay chuoi \"%s\" trong mang.\n", chuoi_tim);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int mang[] = {1, 3, 2, 1, 4, 1, 3, 2, 3, 3};
    int kich_co = sizeof(mang) / sizeof(mang[0]);
    int max_tan_suat = 0;
    int phan_tu_nhieu_nhat = mang[0];
    int i, j;

    for (i = 0; i < kich_co; i++) {
        int tan_suat_hien_tai = 0;
        for (j = 0; j < kich_co; j++) {
            if (mang[i] == mang[j]) {
                tan_suat_hien_tai++;
            }
        }
        if (tan_suat_hien_tai > max_tan_suat) {
            max_tan_suat = tan_suat_hien_tai;
            phan_tu_nhieu_nhat = mang[i];
        }
    }

    printf("Phan tu xuat hien nhieu nhat la: %d\n", phan_tu_nhieu_nhat);
    printf("So lan xuat hien: %d\n", max_tan_suat);

    return 0;
}


#include <stdio.h>

int main() {
    int mang[] = {1, 3, 2, 1, 4, 1, 3, 2, 3, 3};
    int kich_co_ban_dau = sizeof(mang) / sizeof(mang[0]);
    int mang_tam[kich_co_ban_dau];
    int kich_co_moi = 0;
    int i, j;
    int la_duy_nhat;

    for (i = 0; i < kich_co_ban_dau; i++) {
        la_duy_nhat = 1;
        for (j = 0; j < kich_co_moi; j++) {
            if (mang[i] == mang_tam[j]) {
                la_duy_nhat = 0;
                break;
            }
        }
        if (la_duy_nhat) {
            mang_tam[kich_co_moi] = mang[i];
            kich_co_moi++;
        }
    }
    printf("Mang sau khi da loai bo trung lap: ");
    for (i = 0; i < kich_co_moi; i++) {
        printf("%d ", mang_tam[i]);
    }
    printf("\n");

    return 0;
}

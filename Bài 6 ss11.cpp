#include <stdio.h>
#include <limits.h> // co tac dung cung cap gia tri toi thieu va toi da cho cac kieu du lieu so nguyen khac nhau
int main() {
    int mang[] = {12, 35, 1, 10, 34, 1};
    int kich_co = sizeof(mang) / sizeof(mang[0]);
    int i;
    int lon_nhat, lon_thu_hai;
    if (kich_co < 2) {
        printf("Loi: Mang phai co it nhat 2 phan tu.\n");
        return 1;
    }
    lon_nhat = INT_MIN; // gia tri toi thieu cua ham int
    lon_thu_hai = INT_MIN; // gia tri toi thieu cua ham int
    for (i = 0; i < kich_co; i++) {
        if (mang[i] > lon_nhat) {
            lon_thu_hai = lon_nhat;
            lon_nhat = mang[i];
        } else if (mang[i] > lon_thu_hai && mang[i] != lon_nhat) {
            lon_thu_hai = mang[i];
        }
    }

    if (lon_thu_hai == INT_MIN) {
        printf("Loi: Khong tim thay phan tu lon thu hai (co the tat ca cac phan tu deu bang nhau).\n");
        return 1;
    }

    printf("Phan tu lon nhat: %d\n", lon_nhat);
    printf("Phan tu lon thu hai: %d\n", lon_thu_hai);

    return 0;
}

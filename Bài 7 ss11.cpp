#include <stdio.h>
#include <limits.h>

int main() {
    int gia_co_phieu[] = {100, 90, 80, 110, 120};
    int so_thang = sizeof(gia_co_phieu) / sizeof(gia_co_phieu[0]);
    int gia_mua_ban_dau, lo_thap_nhat;
    int co_lo = 0;
    int i;
    if (so_thang < 2) {
        printf("Mang phai co it nhat 2 phan tu.\n");
        return 1;
    }

    gia_mua_ban_dau = gia_co_phieu[0];
    lo_thap_nhat = INT_MAX;

    for (i = 1; i < so_thang; i++) {
        int lo_hien_tai = gia_mua_ban_dau - gia_co_phieu[i];
        
        if (lo_hien_tai > 0) { // N?u có l?
            co_lo = 1;
            if (lo_hien_tai < lo_thap_nhat) {
                lo_thap_nhat = lo_hien_tai;
            }
        }
    }

    if (co_lo) {
        printf("So lo thap nhat la: %d\n", lo_thap_nhat);
    } else {
        printf("Ban co the ban co lai hoac hoa von.\n");
    }

    return 0;
}

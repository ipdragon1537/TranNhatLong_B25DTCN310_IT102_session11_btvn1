#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    int choice;
    int i, j;
    int temp, sum;
    int value, index, foundIndex;
    int left, right, mid;
    int count;
    char confirm;

    int isSorted = 0;

    do {
        printf("\n========== MENU CHUC NANG ==========\n");
        printf("1. Nhap gia tri n phan tu vao mang\n");
        printf("2. In gia tri cac phan tu cua mang\n");
        printf("3. Tinh va in tong, trung binh cong\n");
        printf("4. Sap xep mang\n");
        printf("5. Tim kiem phan tu\n");
        printf("6. Xoa phan tu theo chi so\n");
        printf("7. Chen 1 phan tu vao mang\n");
        printf("8. Xoa cac phan tu co gia tri bang\n");
        printf("9. Thoat\n");
        printf("====================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu (n <= 100): ");
                scanf("%d", &n);
                if (n > 100 || n <= 0) {
                    printf("So phan tu khong hop le. Vui long nhap lai.\n");
                    n = 0;
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                isSorted = 0;
                printf("Nhap mang thanh cong!\n");
                break;

            case 2:
                if (n == 0) {
                    printf("Mang rong. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Cac phan tu cua mang: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Mang rong. Khong the tinh tong va trung binh cong.\n");
                    break;
                }
                sum = 0;
                for (i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cac phan tu: %d\n", sum);
                printf("Trung binh cong: %.2f\n", (float)sum / n);
                break;

            case 4:
                if (n == 0) {
                    printf("Mang rong. Khong the sap xep.\n");
                    break;
                }
                printf("a. Tang dan theo Bubble Sort\n");
                printf("b. Giam dan theo Selection Sort\n");
                printf("c. Tang dan theo Insertion Sort\n");
                printf("Nhap lua chon: ");
                char sortChoice;
                scanf(" %c", &sortChoice);

                switch (sortChoice) {
                    case 'a':
                        for (i = 0; i < n - 1; i++) {
                            for (j = 0; j < n - i - 1; j++) {
                                if (arr[j] > arr[j + 1]) {
                                    temp = arr[j];
                                    arr[j] = arr[j + 1];
                                    arr[j + 1] = temp;
                                }
                            }
                        }
                        isSorted = 1;
                        printf("Mang da duoc sap xep tang dan (Bubble Sort).\n");
                        break;
                    case 'b':
                        for (i = 0; i < n - 1; i++) {
                            int max_idx = i;
                            for (j = i + 1; j < n; j++) {
                                if (arr[j] > arr[max_idx]) {
                                    max_idx = j;
                                }
                            }
                            temp = arr[max_idx];
                            arr[max_idx] = arr[i];
                            arr[i] = temp;
                        }
                        isSorted = 1;
                        printf("Mang da duoc sap xep giam dan (Selection Sort).\n");
                        break;
                    case 'c':
                        for (i = 1; i < n; i++) {
                            temp = arr[i];
                            j = i - 1;
                            while (j >= 0 && arr[j] > temp) {
                                arr[j + 1] = arr[j];
                                j = j - 1;
                            }
                            arr[j + 1] = temp;
                        }
                        isSorted = 1;
                        printf("Mang da duoc sap xep tang dan (Insertion Sort).\n");
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;

            case 5:
                if (n == 0) {
                    printf("Mang rong. Khong the tim kiem.\n");
                    break;
                }
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                foundIndex = -1;

                if (isSorted) {
                    left = 0;
                    right = n - 1;
                    while (left <= right) {
                        mid = left + (right - left) / 2;
                        if (arr[mid] == value) {
                            foundIndex = mid;
                            break;
                        }
                        if (arr[mid] < value) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                    if (foundIndex != -1) {
                        printf("Tim thay phan tu %d tai chi so %d (Binary Search).\n", value, foundIndex);
                    } else {
                        printf("Khong tim thay phan tu %d (Binary Search).\n", value);
                    }
                } else {
                    for (i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            foundIndex = i;
                            break;
                        }
                    }
                    if (foundIndex != -1) {
                        printf("Tim thay phan tu %d tai chi so %d (Linear Search).\n", value, foundIndex);
                    } else {
                        printf("Khong tim thay phan tu %d (Linear Search).\n", value);
                    }
                }
                break;

            case 6:
                if (n == 0) {
                    printf("Mang rong. Khong the xoa.\n");
                    break;
                }
                printf("Nhap chi so phan tu can xoa: ");
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Chi so khong hop le.\n");
                    break;
                }
                for (i = index; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Da xoa phan tu tai chi so %d.\n", index);
                isSorted = 0;
                break;

            case 7:
                if (n >= 100) {
                    printf("Mang da day. Khong the chen them.\n");
                    break;
                }
                printf("Nhap chi so can chen: ");
                scanf("%d", &index);
                if (index < 0 || index > n) {
                    printf("Chi so khong hop le.\n");
                    break;
                }
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                for (i = n; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                n++;
                printf("Da chen phan tu vao chi so %d.\n", index);
                isSorted = 0;
                break;

            case 8:
                if (n == 0) {
                    printf("Mang rong. Khong the xoa.\n");
                    break;
                }
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                
                count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        count++;
                    } else {
                        arr[i - count] = arr[i];
                    }
                }
                n -= count;
                printf("Da xoa tat ca %d phan tu co gia tri %d.\n", count, value);
                isSorted = 0;
                break;

            case 9:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }

        if (choice != 9) {
            printf("\nBan co muon tiep tuc khong? (Y/N): ");
            scanf(" %c", &confirm);
            if (confirm != 'Y' && confirm != 'y') {
                break;
            }
        }

    } while (1);

    return 0;
}

#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX];
    int n = 0, choice, x;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Nhap so luong va gia tri tung phan tu\n");
        printf("2. In ra cac phan tu trong mang\n");
        printf("3. In ra cac phan tu chi co so chan trong mang\n");
        printf("4. In ra gia tri lon nhat cua cac phan tu trong mang\n");
        printf("5. Them moi 1 phan tu vao vi tri cu the\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang giam dan (Insertion Sort)\n");
        printf("8. Kiem tra su ton tai cua phan tu trong mang (Binary Search)\n");
        printf("9. In ra cac phan tu chi xuat hien 1 lan trong mang\n");
        printf("10. Tim va in cac cap phan tu trong mang co tong bang k\n");
        printf("0. Thoat chuong trinh\n");
        printf("=========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            if (n > MAX) n = MAX;
            for (int i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
            break;

        case 2:
            printf("Cac phan tu trong mang la: ");
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;

        case 3:
            printf("Cac phan tu chan trong mang la: ");
            for (int i = 0; i < n; i++)
                if (a[i] % 2 == 0)
                    printf("%d ", a[i]);
            printf("\n");
            break;

        case 4: {
            if (n == 0) {
                printf("Mang rong!\n");
                break;
            }
            int max = a[0];
            for (int i = 1; i < n; i++)
                if (a[i] > max)
                    max = a[i];
            printf("Gia tri lon nhat trong mang la: %d\n", max);
            break;
        }

        case 5: {
            int pos, val;
            printf("Nhap vi tri muon chen (0-%d): ", n);
            scanf("%d", &pos);
            printf("Nhap gia tri muon chen: ");
            scanf("%d", &val);
            if (pos < 0 || pos > n) {
                printf("Vi tri khong hop le!\n");
                break;
            }
            for (int i = n; i > pos; i--)
                a[i] = a[i - 1];
            a[pos] = val;
            n++;
            printf("Da them phan tu thanh cong!\n");
            break;
        }

        case 6: {
            int pos;
            printf("Nhap vi tri muon xoa (0-%d): ", n - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("Vi tri khong hop le!\n");
                break;
            }
            for (int i = pos; i < n - 1; i++)
                a[i] = a[i + 1];
            n--;
            printf("Da xoa phan tu thanh cong!\n");
            break;
        }

        case 7: {
            for (int i = 1; i < n; i++) {
                int key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j] < key) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = key;
            }
            printf("Mang sau khi sap xep giam dan: ");
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;
        }

        case 8: {
            if (n == 0) {
                printf("Mang rong!\n");
                break;
            }
            int found = 0;
            printf("Nhap gia tri can tim: ");
            scanf("%d", &x);

            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[mid] == x) {
                    printf("Phan tu %d duoc tim thay tai vi tri: %d\n", x, mid);
                    found = 1;
                    break;
                } else if (a[mid] < x)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            if (!found)
                printf("Khong tim thay phan tu %d trong mang.\n", x);
            break;
        }

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}


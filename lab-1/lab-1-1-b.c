#include <stdio.h>

int main() {
    int a, b, c, catch = 1;
    while(catch != 0) {
        printf("Хооронд нь нэмэх хоёр тоогоо оруулна уу: ");
        scanf("%d%d", &a, &b);
        printf("Чиний хувьд хариу нь хэд гарах бол?: ");
        scanf("%d", &c);
        if(a + b == c) {
            printf("%d + %d = %d -> Зөв байна\n", a, b, c);
            catch = 0;
        } else {
            printf("%d + %d = %d -> Буруу байна\n", a, b, c);
        }
    }
    return 0;
}
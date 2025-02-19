#include <stdio.h>

int main() {
    int a, b, c, right = 0, total = 5;
    float ratio = 100;
    for(int i = 0; i < total; i++) {
        printf("Хооронд нь нэмэх хоёр тоогоо оруулна уу: ");
        scanf("%d%d", &a, &b);
        printf("Чиний хувьд хариу нь хэд гарах бол?: ");
        scanf("%d", &c);
        if(a + b == c) {
            printf("%d + %d = %d -> Зөв байна\n", a, b, c);
            right++;
        } else {
            printf("%d + %d = %d -> Буруу байна\n", a, b, c);
        }
    }
    ratio = ratio * right / total;
    printf("Нийт %d-н удаа зөв бодсон байна. %.1f хувийн оновчтой.", right, ratio);
    return 0;
}
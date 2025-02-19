#include <stdio.h>

int main() {
    int a, b, c;
    printf("Хооронд нь нэмэх хоёр тоогоо оруулна уу: ");
    scanf("%d%d", &a, &b);
    printf("Чиний хувьд хариу нь хэд гарах бол?: ");
    scanf("%d", &c);
    if(a + b == c) 
        printf("%d + %d = %d -> Зөв байна\n", a, b, c);
    else
        printf("%d + %d = %d -> Буруу байна\n", a, b, c);
    return 0;
}
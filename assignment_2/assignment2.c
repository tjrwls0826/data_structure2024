#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char a[100]; 
    int len = 0;

    printf("���ڿ��� �Է��ϼ���:");
    scanf("%s", a);

    for (int i = 0; a[i] != '\0'; ++i) {
        len++;
    }

    printf("\n\n�Է��� ���ڿ���\n\"%s\"\n�Դϴ�.\n\n", a);
    printf("�Էµ� ���ڿ��� ����=%d\n", len);

    return 0;
}
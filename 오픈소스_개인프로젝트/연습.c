#include<stdio.h>
#define MANUAL_TIME 10  // �޴����� ������ �ð�(sec����)
#define SHEET_SIZE 100  // �Է¹��� �� �ִ� �Ǻ� ���ڿ� �迭�� ũ��

// �Է¹��� ���� �ľ��� ���ڿ�
char note[24] = "CVDWEFXGYAZBcvdwefxgyazb";
/*
�Է¹��� ���� �迭 ������ �ε����ν� ��ȯ�� ��.
�Է¹��� �� : �� (�⺻�� 7�� + �� 5��)*2��Ÿ�� = 24�� (�� ~ ���� ��)
*/

// ������Ų �Ŀ� ����� ���� �ľ��ϴ� ������ �迭
char* pnote[48] = {
    "����", "��#��", "����", "��#��", "�̡�",
    "�ġ�", "��#��", "�֡�", "��#��", "���", "��#��", "�á�",
    "��", "��#", "��", "��#", "��",
    "��", "��#", "��", "��#", "��", "��#", "��",
    "�� ��", "��# ��", "�� ��", "��# ��", "�� ��", "�� ��",
    "��# ��", "�� ��", "��# ��", "�� ��", "��# ��", "�� ��",
    "�� ���", "��# ���", "�� ���", "��# ���", "�� ���", "�� ���",
    "��# ���", "�� ���", "��# ���", "�� ���", "��# ���", "�� ���"
};
/*
�ܾ �����ؾ� �ϹǷ� ������ �迭�� ����Ͽ���.
(������ �迭�� ���� ���� ������, ȭ��ǥ ��ȣ�� ��� ����� �� ����)
�ִ� 12Ű�� �ø��� ���� ���̱� ������, ���� note[24] �迭���� 12���� ���� Ȯ���Ͽ���.
*/

// ���� �� ����ϴ� �Լ�
void izo(char sheet[], int key, int madi) {

    int count = 0;  // ���� �����ϱ� ���� ����ϴ� ����
    int j;

    printf("\n");   // �������� ���� �ٹٲ�

    for (int i = 0; sheet[i] != NULL; i++) {
        /*
        �ݺ� ���� ������ �迭�� NULL�� �����Ͽ�,
        ����ڰ� �Է��� ��ŭ�� ���� �� ����� �ǵ���.
        */

        // sheet[i]�� �� -> note[j]�� ������ �ٲ㼭 �ľ�
        for (j = 0; j < 24; j++)
            if (sheet[i] == note[j])
                break;
        /*
        sheet[i]�� � ���� ��Ÿ�������� note �迭�� �������ν�,
        ����(�ε���)�� �ľ� -> ���ڷ� �ľ��� �� �־�� ������ ����.
        */

        // ������ ���� ��� (\t�� ����, �������� ������ ����)
        printf("%s\t", pnote[j + 12 + key]);
        /*
        note�� j��° ����
        + 12    : note[24] �迭�� ���� pnote[48]��
                  note�� ���� �� �տ�, ������(��) 12���� �߰��Ǿ��� ������
                  �̸� �ݿ��Ͽ� �ùٸ� ������ �ϱ� ����.
        +key    : ����ڰ� �����ϰ� ���� ũ�⸸ŭ ������ ��
        */

        // ���� ���п� �ٹٲ�
        count++;    // ���� �� ���� ������ ī��Ʈ�Ͽ�,
        if (count == madi) {    // ����ڰ� �Է��� madi���� �Ǹ�,
            printf("\n");       // �ٹٲ� (���� �����ϱ� ����)
            count = 0;          // �ٽ� ī��Ʈ���� �ʱ�ȭ
        }
    }

}

// izo()�Լ����� ������ ���� ���� �Լ� (���� �Ǻ��� ����ؼ� �����ֱ� ����)
// izo()�Լ��� �����ϹǷ�, �ּ��� �� ������ �ʾ��� (������ izo()�Լ� ����)
void not_izo(char sheet[], int key, int madi) {

    int j, count = 0;

    printf("\n");

    for (int i = 0; sheet[i] != NULL; i++) {

        for (j = 0; j < 24; j++)
            if (sheet[i] == note[j])
                break;

        printf("%s\t", pnote[j + 12]);

        // ���� ���п� �ٹٲ�
        count++;
        if (count == madi) {
            printf("\n");
            count = 0;
        }
    }
}

// ���� ȭ�� : �޴��� ����ϴ� �Լ�
void menu() {
    system("cls");  // ȭ�� �ʱ�ȭ �� ����ȭ�� ���

    printf("[���� ���α׷�]\n\n");
    printf(" �ѤѤѤѤѤѤѸ޴��ѤѤѤѤѤѤ�\n");
    printf("|\t\t\t\t |\n");
    printf("|\t1. ���� �����ϱ�\t |\n");
    printf("|\t2. �Ǻ� �Է� �޴���\t |\n");
    printf("|\t3. ����\t\t\t |\n");
    printf("|\t\t\t\t |\n");
    printf(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
    // ĭ�� ����� ���� \t, \n ������ ����Ͽ� �޴�ȭ�� ����

    printf("�޴��� �����ϼ��� : "); // �޴� ���� �ȳ� �������� ���
}

void manual() {
    int sec = MANUAL_TIME;  // �޴����� ������ �ð���

    // �Ǻ� �Է� �޴���
    printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("<�⺻ ��>\n");
    printf("��\t��\t��\t��\t��\t��\t��\n");
    printf("C\tD\tE\tF\tG\tA\tB\n");
    printf("\n<#�� ��>\n");
    printf("��#/����\t��#/�̢�\t��#/�֢�\t��#/���\t��#/�â�\n");
    printf("V\tW\tX\tY\tZ\n");
    printf("\n��Ÿ���� ��쿣 �ҹ��ڷ� �Է��մϴ�.");
    printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");

    printf("%d�� �� �޴����� ����˴ϴ�.\n", sec);

    // ���� sec�� ��� : ���� �ݺ��� sec > 0������
    while (sec > 0) {
        printf("%d ", sec); // ���� �� ĭ�� �������� sec ���
        Sleep(1000);    // 1000(�и��� ����) == 1sec�� ��� ����
        sec--;  // sec�� �ϳ��� ����
    }
}

void start() {
    char sheet[SHEET_SIZE];
    int key, madi;

    printf("\n�ø��ų� ���� Ű�� �Է��ϼ��� (���� : -12 ~ 12) : ");
    scanf("%d", &key);

    printf("\n�� ���� �� ��ǥ�� ���� �Է��ϼ��� (������ �Է�) : ");
    scanf("%d", &madi);

    printf("\n������ �Ǻ��� �Է��ϼ���. (�ִ� 100���� ��)\n");
    scanf("%s", sheet);

    printf("\n\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�<���� ��>�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    not_izo(sheet, key, madi);  // ���� �� ���� �Ǻ� ���

    printf("\n\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�<���� ��>�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    izo(sheet, key, madi);      // ���� �� �Ǻ��� ���

    printf("\n\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("������ �Ϸ�Ǿ����ϴ�.\n");
}

int main() {
    int n;

    while (1) {

        menu();
        scanf("%d", &n);

        if (n == 1) {
            start();
            break;
        }
        else if (n == 2) {
            manual();
        }
        else if (n == 3) {
            printf("\n���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("\n***�Է��� �ùٸ��� �ʽ��ϴ�!*** (1�� �� �����)\n\n");
            Sleep(1000);
            getchar();
            /*
            ���� �Է� ��, �޴� ����� ���ѷ����Ǵ� ������ �����ϱ� ����
            ���� �ʱ�ȭ�� �����Ͽ� n ���� ���
            */
        }
    }


    return 0;
}

/*
// Beep() ����

#include <stdio.h>
#include <windows.h>

// ���� ���ļ�
#define C4  261
#define D4  294
#define E4  329
#define F4  349
#define G4  392
#define A4  440
#define B4  493

void playNote(int freq, int duration) {
    Beep(freq, duration);
}

void rest(int duration) {
    Sleep(duration); // duration is in milliseconds
}

int main() {
    // Example melody: C4, D4, E4, rest, F4, G4, A4, B4
    int melody[] = { C4, D4, E4, 0, F4, G4, A4, B4 };
    int noteDurations[] = { 500, 500, 500, 500, 500, 500, 500, 500 }; // milliseconds

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        if (melody[i] == 0) {
            rest(noteDurations[i]);
        }
        else {
            playNote(melody[i], noteDurations[i]);
        }
    }

    return 0;
}
*/
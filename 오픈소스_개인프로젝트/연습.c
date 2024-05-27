#include<stdio.h>
#define MANUAL_TIME 10  // 메뉴얼을 보여줄 시간(sec단위)
#define SHEET_SIZE 100  // 입력받을 수 있는 악보 문자열 배열의 크기

// 입력받은 음을 파악할 문자열
char note[24] = "CVDWEFXGYAZBcvdwefxgyazb";
/*
입력받을 음을 배열 원소의 인덱스로써 반환할 것.
입력받을 음 : 총 (기본음 7개 + 샾 5개)*2옥타브 = 24개 (도 ~ 높은 시)
*/

// 이조시킨 후에 출력할 음을 파악하는 포인터 배열
char* pnote[48] = {
    "도↓", "도#↓", "레↓", "레#↓", "미↓",
    "파↓", "파#↓", "솔↓", "솔#↓", "라↓", "라#↓", "시↓",
    "도", "도#", "레", "레#", "미",
    "파", "파#", "솔", "솔#", "라", "라#", "시",
    "도 ↑", "도# ↑", "레 ↑", "레# ↑", "미 ↑", "파 ↑",
    "파# ↑", "솔 ↑", "솔# ↑", "라 ↑", "라# ↑", "시 ↑",
    "도 ↑↑", "도# ↑↑", "레 ↑↑", "레# ↑↑", "미 ↑↑", "파 ↑↑",
    "파# ↑↑", "솔 ↑↑", "솔# ↑↑", "라 ↑↑", "라# ↑↑", "시 ↑↑"
};
/*
단어를 저장해야 하므로 포인터 배열을 사용하였다.
(이차원 배열로 하지 않은 이유는, 화살표 기호가 어떻게 저장될 지 몰라서)
최대 12키를 올리고 내릴 것이기 때문에, 기존 note[24] 배열에서 12개의 음씩 확장하였다.
*/

// 이조 및 출력하는 함수
void izo(char sheet[], int key, int madi) {

    int count = 0;  // 마디를 구분하기 위해 사용하는 변수
    int j;

    printf("\n");   // 가독성을 위한 줄바꿈

    for (int i = 0; sheet[i] != NULL; i++) {
        /*
        반복 실행 조건을 배열의 NULL로 설정하여,
        사용자가 입력한 만큼만 이조 및 출력이 되도록.
        */

        // sheet[i]의 음 -> note[j]의 음으로 바꿔서 파악
        for (j = 0; j < 24; j++)
            if (sheet[i] == note[j])
                break;
        /*
        sheet[i]가 어떤 음을 나타내는지를 note 배열과 비교함으로써,
        숫자(인덱스)로 파악 -> 숫자로 파악할 수 있어야 이조가 쉬움.
        */

        // 이조된 음을 출력 (\t을 통해, 가독성이 좋도록 만듦)
        printf("%s\t", pnote[j + 12 + key]);
        /*
        note의 j번째 음을
        + 12    : note[24] 배열에 비해 pnote[48]은
                  note의 시작 음 앞에, 낮은음(↓) 12개가 추가되었기 때문에
                  이를 반영하여 올바른 이조를 하기 위함.
        +key    : 사용자가 이조하고 싶은 크기만큼 이조한 것
        */

        // 마디 구분용 줄바꿈
        count++;    // 마디 당 음의 개수를 카운트하여,
        if (count == madi) {    // 사용자가 입력한 madi값이 되면,
            printf("\n");       // 줄바꿈 (마디를 구분하기 위함)
            count = 0;          // 다시 카운트값은 초기화
        }
    }

}

// izo()함수에서 이조만 하지 않은 함수 (원본 악보를 출력해서 보여주기 위함)
// izo()함수와 동일하므로, 주석을 또 달지는 않았음 (설명은 izo()함수 참고)
void not_izo(char sheet[], int key, int madi) {

    int j, count = 0;

    printf("\n");

    for (int i = 0; sheet[i] != NULL; i++) {

        for (j = 0; j < 24; j++)
            if (sheet[i] == note[j])
                break;

        printf("%s\t", pnote[j + 12]);

        // 마디 구분용 줄바꿈
        count++;
        if (count == madi) {
            printf("\n");
            count = 0;
        }
    }
}

// 시작 화면 : 메뉴를 출력하는 함수
void menu() {
    system("cls");  // 화면 초기화 및 시작화면 출력

    printf("[이조 프로그램]\n\n");
    printf(" ㅡㅡㅡㅡㅡㅡㅡ메뉴ㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("|\t\t\t\t |\n");
    printf("|\t1. 이조 시작하기\t |\n");
    printf("|\t2. 악보 입력 메뉴얼\t |\n");
    printf("|\t3. 종료\t\t\t |\n");
    printf("|\t\t\t\t |\n");
    printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
    // 칸을 만들기 위해 \t, \n 적절히 사용하여 메뉴화면 제작

    printf("메뉴를 선택하세요 : "); // 메뉴 선택 안내 문구까지 출력
}

void manual() {
    int sec = MANUAL_TIME;  // 메뉴얼을 보여줄 시간값

    // 악보 입력 메뉴얼
    printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("<기본 음>\n");
    printf("도\t레\t미\t파\t솔\t라\t시\n");
    printf("C\tD\tE\tF\tG\tA\tB\n");
    printf("\n<#과 ♭>\n");
    printf("도#/레♭\t레#/미♭\t파#/솔♭\t솔#/라♭\t라#/시♭\n");
    printf("V\tW\tX\tY\tZ\n");
    printf("\n옥타브의 경우엔 소문자로 입력합니다.");
    printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");

    printf("%d초 후 메뉴얼이 종료됩니다.\n", sec);

    // 남은 sec를 출력 : 따라서 반복은 sec > 0때까지
    while (sec > 0) {
        printf("%d ", sec); // 띄어쓰기 한 칸을 기준으로 sec 출력
        Sleep(1000);    // 1000(밀리초 단위) == 1sec간 명령 쉬기
        sec--;  // sec값 하나씩 감소
    }
}

void start() {
    char sheet[SHEET_SIZE];
    int key, madi;

    printf("\n올리거나 내릴 키를 입력하세요 (범위 : -12 ~ 12) : ");
    scanf("%d", &key);

    printf("\n한 마디에 들어갈 음표의 수를 입력하세요 (정수로 입력) : ");
    scanf("%d", &madi);

    printf("\n이조할 악보를 입력하세요. (최대 100개의 음)\n");
    scanf("%s", sheet);

    printf("\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ<이조 전>ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    not_izo(sheet, key, madi);  // 이조 전 원본 악보 출력

    printf("\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ<이조 후>ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    izo(sheet, key, madi);      // 이조 된 악보를 출력

    printf("\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("이조가 완료되었습니다.\n");
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
            printf("\n프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("\n***입력이 올바르지 않습니다!*** (1초 후 재시작)\n\n");
            Sleep(1000);
            getchar();
            /*
            문자 입력 시, 메뉴 출력이 무한루프되는 오류를 방지하기 위해
            버퍼 초기화를 진행하여 n 값을 비움
            */
        }
    }


    return 0;
}

/*
// Beep() 사용법

#include <stdio.h>
#include <windows.h>

// 음의 주파수
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
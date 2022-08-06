#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define AI 17
#define SPADE "♠"
#define CLUB "♣"
#define DIA "◆"
#define HEART "♥"

struct Player {
    int cash;
    int score;
    int count;
};
struct Player player[2];

void betting(int player) {//베팅할 액수를 입력
    int bet;
    printf("베팅하실 칩 개수를 입력하세요~~ : ");
    while (1) {
        scanf("%d", &bet);
        if (bet > player) {
            printf("베팅하신 개수가 충전량을 넘었습니다. 다시 입력하세요~~ : ");
            continue;
        }
        break;
    }
}

void card(int count) {
    srand(time(NULL));//문제!
    int n = rand() % 13;
    int c = rand() % 4, ace;
    switch (c) {
    case 0: printf("%s", SPADE); break;
    case 1: printf("%s", HEART); break;
    case 2: printf("%s", CLUB); break;
    case 3: printf("%s", DIA); break;
    }
    switch (n) {
    case 10: printf("K"); count += 10; break;
    case 11: printf("Q"); count += 10; break;
    case 12: printf("J"); count += 10; break;
    case 0: printf("A"); 
        printf("\nACE를 뽑으셨습니다! ACE를 [1/11]점으로 계산합니다 : ");
        while (1) {
            scanf("%d", &ace);
            if (ace != 1 && ace != 11) printf("1, 11중 하나의 값을 입력하세요~:");
            break;
        } count += ace; break;
    default: printf("%d", c + 1); count += (c+1);
    }
    printf("  ");
}

void play() {
    printf("player0님 "); betting(player[0].cash); //베팅 액수를 입력
    printf("player1님 "); betting(player[1].cash);
    for (int i = 0; i <= 1; i++) {
        player[i].count = 0;
    }
    for (int i = 0; i <= 1; i++) {
        card(player[i].count);
        card(player[i].count);
        puts("");
    }
    //모르겠다;;

}

void cash() {
    char cash;
    for (int i = 0; i <= 1; i++) {
        player[i].score = 0;
        printf("player%d님 충전하실 금액을 입력해 주세요 : ", i);
        scanf("%d", &player[i].cash);
    }
}

int main() {
        char choice;
        printf("블랙잭 게임에 오신 것을 환영합니다! 지금 바로 시작하시겠습니까? [y/n] ");
        scanf("%c", &choice);

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            printf("이상한 문자를 입력하셨습니다. 다시 입력해주세요! [y/n] ");
            scanf("%c", &choice);
        }

        if (choice == 'Y' || choice == 'y')
        {
            cash();
            play();
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("블랙잭 게임을 종료하겠습니다.\n");
        }
}
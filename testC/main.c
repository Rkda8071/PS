#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SPADE "♠"
#define CLUB "♣"
#define DIA "◆"
#define HEART "♥"

struct Player {
    int cash;
    int count;
    int bet;
};
struct Player player[2];
int turn = 0; void play();

void betting(int p) {//베팅할 액수를 입력
    int bet = 0;
    printf("베팅하실 칩 개수를 입력하세요~~ : ");
    while (1) {
        scanf("%d", &player[p].bet);
        if (bet > player[p].cash) {
            printf("베팅하신 개수가 충전량을 넘었습니다. 다시 입력하세요~~ : ");
            continue;
        }
        break;
    }
}

void card(int p) {
    int n = rand() % 13;
    int c = rand() % 4, ace;
    switch (c) {
    case 0: printf("%s", SPADE); break;
    case 1: printf("%s", HEART); break;
    case 2: printf("%s", CLUB); break;
    case 3: printf("%s", DIA); break;
    }
    switch (n) {
    case 10: printf("K"); player[p].count += 10; break;
    case 11: printf("Q"); player[p].count += 10; break;
    case 12: printf("J"); player[p].count += 10; break;
    case 0: printf("A");
        printf("\nACE를 뽑으셨습니다! ACE를 [1/11]점으로 계산합니다 : ");
        while (1) {
            scanf("%d", &ace);
            if (ace != 1 && ace != 11) printf("1, 11중 하나의 값을 입력하세요~:");
            break;
        } player[p].count += ace; break;
    default: printf("%d", c + 1); player[p].count += (c+1);
    }
    printf("  ");
}

void hit(int p) {
    int q;
    char command;
    if (p == 1)q = 0;
    if (p == 0)q = 1;
    while (1) {
        turn++;
        printf("\nTurn %d\n\n", turn);
        printf("\nHit하실거면 h, Stand하실 거라면 s를 입력해 주세요 [h/s] : ");
        scanf(" %c", &command);
        if (command == 'h' || command == 'H') {
            card(p); printf("\nplayer%d님의 count : %d : ", p, player[p].count);
        }
        else if (command == 'h' || command == 'H') {
            printf("\nplayer%d님의 count : %d", p, player[0].count);
            break;
        }
        else if(command != 'h' && command != 'H' && command != 'h' && command != 'H') {
            printf("다시 입력해주세요~~");
        }
    }
}

void result(int p) {
    int q;
    if (p == 1)q = 0;
    if (p == 0)q = 1;
    printf("\n!!! player%d님이 파산하셨습니다 !!!", p);
    printf("\nplayer%d님의 승리입니다!!!", q);
    return 0;
}

void BlackJack(int p) {
    int q;
    if (p == 1)q = 0;
    if (p == 0)q = 1;
    printf("Congratulation! 블랙잭입니다!\n");
    player[p].count += player[p].bet * 3 / 2;
    player[q].count -= player[q].bet;
    printf("player%d님의 cash : %d\n", p, player[p].count);
    printf("player%d님의 cash : %d\n", q, player[q].count);
    if (player[q].count <= 0) result(q);
}

void play() {
    srand(time(NULL));
    char command;
    printf("player0님 "); betting(0); //베팅 액수를 입력
    printf("player1님 "); betting(1);
    puts("");
    for (int i = 0; i <= 1; i++) {
        printf("player%d님의 카드 : ", i);
        card(i);
        card(i); printf("\nplayer%d님의 count : %d ", i, player[i].count);
        puts("");
    }
    if (player[0].count == 21 && player[1].count == 21) {//블랙잭 판별
        printf("비겼습니다. 새로운 라운드를 시작합니다.\n\n");
        play();
    }
    else if (player[0].count == 21 && player[1].count != 21) {
        BlackJack(0);
    }
    else if (player[0].count != 21 && player[1].count == 21) {
        BlackJack(1);
    }

    if (player[0].count >= player[1].count) {
        printf("\n===========player0님의 turn입니다~!============");
        hit(0);
    }
    else {
        printf("\n===========player1님의 turn입니다~!============");
        hit(1);
    }

    for (int i = 0; i <= 1; i++) {
        if (player[i].count <= 0) {
            result(i);
        }
    }
}

void cash() {
    for (int i = 0; i <= 1; i++) {
        player[i].count = 0;
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

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SPADE "��"
#define CLUB "��"
#define DIA "��"
#define HEART "��"

struct Player {
    int cash;
    int count;
    int bet;
};
struct Player player[2];
int turn = 0; void play();

void betting(int p) {//������ �׼��� �Է�
    int bet = 0;
    printf("�����Ͻ� Ĩ ������ �Է��ϼ���~~ : ");
    while (1) {
        scanf("%d", &player[p].bet);
        if (bet > player[p].cash) {
            printf("�����Ͻ� ������ �������� �Ѿ����ϴ�. �ٽ� �Է��ϼ���~~ : ");
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
        printf("\nACE�� �����̽��ϴ�! ACE�� [1/11]������ ����մϴ� : ");
        while (1) {
            scanf("%d", &ace);
            if (ace != 1 && ace != 11) printf("1, 11�� �ϳ��� ���� �Է��ϼ���~:");
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
        printf("\nHit�ϽǰŸ� h, Stand�Ͻ� �Ŷ�� s�� �Է��� �ּ��� [h/s] : ");
        scanf(" %c", &command);
        if (command == 'h' || command == 'H') {
            card(p); printf("\nplayer%d���� count : %d : ", p, player[p].count);
        }
        else if (command == 'h' || command == 'H') {
            printf("\nplayer%d���� count : %d", p, player[0].count);
            break;
        }
        else if(command != 'h' && command != 'H' && command != 'h' && command != 'H') {
            printf("�ٽ� �Է����ּ���~~");
        }
    }
}

void result(int p) {
    int q;
    if (p == 1)q = 0;
    if (p == 0)q = 1;
    printf("\n!!! player%d���� �Ļ��ϼ̽��ϴ� !!!", p);
    printf("\nplayer%d���� �¸��Դϴ�!!!", q);
    return 0;
}

void BlackJack(int p) {
    int q;
    if (p == 1)q = 0;
    if (p == 0)q = 1;
    printf("Congratulation! �����Դϴ�!\n");
    player[p].count += player[p].bet * 3 / 2;
    player[q].count -= player[q].bet;
    printf("player%d���� cash : %d\n", p, player[p].count);
    printf("player%d���� cash : %d\n", q, player[q].count);
    if (player[q].count <= 0) result(q);
}

void play() {
    srand(time(NULL));
    char command;
    printf("player0�� "); betting(0); //���� �׼��� �Է�
    printf("player1�� "); betting(1);
    puts("");
    for (int i = 0; i <= 1; i++) {
        printf("player%d���� ī�� : ", i);
        card(i);
        card(i); printf("\nplayer%d���� count : %d ", i, player[i].count);
        puts("");
    }
    if (player[0].count == 21 && player[1].count == 21) {//���� �Ǻ�
        printf("�����ϴ�. ���ο� ���带 �����մϴ�.\n\n");
        play();
    }
    else if (player[0].count == 21 && player[1].count != 21) {
        BlackJack(0);
    }
    else if (player[0].count != 21 && player[1].count == 21) {
        BlackJack(1);
    }

    if (player[0].count >= player[1].count) {
        printf("\n===========player0���� turn�Դϴ�~!============");
        hit(0);
    }
    else {
        printf("\n===========player1���� turn�Դϴ�~!============");
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
        printf("player%d�� �����Ͻ� �ݾ��� �Է��� �ּ��� : ", i);
        scanf("%d", &player[i].cash);
    }
}


int main() {
        char choice;
        printf("���� ���ӿ� ���� ���� ȯ���մϴ�! ���� �ٷ� �����Ͻðڽ��ϱ�? [y/n] ");
        scanf("%c", &choice);

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            printf("�̻��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���! [y/n] ");
            scanf("%c", &choice);
        }

        if (choice == 'Y' || choice == 'y')
        {
            cash();
            play();
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("���� ������ �����ϰڽ��ϴ�.\n");
        }
}

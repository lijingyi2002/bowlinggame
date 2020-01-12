#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bowlinggame.h"

struct game_statue g_each_round[MAX_TOTAL_ROUND];

int input_prase(char *input, int size)
{
    int i;
    int round_cnt = 0;
    bool flag = 0;

    if ((size > MAX_TOTAL_SIZE && size < 11) || input == NULL) {
        printf("input ERR size%d !!!\n", size);
        return -1;
    }
    /* '0' stand for '-' and check input string*/
    for (i = 0; i < size; i++) {
        if (input[i] == '0') {
            printf("input string%d ERR:0 !!!\n", i);
            return -1;
        } else if (input[i] == '-') {
            input[i] = '0';
        }
    }

    for (i = 0; i < size; i++) {
        if (input[i] == 'x' || input[i] == 'X') {
            g_each_round[round_cnt].score = 10;
            g_each_round[round_cnt].game_type = TYPE_STRIKE;
            round_cnt++;
            flag = 0;
        } else if (input[i] == '/') {
            g_each_round[round_cnt].score = 10;
            g_each_round[round_cnt].game_type = TYPE_SPARE;
            round_cnt++;
            flag = 0;
        } else if ((input[i] >= '0' || input[i] <= '9')) {
            g_each_round[round_cnt].game_type = TYPE_NORMAL;
            if (flag) {
                g_each_round[round_cnt].score += (input[i] - '0');
                round_cnt++;
                flag = 0;
            } else {
                flag++;
            }
        } else {
            printf("input string%d ERR:%c or %c !!!\n", i, input[i], input[i + 1]);
            return -1;
        }
    }
}

int calc_score(char *input, int size, int *score)
{
    int i;
    int ret;
    int tmp = 0;

    memset(g_each_round, 0, sizeof(struct game_statue) * MAX_TOTAL_ROUND);
    ret = input_prase(input, size);
    if (ret)
        return ret;

    for (i = 0; i < NORMAL_ROUND; i++) {
        if (g_each_round[i].game_type == TYPE_STRIKE) {
            tmp += g_each_round[i].score + g_each_round[i + 1].score + g_each_round[i + 2].score;
        } else if (g_each_round[i].game_type == TYPE_SPARE) {
            tmp += g_each_round[i].score + g_each_round[i + 1].score;
        } else {
            tmp += g_each_round[i].score;
        }
    }
    *score = tmp;
    return 0;
}
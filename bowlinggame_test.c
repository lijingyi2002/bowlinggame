#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bowlinggame.h"

#define TEST_CASE_NUM 10
#define TEST_CASE_MAX_NUM 23
struct testcase {
    char input[TEST_CASE_MAX_NUM];
    int expect_score;
    int expect_ret;
};

struct testcase g_test[TEST_CASE_NUM] = {
    {"XXXXXXXXXXXX",          300, 0},
    {"12345123451234512345",  60,  0},
    {"9-9-9-9-9-9-9-9-9-9-",  90,  0},
    {"5/5/5/5/5/5/5/5/5/5/5", 150, 0},
    {"5/345123451234512345",  70,  0},
    {"125-3/XX12345123XXX",   113, 0},
    {"--------------------",  0,   0},
    {"XXXXXXXXXX1-",          272, 0},
    {"12345/X18-1234527XX1",  103, 0},
    {"XXXXXXXXXX",            0,   -1}
};

void check_result(char *string, int val, int inret, int num)
{   
    int ret;
    int score = 0;
    ret = calc_score(string, strlen(string), &score);
    if (inret != 0) {
        if (inret == ret) {
            printf("testcase %d success!!\n", num);
        } else {
            printf("testcase %d failed ret = %d, score = %d!!\n", num, ret, score);
        }
    } else {
        if (val == score && inret == ret) {
            printf("testcase %d success!!\n", num);
        } else {
            printf("testcase %d failed ret = %d, score = %d!!\n", num, ret, score);
        }
    }
}

int main(void)
{
    int i;
    for (i = 0; i < TEST_CASE_NUM; i++) {
        check_result(g_test[i].input, g_test[i].expect_score,
            g_test[i].expect_ret, i);
    }
    return 0;
}

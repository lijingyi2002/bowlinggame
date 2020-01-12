#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bowlinggame.h"

//char testcase0[] = {"XXXXXXXXXXXX"};

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
    check_result("XXXXXXXXXXXX", 300, 0, 0);
    check_result("12345123451234512345", 60, 0, 0);
    check_result("9-9-9-9-9-9-9-9-9-9-", 90, 0, 0);
    check_result("5/5/5/5/5/5/5/5/5/5/5", 150, 0, 0);
    check_result("5/345123451234512345", 70, 0, 0);
    check_result("125_3/XX12345123XXX", 113, 0, 0);
    return 0;
}

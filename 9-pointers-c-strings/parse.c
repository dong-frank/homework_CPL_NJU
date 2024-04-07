//
// Created by Frank on 2023/12/5.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void Find_value(char *with_value, char *unwith_value, const char *rule);

int main(void) {
    char rule[130] = {};
    //输入解析规则
    scanf("%s", rule);
    //找出需要参数的字母和不需要参数的字母
    char with_value[1000] = {0};
    char unwith_value[1000] = {0};
    Find_value(with_value, unwith_value, rule);
    char program[1000] = {0};
    scanf("%s", program);
    //输入命令
    char command[1000][10] = {0};
    char value[1000];//全体参数
    char num_value[1000][10] = {0};//需要参数的参数
    int count1 = 0;
    int is_value[1000] = {0};
    bool num = 1;
    bool legal = 1;
    while (scanf("%s", command[count1]) != EOF) {
        //判断参数类型
        if (command[count1][0] == '-') {
            value[count1] = command[count1][1];

            if (strchr(with_value, value[count1]) != NULL) { //需要参数的值
                if (scanf("%s", num_value[count1]) != EOF) {
                    is_value[count1] = 1;
                    count1++;
                } else {
                    num = 0;
                    break;
                }
            } else if (strchr(unwith_value, value[count1]) != NULL) {
                count1++;
            } else {
                legal = 0;
                break;
            }
        } else continue;
    }
    if (legal == 0) {
        printf("%s: invalid option -- '%c'", program, value[count1]);
    } else if (num == 0) {
        printf("%s: option requires an argument -- '%c'", program, value[count1]);
    } else {
        printf("%s\n", program);
        for (int i = 0; i < count1; i++) {
            if (is_value[i] == 1) {
                printf("%c=%s\n", value[i], num_value[i]);
            } else {
                printf("%c\n", value[i]);
            }
        }
    }
    return 0;
}

void Find_value(char *with_value, char *unwith_value, const char *rule) {
    int len_rule = strlen(rule);
    int with_count = 0;
    int unwith_count = 0;
    for (int i = 0; i < len_rule; i++) {
        if (rule[i] == ':' && i >= 1) {
            with_value[with_count] = rule[i - 1];
            with_count++;
        } else if (rule[i] != ':' && rule[i + 1] != ':') {
            unwith_value[unwith_count] = rule[i];
            unwith_count++;
        }
    }

}
//
// Created by asus on 2023/12/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
int if_compile_error = 0;
char *prt[4500] = {};

void Reserved(char str[], int count, char *prt1[]);

void Integer(char str[], int count, char *prt1[]);

void Float(char str[], int count, char *prt1[]);

void Operator(char str[], int count, char *prt1[]);

void Variable(char str[], int count, char *prt1[]);

int main() {
    char str[4500] = {};
    int count = 0;
    char fenhaoqian[4500] = {};
    char fenhaohou[4500] = {};
    int fenhao_num = 0;
    while ((scanf("%s", str)) != EOF) {
        //纯分号
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == ';') {
                prt[count] = ";";
                count++;
            } else {
                break;
            }
        }


        char *position = strchr(str, ';');
        if (position == NULL) {//无分号
            Reserved(str, count, prt);
            Integer(str, count, prt);
            Float(str, count, prt);
            Operator(str, count, prt);
            Variable(str, count, prt);
            count++;
            if ((flag1 == 0) && (flag2 == 0) && (flag3 == 0) && (flag4 == 0) && (flag5 == 0)) {
                if_compile_error = 1;
                break;
            }
            flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
            memset(str, '\0', 4500);
        } else {//有分号
            int len1 = strlen(str);
            int m = 0;//分号下标

            //分号前
            for (int i = 0; i < len1; i++) {
                if (str[i] == ';') {
                    m = i;
                    break;
                }
                fenhaoqian[i] = str[i];
            }
            int n = m;
            for (int i = n; i < strlen(str); i++) {
                if (str[i] == ';') {
                    prt[count] = ";";
                    count++;
                    m++;
                } else {
                    break;
                }
            }
            Reserved(fenhaoqian, count, prt);
            Integer(fenhaoqian, count, prt);
            Float(fenhaoqian, count, prt);
            Operator(fenhaoqian, count, prt);
            Variable(fenhaoqian, count, prt);
            count++;
            if ((flag1 == 0) && (flag2 == 0) && (flag3 == 0) && (flag4 == 0) && (flag5 == 0)) {
                if_compile_error = 1;
                break;
            }
            flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
            memset(fenhaoqian, '\0', 4500);

            //分号
            prt[count] = ";";
            count++;

            //分号后
            int j = 0;
            if (m == len1 - 1) {
                flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
                memset(str, '\0', 4500);
                memset(fenhaohou, '\0', 4500);
                continue;
            }
            if (m < len1 - 1) {
                for (int i = m + 1; i < len1; i++) {
                    fenhaohou[j] = str[i];
                    j++;
                }
            }
            Reserved(fenhaohou, count, prt);
            Integer(fenhaohou, count, prt);
            Float(fenhaohou, count, prt);
            Operator(fenhaohou, count, prt);
            Variable(fenhaohou, count, prt);
            count++;
            if ((flag1 == 0) && (flag2 == 0) && (flag3 == 0) && (flag4 == 0) && (flag5 == 0)) {
                if_compile_error = 1;
                break;
            }
            flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
            memset(str, '\0', 4500);
            memset(fenhaohou, '\0', 4500);
        }
    }
//输出
    if (if_compile_error == 1) {
        printf("Compile Error");
    } else {
        for (int i = 0; i < count; i++) {
            if (strcmp(prt[i], ";") == 0) {
                if (fenhao_num > 1) {
                    for (int j = 0; j < fenhao_num; j++) {
                        printf("\n");
                    }
                }
                printf("\n");
            } else {
                printf("%s ", prt[i]);
            }
        }

    }
    return 0;
}

void Reserved(char str[], int count, char *prt1[]) {
    if (strcmp(str, "const") == 0 || strcmp(str, "int") == 0 || strcmp(str, "float") == 0 ||
        strcmp(str, "double") == 0 || strcmp(str, "long") == 0 || strcmp(str, "static") == 0 ||
        strcmp(str, "void") == 0 || strcmp(str, "char") == 0 || strcmp(str, "extern") == 0 ||
        strcmp(str, "return") == 0 || strcmp(str, "break") == 0 || strcmp(str, "enum") == 0 ||
        strcmp(str, "struct") == 0 || strcmp(str, "typedef") == 0 || strcmp(str, "union") == 0 ||
        strcmp(str, "goto") == 0) {
        flag1 = 1;
        prt[count] = "reserved";
    }
}

void Integer(char str[], int count, char *prt1[]) {
    //用strtol函数
    char *endptr;
    //endptr是一个指针，指向转换后的字符串中第一个非数字字符的位置
    int num = strtol(str, &endptr, 10);
    //10表示十进制
    if (*endptr == '\0' && num >= 0) {
        flag2 = 1;
        prt[count] = "integer";
    }
}

void Float(char str[], int count, char *prt1[]) {
    //用strtod函数
    //isdigit函数用于判断一个字符是否是数字字符
    if (flag2 == 0) {
        char *endptr;
        double num = strtod(str, &endptr);
        if (*endptr == '\0' && num > 0) {
            flag3 = 1;
            prt[count] = "float";
        }
    }
}

void Operator(char str[], int count, char *prt1[]) {
    if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 ||
        strcmp(str, "/") == 0 || strcmp(str, "=") == 0 || strcmp(str, "==") == 0 ||
        strcmp(str, "!=") == 0 || strcmp(str, ">=") == 0 || strcmp(str, "<=") == 0 ||
        strcmp(str, ">") == 0 || strcmp(str, "<") == 0) {
        flag4 = 1;
        prt[count] = "operator";
    }
}

void Variable(char str[], int count, char *prt1[]) {
    if (flag1 == 0) {
        int len = strlen(str);
        int flag = 1;
        if (len == 0) {
            flag = 0;
        }
        if (!(isalpha(str[0]) || str[0] == '_')) {
            flag = 0;
        }
        for (int i = 1; i < len; i++) {
            if (!(isalpha(str[i]) || str[i] == '_')) {
                flag = 0;
            }
        }
        if (flag == 1) {
            flag5 = 1;
            prt[count] = "variable";
        }
    }
}
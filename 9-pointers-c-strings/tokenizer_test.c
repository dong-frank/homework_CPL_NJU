//
// Created by Frank on 2023/12/11.
//
//
// Created by Frank on 2023/12/7.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LEN1 16
#define LEN2 11
const char *reserved[LEN1] = {"const", "int", "float", "double", "long", "static",
                              "void", "char", "extern", "return", "break", "enum",
                              "struct", "typedef", "union", "goto"};
const char *operator[LEN2] = {"+", "-", "*", "/", "=", "==", "!=",
                              ">=", "<=", ">", "<"};
char *output[4200];
int count = 0;

bool Analysis(const char statement[]);

bool Reserver(const char statement[]);

bool Integer(const char statement[]);

bool Float(const char statement[]);

bool Operator(const char statement[]);

bool Variable(const char statement[]);

int main(void) {
    bool legal = true;
    char statement[4200] = {0};
    while ((scanf("%s", statement)) != EOF) {
        int len = strlen(statement);
        char *position = strchr(statement, ';');
        if (position == NULL) { // 没有分号
            if (!Analysis(statement)) {
                legal = false;
                break;
            }
        } else { //有分号
            if (len == 1) {
                output[count] = ";";
                count++;
            } else {
                char copy_statement[4200] = {0};
                strcpy(copy_statement, statement);
                char *sub_statement;
                sub_statement = strtok(statement, ";");
                int k = 0;
                int sub_len = 0;
                for (int j = k + sub_len; j < len; j++) {
                    if (copy_statement[j] == ';') {
                        output[count] = ";";
                        count++;
                    } else {
                        break;
                    }
                }
                while (sub_statement != NULL) {
                    k = sub_statement - statement;
                    sub_len = strlen(sub_statement);
                    if (!Analysis(sub_statement)) {
                        legal = false;
                        goto end;
                    } else {
                        for (int j = k + sub_len; j < len; j++) {
                            if (copy_statement[j] == ';') {
                                output[count] = ";";
                                count++;
                            } else {
                                break;
                            }
                        }
                    }
                    sub_statement = strtok(NULL, ";");
                }

            }
        }
        memset(statement, '\0', 4200);
    }
    end:
    if (!legal) {
        printf("Compile Error\n");
    } else {
        for (int i = 0; i < count; i++) {
            if (strcmp(output[i], ";") == 0) {
                printf("\n");
            } else {
                printf("%s ", output[i]);
            }
        }
    }
    return 0;
}

bool Analysis(const char statement[]) {
    //判断是不是保留字
    if (Reserver(statement)) {
        output[count] = "reserved";
        count++;
        return true;
    } else if (Integer(statement)) {
        output[count] = "integer";
        count++;
        return true;
    } else if (Float(statement)) {
        output[count] = "float";
        count++;
        return true;
    } else if (Operator(statement)) {
        output[count] = "operator";
        count++;
        return true;
    } else if (Variable(statement)) {
        output[count] = "variable";
        count++;
        return true;
    } else {
        return false;
    }
}

bool Reserver(const char statement[]) {
    for (int i = 0; i < LEN1; i++) {
        if (strcmp(statement, reserved[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool Integer(const char statement[]) {
    char *endptr;
    if (strtol(statement, &endptr, 10) >= 0 && *endptr == '\0') {
        return true;
    }
    return false;
}

bool Float(const char statement[]) {
    char *endptr;
    if (strtod(statement, &endptr) > 0 && *endptr == '\0') {
        return true;
    }
    return false;
}

bool Operator(const char statement[]) {
    for (int i = 0; i < LEN2; i++) {
        if (strcmp(statement, operator[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool Variable(const char statement[]) {
    bool flag = false;
    if (!Reserver(statement) && !Operator(statement)) {
        int len = strlen(statement);
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                if ((statement[i] >= 'A' && statement[i] <= 'Z') ||
                    (statement[i] >= 'a' && statement[i] <= 'z') || statement[i] == '_') {
                    flag = true;
                } else {
                    return false;
                }
            } else {
                if ((statement[i] >= 'A' && statement[i] <= 'Z')
                    || (statement[i] >= 'a' && statement[i] <= 'z') || statement[i] == '_' ||
                    (statement[i] >= '0' && statement[i] <= '9')) {
                    flag = true;
                } else {
                    return false;
                }
            }
        }
    }
    return flag;
}
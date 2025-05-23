//
// Created by guan on 2025/5/22.
//
#include "app_sprintf.h"

// 将整数转换为字符串，返回字符串的长度
int intToStr(int num, char* str) {
    int i = 0;
    int isNegative = 0;

    // 处理负数
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // 特殊情况：处理数字 0
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    // 处理个位数
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    // 如果是负数，添加负号
    if (isNegative) {
        str[i++] = '-';
    }

    // 因为数字是反向存储的，需要反转字符串
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    str[i] = '\0'; // 添加字符串结束符
    return i; // 返回字符串长度
}

// 自定义的类似 sprintf 函数，支持最多四个整数
void d_Sprintf(char* text, const char* format, int num1, int num2, int num3, int num4) {
    char temp[12]; // 临时缓冲区，足够存储一个整数的字符串表示
    int len;
    int numCount = 0; // 已处理的数字数量

    // 遍历格式字符串，逐字符处理
    while (*format) {
        if (*format == '%') {
            format++; // 跳过 '%'
            if (*format == 'd') {
                // 根据 numCount 确定要处理的数字
                int num = 0;
                switch (numCount) {
                    case 0: num = num1; break;
                    case 1: num = num2; break;
                    case 2: num = num3; break;
                    case 3: num = num4; break;
                }
                len = intToStr(num, temp); // 将整数转换为字符串
                for (int i = 0; i < len; i++) {
                    *text++ = temp[i]; // 将整数字符串复制到目标位置
                }
                numCount++; // 处理的数字数量加 1
            }
            format++; // 跳过 'd'
        } else {
            *text++ = *format++; // 复制普通字符
        }
    }
    *text = '\0'; // 添加字符串结束符
}

#include <stdint.h>

// 将浮点数转换为字符串，保留两位小数
int floatToStr(float num, char* str) {
    int integerPart = (int)num; // 获取整数部分
    float decimalPart = num - integerPart; // 获取小数部分
    int decimalPartInt = (int)(decimalPart * 100 + 0.5); // 小数部分乘以100并四舍五入

    // 特殊情况：处理整数部分为 0
    if (integerPart == 0) {
        str[0] = '0'; // 整数部分为 0
        int len = 1;
        str[len++] = '.'; // 添加小数点

        // 处理小数部分
        char temp[4]; // 临时缓冲区，足够存储两位小数
        intToStr(decimalPartInt, temp); // 将小数部分转换为字符串
        int tempLen = intToStr(decimalPartInt, temp);

        // 确保小数部分有两位
        if (tempLen == 1) {
            str[len++] = '0'; // 如果只有一位小数，补零
        }
        for (int i = 0; i < tempLen; i++) {
            str[len++] = temp[i];
        }

        str[len] = '\0'; // 添加字符串结束符
        return len; // 返回字符串长度
    } else {
        // 处理整数部分
        int len = intToStr(integerPart, str);

        // 添加小数点
        str[len++] = '.';

        // 处理小数部分
        char temp[4]; // 临时缓冲区，足够存储两位小数
        intToStr(decimalPartInt, temp); // 将小数部分转换为字符串
        int tempLen = intToStr(decimalPartInt, temp);

        // 确保小数部分有两位
        if (tempLen == 1) {
            str[len++] = '0'; // 如果只有一位小数，补零
        }
        for (int i = 0; i < tempLen; i++) {
            str[len++] = temp[i];
        }

        str[len] = '\0'; // 添加字符串结束符
        return len; // 返回字符串长度
    }
}

// 自定义的类似 sprintf 函数，支持最多四个 %f，保留两位小数
void f_Sprintf(char* text, const char* format, float num1, float num2, float num3, float num4) {
    char temp[10]; // 临时缓冲区，足够存储浮点数的字符串表示
    int len;
    int numCount = 0; // 已处理的数字数量

    // 遍历格式字符串，逐字符处理
    while (*format) {
        if (*format == '%') {
            format++; // 跳过 '%'
            if (*format == '%') {
                *text++ = '%'; // 如果是 '%%'，直接写入 '%'
                format++; // 跳过第二个 '%'
            } else if (*format == 'f') {
                // 根据 numCount 确定要处理的浮点数
                float num = 0.0f;
                switch (numCount) {
                case 0: num = num1; break;
                case 1: num = num2; break;
                case 2: num = num3; break;
                case 3: num = num4; break;
                }
                len = floatToStr(num, temp); // 将浮点数转换为字符串
                for (int i = 0; i < len; i++) {
                    *text++ = temp[i]; // 将浮点数字符串复制到目标位置
                }
                numCount++; // 处理的数字数量加 1
                format++; // 跳过 'f'
            } else {
                *text++ = *format++; // 如果是其他字符，直接复制
            }
        } else {
            *text++ = *format++; // 复制普通字符
        }
    }
    *text = '\0'; // 添加字符串结束符
}

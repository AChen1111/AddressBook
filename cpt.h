#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define FORMAT "%-10s%-15s%-20s%-30s\n" 
// 格式化输出
#define DATA contacts[i].name,contacts[i].phone,contacts[i].address,contacts[i].email
#define LEN sizeof(Contact)
//结构体长度

typedef struct Contact {
    char name[50];       // 姓名
    char phone[15];      // 电话
    char address[100];   // 地址
    char email[50];      // 电子邮箱
} Contact;
Contact contacts[100]; // 联系人数组
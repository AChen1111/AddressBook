#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define FORMAT "%-10s%-15s%-20s%-30s\n" 
// ��ʽ�����
#define DATA contacts[i].name,contacts[i].phone,contacts[i].address,contacts[i].email
#define LEN sizeof(Contact)
//�ṹ�峤��

typedef struct Contact {
    char name[50];       // ����
    char phone[15];      // �绰
    char address[100];   // ��ַ
    char email[50];      // ��������
} Contact;
Contact contacts[100]; // ��ϵ������
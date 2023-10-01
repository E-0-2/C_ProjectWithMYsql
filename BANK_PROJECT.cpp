#include <stdio.h>
#include <string.h>
#include <mysql.h>
#pragma warning(disable : 4996)
#pragma comment(lib, "libmysql.lib")

#define LOCALHOST "localhost"
#define USER    "root"
#define PASSWORD "1234"
#define DATABASENAME "bankam"
#define PORTNUMBER 3306



void menu();
int account_opening();
int input();
int output();
int all_check_page();
int money_check_page();
int end_part();
int Check_your_account();
int delete_user();

int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            account_opening();
            break;
        case 2:
            input();
            break;
        case 3:
            output();
            break;
        case 4:
            money_check_page();
            break;
        case 5:
            all_check_page();
            break;
        case 6:
            Check_your_account();
            break;
        case 7:
            delete_user();
            break;
        case 8:
            return 0;
            break;
        default:
            break;
        }
    }

}
void finish_with_error(MYSQL* con)

{

    fprintf(stderr, "%s \n", mysql_error(con));

    mysql_close(con);

    exit(1);

}

void menu() {
    printf("\n");
    printf("\t\t\t        HIMEDIA BANK \n");
    printf("\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t\t   Menu       \n");
    printf("\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\n");
    printf("\t\t      1.     �� ��      �� ��    \n");
    printf("\n");
    printf("\t\t      2.        ��   ��    \n");
    printf("\n");
    printf("\t\t      3.        ��   ��    \n");
    printf("\n");
    printf("\t\t      4.     �� ��      �� ȸ    \n");
    printf("\n");
    printf("\t\t      5.     ���    ȸ ��      �� ȸ    \n");
    printf("\n");
    printf("\t\t      6.     �� ��   �� ��      �� ȸ    \n");
    printf("\n");
    printf("\t\t      7.     ȸ ��      �� ��    \n");
    printf("\n");
    printf("\t\t      8.     ���α׷�  ����     \n");
    printf("\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t    �޴� ���� : ");
}
int account_opening() {
   


    MYSQL_RES* res;
    MYSQL_ROW row;

    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL)

    {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(con);
        return 1;
    }
    mysql_set_character_set(con, "euckr");

    char query[1000];
    int useraccnum;
    char username[100];
    char userssn[100];
    char userphone[100];
    char userpass[100];
    int userage;


    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t���ϴ� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t�̸� �Է����ּ��� : ");
    scanf("%s", username);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t�ֹε�Ϲ�ȣ *14�ڸ� (- ������) �ְ� �Է����ּ��� : ");
    scanf("%s", userssn);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t�ڵ��� ��ȣ *11�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%s", userphone);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t����Ͻ� ��й�ȣ  *4�ڸ� �Է����ּ��� : ");
    scanf("%s", userpass);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t������� ���̸� �Է����ּ��� : ");
    scanf("%d", &userage);



    snprintf(query, sizeof(query), "INSERT INTO membertbl(useraccnum,username,userssn,userphone,userpass,userage) VALUES (%d,'%s','%s','%s','%s',%d)", useraccnum, username, userssn, userphone, userpass, userage);

    if (mysql_query(con, query)) {
        printf("\t\t-----------------------------------------------------\n");
        fprintf(stderr, "\t\t������ ���� �Ͽ����ϴ�. %s\n", mysql_error(con));
    }
    else {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t������ �Ϸ� �Ǿ����ϴ�.\n");
    }

    mysql_close(con);

     

    }

int all_check_page() {

    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {

        fprintf(stderr, "mysql_init() failed \n");

        exit(1);

    }



    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL)

    {

        finish_with_error(con);

    }

    mysql_query(con, "set names euckr");



    if (mysql_query(con, "SELECT useraccnum,username,userage,userphone FROM membertbl"))

    {

        finish_with_error(con);

    }



 

    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL)

    {

        finish_with_error(con);

    }



   

    int num_fields = mysql_num_fields(result);



   

    MYSQL_ROW row;
    
    printf("\n\n\n");
    printf("\t\t\t\t���� ���� ��ȸ\n\n\n");
    printf("\t��-����------------�̸�-----------����--------------�޴���----------��\n");
    while (row = mysql_fetch_row(result))

    {
        
        for (int i = 0; i < num_fields; i++)

        {
            
            printf("          %s ", row[i]);

        }
        printf("\n\t��------------------------------------------------------------------��\n");
    }
    printf("\n\n\n\n");

    mysql_free_result(result);

    mysql_close(con);
    
}
int input() {


    MYSQL_RES* res;
    MYSQL_ROW row;

    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL)

    {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(con);
        return 1;
    }
    mysql_set_character_set(con, "euckr");

    char query[1000];
    int useraccnum;
    int inputmoney;
    int outputmoney = 0;

    
 
    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t���� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t�Ա��� �ݾ��� �Է����ּ��� : ");
    scanf("%d", &inputmoney);

    if (inputmoney <= 0) {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t�Ա��� �ݾ��� 0���� Ŀ�� �մϴ�.\n");
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }

    snprintf(query, sizeof(query), "INSERT INTO membermoneytbl (num,useraccnum,inputmoney,outputmoney,date)  VALUES (null,%d,%d,%d,now())", useraccnum, inputmoney, outputmoney);

    if (mysql_query(con, query)) {
        printf("\t\t-----------------------------------------------------\n");
        fprintf(stderr, "\t\t�Ա��� ���� �Ͽ����ϴ�. %s\n", mysql_error(con));
    }
    else {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t%d�� �ԱݿϷ� �Ǿ����ϴ�.\n", inputmoney);
    }

     
}

int output() {
    MYSQL_RES* res;
    MYSQL_ROW row;

    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(con);
        return 1;
    }
    mysql_set_character_set(con, "euckr");

    char query[1000];
    int useraccnum;
    int inputmoney = 0;
    int outputmoney;

    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t���� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t����� �ݾ��� �Է����ּ��� : ");
    scanf("%d", &outputmoney);

    if (outputmoney <= 0) {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t����� �ݾ��� 0���� Ŀ�� �մϴ�.\n");
        mysql_close(con); // ���� ����
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }

    // ��� ���� ���� Ȯ��
    snprintf(query, sizeof(query), "SELECT SUM(inputmoney - outputmoney) AS balance FROM membermoneytbl WHERE useraccnum = %d", useraccnum);

    if (mysql_query(con, query)) {
        printf("\t\t-----------------------------------------------------\n");
        fprintf(stderr, "\t\t�ܾ� ��ȸ ����: %s\n", mysql_error(con));
        mysql_close(con); // ���� ����
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }

    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL) {
        fprintf(stderr, "\t\t�ܾ� ��ȸ ��� �������� ����\n");
        mysql_close(con); // ���� ����
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }

    row = mysql_fetch_row(result);

    int balance = atoi(row[0]);
    mysql_free_result(result); // ��� �޸� ����

    if (outputmoney > balance) {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t�ܾ��� �����մϴ�. ����� �� �����ϴ�.\n");
        mysql_close(con); // ���� ����
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }

    // ��� ���� ����
    snprintf(query, sizeof(query), "INSERT INTO membermoneytbl (num, useraccnum, inputmoney, outputmoney, date) VALUES (null, %d, 0, %d, now())", useraccnum, outputmoney);

    if (mysql_query(con, query)) {
        printf("\t\t-----------------------------------------------------\n");
        fprintf(stderr, "\t\t����� ���� �Ͽ����ϴ�. %s\n", mysql_error(con));
        mysql_close(con); // ���� ����
        return 0; // �Է� ���и� ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }
    else {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t%d���� ��� �Ϸ�Ǿ����ϴ�.\n", outputmoney);
        mysql_close(con); // ���� ����
        return 1; // �Է� ������ ��Ÿ���� �� �Ǵ� �ڵ带 ��ȯ
    }
    
}


int money_check_page(){
    char query[1000];
    int useraccnum;
    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {

        fprintf(stderr, "mysql_init() failed \n");

        exit(1);

    }



    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL)

    {

        finish_with_error(con);

    }

    

    mysql_query(con, "set names euckr");

    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t���� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);

    snprintf(query, sizeof(query), "select useraccnum,sum(inputmoney-outputmoney) from membermoneytbl where useraccnum = '%d'",useraccnum);

    if (mysql_query(con, query)) {
        printf("\t\t-----------------------------------------------------\n");
        fprintf(stderr, "\t\t�ܾ� ��ȸ ���� :  %s\n", mysql_error(con));
    }
    else {
        printf("\t\t-----------------------------------------------------\n");
        printf("\t\t�ܾ� ��ȸ ����\n");
    }



    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL)

    {

        finish_with_error(con);

    }





    int num_fields = mysql_num_fields(result);





    MYSQL_ROW row;

    printf("\n\n\n");
    printf("\t\t\t\t�ܾ� ���� ��ȸ\n\n\n");
    printf("\t\t\t��-����------------------------�ܾ�---��\n");
    while (row = mysql_fetch_row(result))

    {

        for (int i = 0; i < num_fields; i++)

        {

            printf("\t\t          %s ", row[i]);

        }
        printf("\n\t\t\t��------------------------------------��\n");
    }
    printf("\n\n\n\n");

    mysql_free_result(result);

    mysql_close(con);
    
}
int Check_your_account() {
    char query[1000];
    int useraccnum;

    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {

        fprintf(stderr, "mysql_init() failed \n");

        exit(1);

    }



    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL)

    {

        finish_with_error(con);

    }

    mysql_query(con, "set names euckr");

    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t���� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);

    snprintf(query, sizeof(query), "SELECT useraccnum,username,userage,userphone FROM membertbl where useraccnum = '%d'", useraccnum);

    if (mysql_query(con, query))

    {

        finish_with_error(con);

    }





    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL)

    {

        finish_with_error(con);

    }





    int num_fields = mysql_num_fields(result);





    MYSQL_ROW row;

    printf("\n\n\n");
    printf("\t\t\t\t���� ���� ��ȸ\n\n\n");
    printf("\t��-����------------�̸�-----------����--------------�޴���----------��\n");
    while (row = mysql_fetch_row(result))

    {

        for (int i = 0; i < num_fields; i++)

        {

            printf("          %s ", row[i]);

        }
        printf("\n\t��------------------------------------------------------------------��\n");
    }
    printf("\n\n\n\n");

    mysql_free_result(result);

    mysql_close(con);
    
}
int delete_user() {
    char query[1000];
    int useraccnum;
    MYSQL* con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, LOCALHOST, USER, PASSWORD, DATABASENAME, PORTNUMBER, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    mysql_query(con, "set names euckr");

    printf("\n\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t������ ������� ���� ��ȣ  *5�ڸ� (- ������) ���� �Է����ּ��� : ");
    scanf("%d", &useraccnum);

    // ���� membermoneytbl ���̺��� ����ڿ� ���õ� ��� ������ ����
    snprintf(query, sizeof(query), "DELETE FROM membermoneytbl WHERE useraccnum = %d", useraccnum);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    // ���� membertbl ���̺��� ����� ����
    snprintf(query, sizeof(query), "DELETE FROM membertbl WHERE useraccnum = %d", useraccnum);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t����� ������ �����Ǿ����ϴ�.\n");

    mysql_close(con);

    
}


//
// Created by joao.martins on 6/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CONTACTS 5
#define CHARS_NAME 255
#define CHARS_PHONE 50

unsigned int GlobalCode = 1;

typedef enum _bool {
    false,
    true
} bool;

typedef struct _contact {
   unsigned int Code;
   char Name[CHARS_NAME];
   char PhoneNumber[CHARS_PHONE];
   char Email[CHARS_NAME];
} Contact;

typedef struct _contats{
    unsigned int Count;
    Contact *MyContacts[MAX_CONTACTS];
} Contacts;

Contact * NewContact(char *Name, char *PhoneNumber, char *Email);
int ShowMenu();
void HandleMenuOption(int menuOption, Contacts *myContacts);
void HandleInsertContactInList(Contacts *myContacts);
void ShowMyContactList(Contacts *myContacts);
Contacts * InitializeContactList();

int main(){
    setlocale(LC_ALL, "Portuguese");

    Contacts *myContacts = InitializeContactList();

    while(true){
        int menuOption = ShowMenu();

        if(menuOption == 0)
            return menuOption;

        HandleMenuOption(menuOption, myContacts);
    }

    return 0;
}

void HandleInsertContactInList(Contacts *myContacts) {
    char Name[CHARS_NAME];
    char PhoneNumber[CHARS_PHONE];
    char Email[CHARS_NAME];

    printf("==========================\n");
    printf("=\t Novo Cadastro\t==\n");
    printf("==========================\n");
    fflush(stdin);

    printf("Nome: ");
    gets(&Name);
    fflush(stdin);
    printf("\n");

    printf("Telefone: ");
    gets(&PhoneNumber);
    fflush(stdin);
    printf("\n");

    printf("E-mail: ");
    gets(&Email);
    fflush(stdin);
    printf("\n");

    myContacts->MyContacts[myContacts->Count] = NewContact(Name, PhoneNumber, Email);
    myContacts->Count++;

    printf("=\t Novo Cadastro criado com sucesso\t==\n");
    system("pause");
    system("cls");
}

void ShowMyContactList(Contacts *myContacts) {
    printf("==============================================\n");
    for(int i = 0; i < myContacts->Count; i++){
        printf("\t Código: %d\n", myContacts->MyContacts[i]->Code);
        printf("\t Nome: %s\n", myContacts->MyContacts[i]->Name);
        printf("\t Telefone: %s\n", myContacts->MyContacts[i]->PhoneNumber);
        printf("\t E-mail: %s\n", myContacts->MyContacts[i]->Email);
        printf("==============================================\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

int ShowMenu(){
    int menuOption = 1;

    while(true)
    {
        printf("=================================\n");
        printf("=\t1 - Novo Cadastro\t=\n");
        printf("=\t2 - Listar Cadastros\t=\n");
        printf("=\t0 - Finalizar Programa\t=\n");
        printf("=================================\n");
        printf("\tOpção: ");
        scanf("%d", &menuOption);
        system("cls");

        switch(menuOption){
            case 1:
            case 2:
            case 0:
                return menuOption;
            default:
                printf("Erro: opção inválida!\n");
                system("pause");
                system("cls");
        }
    }
}

void HandleMenuOption(int menuOption, Contacts *myContacts){
    switch(menuOption){
        case 1:
            if(myContacts->Count < 5){
                HandleInsertContactInList(myContacts);
            }else{
                printf("Agenda lotada!\n");
                system("pause");
            }
        break;

        case 2:
            if(myContacts->Count == 0){
                printf("Agenda vazia!\n");
                system("pause");
            }else {
                ShowMyContactList(myContacts);
            }
        break;
    }

    system("cls");
}

Contacts * InitializeContactList(){
    Contacts *myContacts = (Contacts*) malloc(sizeof(Contacts));

    myContacts->Count = 0;

    return myContacts;
}

Contact * NewContact(char *Name, char *PhoneNumber, char *Email) {
    Contact *newContact = (Contact*) malloc(sizeof(Contact));

    newContact->Code = GlobalCode++;
    strcpy(newContact->Name, Name);
    strcpy(newContact->PhoneNumber, PhoneNumber);
    strcpy(newContact->Email, Email);

    return newContact;
}

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Número máximo de registros que podem ser armazenados
#define MAX_LENGTH 100 // Número máximo de nome e email que podem ser armazenados

// Estrutura para armazenar um registro
typedef struct {
    int id;
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
} Record;

// Array para armazenar os registros
Record database[MAX_RECORDS];
int record_count = 0;

// Função para criar um novo registro
void create_record(int id, const char* name, const char* email) {
    if (record_count < MAX_RECORDS) {
        database[record_count].id = id;
        strcpy(database[record_count].name, name);
        strcpy(database[record_count].email, email);
        record_count++; // Incrementa o contador de registros
        printf("Registro criado com sucesso!\n");
    } else {
        printf("Erro: O banco de dados está cheio.\n");
    }
}

// Função para ler registros
void read_records() {
    if (record_count == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    printf("Registros:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Nome: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

// Função para atualizar um registro
void update_record(int id, const char* new_name, const char* new_email) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            strcpy(database[i].name, new_name);
            strcpy(database[i].email, new_email);
            printf("Registro atualizado com sucesso!\n");
            return; // Sai da função após a atualização
        }
    }
    printf("Erro: Registro não encontrado.\n");
}

// Função para excluir um registro
void delete_record(int id) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            for (int j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1];
            }
            record_count--;
            printf("Registro excluído com sucesso!\n");
            return;
        }
    }
    printf("Erro: Registro não encontrado.\n");
}

// Função principal
int main() {
    int choice, id;
    char name[MAX_LENGTH], email[MAX_LENGTH];

    while (1) {
        printf("\nSistema de Gerenciamento de Banco de Dados\n");
        printf("1. Criar Registro\n");
        printf("2. Ler Registros\n");
        printf("3. Atualizar Registro\n");
        printf("4. Excluir Registro\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite ID: ");
                scanf("%d", &id);
                printf("Digite Nome: ");
                scanf("%s", name);
                printf("Digite Email: ");
                scanf("%s", email);
                create_record(id, name, email);
                break;
            case 2:
                read_records();
                break;
            case 3:
                printf("Digite ID do registro a ser atualizado: ");
                scanf("%d", &id);
                printf("Digite Novo Nome: ");
                scanf("%s", name);
                printf("Digite Novo Email: ");
                scanf("%s", email);
                update_record(id, name, email);
                break;
            case 4:
                printf("Digite ID do registro a ser excluído: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

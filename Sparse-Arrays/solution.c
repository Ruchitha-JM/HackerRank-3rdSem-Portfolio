
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

#define TABLE_SIZE 100003

typedef struct Node {
    char* key;
    int count;
    struct Node* next;
} Node;

unsigned long hashString(const char* str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

void insertString(Node** table, const char* str)
{
    unsigned long index = hashString(str);

    Node* current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->key, str) == 0)
        {
            current->count++;
            return;
        }

        current = current->next;
    }

    Node* newNode = malloc(sizeof(Node));

    newNode->key = malloc(strlen(str) + 1);
    strcpy(newNode->key, str);

    newNode->count = 1;
    newNode->next = table[index];

    table[index] = newNode;
}

int getCount(Node** table, const char* str)
{
    unsigned long index = hashString(str);

    Node* current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->key, str) == 0)
        {
            return current->count;
        }

        current = current->next;
    }

    return 0;
}

void freeTable(Node** table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* current = table[i];

        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;

            free(temp->key);
            free(temp);
        }
    }

    free(table);
}

int* matchingStrings(int strings_count, char** strings,
                     int queries_count, char** queries,
                     int* result_count)
{
    Node** table = calloc(TABLE_SIZE, sizeof(Node*));

    for (int i = 0; i < strings_count; i++)
    {
        insertString(table, strings[i]);
    }

    int* result = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++)
    {
        result[i] = getCount(table, queries[i]);
    }

    *result_count = queries_count;

    freeTable(table);

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int strings_count = atoi(readline());

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++)
    {
        strings[i] = readline();
    }

    int queries_count = atoi(readline());

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++)
    {
        queries[i] = readline();
    }

    int result_count;

    int* result = matchingStrings(
        strings_count,
        strings,
        queries_count,
        queries,
        &result_count
    );

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", result[i]);

        if (i != result_count - 1)
        {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    for (int i = 0; i < strings_count; i++)
    {
        free(strings[i]);
    }

    for (int i = 0; i < queries_count; i++)
    {
        free(queries[i]);
    }

    free(strings);
    free(queries);
    free(result);

    return 0;
}

char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true)
    {
        char* cursor = data + data_length;

        char* line = fgets(
            cursor,
            alloc_length - data_length,
            stdin
        );

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 ||
            data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length *= 2;

        data = realloc(data, alloc_length);

        if (!data)
        {
            return NULL;
        }
    }

    if (data_length > 0 &&
        data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
    }

    return data;
}

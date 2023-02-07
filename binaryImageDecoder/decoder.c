//Create a simple binary image decoder. This is a program that will read commands from a file and compute results that look like pictures.
//The first line of this file is the decoding key. Load that in first.
//For each line, decode as follows, assuming i is the line number: decodedi = (encodedi xor key) rol i
//The command rol means rotate left i bits. Push the decoded line onto the stack.
//When done processing the commands, the stack is printed out in order (top first) with every 0 replaced by a space and every 1 replaced by an 'X'.

//The input file is a text file with the following format:
/*
01010100011000
01011011101000
01001011100110
11001011100111
10101011111111
10101011100111
00101011111110
10101101100111
10110000111111
01000110001010
01010001010010
01010101111110
*/

//The output of that example should be:
/*
 XX        XX 
 X X      X X 
 X  X    X  X 
 X  XXXXXX  X 
 XXXXXXXXXXXX 
XXXX  XX  XXXX
XXXXXXXXXXXXXX
XXXXXX  XXXXXX
 XXXXXXXXXXXX 
  XXXXXXXXXX  
    XXXXXX     
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001

typedef struct LinkedListNode
{
    char *name;

    struct LinkedListNode *next;

} LinkedListNode;

/* a structure that represents a linked list */
typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;

} LinkedList;

void push(LinkedList *list, const char *name)
{
    LinkedListNode *node = (LinkedListNode *)calloc(1, sizeof(LinkedListNode));
    node->next = NULL;

    node->name = (char *)calloc(strlen(name) + 1, sizeof(char));
    strncpy(node->name, name, strlen(name));

    if (list->head == NULL)
    {
        /* if the list is empty */
        list->head = node;
        list->tail = node;
    }
    else
    {
        /* push to the head of the list to reverse the order of the lines */
        node->next = list->head;
        list->head = node;
    }
}

/**
 * Free the memory allocated for our list
 * @param list Pointer to linked list object
 */
void free_list(LinkedList *list)
{
    LinkedListNode *node;

    for (node = list->head; node != NULL;  )
    {
        LinkedListNode *next = node->next;

        free(node->name);
        free(node);

        node = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

void rotate(char *line, int num)
{
    if (num == 0)
    {
        return;
    }

    int completed = 0;
    while (completed < num)
    {
        char temp = line[0];
        int i = 0;
        while (line[i] != '\0')
        {
            line[i] = line[i + 1];
            i++;
        }
        line[i - 1] = temp;
        completed++;
    }
}

void xor_fn(char *line, char *key)
{
    int i = 0;
    while(line[i] != '\0')
    {
        if(line[i]==key[i])
        {
            line[i] = '0';
        }
        else
        {
            line[i] = '1';
        }
        i++;
    }
}

void convert(char *line)
{
    int i = 0;
    while(line[i] != '\0')
    {
        if(line[i] == '0')
        {
            line[i] = ' ';
        }
        else
        {
            line[i] = 'X';
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: decoder file\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Unable to open input file\n");
        return 1;
    }

    char line[MAX_SIZE];
    char key[MAX_SIZE];
    fgets(key, MAX_SIZE, fp);

    LinkedList list;
    int rotations = 0;

    while(fgets(line, MAX_SIZE, fp))
    {
        /* remove the newline character and exchange it with a null termination */
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }
        xor_fn(line, key);
        rotate(line, rotations);
        convert(line);
        push(&list, line);
        rotations++;
    }

    /* print the linked list from head to tail, with a new line at the end of each line */
    LinkedListNode *node;
    for (node = list.head; node != NULL; node = node->next)
    {
        printf("%s", node->name);
        printf("\n");
    }

    /* free the memory from the linked list and close the file */
    free_list(&list);
    fclose(fp);

    return 0;
}

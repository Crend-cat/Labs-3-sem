#include "head3.10.h"

void Init_tree(Node *root)
{
    root->brother = NULL;
    root->prev = NULL;
    root->son = NULL;
}

enum Errors Build_tree(FILE *input, FILE *output)
{
    char c;
    Node *temp, *root;
    root = (Node *)malloc(sizeof(Node));

    if (!root)
        return INVALID_MEMORY;

    Init_tree(root);
    temp = root;

    while ((c = getc(input))){

        if (c == EOF)
        {
            Print_tree(root, 0, output);
            break;
        }

        if(c == '\r') continue;

        if (c == '\n')
        {
            Print_tree(root, 0, output);
            fprintf(output, "\n");
            Delete_tree(root);

            root = (Node *)malloc(sizeof(Node));
            if (!root)
                return INVALID_MEMORY;
            Init_tree(root);
            temp = root;
        }
        else if (isspace(c))
            continue;
        else if (c == '(') // сын
        {
            temp->son = (Node *)malloc(sizeof(Node));
            if (!temp->son)
            {
                Delete_tree(root);
                return INVALID_MEMORY;
            }
            temp->son->prev = temp;
            temp = temp->son;
            temp->brother = NULL;
            temp->son = NULL;
        }
        else if (c == ')') // к родителю
        {
            temp = temp->prev;
        }
        else if (c == ',') // брат
        {
            temp->brother = (Node *)malloc(sizeof(Node));
            if (!temp->brother)
            {
                Delete_tree(root);
                return INVALID_MEMORY;
            }
            temp->brother->prev = temp->prev;
            temp = temp->brother;
            temp->son = NULL;
            temp->brother = NULL;
        }
        else
        {
            temp->data = c;
        }
    }
    Delete_tree(root);
    return OK;
}

void Print_tree(Node *root, int level, FILE *output)
{
    if (!root)
        return;
    for (int i = 0; i < level; i++)
    {
        fprintf(output, "  ");
    }
    fprintf(output, "%c\n", root->data);
    if (root->son)
        Print_tree(root->son, level + 1, output);
    if (root->brother)
        Print_tree(root->brother, level, output);
}

void Delete_tree(Node *root)
{
    if (root->brother)
        Delete_tree(root->brother);
    if (root->son)
        Delete_tree(root->son);

    free(root);
}


enum Errors Validate_input(int argc, char **argv){

    char in[BUFSIZ], out[BUFSIZ];
    if (argc != 3)
        return INVALID_INPUT;

    if (!realpath(argv[1], in) || !realpath(argv[2], out))
        return INVALID_INPUT;
    if (!strcmp(in, out))
        return INVALID_INPUT;
    return OK;
}
//Nos permitirá acceder a
//la estructura nodo y lista

#ifndef lista_h
#define lista_h

#include <iostream>
#include "libro.hpp"

typedef struct Node
{
    Book book;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    int quantity;
} List;

Node *CreateNode(Book *book)
{
    Node *node = new Node;
    (*node).book = (*book);
    (*node).next = NULL;
    return node;
}

void DestroyNode(Node *node)
{
    delete node;
}

void InsertToStart(List *list, Book *book)
{
    Node *node = CreateNode(book);
    (*node).next = (*list).head;
    (*list).head = node;
    (*list).quantity++;
}

void InsertToEnd(List *list, Book *book)
{
    Node *node = CreateNode(book);
    Node *aux = (*list).head;

    if ((*list).head == NULL)
    {
        (*list).head = node;
    }

    while ((*aux).next)
    {
        aux = (*aux).next;
    }

    (*aux).next = node;
    (*list).quantity++;
}

void InsertBefore(int n, List *list, Book *book)
{
    Node *node = CreateNode(book);

    if ((*list).head == NULL)
    {
        (*list).head == node;
    }
    else
    {
        Node *aux = (*list).head;
        int position = 0;

        while (position < n && (*aux).next)
        {
            aux = (*aux).next;
            position++;
        }

        (*node).next = (*aux).next;
        (*aux).next = node;
    }
    (*list).quantity++;
}

Book *getBook(int n, List *list)
{
    if ((*list).head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *aux = (*list).head;
        int position = 0;

        while (position < n && (*aux).next)
        {
            aux = (*aux).next;
            position++;
        }

        if (position != n)
            return NULL;

        return &(*aux).book;
    }
}

int Count(List *list)
{
    return (*list).quantity;
}

void DeleteFirstElement(List *list)
{
    if ((*list).head)
    {
        Node *deleted = (*list).head;
        (*list).head = (*(*list).head).next;
        DestroyNode(deleted);
        (*list).quantity--;
    }
}

void DeleteLastElement(List *list)
{
    if ((*list).head)
    {
        if ((*(*list).head).next)
        {
            Node *aux = (*list).head;

            while ((*(*aux).next).next)
            {
                aux = (*aux).next;
            }

            Node *deleted = (*aux).next;
            (*aux).next = NULL;
            DestroyNode(deleted);
            (*list).quantity--;
        }
        else
        {
            Node *deleted = (*list).head;
            (*list).head = NULL;
            DestroyNode(deleted);
            (*list).quantity--;
        }
    }
}

void DeleteELementN(int n, List *list)
{
    if ((*list).head)
    {
        if (n == 0)
        {
            DeleteFirstElement(list);
        }
        else if (n < (*list).quantity)
        {
            Node *aux = (*list).head;
            int position = 0;
            while (position < (n - 1))
            {
                aux = (*aux).next;
                position++;
            }

            Node *deleted = (*aux).next;
            (*aux).next = (*deleted).next;
            DestroyNode(deleted);
            (*list).quantity--;
        }
    }
}

#endif /* lista_h */
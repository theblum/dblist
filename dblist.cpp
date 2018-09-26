/* ===========================================================================
 * File: dblist.cpp
 * Date: 26 Sep 2018
 * Creator: Brian Blumberg <blum@disroot.org>
 * Notice:
 * ===========================================================================
 */

// <26 Sep 2018> @Warning: This code has not been thoroughly tested. This should be used for
// reference only. USE AT YOUR OWN RISK!

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    Node *Next;
    Node *Prev;
};

void
PrintList(Node *Head)
{
    while(Head) {
        printf("%d ", Head->Data);
        Head = Head->Next;
    }
}

void
AddStart(Node **Head, int Data)
{
    Node *NewHead = (Node *)malloc(sizeof(Node));

    NewHead->Data = Data;
    NewHead->Next = *Head;
    NewHead->Prev = 0;

    if(*Head) (*Head)->Prev = NewHead;

    *Head = NewHead;
}

void
AddEnd(Node **Head, int Data)
{
    Node *NewEnd = (Node *)malloc(sizeof(Node));

    NewEnd->Data = Data;
    NewEnd->Next = 0;

    Node *End = *Head;
    if(End) {
        while(End->Next) End = End->Next;
        End->Next = NewEnd;
    } else {
        *Head = NewEnd;
    }

    NewEnd->Prev = End;
}

// <26 Sep 2018> @Note: If you try to add a node past the end of the list, this will just add the
// new node to the end of the list.
void
AddAt(Node **Head, int Pos, int Data)
{
    Node *OldNode = *Head;
    while(Pos-- && OldNode) OldNode = OldNode->Next;
    if(OldNode) {
        if(OldNode->Prev) {
            Node *NewNode = (Node *)malloc(sizeof(Node));
            NewNode->Data = Data;
            NewNode->Prev = OldNode->Prev;
            NewNode->Next = OldNode;
            NewNode->Prev->Next = NewNode;
            OldNode->Prev = NewNode;
        } else {
            AddStart(Head, Data);
        }
    } else {
        AddEnd(Head, Data);
    }
}

void
FreeList(Node *Head)
{
    while(Head) {
        Node *Next = Head->Next;
        free(Head);
        Head = Next;
    }
}

int
main(int Argc, char **Argv)
{
    Node *Head = 0;
    AddStart(&Head, 1);
    AddStart(&Head, 5);

    PrintList(Head);
    printf("\n");

    AddEnd(&Head, 9);
    AddEnd(&Head, 8);

    PrintList(Head);
    printf("\n");

    AddAt(&Head, 1, 7);
    AddAt(&Head, 0, 2);
    AddAt(&Head, 9, 3);

    PrintList(Head);
    printf("\n");

    FreeList(Head);

    return 0;
}

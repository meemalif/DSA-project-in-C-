#include <iostream>
#include <string>
#pragma once

using namespace std;

struct node
{
    string data[3];
    node *next;
};

node *head;
node *GetNewNode(string fifaid, string name, string shirtNumber)
{
    node *newNode = new node();
    newNode->data[0] = fifaid;
    newNode->data[1] = name;
    newNode->data[2] = shirtNumber;

    newNode->next = NULL;

    return newNode;
}

void *createRow(string fifaid, string name, string shirtNumber)
{
    if (head == NULL)
    {
        head = GetNewNode(fifaid, name, shirtNumber);
        return head;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = GetNewNode(fifaid, name, shirtNumber);
        return temp;
    }
}

int searchidbyname(node *temp, string name)
{
    if (temp == NULL)
    {
        return 0;
    }
    if ((temp->data[1].find(name)) < 100)
        return stoi(temp->data[0]);
    else
        return searchidbyname(temp->next, name);
}

void printPlayerNamesByShirt(node *temp, string jersey)
{
    if (temp->next == NULL)
    {
        return;
    }
    if (temp->data[2] == jersey)
    {
        cout << "Player's name:   " << temp->data[1] << "\n";
        cout << "Player's FIFA id:   " << temp->data[0] << "\n";
        cout << "Player's Jersey Number:   " << temp->data[2] << "\n";
        printPlayerNamesByShirt(temp->next, jersey);
    }
    else
    {
        printPlayerNamesByShirt(temp->next, jersey);
    }
}

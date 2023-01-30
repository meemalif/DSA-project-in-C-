#include <iostream>
#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include "avlTree.h"
#include "linkedList.h"
using namespace std;

TreeNode *root;
AVLTree obj;

void parser()
{
    head = NULL;

    ifstream inputfile;
    inputfile.open("players_20.csv");
    string line = "";

    while (getline(inputfile, line))
    {
        string sfifaID;
        string fifaID;
        string name;
        string age;
        string teamJersey;
        string club;
        string dob;
        string url;
        string nationality;
        string awards;
        string contactYear;
        string teamPosition;
        string height;
        string skills;
        string line1;
        stringstream inputString(line);

        getline(inputString, fifaID, ',');

        getline(inputString, name, ',');
        getline(inputString, age, ',');
        getline(inputString, teamJersey, ',');
        getline(inputString, club, ',');
        getline(inputString, dob, ',');
        getline(inputString, url, ',');
        getline(inputString, line1, ',');
        // inputString.ignore(numeric_limits<streamsize>::max(), ',');

        getline(inputString, nationality, ',');
        getline(inputString, awards, ',');
        // inputString.ignore(numeric_limits<streamsize>::max(), ',');
        getline(inputString, line1, ',');

        getline(inputString, contactYear, ',');
        getline(inputString, teamPosition, ',');
        getline(inputString, line1, ',');
        getline(inputString, line1, ',');

        // inputString.ignore(numeric_limits<streamsize>::max(), ',');
        // inputString.ignore(numeric_limits<streamsize>::max(), ',');
        getline(inputString, height, ',');
        getline(inputString, line1, ',');
        getline(inputString, line1, ',');

        // inputString.ignore(numeric_limits<streamsize>::max(), ',');
        // inputString.ignore(numeric_limits<streamsize>::max(), ',');
        getline(inputString, skills, ',');

        TreeNode *new_node = new TreeNode(fifaID, name, age, teamJersey, club, dob, url, nationality, awards, contactYear, teamPosition, height, skills);
        obj.root = obj.insert(obj.root, new_node);
        createRow(fifaID, name, teamJersey);
        line = "";
    }
}
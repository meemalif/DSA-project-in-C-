#include <iostream>
#include "parser.h"
#include "linkedList.h"
#include <stdlib.h>
// #include <windows.h>

using namespace std;
int main()
{
    // node *temp1 = head;
    int option;
    TreeNode *temp = obj.root;
    // node *temp1 = head;
    parser();

    do
    {
        cout << "what operations do you want to perform? enter 0 to exit" << endl;
        cout << "1. search player by id 0(logn)" << endl;
        cout << "2. search player by name o(n+logn) " << endl;
        cout << "3. Open player's website in Chrome" << endl;
        cout << "4. print players by level" << endl;
        cout << "5. check teammeates." << endl;
        cout << "6. Print players with same Jersey Number" << endl;
        cout << "7. InOrder, preOrder and PostOrder printing" << endl;
        cout << "8. print all neighbors of a vertex" << endl;
        cout << "0. exit program" << endl;
        cin >> option;
        if (option == 1)
        {
            cout << "enter the player id you want to seacrh \n";
            int player;
            cin >> player;
            temp = obj.recursiveSearch(obj.root, player);
            if (temp != nullptr)
            {
                cout << "Players full name:\t" << temp->value[1] << endl;
                cout << "Age:\t" << temp->value[2] << endl;
                cout << "Team jersey: \t" << temp->value[3] << endl;
                cout << "Club:\t" << temp->value[4] << endl;
                cout << "Date of birth:\t" << temp->value[5] << endl;
                cout << "Players URL:\t" << temp->value[6] << endl;
                cout << "Nationality:\t" << temp->value[7] << endl;
                cout << "International awards:\t" << temp->value[8] << endl;
                cout << "Contact year:\t" << temp->value[9] << endl;
                cout << "Team Position:\t" << temp->value[10] << endl;
                cout << "Height:\t" << temp->value[11] << endl;
                cout << "Skills:\t" << temp->value[12] << endl;
            }
        }
        else if (option == 2)
        {
            cout << "enter the players name you want to check";
            string player;
            cin >> player;
            player[0] = toupper(player[0]);
            int id = searchidbyname(head, player);
            if (id != 0)
            {
                temp = obj.recursiveSearch(obj.root, id);
            }
            else
                cout << "players don't exist";
            if (temp != nullptr)
            {
                cout << "Players full name:\t" << temp->value[1] << endl;
                cout << "Age:\t" << temp->value[2] << endl;
                cout << "Team jersey: \t" << temp->value[3] << endl;
                cout << "Club:\t" << temp->value[4] << endl;
                cout << "Date of birth:\t" << temp->value[5] << endl;
                cout << "Players URL:\t" << temp->value[6] << endl;
                cout << "Nationality:\t" << temp->value[7] << endl;
                cout << "International awards:\t" << temp->value[8] << endl;
                cout << "Contact year:\t" << temp->value[9] << endl;
                cout << "Team Position:\t" << temp->value[10] << endl;
                cout << "Height:\t" << temp->value[11] << endl;
                cout << "Skills:\t" << temp->value[12] << endl;
            }
        }
        else if (option == 3)
        {
            cout << "Enter the Players Name: \n";
            string player;
            cin >> player;
            player[0] = toupper(player[0]);
            int id = searchidbyname(head, player);
            temp = obj.recursiveSearch(obj.root, id);
            string url = temp->value[6];
            cout << "URL of the player is " << url << endl;
            system(("start " + url).c_str());
        }
        else if (option == 4)
        {
            int level;
            cout << "enter the level in AVL tree which you want to search";
            cin >> level;
            obj.printGivenLevel(obj.root, level);
        }
        else if (option == 5)
        {
            string player1;
            string player2;
            cout << "----Enter the players you want to check wether they are teammates or not, Like ahmad & mohamed"<<endl;
            cout << "enter 1st player name: \n";
            cin >> player1;
            player1[0] = toupper(player1[0]);
            int id1 = searchidbyname(head, player1);
            if (id1 != 0)
            {
                temp = obj.recursiveSearch(obj.root, id1);

                string club1 = temp->value[4];
                cout << "enter 2nd player name:\n";
                cin >> player2;
                player2[0] = toupper(player2[0]);
                int id2 = searchidbyname(head, player2);
                if (id2 != 0)
                {
                    temp = obj.recursiveSearch(obj.root, id2);
                }
                string club2 = temp->value[4];
                if (club1 == club2)
                {
                    cout << "yes " << player1 << " from " << club1 << " and " << player2 << " from " << club2 << " are teammeates";
                }
                else
                {
                    cout << "NO!!! " << player1 << " from " << club1 << " and " << player2 << " from " << club2 << " are not teammeates";
                }
            }
            else
                cout << "player 1 don't exist";
        }
        else if (option == 6)
        {
            cout << "Enter the shirt Number: \n";
            string shirtNumber;
            cin >> shirtNumber;
            printPlayerNamesByShirt(head, shirtNumber);
        }
        
        else if (option == 7)
        {
            cout << "select at which order do you want to print \n";
            cout << "1: preOrder \n";
            cout << "2: inOrder \n";
            cout << "3: postOrder \n";
            int option1;
            cin >> option1;
            if (option1 == 1)
            {
                obj.printPreorder(obj.root);
            }
            else if (option1 == 2)
            {
                obj.printInorder(obj.root);
            }
            else if (option1 == 3)
            {
                obj.printPostorder(obj.root);
            }
        }
        else if (option == 9)
        {
        }
        else if (option == 0)
        {
            cout << "exiting program" << endl;
        }
    } while (option != 0);
    // obj.printGivenLevel(obj.root, 3);

    // cout << "done";

    // cout << obj.root->left->left->right->value[1];
}
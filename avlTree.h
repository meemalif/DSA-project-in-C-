#pragma once
#include <iostream>
#include <cstdlib>
#include "linkedList.h"

#define SPACE 10

using namespace std;

class TreeNode
{
public:
    string value[13];
    TreeNode *left;
    TreeNode *right;

    TreeNode(string fifaID, string name, string age, string teamJersey, string club, string dob, string url, string nationality, string awards, string contactYear, string teamPosition, string height, string skills)
    {
        value[0] = fifaID;
        value[1] = name;
        value[2] = age;
        value[3] = teamJersey;
        value[4] = club;
        value[5] = dob;
        value[6] = url;
        value[7] = nationality;
        value[8] = awards;
        value[9] = contactYear;
        value[10] = teamPosition;
        value[11] = height;
        value[12] = skills;
        left = NULL;
        right = NULL;
    }
};

class AVLTree
{
public:
    TreeNode *root;
    node *head;
    AVLTree()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Get Height
    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    // Get Balance factor of node N
    int getBalanceFactor(TreeNode *n)
    {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode *insert(TreeNode *r, TreeNode *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            // cout << "Value inserted successfully" << endl;

            return r;
        }

        if ((new_node->value[0]) < (r->value[0]))
        {
            r->left = insert(r->left, new_node);
        }
        else if ((new_node->value[0]) > (r->value[0]))
        {
            (new_node->value[0]);
            r->right = insert(r->right, new_node);
        }
        else if ((new_node->value[0]) == (r->value[0]))
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case
        if (bf > 1 && (new_node->value[0]) < (r->left->value[0]))
            return rightRotate(r);

        // Right Right Case
        if (bf < -1 && (new_node->value[0]) > (r->right->value[0]))
            return leftRotate(r);

        // Left Right Case
        if (bf > 1 && (new_node->value[0]) > (r->left->value[0]))
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case
        if (bf < -1 && (new_node->value[0]) < (r->right->value[0]))
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value[1] << "\n";        // 6
        print2D(r->left, space);            // Process left child  7
    }
    void printPreorder(TreeNode *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value[1] << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->value[1] << " ";
        /* now recur on right child */
        printInorder(r->right);
    }
    void printPostorder(TreeNode *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree
        printPostorder(r->left);
        // then recur on right subtree
        printPostorder(r->right);
        // now deal with the node
        cout << r->value << " ";
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value[1] << " ";
        else // level > 0
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    // A function to search recursively in the given tree
    TreeNode *recursiveSearch(TreeNode *r, int val)
    {

        if (r == nullptr)
        {
            return nullptr;
        }
        if (stoi(r->value[0]) == val)
        {
            return r;
        }

        if (val > stoi(r->value[0]))
        {
            return recursiveSearch(r->right, val);
        }
        return recursiveSearch(r->left, val);
    }
};


//-------------------------------------------------------------------------------------

// Useless code, which we might have used so pasted here for future use.....

// int main()
// {
//     AVLTree obj;
//     int option, val;

//     do
//     {
//         cout << "What operation do you want to perform? "
//              << " Select Option number. Enter 0 to exit." << endl;
//         cout << "1. Insert Node" << endl;
//         cout << "2. Search Node" << endl;
//         cout << "3. Delete Node" << endl;
//         cout << "4. Print/Traversal AVL Tree values" << endl;
//         cout << "5. Height of Tree" << endl;
//         cout << "6. Clear Screen" << endl;
//         cout << "0. Exit Program" << endl;

//         cin >> option;
//         // Node n1;
//         TreeNode *new_node = new TreeNode();

//         switch (option)
//         {
//         case 0:
//             break;
//         case 1:
//             cout << "AVL INSERT" << endl;
//             cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
//             cin >> val;
//             new_node->value = val;
//             obj.root = obj.insert(obj.root, new_node);
//             cout << endl;
//             break;
//         case 2:
//             cout << "SEARCH" << endl;
//             cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
//             cin >> val;
//             // new_node = obj.iterativeSearch(val);
//             new_node = obj.recursiveSearch(obj.root, val);
//             if (new_node != NULL)
//             {
//                 cout << "Value found" << endl;
//             }
//             else
//             {
//                 cout << "Value NOT found" << endl;
//             }
//             break;
//         case 3:
//             cout << "DELETE" << endl;
//             cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
//             cin >> val;
//             new_node = obj.recursiveSearch(obj.root, val);
//             if (new_node != NULL)
//             {
//                 obj.root = obj.deleteNode(obj.root, val);
//                 cout << "Value Deleted" << endl;
//             }
//             else
//             {
//                 cout << "Value NOT found" << endl;
//             }
//             break;
//         case 4:
//             cout << "PRINT 2D: " << endl;
//             obj.print2D(obj.root, 5);
//             cout << endl;
//             // cout <<"Print Level Order BFS: \n";
//             // obj.printLevelOrderBFS(obj.root);
//             // cout <<endl;
//             //	      cout <<"PRE-ORDER: ";
//             //	      obj.printPreorder(obj.root);
//             //	      cout<<endl;
//             //	      cout <<"IN-ORDER: ";
//             //	      obj.printInorder(obj.root);
//             //	      cout<<endl;
//             //	      cout <<"POST-ORDER: ";
//             //	      obj.printPostorder(obj.root);
//             break;
//         case 5:
//             cout << "TREE HEIGHT" << endl;
//             cout << "Height : " << obj.height(obj.root) << endl;
//             break;
//         case 6:
//             system("cls");
//             break;
//         default:
//             cout << "Enter Proper Option number " << endl;
//         }

//     } while (option != 0);

//     return 0;
// }

// TreeNode *deleteNode(TreeNode *r, int v)
// {
//     // base case
//     if (r == NULL)
//     {
//         return NULL;
//     }
//     // If the key to be deleted is smaller than the root's key,
//     // then it lies in left subtree
//     else if (v < r->value[1])
//     {
//         r->left = deleteNode(r->left, v);
//     }
//     // If the key to be deleted is greater than the root's key,
//     // then it lies in right subtree
//     else if (v > r->value[1])
//     {
//         r->right = deleteNode(r->right, v);
//     }
//     // if key is same as root's key, then This is the node to be deleted
//     else
//     {
//         // node with only one child or no child
//         if (r->left == NULL)
//         {
//             TreeNode *temp = r->right;
//             delete r;
//             return temp;
//         }
//         else if (r->right == NULL)
//         {
//             TreeNode *temp = r->left;
//             delete r;
//             return temp;
//         }
//         else
//         {
//             // node with two children: Get the inorder successor (smallest
//             // in the right subtree)
//             TreeNode *temp = minValueNode(r->right);
//             // Copy the inorder successor's content to this node
//             r->value = temp->value;
//             // Delete the inorder successor
//             r->right = deleteNode(r->right, temp->value);
//             // deleteNode(r->right, temp->value);
//         }
//     }

//     int bf = getBalanceFactor(r);
//     // Left Left Imbalance/Case or Right rotation
//     if (bf == 2 && getBalanceFactor(r->left) >= 0)
//         return rightRotate(r);
//     // Left Right Imbalance/Case or LR rotation
//     else if (bf == 2 && getBalanceFactor(r->left) == -1)
//     {
//         r->left = leftRotate(r->left);
//         return rightRotate(r);
//     }
//     // Right Right Imbalance/Case or Left rotation
//     else if (bf == -2 && getBalanceFactor(r->right) <= -0)
//         return leftRotate(r);
//     // Right Left Imbalance/Case or RL rotation
//     else if (bf == -2 && getBalanceFactor(r->right) == 1)
//     {
//         r->right = rightRotate(r->right);
//         return leftRotate(r);
//     }

//     return r;
//}
// void printLevelOrderBFS(TreeNode *r)
// {
//     int h = height(r);
//     for (int i = 0; i <= h; i++)
//         printGivenLevel(r, i);
// }
// TreeNode *iterativeSearch(TreeNode *r, int v)
// {

//     if (r == NULL)
//     {
//         return r;
//     }
//     else
//     {
//         // cout << "true of false : " << (r->value[1].substr(0, v.size()) > v) << r->value[1].substr(0, v.size()) << " and " << v << "\t";

//         while (r != NULL)
//         {
//             if (stoi(r->value[0]) == v)
//             {

//                 return r;
//             }
//             else if (v > stoi(r->value[0]))
//             {
//                 cout << "moving left";
//                 r = r->left;
//             }
//             else if (v < stoi(r->value[0]))
//             {
//                 cout << "moving right";

//                 return r->right;
//             }
//         }
//         return NULL;
//     }
// }
// TreeNode *minValueNode(TreeNode *node)
// {
//     TreeNode *current = node;
//     /* loop down to find the leftmost leaf */
//     while (current->left != NULL)
//     {
//         current = current->left;
//     }
//     return current;
// }
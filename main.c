#include <stdio.h>
#include <stdlib.h>
#include "nbtree.h"

int main() {
    Isi_Tree myTree;
    int choice, nodeValue, numNodes;
    char searchChar;
    
    printf("=== ADT Non Binary Tree Implementation ===\n");
    
    // Buat tree/pohon
    printf("Enter number of nodes to create: ");
    scanf("%d", &numNodes);
    
    Create_tree(myTree, numNodes);
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Print Tree Structure\n");
        printf("2. PreOrder Traversal\n");
        printf("3. InOrder Traversal\n");
        printf("4. PostOrder Traversal\n");
        printf("5. Level Order Traversal\n");
        printf("6. Search for a node\n");
        printf("7. Count number of elements\n");
        printf("8. Count number of leaf nodes\n");
        printf("9. Find level of a node\n");
        printf("10. Find depth of tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                PrintTree(myTree);
                break;
            case 2:
                printf("PreOrder Traversal: ");
                PreOrder(myTree);
                printf("\n");
                break;
            case 3:
                printf("InOrder Traversal: ");
                InOrder(myTree);
                printf("\n");
                break;
            case 4:
                printf("PostOrder Traversal: ");
                PostOrder(myTree);
                printf("\n");
                break;
            case 5:
                printf("Level Order Traversal: ");
                Level_order(myTree, numNodes);
                printf("\n");
                break;
            case 6:
                printf("Enter character to search: ");
                scanf(" %c", &searchChar);
                if (Search(myTree, searchChar)) {
                    printf("'%c' found in the tree.\n", searchChar);
                } else {
                    printf("'%c' not found in the tree.\n", searchChar);
                }
                break;
            case 7:
                printf("Number of elements: %d\n", nbElmt(myTree));
                break;
            case 8:
                printf("Number of leaf nodes: %d\n", nbDaun(myTree));
                break;
            case 9:
                printf("Enter character to find level: ");
                scanf(" %c", &searchChar);
                nodeValue = Level(myTree, searchChar);
                if (nodeValue != -1) {
                    printf("Level of '%c': %d\n", searchChar, nodeValue);
                } else {
                    printf("'%c' not found in the tree.\n", searchChar);
                }
                break;
            case 10:
                printf("Depth of tree: %d\n", Depth(myTree));
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
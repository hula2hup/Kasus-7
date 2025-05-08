#include <stdio.h>
#include <stdlib.h>
#include "nbtree.h"

// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    char info;
    int parent, first_son, next_brother;
    
    // Inisialisasi node
    for (i = 1; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
    
    // Buat node berdasarkan input pengguna dalam urutan level
    printf("Input tree nodes in level order:\n");
    for (i = 1; i <= Jml_Node; i++) {
        printf("Node %d:\n", i);
        printf("  Info: ");
        scanf(" %c", &info);
        X[i].info = info;
        
        printf("  Parent position (0 if root): ");
        scanf("%d", &parent);
        X[i].ps_pr = parent;
        
        printf("  First son position (0 if none): ");
        scanf("%d", &first_son);
        X[i].ps_fs = first_son;
        
        printf("  Next brother position (0 if none): ");
        scanf("%d", &next_brother);
        X[i].ps_nb = next_brother;
    }
}

// Cek apakah pohon kosong
boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == ' ');
}

// PreOrder traversal: Parent, First Son, Next Brother
void PreOrder(Isi_Tree P) {
    PreOrderRec(P, 1);
}

void PreOrderRec(Isi_Tree P, int root) {
    if (root != nil) {
        printf("%c ", P[root].info);  // parent
        PreOrderRec(P, P[root].ps_fs);  // first son
        PreOrderRec(P, P[root].ps_nb);  // next brother
    }
}

// InOrder traversal: First Son, Parent, Other Children
void InOrder(Isi_Tree P) {
    InOrderRec(P, 1);
}

void InOrderRec(Isi_Tree P, int root) {
    if (root != nil) {
        int first_son = P[root].ps_fs;
        
        // First son
        if (first_son != nil) {
            InOrderRec(P, first_son);
        }
        
        // Parent
        printf("%c ", P[root].info);
        
        // Other children (next brothers of first son)
        if (first_son != nil) {
            int curr = P[first_son].ps_nb;
            while (curr != nil) {
                InOrderRec(P, curr);
                curr = P[curr].ps_nb;
            }
        }
    }
}

// PostOrder traversal: First Son, Next Brother, Parent
void PostOrder(Isi_Tree P) {
    PostOrderRec(P, 1);
}

void PostOrderRec(Isi_Tree P, int root) {
    if (root != nil) {
        PostOrderRec(P, P[root].ps_fs);  // first son
        PostOrderRec(P, P[root].ps_nb);  // next brother
        printf("%c ", P[root].info);  // parent
    }
}

// Level Order traversal
void Level_order(Isi_Tree X, int Maks_node) {
    int i;
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != ' ') {
            printf("%c ", X[i].info);
        }
    }
}

// Print struktur pohon
void PrintTree(Isi_Tree P) {
    int i;
    printf("Tree Structure:\n");
    printf("Index\tInfo\tFS\tNB\tParent\n");
    printf("------------------------------\n");
    
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            printf("%d\t%c\t%d\t%d\t%d\n", 
                   i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
        }
    }
}

// Cari node dengan nilai yang ditentukan
boolean Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

// Hitung jumlah elemen di pohon
int nbElmt(Isi_Tree P) {
    int i, count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            count++;
        }
    }
    return count;
}

// Hitung jumlah daun di pohon
int nbDaun(Isi_Tree P) {
    int i, count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

// Cari level node dengan nilai yang ditentukan
int Level(Isi_Tree P, infotype X) {
    int i, level = 0;
    
    // Cari node dengan value x
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            // Menemukan node, menghitung levelnya
            int curr = i;
            while (P[curr].ps_pr != nil) {
                level++;
                curr = P[curr].ps_pr;
            }
            return level;
        }
    }
    
    // Tidak ketemu
    return -1;
}

// Hitung kedalaman tinggi pohon
int Depth(Isi_Tree P) {
    if (IsEmpty(P)) {
        return 0;
    }
    
    int i, max_level = 0, level;
    
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            level = Level(P, P[i].info);
            if (level > max_level) {
                max_level = level;
            }
        }
    }
    
    return max_level + 1;  
}

// Mengembalikan maksimal dua nilai
int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "DnDMonsters.h"
using namespace std;

int main() {
    int depth = 0;
    // Example of writing out to a file
    // ofstream outFile;
    // outFile.open("../data/example-output.csv");
    // for (int i = 999; i >= 0; --i) {
    //     outFile << i << endl;
    // }
    // outFile.close();

    // Example of how to declare and use a tree object
    BinarySearchTree<int> bst1;
    if (!bst1.add(8)) {
        cout << "Could not add 8 to the tree." << endl;
    }
    if (bst1.find(8, depth)) {
        cout << "Found 8 in the tree." << endl;
    }
    if (bst1.getSize() != 1) {
        cout << "There are " << bst1.getSize() << " nodes in the tree." << endl;
    } else {
        cout << "There is one node in the tree." << endl;
    }
    bst1.timber();

    SplayTree<int> test;
    for (int i = 0; i < 100; ++i) {
        if (!test.add(i)) {
            cout << "Could not add " << i << endl;
        }
    }
    cout << "Size: " << test.getSize() << endl;
    for (int i = 0; i < 100; ++i) {
        if (!test.find(i, depth)) {
            cout << "Could not find " << i << endl;
        }
    }

    BinarySearchTree<int> Bst;
    AVLTree<int> Avlt;
    SplayTree<int> St;
    for (int i = 1; i <= 100; ++i) {
        if (!Bst.add(i)) {
            cout << "Could not add " << i << endl;
        }
        if (!Avlt.add(i)) {
            cout << "Could not add " << i << endl;
        }
        if (!St.add(i)) {
            cout << "Could not add " << i << endl;
        }
    }
    cout << "Size of Binary Tree: " << Bst.getSize() << endl;
    cout << "Size of AVL Tree: " << Avlt.getSize() << endl;
    cout << "Size of Splay Tree: " << St.getSize() << endl;

    bool find0 = Bst.find(0, depth);
    cout << "Value: " << find0 << " Depth: " << depth << endl;

    bool find101 = Bst.find(101, depth);
    Bst.find(101, depth);
    cout << "Value: " << find101 << " Depth: " << depth << endl;

    bool find102 = Bst.find(102, depth);
    Bst.find(102, depth);
    cout << "Value: " << find102 << " Depth: " << depth << endl;


    BinarySearchTree<int> Bst2;
    AVLTree<int> Avlt2;
    SplayTree<int> St2;

    vector<int> vec = {74, 24, 79, 47, 86, 59, 38, 70, 77, 22, 95, 44, 41, 15, 34, 10, 16, 52, 21, 65, 88, 11, 94, 43, 55, 46, 8, 7, 97, 25, 28, 93, 81, 32, 61, 31, 84, 20, 45, 76, 48, 23, 92, 4, 36, 87, 89, 69, 51, 12, 63, 78, 37, 62, 72, 56, 82, 27, 17, 9, 91, 80, 99, 60, 18, 85, 39, 68, 35, 40, 33, 57, 90, 30, 19, 26, 5, 98, 1, 6, 50, 73, 2, 29, 42, 58, 49, 71, 3, 75, 83, 64, 67, 96, 53, 54, 13, 66, 14, 100};


    for (int i = 1; i<100; i++) {
        if (!Bst2.add(vec[i])) {
            cout << "Could not add " << i << endl;
        }
        if (!Avlt2.add(vec[i])) {
            cout << "Could not add " << i << endl;
        }
        if (!St2.add(vec[i])) {
            cout << "Could not add " << i << endl;
        }
    }
    ofstream outFile;
    outFile.open("../data/example-output.csv");
    for (int i = 1; i<=100; i++) {
        Bst2.find(i, depth);
        outFile << depth << " ";
        Avlt2.find(i, depth);
        outFile << depth << " ";
        St2.find(i, depth);
        outFile << depth << endl;
    }
    outFile.close();

    BinarySearchTree<DndMon> BstDM;
    AVLTree<DndMon> AvltDM;
    SplayTree<DndMon> StDM;
    vector<DndMon> Mons;
    getFileData("../Dnd_Monster_Data.csv", Mons);

    for (int i = 1; i<1000; i++) {
        if (!BstDM.add(Mons[i])) {
            cout << "Could not add " << i << endl;
        }
        if (!AvltDM.add(Mons[i])) {
            cout << "Could not add " << i << endl;
        }
        if (!StDM.add(Mons[i])) {
            cout << "Could not add " << i << endl;
        }
    }

    SplayTree<DndMon> Monsters;
    for (int i = 1; i<=1000; i++) {
        if (!Monsters.add(Mons[i])) {
            cout << "Could not add " << i << endl;
        }
    }

    outFile.open("../data/Monsters_Data.csv");
    for (int i=1; i<=1000; i++) {
        outFile<< Mons[i] << " ";
        for (int j=1; j<5; j++) {
            Monsters.find(Mons[i], depth);
            outFile<< depth<< " ";
        }
        outFile<< endl;
    }





    return 0;
}
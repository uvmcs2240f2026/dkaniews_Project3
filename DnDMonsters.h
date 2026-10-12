/**
 *  Deirdre Kaniewski
 *  CS 2240
 *  Section A
 */

#ifndef PROJECT1_DNDMONSTERS_H
#define PROJECT1_DNDMONSTERS_H

#include <fstream>
#include <vector>
using namespace std;
#include <iostream>
#include <string>
using std::string, std:: ostream;



class DndMon {
private:
    // Declaring variables
    std:: string name, type, size;
    double cr;
    int ac;

public:
    //constructors
    DndMon() {
        name= "";
        type= "";
        size= "";
        cr= -1.0;
        ac= -1;
    }
    DndMon(std:: string name, double cr, std:: string type, std:: string size, int ac) {
        this->name = name;
        this->type = type;
        this->size = size;
        this->cr = cr;
        this->ac = ac;

    }

    //getters
    std::string getName() {
        return name;
    }

    double getCr() {
        return cr;
    }

    std::string getType() {
        return type;
    }

    std::string getSize() {
        return size;
    }

    int getAc() {
        return ac;
    }

    //setters
    void setName(std::string name) {
        this->name = name;
    }

    void setCr(double cr) {
        this->cr = cr;
    }

    void setType(std::string type) {
        this->type = type;
    }

    void setSize(std::string size) {
        this->size = size;
    }

    void setAc(int ac) {
        this->ac = ac;
    }

    friend ostream& operator << (ostream& outs, const DndMon& mons) {
        outs << mons.name;
        outs << mons.cr;
        outs << mons.type;
        outs << mons.size;
        outs << mons.ac;
        return outs;
    }

    friend bool operator< (const DndMon& lhs, const DndMon& rhs) {
        return lhs.name < rhs.name;
    }

};

/**
 * Opens the files and reads through each entry in the Dataset
 * @param fName
 * @param DndMons
 */
void getFileData(string fName, vector<DndMon>& DndMons) {
    ifstream fileIn;
    fileIn.open(fName);

    if (fileIn) {
        cout << "Opened file" << endl;
        string header;
        getline(fileIn, header);

        //Declare Variables
        string name = "", type = "", size = "";
        double cr = -1.0;
        int ac = -1;
        char comma = ',';

        while (fileIn && fileIn.peek() !=EOF) {
            name= "";
            type = "";
            size = "";
            cr = -1.0;
            ac = -1;
            //read in name
            getline(fileIn, name, ',');
            cout << name << ", ";

            //read in cr
            fileIn >> cr;
            if (!fileIn) {
                cr = -1.0;
                fileIn.clear();
            }
            fileIn >> comma;
            cout << cr << ", ";;

            //read in type
            getline(fileIn, type, ',');
            cout << type << ", ";;

            //read in size
            getline(fileIn, size, ',');
            cout << size << ", ";

            //read in ac
            fileIn >> ac;
            string newLine;
            getline(fileIn, newLine);
            cout << ac << endl << endl;

            DndMons.push_back(DndMon(name, cr, type, size, ac));
        }
    }

    fileIn.close();

}

/**
 * This function loops through the data to find the monsters with the highest ac
 * if there is more than one it lists all the monsters with the highest ac
 * @param mons
 */

void highestAC(std::vector<DndMon>& mons) {
    string nameOfMon = "";
    int highAC = 0;
    for (DndMon& curr: mons) {
        // adds to the list if there are multiple creatures with the same ac
        if (curr.getAc() == highAC) {
            nameOfMon = nameOfMon + ", " + curr.getName();
        }
        // resets the string if a higher ac is found
        // sets the new highest ac and what creature has that ac
        else if (curr.getAc() > highAC) {
            nameOfMon = "";
            highAC = curr.getAc();
            nameOfMon = curr.getName();
        }
    }
    cout<< nameOfMon<< endl<< endl;
}

/**
 * sizeVary calculates how many monsters from the data set belong to each size category
 * It also calculates the percentage each category makes up of the whole data set
 * @param mons
 */

void sizeVary(std::vector<DndMon>& mons) {
    int tiny = 0, small = 0, medium = 0, large = 0, huge = 0, gargantuan = 0, total = 0;
    double pt = 0, ps = 0, pm = 0, pl = 0, ph = 0, pg =0;

    // loops through data to calc how many entries are in each size category
    for (DndMon& curr: mons) {
        if (curr.getSize() == "Tiny") {
            tiny += 1;
        }
        else if (curr.getSize() == "Small") {
            small += 1;
        }
        else if (curr.getSize() == "Medium") {
            medium += 1;
        }
        else if (curr.getSize() == "Large") {
            large += 1;
        }
        else if (curr.getSize() == "Huge") {
            huge += 1;
        }
        else if (curr.getSize() == "Gargantuan") {
            gargantuan += 1;
        }
        total += 1;
    }

    // calcs of percentage
    pt = (double(tiny)/ total) * 100;
    ps = (double(small)/ total) * 100;
    pm = (double(medium)/ total) * 100;
    pl = (double(large)/ total) * 100;
    ph = (double(huge)/ total) * 100;
    pg = (double(gargantuan)/ total) * 100;

    // prints values
    cout << "Tiny: " << tiny<< endl;
    cout << pt << "%" << endl << endl;

    cout << "Small: " << small<< endl;
    cout << ps << "%" << endl << endl;

    cout << "Medium: " << medium<< endl;
    cout << pm<< "%" << endl << endl;

    cout << "Large: " << large<< endl;
    cout << pl << "%" << endl << endl;

    cout << "Huge: " << huge<< endl;
    cout << ph << "%" << endl << endl;

    cout << "Gargantuan: " << gargantuan<< endl;
    cout << pg << "%" << endl << endl;


}


#endif //PROJECT1_DNDMONSTERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
enum trait {potent, essence, aspect};

struct rune
{
    string name;
    trait type;
};

bool readFile(ifstream& fin, rune& runeStore);


int main(int argc, char** argv)
{
    rune runeHolder;
    bool read;
    int k = 3;
    ifstream fin;
    if (argc != 2)
    {
        cout << "Invalid Startup" << endl;
        return 0;
    }
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Unable to open file " << argv[1] << endl;
        return 0;
    }
    read = readFile(fin, runeHolder);

    return 0;
}

bool readFile(ifstream& fin, rune& runeStore)
{
    string toss;
    string type;
    getline(fin, toss);
    while (getline(fin,runeStore.name,','))
    {
        fin >> type;
        if (type == "Essence")
        {
            runeStore.type = essence;
        }
        if (type == "Aspect")
        {
            runeStore.type = aspect;
        }
        if (type == "Potency")
        {
            runeStore.type = potent;
        }
        cout << runeStore.name << "---" << type << endl;
    }
    return true;
}
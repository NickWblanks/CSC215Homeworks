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

bool readFile(ifstream& fin, rune& runeStore, rune *runeArr, int &n);

void permute(rune *ans, int* used, int n, rune *runeName, int pos);


int main(int argc, char** argv)
{
    int count = 0;
    rune runeHolder;
    bool read;
    int k = 3;
    ifstream fin;
    rune runeA[100];
    rune ans[100];
    int used[100] = {0};
    int pos = 0;
    if (argc != 2)
    {
        cout << "m0100.exe csvdatafile" << endl;
        return 0;
    }
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Unable to open: " << argv[1] << endl;
        return 0;
    }
    read = readFile(fin, runeHolder, runeA, count);
    permute(ans, used, count, runeA, pos);
    return 0;
}

bool readFile(ifstream& fin, rune& runeStore, rune *runeArr, int &n)
{
    //new param in, ans array
    //for loop add in names to array
    int i = 0;
    string toss, toss2;
    string type;
    string name, rune;
    getline(fin, toss);
    while (fin >> name)
    {
        n++;
    }
    fin.clear();
    fin.seekg(0, ios::beg);
    getline(fin, toss2);
    while(i < n)
    {
        getline(fin, rune, ',');
        runeStore.name = rune;
        fin >> type;
        fin.ignore();
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
        runeArr[i] = runeStore;
        i++;
    }
    return true;
}

void permute(rune *ans, int* used, int n, rune *runeName, int pos)
{
    rune theRune, theRune2, theRune3, theRune4;
    string name;
    int i;
    if (pos == 3)
    {
        theRune4 = ans[0];
        theRune2 = ans[1];
        theRune3 = ans[2];
        if (theRune4.type == potent && theRune2.type == essence && theRune3.type == aspect)
        {
            for (i = 0; i < 3; i++)
            {
                theRune = ans[i];
                name = theRune.name;
                cout << name << " ";
            }
            cout << endl;
        }
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            ans[pos] = runeName[i];
            used[i] = 1;
            permute(ans, used, n, runeName, pos + 1);
            used[i] = 0;
        }
    }
}
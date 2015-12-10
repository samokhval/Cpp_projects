#include "iostream"
#include "fstream"
#include "cstring"
#include <stdlib.h>     /* atoi */
#include <iomanip>      /* std::setw */

const int S_SIZE = 128;
const int FLEET_SIZE = 100;
const char FILE_NAME[50] = "starships.txt";

using namespace std;

struct Ship
{
    char *name;
    int registry;
    char *type;
    char *position;
    char *condition;
    char *captain;
    Ship * next;
};

class Starfleet
{
public:
    Starfleet();
    void add_Ship();
    void del_Ship(char *shipName);
    void add_to_List(Ship *curShip);
    bool comparator(Ship *curShip, Ship *tmpShip);
    void display_All_Fleet();
    bool find_Ship(int reg_numb_ship);
    void output_to_File();

    ~Starfleet();
private:
    Ship *head;
    Ship *currentShip;
    Ship *tempShip;

    int shipCount;

};

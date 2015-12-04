#include "iostream"
#include "fstream"
#include "cstring"
#include <stdlib.h>     /* atoi */
#include <iomanip>      /* std::setw */

const int S_SIZE = 128;
const int FLEET_SIZE = 100;
const char FILE_NAME[50] = "C:\\starships.txt";

using namespace std;

struct Ship
{
    char *name;
    int registry;
    char *type;
    char *position;
    char *condition;
    char *captain;
    Ship * next; // Point to next Ship.
};

class Starfleet
{
public:
    Starfleet();
    void add_Ship();
    void display_All_Fleet();
    bool find_Ship(int reg_numb_ship);
    bool comparator(Ship *currentShip, Ship *tempShip);
    ~Starfleet();
private:
    Ship *head;
    int shipCount;
};

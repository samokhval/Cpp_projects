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
};

class Starfleet
{
public:
    Starfleet();
    void add_Ship();
    void display_All_Fleet();
    bool find_Ship(int reg_numb_ship);
    ~Starfleet();
private:
    Ship *Ships[FLEET_SIZE];
    int count_ship;
};

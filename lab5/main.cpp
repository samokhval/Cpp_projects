#include <iostream>
#include <lab5Header.h>
#include<limits>

using namespace std;

int main()
{
    Starfleet pFleet;
    char choice;
    char input[255];
    int reg_Numb;
    char *shipName;

    cout << "Welcome to the Murzjuk Starfleet!" << endl;
    cout << endl;
    cout << "What would you like to do in my Starfllet? (a)dd a new ship, (r)emove a ship, (d)isplay all of the ships, (s)earch ship by registry number, (o)utput info to file, or (q)uit? ";

    do
    {
        cin.clear();
        cin.sync();
        cin.getline(input, 255);
        if (cin.gcount() != 2)
        {
          cout << endl;
          cout << "Wrong command! Please enter only one character!" << endl;
          cout << "Please make your selection: (a)dd a new ship, (r)emove a ship, (d)isplay all of the ships, (s)earch ship by registry number, (o)utput info to file, or (q)uit? ";
        }
        else
        {
            choice = input[0];
            switch (choice)
            {
                case 'a': pFleet.add_Ship();
                          break;
                case 'r': cout << "Please enter the name of ship which you want delete: ";
                          cin >> shipName;
                          pFleet.del_Ship(shipName);
                          break;
                case 's': cout << "Please enter the registry number of ship: ";
                          while(!(cin >> reg_Numb))
                          {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "Invalid registry number. Please enter only numbers: ";
                          }
                          if (!pFleet.find_Ship(reg_Numb))
                            cout << "The ship with register number " << reg_Numb << " is not found!! " << endl;
                          break;
                case 'd': pFleet.display_All_Fleet();
                          break;
                case 'o': pFleet.output_to_File();
                          break;
                case 'q': cout << "Please, press any key!" << endl;
                          return 0;
                          break;
                case 'Q': cout << "Please, press any key!" << endl;
                          return 0;
                          break;
                 default: cout << "Wrong command! Please enter correct character!" << endl;
                          break;
            }
            cout << endl;
            cout << "What would you like to do yet in my Starfllet? (a)dd a new ship, (r)emove a ship, (d)isplay all of the ships, (s)earch ship by registry number, (o)utput info to file, or (q)uit? ";
        }
    }
    while (choice != 'q');

    return 0;
}

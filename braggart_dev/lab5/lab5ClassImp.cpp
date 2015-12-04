#include "lab5Header.h"

Starfleet::Starfleet()
{
    head = nullptr;
    shipCount = 0;
}

Starfleet::~Starfleet()
{
   delete head;
}

void Starfleet::display_All_Fleet()
{
    if (head == nullptr)
        cout<<"\nList is empty\n\n";
    else
    {
       Ship *tempS = head;
       cout<<"\nShips list: ";
       do
       {
          cout << "Ships name is " << tempS->name << endl;
          tempS = tempS->next;
       }
       while(tempS != nullptr);
    cout<<"\n\n";
    }
}

void Starfleet::add_Ship()
{
    char input[S_SIZE];
    Ship *currentShip = new Ship;
    cout << "What is the ships name? ";
    cin.get(input, S_SIZE);
    currentShip->name = new char[strlen(input) + 1];
    strncpy(currentShip->name, input, strlen(input));
    currentShip->name[strlen(input)] = '\0';

    if( head == nullptr)
    {
        head = currentShip;
    }
    else
    {
        //Ship *tempShip = head;
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = currentShip;
    }
    shipCount++;
    cout<<"New ship has been added...\n";
    delete currentShip;
}

bool Starfleet::comparator(Ship *currentShip, Ship *tempShip)
{
    if (strcmp(currentShip->name, tempShip->name) > 0)
    {
       return true;
    }
    else
    {
       return false;
    }
}

bool Starfleet::find_Ship(int reg_numb_ship)
{
   return true;
}

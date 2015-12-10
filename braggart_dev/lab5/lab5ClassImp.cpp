#include "lab5Header.h"

Starfleet::Starfleet()
{
    head = nullptr;
    currentShip = nullptr;
    tempShip = nullptr;

    shipCount = 0;
    ifstream dataFile;
    char buff[S_SIZE];

  if (dataFile)
  {
    dataFile.open(FILE_NAME, std::ifstream::in);

    while (!dataFile.eof())
    {
      while (true)
      {
        for (int i = 0; i < 6; i++)
        {
           dataFile.getline(buff,S_SIZE);

           if (strlen(buff) == 0)
           {
                return;
           }
           switch (i)
           {
                case 0:
                       currentShip = new Ship;
                       currentShip->name = new char[strlen(buff) + 1];
                       strncpy(currentShip->name, buff, strlen(buff));
                       currentShip->name[strlen(buff)] = '\0';
                       break;
                case 1:
                       currentShip->registry = atoi(buff);
                       break;
                case 2:
                       currentShip->type = new char[strlen(buff) + 1];
                       strcpy(currentShip->type, buff);
                       break;
                case 3:
                       currentShip->position = new char[strlen(buff) + 1];
                       strcpy(currentShip->position, buff);
                       break;
                case 4:
                       currentShip->condition = new char[strlen(buff) + 1];
                       strcpy(currentShip->condition, buff);
                       break;
                case 5:
                       currentShip->captain = new char[strlen(buff) + 1];
                       strcpy(currentShip->captain, buff);
                       break;
                default:
                       break;
             }
             currentShip->next = nullptr;
         }
         add_to_List(currentShip);
         shipCount++;
     }
    }
    dataFile.close();       
 }
 else {cout << " Input file doesn't exists!" << endl;}

 if (shipCount !=0)
 {
      cout << " Download " << shipCount << " from the file " << FILE_NAME << endl;
      cout << " You'll see them if you press key 'd'"  << endl;
 }
}

Starfleet::~Starfleet()
{
    if (head == nullptr)
       return;
    else
    {
       tempShip = head;
       while (true)
       {
            if( tempShip == nullptr)
            {
                break;
            }
            else
            {
                tempShip = tempShip->next;
                delete tempShip;
            }
       }
    }
   delete currentShip;
   delete head;
}

void Starfleet::add_Ship()
{
    char input[S_SIZE];
    currentShip = new Ship;
    tempShip = head;
    cout<<"\n";
    cout << "What is the ships name? ";
    cin.get(input, S_SIZE);
    currentShip->name = new char[strlen(input) + 1];
    strncpy(currentShip->name, input, strlen(input));
    currentShip->name[strlen(input)] = '\0';

    while(true)
    {
        cout << "What is the registry of the ship? " ;
        cin >> currentShip->registry;
        if( cin.good())
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cout << "Incorrect input! Please enter only numbers!" << endl;
        cin.ignore(10, '\n');
    }

    cout << "What is the type of the ship? ";
    cin.clear();
    cin.sync();
    cin.get(input, S_SIZE);
    currentShip->type = new char[strlen(input) + 1];
    strncpy(currentShip->type, input, strlen(input));
    currentShip->type[strlen(input)] = '\0';

    cout << "What is the position of the ship? " ;
    cin.clear();
    cin.sync();
    cin.get(input, S_SIZE);
    currentShip->position = new char[strlen(input) + 1];
    strncpy(currentShip->position, input, strlen(input));
    currentShip->position[strlen(input)] = '\0';

    cout << "What is the condition of the ship? ";
    cin.clear();
    cin.sync();
    cin.get(input, S_SIZE);
    currentShip->condition = new char[strlen(input) + 1];
    strncpy(currentShip->condition, input, strlen(input));
    currentShip->condition[strlen(input)] = '\0';

    cout << "Who is the captain of the ship? " ;
    cin.clear();
    cin.sync();
    cin.get(input, S_SIZE);
    currentShip->captain = new char[strlen(input) + 1];
    strncpy(currentShip->captain, input, strlen(input));
    currentShip->captain[strlen(input)] = '\0';

    currentShip->next = nullptr;

    add_to_List(currentShip);

    shipCount++;
    cout<<"\nThe new ship succefully added to the Starfleet!\n";
}

void Starfleet::del_Ship(char *shipName)
{
    tempShip = head;

    while (true)
    {
        if( tempShip == nullptr)
        {
            break;
        }
        else
        {
           if (strcmp(tempShip->name,shipName) == 0 && tempShip == head)
           {
               //delete all the c-strings in the Ship struct
               delete tempShip->name;
               delete tempShip->type;
               delete tempShip->position;
               delete tempShip->condition;
               delete tempShip->captain;
               head = tempShip->next;
               cout << "The ship '" << shipName << "' was deleted!" << endl;
               break;
           }
           else
           {
               if (strcmp(tempShip->next->name,shipName) == 0)
               {
                    if (tempShip->next->next == nullptr)
                    {
                        //delete all the c-strings in the Ship struct
                        delete tempShip->next->name;
                        delete tempShip->next->type;
                        delete tempShip->next->position;
                        delete tempShip->next->condition;
                        delete tempShip->next->captain;
                        tempShip->next = nullptr;
                        cout << "The ship '" << shipName << "' was deleted!" << endl;
                        break;
                    }
                    else
                    {
                        //delete all the c-strings in the Ship struct
                        delete tempShip->next->name;
                        delete tempShip->next->type;
                        delete tempShip->next->position;
                        delete tempShip->next->condition;
                        delete tempShip->next->captain;
                        tempShip->next = tempShip->next->next;
                        cout << "The ship '" << shipName << "' was deleted!" << endl;
                        break;
                    }
                }
           }
           tempShip = tempShip->next;
        }
    }
}

void Starfleet::add_to_List(Ship *curShip)
{
  tempShip = head;
    Ship * prev;

  if( head == nullptr)
  {
       head = curShip;
  }
  else
  {
      prev = head;
    while (true)
    {
       if( tempShip->next == nullptr && tempShip == head)
       {
           if(!comparator(curShip,tempShip))
           {
              head = curShip;
              head->next = tempShip;
              break;
           }
           else
           {
              tempShip->next = curShip;
              break;
           }
       }
       else // There are at least 2 things in the list.
       {
           if (!comparator(curShip,tempShip) && prev == head) // curShip goes at the beginning.
            {
                curShip->next = tempShip;
                head = curShip;
                break;
            }
            else if((tempShip->next != NULL) &&
                (comparator(curShip,tempShip)) && comparator(tempShip->next, curShip))
           {  // curShip goes in the middle.
               curShip->next = tempShip->next;
               tempShip->next = curShip;
               break;
           }

       }
        prev = tempShip;
       tempShip = tempShip->next;
        if(tempShip == NULL) // If we reach the end of the list, curShip goes at the end.
        {
            prev->next = curShip;
            break;
        }
    }
  }
}

bool Starfleet::comparator(Ship *curShip, Ship *tmpShip)
{
    if (strcmp(curShip->name,tmpShip->name) >= 0)
    {
       return true;
    }
    else
    {
       return false;
    }
}

void Starfleet::display_All_Fleet()
{
    tempShip = head;
    if (tempShip == nullptr)
       cout<<"\nThe Starfleet is empty!\n\n";
    else
    {
       cout << endl;
       cout << "The Starfleet is contain next ships: " << endl;
       cout << " ---------------------------------------------------------------------------" << endl;
       cout << "|    Name   | Registry |    Type    |    Position    | Condition|  Captain  |  " << endl;
       cout << " ---------------------------------------------------------------------------" << endl;

       while (true)
       {
            if( tempShip == nullptr)
            {
                break;
            }
            else
            {
                cout << "| " << setw(10) << tempShip->name << "|";
                cout << setw(10) << tempShip->registry << "|";
                cout << setw(12) << tempShip->type << "|";
                cout << setw(16) << tempShip->position << "|";
                cout << setw(11) << tempShip->condition << "|";
                cout << setw(10) << tempShip->captain << "|" << endl;

                tempShip = tempShip->next;
            }
       }
       cout << " ---------------------------------------------------------------------------" << endl;
       cout<<"\n";
    }
}

void Starfleet::output_to_File()
{
    ofstream  output_File(FILE_NAME, ios::trunc);
    tempShip = head;
    if (tempShip != nullptr)
    {
       while (true)
       {
            if( tempShip == nullptr)
            {
                break;
            }
            else
            {
                output_File << tempShip->name << endl;
                output_File << tempShip->registry << endl;
                output_File << tempShip->type << endl;
                output_File << tempShip->position << endl;
                output_File << tempShip->condition << endl;
                output_File << tempShip->captain << endl;

                tempShip = tempShip->next;
            }
       }
       cout << "Upload information to the file is complete!" << endl;
    }
}

bool Starfleet::find_Ship(int reg_numb_ship)
{
    bool is_find = false;
    tempShip = head;
    while (true)
    {
        if( tempShip == nullptr)
        {
            break;
        }
        else
        {
            if (tempShip->registry == reg_numb_ship)
            {
                cout << endl;
                cout << "Was found next ship with registry number " << reg_numb_ship << ": " << endl;
                cout << " ----------------------------------------------------------------------------" << endl;
                cout << "|    Name   | Registry |    Type    |    Position    | Condition |  Captain  |  " << endl;
                cout << " ----------------------------------------------------------------------------" << endl;
                cout << "| " << setw(10) << tempShip->name << "|";
                cout << setw(10) << tempShip->registry << "|";
                cout << setw(12) << tempShip->type << "|";
                cout << setw(16) << tempShip->position << "|";
                cout << setw(11) << tempShip->condition << "|";
                cout << setw(10) << tempShip->captain << "|" << endl;
                cout << " ----------------------------------------------------------------------------" << endl;
                is_find = true;
                break;
           }
           tempShip = tempShip->next;
        }
    }
    return is_find;
}

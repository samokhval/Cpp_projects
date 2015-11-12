#include "lab4Header.h"

Starfleet::Starfleet()
{
    ifstream dataFile;
    count_ship = 0;

    char buff[S_SIZE];
    int step = 0;
    if (dataFile)
    {
        dataFile.open(FILE_NAME, fstream::app);

        while (!dataFile.eof())
        {
            Ships[count_ship] = new Ship;
            dataFile.getline(buff,S_SIZE);
            if (strlen(buff) != 0)
            {
                  if (step == 0)
                  {
                      Ships[count_ship]->name = new char[strlen(buff) + 1];
                      strcpy(Ships[count_ship]->name, buff);
                      cout << Ships[count_ship]->name << endl;
                  }
                  else if (step == 1)
                  {
                      Ships[count_ship]->registry = atoi(buff);
                  }
                  else if (step == 2)
                  {
                      Ships[count_ship]->type = new char[strlen(buff) + 1];
                      strcpy(Ships[count_ship]->type, buff);
                  }
                  else if (step == 3)
                  {
                      Ships[count_ship]->position = new char[strlen(buff) + 1];
                      strcpy(Ships[count_ship]->position, buff);
                  }
                  else if (step == 4)
                  {
                      Ships[count_ship]->condition = new char[strlen(buff) + 1];
                      strcpy(Ships[count_ship]->condition, buff);
                  }
                  else if (step == 5)
                  {
                      Ships[count_ship]->captain = new char[strlen(buff) + 1];
                      strcpy(Ships[count_ship]->captain, buff);
                  }
            }

            if (step > 4)
            {
               step = 0;
               count_ship++;
            }
            else
               step++;
        }
        dataFile.close();
    }
    else cout << " Input file doesn't exists!" << endl;
}

Starfleet::~Starfleet()//a Starfleet destructor
{
    for (int i = 0; i < count_ship; i++)
    {
        if (Ships[i] != NULL) //delete memory that has been allocated.
        {
            delete[] Ships[i]->name;
            delete[] Ships[i]->captain;
            delete[] Ships[i]->condition;
            delete[] Ships[i]->position;
            delete[] Ships[i]->type;
        }
    }
}

void Starfleet::display_All_Fleet()
{
    if (count_ship != 0)
    {
        cout << endl;
        cout << "The Starfleet is contain next ships: " << endl;
        cout << " ---------------------------------------------------------------------------" << endl;
        cout << "|    Name   | Registry |    Type    |    Position    | Condition|  Captain  |  " << endl;
        cout << " ---------------------------------------------------------------------------" << endl;

        for (int i = 0; i < count_ship; i++)
        {
            cout << "| " << setw(10) << Ships[i]->name << "|";
            cout << setw(10) << Ships[i]->registry << "|";
            cout << setw(12) << Ships[i]->type << "|";
            cout << setw(16) << Ships[i]->position << "|";
            cout << setw(11) << Ships[i]->condition << "|";
            cout << setw(10) << Ships[i]->captain << "|" << endl;
        }
        cout << " ---------------------------------------------------------------------------" << endl;
    }
    else
        cout << "The Starfleet is empty!!" << endl;
}

void Starfleet::add_Ship()
{
    //temporary variables
    char tempName[S_SIZE];
    char tempType[S_SIZE];
    char tempPosition[S_SIZE];
    char tempCondition[S_SIZE];
    char tempCaptain[S_SIZE];

    count_ship++;
    ofstream  output_File(FILE_NAME, ios::app);
    Ships[count_ship] = new Ship;

    cout << "What is the name of the ship? ";
    cin.clear();
    cin.sync();
    cin.get(tempName, S_SIZE);
    Ships[count_ship]->name = new char[strlen(tempName) + 1];
    strcpy(Ships[count_ship]->name, tempName);
    output_File << Ships[count_ship]->name << endl;

    cout << "What is the registry of the ship? " ;
    cin.clear();
    cin.sync();
    cin >> Ships[count_ship]->registry;
    output_File << Ships[count_ship]->registry << endl;

    cout << "What is the type of the ship? ";
    cin.clear();
    cin.sync();
    cin.get(tempType, S_SIZE);
    Ships[count_ship]->type = new char[strlen(tempType) + 1];
    strcpy(Ships[count_ship]->type, tempType);
    output_File << Ships[count_ship]->type << endl;

    cout << "What is the position of the ship? " ;
    cin.clear();
    cin.sync();
    cin.get(tempPosition, S_SIZE);
    Ships[count_ship]->position = new char[strlen(tempPosition) + 1];
    strcpy(Ships[count_ship]->position, tempPosition);
    output_File << Ships[count_ship]->position << endl;

    cout << "What is the condition of the ship? ";
    cin.clear();
    cin.sync();
    cin.get(tempCondition, S_SIZE);
    Ships[count_ship]->condition = new char[strlen(tempCondition) + 1];
    strcpy(Ships[count_ship]->condition, tempCondition);
    output_File << Ships[count_ship]->condition << endl;

    cout << "Who is the captain of the ship? " ;
    cin.clear();
    cin.sync();
    cin.get(tempCaptain, S_SIZE);
    Ships[count_ship]->captain = new char[strlen(tempCaptain) + 1];
    strcpy(Ships[count_ship]->captain, tempCaptain);
    output_File << Ships[count_ship]->captain << endl;

    output_File.close();
    cout << "The new ship succefully added to the Starfleet!" << endl;
}

bool Starfleet::find_Ship(int reg_numb_ship)
{
    int i;
    bool is_find = false;

    for (i = 0; i < count_ship; i++)
    {
        cout << Ships[i]->registry << endl;
        if (Ships[i]->registry == reg_numb_ship)
        {
            cout << endl;
            cout << "Was found next ship with registry number " << reg_numb_ship << ": " << endl;
            cout << " ----------------------------------------------------------------------------" << endl;
            cout << "|    Name   | Registry |    Type    |    Position    | Condition |  Captain  |  " << endl;
            cout << " ----------------------------------------------------------------------------" << endl;
            cout << "| " << setw(10) << Ships[i]->name << "|";
            cout << setw(10) << Ships[i]->registry << "|";
            cout << setw(12) << Ships[i]->type << "|";
            cout << setw(16) << Ships[i]->position << "|";
            cout << setw(11) << Ships[i]->condition << "|";
            cout << setw(10) << Ships[i]->captain << "|" << endl;
            cout << " ----------------------------------------------------------------------------" << endl;

            is_find = true;
        }      
    }

    return is_find;
}

//assuming names are unique

#include <iostream>
#include <string>
#include "NewFamilyTree_lib/Person.h"


using namespace std;

void PrintHelp () { //Function that prints valid commands
    cout << "Please input command, each command has name and a corresponding number." << endl;
    cout << "Valid commands are" << endl;
    cout << "ADD or 1 to add a child to the active person" << endl;
    cout << "CHOOSE ACTIVE PERSON or 2 to select a new active person" << endl;
    cout << "EDIT or 3 to change the values of the active person" << endl;
    cout << "DELETE or 4 to delete active person and any children, and their children" << endl;
    cout << "PRINT or 5 to print family in generational order" << endl;
    cout << "PRINT2 or 6 to print family tree by family with last generation first  " << endl;
    cout << "HELP or 7 to print valid commands" << endl;
    cout << "EXIT or 8 to exit the program" << endl << endl;
}

int main(){
    cout << "Family tree" << endl;
    cout << "This is a general tree where with different commands you can create People and add children to a person of your choosing "  << endl;
    cout << "The first step is creating the Root ancestor" << endl;
    // Create the ancestor
    string Commando, sFirstName, sLastName, sGender, sBirthYear, sDeathYear;

    cout << "First name: ";
    getline(cin, sFirstName);

    cout << "Last name: ";
    getline(cin, sLastName);

    cout << "Gender: ";
    getline(cin, sGender);

    cout << "Year of birth: ";
    getline (cin, sBirthYear);

    cout << "Year of death: ";
    getline (cin, sDeathYear);

    cout << endl << "you entered " << endl;
    cout << "First name = " << sFirstName << endl;
    cout << "Last name =  " << sLastName << endl;
    cout << "Gender = " << sGender << endl;
    cout << "Year of birth = " << sBirthYear << endl;
    cout << "Year of death = " << sDeathYear << endl;

    Person NewPerson = Person(sFirstName, sLastName, sGender, sBirthYear, sDeathYear);

    Person* pFamilyTree = new Person(sFirstName, sLastName,sGender,sBirthYear,sDeathYear);
    Person* pActivePerson = pFamilyTree;

    // Now we have created our tree and the root node - ready to accept commands

    cout << "Active person is" << endl;
    cout << pActivePerson->printPerson() << endl << endl;

    PrintHelp();
    string Command;

    while ((Command != "EXIT") && (Command != "8")) {
        cout << "Type HELP or 7 to list valid commands" << endl;
        cout << "Command: ";
        getline(cin, Command);

        if ((Command == "ADD") || (Command == "1")) {

            cout << "First name: ";

            getline(cin, sFirstName);

            cout << "Last name: ";
            getline(cin, sLastName);

            cout << "Gender: ";
            getline(cin, sGender);

            cout << "Year of birth: ";
            getline(cin, sBirthYear);

            cout << "Year of death: ";
            getline(cin, sDeathYear);

            cout << endl << "You entered " << endl;
            cout << "First name = " << sFirstName << endl;
            cout << "Last name =  " << sLastName << endl;
            cout << "Gender = " << sGender << endl;
            cout << "Year of birth = " << sBirthYear << endl;
            cout << "Year of death = " << sDeathYear << endl << endl;

            pActivePerson->addChild(sFirstName, sLastName, sGender, sBirthYear, sDeathYear);
            pActivePerson->printPerson();

        } else if ((Command == "CHOOSE ACTIVE PERSON") || (Command == "2")) {
            string sParentFirstName, sParentLastName;
            cout << "Parent First Name: ";
            cin >> sParentFirstName;
            cout << "Parent Last Name: ";
            cin >> sParentLastName;
            Person* pFoundPerson = nullptr;
            pFamilyTree->findPerson(sParentFirstName, sParentLastName, pFoundPerson);

            if (pFoundPerson != nullptr) {
                pActivePerson = pFoundPerson;
                cout << "Active person is:" << endl;
                cout << *pActivePerson << endl;
            } else {
                cout << "Parent not found" << endl;
            }

        } else if ((Command == "EDIT") || (Command == "3")) {
            pActivePerson->editPerson();
        } else if ((Command == "DELETE") || (Command == "4")) {
            if (pActivePerson->getParent()) { // Will return NULL (ie false) preventing deletion of root node
                Person *pNewActivePerson = pActivePerson->getParent();
                pActivePerson->removePerson();
                delete pActivePerson;
                pActivePerson = pNewActivePerson;

                cout << "New active person is now " << *pActivePerson << endl;
            } else {
                cout << "You cannot delete the ancestor" << endl;
            }

        } else if ((Command == "PRINT") || (Command == "5")) {
            cout << "Family tree printed by generation "<< endl;
            pFamilyTree->depthFirstTraverse();

        } else if ((Command == "PRINT2") || (Command == "6")) {
            cout << "Family tree is printed by family with last generation first" << endl;
            pFamilyTree->traverse();

        } else if ((Command == "HELP") || (Command == "7")) {
            PrintHelp();
        }
    }
    delete pFamilyTree;
    return 0;
}
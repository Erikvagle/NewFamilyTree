#include <string>
#include <iostream>
#include <vector>

class Person {
private:
    std::string firstname_;
    std::string lastname_;
    std::string gender_;
    std::string birthYear_;
    std::string deathYear_;
    std::vector<Person *> children; //create vector of pointers children
    Person* Parent_;
public:
    Person(
            std::string firstname,
            std::string lastname,
            std::string gender,
            std::string birthYear,
            std::string deathYear,
            Person* Parent= nullptr);
    ~Person();

    void traverse(int nIndent = 0);
    void depthFirstTraverse(int nIndent = 0);
    std::string getFirstName();
    std::string getLastName();
    std::string getGender();
    Person* getParent();
    std::string getBirthYear();
    std::string getDeathYear();

    void setFirstName(std::string FirstName);
    void setLastName(std::string LastName);
    void setGender(std::string Gender);
    void setBirthYear(std::string BirthYear);
    void setDeathYear(std::string DeathYear);
    void setParent(Person* newParent);

    //declare function to make child
    void addChild(std::string firstname,std::string lastname, std::string gender, std::string birthYear, std::string deathYear);
    std::string printPerson();
    void findPerson (std::string Firstname, std::string Lastname, Person* &pReturnPerson);
    void removePerson ();
    void editPerson();
    friend std::ostream &operator<<(std::ostream &os, const Person &c);

};
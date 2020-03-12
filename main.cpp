
#include <iostream>
#include <string>

class School
{
protected:
    int avgGrade;
    int capacity;
    std::string type;

    School(int givenCapacity, int givenAvgGrade, std::string givenType )
            : capacity(givenCapacity), avgGrade(givenAvgGrade), type(givenType)
    {}


public:
    int getAvgGrade()
    {
        return avgGrade;
    }

    int getCapacity()
    {
        return capacity;
    }

    std::string getType()
    {
        return type;
    }
};

class ScienceHighSchool : public School
{
public:
    ScienceHighSchool()
            : School(60, 95, "Science HighSchool")
    {}
};

class HumanitiesHighSchool : public School
{
public:
    HumanitiesHighSchool()
            : School(62, 90, "Humanities HighSchool")
    {}
};

class PrivateHighSchool : public School
{
public:
    PrivateHighSchool()
            : School(100, 85, "Private HighSchool")
    {}
};


class PrivatePrimarySchool : public School
{
public:
    PrivatePrimarySchool()
            : School(102, 93, "Private Primary School")
    {}
};

class SciencePrimarySchool : public School
{
public:
    SciencePrimarySchool()
            : School(200, 97, "Science Primary HighSchool")
    {}
};

class HumanitiesPrimarySchool : public School
{
public:
    HumanitiesPrimarySchool()
            : School(300, 95, "Humanities Primary School")
    {}
};




class SchoolFactory
{
public:
    virtual School* getScienceSchool() = 0;
    virtual School* getHumanitiesSchool() = 0;
    virtual School* getPrivateSchool() = 0;

};

class HighSchoolFactory : public SchoolFactory
{
public:
    School* getScienceSchool()
    {
        return new ScienceHighSchool();
    }

    School* getHumanitiesSchool()
    {
        return new HumanitiesHighSchool();
    }

    School* getPrivateSchool()
    {
        return new PrivateHighSchool();
    }
};

class PrimarySchoolFactory : public SchoolFactory
{
public:
    School* getScienceSchool()
    {
        return new SciencePrimarySchool();
    }

    School* getHumanitiesSchool()
    {
        return new HumanitiesPrimarySchool();
    }

    School* getPrivateSchool()
    {
        return new PrivatePrimarySchool();
    }
};

int main()
{
    SchoolFactory* factory = 0;
    std::string message="Which one do you want?\n1.HighSchool\n2.PrimarySchool";
    std::cout << message;
    std::string answer;
    std::cin >> answer;

    bool done=false;
    while (!done) {
        try {
            int selection = std::stoi(answer);
            switch (selection) {
                case 1:
                    factory = new HighSchoolFactory();
                    done=true;
                    break;
                case 2:
                    factory = new PrimarySchoolFactory();
                    done=true;
                    break;
                default:
                    std::cout << "Wrong input";
            }
        } catch (std::exception &err) {
            done=false;
        }
    }

    message="Which one do you want?\n1.ScienceSchool\n2.HumanitiesSchool\n3.PrivateSchool";
    std::cout << message;
    std::cin >> answer;

    School* school;
    done=false;
    while (!done) {
        try {
            int selection = std::stoi(answer);
            switch (selection) {
                case 1:
                    school = factory->getScienceSchool();
                    done=true;
                    break;
                case 2:
                    school = factory->getHumanitiesSchool();
                    done=true;
                    break;
                case 3:
                    school = factory->getPrivateSchool();
                    done=true;
                    break;
                default:
                    std::cout << "Wrong input";
            }
        } catch (std::exception &err) {
            done=false;
        }
    }

    std::cout<<"You choose a(n)"<<school->getType()<<"\n";
    std::cout<<"Capacity: "<<school->getCapacity()<<"\n";
    std::cout<<"Avg Grades: "<<school->getAvgGrade();
}

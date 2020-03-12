
#include <iostream>
#include <string>

/**
 * Abstract Product
 */
class School
{
protected:
    int avgGrade;
    int capacity;
    std::string type;

    /***
    *   Constructor for School
    * @param givenCapacity Capacity of the school
    * @param givenAvgGrade Average grade of the students of the school
    * @param givenType Type of school
    */
    School(int givenCapacity, int givenAvgGrade, std::string givenType )
            : capacity(givenCapacity), avgGrade(givenAvgGrade), type(givenType)
    {}


public:
    /**
     * Returns average grade on the school
     * @return average grade of the students
     */
    int getAvgGrade()
    {
        return avgGrade;
    }
    /**
    * Returns maximun student capacity
    * @return Maximun student capacity
    */
    int getCapacity()
    {
        return capacity;
    }

    /**
     * Returns type of the school
     * @return Type of the school
     */
    std::string getType()
    {
        return type;
    }
};

/**
 * Concrete Science HighSchool product
 */
class ScienceHighSchool : public School
{
public:
    ScienceHighSchool()
            : School(60, 95, "Science HighSchool")
    {}
};

/**
 * Concrete Humanities HighSchool product
 */
class HumanitiesHighSchool : public School
{
public:
    HumanitiesHighSchool()
            : School(62, 90, "Humanities HighSchool")
    {}
};

/**
 * Concrete Private HighSchool product
 */
class PrivateHighSchool : public School
{
public:
    PrivateHighSchool()
            : School(100, 85, "Private HighSchool")
    {}
};

/**
 * Concrete Private Primary product
 */
class PrivatePrimarySchool : public School
{
public:
    PrivatePrimarySchool()
            : School(102, 93, "Private Primary School")
    {}
};

/**
 * Concrete Science Primary product
 */
class SciencePrimarySchool : public School
{
public:
    SciencePrimarySchool()
            : School(200, 97, "Science Primary HighSchool")
    {}
};

/**
 * Concrete Humanities Primary product
 */
class HumanitiesPrimarySchool : public School
{
public:
    HumanitiesPrimarySchool()
            : School(300, 95, "Humanities Primary School")
    {}
};



/**
 * Abstract Factory
 */
class SchoolFactory
{
public:
    virtual School* getScienceSchool() = 0;
    virtual School* getHumanitiesSchool() = 0;
    virtual School* getPrivateSchool() = 0;

};

/**
 * Concrete HighSchool Factory
 */
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

/**
 * Concrete Primary School Factory
 */
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

/**
 * Ask user to specify the type of factory and of school wanted, then creates it and shows its properties.
 * @return
 */
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

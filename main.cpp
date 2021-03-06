
#include <iostream>
#include <string>

/**
 * Abstract class used as parent for the three Abstract Products
 * but is not part of the pattern, and is used because of being useful
 * on this particular example
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
 * Abstract  Science School product
 */
class ScienceSchool : public School
{
public:
    ScienceSchool(int givenCapacity, std::string type)
            : School(givenCapacity, 95, type)
    {}
};

/**
 * Abstract Humanities School product
 */
class HumanitiesSchool : public School
{
public:
    HumanitiesSchool(int givenCapacity, std::string type)
            : School(givenCapacity, 90, type)
    {}
};

/**
 * Abstract  Primary School product
 */
class PrivateSchool : public School
{
public:
    PrivateSchool(int givenCapacity, std::string type)
            : School(givenCapacity, 93, type)
    {}
};


/**
 * Concrete Science HighSchool product
 */
class ScienceHighSchool : public ScienceSchool
{
public:
    ScienceHighSchool()
            : ScienceSchool(60, "Science High School")
    {}
};

/**
 * Concrete Humanities HighSchool product
 */
class HumanitiesHighSchool : public HumanitiesSchool
{
public:
    HumanitiesHighSchool()
            : HumanitiesSchool(62, "Humanities HighSchool")
    {}
};

/**
 * Concrete Private HighSchool product
 */
class PrivateHighSchool : public PrivateSchool
{
public:
    PrivateHighSchool()
            : PrivateSchool(200, "Private HighSchool")
    {}
};

/**
 * Concrete Private Primary product
 */
class PrivatePrimarySchool : public PrivateSchool
{
public:
    PrivatePrimarySchool()
            : PrivateSchool(210, "Private Primary School")
    {}
};

/**
 * Concrete Science Primary product
 */
class SciencePrimarySchool : public ScienceSchool
{
public:
    SciencePrimarySchool()
            : ScienceSchool(200, "Science Primary School")
    {}
};

/**
 * Concrete Humanities Primary product
 */
class HumanitiesPrimarySchool : public HumanitiesSchool
{
public:
    HumanitiesPrimarySchool()
            : HumanitiesSchool(300, "Humanities Primary School")
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
    std::string message="Which one do you want?\n1.HighSchool\n2.PrimarySchool\n";
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

    message="Which one do you want?\n1.ScienceSchool\n2.HumanitiesSchool\n3.PrivateSchool\n";
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

    std::cout<<"You choose a(n) "<<school->getType()<<"\n";
    std::cout<<"Capacity: "<<school->getCapacity()<<"\n";
    std::cout<<"Avg Grades: "<<school->getAvgGrade();
}

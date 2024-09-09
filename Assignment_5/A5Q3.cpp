
 /*Implement following classes. Test all functionalities in main() of each created class. Note that 
employee is inherited into manager and salesman.
*/
 
#include <iostream>
using namespace std;

class Employee
{
private:
    int empid;
    double salary;

public:
    Employee()
    {
        empid = 0;
        salary = 15000.0;
    }
    Employee(int id, double salary)
    {
        this->empid = id;
        this->salary = salary;
    }
    void setId(int id)
    {
        this->empid = id;
    }
    int getId()
    {
        return empid;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter the id: ";
        cin >> empid;
        cout << "Enter the salary: ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id: " << empid << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter Manager Details" << endl;
        Employee::accept();
        cout << "Enter the bonus: ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Manager Details" << endl;
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }

public:
    Manager()
    {
        bonus = 10000.0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return bonus;
    }
    virtual void accept()
    {
        cout << "Enter Manager Details" << endl;
        Employee::accept();
        cout << "Enter the bonus: ";
        cin >> bonus;
    }
    virtual void display()
    {
        cout << "Manager Details" << endl;
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};
class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter Salesman Details" << endl;
        Employee::accept();
        cout << "Enter the commission: ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Salesman Details" << endl;
        Employee::display();
        cout << "Bonus: " << commission << endl;
    }

public:
    Salesman()
    {
        commission = 1000.0;
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }
    void setCommission(double commission)
    {
        this->commission = commission;
    }
    double getCommission()
    {
        return commission;
    }
    virtual void accept()
    {
        cout << "Enter Salesman Details" << endl;
        Employee::accept();
        cout << "Enter the commission: ";
        cin >> commission;
    }
    virtual void display()
    {
        cout << "Salesman Details" << endl;
        Employee::display();
        cout << "Bonus: " << commission << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus), Salesman(id, salary, commission) {}
    void accept()
    {
        cout << "Enter Sales Manager Details" << endl;
        Manager::accept();
        Salesman::acceptSalesman();
    }
    void display()
    {
        cout << "Sales Manager Details" << endl;
        Manager::display();
        Salesman::displaySalesman();
    }
};

int main()
{
    SalesManager *salesManager = new SalesManager();
    salesManager->accept();
    salesManager->display();

    Manager *manager = new Manager();
    manager->accept();
    manager->display();

    Salesman *salesman = new Salesman();
    salesman->accept();
    salesman->display();
    return 0;
}
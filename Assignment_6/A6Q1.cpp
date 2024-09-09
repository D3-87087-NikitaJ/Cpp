/*
 * Provide menu driven code for the functionalities:
 * 1. Accept Employee
 *  a. Accept Manager
 *  b. Accept Salesman
 *  c. Accept SalesManager
 * 2. Display the count of all employees with respect to designation
 * 3. Display All Managers
 * 4. Display All Salesman
 * 5. Display All SalesManagers
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
int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Accept Manager" << endl;
    cout << "2. Accept Salesman" << endl;
    cout << "3. Accept SalesManager" << endl;
    cout << "4. Display the count of all employees" << endl;
    cout << "5. Display All Managers" << endl;
    cout << "6. Display All Salesman" << endl;
    cout << "7. Display All SAlesmanManager" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int index = 0;
    int num;
    cout << "Enter the no of Employees: ";
    cin >> num;
    Employee *arr[num];
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {

            if (index < num)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                index++;
            }
            break;
        }
        case 2:
        {
            if (index < num)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
            }
            break;
        case 3:
            if (index < num)
            {
                arr[index] = new SalesManager();
                arr[index]->accept();
                index++;
            }
            break;
        }
        case 4:
        {
            int m = 0;
            int s = 0;
            int sm = 0;

            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Manager).name())
                {
                    m++;
                }
                else if (typeid(*arr[i]).name() == typeid(Salesman).name())
                {
                    s++;
                }

                else if (typeid(*arr[i]).name() == typeid(SalesManager).name())
                {
                    sm++;
                }
            }
            cout << "no employee:" << index << endl;
            cout << "no manager:" << m << endl;
            cout << "no salesman:" << s << endl;
            cout << "no salesmanager:" << sm << endl;

            break;
        }
        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Manager).name())
                {
                    cout << "-------------------" << endl;
                    arr[i]->display();
                    cout << "-------------------" << endl;
                }
            }
            break;
        }
        case 6:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Salesman).name())
                {
                    cout << "-------------------" << endl;
                    arr[i]->display();
                    cout << "-------------------" << endl;
                }
            }
            break;
        }
        case 7:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]).name() == typeid(SalesManager).name())
                {
                    cout << "-------------------" << endl;
                    arr[i]->display();
                    cout << "-------------------" << endl;
                }
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
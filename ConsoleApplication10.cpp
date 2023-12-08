#include<iostream>
using namespace std;

class Contact
{
    char* FullName = new char[100];
    int HomePhone,WorkPhone,MobilePhone;
    int age;
    char* sex;

public:
    Contact()
    {
        FullName = nullptr;
        sex = nullptr;
        age = 0;
        HomePhone = 0;
        WorkPhone = 0;
        MobilePhone = 0;
    }

    Contact(const char* Fl_Name,const char* Sex, int Age,int HmPhone,int WrPhone,int MbPhone) 
    {
        FullName = new char[strlen(Fl_Name) + 1];
        sex = new char[strlen(Sex) + 1];
        strcpy_s(FullName, strlen(Fl_Name) + 1, Fl_Name);
        strcpy_s(sex, strlen(Sex) + 1, Sex);
        
        age = Age;
        HomePhone = HmPhone;
        WorkPhone = WrPhone;
        MobilePhone = MbPhone;
    }

    void Set_FullName(const char* Fl_Name)
    {
        if (FullName != nullptr)
            delete[] FullName;
        FullName = new char[strlen(Fl_Name) + 1];
        strcpy_s(FullName, strlen(Fl_Name) + 1, Fl_Name);
    }
    void Set_AdditInfo(const char* Sex, int Age)
    {
        if (sex != nullptr)
            delete[] sex;
        sex = new char[strlen(Sex) + 1];
        strcpy_s(sex, strlen(Sex) + 1, Sex);
        age = Age;
    }
    void Set_FhoneNumber(int HmPhone, int WrPhone, int MbPhone) 
    {
        HomePhone = HmPhone;
        WorkPhone = WrPhone;
        MobilePhone = MbPhone;
    }

    
    void Output()
    {
        if (FullName == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "Full Name: " << FullName << "\n";
        cout << "Sex: " << sex << "\n";
        cout << "Age: " << age << "\n\n";
        cout << "Home Phone: " << HomePhone << "\n";
        cout << "Work Phone: " << WorkPhone << "\n";
        cout << "Mobile Phone: " << MobilePhone << "\n\n\n";
    }
    ~Contact()
    {
        cout << "Destruct\n";
        delete[] FullName;
        delete[] sex;
    }
};
void iteration(Contact *arr)
{
    for (int i = 0; i < 3; i++)
    {
       arr[i].Output();
    }
}

int main()
{
    Contact obj("Arsen Sevastianov Ruslanovich","Male",16,34592104,54314353,690321324);
    obj.Output();


   
    Contact* mas = new Contact[3]
    {
        {"Konstanting Ghenadii Dmitrievich ","Male",34,3542134,7890753,678534566},
        {"Arsen Sevastianov Ruslanovich","Male",16,34592104,54314353,690321324},
        {"Anastasia Maksimenko Alekseevna","Female", 56,555676543,678643356,76543356}
    };
    iteration(mas);
    delete[] mas;
}




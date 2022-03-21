#include <iostream>
#include <vector>

///////////////////////////////////////////////////////////////////

class MyInterface
{
public:
  // Empty virtual destructor for proper cleanup
  virtual ~MyInterface() {}

  virtual void Method1() = 0;
  virtual void Method2() = 0;
};


class MyAbstractClass
{
public:
  virtual ~MyAbstractClass();

  virtual void Method1();
  virtual void Method2();
  void Method3();

  virtual void Method4() = 0; // make MyAbstractClass not instantiable
};

//////////////////////////////////////////////////////////////////

using namespace std;
class Stooge
{
public:
    static Stooge *make_stooge(int choice);
    virtual void slap_stick() = 0;
    virtual ~Stooge() {
        cout<<"Stooge destrued \n";
    }

    Stooge() {
        cout<<"Stooge contructed \n";
    }
};

class Larry : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Larry: poke eyes \n";
    }
};

class Moe : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Moe: slap head \n";
    }
};

class Curly : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Curly: suffer abuse \n";
    }
};

Stooge *Stooge::make_stooge(int choice)
{
    if (choice == 1)
    {
        return new Larry;
    }
    else if (choice == 2)
    {
        return new Moe;
    }
    else
    {
        return new Curly;
    }
}

// int main()
// {
//     vector<Stooge *> roles;
//     int choice;

//     while (true)
//     {
//         cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
//         cin >> choice;

//         if (choice == 0)
//         {
//             break;
//         }
//         else if (choice == 1)
//         {
//             roles.push_back(new Larry);
//         }
//         else if (choice == 2)
//         {
//             roles.push_back(new Moe);
//         }
//         else
//         {
//             roles.push_back(new Curly);
//         }
//     }
//     for (int i = 0; i < roles.size(); i++)
//     {
//         roles[i]->slap_stick();
//     }

//     for (int i = 0; i < roles.size(); i++)
//     {
//         delete roles[i];
//     }
// }

int main()
{
    vector<Stooge *> roles;
    int choice;

    while (true)
    {
        cout << "Larry(1) Moe(2) Curly(3) Go(0)";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        else
        {
            roles.push_back(Stooge::make_stooge(choice));
        }
    }
    for (int i = 0; i < roles.size(); i++)
    {
        roles[i]->slap_stick();
    }

    for (int i = 0; i < roles.size(); i++)
    {
        delete roles[i];
    }
}
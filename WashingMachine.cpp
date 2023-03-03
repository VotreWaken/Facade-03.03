#include <iostream>
#include <string>


// Wash Action
class wash
{
public:
    void washingClothes()
    {
        std::cout << "Washing clothes\n";
    }
};

// Rinsing Action
class rinsing
{
public:
    void rinsingClothes()
    {
        std::cout << "Rinsing clothes\n";
    }
};

// Wring Out Action
class wringOut
{
public:
    void wringOutClotches()
    {
        std::cout << "Wring Out clothes\n";
    }
    void finishWringOut()
    {
        std::cout << "Wring Out clothes Finish\n";
    }
};

// Washing Machine Facade 
class washingMachine
{
    wash washClotches_;
    rinsing rinsClotches_;
    wringOut wringOutClotches_;
public:
    washingMachine(wash te, rinsing compiler, wringOut clr)
    {
        washClotches_ = te;
        compiler = compiler;
        clr = clr;
    }
    void Start()
    {
        washClotches_.washingClothes();
        rinsClotches_.rinsingClothes();
        wringOutClotches_.wringOutClotches();
    }
    void Stop()
    {
        wringOutClotches_.finishWringOut();
    }
};

// Washing Machine Interface
class washingMachineUser
{
public:
    void createWashingMachine(washingMachine facade)
    {
        facade.Start();
        facade.Stop();
    }
};

int main()
{
    // Action Objects
    wash washObject;
    rinsing rinsingObject;
    wringOut wringOutObject;

    // Washing Machine
    washingMachine actions(washObject, rinsingObject, wringOutObject);

    // User Interface
    washingMachineUser user;
    user.createWashingMachine(actions);
}


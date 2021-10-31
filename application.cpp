#include "application.h"
#include "database_templates.cpp"

#include<bits/stdc++.h>

using namespace std;

Application::Application(){
    try{
        this->db = new Database();
    }
    catch(Error e){
        cout<<e.getMessage();
        exit(EXIT_FAILURE);
    }
}

void Application::gotoXY(int x, int y) const{
    printf("%c[%d;%df",0x1B,y,x);
}

void Application::renderMenu(){
    char choice = 1;
    while(true){
        system("cls");
        gotoXY(25,4);
        cout<<"Select Any option from below";
        gotoXY(25,5);
        cout<<"1. Add New Vehicle";
        gotoXY(25,6);
        cout<<"2. View Vehicle Details";
        gotoXY(25,7);
        cout<<"3. Edit Vehicle Details";
        gotoXY(25,8);
        cout<<"4. Add New User";
        gotoXY(25,9);
        cout<<"5. Add New Trip";
        gotoXY(25,10);
        cout<<"6. View Trip";
        gotoXY(25,11);
        cout<<"7. Start Trip";
        gotoXY(25,12);
        cout<<"8. Complete Trip";
        gotoXY(25,13);
        cout<<"9. Exit";

        gotoXY(30,15);
        cout<<"Enter your Choice: ";
        gotoXY(50,15);
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch(choice){
            case '1': 
                this->renderAddNewVehicleMenu();
                break;
            case '2': 
                this->renderViewVehicleMenu();
                break;
            case '3': 
                this->renderEditVehicleMenu();
                break;
            case '4':
                this->renderAddNewUserMenu();
                break;
            case '5':
                this->renderAddNewTripMenu();
                break;
            case '6':
                this->renderViewTripMenu();
                break;
            case '7':
                this->renderStartTripMenu();
                break;
            case '8':
                this->renderCompleteTripMenu();
            case '9':
                this->cleanMemory();
                system("cls");
                exit(EXIT_SUCCESS);
                break;
            default: 
                this->cleanMemory();
                system("cls");
                exit(EXIT_SUCCESS);
                break;
        }
    }
}

void Application::renderAddNewVehicleMenu() const{
    string regNo,companyName;
    int vehicleType,seat;
    double price;
    string pucExpirationDate;
    system("cls");
    gotoXY(0,1);
    cout<<"Enter Details of Vehicle:";
    gotoXY(0,3);
    cout<<"Enter Vehicle Registration Number ";
    getline(cin,regNo);
    cout<<"Enter Vehicle type:";
    gotoXY(0,5);
    cout<<"1. Bike 2. Car 3. Towera";
    gotoXY(0,6);
    cin>>vehicleType;
    cout<<"Enter number of seats: ";
    cin>>seat;
    cout<<"Enter name of company: ";
    getline(cin,companyName);
    cout<<"Enter Price per KM: ";
    cin>>price;
    cout<<"Enter PUC Expiration Date (dd/mm/yyyy): ";
    cin>>pucExpirationDate;

    Vehicle *vehicle;
    try{
        vehicle = 
        new Vehicle(regNo,VehicleType(vehicleType),
                    seat,companyName,price,Date(pucExpirationDate));
        this->db->addNewRecord(vehicle);
        stringstream ss;
        ss<<"Vehicle id: "<<vehicle->getRecord();
        showDialog("Vehicle Added Successfully",ss.str());
    }
    catch(Error e){
        showDialog(e.getMessage());
        delete vehicle; 
    }
}

void Application::renderViewVehicleMenu() const{
    string regNo;
    system("cls");
    gotoXY(0,1);
    cout<<"Enter registration number of Vehicle: ";
    getline(cin,regNo);
    try{
        auto vehicle = this->db->getVehicle(regNo);
        vehicle->display();
    }
    catch(Error e){
        this->showDialog(e.getMessage());
    }
}

void Application::renderEditVehicleMenu() const{
    string regNo,price;
    system("cls");
    gotoXY(0,1);
    cout<<"Enter registration number of vehicle you want to edit:";
    getline(cin,regNo);
    try{
        auto vehicle = this->db->getVehicle(regNo);
        Vehicle *newVehicle = new Vehicle(*vehicle);
        vehicle->display();
        cout<<"Enter new price per KM";
        getline(cin,price);
        if(price!=""){
            newVehicle->setPricePerKm(stod(price));    
            this->db->updateRecord(newVehicle);

            this->showDialog("Vehicle updated Successfully"); 
        }
        delete newVehicle;
    }
    catch(Error e){
        this->showDialog(e.getMessage());
    }
}

void Application::renderAddNewUserMenu() const{
    string name,contact,email;
    system("cls");
    gotoXY(0,1);
    cout<<"Enter details of User: ";
    gotoXY(0,2);
    cout<<"Enter Name of User: ";
    getline(cin,name);
    cout<<"Enter Contact number of the user: ";
    getline(cin,contact);
    cout<<"Enter Email of the user: ";
    getline(cin,email);
    try{
        User *user = new User(name,contact,email);
        this->db->addNewRecord(user);
        stringstream ss;
        ss<<"User id: "<<user->getRecord();
        showDialog("User Added succesfully: ",ss.str());
        delete user;
    }
    catch(Error e){
        showDialog(e.getMessage());
    }   
}

void Application::renderAddNewTripMenu() const{
    system("cls");
    gotoXY(0,1);
    string contact,startDate,endDate;
    int vehicleType;
    cout<<"Enter details of Trip: ";
    cout<<"Enter contact number of user: ";
    getline(cin,contact);
    cout<<"When should your trip start?(d/m/yyyy): ";
    getline(cin,startDate);
    cout<<"When should your trip end?(d/m/yyyy): ";
    getline(cin,endDate);
    cout
        <<"Enter Vehicle Type:\n"
        <<"1.Bike 2.Car 3.Towera\n";
    cin>>vehicleType;
        auto availableVehicles = 
            this->db->getVehicle(Date(startDate),
                                 Date(endDate),
                                 VehicleType(vehicleType));

        if(availableVehicles.size()==0){
            this->showDialog("No vehicles are free in given Date Range");
            return;
        }
        gotoXY(0,12);
        cout<<"Registration no. |"<<"Seats |"<<"Price per KM |"<<endl;
        for(auto vehicle: availableVehicles){
            s
        }




    
}
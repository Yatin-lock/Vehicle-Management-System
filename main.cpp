#include "application.h"
#include<iostream>

using namespace std;

int main(){
    char choice='n';
    Application *app = new Application();
    app->start();
    return 0;
}
#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <unordered_map>

void DisplayMenu();
void DisplayOptions();

/* DisplayMenu()
* Description - Displays the user menu prompting for a selection
* Parameters - None
* Returns - None
*/
void DisplayMenu() {
    std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "Welcome to Corner Grocer's Analytics Tool." << std::endl;
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "Please select from one of the following options:" << std::endl;
    std::cout << " 1. Search for item frequency\n 2. View Sales Count by Item\n 3. View Item Historgam\n 4. Exit Program" << std::endl;
    std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl;
    std::cout << std::setfill(' ');
}

void DisplayOptions() {
    std::cout << "\nPlease select from one of the following options:" << std::endl;
    std::cout << " 1. Search for item frequency\n 2. View Sales Count by Item\n 3. View Item Historgam\n 4. Exit Program" << std::endl;
}
#endif
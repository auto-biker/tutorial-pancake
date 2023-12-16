/* 
* Project Three.cpp 
* Author - Nick Colby
* Class - CS.210
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include "CustomFunctions.h"
#include "GroceryItem.h"

using namespace std;

void ReadFileContents(string filePath, unordered_map<string, int>& countList);
void WriteFileContents(const unordered_map<string, int>& map, string destinationFile);
void SearchAndPrint(const unordered_map<string, int>& map, const string& key);
void PrintAllItems(const unordered_map<string, int>& map);
void PrintHistogram(const std::unordered_map<string, int>& map);

int main()
{
    int userInput = 1;
    const string filePath = "GrocerInputFile.txt";
    const string outputFile = "Frequency.dat.txt";
    vector<string> groceryItems(1);
    unordered_map<string, int> itemCount;

    /* Read the contents from the specified input file */
    ReadFileContents(filePath, itemCount);
    
    /* // NOTE: Block reserved for future implementation of class instances
    for (auto i = itemCount.begin(); i != itemCount.end(); ++i) {

        // format a string
        string tempName = i->first;
        int tempCount = i->second;

        // create a class instance of the item
        //GroceryItem* tempName = new GroceryItem;
        //*tempName).SetItemCount(tempCount);
    }
    */
    /* Backs up the unordered_map object to the GrocerOutputFile */
    WriteFileContents(itemCount, outputFile);
    
    /* Displays the menu for the user. */
    DisplayMenu();
        
    /* Collects the user input and acts accordingly */
    while (userInput != 4) {
        cin >> userInput;

        if (userInput == 1) {
            string userSearchString;
            cout << "Enter a word to search for: " <<  endl;  
            cin >> userSearchString;
            SearchAndPrint(itemCount, userSearchString);
            DisplayOptions();
        }
        else if (userInput == 2) {
            PrintAllItems(itemCount);
            DisplayOptions();
        }
        else if (userInput == 3) {
            PrintHistogram(itemCount);
            DisplayOptions();
        }
        else if (userInput == 4) {
            cout << "Thank you for using the Corner Grocer's Analytics Tool. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Selection of " << userInput << " was not recognized" << endl;
            userInput = 4; 
            break;
        }
    }
  
    return 0;
}

/* ReadFileContents()
 *  Description - Reads contents from a given file and counts the numer 
 *  of occurences of each item and inputs them into an unordered map
 *  Parameters - 
 *     - string filePath - the filepath to read from
 *     - unordered_map<string, int> countList - the map of item occurences
 *  Returns - None
*/
void ReadFileContents(string filePath, unordered_map<string, int>& countList) {
    // declare variables
    ifstream inFs;
    string fileItem;
    // open the file
    inFs.open(filePath);
    // read the contents and update the unordered_map
    inFs >> fileItem;
    while (!inFs.fail()) {
        countList[fileItem]++;
        inFs >> fileItem;
    }
    if (!inFs.eof()) {
        cout << "Failure before reaching the end of the file" << endl;
    }
    // close the file
    inFs.close();
}

/* WriteFileContents()
 *  Description - writes a given string to a destination file followed by
 *    a new line. 
 *  Parameters -
 *     - string item - the string you want to write to the file
 *     - string destinationFile - the filepath of the destination file to write to
 *  Returns - None
*/
void WriteFileContents(const unordered_map<string, int>& map, string destinationFile) {
    ofstream outFS;
    outFS.open(destinationFile);
    if (!outFS.is_open()) {
        std::cout << "Error opening the file" << destinationFile << std::endl;
    }
    for (auto mapItem = map.begin(); mapItem != map.end(); ++mapItem) {
        outFS << mapItem->first << ": " << mapItem->second << std::endl;
    }
    outFS.close();
}

/* SearchAndPrint() 
 * Description - Prompts the user to enter a term to search for, takes
 * the user specified term and returns the key value pair with the matching
 * key, returns "<userinput> was not found" if key does not exist. 
 *
 * Parameters - const unordered_map<string, int> - the map to search passed
 * by reference. 
 *  - const string key - the search term entered by the user. 
 * 
 * Returns - None
*/
void SearchAndPrint(const unordered_map<string, int>& map, const string& key) {
    auto searchKey = map.find(key);
    if (searchKey != map.end()) {
        cout << searchKey->first << " : " << searchKey->second << endl;
    }
    else {
        cout << key << " was not found" << endl;
    }
}

/* PrintAllItems 
 * Description - Prints each key value pair in a specified map on the screen
 * 
 * Parameters - const unordered_map<string, int> the map to print
 *
 * Returns - None
*/
void PrintAllItems(const unordered_map<string, int>& map) {
    for (auto mapItem = map.begin(); mapItem != map.end(); ++mapItem) {
        cout << setw(13) << left << mapItem->first << " : ";
        cout << setw(3) << left << mapItem->second << endl;
    }
}
/* PrintHistogram 
 * Description - Prints each key value pair in a specified map on the screen. 
 * instead of the numerical value, a corresponding numer of asterisks is
 * shown on screen, one for each count. e.g. 4 = ****, 6 = ******
 *
 * Parameters - const unordered_map<string, int> the map to print
 *
 * Returns - None
*/
void PrintHistogram(const std::unordered_map<string, int>& map) {
    int i;
    for (auto mapItem = map.begin(); mapItem != map.end(); ++mapItem) {
        std::cout << std::setw(13) << mapItem->first << ": ";
        for (i = 0; i < mapItem->second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
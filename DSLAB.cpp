#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Node structure to hold language data
struct Node {
    string language;
    string family;
    string  branch;
    Node* next;
};

// Linked list class
class LanguageList {
private:
    Node* head;

public:
    // Constructor
    LanguageList() {
        head = nullptr;
    }

    // Function to add a new language to the list
    void addLanguage(string lang, string fam, string bra) {
        Node* newNode = new Node;
        newNode->language = lang;
        newNode->family = fam;
        newNode->branch = bra;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Language added successfully!" << endl;
    }

    // Function to perform linear search for a language
    bool searchLanguage(string lang) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->language == lang) {
                cout << "Searching.....\n\n";
                cout << "Language: " << temp->language << endl;
                cout << "Language Family: " << temp->family << endl;
                cout << "Language Branch: " << temp->branch << endl;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display all languages in the list
    void displayLanguages() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Languages in the list:\n" << endl;
        while (temp != nullptr) {
            cout << "Language: " << temp->language << endl;
            cout << "Language Family: " << temp->family << endl;
            cout << "Language Branch: " << temp->branch << endl;
            cout << "\n\n";
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~LanguageList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LanguageList languages;
    int choice;
    string lang, fam, bra;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Language\n";
        cout << "2. Search Language\n";
        cout << "3. Display Languages\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the language to add: ";
                cin >> lang;
                cout << "Enter the language family: ";
                cin >> fam;
                cout << "Enter the language branch: ";
                cin >> bra;
                languages.addLanguage(lang, fam, bra);
                system("clear"); // Clear screen
                break;
            case 2:
                cout << "\nEnter the language to search: ";
                cin >> lang;
                system("clear"); // Clear screen
                if (languages.searchLanguage(lang)) {
                    cout << "\nLanguage found!" << endl;
                } else {
                    cout << "\nLanguage not found!" << endl;
                }
                break;
            case 3:
                system("clear"); // Clear screen
                languages.displayLanguages();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    // Add a new contact to the address book
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // Search for a contact by name
    void searchContact(const string& name) {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    // Display all contacts in the address book
    void displayContacts() {
        if (contacts.empty()) {
            cout << "Address book is empty." << endl;
            return;
        }
        cout << "Address Book:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
        }
    }
};

int main() {
    AddressBook addressBook;

    // Sample contacts
    Contact contact1 = {"John Doe", "1234567890"};
    Contact contact2 = {"Jane Smith", "9876543210"};

    // Add contacts to the address book
    addressBook.addContact(contact1);
    addressBook.addContact(contact2);

    // Display all contacts
    addressBook.displayContacts();

    // Search for a contact
    string searchName;
    cout << "Enter the name to search: ";
    cin >> searchName;
    addressBook.searchContact(searchName);

    return 0;
}


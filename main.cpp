#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
struct Node;

Node* head = nullptr;
Node* tail = nullptr;

struct Contact {
  std::string first_name;
  std::string last_name;
  std::string phone;
  std::string email;
  std::string address;
};

struct Node {
  Contact contact;
  Node* next;
};

void AddContact(const Contact& contact)
{
  Node* node = new Node{contact, nullptr};
  
  if (head == nullptr) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void ShowContacts(void)
{
  if (head == nullptr) {
    cout << "Empty" << std::endl;
  }

  Node* node = head;
  while (node != nullptr) {
    cout << "Name: " << node->contact.first_name;
    if (node->contact.last_name != "") {
      cout << " " << node->contact.last_name;
    }

    cout << std::endl << "Phone: " << node->contact.phone << std::endl;

    if (node->contact.email != "") {
      cout << "Email: " << node->contact.email << std::endl;
    }
    if (node->contact.address != "") {
      cout << "Address: " << node->contact.address << std::endl;
    }
    cout << std::endl;

    node = node->next;
  }
}

Contact CreateNewContact(void)
{
  std::string first_name {}, last_name {}, phone {};
  std::string email {}, address {};

  cout << "First name: ";
  cin >> first_name;

  cout << "Last name: ";
  cin >> last_name;

  cout << "Phone: ";
  cin >> phone;

  cout << "Email: ";
  cin >> email;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "Address: ";
  std::getline(cin, address);

  Contact contact = {first_name, last_name, phone, email, address};

  return contact; 
}

void ShowMenu(void)
{
  cout << "*****************************" << std::endl;
  cout << "*** 1. Create new contact ***" << std::endl;
  cout << "*** 2. Show contacts      ***" << std::endl;
  cout << "*** 3. Quit               ***" << std::endl;
  cout << "*****************************" << std::endl;
}

int main(void)
{
  Contact contact {};
  int choice {};
  while (true) {
    ShowMenu();
    cin >> choice;

    switch (choice) {
      case 1:
        contact = CreateNewContact();
        AddContact(contact);
        break;
      case 2:
        ShowContacts();
        break;
      case 3:
      default:
        return 0;
    }
  }

  return 0;
}

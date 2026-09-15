#include <iostream>
#include <vector>
using namespace std;
void clearConsole() {
    // Move the cursor to the top-left corner
    std::cout << "\033[H";
    // Clear the screen
    std::cout << "\033[J";
}
class Contact {
    public : 
    string name ; 
    string email ; 
    string phone_no ; 
};
class PhoneBook {
      private : 
            vector<Contact> contacts ; 
      public  : 
      void addContact(const string &name , const string &email, const string &phone_no) {
                   clearConsole();
                   Contact newContact = {name,email,phone_no} ; 
                   contacts.push_back(newContact) ; 
                   cout<<"Contact added successfully......."<<endl;
      }
      void viewContact() {
          clearConsole();
          if (contacts.empty()) {
              cout<<"The phonebook is empty"<<endl;
              return ; 
          }
          cout<<endl<<"----Contact list----"<<endl;
          for (int i=0;i<contacts.size(); i++) {
              cout<<(i+1)<<endl<<"Name: "<<contacts[i].name<<endl;
              cout<<"Email: "<<contacts[i].email<<endl ; 
              cout<<"Phone number :"<<contacts[i].phone_no<<endl ; 
          }
      }
      void searchContact(const string &name) {
             clearConsole();
             bool found = false ; 
             for (int i=0;i<contacts.size();i++) {
                if (contacts[i].name == name) {
                    cout<<"Name: "<<contacts[i].name<<endl;
                    cout<<"Email: "<<contacts[i].email<<endl ; 
                    cout<<"Phone number :"<<contacts[i].phone_no<<endl ; 
                    found = true ; 
                    return ; 
                }
             }
             if (!found)
             cout<<"The "<<name<<" is not prsent in the contact list"<<endl;
      }
      void deleteContact(string name) {
            clearConsole();
            bool found = false ; 
            for (int i=0;i<contacts.size();i++) {
                if (contacts[i].name == name) {
                  contacts.erase(contacts.begin()+i) ;
                  cout<<"Contact deleted Successfully...." <<endl;
                  found = true ; 
                  break ; 
                }
                
             }
             if (!found) {
                cout<<"The "<<name<<" is not prsent in the contact list"<<endl;
             }
      }
      void editContact(string &name) {
           bool found = false ; 
           for (int i=0;i<contacts.size();i++) {
                if (contacts[i].name==name) {
                  found = true ; 
                  cout<< "Contact found"<<endl;
                  cout<<"Name: "<<contacts[i].name<<endl;  
                  cout<<"Email: "<<contacts[i].email<<endl ; 
                  cout<<"Phone no: "<<contacts[i].phone_no<<endl ;

                  cout<<"Enter new Details (leave blank to keep unchanged)"<<endl;
                  string newname,newemail,newphoneno ; 
                  cout<<"New Name: " ; 
                  getline(cin,newname) ;
                  cout<<"New Email: ";
                  getline(cin,newemail) ; 
                  cout<<"New phone no: ";
                  getline(cin,newphoneno) ; 

                  if (!newname.empty()) contacts[i].name = newname ; 
                  if (!newemail.empty()) contacts[i].email = newemail ; 
                  if (!newphoneno.empty()) contacts[i].phone_no = newphoneno ; 
                  break;
                }
           }
           if (!found) {
              cout<<"The "<<name<<" is not prsent in the contact list"<<endl;
           }
      }
      
}; 
int main() {
    PhoneBook phonebook ;
    int choice ; 
    string name,email,phone_no ; 
    do {
    cout<<"***********Phone Book Application************"<<endl;
    cout<<"1. Add contact"<<endl;
    cout<<"2. View All contact"<<endl;
    cout<<"3. Search contact"<<endl;
    cout<<"4. Delete Contact"<<endl;
    cout<<"5. Edit Contact"<<endl;
    cout<<"6. Exit Application"<<endl;
    cout<<"Enter Your choice: " ; 
    cin>>choice ; 
    cin.ignore() ; 
    switch(choice) {
      case 1 : 
              cout<<"Your name: " ; 
              getline(cin,name) ; 
              cout<<"Your email: ";
              cin>>email ; 
              cout<<"Your phone number: "; 
              cin>>phone_no ; 
              phonebook.addContact(name,email,phone_no) ; 
              break ; 
      case 2 : 
                 phonebook.viewContact() ; 
                 break ; 
      case 3 :  {  
                 string sname ; 
                 cout<<"Enter the name you need to search: " ; 
                 getline(cin,sname) ; 
                 phonebook.searchContact(sname) ; 
                 break ; 
      }
      case 4 : {  
                string dname ; 
                cout<<"Enter the name you want to delete: " ; 
                getline(cin,dname); 
                phonebook.deleteContact(dname) ; 
                break ; 
      }
      case 5 :  {
                   string name ;
                   cout<<"Search the name you want to edit in the contact list: " ; 
                   cin>>name ; 
                   phonebook.editContact(name) ; 
                   break ;
      }
      case 6 : cout<<"You have successfully exited the application" <<endl;
              break ; 
      default : 
             cout<<"Enter a valid choice "<<endl;
             break ; 

    }
    }
    while (choice!=6) ;
    
    return 0;
}
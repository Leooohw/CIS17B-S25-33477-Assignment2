#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Book and it's attributes
class Book
{

private:
    string title;
    string author;
    string availibility;
    double ISBN = 0;

public:

    //vector to store input from book listing
    vector <string> bookListName;
    vector <string> authorListing;
    vector <string> isbnListing;

    // function to add book
    void addBook(string bookName, string number, string author)
    {
        bookName = " ";

        //Takes book name and adds to vector
        cout << "\n>> Add a Book:\n";
        cout << ">> Enter the title: ";
        cin.clear();
        cin.ignore();
        getline(cin, bookName);
        bookListName.push_back(bookName);

        //Takes book Author and adds to vector    
        cout << "\n>> Enter the Author: ";
        getline(cin, author);
        authorListing.push_back(author);

        //Takes book ISBN and adds to vector    
        cout << "\n>> Enter the ISBN: ";
        getline(cin, number);
        isbnListing.push_back(number);
    }

    // List all the books
    void bookListing()
    {
        int count = 1;

        cout << "\n Listing: \n";
        for (size_t i = 0; i < bookListName.size(); ++i)
        {
            const auto& bookName = bookListName[i];
            const auto& author = authorListing[i];
            const auto& number = isbnListing[i];

            cout << ">> Book #" << count << " " << bookName << endl;
            cout << ">> -- Author: " << author << endl;
            cout << ">> -- ISBN: " << number << endl;

        }
    }

};

// User and it's attributes
class User
{

public:

    string name;
    double userID = 0;
    double IDcounter;
    vector <string> borrowList;

    void getID(string n, double ID)
    {
        cout << "Please enter user name";
        cin >> n;
        name = n;
        
        cout << "Please enter user ID";
        cin >> ID;
        userID = ID;
    }
};

//inherited student class
class Student : public User
{
public:
    string studentname;
};

//inherited faculty class
class Faculty : public User
{
public:
    string facultyname;
};



// Library, it's functions and uses
class Library
{

    bool isAvailable;

public:

    //functions to display menus
    void libraryMenu()
    {
        cout << "\nWelcome to the Library! \n";
        cout << "1. Manage Books \n";
        cout << "2. Manage Users \n";
        cout << "3. Manage Transactions \n";
        cout << "4. Exit\n\n";
    }

    void manageBook()
    {
        cout << "\nManage Books:\n";
        cout << "1. Add a Book\n";
        cout << "2. Edit a Book\n";
        cout << "3. Remove a Book\n";
        cout << "4. Go Back\n";
    }

    void manageTransactions()
    {
        cout << "\nManage Transactions:\n";
        cout << "1. Check Out A Book\n";
        cout << "2. Check In A Book\n";
        cout << "3. List All Books\n";
        cout << "4. List All Users\n";
        cout << "5. Go Back\n";
    }

};

// MAIN 

int main()
{

    //default variables for input
    int input = 0;
    //int input2;

    int transInput = 0;
    int bookManagerInput = 0;

    //temp variables for book
    string bookname;
    string authorname;
    string ISBN;

    Library test;
    Book test1;

    //switch case to display menu

    while (input != 4)
    {
        test.libraryMenu();

        //Asks user input 
        cout << "> Enter your choice: ";
        cin >> input;

        switch (input)
        {
        case 1:

            // loop for managebook
            while (bookManagerInput != 4)
            {
                test.manageBook();
                cout << "\n> Enter BookManager choice: ";
                cin >> bookManagerInput;

                // processes input choice
                if (bookManagerInput == 1)
                {
                    test1.addBook(bookname, ISBN, authorname);
                }

            }
            break;
        case 2:
            cout << "\ncase 2\n";
            break;
        case 3:

            //loop for transactions
            while (transInput != 5)
            {
                test.manageTransactions();
                cout << "\n> Enter your transaction choice: ";
                cin >> transInput;

                if (transInput == 1)
                {
                    //[;laceholder]
                    cout << "Check Out A Book:\n";
                }
                else if (transInput == 3)
                {
                    test1.bookListing();
                }
            }


            break;
        case 4:
            break;
        default:
            cout << "\nGoing back!\n";



        }

    }

    cout << "\nThank you for using Library services! o/ \n";

    return 0;

}


#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> books;
    int choice;
    string bookName;

    do
    {
        cout << "\n===== Library Returned Books Stack =====";
        cout << "\n1. Return Book (Push)";
        cout << "\n2. Arrange Book (Pop)";
        cout << "\n3. Top Book (Peek)";
        cout << "\n4. Display Stack";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter Book Name: ";
            getline(cin, bookName);

            books.push(bookName);
            cout << "Book Returned Successfully!";
            break;

        case 2:
            if (books.empty())
            {
                cout << "No books available to arrange.";
            }
            else
            {
                cout << "Book Arranged: " << books.top() << endl;
                books.pop();
            }
            break;

        case 3:
            if (books.empty())
            {
                cout << "Stack is Empty.";
            }
            else
            {
                cout << "Top Book: " << books.top() << endl;
            }
            break;

        case 4:
            if (books.empty())
            {
                cout << "No returned books in the stack.";
            }
            else
            {
                stack<string> temp = books;

                cout << "\nReturned Books (Top to Bottom):\n";
                while (!temp.empty())
                {
                    cout << temp.top() << endl;
                    temp.pop();
                }
            }
            break;

        case 5:
            cout << "Program Ended.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}

/* -------------------------------# OUTPUT #----------------------------------------
 




cd "/Users/peeyushmore/Python.app/DSA CLASSROOM/" && g++ peact1.cpp -o peact1 && "/Users/peeyushmore/Python.app/DSA CLASSROOM/"peact1
peeyushmore@Peeyushs-MacBook Python.app % cd "/Users/peeyushmore/Python.app/DSA CLASSROOM/" && g++ peact1.cpp -o peact1 && "/Users/peeyush
more/Python.app/DSA CLASSROOM/"peact1

===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 1
Enter Book Name: harry potter
Book Returned Successfully!
===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 1
Enter Book Name: game of thrones
Book Returned Successfully!
===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 1
Enter Book Name: suites
Book Returned Successfully!
===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 2
Book Arranged: suites

===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 3
Top Book: game of thrones

===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 4

Returned Books (Top to Bottom):
game of thrones
harry potter

===== Library Returned Books Stack =====
1. Return Book (Push)
2. Arrange Book (Pop)
3. Top Book (Peek)
4. Display Stack
5. Exit
Enter your choice: 5
Program Ended.%                                                                                                                           
peeyushmore@Peeyushs-MacBook DSA CLASSROOM % */
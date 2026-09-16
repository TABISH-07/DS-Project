#include <iostream>
#include <string>
#include <queue>
using namespace std;

/* ---------- LINKED LIST : CRIMINAL RECORDS ---------- */
struct Criminal {
    int id;
    string name;
    string status;
    Criminal* next;
};

Criminal* start = NULL;

// Add a criminal (sample data)
void addCriminal(int id, string name, string status) {
    Criminal* newNode = new Criminal;
    newNode->id = id;
    newNode->name = name;
    newNode->status = status;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        Criminal* temp = start;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Show all criminals
void showCriminals() {
    if (start == NULL) {
        cout << "No criminal records found.\n";
        return;
    }
    cout << "\n--- Criminal Records ---\n";
    Criminal* temp = start;
    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

// Search criminal by ID
void searchCriminal() {
    if (start == NULL) {
        cout << "No criminal records found.\n";
        return;
    }
    int searchId;
    cout << "Enter Criminal ID to search: ";
    cin >> searchId;

    Criminal* temp = start;
    bool found = false;
    while (temp != NULL) {
        if (temp->id == searchId) {
            cout << "\nCriminal Found!\n";
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Status: " << temp->status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) cout << "No criminal found with ID " << searchId << ".\n";
}

/* ---------- ARRAY : PRISON CELLS ---------- */
string cells[3] = {"Empty", "Empty", "Empty"};

void showCells() {
    cout << "\n--- Prison Cells ---\n";
    int emptyCount = 0;
    for (int i = 0; i < 3; i++) {
        cout << "Cell " << i+1 << ": " << cells[i] << endl;
        if (cells[i] == "Empty") emptyCount++;
    }
    cout << "Empty Cells: " << emptyCount << endl;
}

// Edit a cell (Jailer feature)
void editCells() {
    showCells();
    int cellNum;
    cout << "Enter cell number to edit (1-3): ";
    cin >> cellNum;
    if (cellNum < 1 || cellNum > 3) {
        cout << "Invalid cell number.\n";
        return;
    }
    cin.ignore();
    string newName;
    cout << "Enter new name (type 'Empty' to mark empty): ";
    getline(cin, newName);
    cells[cellNum-1] = newName;
    cout << "Cell updated successfully.\n";
}

/* ---------- QUEUE : JAILER DUTY ---------- */
queue<string> jailerQueue;

void showJailerDuty() {
    if (jailerQueue.empty()) {
        cout << "No jailers available.\n";
        return;
    }
    string current = jailerQueue.front();
    cout << "\nJailer on Duty: " << current << endl;

    jailerQueue.pop();
    jailerQueue.push(current);
}

/* ---------- LOGIN SYSTEM ---------- */
bool adminLogin() {
    string username, password;
    cout << "Admin Username: ";
    cin >> username;
    cout << "Admin Password: ";
    cin >> password;
    if (username=="admin" && password=="123") {
        cout << "\nAdmin Login Successful!\n";
        return true;
    } else {
        cout << "\nAccess Denied!\n";
        return false;
    }
}

bool jailerLogin() {
    string username, password;
    const string commonPass = "jailer123";
    cout << "Jailer Username: ";
    cin >> username;
    cout << "Jailer Password: ";
    cin >> password;
    if (password == commonPass) {
        cout << "\nJailer Login Successful!\n";
        return true;
    } else {
        cout << "\nAccess Denied!\n";
        return false;
    }
}

/* ---------- MAIN PROGRAM ---------- */
int main() {
    cout << "Select Login Type:\n1. Admin\n2. Jailer\nChoice: ";
    int loginChoice;
    cin >> loginChoice;

    bool loggedIn = false;
    if (loginChoice == 1) loggedIn = adminLogin();
    else if (loginChoice == 2) loggedIn = jailerLogin();
    else { cout << "Invalid choice.\n"; return 0; }

    if (!loggedIn) return 0;

    // Sample data
    addCriminal(1,"Rex","Captured");
    addCriminal(2,"Nova","At Large");
    cells[0] = "Rex";
    jailerQueue.push("Ali");
    jailerQueue.push("Sara");

    int choice;

    if (loginChoice == 1) { // Admin Menu
        do {
            cout << "\n===== ADMIN MENU =====\n";
            cout << "1. View Criminal Records\n2. View Prison Cells\n3. View Jailer Duty\n4. Search Criminal by ID\n5. Exit\nEnter choice: ";
            cin >> choice;
            switch(choice) {
                case 1: showCriminals(); break;
                case 2: showCells(); break;
                case 3: showJailerDuty(); break;
                case 4: searchCriminal(); break;
                case 5: cout << "System Closed.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while(choice != 5);
    } else { // Jailer Menu
        do {
            cout << "\n===== JAILER MENU =====\n";
            cout << "1. View Prison Cells\n2. Edit Prison Cell\n3. Exit\nEnter choice: ";
            cin >> choice;
            switch(choice) {
                case 1: showCells(); break;
                case 2: editCells(); break;
                case 3: cout << "System Closed.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while(choice != 3);
    }

    return 0;
}


#include <iostream>
using namespace std;

string task[10];
int taskcount = 0;
string username;

void displaywelcomemessage();
void displaymenu();
void addtasks();
void edittask();
void viewtasks();
void deletetask();

void displaywelcomemessage() {
    cout << "What is your name? ";
    getline(cin, username);
    cout << "Welcome, " << username << "😊" << endl;
}

void displaymenu() {
    cout << "\nChoose an option:\n";
    cout << "1- Add a task\n";
    cout << "2- Edit a task\n";
    cout << "3- View tasks\n";
    cout << "4- Delete a task\n";
    cout << "5- Exit\n";
}

void addtasks() {
    int numtasks;
    cout << "Enter the number of tasks to add: ";
    cin >> numtasks;
    cin.ignore();
    for (int i = 0; i < numtasks; i++) {
        cout << "Enter task " << taskcount + 1 << ": ";
        getline(cin, task[taskcount]);
        taskcount++;
    }
    cout << "\nTasks added successfully!\n";
}

void edittask() {
    if (taskcount == 0) {
        cout << "No tasks available to edit. Add tasks first.\n";
    } else {
        cout << "Your tasks:\n";
        for (int i = 0; i < taskcount; i++) {
            cout << i + 1<< ": " << task[i] << endl;
        }
        int editIndex;
        cout << "Enter the index of the task you want to edit: ";
        cin >> editIndex;
        cin.ignore();
        if (editIndex >= 1 && editIndex <= taskcount) {
            cout << "Enter the new value for task " << editIndex << ": ";
            getline(cin, task[editIndex - 1]);
            cout << "Task updated successfully!\n";
        } else {
            cout << "Invalid index!\n";
        }
    }
}

void viewtasks() {
    if (taskcount == 0) {
        cout << "No tasks available. Add tasks first.\n";
    } else {
        cout << "Your tasks:\n";
        for (int i = 0; i < taskcount; i++) {
            cout << i + 1 << ": " << task[i] << endl;
        }
    }
}

void deletetask() {
    if (taskcount == 0) {
        cout << "No tasks available to delete. Add tasks first.\n";
    } else {
        cout << "Your tasks:\n";
        for (int i = 0; i < taskcount; i++) {
            cout << i + 1 << ": " << task[i] << endl;
        }
        int deleteIndex;
        cout << "Enter the index of the task you want to delete: ";
        cin >> deleteIndex;
        if (deleteIndex >= 1 && deleteIndex <= taskcount) {
            for (int i = deleteIndex -1 ; i < taskcount - 1; i++) {
                task[i] = task[i + 1];
            }
            taskcount--;
            cout << "Task deleted successfully.\n";
        } else {
            cout << "Invalid index!\n";
        }
    }
}


int main() {
	displaywelcomemessage();
    int num;
  
    do {
    	  displaymenu();
        	  cin >> num;
     
        switch (num) {
        	  
            case 1: 
             addtasks();
             break;
       
            case 2: 
             edittask();
                break;
   
            case 3: 
            viewtasks();
                break;
       

            case 4: 
            deletetask();
                break;
 
            case 5:
                cout << "Goodbye, " << username << "😍\n";
                break;

            default:
                cout << "Invalid option! Please choose a valid number.\n";
                break;
            }
    } while (num != 5);

    return 0;
}
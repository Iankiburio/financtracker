#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <limits>

using namespace std;

class Expense;

// Class to represent an expense
class Expense {
    double amount;
    string category;
    string date;

public:
    Expense() : amount(0), category(""), date("") {}
    Expense(double amt, const string& cat, const string& dt) : amount(amt), category(cat), date(dt) {}

    double getAmount() const { return amount; }
    string getCategory() const { return category; }
    string getDate() const { return date; }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Amount: Ksh." << amount << ", Category: " << category << ", Date: " << date << endl;
    }
};

// Class to manage expenses
class ExpenseTracker {
    vector<Expense> expenses;

public:
    void addExpense(double amount, const string& category, const string& date) {
        expenses.push_back(Expense(amount, category, date));
    }

    void viewExpenses() const {
        cout << "Expenses List:" << endl;
        for (size_t i = 0; i < expenses.size(); ++i) {
            cout << i + 1 << ". ";
            expenses[i].display();
        }
    }

    void deleteExpense(size_t index) {
        if (index < 1 || index > expenses.size()) {
            cout << "Invalid index!" << endl;
            return;
        }
        expenses.erase(expenses.begin() + index - 1);
    }

    void summary() const {
        if (expenses.empty()) {
            cout << "No expenses to summarize." << endl;
            return;
        }

        map<string, double> categoryTotals;
        double total = 0;

        for (const auto& expense : expenses) {
            total += expense.getAmount();
            categoryTotals[expense.getCategory()] += expense.getAmount();
        }

        cout << fixed << setprecision(2);
        cout << "Total Expenses: Ksh." << total << endl;

        for (const auto& entry : categoryTotals) {
            cout << "Category: " << entry.first << ", Total: Ksh." << entry.second << endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    while (true) {
        cout << "\nExpense Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Delete Expense" << endl;
        cout << "4. Summary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: {
                double amount;
                string category, date;
                cout << "Enter amount: ";
                cin >> amount;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number: ";
                    cin >> amount;
                }
                cout << "Enter category: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, category);
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                tracker.addExpense(amount, category, date);
                break;
            }
            case 2:
                tracker.viewExpenses();
                break;
            case 3: {
                size_t index;
                tracker.viewExpenses();
                cout << "Enter index to delete: ";
                cin >> index;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number: ";
                    cin >> index;
                }
                tracker.deleteExpense(index);
                break;
            }
            case 4:
                tracker.summary();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}

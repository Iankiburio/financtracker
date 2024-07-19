# FINANCETRACKER

Finance Tracker
Overview
The Finance Tracker is a C++ console application designed to help users manage and keep track of their expenses. Users can add, view, delete expenses, and get a summary of their expenses categorized by different expense categories.

Features
Add Expense: Allows users to add an expense by entering the amount, category, and date.
View Expenses: Displays a list of all expenses added by the user.
Delete Expense: Users can delete an expense by specifying its index from the list.
Summary: Provides a summary of total expenses and categorizes them for easy tracking.
Exit: Exits the application.

Classes
#Expense
Represents an expense with the following attributes:
amount: The amount of the expense.
category: The category of the expense (e.g., Food, Transport, etc.).
date: The date the expense was incurred.

#ExpenseTracker
Manages a collection of expenses.
Methods:
addExpense(double amount, const string& category, const string& date): Adds a new expense.
viewExpenses(): Displays all the expenses.
deleteExpense(size_t index): Deletes an expense by its index.
summary(): Provides a summary of expenses by category and the total amount.


#How to Run
Clone the Repository: Clone this repository to your local machine using the following command:
git clone <repository-url>
Compile the Code: Navigate to the project directory and compile the code using a C++ compiler. For example, using g++:
g++ -o expense_tracker finance.cpp
Run the Executable: Run the compiled executable:
./finance

Notes
Input validation is included to handle invalid entries for menu choices and amounts.
The date should be entered in the YYYY-MM-DD format.
When deleting an expense, ensure to enter the correct index as displayed in the expenses list.

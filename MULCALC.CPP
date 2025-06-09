#include<iostream>
#include<iomanip> // for better precision 
using namespace std;

// Base Class
class Calculator
{
public:
    void displayMenu() 
{
        cout << "\n==============================\n";
        cout << "      ALL-IN-ONE CALCULATOR      \n";
        cout << "==============================\n";
        cout << "1 Basic Calculator\n";
        cout << "2  Temperature Converter\n";
        cout << "3  CGPA Calculator\n";
        cout << "4  Currency Converter\n";
        cout << "5  Exit\n";
        cout << "==============================\n";
    }
};

// Basic Calculator
class BasicCalculator : public Calculator 
{
    // Factorial helper function
    int factorial(int number) {
        if (number == 0 || number == 1)
            return 1;
        else
            return number * factorial(number - 1);
    }

public:
    void calculate() 
    {
        double num1, num2;
        char op;
        
        cout << "\nEnter a number: ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /, !): ";
        cin >> op;

        if (op != '!')
        {
            cout << "Enter second number: ";
            cin >> num2;
        }

        if (op == '+')
            cout << "Result: " << num1 + num2 << endl;
        else if (op == '-') 
            cout << "Result: " << num1 - num2 << endl;
        else if (op == '*')
            cout << "Result: " << num1 * num2 << endl;
        else if (op == '/')
        {
            if (num2 != 0) 
                cout << "Result: " << num1 / num2 << endl;
            else 
                cout << "Error: Division by zero!\n";
        }
        else if (op == '!')
        {
            if (num1 < 0 || int(num1) != num1)
                cout << "Error: Factorial is only defined for non-negative integers!\n";
            else
                cout << "Result: " << factorial((int)num1) << endl;
        }
        else 
            cout << "Invalid operator!\n";
    }
};


// Temperature Converter
class TemperatureConverter : public Calculator
 {
public:
    void convert() 
  {
        int choice;
        double temp, convertedTemp;
        
        cout << "\nTemperature Converter:\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Fahrenheit to Celsius\n";
        cout << "3. Celsius to Kelvin\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        cout << "Enter temperature: ";
        cin >> temp;
        
        if (choice == 1) 
    {
            convertedTemp = (temp * 9/5) + 32;
            cout << "Temperature in Fahrenheit: " << convertedTemp << "°F\n";
        } 
         else if (choice == 2) 
        {
            convertedTemp = (temp - 32) * 5/9;
            cout << "Temperature in Celsius: " << convertedTemp << "°C\n";
        } 
         else if (choice == 3) 
        {
            convertedTemp = temp + 273.15;
            cout << "Temperature in Kelvin: " << convertedTemp << "K\n";
        } 
          else 
        {
            cout << "Invalid choice!\n";
        }
    }
};

// CGPA Calculator
class CGPACalculator : public Calculator 

{
public:
    void computeCGPA() 
   {
        int numSubjects;
        string grade;
        double credit, totalCredits = 0, weightedSum = 0;
        
        cout << "\n CGPA CALCULATOR \n";
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;
        
        for (int i = 1; i <= numSubjects; i++) 
           {
            cout << "Enter grade (A+, A, B+, B, C+, C, D, F) for subject " << i << ": ";
            cin >> grade;
            
            double gradePoint;
            if (grade == "A+")
                    gradePoint = 10.0;
            else if
                   (grade == "A") gradePoint = 9.0;
            else if 
                   (grade == "B+") gradePoint = 8.0;
            else if 
		(grade == "B") gradePoint = 7.0;
            else if 
		(grade == "C+") gradePoint = 6.0;
            else if 	
		(grade == "C") gradePoint = 5.0;
            else if 				
		(grade == "D") gradePoint = 4.0;
            else if (grade == "F")
		 gradePoint = 0.0;
            else 
	    {
                cout << "Invalid grade! Please enter a valid grade.\n";
                i--;
                continue;
            }
            
            cout << "Enter credit for subject " << i << ": ";
            cin >> credit;
            
            weightedSum += gradePoint * credit;
            totalCredits += credit;
        }
        
        if (totalCredits == 0) 
		cout << "Total credits cannot be zero!\n";
        else 
		cout << "Your CGPA is: " << fixed << setprecision(2) << weightedSum / totalCredits << "\n";
    }
};

// Currency Converter
class CurrencyConverter : public Calculator
 {
public:
    void convertCurrency() 
  {
        double amount;
        int choice;
        
        cout << "\nCurrency Converter:\n";
        cout << "1. INR to USD\n";
        cout << "2. INR to EUR\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        cout << "Enter amount in INR: ";
        cin >> amount;
        
        if (choice == 1)
		 cout << "Equivalent in USD: " << amount / 83.0 << "\n";
        else if (choice == 2)
		 cout << "Equivalent in EUR: " << amount / 90.0 << "\n";
        else
		 cout << "Invalid choice!\n";
    }
};

// Main function
int main() {
    Calculator calc;
    BasicCalculator basicCalc;
    TemperatureConverter tempConv;
    CGPACalculator cgpaCalc;
    CurrencyConverter currConv;
    
    int choice;
    do {
        calc.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) 
  		basicCalc.calculate();
        else if (choice == 2) 
		tempConv.convert();
        else if (choice == 3) 
		cgpaCalc.computeCGPA();
        else if (choice == 4) 
		currConv.convertCurrency();
        else if (choice == 5) 
		cout << "Thank you for using All-in-One Calculator! Have a great day!\n";
        else 
		cout << "Invalid choice! Please try again.\n";
    } 
	while (choice != 5);
    
    return 0;
}

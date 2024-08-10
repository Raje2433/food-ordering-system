This C++ project is a food ordering system that allows users to sign up, log in, and place orders from a selection of restaurants offering different types of cuisine: non-vegetarian, vegetarian, and desserts. The project covers several object-oriented programming concepts, including inheritance, polymorphism, file handling, and encapsulation.

Project Overview

Classes:

customer: 
        This is the base class containing common attributes such as name, email, username, password, mobile number, and address. It also provides methods for logging in, retrieving user choices, and virtual methods for getting dishes.
nonveg, veg, and dessert: These classes inherit from customer and represent different types of cuisines. Each class has its own menu and pricing, and methods to get the user's selected dishes and calculate the total cost.
Bill: 
       This class handles the final billing process, displays the bill to the user, and manages payment modes (cash on delivery or UPI).

Features:

Sign Up & Login:
       The user signs up by providing their details and then logs in using their username and password.
Menu Selection: 
       The user can choose from different categories (non-veg, veg, dessert) and select dishes from the chosen category's menu.
Billing: 
       The total cost of the selected dishes is calculated, and the user can choose a payment method. The final bill and order confirmation are displayed to the user.
File Handling: 
        The project uses file handling to store user details and the final bill in a text file (sidenilo.txt).
 
Execution Flow:

The program starts by asking the user to sign up and then log in.
Once logged in, the user selects a category (non-veg, veg, dessert).
The user chooses a restaurant and selects dishes from the menu.
The total bill is calculated and displayed, and the user chooses a payment method.
The user's details, order, and bill are saved in a text file, and a confirmation message is displayed.
This project is a simple yet effective implementation to understand and apply various C++ programming concepts, including class inheritance, polymorphism, encapsulation, and file handling.







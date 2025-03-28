# Bill-Management-System
The Bill Management System is a C++ program that allows users to manage product records, generate bills, and track transactions. It supports adding products with prices and quantities, creating and deleting bills, and saving product data to a file. The system provides an interactive menu for easy navigation.
Project Breakdown
1️⃣ Product Management
Users can add products to a database by specifying a product name and its price.

The system stores these products in memory and saves them to a file (products.txt) for future use.

When the program restarts, it loads the product list from the file, ensuring data is not lost.

2️⃣ Billing System
Users can create a new bill by entering products along with their prices.

The system allows multiple products to be added to a single bill.

The total bill amount is calculated dynamically as products are added.

3️⃣ Bill Management
Users can view all previously generated bills along with detailed item-wise breakdowns.

Delete bills if they are no longer needed.

Ensures that bills are managed properly within the system.

4️⃣ File Handling for Persistent Storage
The system saves product data into a text file (products.txt) to ensure products persist across sessions.

This prevents loss of data when the program is closed and reopened.

Working of the System
Adding a Product to the Database:

The user enters a product name and price.

The product is added to the internal database and saved to a file.

Generating a Bill:

The user enters product details for a bill (multiple items can be added).

The system calculates the total amount dynamically.

The final bill is displayed to the user.

Displaying Bills:

The system lists all generated bills.

Each bill shows the items, prices, and total cost.

Deleting a Bill:

Users can delete unwanted bills from the system.

Technologies & Concepts Used
C++ Programming – Core logic and implementation.

Object-Oriented Programming (OOP) – Classes (Product, Bill, BillManagementSystem) ensure structured management.

File Handling – Uses ifstream and ofstream to save/load product data (products.txt).

Arrays – Stores products and bills efficiently.

Looping & Conditional Statements – Used for user input handling and decision-making.
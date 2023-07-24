<div>
    

    <h1>Banking Management System</h1>
    <p>The Banking Management System is a C++ console application that simulates a simple banking system. It allows users to create savings and current accounts, perform various account operations such as deposit, withdraw, transfer, and display account balance. The project demonstrates the use of object-oriented programming (OOP) concepts, including inheritance, polymorphism, abstraction, template class, and exception handling.</p>

    <h2>Table of Contents</h2>
    <ul>
        <li><a href="#features">Features</a></li>
        <li><a href="#requirements">Requirements</a></li>
        <li><a href="#how-to-use">How to Use</a></li>
        <li><a href="#class-hierarchy">Class Hierarchy</a></li>
        <li><a href="#sample-screenshots">Sample Screenshots</a></li>
        <li><a href="#license">License</a></li>
    </ul>

    <h2 id="features">Features</h2>
    <ul>
        <li>Create Savings Account: Users can create a savings account by providing account details like account number, account holder name, and interest rate.</li>
        <li>Create Current Account: Users can create a current account by providing account details like account number and account holder name.</li>
        <li>Deposit: Users can deposit a specified amount to a particular account.</li>
        <li>Withdraw: Users can withdraw a specified amount from a particular account.</li>
        <li>Transfer: Users can transfer a specified amount from one account to another.</li>
        <li>Display Account Balance: Users can view the account balance of a specific account.</li>
        <li>Password System: Each account is created with a password, and users need to enter the correct password to access account operations.</li>
        <li>Account Limit: The system allows creating up to 10 accounts.</li>
    </ul>

    <h2 id="requirements">Requirements</h2>
    <ul>
        <li>C++ compiler that supports C++11 or higher.</li>
    </ul>

    <h2 id="how-to-use">How to Use</h2>
    <ol>
        <li>Clone the repository or download the source code files.</li>
        <li>Open the terminal or command prompt.</li>
        <li>Navigate to the directory where the files are located.</li>
        <li>Compile the C++ code using your preferred C++ compiler.</li>
        <pre><code>g++ main.cpp -o banking_system</code></pre>
        <li>Run the executable file.</li>
        <pre><code>./banking_system</code></pre>
        <li>Follow the on-screen instructions to use the Banking Management System.</li>
        <li>To exit the program, select "0. Exit" from the main menu.</li>
    </ol>

    <h2 id="class-hierarchy">Class Hierarchy</h2>
    <ul>
        <li><strong>BankAccount</strong>: Base class representing a bank account with common functionalities like deposit, withdraw, transfer, and balance display.</li>
        <li><strong>SavingsAccount</strong>: Derived class from <em>BankAccount</em> with additional functionality to calculate and add interest to the account balance.</li>
        <li><strong>CurrentAccount</strong>: Derived class from <em>BankAccount</em> with additional functionality for overdraft facility.</li>
    </ul>

    <h2 id="sample-screenshots">Sample Screenshots</h2>
    <img src="/screenshots/main_menu.png" alt="Main Menu">
    <img src="/screenshots/create_savings_account.png" alt="Create Savings Account">
    <img src="/screenshots/create_current_account.png" alt="Create Current Account">
    <img src="/screenshots/access_account.png" alt="Access Account">
    <img src="/screenshots/account_operations.png" alt="Account Operations">

    <h2 id="license">License</h2>
    <p>This project is licensed under the <a href="LICENSE">MIT License</a>. Feel free to modify and use it for educational or personal purposes.</p>

</div>

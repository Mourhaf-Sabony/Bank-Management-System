# Bank-Management-System
Bank Management System implemented in C++ using Object-Oriented Programming (OOP) and file handling.

## 📖 Overview

This **Bank Management System** is a console-based C++ application designed with **Object-Oriented Programming (OOP)** principles. It simulates a real-world banking environment with modular architecture and file-based persistence.

The project evolved from a simple procedural system into a fully OOP design, showcasing **encapsulation, abstraction, inheritance, and polymorphism**.

---

## 🎯 Objectives

* Transform procedural banking logic into OOP-based architecture.

* Demonstrate core OOP principles:

  * 🔒 **Encapsulation:** Protect client and user data.
  * 🎭 **Abstraction:** Simplify interactions while hiding complex logic.
  * 🧬 **Inheritance:** Reuse and extend functionality across classes.
  * 🔄 **Polymorphism:** Support flexible operations like deposits, withdrawals, and transfers.

* Separate the system into clear layers:

  * **Presentation Layer:** Console UI screens
  * **Business Logic Layer:** Core operations and transaction handling
  * **Data Layer:** File-based persistence

* Ensure maintainability, scalability, and modular design.

---

## 🧱 Features

* **Client Management:** Add, edit, and remove clients.
* **Transactions:** Deposit, withdraw, and transfer money.
* **User Management:** Roles, permissions, and login security.
* **Security:** Lock system after 3 failed login attempts.
* **Reports:** Transaction logs and audit records.
* **UI Screens:** Organized menus showing current user and date.

---

## 🏗️ Architecture

```
Bank-Management-System/
 ┣ 📁 Core
 ┃ ┣ clsPerson.h / clsUser.h / clsBankClient.h
 ┃ ┗ clsScreen.h / clsMainScreen.h
 ┣ 📁 Lib
 ┃ ┗ Transaction and Access Control Classes
 ┣ 📁 Screens
 ┃ ┗ Menu and transaction UI screens
 ┣ 📁 Data
 ┃ ┗ clients.txt / Users.txt / TransferLog.txt / Currencies.txt
 ┗ main.cpp
```

*Modular design supports easy debugging, enhancements, and scalability.*

---

## ⚙️ Technology Stack

* 💻 **C++**
* 🧰 **OOP Concepts:** Encapsulation, Inheritance, Polymorphism, Abstraction
* 📁 **File Handling:** Persistent storage for clients, users, and transactions
* 🧮 **Bitwise Operations:** Permission handling for roles

---

## 🧩 Key Modules

| Module            | Features                      | OOP Concept    |
| ----------------- | ----------------------------- | -------------- |
| Client Management | CRUD operations for clients   | Encapsulation  |
| Transactions      | Deposit, withdraw, transfer   | Polymorphism   |
| Login & Security  | Failed login lock, user roles | Abstraction    |
| Reporting         | Transaction & activity logs   | Inheritance    |
| UI Screens        | Menus, transaction screens    | Modularization |

---

## 🧠 Learning Outcomes

* Modular OOP design reduces duplication and improves maintainability.
* Abstraction allows easy addition of features with minimal code changes.
* Encapsulation safeguards critical data.
* Demonstrates how a simple CLI banking system can scale to a professional design.

---

## 💻 Getting Started

1. Clone the repository:

```bash
git clone https://github.com/Mourhaf-Sabony/Bank-Management-System.git
```

2. Compile the project using any C++ compiler.
3. Run `main.cpp` to start the banking system.

---

## 📂 Repository Files

* `Core/` – Core classes for users, clients, and screens
* `Lib/` – Business logic and transaction handling
* `Screens/` – UI menus and transaction screens
* `Data/` – File-based persistence (`clients.txt`, `Users.txt`, `TransferLog.txt`)
* `main.cpp` – Entry point

---

## 📜 License

MIT License – see [LICENSE](LICENSE)

---

## 🔗 GitHub Repository

[https://github.com/Mourhaf-Sabony/Bank-Management-System](https://github.com/Mourhaf-Sabony/Bank-Management-System)

---

## 🏷️ Tags

#CPlusPlus #OOP #Encapsulation #Abstraction #Inheritance #Polymorphism #CLI #FileHandling #BankSystem #ModularCode #SoftwareEngineering #LearningByDoing


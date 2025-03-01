# Data-Structure-Instagram-App-in-Cpp
This project is a micro-version of Instagram built using C++ with fundamental data structures. It includes user management, messaging, friend requests, and notifications while utilizing linked lists, graphs, stacks, queues, and trees for efficient data handling

🚀 Features & Functionalities

1️⃣ User Profile & Management

Unique username & password authentication.

Additional attributes: City, Posts (with timestamps), Last login status.

Graph-based relationships (Friend requests, Active/Blocked/Pending status).

2️⃣ Data Structures Used

Feature

Data Structure Used

User & Friend Network

Graph (Adjacency List)

Login Authentication

Hash Table (Pending Implementation)

Messaging System

Stack (LIFO for latest message retrieval)

Friend Requests

Queue (FIFO for request processing)

Notifications

Queue (FIFO for notification order)

Search Users

Binary Search Tree (BST) (O(log n) complexity)

3️⃣ Core Functionalities

✅ Signup/Login System: Unique username validation & password strength enforcement.✅ Friend Requests: Pending requests handled using a Queue (FIFO).✅ Messaging: Private messaging feature using Stack-based chat storage.✅ Newsfeed & Posts: Posts stored using Stack, ensuring latest-first retrieval.✅ Search Users: Implemented using a Binary Search Tree (BST) for efficient lookup.✅ Notifications: Managed using a Queue, keeping events in order.✅ Graph Traversal for Friend Suggestions.

⚙️ Technologies Used

C++ (No external libraries for data structures)

Object-Oriented Programming (OOP) principles

Graph Data Structures (Adjacency List for Friend Network)

Queues & Stacks (For messaging & notifications)

Binary Search Trees (For searching users efficiently)

📂 Project Structure

📦 Data Structure Instagram App
 ┣ 📂 src
 ┃ ┣ 📜 main.cpp          # Main program file
 ┃ ┣ 📜 User.cpp          # User management & authentication
 ┃ ┣ 📜 Graph.cpp         # User relationships (friends, following, blocking)
 ┃ ┣ 📜 Stack.cpp         # Messaging & posts
 ┃ ┣ 📜 Queue.cpp         # Friend requests & notifications
 ┃ ┣ 📜 BST.cpp           # Searching users
 ┣ 📂 include             # Header files for modularity
 ┣ 📜 README.md           # Project documentation (You're reading it!)
 ┣ 📜 LICENSE             # License information

🔧 Installation & Usage

1️⃣ Clone the Repository

git clone https://github.com/YourUsername/DataStructure-Instagram.git
cd DataStructure-Instagram

2️⃣ Compile the Program

g++ -o instagramApp src/main.cpp src/User.cpp src/Graph.cpp src/Stack.cpp src/Queue.cpp src/BST.cpp -I include

3️⃣ Run the Application

./instagramApp

🛠 Future Improvements

✅ Complete Hash Table implementation for authentication.

🚀 Optimize Graph Traversal Algorithms for better friend suggestions.

🔥 Implement File Handling for persistent storage of users, messages, and posts.

📜 License

This project is licensed under the MIT License – see the LICENSE file for details.

👨‍💻 Contributing

Contributions are always welcome! Feel free to fork this repository and submit a pull request.


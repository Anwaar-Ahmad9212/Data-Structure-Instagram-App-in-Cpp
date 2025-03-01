# Data Structure Instagram App in C++

## 📌 Overview

This project is a micro-version of Instagram built using **C++** with fundamental **data structures**. It includes user management, messaging, friend requests, and notifications while utilizing **linked lists, graphs, stacks, queues, and trees** for efficient data handling.

🔹 **No built-in data structures** (like STL stack, queue, etc.) are used. All data structures are **implemented from scratch**.

🔹 The system is designed to **mimic Instagram features**, such as **friend requests, messaging, notifications, and posts** while ensuring optimal performance and modular design.

---

## 🚀 Features & Implemented Data Structures

### 🧑‍💻 User Profile (Linked List & Graph)
- Each user is represented as a **node** with attributes:
  - Name (Unique Identifier)
  - Password (Login Authentication)
  - City
  - Posts (Date/Time, Text Content)
  - Last Login Timestamp
- **Friend Relationships** are represented as **graph edges**, including:
  - Relation type (Friend, Blocked, Pending Request)
  - Status Management

### 👥 User Network (Graph)
- Users and their relationships are stored in an **adjacency list**.
- **Graph traversal optimizations** help manage **friend suggestions & mutual friends**.
- Username & password verification is done using **hash lookup**.

### ✉️ Messages (Stack)
- Each conversation between two users is stored as a **stack**.
- The **latest message is always at the top** for easy retrieval.

### 📝 Posts & Newsfeed (Stack)
- Each user has a **separate post stack** for:
  - Their own posts.
  - Posts from followers (Newsfeed).

### 🤝 Friend Requests (Queue)
- Friend requests are managed using a **queue (FIFO order)**.
- Ensures **oldest requests are handled first**.

### 🔔 Notifications (Queue)
- New friend requests, accepted requests, and received messages are **queued**.
- Users can view notifications **in the order they arrived**.

### 🔍 Searching Users (Binary Search Tree - BST)
- Users are stored in a **BST (sorted by username)**.
- Search users in **O(log n) time complexity**.

### 📜 Menu Functionalities
✅ **Signup/Login**: Secure user authentication & password reset.
✅ **Follow Requests**: Manage requests & approvals.
✅ **Friend Management**: Accept, reject, or cancel requests.
✅ **Posting System**: Timeline to display posts from followers.
✅ **Messaging System**: Send & receive messages in real time.
✅ **Search Feature**: Efficient search using BST.
✅ **Notifications**: Display unread messages, friend requests, and updates.
✅ **Followers List**: View and manage followers.
✅ **Newsfeed**: Display personal posts & posts from followers.

### ⚡ Scalability & Future Enhancements
- **Modular Design**: Separated into classes like `User`, `Followers`, `Messages` for easy expansion.
- **Persistent Storage**: Data saved and loaded from files to prevent loss on crashes.

---

## 🛠️ Technologies Used
- **C++**
- **Data Structures**: Linked Lists, Graphs, Stacks, Queues, Binary Search Trees (BST)
- **File Handling** for data persistence

---

## 📂 Installation & Usage
```bash
# Clone the repository
git clone https://github.com/Anwaar-Ahmad9212/Data-Structure-Instagram-App-in-Cpp

---

## 📜 License
This project is licensed under the **MIT License**. Feel free to use and modify it.

---

## 🤝 Contributing
Contributions are welcome! Follow these steps:
1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Commit changes (`git commit -m 'Added new feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Open a Pull Request

---

## 📞 Contact
For any inquiries or issues, reach out via **GitHub Issues**.

---

🔹 **Developed by Anwaar Ahmad**


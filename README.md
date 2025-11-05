Quiz App using DSA (C)
📘 Project Overview

The Quiz App using Data Structures is a command-line quiz application built in C language that demonstrates the use of Linked Lists for dynamic question management.
It allows users to answer multiple-choice questions, validates input, calculates scores, and gives performance feedback.
The project showcases how fundamental Data Structures (Linked Lists) can be applied in a real-world context — dynamically adding, storing, and traversing quiz questions.

⚙️ Technologies Used
Language: C
Data Structure: Linked List
Concepts Used:
Structures (struct)
Dynamic Memory Allocation (malloc)
Linked List traversal
Input validation
Conditional logic and loops

🧩 Features

✅ Linked List-based Question Storage – Questions are stored dynamically in nodes, each containing the question, 4 options, and the correct answer.
✅ Automatic Quiz Start – Preloaded set of multiple-choice questions; no manual question entry needed.
✅ Case-Insensitive Input – Accepts both uppercase (A) and lowercase (a) answers.
✅ Input Validation – Displays an error message for invalid choices (like z, 1, or symbols).
✅ Dynamic Scoring System – Tracks correct and incorrect answers in real-time.
✅ Result Evaluation – Shows total score, percentage, and feedback messages like “Excellent!”, “Good!”, or “Try Again!”.
✅ Extensible Design – New questions can be added easily with a single function call.

How It Works

Each question is created using a structure that holds:
Question text
Four options (A, B, C, D)
Correct answer key
All questions are linked together in a singly linked list.
The quiz iterates through the linked list, displaying one question at a time.
The user inputs an answer (A–D or a–d).
If invalid input (like z), the program asks again.
At the end, the app displays:
Total score
Percentage
Feedback message

<img width="702" height="598" alt="image" src="https://github.com/user-attachments/assets/7d178bdb-dae3-477b-8535-a48157c0943c" />
QuizApp_LinkedList/
│
├── quiz_app.c        # Main source code
├── README.md         # Project documentation
└── (optional) quiz_scores.txt   # Future extension for storing player scores


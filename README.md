# computer_network_monitoring

📡 Network Topology Monitoring System (C Project)

👥 Team Members
Student 1: Baira Spoorthi
Student 2: Nellore Sanjana 

🎯 Problem Statement


The objective of this project is to design and implement a Computer Network Monitoring System using the C programming language. 
The system simulates a network topology where devices (nodes) are connected through links (edges).
To implement the program using the C programming language with proper use of structures and dynamic memory allocation.
 To allow users to perform CRUD operations on network devices:
Create (Add devices and connections)
Read (Display network topology and search devices)
Update (Modify device details)
Delete (Remove devices and connections)



🧠 Data Structure Used


Graph (Adjacency List Representation)
Each device is represented as a vertex
Each connection is represented as an edge
Structures Used:
struct Vertex → stores device details (ID, Name)
struct AdjNode → stores connections
Dynamic Memory Allocation:
Used malloc() and free() for adjacency list nodes



⚙️ Algorithm Explanation


1. Add Device (CREATE)
Input device ID and name
Check if device already exists
Add to vertex list
2. Add Connection (CREATE)
Input source and destination device IDs
Create a new adjacency node
Insert into adjacency list
3. Display Network (READ)
Traverse all vertices
Print each device and its connections
4. Search Device (READ)
Find device by ID
Display its connections
5. Update Device (UPDATE)
Search device by ID
Modify device name
6. Delete Connection (DELETE)
Locate connection in adjacency list
Remove and free memory
7. Delete Device (DELETE)
Remove all its connections
Remove incoming connections
Shift vertices
8. File Handling (Persistence)
Save data using fprintf() to network.txt
Load data using fscanf() when program starts

🛠️ Compilation Instructions
Step 1: Save File
Save the program as:
network.c

Step 2: Compile
gcc network.c -o network

Step 3: Run

For Linux/Mac:

./network


For Windows:

network.exe




💻 Sample Output


<img width="1003" height="720" alt="Screenshot 2026-04-04 203116" src="https://github.com/user-attachments/assets/b7284a81-e317-4a60-a0fb-8322203ab1c9" />

<img width="900" height="671" alt="Screenshot 2026-04-04 203135" src="https://github.com/user-attachments/assets/a74516d1-fb28-4ad2-acfc-119d0bbfff12" />

<img width="679" height="387" alt="Screenshot 2026-04-04 203147" src="https://github.com/user-attachments/assets/f9cdbd0e-2265-4a0a-bd79-b8cff80bb8b9" />

<img width="532" height="330" alt="Screenshot 2026-04-04 203157" src="https://github.com/user-attachments/assets/e8a8859f-c673-46a4-85af-e0eef3565582" />

<img width="653" height="336" alt="Screenshot 2026-04-04 203205" src="https://github.com/user-attachments/assets/0dbc9318-1919-4dbe-9a3e-a566520d6ac2" />

<img width="626" height="321" alt="Screenshot 2026-04-04 203219" src="https://github.com/user-attachments/assets/c9048625-5487-4097-99f3-fcef9a2478fd" />

<img width="582" height="309" alt="Screenshot 2026-04-04 203230" src="https://github.com/user-attachments/assets/2062192e-1c37-4f83-acba-236b33e4ec7e" />

<img width="710" height="362" alt="Screenshot 2026-04-04 203238" src="https://github.com/user-attachments/assets/9a86404b-3b43-4412-80a6-51f1242cb4c1" />

<img width="638" height="293" alt="Screenshot 2026-04-04 203247" src="https://github.com/user-attachments/assets/ab84f6eb-9ae8-4239-8905-66b5ef70343e" />

<img width="790" height="344" alt="Screenshot 2026-04-04 203252" src="https://github.com/user-attachments/assets/9b018f61-59ed-451d-a14f-81f687d86234" />









🏆 Conclusion
This project successfully demonstrates the use of graph data structures, dynamic memory allocation, and file handling in C to simulate a real-world network monitoring system with full CRUD operations.


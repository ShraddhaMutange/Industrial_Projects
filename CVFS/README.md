# 📂 Customized Virtual File System (CVFS)

---

## 🛠️ Technology
**Language:** C Programming  

---

## 📌 Project Overview

This project is a custom implementation of a **Virtual File System (VFS)** that simulates the core functionality of the Linux file system.

It is built entirely in **C**, with its own custom shell to interact with the virtual environment.

The project provides hands-on understanding of:

- System calls  
- File handling  
- Memory management  
- Operating system internals  

---

## 🚀 Key Features

### 🖥️ Custom Shell Interface
- Provides Linux-like commands for file operations:
  - `create`
  - `open`
  - `read`
  - `write`
  - `delete`
  - `ls`
  - `man`
  - `exit`

---

### ⚙️ System Call Simulation
Implements core Linux file system system calls using C:
- `open`
- `read`
- `write`
- `lseek`
- `close`
- `rm`
- `ls`

---

### 🗂️ File System Data Structures
Internally simulates:

- Incore Inode Table  
- File Table  
- UAREA (User Area)  
- User File Descriptor Table (UFDT)  
- Super Block  
- Boot Block  

---

### 🌍 Platform Independent
- Simulates Linux-style file handling logic  
- Can run on any operating system with a C compiler  

---

### 🗃️ Database-like Functionality
- Structured file handling  
- Organized metadata management  
- Controlled memory allocation  
- Simulated storage management  

---

## 🎯 Learning Outcomes

- Deep understanding of Linux File System internals  
- Practical knowledge of OS data structures (inode, file tables, UAREA)  
- Strong grasp of system programming in C  
- Hands-on experience with shell design and command interpreter  
- Application of low-level logic building for OS-like environments  

---

## ▶️ Example Usage

```bash
$ ./Myexe

Marvellous CVFS> create Demo.txt 3
Marvellous CVFS> write 3
Enter the data that you want to write:
Jay Ganesh

Marvellous CVFS> read 3 10
Jay Ganesh

Marvellous CVFS> ls
Demo.txt

Marvellous CVFS> unlink Demo.txt
Marvellous CVFS> exit
```

---

## 👩‍💻 Author

**Shraddha Dhananjay Mutange**  
Information Technology Undergraduate  

🔗 GitHub: https://github.com/ShraddhaMutange  
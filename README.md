# ProPart1 – Alphabetically Sorted Country Data  
**Author:** Andrew Merritt  
**Language:** C++  
**GitHub Repository:** [AndrewMerritt_ProPart1-](https://github.com/a0merr/AndrewMerritt_ProPart1-)  

---

## 📌 Project Overview
This project implements a **sorted array list (ASList)** in C++ to store and display **country data**.  

The program reads a CSV file (`education-economy-data modified.csv`) containing:  
- Country name  
- Literacy rate  
- GDP per capita  

The **ASList template class** ensures that data is stored in **alphabetical order by country**.  

The goals of the project were to:  
- Practice **templates and generic programming** in C++  
- Implement a **sorted array list** with insert and print operations  
- Read and process **CSV files**  
- Use **operator overloading** for custom sorting  

---

## 🛠️ Files Included
- **ASList.h / ASList.cpp** – Template-based sorted array list  
  - `insert()` – Adds an item in alphabetical order  
  - `print()` – Displays the list contents  
  - `isFull()` / `isEmpty()` – Check list status  
- **CountryData.h** – Struct for storing **country information**  
  - Overloads `<` operator for alphabetical sorting  
- **main.cpp** – Reads the CSV file, inserts data into the list, and prints it  

---

## ▶️ How to Compile and Run
1. Make sure you have a **C++ compiler** installed (e.g., g++, Visual Studio, clang)  
2. Clone the repository:
   ```bash
   git clone https://github.com/a0merr/AndrewMerritt_ProPart1-.git

Open students.csv

While another line exists in the file Read the line Create a Student object on the heap using the line Add the Student pointer to the vector End While

Close the file


---

### printStudents(vector<Student*>& students)

Purpose: Print the complete information for every student.



Loop through each Student pointer in the vector Call printFull() End Loop


---

### showStudentNames(vector<Student*>& students)

Purpose: Print only each student's last name and first name.



Loop through each Student pointer in the vector Call printSummary() End Loop


Example Output:



Johnson, Danielle Booth, Joshua Lee, Angela


---

### findStudent(vector<Student*>& students)

Purpose: Search for students by last name.



Ask the user for a search string

Loop through each Student pointer in the vector

If the search string is found within the student's last name
    Print the student's full information
End If


End Loop


Example:



Search: Lee


Returns:



Angela Lee


Example:



Search: R


Returns all students whose last name contains the capital letter R.

---

### delStudents(vector<Student*>& students)

Purpose: Remove all Student objects from heap memory.



Loop through each Student pointer in the vector Delete the Student object End Loop

Clear the vector


---

### menu()

Purpose: Display the menu and return the user's choice.



Display menu options

Get user's choice

Return choice


Menu:


quit
print all student names
print all student data
find a student

---

### Student(string csvLine)

Purpose: Create a Student object from one line of CSV data.



Split the CSV line into fields

Store first name Store last name

Create an Address object on the heap

Create a Date object for date of birth on the heap

Create a Date object for graduation date on the heap

Store credit hours


---

### Student Destructor

Purpose: Prevent memory leaks by deleting heap objects.



Delete Address pointer

Delete Date of Birth pointer

Delete Graduation Date pointer


---

### main()

Purpose: Control the overall program flow.



Create a vector of Student pointers

Load students from the CSV file

Repeat until the user chooses to quit

Display the menu

If choice is 1
    Show all student names

Else if choice is 2
    Print all student data

Else if choice is 3
    Search for a student


Until choice is 0

Delete all students from memory

End program


---

### Optional Sort by Last Name



Sort the vector using Student last names

Store updated order in the vector


---

### Optional Sort by First Name



Sort the vector using Student first names

Store updated order in the vector


---

### Optional Sort by Credit Hours



Sort the vector by credits in descending order

Students with more credits appear first

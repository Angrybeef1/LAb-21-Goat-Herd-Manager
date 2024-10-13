What to submit: your Github repository URL. Commit and push your code every ten minutes when coding this assignment.

Use the demo code for doubly-linked lists that we studied in this module: 210-dll-demo-1.cppDownload 210-dll-demo-1.cpp

Right now, each node in the linked list contains one data item: an int data. 

We are going to modify this code such that rather than a single integer, each node contains an object. Specifically, a Goat object.

Write a class Goat that has these private member variables:

age (int)
name (string)
color (string)
names[] - a string array of 15 names. Use the replit AI feature to develop a quick list of names.
colors[] - a string array of 15 colors. Use AI again.
The Goat class will have two constructors, as expected:

The default constructor will randomly assign:
an age, 1-20
a name, randomly selected from the 15-element names[] array
a color, randomly selected from the 15-element colors[] array
The parameter constructor will be a typical 3-element parameter setup.
Task. Modify the DoublyLinkedList class's push_front() and push_back() functions such that it has a Goat object as a parameter, rather than an int. 

Task. In main(), create a DoublyLinkedList object. Append to it a random number of Goat objects, range 5-20 or so.

Task. In main(), call your methods to print both forward and backward to show the proper traversals.

Task. Use srand(time(0)); as one of your first lines in main() to randomize your random numbers.

Task. Update both of the print() methods that are in the class. Both should display the text "List is empty" if the list is empty; otherwise, output the list as shown in the sample output below.

Sample output
Forward: 
    Senior (Yellow, 6)
    Godlike (Red, 7)
    Old (Red, 2)
    Old (Gold, 6)
    Mature (Mauve, 6)
    Teen (Gold, 10)
    Teen (White, 17)

Backward: 
    Teen (White, 17)
    Teen (Gold, 10)
    Mature (Mauve, 6)
    Old (Gold, 6)
    Old (Red, 2)
    Godlike (Red, 7)
    Senior (Yellow, 6)

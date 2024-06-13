#include<bits/stdc++.h>
using namespace std;

int main(){
    //-------------Vector----------//
    //size()	returns the number of elements present in the vector
    //clear()	removes all the elements of the vector
    //front()	returns the first element of the vector
    //back()	returns the last element of the vector
    //empty()	returns 1 (true) if the vector is empty

    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> vector2(5,12);//size of vector array is 5 with all 12 value
    vector<int> vector4;//don't need to declare size. You can push back to the vector
    vector1.push_back(6);
    vector1.push_back(7);//push back will be occurr

    vector4.push_back(2);
    cout<<vector4[0]<<endl;//index start with 0
    //cout<<vector4.at(0)<<endl;
    //cout<<vector3[1]<<endl;//index start with 0

    // change elements at indexes 1 and 4
    vector1.at(1) = 9;

    // remove the last element
    vector1.pop_back();

     /* 
    We initialize a 2D vector  
    named "vect" on line 16 with 
    different number of values  
    in each element. 
    */
      
    vector<vector<int>> vect 
    { 
        /* Element one with 2 values in it. */
        {1, 2},  
        
        /* Element two with 3 values in it. */
        {4, 5, 6},  
        
         /* Element three with 4 values in it. */
        {7, 8, 9, 10}  
    }; 
  
    /* 
    Now we print the vector that we  
    just defined using a simple 
    nested for loop. 
    */
      
    for (int i = 0; i < vect.size(); i++)  
    { 
        for (int j = 0; j < vect[i].size(); j++) 
        { 
            cout << vect[i][j] << " "; 
        }     
        cout << endl; 
    } 

    //-------------Queue----------//
    //Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement. 
    //Elements are inserted at the back (end) and are deleted from the front
    //push()	Inserts an element at the back of the queue.
    //pop()	Removes an element from the front of the queue.
    //front()	Returns the first element of the queue.
    //back()	Returns the last element of the queue.
    //size()	Returns the number of elements in the queue.
    //empty()	Returns true if the queue is empty.
    // create a queue of string
    queue<string> animals;
    // push elements into the queue
    animals.push("Cat");
    animals.push("Dog");
    cout << "Queue: ";
    // print elements of queue
    // loop until queue is empty
    while(!animals.empty()) {
        // print the element
        cout << animals.front() << ", ";
        // pop element from the queue
        animals.pop();
    }


    //-------------Map----------//
    map<int, string> student;
    //insert()	adds an element (key-value pair) to the map
    //erase()	removes an element or range of elements from the map
    //clear()	removes all the elements from the map
    //find()	searches the map for the given key
    //size()	returns the number of elements in the map
    //empty()	returns true if the map is empty
  
    // use [] operator to add elements
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // use insert() method to add elements
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake"));

    // add elements with duplicate keys
    student[5] = "Timothy";
    student[5] = "Aaron";

    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }
    // remove the element having key 4
    student.erase(4);


    //----------Set--------------//
    set<int> my_set;

    // add values to the set
    my_set.insert(10);
    my_set.insert(30);
    my_set.insert(20);
    my_set.insert(50);
    my_set.insert(40);
    my_set.insert(50);

    // delete values from the set
    my_set.erase(10);
    my_set.erase(20);

    // check if 40 exists
    int num = 40;
    if(my_set.count(num) == 1) {
        cout << num << " exists." << endl;
    } else {
        cout << num << " doesn't exist." << endl;
    }
    
    // print the set elements
    for (int i : my_set) {
        cout << i << "  ";
    }

    //---------------Stack----------------//
    //Stacks are a type of container adaptors with LIFO(Last In First Out) type of working,
    //where a new element is added at one end (top) and an element is removed from that end only. 
    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num=0;
    stack.push(num);
    stack.pop();
    stack.pop();
    stack.pop();
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }




    return 0;
}
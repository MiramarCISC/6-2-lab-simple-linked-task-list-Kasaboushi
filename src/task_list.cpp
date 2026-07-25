#include "task_list.hpp"
#include <iostream>

using namespace std;

bool isValidPriority(int priority) {
    // TODO: Return true when priority is from 1 to 5.
    if ((priority >= 1) && (priority <= 5))
    {
        return true;
    }
    return false;
}

Task createTask(string description, int priority) {
    Task task;
    string desc = description;
    int prior = 1;
    if (isValidPriority(priority)) {
        prior = priority;
    }
    task.priority = prior;
    task.description = desc;
    task.completed = false;

    return task;  

    // TODO:
    // Store the description.
    // Store the priority if valid; otherwise store 1.
    // New tasks should start as not completed.
}

void insertFront(TaskNode*& head, Task task) {
    // TODO:
    // Dynamically allocate a new TaskNode.
    // Store task in the node.
    // Point the new node to the old head.
    // Update head.

    // Create a new Node
    // add the info
    // set the next

    TaskNode* node = new TaskNode; //Make a new node
    node->data = task; // and set the variables
    node->next = head;
    head = node;
    
}

int countTasks(const TaskNode* head) {
    // TODO: Traverse the list and count nodes.
    int count = 0;
    while (head != nullptr) {
        count ++;
        head = head->next;
    }
    return count;
}

TaskNode* findTask(TaskNode* head, string description) {
    // TODO:
    // Traverse the list.
    // Return the first node whose task description matches.
    // Return nullptr if not found.
    
    while (head != nullptr)  {
        if (head -> data.description == description) {
            return head;
        }
        head = head -> next;
    }
    return nullptr;
}

bool markTaskComplete(TaskNode* head, string description) {
    // TODO:
    // Find the task.
    // If found, set completed to true and return true.
    // Otherwise return false.
    
    //Does not work; only tags first one
    if (findTask(head, description) != nullptr) {
        findTask(head,description) -> data.completed = true;
        return true;
    }
    return false;
}

int removeCompletedTasks(TaskNode*& head) {
    // TODO:
    // Remove all completed tasks.
    // Return the number of removed nodes.
    // Be sure to handle completed tasks at the head of the list.

        // // two pointers, current and previous
        // // continue while current is not null
        // // count whenever current = completed
        // // if previous is null, shift head, delete it
        // int count = 0;
        // TaskNode* previous = head;
        // // TaskNode* nextNode = head->next;
        // while (previous != nullptr) {
        //     // TaskNode* nextNode = previous->next;
        //     // if (previous->data.completed == true) {
        //     //     count ++;
        //     //     delete previous;
        //     // }
        //     // cout << previous->data.description;
        //     // cout << "\n";
        //     // TaskNode* nextNode = previous->next;
        //     // if (nextNode != nullptr) {
        //     //     cout << "next is" << nextNode->data.description << "***";
        //     //     cout << "\n";
        //     //     previous-

        //     }
        // int count = 0;
        // TaskNode* trail = head;
        // TaskNode* newHead = nullptr;
        // TaskNode* movingHead = head;
        // while (movingHead != nullptr) {
            
        //     if (movingHead->data.completed == true) {
        //         cout << "deleting " << trail->data.description; 
        //         movingHead = movingHead->next;
        //         count ++;
        //         delete trail;
        //     }
        //     else {
        //         movingHead = movingHead->next;
        //     }
        //     trail = movingHead;
        //     // movingHead = movingHead->next;
        //     if (newHead == nullptr) {
        //         newHead = movingHead;
        //     }
            
        // }
        
        // head = newHead;
        
        // return count;
        TaskNode* previous = nullptr;
        TaskNode* current = head;
        int count = 0;
        //if it's completed
        //     check if previous is null
        //         if yes, move head forward after deleting what used to be head; make another pointer and cut
        //         otherwise
        //         if no, relink; set previous next to current and then delete.
        // else move on and set previous to current, current to next

        while (current != nullptr) {
            if (current->data.completed) {
                TaskNode* temp = current;
                if (previous == nullptr) {
                    head = current->next;
                    current = head;
                }
                else {
                    previous->next = current-> next;
                    current = current->next;
                }
                delete temp;
                count ++;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    return count;
}

void clearTasks(TaskNode*& head) {
    // TODO:
    // Delete every node in the list.
    // Set head to nullptr.

    // while (head != nullptr) {
    //     head = nullptr;
    //     head = head->next;
    // }

    // Need to loop until nothing left: So, while the next one exists, delete the next, then set head to nullptr.
    // Or, save the next one ahead of time, and delete the current
    while (head != nullptr) {
        TaskNode* node = new TaskNode;
        node = head->next;
        delete head;
        head = node;
    }
    head = nullptr;
}

void printTask(const Task& task) {
    cout << task.description
         << " | priority " << task.priority
         << " | " << (task.completed ? "complete" : "not complete")
         << endl;
}

void printTasks(const TaskNode* head) {
    if (head == nullptr) {
        cout << "No tasks." << endl;
        return;
    }

    const TaskNode* current = head;

    while (current != nullptr) {
        printTask(current->data);
        current = current->next;
    }
}

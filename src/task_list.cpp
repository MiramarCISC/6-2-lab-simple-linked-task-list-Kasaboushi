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

    //TaskNode head->data = &task;

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
    
    if (findTask(head, description) != nullptr) {
        head -> data.completed = true;
        return true;
    }
    return false;
}

int removeCompletedTasks(TaskNode*& head) {
    // TODO:
    // Remove all completed tasks.
    // Return the number of removed nodes.
    // Be sure to handle completed tasks at the head of the list.
    int count = 0;
    while (head->next != nullptr) {
        if (head->data.completed == true) {
            head = nullptr;
        }
        head = head-> next;
    }
    return count;
}

void clearTasks(TaskNode*& head) {
    // TODO:
    // Delete every node in the list.
    // Set head to nullptr.
    while (head != nullptr) {
        head = nullptr;
        head = head->next;
    }
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

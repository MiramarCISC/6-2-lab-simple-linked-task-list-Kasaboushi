#include "task_list.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testIsValidPriority() {
    assert(isValidPriority(1));
    assert(isValidPriority(3));
    assert(isValidPriority(5));
    assert(!isValidPriority(0));
    assert(!isValidPriority(6));
}

void testCreateTask() {
    Task task = createTask("homework", 3);

    assert(task.description == "homework");
    assert(task.priority == 3);
    assert(task.completed == false);

    Task invalid = createTask("laundry", 9);
    assert(invalid.priority == 1);
}

void testInsertFrontAndCount() {
    TaskNode* head = nullptr;

    insertFront(head, createTask("homework", 3));
    assert(head != nullptr);
    assert(countTasks(head) == 1);

    insertFront(head, createTask("study", 5));
    assert(countTasks(head) == 2);
    assert(head->data.description == "study");

    clearTasks(head);
    assert(head == nullptr);
}

void testFindTask() {
    TaskNode* head = nullptr;

    insertFront(head, createTask("homework", 3));
    insertFront(head, createTask("study", 5));

    TaskNode* found = findTask(head, "homework");
    TaskNode* missing = findTask(head, "missing");

    assert(found != nullptr);
    assert(found->data.priority == 3);
    assert(missing == nullptr);

    clearTasks(head);
}

void testMarkTaskComplete() {
    TaskNode* head = nullptr;

    insertFront(head, createTask("homework", 3));

    assert(markTaskComplete(head, "homework"));
    assert(head->data.completed == true);
    assert(!markTaskComplete(head, "missing"));

    clearTasks(head);
}

void testRemoveCompletedTasks() {
    TaskNode* head = nullptr;

    insertFront(head, createTask("task1", 1));
    insertFront(head, createTask("task2", 2));
    insertFront(head, createTask("task3", 3));

    markTaskComplete(head, "task1");
    markTaskComplete(head, "task3");

    int removed = removeCompletedTasks(head);

    assert(removed == 2);
    assert(countTasks(head) == 1);
    assert(findTask(head, "task2") != nullptr);
    assert(findTask(head, "task1") == nullptr);
    assert(findTask(head, "task3") == nullptr);

    clearTasks(head);
}

void testClearEmptyAndNonEmpty() {
    TaskNode* head = nullptr;

    clearTasks(head);
    assert(head == nullptr);

    insertFront(head, createTask("homework", 3));
    insertFront(head, createTask("study", 5));

    clearTasks(head);
    assert(head == nullptr);
}

int main() {
    testIsValidPriority(); 
    testCreateTask(); 
    testInsertFrontAndCount(); 
    testFindTask(); 
    testMarkTaskComplete(); 
    testRemoveCompletedTasks(); 
    testClearEmptyAndNonEmpty(); 

    cout << "All Lab 6.2 linked task list tests passed!" << endl;
    return 0;
}

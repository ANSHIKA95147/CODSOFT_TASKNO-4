#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

// Function prototypes
void addTask(std::vector<Task>& todoList);
void viewTasks(const std::vector<Task>& todoList);
void markTaskCompleted(std::vector<Task>& todoList);
void removeTask(std::vector<Task>& todoList);

int main() {
    std::vector<Task> todoList;
    int choice;

    while (true) {
        std::cout << "\n===== TO-DO LIST MANAGER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addTask(todoList);
                break;
            case 2:
                viewTasks(todoList);
                break;
            case 3:
                markTaskCompleted(todoList);
                break;
            case 4:
                removeTask(todoList);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select between 1 and 5.\n";
        }
    }
    return 0;
}

void addTask(std::vector<Task>& todoList) {
    std::cin.ignore(10000, '\n'); // Clear buffer
    std::cout << "Enter the task description: ";
    std::string description;
    std::getline(std::cin, description);
    
    if (!description.empty()) {
        todoList.push_back({description, false});
        std::cout << "Task added successfully!\n";
    } else {
        std::cout << "Task description cannot be empty.\n";
    }
}

void viewTasks(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "Your to-do list is empty.\n";
        return;
    }

    std::cout << "\n--- Current Tasks ---\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        std::cout << i + 1 << ". [" 
                  << (todoList[i].isCompleted ? "Completed" : "Pending") 
                  << "] " << todoList[i].description << "\n";
    }
}

void markTaskCompleted(std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "No tasks available to mark as completed.\n";
        return;
    }

    viewTasks(todoList);
    std::cout << "Enter the number of the task to mark as completed: ";
    size_t index;
    std::cin >> index;

    if (index > 0 && index <= todoList.size()) {
        todoList[index - 1].isCompleted = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "No tasks available to remove.\n";
        return;
    }

    viewTasks(todoList);
    std::cout << "Enter the number of the task to remove: ";
    size_t index;
    std::cin >> index;

    if (index > 0 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + (index - 1));
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

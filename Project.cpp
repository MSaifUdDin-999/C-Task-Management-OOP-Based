#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

class Task
{
private:
  string title;
  string description;
  bool completed;

public:
  Task() : title(""), description(""), completed(false) {}

  Task(string t, string d, bool c = false)
  {
    title = t;
    description = d;
    completed = c;
  }

  void markAsComplete()
  {
    completed = true;
  }

  bool isCompleted() const
  {
    return completed;
  }

  string getTitle() const
  {
    return title;
  }

  string getDescription() const
  {
    return description;
  }

  void setTask(string t, string d, bool c = false)
  {
    title = t;
    description = d;
    completed = c;
  }

  bool isEmpty() const
  {
    return title == "";
  }

  void clear()
  {
    title = "";
    description = "";
    completed = false;
  }
};

class TaskManager
{
private:
  Task tasks[MAX_TASKS];
  int taskCount = 0;

public:
  void addTask(string title, string description)
  {
    if (taskCount < MAX_TASKS)
    {
      tasks[taskCount].setTask(title, description);
      taskCount++;
      cout << "Task added successfully.\n";
    }
    else
    {
      cout << "Task list is full. Cannot add more tasks.\n";
    }
  }

  void markTaskAsComplete(int index)
  {
    if (index >= 0 && index < taskCount)
    {
      tasks[index].markAsComplete();
      cout << "Task marked as complete.\n";
    }
    else
    {
      cout << "Invalid index.\n";
    }
  }

  void removeTask(int index)
  {
    if (index >= 0 && index < taskCount)
    {
      for (int i = index; i < taskCount - 1; i++)
      {
        tasks[i] = tasks[i + 1];
      }
      taskCount--;
      cout << "Task removed successfully.\n";
    }
    else
    {
      cout << "Invalid index.\n";
    }
  }

  void listAllTasks()
  {
    if (taskCount == 0)
    {
      cout << "No tasks to show.\n";
      return;
    }

    cout << "Tasks:\n";
    for (int i = 0; i < taskCount; i++)
    {
      cout << i + 1 << ". " << tasks[i].getTitle() << " - " << tasks[i].getDescription();
      if (tasks[i].isCompleted())
        cout << " [Completed]";
      cout << endl;
    }
  }
};
int main()
{
  string user;
  int pin;
  TaskManager taskManager;
  int mainChoice;

  cout << "-------------------------\n";
  cout << " Main Menu\n";
  cout << "-------------------------\n";
  cout << " 1. Admin Menu\n";
  cout << " 2. Exit\n";
  cout << "-------------------------\n";
  cout << "Enter your choice: ";
  cin >> mainChoice;

  if (mainChoice == 1)
  {
    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter your 4 Digit pin: ";
    cin >> pin;

    if (user == "saif" && pin == 1234)
    {
      int choice;
      bool running = true;

      while (running)
      {
        cout << "-------------------------\n";
        cout << " Task Manager Menu\n";
        cout << "-------------------------\n";
        cout << " 1. Add Task\n";
        cout << " 2. Mark Task as Complete\n";
        cout << " 3. Remove Task\n";
        cout << " 4. List All Tasks\n";
        cout << " 5. Exit\n";
        cout << "-------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
          string title, description;
          cout << "Enter task title : ";
          cin >> title;
          cout << "Enter task description : ";
          cin >> description;
          taskManager.addTask(title, description);
          break;
        }
        case 2:
        {
          taskManager.listAllTasks();
          int index;
          cout << "Enter task index to mark as complete: ";
          cin >> index;
          taskManager.markTaskAsComplete(index - 1);
          break;
        }
        case 3:
        {
          taskManager.listAllTasks();
          int index;
          cout << "Enter task index to remove: ";
          cin >> index;
          taskManager.removeTask(index - 1);
          break;
        }
        case 4:
          taskManager.listAllTasks();
          break;
        case 5:
          cout << "Exiting program. Goodbye!" << endl;
          running = false;
          break;
        default:
          cout << "Invalid choice. Try again.\n";
          break;
        }

        if (running)
        {
          char again;
          cout << "-------------------------\n";
          cout << "Enter 'n' to return to menu or any other key to exit: ";
          cin >> again;
          if (again != 'n' && again != 'N')
          {
            cout << "Goodbye! Program terminating.\n";
            running = false;
          }
        }
      }
    }
    else
    {
      cout << "-------------------------\n";
      cout << "INCORRECT LOGIN !!!!\n";
    }
  }
  else
  {
    cout << "-------------------------\n";
    cout << "Goodbye! Program terminating.\n";
  }

  return 0;
}
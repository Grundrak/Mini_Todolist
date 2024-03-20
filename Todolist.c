#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int lvl;
    int id;
    char desc[128];
    int end;
} todo;

todo *todoList = NULL;
int count = 0;

void add()
{
    char desc[128];
    int lvl = 0;
    int end = 0;
    printf("Enter ur Task please :");
    fgets(desc, sizeof(desc), stdin);
    desc[strcspn(desc, "\n")] = 0;

    do
    {
        printf("Enter your level of priority for this Task from 1 to 3 : ");
        scanf("%d", &lvl);
        getchar();

        if (lvl < 1 || lvl > 3)
        {
            printf("Error: Number must be from 1 to 3. Please try again.\n");
        }
    } while (lvl < 1 || lvl > 3);

    printf("Enter if you complited the task or not { (1) for done and (0) for unfinished }  : ");
    scanf("%d",&end);
    getchar();


    todoList = (todo *)realloc(todoList, (count + 1) * sizeof(todo));  

    todoList[count].id = count + 1;
    strncpy(todoList[count].desc, desc, sizeof(todoList[count].desc) - 1);
    todoList[count].desc[sizeof(todoList[count].desc) - 1] = '\0';
    todoList[count].lvl = lvl;
    todoList[count].end= end;
    printf("Added successfully");
    count++;
}

void display()
{
    for (int i = 0; i < count; i++)
    {
        printf("id: %d | Task : %s  | Lvl Priority : %d  | Task is : %s \n ", todoList[i].id, todoList[i].desc, todoList[i].lvl ,(todoList[i].end == 1) ? "Complited" :"Unfinished");
    }
}
void displayByPriority()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (todoList[j].lvl < todoList[j + 1].lvl)
            {
                todo temp = todoList[j];
                todoList[j] = todoList[j + 1];
                todoList[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("id: %d | Task : %s  | Lvl Priority : %d  | Task is : %s \n ", todoList[i].id, todoList[i].desc, todoList[i].lvl ,(todoList[i].end == 1) ? "Complited" :"Unfinished");
    }
}
void update()
{
    int id;
    char newDesc[128];
    printf("Enter the id of task you wanna update : ");
    scanf("%d", &id);
    getchar();

    printf("Enter the new task : ");
    fgets(newDesc, sizeof(newDesc), stdin);
    newDesc[strcspn(newDesc, "\n")] = 0;

    for (int i = 0; i < count; i++)
    {
        if (todoList[i].id == id)
            strncpy(todoList[i].desc, newDesc, sizeof(todoList[i].desc) - 1);
        todoList[i].desc[sizeof(todoList[i].desc) - 1] = '\0';
        printf("Uptaded successfully");
        break;
    }
}
void deleteT()
{
    int id;

    printf("Enter the Id of task you wanna delete .");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++)
    {
        if (todoList[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                todoList[j] = todoList[j + 1];
            }
        }
        count--;
        printf("Deleted successfully");
        break;
    }
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Add Task\n2. Display All Tasks\n3. Display Tasks by priority \n4. Update Task \n5. Delete task\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            displayByPriority();
            break;
        case 4:
            update();
            break;
        case 5:
            deleteT();
            break;
        case 6:
            free(todoList);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
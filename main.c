#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>

#include "school.h"




int main()
{
    int i, j, op, idORname, Add_Checked=0, Delete_Checked=0, Searched_ID, Student_Index, school_size=0;
    char Searched_Name[50]={0};


    printf("1- Add Student.\n");
    printf("2- Edit Student.\n");
    printf("3- Delete Student.\n");
    printf("4- Print Student.\n");
    printf("5- Print School.\n");
    printf("6- Call Student.\n\n");


    while(1)
    {
        op=0;
        printf("Enter the option: ");
        scanf("%d", &op);

        Add_Checked = 0;
        Delete_Checked = 0;
        
        if(op == 1)
        {
            Add_Checked = Add_Student(school, SCHOOL_SIZE);
            if(Add_Checked)
            {
                printf("ِِِAddition failed!!\n");
            }
            else
            {
                school_size = get_Max_Students();
                student_School_AlphabetSelectionSort(school, school_size);
                printf("Addition succeeded\n");
            }
        }
        else if(op == 2)
        {
            school_size = get_Max_Students();
            if(school_size)
            {
                printf("Enter name or id: ");
                scanf("%d", &Searched_ID);
                if(Searched_ID >= 20230000 && Searched_ID < 202310000)
                {
                    Student_Index = Search_StudentByID(school,SCHOOL_SIZE, Searched_ID);
                    if(Student_Index >= 0)
                    {
                        Print_Student(&school[Student_Index]);
                        Edit_Student(&school[Student_Index], Student_Index);
                    }
                    else
                    {
                        printf("Not found the student\n");
                    }
                }
                else
                {
                    printf("Wrong ID\n");
                }
                Print_Student(&school[Student_Index]);
            }
            else
            {
                printf("No students\n");
            }

        }
        else if(op == 3)
        {
            printf("Enter the student id to delete: ");
            scanf("%d", &Searched_ID);
            if(Searched_ID >= 20230000 && Searched_ID < 202310000)
            {
                Student_Index = Search_StudentByID(school,SCHOOL_SIZE, Searched_ID);

            }
            if(Student_Index >= 0)
            {
                Delete_Checked = Delete_Student(school, Student_Index);
                if(Delete_Checked)
                {
                    printf("Deletion failed!!\n");
                }
                else
                {
                    printf("Deletion succeeded\n");
                }
            }
            else
            {
                printf("Not found the student\n");
            }
        }
        else if(op == 4)
        {
            printf("Select 0- ID\n");
            printf("       1- Name\n");
            scanf("%d", &idORname);
            if(idORname == 0)
            {
                printf("Enter the student id: ");
                scanf("%d", &Searched_ID);
                if(Searched_ID >= 20230000 && Searched_ID < 202310000)
                {
                    Student_Index = Search_StudentByID(school,SCHOOL_SIZE, Searched_ID);
                }
                if(Student_Index >= 0)
                {
                    Print_Student(&school[Student_Index]);
                }
                else
                {
                    printf("Not found the student\n");
                }
            }
            else if(idORname == 1)
            {
                printf("Enter the student name: ");
                string_scan(Searched_Name, 50);

                Student_Index = Search_StudentByName(school,SCHOOL_SIZE, Searched_Name);
                if(Student_Index >= 0)
                {
                    Print_Student(&school[Student_Index]);
                }
                else
                {
                    printf("Not found the student\n");
                }
            }
            else
            {
                printf("Wrong Selection!!\n");
            }

        }
        else if(op == 5)
        {
            school_size = get_Max_Students();
            if(school_size)
            {
                print_School(school, school_size);
            }
            else
            {
                printf("No students\n");
            }

        }
        else if (op == 6)
        {
            printf("Select 0- ID\n");
            printf("       1- Name\n");
            scanf("%d", &idORname);

            if(idORname == 0)
            {
                printf("Enter the student id: ");
                scanf("%d", &Searched_ID);
                if(Searched_ID >= 20230000 && Searched_ID < 202310000)
                {
                    Student_Index = Search_StudentByID(school,SCHOOL_SIZE, Searched_ID);
                }
                if(Student_Index >= 0)
                {
                    printf("%s\n", school[Student_Index].phone);
                }
                else
                {
                    printf("Not found the student\n");
                }
            }
            else if(idORname == 1)
            {
                printf("Enter the student name: ");
                scanf("%s", &Searched_Name);

                Student_Index = Search_StudentByName(school,SCHOOL_SIZE, Searched_Name);

                if(Student_Index >= 0)
                {
                    printf("%s\n", school[Student_Index].phone);
                    printf("calling.");
                    for(i=0; i<4; i++)
                    {
                        Sleep(300);
                        printf("%c", '.');
                    }
                    printf("no answer!\n");
                }
                else
                {
                    printf("Not found the student\n");
                }
            }

        }
        else
        {
            printf("Wrong Entey!!\n");
        }

        fflush(stdin);
    }


    return 0;
}


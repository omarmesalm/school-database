
#ifndef SCHOOL_H_
#define SCHOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include "school.h"


static int noOfStudents = 0, Student_ID=20230000;


void SwapStudent(student_t* arr1, student_t* arr2)
{
    student_t tempStudent=*arr1;
    *arr1 = *arr2;
    *arr2 = tempStudent;
}

int name_compare_sort(student_t* arr1, student_t* arr2)
{
    char i, state=0, str1, str2;
    for(i=0; (arr1->name[i] || arr2->name[i]) && state==0 ;i++)
    {
        if(arr1->name[i] >= 'A' && arr1->name[i] <= 'Z')
        {
            str1 = arr1->name[i] - 'A';
        }
        else if(arr1->name[i] >= 'a' && arr1->name[i] <= 'z')
        {
            str1 = arr1->name[i] - 'a';
        }
        if(arr2->name[i] >= 'A' && arr2->name[i] <= 'Z')
        {
            str2  = arr2->name[i] - 'A';
        }
        else if(arr2->name[i] >= 'a' && arr2->name[i] <= 'z')
        {
            str2 = arr2->name[i] - 'a';
        }

        if(str1 > str2)
        {
            state = 1;
        }
        else if(str1 < str2)
        {
            state = -1;
        }
    }

    return state;
}


void student_School_AlphabetSelectionSort(student_t* arrSchool, int size)
{
    int i,j, max_index, lastIndex=size-1;


    for(i=0; i<size; i++)
    {
        max_index = 0;
        for(j=0; j<=lastIndex; j++)
        {
            if(name_compare_sort(&arrSchool[max_index], &arrSchool[j]) == -1)
            {
                max_index = j;
            }
        }
        SwapStudent(&arrSchool[max_index], &arrSchool[lastIndex]);
        lastIndex--;
    }
}





int string_scan(char *str, int maxsize)
{
    int i=0, Error_State=0, flag=0;
    char ch;

    fflush(stdin);
    scanf("%c", &ch);
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch==' '))
    {
        str[i] = ch;
    }
    else
    {
        Error_State = 1;
    }
    for(; (str[i]!='\n') && (i<maxsize-1)&& (flag==0);)
    {
        i++;
        scanf("%c", &ch);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch==' ') || (ch=='\n'))
        {
            str[i] = ch;
        }
        else
        {
            flag = 1;
            Error_State = 1;
        }
    }
    str[i] = 0;
    fflush(stdin);

    return Error_State;
}

char phone_scan(char* phone, char maxsize)
{
    char i=0, ph, ErrorState=0, flag=0;

    fflush(stdin);
    scanf("%c", &ph);
    if(ph >= '0' && ph <= '9')
    {
        phone[i] = ph;
    }
    else
    {
        ErrorState = 1;
    }
    for(; phone[i]!='\n' && i<maxsize && (flag==0);)
    {
        i++;
        scanf("%c", &ph);
        if(((ph=='\n') && (i<11)) || ((i==11) && (ph!='\n')))
        {
            flag = 1;
            ErrorState = 1;
        }
        else if((ph >= '0' && ph <= '9') || (ph=='\n'))
        {
            phone[i] = ph;
        }
    }
    phone[i] = 0;
    fflush(stdin);

    return ErrorState;
}

int Add_Material(student_t* Sub_Data, int Start_Material, int Last_Material)
{
    char i, ErrorState=0, flag=0, SubNameChecked=0;
    int grade;

    if(Sub_Data == 0 || (Last_Material-Start_Material)==0)
    {
        ErrorState = 1;
    }
    else
    {
        for(i=Start_Material; (i<Last_Material) && (flag==0); i++)
        {
            printf("Enter the name of material [%d]: ", i+1);
            SubNameChecked = string_scan(Sub_Data->materials[i].sub_name, 20);
            if(SubNameChecked)
            {
                ErrorState = 1;
                break;
            }
            else
            {

            }
            printf("Enter the grade: ");
            scanf("%d", &grade);
            if(grade >= 0 && grade <= 100)
            {
                Sub_Data->materials[i].sub_grade = grade;
            }
            else
            {
                ErrorState = 1;
                break;
            }
            fflush(stdin);
            printf("Enter the max grade: ");
            scanf("%d", &grade);
            if(grade >= 0 && grade <= 100)
            {
                Sub_Data->materials[i].max_grade = grade;
            }
            else
            {
                ErrorState = 1;
                break;
            }
        }
        fflush(stdin);
    }

    return ErrorState;
}


int Add_Student(student_t* arrSchool, int MaxSize)
{
    int Error_State=0, phoneChecked=0, nameChecked=0, MaterialChecked=0;

    if((arrSchool==0) || (MaxSize > 1000))
    {
        Error_State = 1;
    }
    else
    {
        printf("Enter the student name: ");
        nameChecked = string_scan(arrSchool[noOfStudents].name, 50);
        while(nameChecked)
        {
            printf("Invalid Name!!, Enter the student name: ");
            nameChecked = string_scan(arrSchool[noOfStudents].name, 50);
        }
        arrSchool[noOfStudents].ID = Student_ID;
        printf("Enter the student age: ");
        scanf("%d", &arrSchool[noOfStudents].age);
        printf("Enter the student grade: ");
        scanf(" %c", &arrSchool[noOfStudents].grade);
        printf("Enter the student phone: ");
        phoneChecked = phone_scan(arrSchool[noOfStudents].phone, 11);
        while(phoneChecked)
        {
            printf("Invalid Number!!, Enter the correct phone Number:");
            phoneChecked = phone_scan(arrSchool[noOfStudents].phone, 11);
        }

        printf("Enter the no of subjects: ");
        scanf("%d", &school[noOfStudents].noOfMaterials);
        if(school[noOfStudents].noOfMaterials > 0)
        {
            school[noOfStudents].materials = (subject_t*)malloc(school[noOfStudents].noOfMaterials * sizeof(subject_t));
            MaterialChecked = Add_Material(&school[noOfStudents], 0, school[noOfStudents].noOfMaterials);
            while(MaterialChecked)
            {
                printf("Invalid Entry, Try again!!\n");
                MaterialChecked = Add_Material(&school[noOfStudents], 0, school[noOfStudents].noOfMaterials);
            }
            Student_ID++;
        }
    }

    if(Error_State == 0)
    {
        noOfStudents++;
    }

    return Error_State;
}


int Search_StudentByID(student_t* arrSchool, int MaxSize, int ID_Find)
{
    int i, Error_State=0, StudentIndex=-1, flag=0;

    if(arrSchool == 0 || MaxSize > 1000)
    {
        Error_State = 1;
    }
    else
    {
        for(i=0; (i<1000) && (flag==0); i++)
        {
            if(arrSchool[i].ID == ID_Find)
            {
                StudentIndex = i;
                flag = 1;
            }
        }
    }
    return StudentIndex;
}

void UpperToLower(char*str)
{
    int i;

    for(i=0; str[i]; i++)
    {
        if(str[i]>= 'A'&& str[i]<='Z')
        {
            str[i]=str[i]-'A'+'a';
        }
    }
}


int string_compareNotCaseSenstive(char *str1, char *str2)
{
    int i;
    UpperToLower(str1);
    UpperToLower(str2);

    for(i=0; str1[i] || str2[i]; i++)
    {
        if(str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}


int Search_StudentByName(student_t* arrSchool, int MaxSize, char* Name_Find)
{
    int i, Error_State=0, StudentIndex=-1, flag=0;

    if(arrSchool == 0 || MaxSize > 1000)
    {
        Error_State = 1;
    }
    else
    {
        for(i=0; (i<1000) && (flag==0); i++)
        {
            if((string_compareNotCaseSenstive(arrSchool[i].name, Name_Find)) == 1)
            {
                StudentIndex = i;
                flag = 1;
            }
        }
    }
    return StudentIndex;
}


void Print_Student(student_t* arrSchool)
{
    int i;

    printf("\nStudent Data:-\n");
    printf("ID     : %d\n", arrSchool->ID);
    printf("Name   : %s\n", arrSchool->name);
    printf("Age    : %d\n", arrSchool->age);
    printf("Grade  : %c\n", arrSchool->grade);
    printf("Phone  : %s\n", arrSchool->phone);
    printf("no. of Subjects  : %d\n", arrSchool->noOfMaterials);

    printf("\n");
    printf("\tSubject Name  \t\t Grade  \tMax Grade\n");
    printf("_________________________________________________________\n");
    for(i=0; i<(arrSchool->noOfMaterials); i++)
    {
        printf("[%d]  |\t %13s  \t\t %2d  \t\t   %2d\n", i+1, arrSchool->materials[i].sub_name,
                                                              arrSchool->materials[i].sub_grade,
                                                              arrSchool->materials[i].max_grade);
    }
    printf("\n");
}

void Edit_Material(subject_t* Sub_Data)
{
    int sub_edit;

    printf("1- Edit grade.\n");
    printf("2- Edit max grade.\n");
    scanf("%d", &sub_edit);
    if(sub_edit==1)
    {
        printf("Enter the new grade: ");
        scanf("%d", &Sub_Data->sub_grade);
    }
    else if(sub_edit==2)
    {
        printf("Enter the new max grade: ");
        scanf("%d", &Sub_Data->max_grade);
    }
}


void Delete_Material(subject_t* Sub_Data, int* MaxSize, int DeleteIndex)
{
    char i, ErrorState=0;

    if(Sub_Data==0)
    {
        ErrorState = 1;
    }
    else
    {
        for(i=DeleteIndex; i<(*MaxSize); i++)
        {
            Sub_Data[i] = Sub_Data[i+1];
        }
        (*MaxSize)--;
    }
}


void Edit_Student(student_t* arrStudent, int Edit_Index)
{
    int mode, sub_mode, noOfNewSubjects, StartIndex, LastIndex, sub_edit, selected_sub;

    printf("Select:\n");
    printf("1- Edit Name.\n");
    printf("2- Edit Age.\n");
    printf("3- Edit Grade.\n");
    printf("4- Edit Phone.\n");
    printf("5- Edit subjects.\n");


    scanf("%d", &mode);
    if(mode==1)
    {
        printf("Enter the new name: ");
        scanf("%s", &arrStudent->name);
    }
    else if(mode==2)
    {
        printf("Enter the new age: ");
        scanf("%d", &arrStudent->age);
    }
    else if(mode==3)
    {
        printf("Enter the new grade: ");
        scanf("%c", &arrStudent->grade);
    }
    else if(mode==4)
    {
        printf("Enter the new phone: ");
        scanf("%s", &arrStudent->phone);
    }
    else if(mode==5)
    {
        printf("Select:\n");
        printf("1- Add subject.\n");
        printf("2- Delete subject.\n");
        printf("3- Edit subject.\n");
        scanf("%d", &sub_mode);
        if(sub_mode==1)
        {
            printf("Enter no. of subjects to add: ");
            scanf("%d", &noOfNewSubjects);
            arrStudent[Edit_Index].materials = (subject_t*)realloc(arrStudent[Edit_Index].materials, (noOfNewSubjects+arrStudent->noOfMaterials) * sizeof(subject_t));
            if(arrStudent[Edit_Index].materials == 0)
            {
                printf("Not Allocated!!\n");
            }
            else
            {
                StartIndex = arrStudent->noOfMaterials;
                LastIndex = StartIndex + noOfNewSubjects;
                print_School(school, noOfStudents);
                Add_Material(&arrStudent[Edit_Index], StartIndex, LastIndex);
                arrStudent->noOfMaterials = arrStudent->noOfMaterials + noOfNewSubjects;
            }

        }
        else if(sub_mode==2)
        {
            printf("Select the subject to delete:\n");
            scanf("%d", &selected_sub);
            if(selected_sub <= 0)
            {
                printf("Invalid Selection!!");
            }
            else
            {
                selected_sub--;
                Delete_Material(arrStudent->materials, &arrStudent->noOfMaterials, selected_sub);
            }

        }
        else if(sub_mode==3)
        {
            printf("Select the subject to edit:\n");
            scanf("%d", &selected_sub);
            if(selected_sub <= 0)
            {
                printf("Invalid Selection!!");
            }
            else
            {
                selected_sub--;
                Edit_Material(&arrStudent->materials[selected_sub]);
            }

        }

    }
}


int Delete_Student(student_t* arrStudent, int DeleteIndex)
{
    char i, ErrorState=0;

    if(arrStudent==0)
    {
        ErrorState = 1;
    }
    else
    {
        for(i=DeleteIndex; i<noOfStudents; i++)
        {
            arrStudent[i] = arrStudent[i+1];
        }
        noOfStudents--;
    }

    return ErrorState;
}

void print_School(student_t* arrSchool, int size)
{
    int i, j, c;

    printf("\n\n");
    printf("School Information:- \n");
    printf("Number of Students = %d\n", size);
    printf("__________________________________________________________________________________________________________________\n");
    printf("         |    \t\t\t  |     |       |              |                 |          subjects\t          |\n");
    printf("   ID    |\tName\t\t  | Age | Grade | Phone Number | no. of subjects |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("         |                        |     |       |              |                 |       Name     |Grade|Max Grade|\n");
    printf("~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~|~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~~~|\n");

    for(i=0; i<size; i++)
    {
        printf("%d |%24s| %2d  | %3c   | %4s  | %7d \t | ", arrSchool[i].ID,
                                                            arrSchool[i].name,
                                                            arrSchool[i].age,
                                                            arrSchool[i].grade,
                                                            arrSchool[i].phone,
                                                            arrSchool[i].noOfMaterials);

        c = 0;
        for(j=0; j<arrSchool[i].noOfMaterials; j++)
        {
            printf("%13s  | %2d  | %4d    |\n", arrSchool[i].materials[j].sub_name,
                                               arrSchool[i].materials[j].sub_grade,
                                               arrSchool[i].materials[j].max_grade);
            if(c < (arrSchool[i].noOfMaterials)-1)
            {
                printf("         |                        |     |       |              |                 | ");
            }
            c++;
        }
        if(arrSchool[i].noOfMaterials !=0)
        {
            printf("~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~|~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~~~|\n");
        }
        else
        {
            printf("\n~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~|~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~|~~~~~|~~~~~~~~~|\n");
        }
    }
}


int get_Max_Students(void)
{
    return noOfStudents;
}



#endif // SCHOOL_H_

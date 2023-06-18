
#define SCHOOL_SIZE 1000

typedef struct{
char sub_name[20];
int sub_grade;
int max_grade;

}subject_t;



typedef struct{
char name[50];
int ID;
int age;
char grade;
char phone[12];
int noOfMaterials;
subject_t* materials;

}student_t;

student_t school[SCHOOL_SIZE];


void SwapStudent(student_t* arr1, student_t* arr2);
int name_compare_sort(student_t* arr1, student_t* arr2);
void student_School_AlphabetSelectionSort(student_t* arrSchool, int size);


int string_scan(char *str, int maxsize);
char phone_scan(char* phone, char maxsize);
int Add_Material(student_t* Sub_Data, int Start_Material, int Last_Material);
int Add_Student(student_t* arrSchool, int MaxSize);

int Search_StudentByID(student_t* arrSchool, int MaxSize, int ID_Find);
void Print_Student(student_t* arrSchool);
void Edit_Student(student_t* arrStudent, int Edit_Index);
void Edit_Material(subject_t* Sub_Data);

int Delete_Student(student_t* arrStudent, int DeleteIndex);
void Delete_Material(subject_t* Sub_Data, int* MaxSize, int DeleteIndex);
void print_School(student_t* arrSchool, int noOfStudents);


void UpperToLower(char*str);
int string_compareNotCaseSenstive(char *str1, char *str2);
int Search_StudentByName(student_t* arrSchool, int MaxSize, char* Name_Find);

int get_Max_Students(void);





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
   char name[20];
   char usn[20];
   int age;
   int sem;
   int Attendance;
   int indivisualMarks;
   float marks;
};
typedef struct Student S;
struct node
{
    S info;
    struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not Allocated\n");
        exit(0);
    }
    return x;
}
void Showdetails(S s1)
{
    printf("Name of the Student=%s\n",s1.name);
    printf("USN:%s\n",s1.usn);
    printf("AGE of the Student:%d\n",s1.age);
    printf("Semester of the Student:%d\n",s1.sem);
    printf("Attendance:%d\n",s1.Attendance);
    printf("Overall marks scored:%f\n",s1.marks);
}
NODE insert_front(NODE first,S s1)
{
     NODE temp;
     temp=getnode();
     temp->info=s1;
     temp->link=first;
     return temp;
}
void sort(NODE first)
{
    S temp;
    NODE curr,next;
    int i=0;
    curr=first;
    while(curr->link!=NULL)
    {
        next=curr->link;
        while(next!=NULL)
        {
            if((curr->info).name[i]>(next->info).name[i])
            {
                temp=curr->info;
                curr->info=next->info;
                next->info=temp;
            }
            next=next->link;
        }
        curr=curr->link;
    }
}
void Attendence_Calculation(NODE first)
{
    int ispresent,count,days=1,lastDay;
    printf("Enter no of Days till which Attendance is to be considered\n");
    scanf("%d",&lastDay);
    while(1)
    {
        NODE curr;
        curr=first;
        if(lastDay<1)
            return;
    
        count=0;
        while(curr!=NULL)
        {
            
            printf("Enter 0->if student %s is not present on that day: %d,1->if the student is present\n",(curr->info).name,days);
            scanf("%d",&ispresent);
            if(ispresent==1)
            {
                printf("Student present\n");
                (curr->info).Attendance=1;
                
            }
            else
            {
                printf("Student is Absent\n");
                (curr->info).Attendance=0;
            }
            if(ispresent==1)
            {
                count++;
            printf("Displaying the Details of That Student\n");
            Showdetails(curr->info);
            }
            curr=curr->link;
        }
        if(count>0)
        {
            printf("Number of Students present on  day %d is %d\n",days,count);
        }
        if(lastDay<=days)
            break;
        days++;
    }
}
void display(NODE first)
{
    if(first==NULL)
        return;
    NODE t;
    t=first;
    int i=0;
    while(t!=NULL)
    {
       printf("Displaying the details of Student %d\n",i+1);
       printf("Name=%s\n",(t->info).name);
       printf("USN=%s\n",(t->info).usn);
       printf("Age=%d\n",(t->info).age);
       printf("Semester=%d\n",(t->info).sem);
       printf("Attendance=%d\n",(t->info).Attendance);
       printf("Marks=%f\n",(t->info).marks);
       i++;
       t=t->link;
    }    
}
int count(NODE first)
{
    if(first==NULL)
         return 0;
    int count2=0;
    NODE t=first;
    while(t!=NULL)
    {
        count2++;
        t=t->link;
    }     
    return count2;
}
void Calculate_Marks(NODE first)
{
     printf("*** flag3***");
     NODE curr;
     int totalMarks=0;
     curr=first;
     int n=count(first);
     int marks[5];
     while(curr!=NULL)
     {
        (curr->info).marks=0.0;
        printf("Entering the Marks of Student %s in 5 subjects,each of which is out of 60 marks,pls Enter within 60.",(curr->info).name);
        for(int i=0;i<5;i++)
        {
            scanf("%d",&marks[i]);
        }
        for(int i=0;i<5;i++)
        {
            (curr->info).marks+=marks[i];
        }
        (curr->info).indivisualMarks=(((curr->info).marks/300)*30)+10+10;
        printf("Marks of the Student %s out of 50 is %d\n",(curr->info).name,(curr->info).indivisualMarks);
        totalMarks+=(curr->info).indivisualMarks;
        curr=curr->link;
     }
     printf("\n\n flag2\n");
    int AvgMarks=totalMarks/n;
     printf("The Average Marks of All Students is %d\n",AvgMarks);
     curr=first;
     while(curr!=NULL)
     {
        if((curr->info).indivisualMarks>AvgMarks)
        {
            printf("Very Good Effort %s.Keep it Up.",(curr->info).name);
            Showdetails(curr->info);
        }
        else
        {
            printf("Can Do better Next time.Please improve and work Harder %s.All the best",(curr->info).name);
        }
        curr=curr->link;
     }
}
void file_display(NODE first)
{
    if(first==NULL)
        return;
    FILE *fptr;
    fptr=fopen("Student_Attendence.txt","w+");    
    NODE t;
    t=first;
    int i=0; 
    while(t!=NULL)
    {
       fprintf(fptr,"Displaying the details of Student %d\n",i+1);
       fprintf(fptr,"Name=%s\n",(t->info).name);
       fprintf(fptr,"USN=%s\n",(t->info).usn);
       fprintf(fptr,"Age=%d\n",(t->info).age);
       fprintf(fptr,"Semester=%d\n",(t->info).sem);
       fprintf(fptr,"Attendance=%d\n",(t->info).Attendance);
       fprintf(fptr,"Marks=%.2f\n\n",(t->info).marks);
       i++;
       t=t->link;
    }    
    fclose(fptr);
}
int main()
{
    NODE first=NULL;
    S student;
    int n;
    printf("Accept the no of Students\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Enter the Details of Student %d\n",i+1);
       printf("Initially please Enter Name,USN,Age,and Semester only");
       scanf("%s%s%d%d",student.name,student.usn,&student.age,&student.sem);
       student.Attendance=0;
       student.marks=0; 
       if(student.name[0]>90)
       {
            printf("Oops!Error!!\nWrite the first letter of the Name in Capitals");
            exit(0);
       }
       if(student.Attendance>0)
       {
         printf("Invalid.Please enter Marks as Zero initially\n");
         exit(0);
       }
       if(student.marks>0)
       {
         printf("Invalid.Please enter Marks as Zero initially\n");
         exit(0);
       }
      first=insert_front(first,student);
    }
    printf("Displaying the Unsorted list of Students\n");
    display(first);
    printf("\n\nflag1\n\n");
    sort(first);
    printf("Displaying the Sorted list of Students\n");
    display(first);
    printf("\nAttendance of Students:");
    Attendence_Calculation(first);
    printf("\n\nMarks Calculation\n");
    Calculate_Marks(first);
    file_display(first);
    return 0;
}
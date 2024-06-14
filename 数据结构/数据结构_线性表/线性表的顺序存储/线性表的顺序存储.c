//Creat table
#define MaxSize 10  //define the maximum length
typedef struct 
{   
    int data [MaxSize] ;//Use static arrays to store data elements
    int length;         //The current length of the sequence list
}SqList;                //Type definition of sequence table (static allocation method)

//initialize the table
void IntiList (SqList *L)
{
    for (int i = 0; i < MaxSize ; i++)
        L->data[i] = 0;
    L->length = 0;
}
//implement
int main()
{
    SqList L;
    InitiList(&L);
    return 0;
}


    

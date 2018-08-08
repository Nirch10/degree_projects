typedef queue STRUCT_TYPE;

typedef enum {Stack,Queue,OrderedList} StructType;

typedef enum {Int,Double,Char,String} StructDataType;

//Gets a struct ,Prints its data
//structToPrint: the struct to print 
//vars it gets :typeOfStruct- Enum declares the struct {Stack,Queue,OrderedList}
//dataType :Enum declares the type which the struct's value has {Int,Char}
//helper var: not really usefull ,but still important to be given - represents helper var the libraray uses (put 0)
//devider: the char array which will devide each printing
void PrintComplexStruct(STRUCT_TYPE *structToPrint, StructType typeOfStruct, StructDataType dataType,void *helperVar,char *devider);


//Gets Arrays, Prints its data 
void PrintArrayStruct(StructDataType arrayDataType, void* size, int dimension);
typedef queue STRUCT_TYPE;

typedef enum {Stack,Queue,OrderedList} StructType;

typedef enum {Int,Double,Char,String} StructDataType;

//gets a struct , and enum contains the struct type - prints its data
void Print(STRUCT_TYPE *structToPrint, StructType typeOfStruct, StructDataType dataType);


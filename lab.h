typedef struct militarytechnique{
	char type[40];
	char country[40];
	int amount;
}mt;

void create(mt **arr,int *n);
void read(mt **arr,int *n);
void write(mt *arr,int n);
void search(mt *arr,int n,int crit);



#include "lab4.h"
#define FILENAME "data.csv"



void Print(InventoryItem *array){
	for(int i = 0; i <10;i++){
		printf("ID: %d, Weight: %f, StockCount: %d, Colors:%hd\n", array[i].ID, array[i].weight, array[i].stockCount, array[i].colors);
	}
}

int main(void){
	FILE *fp = fopen(FILENAME, "r");
	InventoryItem *items;
	int size = 0;
	fscanf(fp, "%d", &size);
	printf("Size Scan returned: %d\n",size);
	
	items = makeArray(size, sizeof(InventoryItem));
	for(int i = 0;i<10;i++){
		fscanf(fp,"%d, %f, %d, %hd", &items[i].ID, &items[i].weight, &items[i].stockCount, &items[i].colors);
	}
	Print(items);
	
	int x = getSize((void *)items);
	printf("getSize returned: %d\n",x);
	float y = 2.5;
	int num = countWithWeight(items, y);
	printf("countWithWeight Returned: %d\n",num);
	
	freeArray((void *)items);
}
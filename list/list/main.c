#include <stdio.h>
#include <time.h>
#include <math.h>

struct list
{
	double value;
	struct list* next;
};

typedef struct list List;

void addValue(List* head, double value) {
	while (head->next != 0)
		head = head->next;

	head->next = (List*)malloc(sizeof(List));
	head->next->value = value;
	head->next->next = 0;
}

void addRandomValue(List* head) {
	double value = rand()%100 * 0.01 +25;
	while (head->next != 0)
		head = head->next;

	head->next = (List*)malloc(sizeof(List));
	head->next->value = value;
	head->next->next = 0;
}
void outputList(List* head) {
	while (head->next != 0) {
		printf("%f->", head->value);
		head = head->next;
	}
	printf("%f", head->value);
}

void addBeforeValue(List* head, double value) {
	while ((head->next->next != 0) && (fabs(head->next->value - value) > 0.001)) {
		head = head->next;
	}
	if (fabs(head->next->value - value) < 0.00001) {
		List* ptr = head->next;
		head->next = (List*)malloc(sizeof(List));
		head->next->value = rand() %100 * 0.01 + 25;
		head->next->next = ptr;
	}
	if (head->next->next == 0) {
		printf("Have no value\n");
		return;
	}
}



int main() {
	srand((unsigned int)time(0));

	List* l1 = (List*)malloc(sizeof(List));
	l1->next = 0;
	l1->value = rand()%100 * 0.01 + 25;
	//printf("value %f\n", l1->value);
	for (int i = 0; i < 5; i++) {
		addRandomValue(l1);
	}
	outputList(l1);
	printf("\n");
	double value;
	printf("Input value:");
	scanf_s("%lf", &value);
	printf("value: %lf\n", value);
	addBeforeValue(l1, value);
	outputList(l1);
	return 0;
}


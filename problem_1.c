#include <stdio.h>
#include <string.h>


char months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void report(double sales_numbers[]) {
	printf("Monthly sales report for 2022:\n\nMonth\t\tSales\n");
	for (int i = 0; i < 12; i++) {
		if (i == 1 || i == 8 || i == 10 || i == 11)   { 
			printf("%s\t$%.2lf\n", months[i], sales_numbers[i]);
		} else {
			printf("%s\t\t$%.2lf\n", months[i], sales_numbers[i]);	
		}
	}
}


double average(double sales_numbers[], int start, int end) {
	double result;
	double sum = 0;
	double num_of_terms = 0;
	for(int i = start; i <= end; i++) {
		num_of_terms++;
		sum += sales_numbers[i];
	}

	result = sum / num_of_terms;
	return result;
}






void summary(double sales_numbers[]) {
	printf("\n\nSales summary:\n\n");
	for (int i = 0; i < 12; i++) {
		double current_val = sales_numbers[i];
		int is_minimum = 1;
		for (int j = 0; j < 12; j++) {
			if (sales_numbers[j] <  current_val) {
				is_minimum = 0;
				break;
			}
		}

		if (is_minimum == 1) {
			printf("Minimum sales:\t$%.2lf    (%s)\n", current_val, months[i]);
			break;
		}
	}

	for (int i = 0; i < 12; i++) {
		double current_val = sales_numbers[i];
		int is_maximum = 1;
		for (int j = 0; j < 12; j++) {
			if (sales_numbers[j] >  current_val) {
				is_maximum = 0;
				break;
			}
			
		}
		
		if (is_maximum == 1) {
			printf("Maximum sales:\t$%.2lf    (%s)\n", current_val, months[i]);
			break;
		}
	}

	double the_average = average(sales_numbers, 0, 11);
	printf("Average sales:\t$%.2lf\n", the_average);

}



void moving_averages(double sales_numbers[]) {
	printf("\n\nSix-Month Moving Average Report:\n\n");
	int i = 0;
	while (i+5 <= 11) {
		double current_avg = average(sales_numbers, i, i+5);
		if (i == 1 || i == 8 || i == 10 || i == 11) {
			printf("%s\t-\t", months[i]);
		} else {
			printf("%s\t\t-\t", months[i]);
		}

		if (i+5 == 1 || i+5 == 8 || i+5 == 10 || i+5 == 11) {
			printf("%s\t$%.2lf\n", months[i+5], current_avg);
		} else {
			printf("%s\t\t$%.2lf\n", months[i + 5], current_avg);
		}	
		i++;
	}
}


void rank_sales(double sales_numbers[]) {
	printf("\n\nSales Report (Highest to Lowest)\n");
	printf("   Month\tSales\n\n");

	int month_order[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if ( j+1 < 12) {
				if (sales_numbers[j] < sales_numbers[j+1]) {
					double temp = sales_numbers[j];
					sales_numbers[j] = sales_numbers[j+1];
					sales_numbers[j+1] = temp;
					
					int temp2 = month_order[j];
					month_order[j]  = month_order[j+1];
					month_order[j+1] = temp2;
			
				}
			}
		}
	}




	for (int i = 0; i < 12; i++) {
		if (month_order[i] == 1 || month_order[i]  == 8 || month_order[i]  == 10 || month_order[i]  == 11) {
			printf("%s\t$%.2lf\n",months[month_order[i]], sales_numbers[i]);
		} else {
			printf("%s\t\t$%.2lf\n", months[month_order[i]], sales_numbers[i]);
		}
	}
}











void  main(){
	char file_name[70];
	printf("Enter a valid file name: ");
	gets(file_name);
	printf("\n");	


	FILE *input_file = fopen(file_name, "r");
	double  sales_numbers[12];
	for (int i = 0; i < 12; i++) {
		fscanf(input_file, "%lf", &sales_numbers[i]);
	}
	fclose(input_file);
	
	report(sales_numbers);

	summary(sales_numbers);
	
	moving_averages(sales_numbers);

	rank_sales(sales_numbers);
}

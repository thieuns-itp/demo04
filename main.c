#include <stdio.h>
#include <stdlib.h>
#include "sinhvien.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int chon,n;
	Hoc_vien ds[100];
	do {
		system("cls");
		printf("\n-------MENU--------");		
		printf("\n 1. Nhap thong tin hoc vien");
		printf("\n 2. Hien thi thong tin hoc vien");
		printf("\n 3. Tim thong tin hoc vien theo ma hoc vien");
		printf("\n 4. Ghi thong tin hoc vien vao tep");
		printf("\n 5. Doc thong tin hoc vien tu tep");
		printf("\n 0. Thoat");
		printf("\n-------------------");
		printf("\n Ban hay chon mot cong viec: ");scanf("%d",&chon);
		switch (chon)
		{
			case 1: 
				system("cls");
				printf("\n1. Nhap thong tin hoc vien\n");
				nhapdsHv(ds,&n);
				getch();
				break;
			case 2: 
				system("cls");
				printf("\n2. Hien thi thong tin hoc vien\n");
				indsHv(ds,n);
				getch();
				break;
			case 3: 
				system("cls");
				printf("\n3. Tim thong tin hoc vien theo ma hoc vien\n");
				timHvTheoMa(ds,n);
				getch();
				break;	
			case 4: 
				system("cls");
				printf("\n4. Ghi danh sach hoc vien vao tep\n");
				ghidsHv(ds,n);
				getch();
				break;	
			case 5: 
				system("cls");
				printf("\n5. Doc danh sach hoc vien tu tep\n");
				docdsHv(ds,&n);
				getch();
				break;	
		}
	} while (chon!=0);
	return 0;
}
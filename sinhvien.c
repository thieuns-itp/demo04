//
#include <stdio.h>
#include "sinhvien.h"

void nhapHv(Hoc_vien *h)
{
	fflush(stdin);
	printf("Nhap ma hoc vien:");gets(h->mahv);
	printf("Nhap ho ten:");gets(h->hoten);
	nhapNgay(&h->ns);
	printf("Nhap gioi tinh (0-nu,1-nam):");scanf("%d",&h->gt);
	fflush(stdin);
	printf("Nhap que quan:");gets(h->quequan);
	printf("Nhap lop:");gets(h->lop);
}

void inHv(Hoc_vien h)
{
	printf("\nMa hoc vien: %s",h.mahv);
	printf("\nHo ten: %s",h.hoten);
	printf("\nNgay sinh: ");inNgay(h.ns);
	printf("\nGioi tinh: %s",(h.gt!=0?"Nam":"Nu"));
	printf("\nQue quan: %s",h.quequan);
	printf("\nLop: %s",h.lop);
}

void nhapdsHv(Hoc_vien *a, int *n)
{
	int i;
	printf("So hoc vien muon nhap:");scanf("%d",n);
	for (i=0;i<*n;i++)
	{
		printf("\nHoc vien thu %d:\n",i+1);
		nhapHv(&a[i]);
	}
	printf("\nNhap du lieu thanh cong...");
}

void indsHv(Hoc_vien *a,int n)
{
	int i;
	printf("\nCac hoc vien da nhap:");
	for (i=0;i<n;i++)
	{
		printf("\nHoc vien thu %d:\n",i+1);
		inHv(a[i]);
	}
}

void timHvTheoMa(Hoc_vien *a,int n)
{
	char findText[15];
	int i;
	fflush(stdin);
	printf("\nNhap ma sinh vien muon tim:");gets(findText);
	for (i=0;i<n;i++)
		if (strcmp(a[i].mahv,findText)==0)
	 		{
	 			inHv(a[i]);
	 		}
}

void ghidsHv(Hoc_vien *a,int n)
{
	char tentep[50]; int i;
	FILE *fp;
	fflush(stdin);
	printf("\nNhap ten tep muon ghi:");gets(tentep);
	if ((fp=fopen(tentep,"w"))==NULL)
	{
		printf("\nLoi mo tep!");
		exit(1);
	}
	for (i=0;i<n;i++)
	{				
		fprintf(fp,"%s\n",a[i].mahv);
		fprintf(fp,"%s\n",a[i].hoten);
		fprintf(fp,"%d %d %d\n",a[i].ns.ngay,a[i].ns.thang,a[i].ns.nam);
		fprintf(fp,"%d\n",a[i].gt);
		fprintf(fp,"%s\n",a[i].quequan);
		fprintf(fp,"%s\n",a[i].lop);
	}
	fclose(fp);
	printf("\nGhi du lieu thanh cong...");
}

void docdsHv(Hoc_vien *a,int *n)
{
	char tentep[50]; 
	Hoc_vien temp;
	FILE *fp;
	fflush(stdin);
	printf("\nNhap ten tep muon doc:");gets(tentep);
	if ((fp=fopen(tentep,"r"))==NULL)
	{
		printf("\nLoi mo tep!");
		exit(1);
	}
	*n=0;
	while (fgets(temp.mahv,10,fp) != NULL)
    {   	
		fgets(temp.hoten,50,fp);
		fscanf(fp,"%d%d%d",&temp.ns.ngay,&temp.ns.thang,&temp.ns.nam);
		fscanf(fp,"%d",&temp.gt);
		fgetc(fp);
		fgets(temp.quequan,30,fp);
		fgets(temp.lop,10,fp);
		a[*n]=temp;
		inHv(a[*n]);
		*n++;
	}
	fclose(fp);
	printf("\nDoc du lieu thanh cong...");
}
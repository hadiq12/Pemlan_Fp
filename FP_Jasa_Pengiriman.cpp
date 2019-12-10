#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <bits/stdc++.h> 
using namespace std;

struct tgl_pengiriman{
	int tgl;
	int bln;
	int thn;
}dt[30];

struct data_pengiriman{
	char nama_pengirim[50];
	char alm_pengirim[50];
	char nama_penerima[50];
	char alm_penerima[50];
	int zip_code;
	int no_resi;
	int jns_pengiriman;
	int berat_brg;
	int total_hrg;
	struct tgl_pengiriman tbt;
}dp[30];

int x=0;

int jump_search(int a[], int low, int high, int val, int n){
	int step, i;
	step = n;
	for(i=0; i<step; i++)
	{
		if(val < a[step])
		high = step - 1;
		else
		low = step + 1;
	}
	for(i=low; i<=high; i++)
	{
		if(a[i] == val)
		return i;
	}
	return -1;
	}

int main (){
	
	int pilihan=1;
	int menu;
	int search;
	int y;
	struct data_pengiriman dp[50];
	int milih;




	
	while(pilihan==1){
	printf("|===============================================================|\n");
	printf("|                      INFORMATICS EXPRESS                      |\n");
	printf("|===============================================================|\n");
	printf("|1. Input Data                                                  |\n");
    printf("|2. Show Data                                                   |\n");
    printf("|3. Edit Data                                                   |\n");
    printf("|4. Search Data                                                 |\n");
    printf("|5. Sort Data                                                   | \n");
	printf("|6. keluar                                                      |\n");
	printf("|===============================================================|\n");
	printf("Choose Menu: ");
	scanf("%d",&menu);
	system("cls");
	
	switch(menu){		
		case 1:
		{
			printf("======================Informasi Data Diri======================\n");
			fflush(stdin);
			printf("Nama Pengirim: ");
			gets(dp[x].nama_pengirim);fflush(stdin);	
			printf("Alamat Pengirim: ");
			gets(dp[x].alm_pengirim);fflush(stdin);
			printf("Nama Penerima: ");
			gets(dp[x].nama_penerima);fflush(stdin);
			printf("Alamat Penerima: ");
			gets(dp[x].alm_penerima);fflush(stdin);
			printf("---------------------------------------------------------------\n\n");
					
			printf("========================Informasi Paket========================\n");
			fflush(stdin);
			printf("Tanggal Pengiriman\n");
			printf("Masukkan Tanggal: ");
			scanf("%d",&dt[x].tgl);
			printf("Masukkan Bulan: ");
			scanf("%d",&dt[x].bln);
			printf("Masukkan Tahun: ");
			scanf("%d",&dt[x].thn);
			printf("---------------------------------------------------------------\n");
			
			printf("Jenis Pengiriman\n");
			printf("1. Fast\n");
			printf("2. Flash\n");
			printf("Pilih Nomer: ");
			scanf("%d",&dp[x].jns_pengiriman);
			printf("---------------------------------------------------------------\n");
			
			printf("Berat Paket");		
			printf("Berat Barang (kg): ");
			scanf("%d",&dp[x].berat_brg);
			printf("---------------------------------------------------------------\n");
					
			printf("Tujuan Pengiriman\n");
			printf("1. Asgard (7751)\n");
			printf("2. Vinland (7752)\n");
			printf("3. Nilfheim (7753)\n");
			printf("4. Jotunheim (7754)\n");
			printf("Pilih ZIP Code Tujuan: ");
			scanf("%d",&dp[x].zip_code);
			fflush(stdin);
			printf("---------------------------------------------------------------\n");
			
			printf("Nomer Resi Paket");				
			printf("\n%d%d%d%d%d\n", dt[x].thn, dt[x].bln, dt[x].tgl, dp[x].zip_code, dp[x].jns_pengiriman);
			printf("Masukan No Resi (Diatas): ");
			scanf("%d", &dp[x].no_resi);
			
			dp[x].total_hrg = dp[x].jns_pengiriman*3000 + dp[x].berat_brg*6000 + (dp[x].zip_code-7750)*2000;
		
			printf ("Total Harga: %d\n", dp[x].total_hrg);
			printf("---------------------------------------------------------------\n");
					
			printf("Data Berhasil Disimpan !!");
			getch();
			system("cls");
			x++;					
		}
		break;
				
			
			
		case 2:
		{
			printf("Show Data\n");
			for(y=0;y<x;y++){
				printf("Nama Pengirim           : %s\n",dp[y].nama_pengirim);
				printf("Alamat Pengirim         : %s\n",dp[y].alm_pengirim);
				printf("Nama Penerima           : %s\n",dp[y].nama_penerima);
				printf("Alamat Penerima         : %s\n",dp[y].alm_penerima);
				printf("Tanggal Pengiriman      : %d-%d-%d\n",dt[y].tgl, dt[y].bln, dt[y].thn);
				printf("ZIP Code Penerima       : %d\n",dp[y].zip_code);
				printf("Jenis Pengiriman        : %d\n",dp[y].jns_pengiriman);
				printf("Berat Barang            : %d\n",dp[y].berat_brg);
				printf("No Resi                 : %d\n",dp[y].no_resi);
				printf("Total Harga             : %d\n",dp[y].total_hrg);
		
				printf("\n\n");
				}
				
				getch();
				system("cls");				
		}
		break;
		
		case 3:
		{
		
			
				
				
			
			
		}
		break;	
		
		case 4:
		{
			int i, n, tempzip[n], tempzip2[n], pos, val;
			
			for (int i=0; i<=n; i++){
				tempzip[i] = dp[i].zip_code;
			}
			for (int i=0; i<=n; i++){
				tempzip2[i] = dp[i].zip_code;
			}
	
			printf("Masukkan ZIP Code: ");
			scanf("%d", &val);
			fflush(stdin);
			
			pos = jump_search(tempzip, 0, n-1, val, n);
	
			if(pos == -1)
			printf("\n %d is not found in the array ", val);
			else
			printf("\n %d is found at position arry [%d]", val, pos);
			
		}
		break;

			
				
		case 5:
		{
					
		}
		break;
			
		
		}
		
		printf("\nApakah Anda Ingin Melakukan Aktivitas Lain ? \n");
		printf("1. Ya\n");
		printf("2. Tidak\n");
		scanf("%d",&pilihan);
		system("cls");
	}

}




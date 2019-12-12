#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

struct tb{
	int tanggal;
	int bulan;
	int tahun;
};


struct data{
	int no_resi;
	char nama_pengirim[50];
	char alm_pengirim[50];
	char nama_penerima[50];
	char alm_penerima[50];
	int zip_code;
	int jns_pengiririman;
	int berat;
	int total;
	struct tb tl;
}dt[100];

typedef struct data data;



int jump(int arr[], int jumlah, int cari){
	int m = sqrt(jumlah);
	int indexatas = m;
	int indexbawah = 0;
	int ketemu = 0;
	int index = -1;
	
	for (int i=0; i<(jumlah/m); i++){
		if (cari==arr[indexbawah]){
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (cari==arr[indexatas]){
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (cari>arr[indexbawah]&&cari<arr[indexatas]){
			for (int j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
				}
			}
			break;
		}
		else if (cari>arr[indexbawah]&&i==((jumlah/m)-1)){
			for (int j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
					break;
				}
			}
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		system("cls");
		printf("Data Not Found!");
		getch();
	}
	return index;
}


int strjump(char arr[][100], int jumlah, char data[][100]){
	char cari[100][100];
	strcpy(cari[0], data[0]);
	int m = sqrt(jumlah);
	int indexatas = m;
	int indexbawah = 0;
	int ketemu = 0;
	int index = -1;
	
	for (int i=0; i<=(jumlah/m); i++){
		if (strcmp(cari[0], arr[indexbawah])==0){
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (strcmp(cari[0], arr[indexatas])==0){
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (strcmp(cari[0], arr[indexbawah])>0&&strcmp(cari[0], arr[indexatas])<0){
			for (int j=indexbawah; j<indexatas; j++){
				if (strcmp(cari[0], arr[j])==0){
					index = j;
				}
			}
			ketemu = 1;
			break;
		}
		else if (strcmp(cari[0], arr[indexbawah])>0&&i==((jumlah/m)-1)){
			for (int j=indexbawah; j<indexatas; j++){
				if (strcmp(cari[0], arr[j])==0){
					index = j;
					ketemu = 1;
				}
			}
			break;
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	if (ketemu!=1){
		system("cls");
		printf("Data Not Found!");
		getch();
	}
	return index;
}




void mergeofarrays(int a[], int low, int mid, int high){
	int i = low, j = mid + 1, index = low, temp[100], k;
	while ((i <= mid) && (j <= high)){
    	if (a[i] < a[j]){
    		temp[index] = a[i];
    		i++;
    	}
	else{
    	temp[index] = a[j];
    	j++;
    }
    index++;
  	}

	if (i > mid){
    	while (j <= high){
    		temp[index] = a[j];
    		j++;
    		index++;
    	}
  	}
	else{
    	while (i <= mid){
			temp[index] = a[i];
    		i++;
    		index++;
    	}
  	}
  	for (k = low; k < index; k++){
    	a[k] = temp[k];
  	}
}


void mergesort(int a[], int low, int high){
  	if (low < high){
	    int middle = (low + high) / 2; 
    	mergesort(a, low, middle); 
    	mergesort(a, middle + 1, high); 
    	mergeofarrays(a, low, middle, high); 
  	}
}




int strpartition(char arr[][100], int low, int high){
	char pivot[100][100];
	strcpy(pivot[0],arr[high]);
	int index = low;
	char temp[100][100];
	
	for (int i=low; i<=(high-1); i++){
		if (strcmp(arr[i],pivot[0])<0){
			strcpy(temp[0], arr[i]);
			strcpy(arr[i], arr[index]);
			strcpy(arr[index], temp[0]);
			index++;
		}
	}
	strcpy(temp[0], arr[index]); 
	strcpy(arr[index], arr[high]);
	strcpy(arr[high], temp[0]);
	return index;
}


void strquick(char arr[][100], int awal, int akhir){
	if (awal < akhir){
		int index = strpartition(arr, awal, akhir);
		strquick(arr, awal, (index-1));
		strquick(arr, (index+1), akhir);
	}
}



int main(){
	
	srand(time(0));
	int a,b,i,j;
	int loop=1;
	int menu, menu1;
	int n=0, dat=0; 
	int ganti;
	int ceknoresi=0;
	int cektotal=0;
	int cekberat=0;
	
	while(loop==1){
		printf("|===================================|\n");
		printf("|        Informatics Express        |\n");
		printf("|===================================|\n");
		printf("|1. Input Data                      |\n");
		printf("|2. Show Data                       |\n");
		printf("|3. Search Data                     |\n");
		printf("|4. Edit Data                       |\n");
		printf("|5. Sort Data                       |\n");
		printf("|0. Exit                            |\n");
		printf("|===================================|\n");
		printf("Pilihan : ");
		scanf("%d",&menu);
		switch(menu){


			case 1:{
				dat=1;
				dt[n].no_resi = rand() &2019 + 15;
				fflush(stdin);
				system("cls");
				printf("======================================\n");
				printf("============= INPUT DATA =============\n");
				printf("======================================\n");

				printf("Nama Pengirim            : ");
				gets(dt[n].nama_pengirim);
				fflush(stdin);
				printf("Alamat Pengirim          : ");
				gets(dt[n].alm_pengirim);
				fflush(stdin);
				
				printf("Nama Penerima            : ");
				gets(dt[n].nama_penerima);
				fflush(stdin);
				printf("Alamat Penerima          : ");
				gets(dt[n].alm_penerima);
				fflush(stdin);
				
				printf("1. Asgard (7751)\n");
				printf("2. Vinland (7752)\n");
				printf("3. Nilfheim (7753)\n");
				printf("4. Jotunheim (7754)\n");
				printf("Pilih ZIP Code Tujuan    : ");
				scanf("%d",&dt[n].zip_code);
				
				printf("1. Fast\n");
				printf("2. Flash\n");
				printf("Jenis Pengiriman (nomer) : ");
				scanf("%d",&dt[n].jns_pengiririman);
				
				printf("Berat Paket              : ");
				scanf("%d",&dt[n].berat);
				
				printf("Tanggal Pengiriman       : ");
				scanf("%d",&dt[n].tl.tanggal);
				printf("Bulan Pengiriman         : ");
				scanf("%d",&dt[n].tl.bulan);
				
				dt[n].total = dt[n].berat*5000 + (dt[n].zip_code-7750)*3000 + dt[n].jns_pengiririman*3000;
				
				system("cls");
				
				n++;
				ceknoresi=0;
				cektotal=0;
				cekberat=0;
				system("cls");
				break;
			}


			case 2:{
				if(dat==0){
					system("cls");
					printf("Data belum diinputkan!\n");
					getch();
					system("cls");
				}
				else{
					system("cls");
					printf("======================================\n");
					printf("============= SHOW  DATA =============\n");
					printf("======================================\n");

					for(j=0;j<n;j++){
						printf("Data ke - %d\n",j+1);
						printf("No Resi                 : %d\n", dt[j].no_resi);
						printf("Nama Pengirim           : %s\n", dt[j].nama_pengirim);
						printf("Alamat Pengirim         : %s\n", dt[j].alm_pengirim);
						printf("Nama Penerima           : %s\n", dt[j].nama_penerima);
						printf("Alamat Penerima         : %s\n", dt[j].alm_penerima);
						printf("ZIP Code Tujuan         : %d\n", dt[j].zip_code);
						printf("Jenis Pengiriman        : %d\n", dt[j].jns_pengiririman);
						printf("Berat Barang            : %d\n", dt[j].berat);
						printf("Total Harga             : %d\n", dt[j].total);
						printf("Tanggal Pengiriman      : %d\n", dt[j].tl.tanggal);
						printf("Bulan Pengiriman        : %d\n", dt[j].tl.bulan);
						printf("======================================\n");
						b++;
					}
					getch();
					system("cls");
				}
				break;
			}


			case 3:{
				int cari, cari2, index;
				char coba[100][100];
				char caristr[100][100];
				int tempnoresi[n];
				char tempnamapengirim[30];
				char tempalmpengirim[30];
				char tempnamapenerima[30];
				char tempalmpenerima[30];
				int tempzip[n];
				int tempberat[n];
				int temptotal[n];
				int tempjnspengiriman[n];
				int temptanggal[n];
				int tempbulan[n];
				system("cls");
		
				printf("======================================\n");
				printf("============ SEARCH  DATA ============\n");
				printf("======================================\n");

				printf("1. No Resi\n");
				printf("2. Total Harga\n");
				printf("3. Berat Barang\n");
				printf("Pilih pencarian : ");scanf("%d",&menu1);fflush(stdin);
				switch (menu1){


					case 1://no resi
						if (ceknoresi==1){
							for (int i=0; i<=n; i++){
								tempnoresi[i] = dt[i].no_resi;
							}
							printf("Masukkan No Resi : ");scanf("%d",& cari);fflush(stdin);
							index = jump(tempnoresi, n, cari);	
							system("cls");
							cektotal=0;
							cekberat=0;
						}
						else{
							system("cls");
							printf("Harap Sorting No Resi!");
							getch();
							index=-1;
						}
							break;


					case 2://total harga
						if (cektotal==1){
							for (int i=0; i<=n; i++){
								temptotal[i] = dt[i].total;
							}
							printf("Masukkan Total Harga : ");scanf("%d",& cari);fflush(stdin);
							index = jump(temptotal, n, cari);	
							system("cls");
							ceknoresi=0;
							cekberat=0;
						}
						else{
							system("cls");
							printf("Harap Sorting Total Harga!");
							getch();
							index=-1;
						}
						break;


					case 3://berat barang
						if (cekberat==1){
							for (int i=0; i<n; i++){
								tempberat[i] = dt[i].berat;
							}
							printf("Masukkan Berat Barang : ");scanf("%d",& cari2);fflush(stdin);
							index = jump(tempberat, n, cari2);	
							system("cls");
							ceknoresi=0;
							cektotal=0;
						}
						else{
							system("cls");
							
							printf("Harap Sorting Berat Barang!");
							getch();
							index=-1;
						}
						break;
				}
				if (index!=-1){
					printf("Data ke - %d",j+1);printf("\n");b++;
					printf("No Resi                 : %d\n", dt[index].no_resi);
					printf("Nama Pengirim           : %s\n", dt[index].nama_pengirim);
					printf("Alamat Pengirim         : %s\n", dt[index].alm_pengirim);
					printf("Nama Penerima           : %s\n", dt[index].nama_penerima);
					printf("Alamat Penerima         : %s\n", dt[index].alm_penerima);
					printf("ZIP Code Tujuan         : %d\n", dt[index].zip_code);
					printf("Jenis Pengiriman        : %d\n", dt[index].jns_pengiririman);
					printf("Berat Barang            : %d\n", dt[index].berat);
					printf("Total Harga             : %d\n", dt[index].total);
					printf("Tanggal Pengiriman      : %d\n", dt[index].tl.tanggal);
					printf("Bulan Pengiriman        : %d\n", dt[index].tl.bulan);
					b++;
					getch();
				}
				system("cls");
				break;
			}


			case 4:{
				if (ceknoresi=1){
					int ganti, index;
					int tempnoresi[n];
					char tempnamapengirim[30];
					char tempalmpengirim[30];
					char tempnamapenerima[30];
					char tempalmpenerima[30];
					int tempzip[n];
					int tempberat[n];
					int temptotal[n];
					int tempjnspengiriman[n];
					int temptanggal[n];
					int tempbulan[n];
					for (int i=0; i<n; i++){
						tempnoresi[i] = dt[i].no_resi;
					}
					system("cls");
					fflush(stdin);
					printf("======================================\n");
					printf("============= EDIT  DATA =============\n");
					printf("======================================\n");

					printf("Masukkan No Resi : ");
					scanf("%d",& ganti);
					fflush(stdin);
					index = jump(tempnoresi, n, ganti);
					if(index!=-1){
						dt[index].no_resi = rand() &1001 + 11;
						fflush(stdin);
						system("cls");
						
						printf("Nama Pengirim            : ");
						gets(dt[index].nama_pengirim);
						fflush(stdin);
						printf("Alamat Pengirim          : ");
						gets(dt[index].alm_pengirim);
						fflush(stdin);
				
						printf("Nama Penerima            : ");
						gets(dt[index].nama_penerima);
						fflush(stdin);
						printf("Alamat Penerima          : ");
						gets(dt[index].alm_penerima);
						fflush(stdin);
				
						printf("1. Asgard (7751)\n");
						printf("2. Vinland (7752)\n");
						printf("3. Nilfheim (7753)\n");
						printf("4. Jotunheim (7754)\n");
						printf("Pilih ZIP Code Tujuan    : ");
						scanf("%d",&dt[index].zip_code);
				
						printf("1. Fast\n");
						printf("2. Flash\n");
						printf("Jenis Pengiriman (nomer) : ");
						scanf("%d",&dt[index].jns_pengiririman);
				
						printf("Berat Paket              : ");
						scanf("%d",&dt[index].berat);
				
						printf("Tanggal Pengiriman       : ");
						scanf("%d",&dt[index].tl.tanggal);
						printf("Bulan Pengiriman         : ");
						scanf("%d",&dt[index].tl.bulan);
				
						dt[index].total = dt[index].berat*5000 + (dt[index].zip_code-7750)*3000 + dt[index].jns_pengiririman*3000;
				
						printf("Data Berhasil Diupdate!");
						getch();
					}
					system("cls");
					cektotal=0;
					cekberat=0;
				}
				else{
					system("cls");
					printf("Harap Sorting Data!");
					getch();
				}
				break;
			}


			case 5:{
				system("cls");
				char temp[100][100];
				int tempi[n];
				int tempnoresi[n];
				char tempnamapengirim[30];
				char tempalmpengirim[30];
				char tempnamapenerima[30];
				char tempalmpenerima[30];
				int tempzip[n];
				int tempberat[n];
				int temptotal[n];
				int tempjnspengiriman[n];
				int temptanggal[n];
				int tempbulan[n];
				printf("======================================\n");
				printf("============= SORT  DATA =============\n");
				printf("======================================\n");

				printf("1. No Resi\n");
				printf("2. Nama Pengirim\n");
				printf("3. Alamat Pengirim\n");
				printf("4. Nama Penerima\n");
				printf("5. Alamat Penerima\n");
				printf("6. ZIP Code\n");
				printf("7. Total\n");
				printf("8. Jenis Pengiriman\n");
				printf("9. Berat\n");
				printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch(menu1){

					
					case 1://no resi
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].no_resi;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].no_resi){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						ceknoresi=1;
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;

						
					case 2://nama pengirim
						fflush(stdin);
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].nama_pengirim);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].nama_pengirim)==0){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;


					case 3://alamat pengirim
						fflush(stdin);
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].alm_pengirim);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].alm_pengirim)==0){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;


					case 4://nama pengirim
						fflush(stdin);
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].nama_penerima);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].nama_penerima)==0){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;


					case 5://alamat pengirim
						fflush(stdin);
						for (int i=0; i<=n; i++){
							strcpy(temp[i], dt[i].alm_penerima);
						}
						strquick(temp, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (strcmp(temp[i], dt[j].alm_penerima)==0){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;


					case 6://zip code
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].zip_code;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].zip_code){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;

					
					case 7://total
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].total;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].total){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
								}
							}
						}
						cektotal=1;
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;

						
					case 8://jenis pengiriman
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].jns_pengiririman;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].jns_pengiririman){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									tempjnspengiriman[i] = dt[i].jns_pengiririman;
									tempberat[i] = dt[i].berat;				
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
									dt[i].jns_pengiririman = dt[j].jns_pengiririman;
									dt[i].berat = dt[j].berat;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
									dt[j].jns_pengiririman = tempjnspengiriman[i];
									dt[i].berat = tempberat[i];	
									
								}
							}
						}
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;

					
					case 9://berat
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].berat;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].berat){
									tempnoresi[i] = dt[i].no_resi;
									strcpy(tempnamapengirim, dt[i].nama_pengirim);
									strcpy(tempalmpengirim, dt[i].alm_pengirim);
									strcpy(tempnamapenerima, dt[i].nama_penerima);
									strcpy(tempalmpenerima, dt[i].alm_penerima);
									tempzip[i] = dt[i].zip_code;
									temptotal[i] = dt[i].total;
									temptanggal[i] = dt[i].tl.tanggal;
									tempbulan[i] = dt[i].tl.bulan;
									tempjnspengiriman[i] = dt[i].jns_pengiririman;
									tempberat[i] = dt[i].berat;				
									
									dt[i].no_resi = dt[j].no_resi;
									strcpy(dt[i].nama_pengirim, dt[j].nama_pengirim);
									strcpy(dt[i].alm_pengirim, dt[j].alm_pengirim);
									strcpy(dt[i].nama_penerima, dt[j].nama_penerima);
									strcpy(dt[i].alm_penerima, dt[j].alm_penerima);
									dt[i].zip_code = dt[j].zip_code;
									dt[i].total = dt[j].total;
									dt[i].tl.tanggal = dt[j].tl.tanggal;
									dt[i].tl.bulan = dt[j].tl.bulan;
									dt[i].jns_pengiririman = dt[j].jns_pengiririman;
									dt[i].berat = dt[j].berat;
								
									dt[j].no_resi = tempnoresi[i];
									strcpy(dt[j].nama_pengirim, tempnamapengirim);
									strcpy(dt[j].alm_pengirim, tempalmpengirim);
									strcpy(dt[j].nama_penerima, tempnamapenerima);
									strcpy(dt[j].alm_penerima, tempalmpenerima);
									dt[j].zip_code = tempzip[i];
									dt[j].total = temptotal[i];
									dt[j].tl.tanggal = temptanggal[i];
									dt[j].tl.bulan = tempbulan[i];
									dt[j].jns_pengiririman = tempjnspengiriman[i];
									dt[i].berat = tempberat[i];	
								}
							}
						}
						cekberat=1;
						getch();
						system("cls");
						printf("Data telah di sort!");
						getch();
						system("cls");
						break;
					
				}	
				break;
			}
			case 0:
				loop=0;
				exit(0);
				break;
		}
	}	
}

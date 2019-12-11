#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>


struct ttl{
	int tanggal;
	int bulan;
};
struct data{
	int no_resi;
	char nama_pengirim[30];
	char alm_pengirim[30];
	char nama_penerima[30];
	char alm_penerima[30];
	int zip_code;
	int jns_pengiririman;
	int berat;
	int total;
	struct ttl tl;
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
		printf("Data Tidak Ditemukan !!!");
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
		printf("Data Tidak Ditemukan !!!");
		getch();
	}
	return index;
}

void mergeofarrays(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, temp[100], k;
  while ((i <= mid) && (j <= high)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }
  //copy the remaining elements of right array
  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      j++;
      index++;
    }
  } else //remaining elements of left array
  {
    while (i <= mid) {
      temp[index] = a[i];
      i++;
      index++;
    }
  }
  for (k = low; k < index; k++) //copying into original array
  {
    a[k] = temp[k];
  }
}
void mergesort(int a[], int low, int high) {
  if (low < high) {
    int middle = (low + high) / 2; //calculating middle index of array to divide it in two halves
    mergesort(a, low, middle); //sorting first half
    mergesort(a, middle + 1, high); //sorting second half
    mergeofarrays(a, low, middle, high); //merging 2 sorted halves
  }
}


int strpartition(char arr[][100], int awal, int akhir){
	char pivot[100][100];
	strcpy(pivot[0],arr[akhir]);
	int index = awal;
	char temp[100][100];
	
	for (int i=awal; i<=(akhir-1); i++){
		if (strcmp(arr[i],pivot[0])<0){
			strcpy(temp[0], arr[i]);
			strcpy(arr[i], arr[index]);
			strcpy(arr[index], temp[0]);
			index++;
		}
	}
	strcpy(temp[0], arr[index]); 
	strcpy(arr[index], arr[akhir]);
	strcpy(arr[akhir], temp[0]);
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
	int a,b,i,j,loop=1,menu,menu1,orang=0,n=0,dat=0,sort,ganti,ceknoresi=0,ceknamapengirim=0,cekzip=0;
	char cganti[10],ccari[10];
	while(loop==1){
		
		printf("Menu : \n");
		printf("1. Input Data\n");
		printf("2. Show Data\n");
		printf("3. Search Data\n");
		printf("4. Edit Data\n");
		printf("5. Sort Data\n");
		puts("0. X-it\n");
		printf("Pilihan : ");
		scanf("%d",&menu);
		switch(menu){
			case 1:{//input
				dat=1;
				dt[n].no_resi = rand() &1001 + 11;
				fflush(stdin);
				system("cls");
				printf("Nama Pengirim\t\t: ");b++;
				gets(dt[n].nama_pengirim);
				printf("Alamat Pengirim\t\t: ");b++;
				gets(dt[n].alm_pengirim);
				
				printf("Nama Penerima\t\t: ");b++;
				gets(dt[n].nama_penerima);
				fflush(stdin);
				printf("Alamat Penerima\t\t: ");b++;
				gets(dt[n].alm_penerima);
				fflush(stdin);
				
				printf("1. Asgard (7751)\n");
				printf("2. Vinland (7752)\n");
				printf("3. Nilfheim (7753)\n");
				printf("4. Jotunheim (7754)\n");
				printf("Pilih ZIP Code Tujuan: ");
				scanf("%d",&dt[n].zip_code);
				
				printf("1. Fast\n");
				printf("2. Flash\n");
				printf("Jenis Pengiriman\t\t: ");b++;
				scanf("%d",&dt[n].jns_pengiririman);
				
				printf("Berat Paket\t\t: ");b++;
				scanf("%d",&dt[n].berat);
				
				printf("Tanggal Pengiriman\t\t: ");b++;
				scanf("%d",&dt[n].tl.tanggal);
				printf("Bulan Pengiriman\t\t: ");b++;
				scanf("%d",&dt[n].tl.bulan);
				
				dt[n].total = dt[n].berat*5000 + (dt[n].zip_code-7750)*3000 + dt[n].jns_pengiririman*3000;
				
				system("cls");
				n++;
				ceknoresi=0;
				ceknamapengirim=0;
				cekzip=0;
				system("cls");
				break;
			}
			case 2:{//history
				if(dat==0){
					system("cls");
					printf("Data belum di inputkan\n");
					getch();
					system("cls");
				}
				else{
					system("cls");
					
					for(j=0;j<n;j++){
						printf("Data ke - %d",j+1);printf("\n");b++;
						printf("No Resi                 : %d\n", dt[j].no_resi);b++;
						printf("Nama Pengirim           : %s\n", dt[j].nama_pengirim);b++;
						printf("Alamat Pengirim         : %s\n", dt[j].alm_pengirim);b++;
						printf("Nama Penerima           : %s\n", dt[j].nama_penerima);b++;
						printf("Alamat Penerima         : %s\n", dt[j].alm_penerima);b++;
						printf("ZIP Code Tujuan         : %d\n", dt[j].zip_code);b++;
						printf("Jenis Pengiriman        : %d\n", dt[j].jns_pengiririman);b++;
						printf("Berat Barang            : %d\n", dt[j].berat);b++;
						printf("Total Harga             : %d\n", dt[j].total);b++;
						printf("Tanggal Pengiriman      : %d\n", dt[j].tl.tanggal);b++;
						printf("Bulan Pengiriman        : %d\n", dt[j].tl.bulan);b++;
						b++;
					}
					getch();
					system("cls");
				}
				break;
			}
			case 3:{//search
				int cari, cari2, index;
				char coba[100][100];
				char caristr[100][100];
				int tempnoresi[n];
				char tempnamapengirim[30];
				char tempalmpengirim[30];
				char tempnamapenerima[30];
				char tempalmpenerima[30];
				int tempzip[n];
				int temptotal[n];
				int temptanggal[n];
				int tempbulan[n];
				system("cls");
		
				printf("List : \n");
				printf("1. No Resi\n");
				printf("2. Nama Pengirim\n");
				printf("3. ZIP Code\n");
				printf("Pilih : ");scanf("%d",&menu1);fflush(stdin);
				switch (menu1){
					case 1://no resi
						if (ceknoresi==1){
							for (int i=0; i<=n; i++){
								tempnoresi[i] = dt[i].no_resi;
							}
							printf("Masukkan No Resi: ");scanf("%d",& cari);fflush(stdin);
							index = jump(tempnoresi, n, cari);	
							system("cls");
							ceknamapengirim=0;
							cekzip=0;
						}
						else{
							system("cls");
							printf("Harap Melakukan Sorting No Resi!");
							getch();
							index=-1;
						}
							break;
					case 2://nama pengirim
						if (ceknamapengirim==1){
							for (int i=0; i<=n; i++){
								strcpy(coba[i], dt[i].nama_pengirim);
							}
							fflush(stdin);
							printf("Masukkan Nama Pengirim: ");gets(caristr[0]);
							index = strjump(coba, n, caristr);
							system("cls");
							ceknoresi=0;
							cekzip=0;
						}
						else{
							system("cls");
							printf("Harap Melakukan Sorting Nama Pengirim!");
							getch();
							index=-1;
						}
						break;
					case 3://zip code
						if (cekzip==1){
							for (int i=0; i<n; i++){
								tempzip[i] = dt[i].zip_code;
							}
							printf("Masukkan ZIP Tujuan: ");scanf("%d",& cari2);fflush(stdin);
							index = jump(tempzip, n, cari2);	
							system("cls");
							ceknoresi=0;
							ceknamapengirim=0;
						}
						else{
							system("cls");
							
							printf("Harap Melakukan Sorting ZIP code!");
							getch();
							index=-1;
						}
						break;
				}
				if (index!=-1){
					printf("Data ke - %d",j+1);printf("\n");b++;
					printf("No Resi                 : %d\n", dt[index].no_resi);b++;
					printf("Nama Pengirim           : %s\n", dt[index].nama_pengirim);b++;
					printf("Alamat Pengirim         : %s\n", dt[index].alm_pengirim);b++;
					printf("Nama Penerima           : %s\n", dt[index].nama_penerima);b++;
					printf("Alamat Penerima         : %s\n", dt[index].alm_penerima);b++;
					printf("ZIP Code Tujuan         : %d\n", dt[index].zip_code);b++;
					printf("Jenis Pengiriman        : %d\n", dt[index].jns_pengiririman);b++;
					printf("Berat Barang            : %d\n", dt[index].berat);b++;
					printf("Total Harga             : %d\n", dt[index].total);b++;
					printf("Tanggal Pengiriman      : %d\n", dt[index].tl.tanggal);b++;
					printf("Bulan Pengiriman        : %d\n", dt[index].tl.bulan);b++;
					b++;
					getch();
				}
				system("cls");
				break;
			}
			case 4:{//ubah
				if (ceknoresi=1){
					int ganti, index;
					int tempnoresi[n];
					char tempnamapengirim[30];
					char tempalmpengirim[30];
					char tempnamapenerima[30];
					char tempalmpenerima[30];
					int tempzip[n];
					int temptotal[n];
					int temptanggal[n];
					int tempbulan[n];
					for (int i=0; i<n; i++){
						tempnoresi[i] = dt[i].no_resi;
					}
					system("cls");
					fflush(stdin);
					printf("Masukkan No Resi: ");scanf("%d",& ganti);fflush(stdin);b++;
					index = jump(tempnoresi, n, ganti);
					if(index!=-1){
						dt[n].no_resi = rand() &1001 + 11;
						fflush(stdin);
						system("cls");
						printf("Nama Pengirim\t\t: ");b++;
						gets(dt[n].nama_pengirim);
						printf("Alamat Pengirim\t\t: ");b++;
						gets(dt[n].alm_pengirim);
				
						printf("Nama Penerima\t\t: ");b++;
						gets(dt[n].nama_penerima);
						fflush(stdin);
						printf("Alamat Penerima\t\t: ");b++;
						gets(dt[n].alm_penerima);
						fflush(stdin);
				
						printf("1. Asgard (7751)\n");
						printf("2. Vinland (7752)\n");
						printf("3. Nilfheim (7753)\n");
						printf("4. Jotunheim (7754)\n");
						printf("Pilih ZIP Code Tujuan: ");
						scanf("%d",&dt[n].zip_code);
				
						printf("1. Fast\n");
						printf("2. Flash\n");
						printf("Jenis Pengiriman\t\t: ");b++;
						scanf("%d",&dt[n].jns_pengiririman);
				
						printf("Berat Paket\t\t: ");b++;
						scanf("%d",&dt[n].berat);
				
						printf("Tanggal Pengiriman\t\t: ");b++;
						scanf("%d",&dt[n].tl.tanggal);
						printf("Bulan Pengiriman\t\t: ");b++;
						scanf("%d",&dt[n].tl.bulan);
				
						dt[n].total = dt[n].berat*5000 + (dt[n].zip_code-7750)*3000 + dt[n].jns_pengiririman*3000;
				
						printf("Data Berhasil Diupdate !!!");
						getch();
					}
					system("cls");
					ceknamapengirim=0;
					cekzip=0;
				}
				else{
					system("cls");
					printf("Harap Melakukan Sorting ID Terlebih Dahulu !!!");
					getch();
				}
				break;
			}
			case 5:{//sort
				system("cls");
				char temp[100][100];
				int tempi[n];
				int tempnoresi[n];
				char tempnamapengirim[30];
				char tempalmpengirim[30];
				char tempnamapenerima[30];
				char tempalmpenerima[30];
				int tempzip[n];
				int temptotal[n];
				int temptanggal[n];
				int tempbulan[n];
				printf("List : \n");
				printf("1. No Resi\n");
				printf("2. Nama Pengirim\n");
				printf("3. Alamat Pengirim\n");
				printf("4. Nama Penerima\n");
				printf("5. Alamat Penerima\n");
				printf("6. ZIP Code\n");
				printf("7. Total\n");
				printf("8. Tanggal\n");
				printf("9. Bulan\n");
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
						printf("Data Berhasil Diurutkan !!!");
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
						ceknamapengirim=1;
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
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
						printf("Data Berhasil Diurutkan !!!");
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
						printf("Data Berhasil Diurutkan !!!");
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
						printf("Data Berhasil Diurutkan !!!");
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
						cekzip=1;
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
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
						getch();
						system("cls");
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
						
					case 8://tanggal
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].tl.tanggal;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].tl.tanggal){
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
						printf("Data Berhasil Diurutkan !!!");
						getch();
						system("cls");
						break;
					
					case 9://bulan
						for (int i=0; i<=n; i++){
							tempi[i] = dt[i].tl.bulan;
						}
						mergesort(tempi, 0, (n-1));
						for (int i=0; i<(n-1); i++){
							for (int j=0; j<n; j++){
								if (tempi[i]==dt[j].tl.bulan){
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
						printf("Data Berhasil Diurutkan !!!");
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

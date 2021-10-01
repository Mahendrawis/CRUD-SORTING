#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void TambahMHS();
void TampilMHS();
void UpdateMHS();
void DeleteMHS();
void menu();
void close();
void sort();
struct mahasiswa
{
	int nim,id; 
	char nama[26];
 	float ipk;
 	int tampung;
}tambah,cek,sorts[100],temp,hapus;
int pilih;

int main(){
	system("cls");
		printf("Now Loading");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	menu();
	return 0;
}
void menu(){
menu:
	printf("\n Pilih Menu : ");
	printf("\n [1] input data mahasiswa");
	printf("\n [2] tampil data mahasiswa");
	printf("\n [3] edit data mahasiswa");
	printf("\n [4] delete data mahasiswa");
	printf("\n [5] sort data");
	printf("\n [6] exit");
	printf("\nMasukan Pilihan Menu : ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1:
			TambahMHS();
			goto menu;
			
		case 2:
			TampilMHS();
			goto menu;
			
		case 3:
			UpdateMHS();
			goto menu;

		case 4:
			DeleteMHS();
			goto menu;
			
		case 5:
			sort();
			goto menu;	
			
		case 6:
			exit(0);
			break;	
	}
}
void TambahMHS(){
	FILE *ptr,*ptr1;
	int count=0;
	
	ptr =fopen("CRUD.txt","a");
		system("cls");
		ptr1 =fopen("CRUD.txt","r");
		while (fscanf(ptr1,"%d;%[^;];%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk)!=EOF)
		{
			tambah.id++;	
		}
		cek.id = tambah.id;
		fclose(ptr1);
		printf ("masukan nama  : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("masukan NIM   : ");fflush(stdin);
		scanf ("%d",&tambah.nim); 
		printf("Nilai IPK      : ");
		scanf("%f",&tambah.ipk);
		fprintf(ptr,"%d;%s;%d;%f\n",tambah.id,tambah.nama,tambah.nim,tambah.ipk);
		fclose(ptr);
	
		printf("\n\nData Mahasiswa Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void TampilMHS(){
	FILE *view;
	int test=0;
	view=fopen("CRUD.txt","r");
	printf("%s %s %s %s \n\n", "ID","Nama", "NIM", "IPK");
	while(fscanf(view,"%d;%[^;];%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk)!=EOF)
		{
			printf("%d %s %d %f \n",tambah.id,tambah.nama,tambah.nim,tambah.ipk);
			test++;
		}
	printf("\n");
	printf("jumlah banyak data mahasiswa : %d ", test);
	fclose(view);
		if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void close(){
}
void UpdateMHS(){
	int test=0;
	FILE *lama,*baru;
	lama = fopen("CRUD.txt","a");
	baru = fopen("CRUD.txt","w");
	system("cls");
	
	printf("masukan id mahasiswa : ");
	scanf("%d",&cek.id);
	while(fscanf(lama,"%d;%[^;];%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk)!=EOF){
		if(tambah.id==cek.id){
				printf("\nNo. ID : %d dimiliki Mahasiswa dengan Nama : %s", tambah.id, tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. NAMA");
				printf("\n[2]. NIM");
				printf("\n[3]. IPK");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				if(pilih==1)
				{
					printf("\nMasukan Nama : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih==2)
				{
					printf ("\nMasukan Data NIM baru : ");fflush(stdin);
					scanf ("%d",&cek.nim);
					tambah.nim=cek.nim;
					fprintf(baru,"%d;%s;%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih==3)
				{
					printf ("\nMasukan IPK baru : ");
					scanf ("%f",&cek.ipk);
					tambah.ipk = cek.ipk;
						fprintf(baru,"%d;%s;%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk);	
					printf ("\nPerubahan Sudah Disimpan !");
				}else{
					printf("\n\nInput Anda Salah !");
				}			
		} 
	else
		{
			fprintf(baru,"%d;%s;%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("CRUD.txt");
	rename("baru.txt","CRUD.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': UpdateMHS();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

void DeleteMHS()
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("CRUD.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. ID Mahasiswa yang akan di hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk)!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%d;%f",tambah.id,tambah.nama,tambah.nim,tambah.ipk);	
		}
		else{
			test++;
			printf("\nData Mahasiswa No ID : %d dengan Nama : %s\n",tambah.id,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("CRUD.txt");
	rename("baru.txt","CRUD.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': DeleteMHS();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
	
}

void sort(){
	system("cls");
	FILE *sortdata;
	int count=0,i,j,test=0,pilih;
	system("cls");
	printf ("MENAMPILKAN TOTAL NILAI ASCENDING\n");
	sortdata=fopen("CRUD.txt","r");
	while(fscanf(sortdata,"%d;%[^;];%d;%f",&tambah.id,tambah.nama,&tambah.nim,&tambah.ipk)!=EOF) {
		
		sorts[count].nim = tambah.nim;
		sorts[count].tampung = tambah.ipk;
		sorts[count].id = tambah.id;
		strcpy(sorts[count].nama,tambah.nama);
		count++;
		test=1;
	}	
	back:
	printf ("\n");
	printf ("1.METODE ASCENDING\n");
	printf ("Masukan Nomer :");
	scanf ("%d", &pilih);
	if(pilih==1)
	{
		printf ("ID\tNAMA\tNIM\tIPK\n");
		for(i=0;i<count-1;i++){
			for(j=i+1;j<count;j++)
			{
				if(sorts[i].tampung > sorts[j].ipk)
				{
					temp = sorts[j];
					sorts[j] = sorts[i];
					sorts[i] = temp;
				}
			}
		}
		for(i=0;i<count;i++)
		{
			printf("%d\t%s\t%d\t%d\n",sorts[i].id,sorts[i].nama,sorts[i].nim,sorts[i].tampung);
		}
	} else {
		printf ("Salah INPUT!\n");
		getch();
		goto back;
	}
	fclose(sortdata);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': sort();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}
	


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//taş = 0
//kağıt = 1
//makas = 2


//BURADAKİ FONKSİYON PARAMETRE OLARAK BİLGİSAYARIN SEÇTİĞİ DEĞERLERİ ALIR VE 
// VERİLEN KURALA GÖRE DEĞERLENDİRİR İŞLEMİN SONUCUNDA KİMİN KAZANDIĞINI DÖNDÜRÜR

int kazananOyuncu(int oyuncu1, int oyuncu2) {
	if (oyuncu1 == oyuncu2) {
		return 0; //Beraberlik durumu.
	}
	else if((oyuncu1==0 and oyuncu2==2) or
		(oyuncu1 == 1 and oyuncu2 == 0) or
		(oyuncu1 == 2 and oyuncu2 == 1)) {
		return 1; //Birinci oyuncunun yenmesi durumu.
	}
	else {
		return 2; //İkinci oyuncunun yenmesi durumu.
	}
	return 0;
}


int main() {

	srand(time(NULL)); //Sürekli farklı değerler üretmek için srand() fonksiyonunu kullandım.
	int turSayisi;
	int kazanan1 = 0, kazanan2 = 0,beraberlik=0; //kazanan oyuncunun galibiyet sayısını tutmak için kullanılacak değişkenler.

	setlocale(LC_ALL, "Turkish");
	
	printf("Oyun kaç tur oynansın: ");
	scanf("%d", &turSayisi);
	
	//BU BÖLÜMDE OYUNUN KAÇ TUR OYNANACAĞINA GÖRE OLUŞTURULMUŞ BİR DÖNGÜ 
	// VE SEÇİMLERİN SONUÇLARINA GÖRE KAZANAN OYUNCUNUN HANESİNE + EKLEYEN KISIM BULUNUYOR.
	for (int i = 0; i < turSayisi; i++) {
		
		int oyuncu1Secim = rand() % 3;  //YALNIZCA 0,1 VE 2 DEĞERLERİNİ DÖNDÜREBİLMEK İÇİN %3 İLE SINIRLANDIRDIM.
		int oyuncu2Secim = rand() % 3;
		printf("Tur %d:\n", i + 1);
		printf("Oyuncu1'in seçimi: %d, Oyuncu2'nin seçimi:%d\n", oyuncu1Secim, oyuncu2Secim);
		int kazanan = kazananOyuncu(oyuncu1Secim, oyuncu2Secim);

		if (kazanan == 1) {
			kazanan1++;
			printf("Bu turu Oyuncu1 kazandı.");
		}
		else if (kazanan == 2) {
			kazanan2++;
			printf("Bu turu Oyuncu2 kazandı.");
		}
		else {
			beraberlik++;
			printf("Beraberlik");
		}
		printf("\n");
	}

	//
	if (kazanan1 > kazanan2) {
		printf("\nOyunun kazananı Oyuncu1  %d galibiyet!\n",kazanan1);
	}
	else if (kazanan2 > kazanan1) {
		printf("\nOyunun kazananı Oyuncu2  %d galibiyet!\n",kazanan2);
	}
	else {
		printf("\nBeraberlik.Oyuncu1: %d\nOyuncu2: %d\nBerabere: %d\n",kazanan1,kazanan2,beraberlik);
	}


	return 0;
}
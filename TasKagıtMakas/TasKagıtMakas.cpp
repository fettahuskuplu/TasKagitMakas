// 1221602632 FETTAH ÜSKÜPLÜ

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
	else if((oyuncu1==0 && oyuncu2==2) ||
		(oyuncu1 == 1 && oyuncu2 == 0) ||
		(oyuncu1 == 2 && oyuncu2 == 1)) {
		return 1; //Birinci oyuncunun yenmesi durumu.
	}
	else {
		return 2; //İkinci oyuncunun yenmesi durumu.
	}
	return 0;
}


int main() {

	srand(time(NULL)); //Sürekli farklı değerler üretmek için srand() fonksiyonunu kullandım.
	int secim;
	int turSayisi;
	int kazanan1 = 0, kazanan2 = 0,beraberlik=0; //kazanan oyuncunun galibiyet sayısını tutmak için kullanılacak değişkenler.
	int dongu = 1;
	const char *secimler[] = { "Taş","Kağıt","Makas" };

	setlocale(LC_ALL, "Turkish");

	//MENÜ KISMINI YÖNETEBİLMEK İÇİN BİR WHİLE DÖNGÜSÜ VE SWITCH CASE YAPISINDAN YARARLANDIM.
	while (dongu) { 
		printf("\nTaş Kağıt Makas oyununa hoşgeldiniz!\n\n-- MENÜ --\n1-)Oyuna başla.\n2-)Kurallar.\n3-)Çıkış.\n\nSeçiminiz: ");
		scanf("%d", &secim);
		switch (secim) {
		case 1:
			printf("\nOyun kaç tur oynansın: ");
			scanf("%d", &turSayisi);

			//BU BÖLÜMDE OYUNUN KAÇ TUR OYNANACAĞINA GÖRE OLUŞTURULMUŞ BİR DÖNGÜ 
			// VE SEÇİMLERİN SONUÇLARINA GÖRE KAZANAN OYUNCUNUN HANESİNE + EKLEYEN KISIM BULUNUYOR.
			for (int i = 0; i < turSayisi; i++) {

				int oyuncu1Secim = rand() % 3;  //YALNIZCA 0,1 VE 2 DEĞERLERİNİ DÖNDÜREBİLMEK İÇİN %3 İLE SINIRLANDIRDIM.
				int oyuncu2Secim = rand() % 3;
				printf("\nTur %d:\n", i + 1);
				printf("Oyuncu1'in seçimi: %s, Oyuncu2'nin seçimi:%s\n", secimler[oyuncu1Secim], secimler[oyuncu2Secim]);
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

			//BU KISIMDA OYUNCULARIN SKORLARINI KARŞILAŞTIRARAK 
			// TÜM TURLARIN SONUNDA GALİBİ BELİRLİYORUZ.
			if (kazanan1 > kazanan2) {
				printf("\nOyunun kazananı Oyuncu1  %d galibiyet!\n", kazanan1);
			}
			else if (kazanan2 > kazanan1) {
				printf("\nOyunun kazananı Oyuncu2  %d galibiyet!\n", kazanan2);
			}
			else {
				printf("\nBeraberlik.\nOyuncu1: %d galibiyet\nOyuncu2: %d galibiyet\nBeraberlik:%d\n", kazanan1, kazanan2,beraberlik);
			}
			break;
		case 2:
			printf("\nTaş makası yener.\nKağıt taşı yener.\nMakas kağıdı yener.\En çok puan toplayan kazanır.Her galibiyet 1 puandır.\n\nGeri dönmek için 0'a basınız.\n\n");
			int cikis;
			do {
				printf("Seçiminiz: ");
				scanf("%d", &cikis);
				if (cikis != 0) {
					printf("Geçersiz tuş,lütfen 0'a basınız.");
				}
			} while (cikis != 0);
			break;
		case 3:
			printf("Çıkış yapılıyor.");
			dongu = 0;

			break;
		default:
			printf("Lütfen geçerli bir seçim yapınız.");
			break;
		}
	}
	return 0;
}

/*

Taş Kağıt Makas oyununa hoşgeldiniz!

-- MENÜ --
1-)Oyuna başla.
2-)Kurallar.
3-)Çıkış.

Seçiminiz: 2

Taş makası yener.
Kağıt taşı yener.
Makas kağıdı yener.En çok puan toplayan kazanır.Her galibiyet 1 puandır.

Geri dönmek için 0'a basınız.

Seçiminiz: 0

Taş Kağıt Makas oyununa hoşgeldiniz!

-- MENÜ --
1-)Oyuna başla.
2-)Kurallar.
3-)Çıkış.

Seçiminiz: 1

Oyun kaç tur oynansın: 10

Tur 1:
Oyuncu1'in seçimi: Taş, Oyuncu2'nin seçimi:Kağıt
Bu turu Oyuncu2 kazandı.

Tur 2:
Oyuncu1'in seçimi: Taş, Oyuncu2'nin seçimi:Taş
Beraberlik

Tur 3:
Oyuncu1'in seçimi: Makas, Oyuncu2'nin seçimi:Makas
Beraberlik

Tur 4:
Oyuncu1'in seçimi: Makas, Oyuncu2'nin seçimi:Kağıt
Bu turu Oyuncu1 kazandı.

Tur 5:
Oyuncu1'in seçimi: Taş, Oyuncu2'nin seçimi:Taş
Beraberlik

Tur 6:
Oyuncu1'in seçimi: Taş, Oyuncu2'nin seçimi:Makas
Bu turu Oyuncu1 kazandı.

Tur 7:
Oyuncu1'in seçimi: Taş, Oyuncu2'nin seçimi:Kağıt
Bu turu Oyuncu2 kazandı.

Tur 8:
Oyuncu1'in seçimi: Makas, Oyuncu2'nin seçimi:Makas
Beraberlik

Tur 9:
Oyuncu1'in seçimi: Kağıt, Oyuncu2'nin seçimi:Taş
Bu turu Oyuncu1 kazandı.

Tur 10:
Oyuncu1'in seçimi: Kağıt, Oyuncu2'nin seçimi:Kağıt
Beraberlik

Oyunun kazananı Oyuncu1  3 galibiyet!

Taş Kağıt Makas oyununa hoşgeldiniz!

-- MENÜ --
1-)Oyuna başla.
2-)Kurallar.
3-)Çıkış.

Seçiminiz:

*/
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>
#include "header.h"
#include <chrono>

int akunKe = 0;

void ucapan_selamat_datang();
void masuk();
void leaderboard();
void daftar();
void menu_utama();
void inisialisasi();
void materi();
void latihan();

struct Akun
{
	std::string username;
	std::string sandi;
};

struct Data
{
    int skor;

};
std::vector <Data> data;
std::vector <Akun> akun;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





int main()
{
    ucapan_selamat_datang();
    
	inisialisasi();

	std::cout << tamplateAwal;
	int pilihan;
	std::cout << "Pilihan : ";
	std::cin >> pilihan;
	std::cin.ignore();
	system("cls");

	switch (pilihan)
	{
	case 1:
        masuk();
        //ucapan_selamat_datang();

		break;

	case 2:
		daftar();

		break;

	case 3:
		std::cout << "Semoga harimu menyenangkan :)\n";
		system ("pause");
		return 0;

	}



	return 0;
}

void menu_utama()
{
	int pilihann;
	do {
		std::cout << menuUtama;
		std::cout << "Pilihan : ";
		
		std::cin >> pilihann;

		switch (pilihann)
		{
		case 1:
			materi();
			break;

		case 2:
			latihan();
			break;

		case 3: 
			break;

		case 4:
			break;

		case 5:
			break;
		case 6:
			break;
		}
	}while (pilihann != 6);
	system("cls");
	main();
	
}


void leaderboard()
{
    for (size_t z = 0; z < akun.size(); z++)
    {
        std::cout << z + 1 << ". " << akun[z].username << " || skor = " << data[z].skor << '\n';
    }
}


void cariNama(const std::string& nama)
{
    int temu = 0;
    for (size_t a = 0; a < akun.size(); a++)
    {

        if (nama == akun[a].username)
        {
            std::cout << nama << " ada di peringkat " << a + 1 << '\n';
            temu++;
            break;
        }
    }
    if (temu <= 0)
    {
        std::cout << "nama tidak ditemukan\n";
    }
}

void masuk()
{
	int kesalahan = 0;
	int pilih = 0;
	do {
		std::cout << tamplateMasuk;
		std::string namaa;
		gotoxy(12, 4);
		std::cin >> namaa;
		std::string sandii;
		gotoxy(12, 5);
		std::cin >> sandii;

		for (size_t i = 0; i < akun.size(); i++)
		{
			if (akun[i].username == namaa && akun[i].sandi == sandii)
			{
				system("cls");
				menu_utama();

				break;
			}
		}
		//++kesalahan;
		
		if (kesalahan <= 5)
		{
			std::cout << "\n\nUsername satau sandi anda salah\n";
			kesalahan++;
			system("pause");
			system("cls");
			
		}
		if (kesalahan%5 == 0)
		{
			std::cout << "Terlalu banyak percobaan\n"
						 "Tunggu 30 detik lagi!!!";
			Sleep(30000);
			kesalahan = 0;
			system("cls");
			std::cout << "1. Lanjut\n"
						 "2. Kembali\n";
			std::cout << "Pilihan : ";
			std::cin >> pilih;
			if (pilih == 1)
			{
				system("cls");
				masuk();
			}
		}
	} while (pilih != 2);

	system("cls");
	main();
}


void ucapan_selamat_datang()
{
    const char selamat_datang[] = "SELAMAT DATANG";
    const char selamat_datang2[] = "FINAL PROJECT ALGEBRA KELAS 7 SMP";

    const int kalimat_selamat_datang = sizeof(selamat_datang) / sizeof(selamat_datang[0]);
    const int kalimat_selamat_datang2 = sizeof(selamat_datang2) / sizeof(selamat_datang2[0]);


    for (int x = 0; x < kalimat_selamat_datang; ++x)
    {
        gotoxy((x + 50), 4);
        std::cout << selamat_datang[x];
        Sleep(50);
    }
    std::cout << '\n';
    
    for (int x = 0; x < kalimat_selamat_datang2; ++x)
    {
        gotoxy((x + 40), 5);
        std::cout << selamat_datang2[x];
        Sleep(50);
    }
    std::cout << "\n\n";
    system("pause");
    system("cls");
}

void mencariNama()
{
	std::cout << tamplateCariNama;
	std::string namaa;
	std::cin >> namaa;
	gotoxy(4, 8);

	cariNama(namaa);
	
}

void sortingLeaderboard()
{
	for (int x = 0; x < akun.size() - 1; x++)
	{
		for (int y = x + 1; y < akun.size(); ++y)
			if (data[x].skor < data[y].skor)
			{
				std::swap(data[x].skor, data[y].skor);
				std::swap(akun[x].username, akun[y].username);

			}
	}

}

void daftar()
{
	std::string username;
	std::string sandi;
	std::cout << tamplateDaftar;
	gotoxy(18, 3);
	std::cin >> username;
	gotoxy(18, 4);
	std::cin >> sandi;

	gotoxy(0, 7);
	system("pause");

	akun.push_back({ username, sandi });

	std::ofstream akunt("akun.txt");
	if (akunt.is_open())
	{
		akunt << akun.back().username << "," << akun.back().sandi << '\n';
	}
	else
	{
		std::cout << "Gagal membuat akun";
	}
	++akunKe;
	akunt.close();
	system("cls");
	std::cout << "Berhasil membuat Akun\n";
	system("pause");
	system("cls");
	main();



	/*std::cout << "banyak akun = " << akunKe << '\n';

	for (int x = 0; x < akunKe; ++x)
	{
		std::cout << "vector ke - [" << x << "] " << akun[x].username << " dan " << akun[x].sandi << '\n';
	}*/
}

void inisialisasi()
{
	std::ifstream akunt("akun.txt");
	if (akunt.is_open())
	{
		std::string namaAkun, passAkun;
		while (std::getline(akunt, namaAkun, ','))
		{
			std::getline (akunt, passAkun);

			//Akun akkun;
			//akkun.username = namaAkun;
			//akkun.sandi = passAkun;
			//akun.push_back(akkun);
			akun.push_back({ namaAkun, passAkun });
		}
	}
}

void materi()
{
	system("cls");
	std::string line, line2, line3;
	std::ifstream materi("materi.txt");
		if (materi.is_open())
		{
			while (std::getline(materi, line, '\\'))
			{
				std::getline(materi, line2, '\\');

				//std::getline(materi, line3);
				std::cout << line << '\n';
				system("pause");
				system("cls");
				std::cout << line2 << '\n';
			}
			materi.close();
		}
		system("pause");
		system("cls");
		menu_utama();
		
}

void latihan()
{
	system("cls");
	std::string awal, soal1, soal2, soal3, soal4, soal5, soal6, soal7;
	const std::string jawaban = "Jawaban : ";
	std::string jawab;
	std::ifstream soal("latihan.txt");
	if (soal.is_open())
	{
		while (std::getline(soal, awal, '\\'))
		{
			std::getline(soal, soal1, '\\');
			std::getline(soal, soal2, '\\');
			std::getline(soal, soal3, '\\');
			std::getline(soal, soal4, '\\');
			std::getline(soal, soal5);
			
			std::cout << awal << '\n';
			system ("pause");
			system("cls");

			std::cout << soal1;
			std::cout << '\n' << jawaban;
			std::cin >> jawab;
			system("cls");

			//std::getline(soal, soal2, '\\');
			std::cout << soal2;
			std::cout << '\n' << jawaban;
			std::cin >> jawab;
			system("cls");

			//std::getline(soal, soal3, '\\');
			std::cout << soal3;
			std::cout << '\n' << jawaban;
			std::cin >> jawab;
			system("cls");

			//std::getline(soal, soal4, '\\');
			std::cout << soal4;
			std::cout << '\n' << jawaban;
			std::cin >> jawab;
			system("cls");

			//std::getline(soal, soal5, '\\');
			std::cout << soal5;
			std::cout << '\n' << jawaban;
			std::cin >> jawab;
			//system("cls");
			break;
		}
		soal.close();
	}
	else
		std::cout << "Tidak dapat membuka soal\n";

		system("pause");
		system("cls");
		menu_utama();
}
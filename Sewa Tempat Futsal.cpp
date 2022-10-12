#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <iomanip>
#define MAX 10
using namespace std;

//		          Kelompok 5                //
// Nama	: Rigan Rahmadin 20.12.1630         //
//		  Afrisa Miftaqul Huda 20.12.1644   //
//		  Muhammad Husnan Arifin 20.12.1651 //
//		  Muhammad Taufiq Akbar 20.12.1656  //
//		  Ridhlo Bahar Riswanto 20.12.1664  //

//Supaya bisa dipanggil di void yang lain
void opening();
void pilihanSatu();
void pilihanDua();
void pilihanTiga();
void pilihanEmpat();
void pilihanLima();
void pilihanEnam();
void pilihanTujuh();
void menuBalik();


struct menuSewa {
	//deklarasi struct dari menuSewa
	char namaPembooking[10][10];
	char tanggal[10][10];
	int lamaMain[10];
	char jam[10][10];
	int jml;
	int totBayar;
	int menu;
}booking;

struct sortingSearching {
	//deklarasi struct dari Sorting & Searching

	//Sorting
	string namaLapangan[10];
	int noLapangan[5];
	int index[7];
	int awal, akhir, sementara;
	//Searching
	int cariData;
	int penanda;
}line;

struct harga{
    float data;
    harga* next; //LinkedList
};

struct AirMineral {
	int atasAirMineral;
	string namaAirMineral[10];
}stackAirMineral;

void opening() {
	//menu pembuka/selamat datang
	system("cls");
	string pembuka[5] = {
		"\n+++++++++++++++++++++++++++++++++++\n",
		"+        SI-04 SEWA FUTSAL        +\n",
		"+++++++++++++++++++++++++++++++++++\n"};
	for (int i = 0; i<5; i++) {
		cout << pembuka[i];
	}
}


void isiForm() {
	/*
	* menu untuk mengisi form data/identitas penyewa
	*/
	cout << "Masukkan Jumlah Pembooking : ";
	cin >> booking.jml;
	system("cls");
	for (int j = 0; j<booking.jml; j++) {
		cout << "\n+++++++++++++++++++++++++++++++++++";
		cout << "\n+     Masukkan Data Diri Anda     +\n";
		cout << "+++++++++++++++++++++++++++++++++++";
		cout << "\nMasukkan Nama Anda : ";
		cin >> booking.namaPembooking[j];
		cout << "Tanggal Sewa (tanggal/bulan/tahun): ";
		cin >> booking.tanggal[j];
		cout << "Jam Berapa *XX.XX* : ";
		cin >> booking.jam[j];
		cout << "Berapa Jam Main : ";
		cin >> booking.lamaMain[j];
	}
}

/*
* Program Khusus Admin : Nambah Air Mineral
*/

void initAirMineral() {
    stackAirMineral.atasAirMineral = -1;
}

bool kosongAirMineral() {
    return stackAirMineral.atasAirMineral == MAX-1;
}

bool fullAirMineral() {
    return stackAirMineral.atasAirMineral == 10-1;
}
// ----------------------ganti A--------------------- //
void tambahAirMineral() {
    if(fullAirMineral()) {
        cout << "Stock Air Mineral Penuh!" << endl;
    }
    else {
        stackAirMineral.atasAirMineral++;
        cout << "\nMasukkan Air Mineral : "; cin >> stackAirMineral.namaAirMineral[stackAirMineral.atasAirMineral];
        system("cls");
        cout << "Air Mineral " << stackAirMineral.namaAirMineral[stackAirMineral.atasAirMineral] << " masuk kedalam stock" << endl;
    }
}

void hapusAirMineral() {
    if(kosongAirMineral()) {
        cout << "Stock Air Mineral Kosong!" << endl;
    }
    else {
        cout << "Air Mineral " << stackAirMineral.namaAirMineral[stackAirMineral.atasAirMineral] << " sudah terhapus" << endl;
        stackAirMineral.atasAirMineral--;
    }
}

void lihatAirMineral() {
    if(kosongAirMineral()) {
        cout << "Air Mineral KOSONG!!!";
    }
    else {
        cout << "\n    STOCK Air Mineral" << endl;
        cout << "_______________________" << endl;
        for(int i=stackAirMineral.atasAirMineral; i>=0; i--) {
            cout << " [-] " << stackAirMineral.namaAirMineral[i] << "\n" << endl;
        }
    }
}

int menuAirMineral() {
    int pilihan;
    initAirMineral();
    do {
    	cout << "\n__________________________";
    	cout << "\n|                        |";
        cout << "\n|    ADMIN-Air Mineral   |";
        cout << "\n|________________________|";
        cout << "\n1. Tambah Air Mineral\n"
             << "\n2. Hapus Air Mineral\n"
             << "\n3. Lihat Air Mineral\n"
             << "\n4. Balik Menu User\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Tolong pilihlah dengan pilihan yang tersedia.\n";
            cout << "Masukkan pilihan : ";
            cin >> pilihan;
        }

        switch(pilihan) {
            case 1:
                system("cls");
                cout << "Note : Inputlah kalimat tanpa spasi . \n" << endl;
                tambahAirMineral();
                break;
            case 2:
                system("cls");
                hapusAirMineral();
                break;
            case 3:
                system("cls");
                lihatAirMineral();
                break;
            case 4:
                system("cls");
                menuBalik();
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }

    }while(pilihan != 4);
}

/*
 * Program tambah harga Air Mineral
 */
//LinkedList
harga* head;
harga* tail;
harga* curr;
harga* entry;
harga* del;

void inisialHarga() {
    head = NULL;
    tail = NULL;
}

void input(int dt) {
    entry = (harga* )malloc(sizeof(harga));
    entry ->data = dt;
    entry ->next = NULL;

    if(head==NULL) {
        head = entry;
        tail = head;
    }
    else {
        tail ->next = entry;
        tail = entry;
    }
}
// ----------------------ganti H--------------------- //
void hapusHarga() {
    int simpan;
    if(head == NULL) {
        cout << "\nHarga Air Mineral Kosong!" << endl;
    }
    else {
    	cout<<"\npilih no harga yang ingin di hapus"<<endl;
    	cin>>simpan;
        simpan = head->data;
        cout << "\nData yang terhapus : " << simpan << endl;

        del = head;
        head = head->next;
        delete del;
    }
}

void lihatHarga() {
    curr = head;
    if(head == NULL) {
        cout << "Tidak ada data Harga" << endl;
    }
    else {
        system("cls");
        cout << "\n______________________";
        cout << "\n== Data Harga Air Mineral ==" << endl;
        cout <<   "______________________\n\n";
        cout << setw(6);
        while(curr!=NULL) {
            cout << "  [-]  " << curr->data << endl;
            curr = curr->next;
        }
        cout << endl;
    }
}

void menuHarga()
{
      char pilih, ulang;
      float data;

      do
      {
      system("cls");
      cout << "\n____________________________________________________";
      cout << "\n|                                                  |";
      cout << "\n|==         ADMIN-(TAMBAH HARGA Air Mineral)     ==|";
      cout << "\n|== (Masukkan Harga Sesuai Urutan atas ke Bawah) ==|";
      cout << "\n|__________________________________________________|"<< endl;
      cout << endl;
      cout << "1. Tambah Harga" << endl;
      cout << "2. Hapus Harga"<< endl;
      cout << "3. Lihat Harga" << endl;
      cout << "4. Balik Ke Menu User\n" << endl;

	  cout << "\n_______________________";
	  cout << "\n|                     |";
      cout << "\n|   Nama Air Mineral  |";
      cout << "\n|_____________________|"<< endl;
      for(int i=stackAirMineral.atasAirMineral; i>=0; i--) {
            cout << "\n [-] " << stackAirMineral.namaAirMineral[i] << "\n" << endl;
      }
      cout << "Masukkan pilihan Anda : ";
      cout<<endl;
      cin >> pilih;

      switch(pilih)
      {
      case '1' :
            cout << "\nMasukkan Harga : ";
            cin >> data;
            input(data);
            break;
      case '2' :
            hapusHarga();
            break;
      case '3' :
            lihatHarga();
            break;
      case '4' :
            menuBalik();
      default :
            cout<<"\nPilih ulang"<<endl;
      }
      cout<<"\nInput Ulang?(y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang=='Y');
}

void mainHarga() {
    inisialHarga();
    menuHarga();
}

/*
* Program User Untuk Menyewa tempat Futsal
*/

void menuUtama() {
	/*
	* menu utama untuk
	* - lihat siapa saja yang telah membooking
	* - menambahkan lineup dan menyorting lineup
	* - mencari nomor punggung pemain yang sudah disorting
	* - keluar
	*/

	//panggil opening();
	opening();

	//Menu Booking
	cout << endl;
	cout << "1. Lihat Daftar Pembooking" << endl;
	//Sorting -LineUp-
	cout << "2. Masukkan Lapangan" << endl;
	cout << "3. Cari Nama Lapangan" << endl;
	cout << "4. (Admin) :Tambah Air Mineral" << endl;
	cout << "5. (Admin) : Harga Air Mineral" << endl;
	cout << "6. Beli Air Mineral" << endl;
	cout << "7. Keluar" << endl;
	cout << "Pilih Menu : ";
	cin >> booking.menu;
	system("cls");
// ----------------------ganti T--------------------- //
	if (booking.menu == 1) {
		pilihanSatu();
		menuBalik();
	}

	else if (booking.menu == 2) {
		pilihanDua();
		menuBalik();
	}

	else if (booking.menu == 3) {
		pilihanTiga();
		menuBalik();
	}

	else if (booking.menu == 4) {
		pilihanEmpat();
		menuBalik();
	}

	else if (booking.menu == 5) {
		pilihanLima();
		menuBalik();
	}

	else if (booking.menu == 6) {
		pilihanEnam();
		menuBalik();
	}

	else if (booking.menu == 7) {
		cout << "\n+++++++++++++++++++++++";
		cout << "\n+     TERIMAKASIH     +\n";
		cout << "++++++++++++++++++++++++\n";
		exit(0);
	}

	else {
		cout << "\n--  Menu tidak ditemukan  --\n";
	}
}

void menuBalik() {
	//menu untuk balik ke menuUtama
	char pilihBalik = 0;
	bool exitNow = false;

	cout << "\nBalik ke menu? (y/n) : ";
	cin >> pilihBalik;
	if (pilihBalik == 'y') {
		return menuUtama();
	}
	else if (pilihBalik == 'n') {
		cout << "\n+++++++++++++++++++++++";
		cout << "\n+     TERIMAKASIH     +\n";
		cout << "+++++++++++++++++++++++++\n";
		exit(0);
	}
	else {
		cout << "\n++++++++++++++++++++++++++++++";
		cout << "\n+   Menu tidak ditemukan   +\n";
		cout << "++++++++++++++++++++++++++++++++";
	}
}

void pilihanSatu() {
	// mengisi data pembooking dengan struct
	for (int k = 0; k<booking.jml; k++) {
		cout << "\n===========================" << endl;
		cout << "    Tampilan Booking    ";
		cout << "\n===========================" << endl;
		cout << "Nama Anda 				: " << booking.namaPembooking[k] << endl;
		cout << "Tanggal Sewa 				: " << booking.tanggal[k] << endl;
		cout << "Jam Main 				: " << booking.jam[k] << endl;
		cout << "Lama Bermain 				: " << booking.lamaMain[k] << endl;
		//rumus total bayar
		booking.totBayar = 100000 * booking.lamaMain[k];
		cout << "Biaya Sewa 				: " << booking.totBayar << endl;
	}
}

void pilihanDua() {
	// menambahkan Lapangan sekaligus mengurutkan dengan sorting
	// Sorting - Tambah Lapangan
	cout << "++++++++++++++++++++++++++++++++";
	cout << "\n+  Silahkan Isi Lapangan  +\n";
	cout << "++++++++++++++++++++++++++++++++\n";
	for (line.awal = 0; line.awal<2; line.awal++) {
		//input Nama Lapangan
		cout << "Masukkan Nama Lapangan : ";
		cin >> line.namaLapangan[line.awal];
		//input No Lapangan
		cout << "Masukkan No Lapangan : ";
		cin >> line.noLapangan[line.awal];
	}

	for (line.awal = 0; line.awal<2; line.awal++) {
		line.index[line.awal] = line.awal;
	}

	for (line.awal = 0; line.awal<2; line.awal++) {
		for (line.akhir = line.awal + 1; line.akhir<2; line.akhir++) {
			if (line.noLapangan[line.index[line.awal]] > line.noLapangan[line.index[line.akhir]]) {
				line.sementara = line.index[line.awal];
				line.index[line.awal] = line.index[line.akhir];
				line.index[line.akhir] = line.sementara;
			}
		}
	}
// ----------------------ganti B--------------------- //
	for (line.awal = 0; line.awal<2; line.awal++) {
		cout << "\n++++++++++++++++++++++" << "++++++";
		cout << "\n+    Data Lapangan " << line.awal << "    +\n";
		cout << "++++++++++++++++++++++++" << "++++++\n";

		cout << "- Nama Lapangan : " << line.namaLapangan[line.index[line.awal]] << "				- No Lapangan : ";
		cout << line.noLapangan[line.index[line.awal]] << endl;
	}
	cin.ignore();
	cin.get();

	// system("pause");
}

void pilihanTiga() {
	// mencari No Lapangan dengan searching
	//tampilkan Data No Lapangan
	cout << "+++++++++++++++++++++";
	cout << "\n+    Data No Lapangan   +\n";
	cout << "+++++++++++++++++++++\n";

	for (line.awal = 0; line.awal<2; line.awal++) {
		line.index[line.awal] = line.awal;
	}

	for (line.awal = 0; line.awal<2; line.awal++) {
		for (line.akhir = line.awal + 1; line.akhir<2; line.akhir++) {
			if (line.noLapangan[line.index[line.awal]] > line.noLapangan[line.index[line.akhir]]) {
				line.sementara = line.index[line.awal];
				line.index[line.awal] = line.index[line.akhir];
				line.index[line.akhir] = line.sementara;
			}
		}
	}

	for (line.awal = 0; line.awal<2; line.awal++) {
		cout << "\n+++++++++++++++++++++++" << "++++++";
		cout << "\n+     Data Lapangan     +\n";
		cout << "+++++++++++++++++++++++++" << "++++++\n";

		cout << "- Nama Lapangan : " << line.namaLapangan[line.index[line.awal]] << "				- No Lapangan : ";
		cout << line.noLapangan[line.index[line.awal]] << endl;
	}

	cout << "\n====================================";
	cout << "\n     Cari Data No Lapangan     \n";
	cout << "====================================\n";

	cout << "Silahkan Masukkan No.Lapangan Yang Dicari : ";
	cin >> line.cariData;

	//sequential search

	for (line.awal = 0; line.awal<2; line.awal++) {
		if (line.noLapangan[line.index[line.awal]] == line.cariData) {
			line.penanda = 1;
			break;
		}
	}

	if (line.penanda == 1) {
		cout << "Data ditemukan pada indeks ke- " << line.awal << endl;
	}
	else {
		cout << "Data tidak ditemukan";
	}
	cin.get();
	_getche();
}


void pilihanEmpat(void) {
	menuAirMineral();
}

void pilihanLima() {
    mainHarga();
}

void pilihanEnam() {
    curr = head;
    cout << "\n_____________________";
    cout << "\n|                   |";
    cout << "\n| Nama Air Mineral  |";
    cout << "\n|___________________|" << endl;
        for(int i=stackAirMineral.atasAirMineral; i>=0; i--) {
            cout << "[-] " << stackAirMineral.namaAirMineral[i] << "\n\n";
        }

		cout << "\n_______________________";
        cout << "\n|                     |";
        cout << "\n|  Harga Air Mineral  |";
        cout << "\n|_____________________|";
        if(head == NULL) {
            cout << "\n[-] Not found" << endl;
        }
        else {
            cout << setw(6);
            while(curr!=NULL) {
                cout << "\n[-] " << curr->data << "\n" << endl;
                curr = curr->next;
            }
            cout << endl;
        }
    menuBalik();
}

void pilihanTujuh() {

	exit(0);
}

int main(void) {
	//tampilkan opening
	opening();

	//Menu Sewa
	isiForm();

	//tampilkan & input pilihan
	system("cls");
	opening();
	menuUtama();
}


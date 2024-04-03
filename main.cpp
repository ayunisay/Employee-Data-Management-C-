#include <iostream>
#include <string>

using namespace std;

// Struct untuk menampung data
struct Data {
  string nama;
  int usia;
  string alamat;
  string gaji;
  Data *next;
};

// Deklarasi array pointer
Data *arr[10];

//Fungsi untuk menampilkan menu operasi
void display_menu(){
  cout << "\n\nMENU: " << endl;
  cout << "1. Menambahkan Data Karyawan" << endl;
  cout << "2. Menampilkan Data Karyawan" << endl;
  cout << "3. Menghapus Data Karyawan" << endl;
  cout << "4. Keluar" << endl;
}

// Fungsi untuk menambahkan data baru
void addData(string nama, int usia, string alamat, string gaji) {
  // Buat node baru
  Data *newNode = new Data;
  newNode->nama = nama;
  newNode->usia = usia;
  newNode->alamat = alamat;
  newNode->gaji = gaji;
  newNode->next = NULL;

  // Simpan alamat node baru di array pointer
  for (int i = 0; i < 10; i++) {
    if (arr[i] == NULL) {
      arr[i] = newNode;
      break;
    }
  }
}

// Fungsi untuk mencetak data
void displayData() {
  for (int i = 0; i < 10; i++) {
    if (arr[i] != NULL) {
      cout << "\n\nNama: " << arr[i]->nama << endl;
      cout << "Usia: " << arr[i]->usia << endl;
      cout << "Alamat: " << arr[i]->alamat << endl;
      cout << "Gaji: " << arr[i]->gaji << endl << endl;
    }
  }
}

// Fungsi untuk menghapus data
void deleteData(string nama) {
  // Cari node yang ingin dihapus
  int i = 0;
  while (arr[i] != NULL && arr[i]->nama != nama) {
    i++;
  }

  // Jika node ditemukan
  if (arr[i] != NULL) {
    // Hapus node dari array pointer
    for (int j = i; j < 100 - 1; j++) {
      arr[j] = arr[j + 1];
    }

    // Hapus node dari memori
    delete arr[100 - 1];
  } else {
    // Data tidak ditemukan
    cout << "Data tidak ditemukan!" << endl;
  }
}

int main() {
  //Deklarasi variabel yang akan digunakan
  int jumlah = 0;
  string nama;
  string alamat;
  string gaji;
  int usia;
  int menu;

  while (menu != 4) {
    display_menu();//Memanggil fungsi display_menu untuk menampilkan menu
    cout << "Masukkan pilihan: ";
    cin >> menu;//Mennyimpan kedalam variabel menu
  
  switch (menu){
    case 1:
  // Meminta user untuk memasukkan jumlah data
  cout << "Masukkan jumlah data yang ingin dimasukkan: ";
  cin >> jumlah;

  // Menambahkan data baru dari user
  for (int i = 0; i < jumlah; i++) {
    
    cout << "\n\nData ke-" << i + 1 << endl;
    cout << "Masukkan Nama: ";
    cin >> nama;

    cout << "Masukkan Usia: ";
    cin >> usia;

    cout << "Masukkan Alamat: ";
    cin >> alamat;

    cout << "Masukkan Gaji: ";
    cin >> gaji;

    addData(nama, usia, alamat, gaji);
  }
  // Mencetak data
  displayData();
  break;

  case 2:
  displayData();//Menampilkan data
  break;

  case 3://Menghapus data
    cout << "Masukkan nama data yang ingin dihapus: ";
    cin >> nama;
    deleteData(nama);

    // Mencetak data setelah dihapus
    displayData();
    break;

  case 4:
  //Opsi keluar akan muncul ouput seperti dibawah
    cout << "\n\nTerimakasih..." << endl;
    cout << "Sampai jumpa lagi" << endl;
    break;

  default:
    cout << "Pilihan Tidak Ada. Harap Coba Lagi!!" << endl;
    break;
}
  }
  return 0;
}

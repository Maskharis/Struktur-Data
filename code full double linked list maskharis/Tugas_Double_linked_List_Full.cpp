#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
     char nama[30];
     int umur;
     Node *next;
     Node *prev;
};

Node *head = NULL, *tail = NULL;

void tambahDepan() {
	char namaorg[30];
	int umurorg;
	cout<<"Nama : "; cin>>namaorg;
	cout<<"Umur : "; cin>>umurorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	baru->umur = umurorg;

	baru->prev = NULL;
	baru->next = head;
	if(head==NULL)
		tail = baru;
	else
		head->prev = baru;
	head = baru;
	
	cout<<namaorg<<" "<<umurorg<<" berhasil masuk list\n";
}

void tambah_belakang()
{
	char a[30];
	int b;
	//Masukan Data-datanya
	cout<<"Masukan Nama Teman : "; cin>>a;
	cout<<"Masukan Umur Teman : "; cin>>b;
	//Buat Node Baru :: Memesan Tempat di memory
	Node *baru;
	baru= new Node;
	//Masukan Datanya ke Node Baru
	strcpy(baru->nama,a);
	baru->umur=b;
	//Jika data Teman Belum Ada di Memory
	if(head==NULL)
	{
		head=baru;	
		head->next=NULL;
        head->prev=NULL;
		tail=head;
	}
	//Jika Data Teman sudah ada datanya di Memory
	else
	{
		tail->next=baru;
        baru->prev=tail;
		tail=baru;
		tail->next=NULL;
	}
}

void tambahSetelah() {
	char namaorg[30];
	bool found;
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	if(head==NULL) {
		baru->prev = NULL;
		baru->next = NULL;
		head = baru;
		tail = baru;
		found = true;
	}	else {
		char cari[30];
		cout<<"Tambahkan setelah siapa : "; cin>>cari;
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->next = bantu->next;
				baru->prev = bantu;
                bantu->next->prev=baru;
				bantu->next = baru;
				if(bantu==tail) tail = baru;
				found = true;
				break;
			}
			bantu = bantu->next;
		}
	}
	if(found) cout<<namaorg<<" berhasil masuk list\n";
	else cout<<namaorg<<" gagal masuk list\n";
}

void tambahSebelum() {
	char namaorg[30];
	bool found = false;
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	if(head==NULL) {
		baru->prev = NULL;
		baru->next = NULL;
		head = baru;
		tail = baru;
		found = true;
	}	else {
		char cari[30];
		cout<<"Tambahkan sebelum siapa : "; cin>>cari;
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->prev = bantu->prev;
				baru->next = bantu;
                bantu->prev->next = baru;
				bantu->prev = baru;
				if(bantu==head) head = baru;
				found = true;
				break;
			}
			bantu = bantu->next;
		}
	}	
	if(found) cout<<namaorg<<" berhasil masuk list\n";
	else cout<<namaorg<<" gagal masuk list\n";
}

void cetakmundur() {
	Node *bantu = tail;
	while(bantu!=NULL) {
		cout<<bantu->nama<<" -> ";
		bantu = bantu->prev;
	} cout<<"NULL\n";
}

void cetakmaju() {
	Node *bantu = head;
	while(bantu!=NULL) {
		cout<<bantu->nama<<" -> ";
		bantu = bantu->next;
	} 
    cout<<"NULL\n";
}

void hapusdepan() {
     if(head==NULL){ 
					cout<<"List masih Kosong \n";
					cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
				}
				else{
					if(head==tail){
						cout<<"Lokasi terakhir Data "<<head<<endl;   
						delete head;
						cout<<"Data Berhasil dihapus"<<endl; 
						cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
						head = NULL;
						tail = NULL;
					}
					else{
						char x[30];
						cout<<"Menghapus Nama siapa ? ";cin>>x;
						if(strcmp(head->nama,x)==0){
							Node *hapus;        
							hapus = head;             
							head = head->next;
							cout<<"Lokasi terakhir Data "<< x << " : " <<hapus<<endl;       
							delete hapus;
							cout<<"Data "<< x <<" Berhasil dihapus"<<endl;
							cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
						}
						else{
							cout<<"Tidak Ada Data \n";
							cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
						}
					}
				}
            }

void hapustengah(){
     char x[30];
				cout<<"Menghapus Nama siapa ? ";cin>>x;
				Node *bantu;
				bantu=head; 
				while(bantu!=NULL){ 
					if(strcmp(bantu->next->nama,x)==0){
						Node *hapus; 
						hapus = bantu->next; 
						bantu->next = bantu->next->next;
						cout<<"Lokasi terakhir Data "<< x << " : " <<hapus<<endl;   
						delete hapus; //hapus hapus(bantu->next)
						cout<<"Data "<< x <<" Berhasil dihapus"<<endl; 
						cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
						break; 
					}
					else{ 
						cout<<"Tidak Ada Data \n"; 
						cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
					}
				}
            }

void hapusbelakang(){
    char x[30];
				cout<<"Manghapus Nama siapa ? ";cin>>x;
				if(strcmp(tail->nama,x)==0){
					Node *bantu;     
					bantu = head;             
					while(bantu->next != tail){             
						bantu = bantu->next;            
					}
					cout<<"Lokasi terakhir Data "<< x << " : " <<tail<<endl;                    
					delete tail;
					cout<<"Data "<< x <<" Berhasil dihapus"<<endl;
					cout<<"Tekan Tombol Apapun Untuk Melanjutkan..."; 
					bantu->next = NULL;          
					tail = bantu;
				}
				else{
					cout<<"Tidak Ada Data \n";
					cout<<"Tekan Tombol Apapun Untuk Melanjutkan...";
				    }
                }

int main() {
	int pilih;
	do {
		cout<<"Pilih operasi Double Linked List :\n";
		cout<<"1.  tambah data di depan\n";
        cout<<"2.  tambah data di belakang\n";
        cout<<"3.  tambah data diTengah sebelum node tertentu\n";
        cout<<"4.  tambah Data diTengah sesudah node tertentu\n";
		cout<<"5.  tampil data maju\n";
		cout<<"6.  tampil data mundur\n";
        cout<<"7.  hapus data depan\n";
        cout<<"8.  hapus data tengah\n";
        cout<<"9.  hapus data belakang\n";
        cout<<"10. keluar\n";
		cout<<"Pilih operasi : "; cin>>pilih;
		
		if(pilih==1) tambahDepan();
		if(pilih==2) tambah_belakang();
        if(pilih==3) tambahSebelum();
		if(pilih==4) tambahSetelah();
        if(pilih==5) cetakmaju();
        if(pilih==6) cetakmundur();
        if(pilih==7) hapusdepan();
        if(pilih==8) hapustengah();
        if(pilih==9) hapusbelakang();
		
	} while(pilih!=10);
	
	return 0;
}
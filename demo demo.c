#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>
#define MAX 100
#define MAX_TRANS 100

struct Product {
    char productId[10];
    char name[50];
    char unit[10];
    int qty;
    int status; 
};

struct Product listproduct[MAX] = {
    {"P001", "Sua Hop Vinamilk", "Hop", 120, 1},
    {"P002", "Mi Tom Hao Hao", "Hop", 350, 1},
    {"P003", "Gao Thom ST25", "Kg", 80, 0},
    {"P004", "Khoai Tay Chien Dong Lanh", "Goi", 290, 1},
    {"P005", "Hat Dieu Rang Muoi", "Hop", 90, 1},
    {"P006", "Banh Quy Cosy", "Hop", 210, 1},
    {"P007", "Keo Socola KitKat", "Goi", 140, 1},
    {"P008", "Mi Ly Modern", "Ly", 380, 1},
    {"P009", "Thit Heo Xay Dong Lanh", "Kg", 60, 1},
    {"P010", "Trung Ga CP", "Vi", 75, 1},
    {"P011", "Nuoc Mam Nam Ngu", "Chai", 95, 1},
    {"P012", "Nuoc Tuong Maggi", "Chai", 90, 1},
    {"P013", "Muoi Iot", "Kg", 200, 1},
    {"P014", "Bot Ngot Mi Chinh", "Goi", 220, 1},
    {"P015", "Duong Cat Trang", "Kg", 150, 1},
    {"P016", "Dau An Neptune", "Lit", 110, 1},
    {"P017", "Dau An Huong Duong", "Lit", 90, 1},
    {"P018", "Sua Hop Vinamilk", "Hop", 120, 1},
    {"P019", "Sua Tuoi TH True Milk", "Hop", 320, 1},
    {"P020", "Nuoc Ngot Coca Cola", "Chai", 170, 1},
    {"P021", "Bia Heineken", "Lon", 260, 1},
    {"P022", "Ca Phe Hoa Tan G7", "Hop", 175, 1},
    {"P023", "Nuoc Loc Aquafina", "Thung", 105, 1},
    {"P024", "Dau Goi Sunsilk", "Chai", 160, 1},
    {"P025", "Kem Danh Rang P/S", "Tuyt", 180, 1},
    {"P026", "Nuoc Xa Vai Comfort", "Tui", 130, 1},
    {"P027", "Bot Giat Omo", "Tui", 100, 1},
    {"P028", "Giay Ve Sinh", "Cuon", 500, 1},
    {"P029", "Xa Bong Tam Lifebuoy", "Cuc", 210, 1},
    {"P030", "Dao Got Hoa Qua", "Cai", 40, 1},
    {"P031", "Nuoc Rua Chen Sunlight", "Chai", 250, 1},
    {"P032", "Ban Chai Danh Rang Colgate", "Cai", 120, 1},

};
int size = 32;
void remoNewLine(char str[]);
int indexByproductId(char findId[]);
int indexByname(char findname[]);
bool isValidName(char str[]);
bool isAlphaString(char str[]);
void insertProduct();
void editProduct();
void changestatus();
void findproduct();
void showproductPaginate();
void sortProduct();
void inoutproduct();
void showTransactionHistory();
int main() {
    int choice;
    while (true) {
        printf("+-------------------------MENU-------------------------+\n");
        printf("| %-53s|\n", "1. Them ma hang moi");
        printf("| %-53s|\n", "2. Cap nhat thong tin san pham qua id");
        printf("| %-53s|\n", "3. Quan li trang thai san pham (khoa/xoa)");
        printf("| %-53s|\n", "4. Tra cuu san pham theo id");
        printf("| %-53s|\n", "5. Danh sach (phan trang)"); 
        printf("| %-53s|\n", "6. Sap xep danh sach san pham"); 
        printf("| %-53s|\n", "7. Giao dich xuat/nhap hang hoa"); 
        printf("| %-53s|\n", "8. Lich su xuat/nhap"); 
        printf("| %-53s|\n", "9. Thoat chuong trinh");
        printf("+------------------------------------------------------+\n");
        printf("Moi ban nhap lua chon chuc nang: ");

        char input[10];
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Vui long nhap so tu 1 den 9!\n");
            continue;
        }

        switch (choice) {
            case 1:
                insertProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                changestatus();
                break;
            case 4:
                findproduct();
                break;
            case 5:
                showproductPaginate();
                break;
            case 6:
                sortProduct();
  
                break;
            case 7:
                inoutproduct();
                break;
            case 8:
                showTransactionHistory();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    }
    return 0;
}


void remoNewLine(char str[]) {
          str[strcspn(str, "\n")] = '\0';
}


int indexByproductId(char findId[]) {
        for (int i = 0; i < size; i++) {
        if (strcmp(listproduct[i].productId, findId) == 0) {
        return i;
        }
    }
    return -1;
}


int indexByname(char findname[]) {
        for (int i = 0; i < size; i++) {
        if (strcmp(listproduct[i].name, findname) == 0) {
        return i;
        }
    }
    return -1;
}


bool isValidName(char str[]) {
        for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) {
        return false;
        }
    }
    return true;
}


bool isAlphaString(char str[]) {
        for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
        return false;
        }
    }
    return true;
}


void insertProduct() {
        if (size == MAX) {
        printf("Mang da day, khong the chen them!\n");
        return;
    }
    struct Product insertproduct;

    printf("------------ Nhap thong tin san pham can them ---------------\n");

    
    while (true) {
        printf("Nhap Id san pham: ");
        fgets(insertproduct.productId, sizeof(insertproduct.productId), stdin);
        remoNewLine(insertproduct.productId);

        if (strlen(insertproduct.productId) == 0) {
            printf("ProductId khong duoc de trong!\n");
            continue;
        }
        if (indexByproductId(insertproduct.productId) != -1) {
            printf("Ma san pham bi trung, moi nhap lai!\n");
            continue;
        }
        break;
    }

    
    while (true) {
        printf("Nhap ten san pham: ");
        fgets(insertproduct.name, sizeof(insertproduct.name), stdin);
        remoNewLine(insertproduct.name);

        if (strlen(insertproduct.name) == 0) {
            printf("Ten san pham khong duoc de trong!\n");
            continue;
        }
        if (!isValidName(insertproduct.name)) {
            printf("Ten san pham chi duoc chua chu cai va khoang trang, moi nhap lai!\n");
            continue;
        }
        break;
    }

   
    while (true) {
        printf("Nhap don vi san pham (cai/hop/kg): ");
        fgets(insertproduct.unit, sizeof(insertproduct.unit), stdin);
        remoNewLine(insertproduct.unit);

        if (strlen(insertproduct.unit) == 0) {
            printf("Don vi san pham khong duoc de trong!\n");
            continue;
        }
        if (!isAlphaString(insertproduct.unit)) {
            printf("Don vi san pham phai la chu cai, moi nhap lai!\n");
            continue;
        }
        break;
    }

    
    while (true) {
        printf("Nhap so luong san pham ton kho: ");
        char qtyInput[20];
        fgets(qtyInput, sizeof(qtyInput), stdin);
        if (sscanf(qtyInput, "%d", &insertproduct.qty) != 1) {
            printf("So luong phai la so nguyen!\n");
            continue;
        }
        if (insertproduct.qty < 0) {
            printf("So luong phai >= 0!\n");
            continue;
        }
        break;
    }

   
    while (true) {
        printf("Nhap trang thai san pham (1 = con SD, 0 = het han): ");
        char statusInput[10];
        fgets(statusInput, sizeof(statusInput), stdin);
        if (sscanf(statusInput, "%d", &insertproduct.status) != 1) {
            printf("Trang thai phai la so 0 hoac 1!\n");
            continue;
        }
        if (insertproduct.status != 0 && insertproduct.status != 1) {
            printf("Trang thai chi co the la 0 hoac 1!\n");
            continue;
        }
        break;
    }

    
    listproduct[size] = insertproduct;
    size++;

    printf("Them moi hang hoa thanh cong!\n");
}


void editProduct() {
    char editid[50];
    int index;

    
         
        printf("Nhap ma san pham can cap nhat thong tin: ");
        fgets(editid, sizeof(editid), stdin);
        remoNewLine(editid);
        index = indexByproductId(editid);

        if (index == -1) {
            printf("San pham [%s] khong ton tai trong danh sach!\n", editid);
          return;  
        }
       
    


    printf("---- Cap nhat thong tin san pham [%s] ----\n", editid);

    
    while (true) {
        printf("Nhap ten san pham moi: ");
        fgets(listproduct[index].name, sizeof(listproduct[index].name), stdin);
        remoNewLine(listproduct[index].name);

        if (strlen(listproduct[index].name) == 0) {
            printf("Ten san pham khong duoc de trong!\n");
            continue;
        }
        if (!isValidName(listproduct[index].name)) {
            printf("Ten san pham chi duoc chua chu cai va khoang trang, moi nhap lai!\n");
            continue;
        }
        break;
    }

    
    while (true) {
        printf("Nhap don vi moi (cai/hop/kg): ");
        fgets(listproduct[index].unit, sizeof(listproduct[index].unit), stdin);
        remoNewLine(listproduct[index].unit);

        if (strlen(listproduct[index].unit) == 0) {
            printf("Don vi san pham khong duoc de trong!\n");
            continue;
        }
        if (!isAlphaString(listproduct[index].unit)) {
            printf("Don vi san pham phai la chu cai, moi nhap lai!\n");
            continue;
        }
        break;
    }

    
    while (true) {
        printf("Nhap so luong moi: ");
        char qtyInput[20];
        int qty;
        fgets(qtyInput, sizeof(qtyInput), stdin);
        if (sscanf(qtyInput, "%d", &qty) != 1) {
            printf("Nhap sai! Phai la so nguyen >= 0\n");
            continue;
        }
        if (qty < 0) {
            printf("So luong phai >= 0\n");
            continue;
        }
        listproduct[index].qty = qty;
        break;
    }

    
    while (true) {
        printf("Nhap trang thai moi (1 = con SD, 0 = het han): ");
        char statusInput[10];
        int status;
        fgets(statusInput, sizeof(statusInput), stdin);
        if (sscanf(statusInput, "%d", &status) != 1) {
            printf("Trang thai phai la 0 hoac 1!\n");
            continue;
        }
        if (status != 0 && status != 1) {
            printf("Trang thai chi co the la 0 hoac 1!\n");
            continue;
        }
        listproduct[index].status = status;
        break;
    }

    printf("Cap nhat hang hoa <%s> thanh cong!\n", editid);
}


void changestatus() {
    char changeid[50];
    int index=-1;

    
   
        printf("Nhap id san pham can thay doi trang thai: ");
        fgets(changeid, sizeof(changeid), stdin);
        remoNewLine(changeid);

        for (int i=0;i<size;i++){
        if(strcmp(listproduct[i].productId,changeid)==0){
        index=i;
        	break;
        	}
        	}
        if (index == -1) {
          printf("San pham [%s] khong ton tai trong danh sach!\n", changeid);
          return;
          }
	  

        
    
    printf("Trang thai hien tai cua san pham [%s]: %d\n", listproduct[index].productId, listproduct[index].status);

    
    int newStatus;
    while (true) {
        printf("Nhap trang thai moi (1 = con SD, 0 = het han): ");
        char statusInput[10];
        fgets(statusInput, sizeof(statusInput), stdin);
        if (sscanf(statusInput, "%d", &newStatus) != 1) {
            printf("Trang thai phai la so 0 hoac 1!\n");
            continue;
        }
        if (newStatus != 0 && newStatus != 1) {
            printf("Trang thai chi co the la 0 hoac 1!\n");
            continue;
        }
        break;
    }

    if (listproduct[index].status == 1 && newStatus == 0) {
        listproduct[index].status = 0;
        printf("Cap nhat thanh cong! San pham [%s] da thay doi trang thai thanh 0 (het han).\n", listproduct[index].productId);
    } else if (listproduct[index].status == newStatus) {
        printf("Trang thai khong thay doi.\n");
    } else if (listproduct[index].status == 0 && newStatus == 1) {
        printf("Khong the cap nhat trang thai tu 0 sang 1!\n");
    }
}

void findproduct(){
	
    char key[50];
    int found = 0;

    printf("Nhap tu khoa (ID hoac ten san pham): ");
    fgets(key, 50, stdin);
    remoNewLine(key);
    printf("\n=== Ket qua tim kiem cho tu khoa: \"%s\" ===\n", key);
    for (int i = 0; i < size; i++) {

        if (strstr(listproduct[i].productId, key) != NULL ||
            strstr(listproduct[i].name, key) != NULL)
        {
            
            printf(" - ID : %s\n", listproduct[i].productId);
            printf(" - Ten: %s\n", listproduct[i].name);
            printf(" - Don vi: %s\n", listproduct[i].unit);
            printf(" - So luong: %d\n", listproduct[i].qty);
            printf(" - Trang thai: %d\n", listproduct[i].status);

            found++;
        }
    }


    if (found == 0) {
        printf("\n>>> Khong tim thay san pham nao phu hop voi tu khoa \"%s\"!\n", key);
    } else {
        printf("\n>>> Tim thay tong cong %d san pham.\n", found);
    }
}
void showproductPaginate(){
    int pagenumber=1;
    int itemPerPage = 10;
    int index=0;
    int result=size/itemPerPage;
    int totalpage=(size%itemPerPage==0)?result:result+1;
    while(1){
        printf("Moi ban nhap so trang can xem(1-%d):",totalpage);
        scanf("%d",&pagenumber);
        while (getchar() != '\n'); // xoa enter cua scanf o tren
        index = (pagenumber - 1) * itemPerPage; // cap nhat lai index moi
        printf("Trang %d/%d :\n\n", pagenumber, totalpage); // trang dau 1/so trang
        while (index < (pagenumber - 1) * itemPerPage + itemPerPage && index < size) {
            printf(" - ID : %s\n", listproduct[index].productId);
            printf(" - Ten: %s\n", listproduct[index].name);
            printf(" - Don vi: %s\n", listproduct[index].unit);
            printf(" - So luong: %d\n", listproduct[index].qty);
            printf(" - Trang thai: %d\n\n", listproduct[index].status);
            index++;
        }
          if (pagenumber >= totalpage) {
            printf("danh sach san pham rong!\n");
        } else {
          printf("Ban co muon xem tiep trang sau khong? (1-co/0-khong): ");
          char ch = getchar(); 
          while(getchar() != '\n'); // xoa phan enter con lai

          if (ch == '1' || ch == '1') {
          pagenumber++;   
          continue;//chuyen sang trang tiep sau khi nhap so trang
            }
        }
          printf("Ban co muon nhap trang khac khong? (1-co/0-khong): ");
          char ch2 = getchar(); // dùng de nhap co hoac khong
          while(getchar() != '\n'); // xóa buffer
          if (ch2 == '1' ) {
          int newPage;
          do {
          printf("Nhap trang (1-%d): ", totalpage);
          scanf("%d", &newPage);
          while (getchar() != '\n'); // xoa enter
        } while (newPage < 1 || newPage > totalpage);
          pagenumber = newPage; 
          continue;//chon trang khac sau khi nhap so trang
        }
         printf("Thoat xem danh sach!\n");
         break;
    }
}
void sortProduct(){
	
	if(size==0){
		printf("Danh sach hang hoa rong!!\n");
		return;
	}
	int choice;
	printf("+--------SAP XEP HANG HOA-------+\n");
	printf("|1. Sap xep theo ten (A-Z).     |\n");
	printf("|2. Sap xep tang theo so luong. |\n");
	printf("+-------------------------------+\n");
	printf("Xin moi nhap lua chon: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
		if(strcmp( listproduct[i].name, listproduct[j].name)>0){
		struct Product temp= listproduct[i];
		listproduct[i]= listproduct[j];
		listproduct[j]=temp;
		}
		}
		}
		printf("Da sap xep theo ten (A-Z) thanh cong!!\n");
		showproductPaginate();
		break;
		case 2:
		for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
		if( listproduct[i].qty> listproduct[j].qty){
		struct Product temp= listproduct[i];
		listproduct[i]= listproduct[j];
		listproduct[j]=temp;
		}
		}
		}
		printf("Da sap xep theo so luong thanh cong!!\n");
		showproductPaginate();
		break;
		default:
		printf("Lua chon khong hop le!!\n");
		return;
	}
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	printf("| Ma         | Ten                          | Don vi     | So luong ton kho  | Trang thai       |\n");
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	for(int i=0;i<size;i++){
		printf("| %-10s | %-28s | %-10s | %-17d | %-16s |\n",
	     listproduct[i].productId,
	     listproduct[i].name,
	     listproduct[i].unit,
	     listproduct[i].qty,
	     listproduct[i].status?"Con su dung":"Het han su dung");
		printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	}
}
struct Transaction {
    char transId[10];
    char productId[10];
    char type[5];  // "IN" hoac "OUT"
    int qty;
    char date[15]; // dd/mm/yyyy
};

struct Transaction listTrans[MAX_TRANS];
int transize = 0; 

void inoutproduct(){
	int choice2;
	char pid[50];//chuoi nhap ma san oham trung gian de neu cap nhat that bai id cx ko bi thay doi
	int qty;
	int pos;
	char buffer[50];
	char transId[20]; // Chuoi luu ma giao dic
	char numberStr[10]; // Chuoi trung gian di chuyen so sang chuoi
	printf("Moi ban lua chon(1.Nhap hang/2.Xuat hang):");
	scanf("%d",&choice2);
	getchar();
	switch(choice2){
		case 1:
		printf("Moi ban nhap ma san pham:");
		do{
		fgets(pid,50,stdin);
		remoNewLine(pid);
		if(strlen(pid)==0){
		printf("Ma san pham khong duoc de trong\n");
		continue;
		}
		}while(strlen(pid)==0);
		 pos=indexByproductId(pid);
		if(pos<0){
		printf("San pham khong ton tai trong danh sach\n");
		return;
		}
          if (listproduct[pos].status == 0) {
	printf("Hang hoa da ngung kinh doanh, khong the giao dich!\n");
	return;
           }
          
	while(true){
          printf("Nhap so luong nhap: ");
          if (scanf("%d", &qty) != 1 || qty <= 0) {
            printf("So luong khong hop le!\n");
            while (getchar() != '\n');
         	 continue;
         	 }
         	break;
         	}
        while (getchar() != '\n');
        listproduct[pos].qty += qty;
        itoa(transize + 1, numberStr, 10); // chuyen so sang chuoi
        if(transize + 1 < 10){
            strcpy(transId, "T00");
        } else if(transize + 1 < 100){
            strcpy(transId, "T0");
        } else {
            strcpy(transId, "T");
        }// ma giao dich tu dong tang
        strcat(transId, numberStr); 
        strcpy(listTrans[transize].transId, transId);
        strcpy(listTrans[transize].productId, pid);
        strcpy(listTrans[transize].type, "IN");
        listTrans[transize].qty = qty;
        printf("Nhap thoi gian giao dich (dd/mm/yyyy):");
        fgets(listTrans[transize].date, sizeof(listTrans[transize].date), stdin);
        remoNewLine(listTrans[transize].date);
        transize++;
        printf("Nhap hang hoa %s thanh cong!So luong hang duoc tang len:%d.\n", pid,qty);
        break;
	case 2:
	printf("Nhap ma san pham: ");
        	fgets(pid, sizeof(pid), stdin);
       	 remoNewLine(pid);
       	do{
	    if (strlen(pid) == 0) {
            printf("Ma san pham khong duoc de trong!\n");
            return;
        }
    	}while(strlen(pid) == 0);
         pos = indexByproductId(pid);
        if (pos == -1) {
            printf("San pham %s khong ton tai trong danh sach!\n", pid);
            return;
        }
        if (listproduct[pos].status == 0) {
	printf("Hang hoa da ngung kinh doanh, khong the giao dich!\n");
	return;
	}
	while(true){
        printf("Nhap so luong xuat: ");
        if (scanf("%d", &qty) != 1 || qty <= 0) {
            printf("So luong xuat khong hop le!\n");
            while (getchar() != '\n');
           continue;
        }
         break;
         }
        
        if (qty > listproduct[pos].qty) {
            printf("So luong xuat hang hoa %s vuot qua so luong hien co!\n", pid);
            return;
        }
        listproduct[pos].qty -= qty;
         itoa(transize + 1, numberStr, 10); // chuyen so sang chuoi
        if(transize + 1 < 10){
        	strcpy(transId, "T00");
        } else if(transize + 1 < 100){
            strcpy(transId, "T0");
        } else {
            strcpy(transId, "T");
        }// ma giao dich tu dong tang
        strcat(transId, numberStr); // Noi so vao chuoi
        strcpy(listTrans[transize].transId, transId);
        strcpy(listTrans[transize].productId, pid);
        strcpy(listTrans[transize].type, "OUT");
        listTrans[transize].qty = qty;
        printf("Nhap thoi gian giao dich (dd/mm/yyyy): ");
        while (getchar() != '\n');
        fgets(listTrans[transize].date, sizeof(listTrans[transize].date), stdin);
        remoNewLine(listTrans[transize].date);
        transize++;
        printf("Xuat hang hoa %s thanh cong!So luong hang hoa trong danh sach giam:%d.\n", pid,qty);
        break;

    default:
        printf("Lua chon khong hop le!\n");
    
	}	
}

void showTransactionHistory() {
    char productId[10];
    printf("Nhap ma hang hoa can xem lich su giao dich: ");
    fgets(productId, sizeof(productId), stdin);
    remoNewLine(productId);

    if (strlen(productId) == 0) {
        printf("Ma hang hoa khong duoc de trong!\n");
        return;
    }

    int found = 0;
    printf("\n=== Lich su giao dich hang hoa [%s] ===\n", productId);
    printf("+----------+-----------+-------+----------+--------+\n");
    printf("| Ma GD    | Ma Hang   | Loai  | So luong | Ngay   |\n");
    printf("+----------+-----------+-------+----------+--------+\n");

    for (int i = 0; i < transize; i++) {
        if (strcmp(listTrans[i].productId, productId) == 0) {
            printf("| %-8s | %-9s | %-5s | %-8d | %-6s |\n",
                   listTrans[i].transId,
                   listTrans[i].productId,
                   listTrans[i].type,
                   listTrans[i].qty,
                   listTrans[i].date);
            found++;
        }
    }

    printf("+--------------------------------------------------+\n");

    if (found == 0) {
        printf("Vat tu [%s] chua co giao dich nhap/xuat.\n", productId);
    } else {
        printf("Tong cong %d giao dich.\n", found);
    }
}




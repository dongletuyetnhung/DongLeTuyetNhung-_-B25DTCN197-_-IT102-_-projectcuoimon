#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

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
};
int size = 3;
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
                printf("Chuc nang chua duoc phat trien.\n");
                break;
            case 8:
                printf("Chuc nang chua duoc phat trien.\n");
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

    
         while (true) {
        printf("Nhap ma san pham can cap nhat thong tin: ");
        fgets(editid, sizeof(editid), stdin);
        remoNewLine(editid);
        index = indexByproductId(editid);

        if (index == -1) {
            printf("San pham [%s] khong ton tai trong danh sach!\n", editid);
            continue;
        }
        break;
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
        index = (pagenumber - 1) * itemPerPage; // capnhat lai index moi
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
          char ch2 = getchar(); // dùng d? nh?p yes ho?c no
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



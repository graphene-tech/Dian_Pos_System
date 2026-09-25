#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product{
    char barcode[10];
    char name[20];
    float price;
};
struct CartItem{
    struct Product prod;
    int qty;
};
struct CartItem cart[10];
int cart_count=0;

struct Product inventory[10];
int item_count=0;
void init_products(){
    strcpy(inventory[0].barcode,"001");
    strcpy(inventory[0].name,"Cola");
    inventory[0].price =3.50;
    
    strcpy(inventory[1].barcode,"002");
    strcpy(inventory[1].name,"Lollipop");
    inventory[1].price =0.50;

    strcpy(inventory[2].barcode,"003");
    strcpy(inventory[2].name,"Noodles");
    inventory[2].price =6.00;

    item_count=3;
}

void search_by_barcode(char input_code[]){
    int i;
    int found=0;

    for (i=0;i<item_count;i++){
        if(strcmp(inventory[i].barcode,input_code) ==0){
            printf("%-10s %.2f\n",inventory[i].name,inventory[i].price);
            found=1;
            break;
        }
    }

    if (found ==0){
        printf("ERROR: code not foumd\n");
    }
}
void show_prices(){
    int i;
    printf("Item          No. Pri.\n");
    printf("------------------\n");

    for (i=0;i<item_count; i++){
        printf("%-10s  %s  %.2f\n",inventory[i].name,inventory[i].barcode,
        inventory[i].price);
    }
}
void add_to_cart(char input_code[]){
    int i;
    int found =0;

    for (i=0;i<item_count;i++){
        if(strcmp(inventory[i].barcode,input_code)==0){
            found =1;
            int j;
            for(j=0;j<cart_count;j++){
                if(strcmp(cart[j].prod.barcode,input_code)==0){
                    cart[j].qty=cart[j].qty+1;
                    printf("%-10s %.2f x%d=%.2f\n",
                        inventory[i].name,inventory[i].price,cart[j].qty,inventory[i].price*cart[j].qty);
                    return; }
            }
                    cart[cart_count].prod=inventory[i];
                    cart[cart_count].qty=1;
                    cart_count=cart_count+1;
                    printf("%-10s %.2fx1=%.2f\n",
                    inventory[i].name,inventory[i].price,inventory[i].price);
                        return;}
                    }
            if(found==0){
                printf("ERROR:code not found\n");

    }
}
    void remove_from_cart(char input_code[]){
        int j;
        int k;
        int found=0;

        for(j=0;j<cart_count;j++){
            if(strcmp(cart[j].prod.barcode,input_code)==0){
                found=1;
                if (cart[j].qty>1){
                    cart[j].qty=cart[j].qty-1;
                    printf("%-10s %.2f x%d=%.2f\n",
                    cart[j].prod.name,cart[j].prod.price,cart[j].qty,cart[j].prod.price*cart[j].qty);
                    return;
                }
                if(cart[j].qty==1){
                for(k=j;k<cart_count-1;k++){
                    cart[k]=cart[k+1];
                }
                cart_count=cart_count-1;
                printf("商品已删除\n");
                return;
                }
                }
                }
            

                if(found==0){
                    printf("Item not in the cart\n");
                }
            }
            void print_receipt(void){
                int j;
                float total=0;
                printf("Item          Pri.Qty Amout\n");
                printf("----------------------------\n");
                for(j=0;j<cart_count;j++){
                printf("%-10s %.2f x%d=%.2f\n",
                cart[j].prod.name,cart[j].prod.price,cart[j].qty,cart[j].prod.price*cart[j].qty);
                total=total+cart[j].prod.price+cart[j].qty;}
                printf("------------------------------\n");
                printf("Total             = %.2f\n",total);
                return;
            }
    
    

int main(){
    system("chcp 65001");
    char input[20];

    init_products();

    printf("欢迎使用 七一一便利店 POS收银系统!\n");

    while (1){
        printf("> ");
        scanf(" %s",input);
        if(strcmp(input,"exit") ==0 || strcmp(input,"quit")==0){
            printf("退出系统，再见!\n");
            break;
        }
        else if (strcmp(input,"prices")==0){
            show_prices();

        }
        else if(input[0]=='-'){
            remove_from_cart(input+1);
        }
        else if(strcmp(input,"drop")==0){
            cart_count=0;
            printf("记录已清空");
        }
        else if(strcmp(input,"checkout")==0){
            print_receipt();
        }
    
        else{
            add_to_cart(input);
        }
    }
    return 0;
}
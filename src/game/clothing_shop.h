#ifndef CLOTHING_SHOP_H
#define CLOTHING_SHOP_H
typedef enum { CLOTHING_SHOP, LUXURY_SHOP, BARBER_SHOP, TATTOO_SHOP, SHOE_SHOP } ShopType;
typedef struct { char name[32]; ShopType type; int country; float pos_x; float pos_y; int is_open; } Shop;
extern Shop shops[];
extern int total_shops;
void enter_shop(int index);
void buy_item(int shop_index, int item_index, int price);
void change_hairstyle_shop(int style);
void add_tattoo_shop(int tattoo);
#endif

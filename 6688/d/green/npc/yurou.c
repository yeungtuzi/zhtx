inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("银鱼肉", ({"yu rou", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块鲜美的鱼肉。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}

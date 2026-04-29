
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蛋糕", ({ "cake" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 500);
                set("food_remaining", 20);
                set("food_supply", 10);

                set("material","面粉");
        }
        setup();
}

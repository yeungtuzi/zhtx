// /d/xizang/class/gold_wh/obj/cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("大饼", ({ "big cake", "cake" }) );
        set_weight(130);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一张烤得硬梆梆的青稞大饼\n");
                set("unit", "张");
                set("value", 20);
                set("food_remaining", 5);
                set("food_supply", 60);
        }
}

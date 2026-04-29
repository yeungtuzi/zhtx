// /obj/example/mantou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("馒头", ({ "man tou", "mantou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个硬梆梆的大馒头.\n");
                set("unit", "个");
                set("value", 15);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

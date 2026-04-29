// /d/xizang/class/bad/npc/obj/cai2.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("咸菜", ({"xian cai","cai"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘咸菜.\n");
                set("unit", "盘");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
        setup();
}


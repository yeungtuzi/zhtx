// /d/xizang/class/bad/npc/obj/cai3.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("泡菜", ({"pao cai","cai"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘泡菜.\n");
                set("unit", "盘");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
        setup();
}


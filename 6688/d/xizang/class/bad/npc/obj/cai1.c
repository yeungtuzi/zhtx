// /d/xizang/class/bad/npc/obj/cai1.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("小菜", ({"xiao cai","cai"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘精美可口的小菜.\n");
                set("unit", "盘");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
        setup();
}


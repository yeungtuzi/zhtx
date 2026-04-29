// /d/xizang/class/bad/npc/obj/cai4.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("炒菜", ({"chao cai","cai"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"一盘精致可口的炒菜,如果说是那个拿剑的家伙做的,不知道有没有人信.\n");
                set("unit", "盘");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
        setup();
}


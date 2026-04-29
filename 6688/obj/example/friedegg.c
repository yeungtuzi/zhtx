// /obj/example/friedegg.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("炒鸡蛋", ({ "fried egg", "egg" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘炒的焦黄冒着香气的炒鸡蛋.\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
}


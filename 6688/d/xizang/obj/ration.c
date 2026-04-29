// /d/xizang/npc/obj/ration.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("干粮", ({ "ration", "ganliang" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块青稞面作的粗硬的干粮.\n");
                set("unit", "块");
                set("value", 10);
                set("food_remaining", 6);
                set("food_supply", 80);
        }
}

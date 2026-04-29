// /d/xizang/class/budala/obj/food.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("斋饭", ({ "food", "zhai fan", "fan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是布达拉宫的上等斋饭.\n");
                set("unit", "碗");
                set("value", 30);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
        setup();
}

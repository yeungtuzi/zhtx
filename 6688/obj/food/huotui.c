// /obj/food/huotui.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("金华火腿", ({"jinhua huotui", "huotui", "ham"}) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "金华火腿,名满天下,既到金华,不可不尝,快吃啊!\n");
                set("unit", "块");
                set("value", 300);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
        setup();
}

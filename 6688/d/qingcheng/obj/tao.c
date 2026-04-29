inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("水密桃", ({ "shuimitao","tao" }) );
        set_weight(160);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个熟透了的水密桃。\n");
                set("unit", "个");
                set("food_remaining", 10);
                set("food_supply", 20);
        }
}

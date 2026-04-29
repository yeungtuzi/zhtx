//huasheng.c 花生
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("花生",({"hua sheng","food"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一把煮花生，看起来很好吃的样子～～～\n");
                set("unit", "把");
                set("value", 30);
		        set("food_remaining", 5);
		        set("food_supply", 25);
		}
        
        setup();
}

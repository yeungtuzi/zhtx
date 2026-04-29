// /d/xizang/class/budala/npc/obj/food.c

inherit ITEM;
inherit F_FOOD;
string* titles = ({
"油炸花生米",
"五香花生米",
"五香瓜子",
"糖炒栗子",
"素什锦",
"酱牛肉"
}));

void create()
{
	string name1;
        name1 = titles[random(sizeof(titles))]
        set_name(name1, ({ "xiaocai", "cai", "food" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碟精美可口的小菜.\n");
                set("unit", "碟");
                set("value", 10);
                set("food_remaining", 2);
                set("food_supply", 10);
        }
        setup();
}

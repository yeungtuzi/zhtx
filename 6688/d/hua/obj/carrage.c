inherit ITEM;

void create()
{
        set_name("婴儿摇篮", ({ "carrage" }) );
        set_weight(100);
        set_max_encumbrance(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个精致漂亮的婴儿摇篮。\n");
                set("value", 10000);
        }
}

int is_container() { return 1; }


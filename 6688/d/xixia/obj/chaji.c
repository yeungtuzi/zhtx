inherit ITEM;

void create()
{
        set_name("茶几", ({ "cha ji"}) );
        set_weight(10000);
	set_max_encumbrance(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get", 1);
		set("no_drop", 1);
                set("long", "这是一张精致的茶几。\n");
                set("unit", "张");
                set("value", 20000);
		set("reset", 1);
        }
                new(__DIR__"tea")->move(this_object());
                new(__DIR__"cake")->move(this_object());

} 

int is_container() { return 1; }


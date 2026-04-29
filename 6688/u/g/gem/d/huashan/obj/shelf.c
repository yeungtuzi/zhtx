
inherit ITEM;

void create()
{
        set_name("书架", ({ "shu jia","shelf",}) );
        set_weight(5000000000); 
		set_max_encumbrance(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
				set("no_get",1);
                set("prep", "on");
                set("unit", "个");
                set("long", "一个书架。\n");
                set("value", 1);
        }
		setup();
}



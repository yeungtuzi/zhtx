
inherit ITEM;

void create()
{
        set_name("书架", ({ "shielf","书架"}) );
        set_weight(500); 
		set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("prep", "on");
                set("unit", "个");
                set("long", "一个书架。\n");
                set("value", 1);
        }
}
int is_container() { return 1; }


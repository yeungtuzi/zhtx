
inherit ITEM;

void create()
{
        set_name("箱子", ({ "box","箱子"}) );
        set_weight(500); 
	set_max_encumbrance(800);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("prep", "in");
                set("unit", "个");
                set("long", "一个箱子。\n");
                set("value", 1);
        }
}
int is_container() { return 1; }


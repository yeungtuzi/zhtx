//write by lysh
// letter.c
inherit ITEM;

void create()
{
	set_name("书信", ({"shu xin"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
"这是明教掌门张无忌给张真人的书信。\n");
                set("material", "paper");
        }
}


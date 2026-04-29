// letter.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( "画卷" , ({ "picture" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("value", 0);
                set("material", "paper");
                set("long", "这是一幅画卷，打开一看，上面画着一个绝色女子。\n");
              }

	set("nopawnable", 1);
	set("no_get", 1);
	set("no_sell", 1);
 
       setup();
}

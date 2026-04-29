// dust.c

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name("化尸粉", ({"dust"}));
        set("long",
                "这是一包用来毁尸灭迹的化尸粉，只要用一丁点就可以\n"
                "化去(dissolve)一具尸体！\n");
        set("value", 1000);
        set("unit", "包");
        set("base_unit", "份");
        set("base_weight", 1);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_dissolve", "dissolve");
}

int do_dissolve(string arg)
{
        object ob;
object me = this_player();
me->add("shen",-10000);
        return 1;
}


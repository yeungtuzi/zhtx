#include <ansi.h>
inherit ITEM;

void create()
{
	int val=random(100)*100000;
        set_name(HIW"夜明珠"NOR, ({"yeming zhu", "zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗隐隐发光的夜明珠，价值连城。\n");
                set("value", val);
        }
        setup();
}

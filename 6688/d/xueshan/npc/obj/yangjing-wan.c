// yangjing-wan.c养精丸

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{

        set_name("养精丸", ({"yangjing wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗别具灵效的养精丸，程灵素为对付星宿而研制。\n");
               set("value", 20000);

        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");

        if (me->query("eff_gin") == me->query("max_gin"))
                return notify_fail("你现在不需要用养精丸。\n");

        else
        {
                this_player()->receive_curing("gin", 250);
                message_vision(HIC "$N吃下一颗养精丸，只觉精神振作，气色看起来好多了。\n" NOR, me);
        }

        destruct(this_object());
        return 1;

}

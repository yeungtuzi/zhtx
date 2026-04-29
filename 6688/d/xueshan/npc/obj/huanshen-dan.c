// huanshen-dan.c还神丹

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

        set_name("还神丹", ({"huanshen dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗别具灵效的还神丹，程灵素为对付唐门而研制。\n");
                set("value", 30000);

        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");

        if (me->query("eff_sen") == me->query("max_sen"))
                return notify_fail("你现在不需要用还神丹。\n");

        else
        {
                this_player()->receive_curing("sen", 250);
                message_vision(HIC "$N吃下一颗还神丹，只觉精神振作，气色看起来好多了。\n" NOR, me);
        }

        destruct(this_object());
        return 1;

}

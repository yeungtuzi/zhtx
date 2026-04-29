// write by qqqqq
#include <ansi.h>
inherit ITEM;

int do_drink(string arg);

void create()
{
       set_name("孟婆汤", ({ "mengpo tang", "tang", "bowl" }) );
       set_weight(1000);
        set("value",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗孟婆汤，喝下去就可以忘却生前之事\n");
                set("unit", "碗");
        }
                setup();
}

void init() 
{
       add_action("do_drink","drink");
}

int do_drink(string arg)
{
        object sb;
        sb=this_player();
       if(!id(arg)) return notify_fail("你要喝什么？\n");
        else if(sb->is_busy())
                return notify_fail("你上一个动作还没完成。\n");
        else
       {
                
                sb->set("shen",0);
		sb->set("bellicosity",0);
                message_vision( HIG "$N喝下一碗孟婆汤,只觉得心里一片清明，江湖上的恩恩怨怨是是非非一下子都无影无踪了\n" NOR,sb);
		tell_object(sb,"你的正气和杀气都消失了。\n");
                destruct(this_object());
                return 1;
        }
}



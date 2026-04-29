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
        set_name(HIY"金"+HIW"蚕"+HIC"王"NOR, ({"jincan wang", "can", "wang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只金蚕王，据说服食以后会增加很多天赋，也不知道是不是真的。\n");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_paimai",1);
                set("no_sell",1);
                set("value", 500);
                set("medicine", 1);
                set("unpawnable",1);
        }
        setup();
}

int do_eat(string arg)
{
       object me,ob;
       me=this_player();
       ob = this_object();
       if( !this_object()->id(arg) ) return 0;
       
       write(HIC"你服下一只金蚕王，只觉得脱胎换骨，全身的能量几欲奔泻而出!(假的！上当了！)\n"NOR);
       destruct(this_object());
       return 1;
}


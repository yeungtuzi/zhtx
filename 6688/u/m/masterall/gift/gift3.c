//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"圣诞"+HIM"礼盒"NOR , ({ "Christmas box", "box" }) );
        set_weight(600);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", HIM"这是一个包装精美的圣诞礼盒，赶紧打开(open)看看里面是什么礼物吧！\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "个");
        
}
void init()
{
        add_action("open_box","open");
}


int open_box(string arg)
{
       object me,ob;
       int luck;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();
       ob = this_object();
       luck = random(8);

       if( ob->query("owner") != me )
                return notify_fail("这个圣诞礼盒不是你的！\n");

       tell_object(me,HIC"纵横天下II祝您在新的一年里工作学习顺利，身体健康！\n这份特别的祝福带给您，以及您的亲人、爱侣、朋友。\n"NOR);
       tell_object(me,HIG"您得到了568000点战斗经验，388888点潜能的奖励！\n"NOR);
       tell_object(me,HIG"另外特别由于感谢您对于这个游戏的投入以及对巫师工作的支持，\n特奖励您38点武林声望，2点悟性，2点灵性，2点魅力，2点福缘，168点永久内力！\n"NOR);
       me->add("combat_exp", 568000);
       me->add("potential", 388888);
       me->add("wlshw", 28);
       me->add("int", 2);
       me->add("spi", 2);
       me->add("kar", 2);
       me->add("per", 2);
       me->add("max_force", 168);

       destruct(this_object());
        return 1;
}


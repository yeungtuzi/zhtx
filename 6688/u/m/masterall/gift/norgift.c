//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"圣诞"+HIM"礼盒"NOR , ({ "Christmas box", "box" }) );
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
       tell_object(me,HIG"您得到了168000点战斗经验，88888点潜能的奖励！\n"NOR);

       me->add("combat_exp", 168000);
       me->add("potential", 88888);


       destruct(this_object());
        return 1;
}


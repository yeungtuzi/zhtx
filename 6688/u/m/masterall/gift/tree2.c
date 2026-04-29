#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"圣诞树间"NOR);
        set("long", @LONG
圣诞快乐！
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/jingcheng/tamgch",
]));                                                  

        set("no_clean_up", 0);

        setup();
        
}


void init()
{
        add_action("do_pick","pick");
}



int do_pick(string arg)
{
        object me = this_player();
        object ob = new("/u/m/masterall/gift/gift2.c");


        if ( me->query("chgift_got") ) 
        {
                write(HIR"每个人只能拿一个礼物，你怎么这么贪心！给你找个地方闭门思过吧！\n"NOR);
                me->move("/d/wizard/prizon.c");
                return 1;
        }
        else if ( !me->query_temp("tree2") ) 
        {
                write(HIR"这里不是你该来的地方，给你找个更好的地方待着吧！\n"NOR);
                me->move("/d/wizard/jianyu.c");
                return 1;
        }
        else 
        {
                message_vision(HIM"$N满心欢喜的从圣诞树上摘下一件礼物。\n"NOR, me);         
                me->set("chgift_got", 1);
                me->delete_temp("tree2");
                ob->move(me);
                ob->set("owner", me);
                return 1;
        }
}

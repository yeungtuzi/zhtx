#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "小花池");
        set("long", @LONG
这是一个小花池，清澈的池水含著淡淡的幽香。池周围有许多奇花    
异草，时如至芝兰之室，清香袭脑，温馨荡魄。缤纷的花瓣飘在池上，
云幢羽葆中，簇拥著许多师姐妹，有的嘻戏玩耍，有的翩然起舞。你也
想到小花池中沐浴休憩(take bath)。
LONG
        );
    set("resource/water", 1);
    set("objects", ([
      __DIR__"npc/fireangel" : 1,
       __DIR__"npc/eton" : 1,
    ]) );

        set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"bathroom1",
]));

        setup();
}
void init()
{
          add_action("do_takebath","take");
}
int do_takebath(string arg)
{
       object me;
       me = this_player();

       if( !arg || (arg!= "bath") )
            return notify_fail("你想作什麽? \n");
       if( !me->query_skill("iceforce",1) )
       {
       		message_vision(HIR"$N跳进小花池，只觉得一阵燥热之气从心头涌起，抬眼一看，火神族神像似乎模糊不清。\n"NOR,me);
	        me->apply_condition("rose_poison", 30);       		
	        return 1;
       }	
       if( (string)me->query("gender") != "女性" ) {
            me->apply_condition("rose_poison", 15);
            tell_object(me, HIG "你觉得池水好像有种奇特的沁凉！\n" NOR );
       } else {
       message_vision("$N在池子中尽情沐浴，舒服的泡在池中。\n",this_player() );

       if( me->query("kee") > 30 )
       {
       		me->receive_damage("kee", 20);
	        me->receive_heal("sen", 50+me->query_spi()+me->query_per());
       }
       }
       return 1;
}


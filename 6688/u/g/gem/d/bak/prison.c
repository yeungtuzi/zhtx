//prison.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
    set("short","梅庄大厅");
    set("long",@LONG
这里是一间阴暗潮湿的地牢。地牢的出口是一块厚重的铁板，
上面留着个尺许见方的孔洞。从孔洞看过去，地牢之中十分黑暗
但是就是在这漆黑的地牢中，竟有两点寒光闪烁。在地牢的墙角
里放着一张床，仔细一看，那张床竟然是精钢所铸。
LONG);
     set("exits",([
          "south" :__DIR__"didao0",
     ]));
     set("objects",([
            __DIR__"npc/ren" : 1,
        ]));
     create_door("south", "铁门", "north", DOOR_CLOSED);
     set("no_clean_up",1);
     setup();
//     replace_program(ROOM);
}

void init()
{
    add_action("do_study","mosuo");
    add_action("do_study","touch");	
}
void do_study(string arg)
{
     object me;
     me = this_player();
     if(!arg||arg=="")
     return notify_fail("什么？你想干什么？\n");
     if(!me->query("save_ren_success"))
     return notify_fail("什么？你想干什么？\n");
     if(!me->query("have_read_hgdf"))
     {
         me->apply_condition("can_study_hgdf",500);
         me->set("have_read_hgdf",1);	
     }
     if(!me->query_condition("can_study_hgdf"))
     return notify_fail("你发觉铁板上的东西实在是太深奥了，你完全无法领会其中奥妙。\n");
    //begin study bed 
    if(arg=="bed"||arg=="床")
    {
      int sen_cost;
      if(me->query("sen")<51)
      return notify_fail("你现在实在太累了，无法静下心来学习化功大法。\n");
      sen_cost = 50*55/me->query("int");
      if (sen_cost<50) sen_cost = 50;
      me->receive_damage("sen",sen_cost);
      me->improve_skill("huagong-dafa",random(me->query("int")));
    }
	
}

// Room: /u/kiss/quanzhen/yutang.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
        set("short", HIG"浴堂"NOR);
        set("long", @LONG
这是全真教沐浴的地方,几个道士正在这里洗澡,你走了半天了,身上一定很脏了吧,
那就赶紧来洗个澡(bath)吧.旁边有一个大牌子,写着:
                   女  士   止  步
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gengyis.c",
]));
       set("objects",([
         __DIR__"npc/yudao.c" :1,
         ]));
        set("no_clean_up", 0);
	set("no_faint",1);
	set("family","全真派");
        setup();

}

void init()
{
   add_action("do_bath","bath");
 }


int do_bath( string arg )
{ 
   object me;
   me=this_player();
  if(!arg)
{
  return notify_fail("你要给谁洗澡?\n");
 }
  if( me->query_condition("bath"))
 { return notify_fail("你不是刚刚洗过澡了么?遇到不要钱的水就想赚本啊。\n");
  }
   if(arg=me->query("id"))
 {   
     me->apply_condition("bath",10);
     me->set("kee",    me->query("eff_kee"));
     me->set("gin",  me->query("eff_gin"));
     me->set("sen",  me->query("eff_sen"));
     if( (me->query("max_force")/2 - me->query("force")/2) > 0 )
     if( (me->query("max_force")/2 - me->query("force")/2) > 0 )
          me->add("force", me->query("max_force")/2 - me->query("force")/2);
     message_vision("$N痛痛快快的洗了一个热水澡,\n",me);
     message_vision("只感觉精神焕发,整个人仿佛脱胎换骨似的\n",me);
   return 1;
  }
}

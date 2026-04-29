#include <ansi.h>
inherit ROOM;

int do_out(string arg);

void create()
{
 set("short", "棺材");
 set("long", @LONG
这是一口不大不小的棺材，好象没什么特别。
LONG
 );
   set("objects",([
  __DIR__"obj/marrycloth" : 1,
]));
 set("exits", ([
 "out" : __DIR__"gumu",
 ]));
  replace_program(ROOM);
//setup();
}

void init()
{  add_action("do_out","out");
  }
 
 int do_out(string arg)
   {
   object me;
   me=this_player();
    if (!arg||arg=="") return 1;
    if (arg=="guancai")
    {
     message("vision", me->name() + "突地不见了\n", 
     environment(me), ({me}) );
                me->move(__DIR__"midao/rukou");
                message("vision",
     me->name() + "走了过来 \n",
                environment(me),({me}) );
     return 1;
  }
 }
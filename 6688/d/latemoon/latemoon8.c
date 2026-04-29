#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","密室");
        set("long", @LONG
这是一间密室。地上铺著可以合地打坐的大理石床。四周挂了一
些兵器，正面墙上写了偌大的 『 舞 』字！ 地板上隐约看到一幅先
天八卦图。中央画著两仪，八个角落分别是：乾坤兑离震巽坎艮、等
卦相。墙上画著几幅玄天玉女翩然起舞的美妙步法。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon7",
]));

    create_door("north","石门","south", DOOR_CLOSED);
        setup();
}

void init()
{
         add_action("do_dancing", "dancing");
}

int do_dancing(string arg)
{
     object me;
      me = this_player();

      if( (string)me->query("gender") == "男性" ) {
      if ( (int)me->query("sen") < 100 )
           return notify_fail("你现在的神太少了，无法专注跳出舞步！\n");
           me->receive_damage("sen", 50);
      }
      if( (string)me->query("gender") == "女性" ) {
      if ( (int)me->query("sen") < 50 )
           return notify_fail("你现在的神太少了，无法专注跳出舞步！\n");
           me->receive_damage("sen", 30);
      }

        if( !arg || (arg!= "out" && arg!="yu-fong") )
             return notify_fail("你在卦象中跳起舞来。但似乎不得要领！\n");

       if ( arg=="yu-fong" ) {
                
message_vision("$N在卦象中跳起舞来..一曲"+HIM"「 有凤来仪 」"+NOR"突然...\n",
                        this_player() );
         this_player()->receive_damage("sen", 50);
         this_player()->move(__DIR__"miroom");
        } else  if ( arg=="out" ) {
          message_vision("$N在卦象中跳起舞来..一曲"+HIM"「 西出阳关 」"+
          NOR"突然...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");
        }

         return 1;
}

#include <ansi.h>

inherit ROOM;

void create()
{
 set("short", YEL "午门" NOR);
        set("long", @LONG
 这是午门,据说皇帝处死大臣都是在这里砍头。所以置身在这里的确有一种
阴森恐怖的感觉。门口有很多侍卫把守着。再往北就是端门了。
LONG
        );
        set("outdoors", "city");
        set("exits", ([
          "south" : "/d/chaoting/zhengmen",
          "west" : "/d/chaoting/ysf",
            "north" : "/d/chaoting/chaoyang",
        ]));
        set("objects", ([
   __DIR__"npc/hchshw1" : 3,
   __DIR__"npc/hchshw2" : 3,
   __DIR__"npc/hchshw3" : 3,
 

        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object renzhi;
        int i;

        if( dir == "north" ) { 
                  if( present("shi wei", environment(me)) && me->query("ct_faith")==0
                
                )
                        return notify_fail(RED"侍卫恶狠狠地说道:皇宫重地，企容尔等擅闯，速速离去,免受皮肉之苦! \n"NOR);
        }
        if( dir == "west" ) { 
                  if( objectp(renzhi = present("ren zhi",me) ) )
                        return notify_fail(RED"你不能背着朝廷大员进去!! \n"NOR);
        }
       return :: valid_leave(me, dir);
}  

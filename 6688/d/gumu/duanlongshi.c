// room: duanlongshi.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);

void create()
{
    set("short", "断龙石");
    set("long", @LONG
  这里有一个很隐蔽的入口，不知道通往何方，看来，这
里面就是终南山古墓了，入口上方有一块巨大的石头，石头
有点松动，如果这块石头掉了下来，那无论如何，古墓都
是要和外界隔绝了。
  
LONG
    );

    set("exits", ([
       "south" : __DIR__"caodi3",
	"east" : __DIR__"shandao",         
	"north" : __DIR__"mudao",         
	
    ]));

    set("item_desc", ([
      "stone" : "这是一个巨大的石头，比较光滑，而且有些松动，让人心惊胆战。\n",
    ]) );
    setup();
}


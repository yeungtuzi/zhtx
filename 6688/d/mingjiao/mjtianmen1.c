
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "松林");
    set("long", @LONG
这是松林中的一间小院，是明教男教众练功修行的场所。
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"mjtianmen",
	"north"	    : __DIR__"nanshe",
    ]));

    set("objects",([
       	 __DIR__"npc/lifusheng":1,
    ]));


    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}


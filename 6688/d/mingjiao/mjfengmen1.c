
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "竹林");
    set("long", @LONG
	明教风门弟子都是佛道等世外之人，行至此间，四处愈加静谧，
阵阵禅唱随微风隐隐传来。
LONG
    );

    set("exits", ([
        "south" : __DIR__"daoshe",
	"north"	    : __DIR__"foshe",
	"northwest" : __DIR__"mjfengmen",
    ]));

    set("objects",([
       	 __DIR__"npc/tuoba":1,
    ]));


    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}


//didao0.c
//writen by emote
//1999.7.15
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
    set("short","地道");
    set("long",@LONG
这是一条黝黑深远的地道，前方很黑，但是似乎又透着一丝亮光。
前面好象有一扇铁门。
LONG
    );
    set("exits",([
         "north" :__DIR__"prison",
         "south" :__DIR__"laomen2",
     ]));
    create_door("north", "铁门", "south", DOOR_CLOSED);
    setup();
    replace_program(ROOM);
}
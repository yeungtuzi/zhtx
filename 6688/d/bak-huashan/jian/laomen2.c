//laomen2.c
//writen by emote
//1999.7.15
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short","牢门");
     set("long",@LONG
你的面前是一扇厚重的牢门，这扇牢门看起来相当怪异。
因为它是由四道门夹成的。一道铁门后，一道钉满了棉絮的
木门，其后又是一道铁门，又是一道钉棉的板门。可见此监
牢是用来关押武林中的绝顶高手的地方。
LONG
     );	
     set("exits",([
         "south" :__DIR__"didao1",
         "north" :__DIR__"didao0",
     ]));
     create_door("south", "牢门", "north", DOOR_CLOSED);
     setup();
     replace_program(ROOM);
	
}

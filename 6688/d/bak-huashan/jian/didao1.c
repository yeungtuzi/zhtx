//didao1.c 地道
//writen by emote
#include <room.h>
inherit ROOM;
void create()
{
    set("short","地道");
    set("long",@LONG
这里的地道黑黝黝的，周围看不大清什么东西，只能凭着感觉往前走。
你大约向前走了一盏茶的功夫，突然发现前面似乎又多了一扇铁门。
LONG);
     set("exits",([
         "south" :__DIR__"laomen",
         "north" :__DIR__"laomen2",
     ]));
     setup();
     replace_program(ROOM);
}
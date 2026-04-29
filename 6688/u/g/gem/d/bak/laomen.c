//laomen.c 牢门
//writen by emote
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short","牢门");
     set("long",@LONG
周围四遭黑漆漆的，完全无法辨别方向，只能看见前方约两丈远的地方，
似乎有一扇巨大的石门，你左手边好象还有个不大不小的石块嵌在石壁上，似
乎有什么用处是的。
LONG);
     set("exits",([
         "north" :__DIR__"didao1",
         ]));
     setup();    
}
void init()
{
    add_action("do_push","push");
}
void do_push(string arg)
{
   object room;
   if(!arg||arg=="")
   return notify_fail("你要按什么？\n");
   if((arg=="button"||arg=="石块")
      &&!query("exits/down") )
     {
        message("vision", "铁板出轧轧的声音，向一侧缓缓移开，"
                "向下露出一个黑洞洞的入口。\n", this_object() );
         set("exits/up", __DIR__"qintang");
                if( room = find_object(__DIR__"qintang") ) {
                        room->set("exits/down", __FILE__);
                        message("vision","头顶上的铁板忽然发出轧轧的声音，露出一个光亮亮的洞口。",room );
                }
                remove_call_out("close_path");
                call_out("close_path", 10);
        }
}

void close_path()
{
        object room;

        if( !query("exits/up") ) return;
        message("vision", "铁板忽然咣的一声倒了下去，将向下的洞口盖住了。\n", this_object() );
        if( room = find_object(__DIR__"qintang") ) {
                room->delete("exits/down");
                message("vision", "头顶上的铁板咣的一下倒了下来盖住了向下的洞口。\n", room );
        }
        delete("exits/up");
}


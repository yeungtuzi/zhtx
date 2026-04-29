//华山别院
//gudi.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "山谷底");
        set("long", @LONG
这里是华山舍身崖的底部，你头上是高耸的山崖。一朵朵白云低低地押在你的
头顶上。你好象身处在一个硕大无底的桶里一样，周围的岩壁异常光滑，看来是无
法找到出去的路了。
LONG
        );
        set("item_desc",([
               "草丛":"一丛茂盛碧绿的草。不过这里其他的地方草长的都不怎么好，就这丛长得非常茂盛。\n",
               "grass":"一丛茂盛碧绿的草。不过这里其他的地方草长的都不怎么好，就这丛长得非常茂盛。\n",
          ]));
        setup();
//      replace_program(ROOM);
}
void init()
{
   add_action("do_push","pushaside");	
}
int do_push(string arg)
{
    object me;
    me=this_player();
    if ((!arg)||(arg==""))
    return notify_fail("什么？\n");
    if (arg=="grass")
    {
        message_vision("你轻轻地将草丛拨开，居然发现了一条迷道。\n",me,me);
        set("exits",([
             "enter":__DIR__"bieyuan",
        ]));
    }
    return 1;
}
/*int do_smear(string arg)
{
   	object me,ob;
   	me = this_player();
   	if (!arg||arg=="")
   	return notify_fail("你要往白纸上摸什么东西？\n");
   	if (arg=="dust")
   	{
   	if (query("have_map"))	
   	    return notify_fail("这里已经没有炭粉了。\n");
   	else    
   	{
   		message_vision("你仔细地刮了一小撮炭粉，轻轻抹去最上面一张纸上，纸上便现出了花纹。\n",this_player(),this_player());
                message_vision("你仔细一看，原来是一幅地图，地图上面画地竟然是.........\n",this_player(),this_player());
	        ob=new(__DIR__"obj/map");
       	        ob->move(this_player());
	        set("have_map",1);
        }
        }
        return 1;
}

*/
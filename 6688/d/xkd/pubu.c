// Room: 山路

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"瀑布"NOR);
        set("long", @LONG
这里是一道极为壮观的瀑布，世间罕有，即便踏变天下名山大川，这样的瀑布也实
在是难得一见，你心中不由得暗暗称奇。瀑布前站立一位仆从，背手而立，莫不作
声，瀑布后面隐隐的有一个山洞，好像可以进去(enter),但瀑布自上而下的水流这
么湍急你要是想再往前走可得问问他了。
LONG
        );
        set("outdoors", "xkd");
        set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"shanjing",
]));
        set("objects",([
                "/d/xkd/npc/puren" : 1,
        ]) );

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{

       object me,armor;
       me=this_player();

       if( !objectp(armor = present("rain coat",me) ) || !armor->query("equipped"))
                return notify_fail("你没穿雨衣就这么进去不怕给淋着？？\n");

       if ( !me->query("got_ling") )
                  return notify_fail("你哪里搞来这么一件破衣服就跑来蒙事？！\n");

       message_vision(HIC"\n$N靠近进瀑布，纵身一跃，耳边的直落瀑布发出震天动地的响声，$N定了定心神，才发现瀑布内别有洞天！！\n"NOR,me);
       me->move(__DIR__"yongdao1.c");
         return 1;
 
}


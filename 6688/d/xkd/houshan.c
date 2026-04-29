 // shanlu1.c 山路
// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"侠客岛后山"NOR);
        set("long", @LONG
由侠客岛正厅出来就是一片开阔的空地，但奇怪的是周围光秃秃的寸草不生，比起
海岸边上的枝繁叶茂真是判若两境，再往前行好似有一个山洞，隐隐的透出光亮来。
LONG
        );
 
        set("exits", ([
                "south" : __DIR__"shidong",
        ]));

        setup();

} 
 
void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{

       object me;
       me=this_player();

       if ( !me->query("got_ling") )
                  return notify_fail("那个洞黑漆漆的，你掂量了一下自己的功夫，想想还是不进去的好。\n");

       if ( !me->query("got_zhou") )
                  return notify_fail("你还没喝腊八粥吧，还不赶快去要一碗解解馋？！\n");

       message_vision(HIC"\n$N一猫腰就钻了进去，由于过于兴奋，脑袋差点磕在洞口的石头上！！\n"NOR,me);
       me->move(__DIR__"shi1.c");
         return 1;
 
}


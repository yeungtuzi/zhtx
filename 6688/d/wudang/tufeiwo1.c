// tufeiwo1.c 林中小路
// by Cleansword 1996/2/2

inherit "/u/l/lazypig/room/qiankuncave.c";
#include <ansi.h>
void create()
{
        set("short", "林中小路");
        set("long", @LONG
        你走在一条僻静的林中小路上，两旁是阴森森的树林。只见左右前后，到处
都是铺天盖地的松树林。几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞
般伸向天空，把阳光遮得丝毫也无。据说这里经常有土匪出没，不可久留。边上
有个小山洞(dong)。
LONG
        );
        set("outdoors", "wudang");

        set("no_sleep_room",1);

        set("exits", ([
                "south" : __DIR__"tufeiwo2",
                "northdown" : __DIR__"wdroad7",
        ]));

        set("objects", ([
                __DIR__"npc/tufei2" : 2 ]));

        set("item_desc", ([
                "dong": "这个小洞黑乎乎的，也不知道它会通往哪里。\n",
 
        ]) );


        setup();
}

/*
void init()
{
//        ::init();
        add_action("do_enter", "enter");
//        add_action("do_enter", "zuan");
}


int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" )
        {
                if( me->query("combat_exp")>5000000 ) 
                {
        message_vision(HIY"$N给自己壮了壮胆，一弯腰往洞里钻了进去。\n\n走了半天才发觉前面有光亮，$N心里乐开了花，\n\n不断加快了脚步，没想到却在出口摔了个大跟头！\n"NOR, me);
                        me->move("/d/qiankun/entrance");
                        me->add("combat_exp",-5000);
                        message("vision",
                                me->name() + "从旁边的一个小洞里连滚带爬的摔了进来，模样甚是狼狈。\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else 
                        return notify_fail("你的江湖经验太低，这种危险的地方还是不要乱跑了！\n");
        }
} 
*/

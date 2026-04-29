// Room: /d/qingcheng/shuyuan.c
//write by pock 98.04.04
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"书院"NOR);
	set("long", @LONG
这里是一个小小的书院，一个教书先生正拿着教鞭在书院里走来走去，
督促学童发奋读书，但小童天性贪玩，只是在老师走过时才放声读书，
当老师转身离开时，又顾着玩自己私下带来的玩意了。书院的东边墙
上有一幅草书(caoshu),可能是这里主人所作。
院子虽小，但来来回回有不少人忙里忙外的抄写书本，也不知道拿来要
做什么用，你如果想挣点钱打打杂，顺便学习一下，不妨来试试(copy)。
LONG
	);
        set("no_fight", 1);
	set("exits", ([ /* sizeof() == 1 */
                   "west": __DIR__"jie31",
		]));
        set("objects",([
             __DIR__"npc/teacher":1,
                      ]));
	set("item_desc",([
          "caoshu":"草书写得龙飞凤舞，苍劲有力，可见作者草书的造诣特别的高了.\n",	
          "草书":"草书写得龙飞凤舞，苍劲有力，可见作者草书的造诣特别的高了.\n",	
		]));
	setup();

}
void init()
{
        add_action("do_copy", "copy");
}

int do_copy()
{
        object ob, me;
        me=this_player();
        if(!me->query_skill("literate", 1))
                return notify_fail("你是个文盲,这活计没法做.\n");
        if ((int)me->query_skill("literate", 1) > 150)
                return notify_fail("您这样的文学大家，小店哪里用得起啊。\n");
        if(me->query("combat_exp")> 800000)
                return notify_fail("这位大侠请上座，赶紧进来歇个脚，这些粗活还是让小的们干吧。\n");
        if ((int)me->query("gin")<30)
                return notify_fail("你太累了,休息一下吧!\n");
        me->add("gin",-30);

        message_vision(YEL"$N随手抄起一支笔，开始玩命的抄了起来，不过半晌，已然累得腰酸背痛腿抽筋了。\n"NOR, me);
        if ((int)me->query_skill("literate", 1) < 151)
                me->improve_skill("literate", me->query_int()/2+me->query_wil()/2);
                write("工作虽然辛苦，但你感到渐入佳境，不知不觉使得自己的文学造诣有所提高！\n");

        ob = new("/obj/money/silver.c");
        ob->move(me);
        write("读千里笑嘻嘻的为你擦了擦汗，“这是你的工钱，回去好好休息吧！”。\n");
        return 1;
}


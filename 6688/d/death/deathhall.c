//death room
//by roar
//copy from Karl.Sagon
//transfered by 朱蒂。福斯特
#include <ansi.h>
#include <login.h>
//inherit ROOM;
inherit "/d/wizard/jianyu";

int do_revive();

void create()
{
	set("short","生命尽头");
	set("ghostplace",1);
        set("valid_startroom", 1);
	set("long", @LONG
这里是一处海滩，椰树婆娑摇曳。这儿没有热带海滨那灼人的烈日，笼罩在一
片奇异的蓝色辉光之下，是一切看起来如在水中。远处，平静的大海与庄严肃穆的
星空融成浑然一体。这里似乎是宇宙的边缘，时间的终点。景色之美令你沉醉，但
它又是那么惊人的熟悉，仿佛是深藏在记忆深处的一幅画面。这只该存在于孩童最
纯真的梦想之中。谁能想到这里是生命尽头的地方。每一位死去的人都从这里获得
再生。
LONG
	);
	set("exits",([
		"roar" : __DIR__"roar",
		"wiz"  : __DIR__"wiz",
		"marx" : __DIR__"marx",
		"dao"  : __DIR__"dao",
                "ru"   : __DIR__"ru",
		"shi"  : __DIR__"shi",
	]));

	set("objects", ([
                __DIR__"npc/player":1
        ]) );

	setup();
//	replace_program(ROOM);
        call_other("/obj/board/death_b", "???");
}

void init()
{
//	add_action("do_revive","revive");
	add_action("do_climb","climb");
}


int do_climb(string arg) {

	object ob = this_player();
	if( arg != "椰树" && arg != "tree" ) 
		return 0;

	else {
                write("\n你手脚并用向椰树顶上爬了上去，忽然一阵海风吹来,你眼前一花....\n\n\n");

        tell_room(environment(ob),(string)ob->query("name")+
        "往椰树顶上爬去, 忽然一阵海风吹来,椰树剧烈的摇晃起来。\n",
        ({this_object(), ob}));
        tell_room(environment(ob),
        "一眨眼的功夫"+(string)ob->query("name")+"竟然不见了.\n",
        ({this_object(), ob}));
        ob->move(DEATH_ROOM);
        return 1;
	}
}

int do_revive()
{
        object ob=this_player();
	ob->reincarnate();
	ob->move(REVIVE_ROOM);
        message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"+
                "很久了，只是你一直没发觉。\n", environment(ob), ob);
	return 1;
}

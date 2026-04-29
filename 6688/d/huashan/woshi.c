//woshi.c 卧室
//by emote
inherit ROOM;

void create()
{
	set("short","卧室");
	set("long",
@LONG
这里是岳不群的寝室，岳不群在江湖上人称「君子剑」，他虽为一大派
掌门，可他的卧室却布置的很简单。除了一张床，几只箱子，墙角有张化妆
台，只有靠墙一张红木书桌还显得略有气派。从窗户向外看出去，外面就是
悬崖绝壁。
    现在岳夫人宁中则就坐在屋里。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"zhengqitang",
]));
        set("objects", ([
//                 __DIR__"npc/ning":1,
		"/class/huashan/ning":1,
				 
]));

		setup();
		replace_program(ROOM);
}


//ercaya.c 耳擦崖
//by emote

inherit ROOM;


void create()
{
	set("short","耳擦崖");
	set("long",
@LONG
这里山势十分险峻，在山崖边仅仅有一条三尺来宽的小路，以供行人行
走。自古以来行人就很少，只有以采药为生的药农，和一些江湖上的人物才
会到这样的地方来。你往山崖的旁边一看，旁边的山谷里面白云缭绕，也不
知道究竟有多深。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"north"  : __DIR__"yuntai",
		"southup": __DIR__"shangtianti",
		]));
	 set("objects", ([
                 __DIR__"npc/caiyaoren": 1,
]));
	set("outdoors","huashan");
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="southup")
	{
	 if(random(4))
	   {
/*
	     me->receive_wound("kee",50,me);
*/
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	   }
	}
	 return 1;
}
